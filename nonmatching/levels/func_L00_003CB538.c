/* func_L00_003CB538, 280 bytes, 27 placements.  ABANDON - the loop's shape; not attempted past the reading.
 *
 * The record walks a 0x30-stride block of sixty-four records whose base pointer is read
 * from D_L00_001B2AD4 (`lui $s0,0x1B ; lw $s0,0x2AD4($s0)`).  The loop's test is
 * `slti $v0,$v1,0x40` and its step `addiu $s0,$s0,0x30` sits in the branch's delay slot;
 * the counter is incremented in the delay slot of the `bnez $v0` that skips the body, so
 * it counts the records whose +0x10 word is set while the body runs on the others.  The
 * body is four calls to func_0031A7C0 with the pair (-1.0f, 1.0f), then func_002EE3D0 on
 * the record, func_0031A768(0x14, 0x32), a fourth func_0031A7C0 with the same pair, then
 * func_001163B0 and a test of its return value that picks 1.0f or -1.0f for the record's
 * +0x2C word; the last call uses the constants 0.7f (0x3F333333) and 0.9f (0x3F666666).
 *
 * What would unblock it: the exact source of the loop (the counter in the delay slot of
 * the skip branch is not a shape this cc1 produces from an ordinary while) and the
 * prototypes of func_0031A7C0, func_0031A768 and func_001163B0.
 */
#include "include_asm.h"

extern char *D_L00_001B2AD4;

extern float func_0031A7C0(float, float);

extern void func_002EE3D0(char *, char *);

extern int func_0031A768(int, int);

extern int func_001163B0(void);

/* The body is a sixty-four iteration loop over the 0x30-stride block read from
   D_L00_001B2AD4; the counter is incremented in the delay slot of the branch that skips
   the body, so it counts the records whose +0x10 word is set.  The record's own words are
   written by the four calls of the body: func_0031A7C0(-1.0f, 1.0f) three times,
   func_002EE3D0, func_0031A768(0x14, 0x32) and func_001163B0, then the last
   func_0031A7C0(0.7f, 0.9f). */
void func_L00_003CB538(char *a0)
{
    char *rec;
    int i;

    rec = D_L00_001B2AD4;
    for (i = 0; i < 0x40; ) {
        if (rec[0x10] != 0) {
            i++;
        } else {
            func_0031A7C0(-1.0f, 1.0f);
            func_0031A7C0(-1.0f, 1.0f);
            func_0031A7C0(-1.0f, 1.0f);
            func_002EE3D0(rec, rec);
            func_0031A768(0x14, 0x32);
            func_0031A7C0(-1.0f, 1.0f);
            func_001163B0();
        }
        rec += 0x30;
    }
}

INCLUDE_ASM("asm/levels", func_L00_003CB538);
