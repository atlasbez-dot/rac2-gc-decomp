/* func_L00_002FE268 - NON MATCHEE (wave 8, agent w8-09).
 *
 * The body is understood and the two 64-bit constants reach retail's exact `dli`
 * sequences (`ori 0xFFA0 / dsll32 0 / ori 0xE0` and
 * `ori 0x8000 / dsll 20 / ori 0x8000 / dsll 19 / ori 0x4000`, which is
 * 0x40000400004000).  The resident latch read, the three-word block stores and
 * the call all reproduce.
 *
 * Corrected symbol names (the previous draft had them wrong, so its
 * relocations could never check out):
 *   - the block base is 0x1CFF91C0, not 0x1D91C0: retail materialises it with
 *     `lui $v1,0x1D ; addiu $a3,$v1,-0x6E40`;
 *   - the word read into $a0 is 0x1BFF1B4, not 0x1BF1B4: retail reads it with
 *     `lui $v0,0x1C ; lw $a0,-0xE4C($v0)`; the low half only fits the signed
 *     16-bit displacement when the address is 0x1BFF1B4, which is also what
 *     makes retail split the address instead of materialising it whole;
 *   - the third call argument is 0x1A9510, not 0x1A9520: retail loads it with
 *     `addiu $a2,$gp,-0x5AE0` and $gp is 0x1AEFF0;
 *   - the callee is func_002933D0 (the boot name of the level-00 0x002FF0C0).
 *
 * What is left: 112 bytes against 108.  This cc1 materialises the block address
 * into a spare register ($v0) and copies it into $a3 for the call
 * (`daddu $a3,$v0,$zero`), where retail materialises it straight into $a3
 * (`addiu $a3,$v1,-0x6E40`) and stores through $a3.  The 64-bit constant pair
 * lands in ($a2,$a3) here and in ($v0,$v1) in retail, i.e. the two allocations
 * are swapped: the address pseudo has to take $a3 and the constant pair
 * ($v0,$v1).  Writing the three stores through the symbol (no local pointer),
 * through a local pointer, or with the symbol in the call, all give the same
 * object.
 *
 * The third call argument is a one-instruction `addiu $a2,$gp` load, so the
 * unit must be -G8 (measured in a dedicated file; the canonical
 * L00_002FC7A0.c is -G0).
 */

#include "include_asm.h"

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned char u8;

extern u8 D_L00_001A9510[4] __attribute__((sda));

extern u64 D_001A72C8;
extern u32 D_001A72C0;
extern u32 D_L00_001BFF1B4;
extern u64 D_L00_001CFF91C0[3];

extern void func_002933D0(u32, u32, void *, void *);

/* latches the incoming word, seeds the three-word block from the resident latch
   and hands both to the shared routine */
void func_L00_002FE268(u32 value)
{
    u64 previous = D_001A72C8;
    u64 *block = D_L00_001CFF91C0;

    D_001A72C0 = value;
    block[0] = previous;
    block[2] = 0x40000400004000ULL;
    block[1] = 0xFFA0000000E0ULL;
    func_002933D0(D_L00_001BFF1B4, 0, D_L00_001A9510, block);
}
