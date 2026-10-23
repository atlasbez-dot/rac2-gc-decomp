/* func_L00_00411F48, 316 bytes, 27 placements.  ABANDON - the per-level block address and the loop's shape; not attempted past the reading.
 *
 * The record walks a 0xD0-stride block of forty-eight entries whose base is 0x00256BC0
 * in level 00 (`lui $v0,0x25 ; addiu $v0,$v0,0x6BC0`); the address differs from level to
 * level, so it would take a per-level name like func_L00_004117B8's block.  The frame is
 * 0x50 with $s0-$s6 saved, $s5 counts the forty-eight entries down to 0 and $s1 walks the
 * block.  Each entry is tested twice: `lw $v0,0x7C($s1)` must equal the object and
 * `lw $v0,0x88($s1)` must be zero, each with a `bnel` that skips the entry and advances
 * $s1 by 0xD0 in the delay slot.  The body of an entry builds a colour word
 * (`sll $s0,$v0,24` with 0x00103080 or 0xFFFFFFFF) and calls func_0031A768(0x50, 0x60),
 * func_0031A888, func_002ED210(s1, colour, 1, 0.5f, 0.1f, f0) and the same pair again
 * with func_0031A768(0x50, 0x60) and func_0031A888.
 *
 * What would unblock it: the per-level address of the block (a ref_L00_00411F48_00 name)
 * and the prototypes of func_0031A768, func_0031A888 and func_002ED210.
 */
#include "include_asm.h"

extern char ref_L00_00411F48_00[];

extern void func_0031A768(int, int);

extern void func_0031A888(int);

extern void func_002ED210(char *, int, int, float, float, float);

/* The record walks a 0xD0-stride block of forty-eight entries; the block's address differs
   from level to level.  Each entry must name the object at +0x7C and have a zero word at
   +0x88, then the entry is drawn with a colour built from its +0x88 word. */
void func_L00_00411F48(char *a0)
{
    char *s1;
    int i;

    s1 = ref_L00_00411F48_00;
    for (i = 0x2F; i >= 0; i--) {
        if (*(int *)(s1 + 0x7C) == (int)a0 && *(int *)(s1 + 0x88) == 0) {
            func_0031A768(0x50, 0x60);
            func_0031A888(0);
            func_002ED210(s1, 0, 1, 0.5f, 0.1f, 0.0f);
            func_0031A768(0x50, 0x60);
            func_0031A888(0);
            func_002ED210(s1, 0, 1, 0.5f, 0.1f, 0.0f);
        }
        s1 += 0xD0;
    }
}

INCLUDE_ASM("asm/levels", func_L00_00411F48);
