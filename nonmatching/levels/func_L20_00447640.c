/* Wave 4 (worker 04): the candidate below is the wave-4 one - the split address
   works with a second C name for the table, the body is the retail's 264 bytes
   and 26 of the 66 instructions differ.  See the wave-4 note at the end. */
/* near-miss: func_L20_00447640 (20_yeedil, 264 bytes).
   The body and the loop condition are retail's, byte for byte; only the entry block
   differs, the same way as func_L20_00442E68's (see that file: the table's %hi lands in
   $v1 instead of $v1/$v0, the table's address is materialised in place instead of into
   $a0, and the index lands in $a0 instead of $v0).
   Everything from 0x00447688 on is retail's: the object lookup
   (D_L20_001B2F9C + ((*p & 0x7FFF) << 8)), the 0xB69 class test with the `bnel` that
   skips to the condition, the two 0xFE/0xFD tests, the two calls and the `p++` that
   falls into the condition block.
   Measured: the class byte must be read as UNSIGNED (`*(unsigned char *)(e + 0x20)`);
   a signed char makes the 0xFE/0xFD test impossible and gcc drops the whole block
   (248 bytes). The two 0xFE/0xFD tests must be two separate `if`s: gcc merges
   `c == 0xFE || c == 0xFD` into a range check (`addiu`/`andi`/`sltiu`, 268 bytes) and
   a `switch` with the two cases merges them the same way.
   Per-file flags measured on this unit: -fno-schedule-insns2 gives 260 bytes (four
   short) and -fno-schedule-insns 256; -g and -mno-split-addresses change nothing. All
   of them break the five functions already matched in L20_0043ECB0-g8.c, so no flag can
   be used for that unit.
   The body needs the -G8 unit: it reaches D_L20_001B2FB8 through $gp. */
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef float f32;


extern char *D_L20_001FBB20[] __attribute__((nosda));
extern char *D_L20_001FBB20_b[] __attribute__((nosda));

extern char *D_L20_001B2F9C __attribute__((nosda));

extern int D_L20_001B2FB8 __attribute__((sda));

extern void func_0032EAB8(char *, int, int);

extern void func_003FBEA8(char *, int);

void func_L20_00447640(char *arg0) {
    unsigned char *self = arg0;
    unsigned short *p;
    int i;

    i = self[0x21];
    if (i == 0xFF) {
        goto out;
    }
    p = (unsigned short *)D_L20_001FBB20[i];
    goto cond;
loop:
    {
        char *e = D_L20_001B2F9C + ((*p & 0x7FFF) << 8);

        if (e == 0) {
            goto out;
        }
        if (*(short *)(e + 0xAA) != 0xB69) {
            p++;
            goto cond;
        }
        if (*(unsigned char *)(e + 0x20) == 0xFE) {
            goto skip;
        }
        if (*(unsigned char *)(e + 0x20) == 0xFD) {
            goto skip;
        }
        func_0032EAB8(e, 0, 1);
        func_003FBEA8(e, 0);
skip:
        p++;
    }
    goto cond;
cond:
    i = self[0x21];
    if (i == 0xFF) {
        goto out;
    }
    if (D_L20_001B2FB8 < i) {
        goto out;
    }
    if (p == 0) {
        goto out;
    }
    if (*(short *)(p - 1) >= 0 || p == (unsigned short *)D_L20_001FBB20[i]) {
        goto loop;
    }
    goto out;
out:
    ;
}



/* ---- wave 4 (20_yeedil, 2026-10-20, worker 04): the SPLIT ADDRESS is SOLVED -----
 *
 * The split address is the compiler's own form and a SECOND C NAME for the
 * global reaches it: declaring the table twice (two names for the same
 * address) stops the CSE from merging the two uses, the %hi half is
 * materialised once into a scratch and copied into a callee-saved register
 * (`daddu $s3,$v1,$zero`), and the %lo half is added again at every use
 * (`addiu $v0,$s3,%lo(D)`).  That is the retail's shape:
 *
 *   retail: lui $v1,%hi(D_1FBB20) ; sll $v0,$v0,2 ; addiu $a0,$v1,%lo(D_1FBB20)
 *           addu $v0,$v0,$a0 ; lw $s1,0x0($v0) ; b .L ; daddu $s3,$v1,$zero
 *           ... ; sll $v0,$v1,2 ; addiu $v1,$s3,%lo(D_1FBB20) ; addu $v0,$v0,$v1
 *
 * With the second name the candidate is the retail's 264 bytes and every
 * branch is the retail's; 26 of the 66 instructions differ, all of them the
 * register allocation of the entry block.
 *
 * Measured:
 *  - the second name has to be used for the LATER use (the comparison in the
 *    loop condition); with it on the earlier use the split form disappears and
 *    the body is eight bytes short;
 *  - the two names must both be declared `__attribute__((nosda))` in this -G8
 *    unit; the table is reached through $gp there;
 *  - the loop's index must be read again (`i = self[0x21]`) in the condition
 *    block, as this candidate does; the retail re-reads it (`lbu $v1,0x21($s2)`)
 *    instead of keeping it in a register.
 *
 * The residues (the sizes and the branches are right):
 *   - the retail keeps the 0xFF constant, the %hi and the index in $v1/$v1/$v0,
 *     this candidate in $v0/$v0/$a0, so the table's address lands in $a0 in the
 *     retail and in $v0 here;
 *   - the retail has no copy of the index (`daddu $a1,$a0,$zero` here is one
 *     extra instruction and the reason the two bodies are two instructions
 *     apart at the end of the entry block);
 *   - the retail puts the `lw $s1,0x0($v0)` before the `b` and the `daddu
 *     $s3,$v1,$zero` in its delay slot, this candidate the other way round.
 */
