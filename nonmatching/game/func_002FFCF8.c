#include "include_asm.h"

/* Near miss (wave 13, worker g3): 124 bytes of retail, the body is reproduced except for
   three points.

   The retail body:

     addiu $sp,$sp,-0x10 / addiu $a1,$zero,0x44 / sd $ra / jal func_002FC560 /
     addiu $a0,$zero,0x42 / lui $a0,0x1B / lh $a0,0x2312($a0) / jal func_00283CE0 /
     nop / lui $at,0x1B / lwc1 $f1,0x2314($at) / lui $at,0x3F80 / mtc1 $at,$f12 /
     mul.s $f0,$f0,$f1 / lui $at,0x437F / mtc1 $at,$f2 / sub.s $f12,$f12,$f0 /
     jal func_00283CF0 / mul.s $f12,$f12,$f2 / lui $v1,0x1A / sll $v0,$v0,24 /
     addiu $v1,$v1,0x6480 / daddu $t0,$v0,$zero / lh $a3,0x150($v1) / daddu $a0,$zero /
     lh $a1,0x152($v1) / jal func_0027DE50 / daddu $a2,$zero / ld $ra / jr $ra

   What differs:

   1. The short is loaded into $a0 with the address folded into it (`lui $a0` then
      `lh $a0,lo($a0)`) and the delay slot of the call stays empty; this C shares one
      `lui` between the short and the float (both live in the same page) and puts the
      short load in the delay slot.
   2. For the same reason the float load comes after the 1.0f constant here and before
      it in the retail.
   3. The fifth argument: the retail shifts in $v0 and copies it to $t0
      (`sll $v0,$v0,24` then `daddu $t0,$v0,$zero`); this C shifts straight into $t0
      (`sll $t0,$v0,24`).  The retail's shape is what a 64-bit fifth parameter gives
      (measured: a `long long` fifth parameter produces exactly `sll`+`daddu`), but
      func_0027DE50's prototype is shared with func_002FFFE0 in the same unit, which
      needs the 32-bit one.  The two functions cannot both match in one unit.

   Measured: `tools/check.py func_002FFCF8 --diff` gives 116 bytes against the retail's
   124, "instruction at +0x14 differs" in the boot and in every level.

   The two data cells sit at a different address in the boot (0x1B2312 and 0x1B2314) and
   in the levels (0x1B2672 and 0x1B2674), so they are named without an address. */

extern short ref_L00_002FFCF8_00;

extern float ref_L00_002FFCF8_01;

extern float func_00283CE0(int);

extern int func_00283CF0(float);

extern short D_001A6480[];

extern void func_002FC560(int, long long);

extern void func_0027DE50(int, int, int, int, int);

void func_002FFCF8(void)
{
    int v;
    func_002FC560(0x42, 0x44);
    v = func_00283CF0((1.0f - func_00283CE0(ref_L00_002FFCF8_00) * ref_L00_002FFCF8_01) * 255.0f);
    func_0027DE50(0, D_001A6480[0xA9], 0, D_001A6480[0xA8], v << 24);
}
