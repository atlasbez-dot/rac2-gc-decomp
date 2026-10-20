/* func_002ED4B8: 180 bytes compiled (-O2 -G8, the src/game/002ED260.c profile), retail 176.
   Every instruction is retail's. The single difference is one `nop` that the assembler inserts
   between `mfc1 $a2,$f1` and the dependent `sll $a2,$a2,24` (cc1 prints `#nop` there and gas
   turns it into a real nop); retail has none, and retail has none after any mfc1 in compiled
   code. This C is therefore the right C and the residue is the assembler's mfc1 hazard rule.
   Measured: with a gas that exempts the R5900 from the INSN_LOAD_COPROC_DELAY rule (stock
   tc-mips.c: `(prev_pinfo & INSN_LOAD_COPROC_DELAY) && ! cop_interlocks`, and cop_interlocks is
   only the 4300 and 5400; adding `&& mips_cpu != 5900` is the whole change, see
   /home/vbess/rac2-gc-decomp/work/p2/build/scratch/cc1build/gas-mfc1-r5900.diff) this exact C is
   176 bytes and Placement.derive accepts it at the boot place (a MATCH); the same assembler also
   matches func_00290680 (-G8 game profile). The change alters no object of the 636 files of src/
   (535 game-compiled, 101 SDK) and keeps the nop after mtc1. The nop cannot be removed from C:
   `.set mips4` would drop it but cc1 emits no ISA directive and its -mips3/-mips4 do not change
   the .s. The same nop blocks func_00290680 and func_L22_003A2DF8.
   What fixed everything else, against the earlier attempt: `offset = 0;` written after the
   guard (this gives retail's save order $s0 then $s1 and the beql whose delay slot carries the
   loop decrement), the flag computed before `scaled`, and `flag = x != 1` (the xor temporary
   then lands in $v0 as in retail). */
#include "include_asm.h"

#ifndef RAC2_T_U32_FE8672EA5
#define RAC2_T_U32_FE8672EA5
typedef unsigned int u32_Fe8672ea5;
#endif

extern u32_Fe8672ea5 D_L04_001AC18C __attribute__((sda));
extern float D_L04_001AC190 __attribute__((sda));

extern void func_00281EB8(void *a0, u32_Fe8672ea5 a1, u32_Fe8672ea5 a2, int a3, float f12, float f13, float f14);

void func_002ED4B8(void)
{
    u32_Fe8672ea5 offset;
    u32_Fe8672ea5 cursor;
    int i;

    if (D_L04_001AC18C == 0) {
        return;
    }
    offset = 0;
    for (i = 511; i >= 0; i--) {
        cursor = D_L04_001AC18C + offset;
        if (*(u32_Fe8672ea5 *)(cursor + 0x48) != 0) {
            float scaled;
            int flag;
            int x;
            flag = 1;
            x = *(int *)(cursor + 0x3C) >> 1;
            if (x != 0) {
                flag = x != 1;
            }
            scaled = (float)*(int *)(cursor + 0x38) * D_L04_001AC190;
            func_00281EB8((void *)cursor, *(u32_Fe8672ea5 *)(cursor + 0x4C),
                          *(u32_Fe8672ea5 *)(cursor + 0x30) | ((u32_Fe8672ea5)(int)scaled << 24),
                          flag,
                          *(float *)(cursor + 0x28), 0.001f, *(float *)(cursor + 0x24));
        }
        offset += 80;
    }
}
