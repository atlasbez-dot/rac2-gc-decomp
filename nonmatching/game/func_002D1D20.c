#include "include_asm.h"

/* Near miss (wave 13, worker g3): 336 bytes of retail, the body is reproduced except for
   the register allocation of the last eleven instructions.

   The whole body matches word for word up to +0x124 (the tail): the flags word
   D_00138344, the counter in the small data, the callback state at 0x1FEC40 (the same
   layout as D_001F2840: source at +0x14, value at +0x18, fallback at +0x134) and the
   three cells of the tail.

   What differs is the tail:

     retail: lw $a0,counter / lui $v0 / lui $a1 / addiu $a1 / lui $a2 / sll $v1,$a0,1
             / sw $a0 / addu $v1,$v1,$a1 / daddu $v0,$s0 / lh $a0 / sw $a0
     this C: lw $a1,counter / lui $v1 / lui $a0 / addiu $v1 / sll $v0,$a1,1 / sw $a1
             / addu $v0,$v0,$v1 / lui $a2 / lh $v1 / daddu $v0,$s0 / sw $v1

   The same eleven instructions, but the counter lands in $a1 instead of $a0, the shift
   in $v0 instead of $v1 and the return value is copied at the end instead of before the
   last store.  The retail keeps $v0 for the return value over the whole tail, which is
   what pushes the shift into $v1.

   Measured: `tools/check.py func_002D1D20 --diff` gives "instruction at +0x124 differs"
   in the boot and in every level, the size being right (336).

   The function needs the -G8 unit: the counter is reached through $gp, and in a -G0
   unit the sda attribute only gives the `lui`+`sw` pair instead of the one
   instruction the retail has.  Put it back into a 002CD8C0-g8.c unit. */

typedef struct { char prefix[0x14]; char *source; int value; char gap[0x118]; int fallback; } SelectionCallback;

extern int D_00138344[];

extern int ref_L00_002D1D20_00 __attribute__((sda));

extern SelectionCallback D_L00_001FEC40;

extern int D_L00_002853A0[4];

extern int D_L00_00285324[4];

extern short D_L00_001B0C80[0x12];

extern int func_002E5E58(int, unsigned int, void *);

int func_002D1D20(void)
{
    int flags = D_00138344[0];
    int result = 0;
    int counter;

    if (flags & 0x10) {
        int value;
        int status;
        ref_L00_002D1D20_00 = 0;
        value = *(int *)(D_L00_001FEC40.source + 0xE0);
        if (value != 0)
            D_L00_001FEC40.value = value;
        else if (D_L00_001FEC40.fallback == 0) {
            status = -1;
            goto finish;
        }
        status = 0;
    finish:
        return status;
    }
    if (flags & 0x900) {
        ref_L00_002D1D20_00 = 0;
        result = 1;
    } else if (flags & 0x8000) {
        if (ref_L00_002D1D20_00 > 0)
            func_002E5E58(3, 0, 0);
        else
            func_002E5E58(5, 0, 0);
        ref_L00_002D1D20_00 = ref_L00_002D1D20_00 - 1;
        if (ref_L00_002D1D20_00 < 0)
            ref_L00_002D1D20_00 = 0;
    } else if (flags & 0x2000) {
        if (ref_L00_002D1D20_00 < 0x11)
            func_002E5E58(3, 0, 0);
        else
            func_002E5E58(5, 0, 0);
        ref_L00_002D1D20_00 = ref_L00_002D1D20_00 + 1;
        if (ref_L00_002D1D20_00 >= 0x12)
            ref_L00_002D1D20_00 = 0x11;
    }
    {
        int c = ref_L00_002D1D20_00;
        *(int *)D_L00_002853A0 = c;
        *(int *)D_L00_00285324 = *(short *)(D_L00_001B0C80 + c);
    }
    return result;
}
