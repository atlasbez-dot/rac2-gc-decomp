/* func_L02_004013C0 (188 bytes, 3 places) -- NEAR MISS, not integrated.
   NOTE: this shared worktree is being edited by another worker at the same time;
   at 2026-10-22 15:16 that worker put a C attempt of their own for this
   function into src/levels/shared/L02_003C43F0-g8.c (the conditional values as
   the call's last two arguments, 180 bytes).  That edit was left untouched (it
   is not this attempt's to revert); the deposit below is the measurement of the
   source that follows, which is a different attempt: the two words retail
   writes and never reads are kept in a volatile local here.
   state: 172 bytes against retail's 188; the first 16 words are identical.
   check.py (02_maktar_nebula), with the source below:
     0040140C  lh   $v1,0xAA($s1)   | lh   $v1,0xAA($s1)
     00401410  addiu $v0,$zero,0xB5A | addiu $v0,$zero,0xB5A
     00401414  bne  $v1,$v0,+4       | bne  $v1,$v0,+0x14
     00401418  lw   $v0,0x0($gp)    | lw   $v0,0x2720($gp)
     0040141C  lw   $v0,0x0($gp)    | lui  $v1,0x1B
   The prologue, the frame (0x40), the saved registers, the two calls and their
   arguments, the float constant and the tail call all match.

   What is measured and right:
   - the mode word at +0xAA is compared with 0xB5A; the two scalar bytes at +0x75
     and +0x76 are the arguments of the second call (a0 takes +0x75).
   - the float constant is 210000.0f: retail's `lui $at,0x484D; ori $at,$at,0x1400`
     is that literal, and it is multiplied with the first call's float return.
   - the call takes (void *, char *, float, int, int, int): this compiler's ABI
     gives a0-a3 and t0 to the integer arguments and f12-f15 to the float ones, so
     the float has to be the third argument for it to reach f12.
   - the first call returns the float that is multiplied, the second call's integer
     return is copied to $t0 and passed as the sixth argument; that copy is what
     keeps `daddu $t0,$v0,$zero` in the body.
   - the pointer at +0x68 has to be loaded BEFORE the first call: retail loads it
     in that call's delay slot and keeps it in $s0, a callee-saved register
     because it is live across the call.

   Open differences and what was tried:
   - the two stack words at sp+0 and sp+4 are written but never read.  A plain
     local loses both stores (this cc1 removes them); `volatile` keeps them but
     then the two branches are merged differently and the body is 200 bytes.
     Nothing tried keeps the stores in the branches and still merges the second
     store at the join the way retail does.
   - the three words D_L02_001B1714, D_L02_001B1718 and D_L02_001B171C are
     addressed absolutely by retail (`lui $v1,0x1B; lw $v1,0x1714($v1)`); this
     cc1 puts them in the small data area and reaches them through $gp.
     `__attribute__((nosda))` gives the absolute form but then materialises the
     address in a second register and the body grows to 200 bytes.
   - the dead load of the second float argument (f13) is kept here and matches
     retail; the earlier note about it dropping was about a different spelling.

   Measured afterwards (same cc1, same unit):
   - the calling convention measured here: the first four integer arguments go to
     $a0-$a3, the fifth to the eighth to $t0-$t3, and only the ninth and later
     reach the outgoing area at the frame's bottom.  A call with seven integer
     arguments therefore sets $t1 and $t2 and never writes to sp+0 and sp+4.
   - an eight-byte aggregate (a struct of two ints) is passed in a register pair,
     $t1/$t2 here, and its copy to the outgoing area is emitted as well; an
     aggregate larger than eight bytes is passed by reference, the address in a
     register, and only its words are copied.  Neither form writes the two
     words the way retail does and leaves $t1 and $t2 unset.
   - the callee, func_002BDBC0, reads $a0-$a3, $t0 and $f12 only: the two words
     retail writes into the outgoing area are dead for it, so they are a local
     of the caller, not arguments.
   - the frame is 0x40 with the saved registers at 0x10, so sixteen bytes sit
     below them; a local of eight bytes plus the outgoing area of eight bytes
     gives that layout, and retail's two stores are at 0x00 and 0x04.
   - retail merges the second store at the join (both paths store the same word),
     which a volatile local cannot do (volatile stores are never merged) and a
     dead local cannot do at all (this cc1 removes the stores). */
#include "include_asm.h"
#include "common.h"

extern float D_L02_001B1720 __attribute__((sda));

extern float D_L02_001B1724;

extern int D_L02_001B1710 __attribute__((sda));

extern int D_L02_001B1714;

extern int D_L02_001B1718;

extern int D_L02_001B171C;

extern char *D_L02_001A8F20;

extern float ref_L02_004013C0_00(float, float);

extern int ref_L02_004013C0_01(unsigned char, unsigned char);

extern void ref_L02_004013C0_02(void *, char *, float, int, int, int);

void func_L02_004013C0(void *a0)
{
    void *s1 = a0;
    void *s0;
    volatile int local[2];
    float f20;
    float r;
    int t0;

    s0 = *(void **)(s1 + 0x68);
    r = ref_L02_004013C0_00(D_L02_001B1720, D_L02_001B1724);
    f20 = r * 210000.0f;
    t0 = ref_L02_004013C0_01(*(unsigned char *)(s0 + 0x75), *(unsigned char *)(s0 + 0x76));
    if (*(short *)(s1 + 0xAA) == 0xB5A) {
        local[0] = D_L02_001B1710;
        local[1] = D_L02_001B1714;
    } else {
        local[0] = D_L02_001B1718;
        local[1] = D_L02_001B171C;
    }
    ref_L02_004013C0_02(s1 + 0x10, D_L02_001A8F20, f20, D_L02_001B1710, D_L02_001B1714, t0);
}
