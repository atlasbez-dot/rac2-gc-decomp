/* func_L23_004256F0 (340 bytes, 1 place: 23:004256F0) -- NEAR MISS, not integrated.
   Measured on 21 October 2026 in a unit of its own (src/levels/23_damosel_orbit/L23_004256F0.c) built with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`: 340 bytes, retail's size (the earlier record's 332 came from
   the folded `sq $v0,0x10($s0)` in the first call's delay slot; the grouped copy keeps `jal ; nop`), the
   single return `daddu $v0,$s0,$zero`, the copy `lq $v0,0($s4) ; sq $v0,0($a2)` with `$a2 = $s0+0x10` and
   the three sample calls are retail's. check.py: "instruction at +0x8 differs", 26 words.
   What still differs:
   - the saves, +0x4..+0x30: the object pointer and a7 take $s3/$s4, retail $s4/$s3;
   - the stores into the sub-record: sched1 puts the four stack-argument stores (a9..a12, each
     `lw ; sw/sb` after reload) first, retail keeps source order (a3, a4, f1..f4, a5, a6, a7, then a9..a12).
   Cause (measured, -dR -fsched-verbose-5, sched1 of the second block): all thirteen stores tie on priority
   (11) and register weight; the four stack-argument stores have seven dependents against five, so they win.
   Their source pseudos are REG_EQUIV to the argument slot (`mem (reg 0)`, the incoming-argument pointer), so
   sched_analyze counts a use of that call-used hard register at each of them, and patch 0029 keeps those uses
   across calls: the second and third `func_002A7940` call get an anti-dependence on each (`151 144` in
   their dependent lists). With the original's volatile asm copy
   (`__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(s0 + 0x10), "r"(obj) : "$2")`, scratch only)
   the file is exact (0 words differ): the asm sits between the stores and the calls and clears the register-use
   lists, so the two calls lose those dependents, the stores tie, the LUID (source order) decides, and the saves
   follow from that schedule. The qcopy insn does not clear them.
   Tried without effect: taking the address of a9..a12 (`s32 *p9 = &a9`) and storing through the pointers
   (the same 26 words, the same code); -frac2-zero-ti-barrier added (no change); 50 single extra cc1 flags (none reaches exact: -fno-schedule-insns 55
   words and 344 bytes, -fno-schedule-insns2 55, -mastra-keep-frame-order 48); from the earlier record: u8 or
   short stack arguments (REG_EQUIV lost, but they are loaded at entry into callee-saved registers) and a local
   copy of obj or of a7. Needs a barrier model for qcopy, or a way to keep the stack-argument stores from
   counting a use of the argument pointer. */


typedef unsigned char u8;

typedef int s32;

typedef int TI16 __attribute__((mode(TI)));

extern void *func_0029EFD0(int size);

extern float func_002A7940(void);

/* allocates the record, fills its sub-record from the arguments, then draws three samples into it */
void *func_L23_004256F0(u8 *obj, u8 *a1, u8 *a2, u8 a3, u8 a4, short a5, short a6, s32 a7, float f1, float f2,
                        float f3, float f4, s32 a9, s32 a10, s32 a11, s32 a12) {
    u8 *s0;
    u8 *v1;

    s0 = func_0029EFD0(0x11AC);
    if (s0 != 0) {
        v1 = *(u8 **)(s0 + 0x68);
        v1[0x28] = a3;
        v1[0x29] = a4;
        *(float *)(v1 + 0x10) = f1;
        *(float *)(v1 + 0x14) = f2;
        *(float *)(v1 + 0x18) = f3;
        *(float *)(v1 + 0x1C) = f4;
        *(short *)(v1 + 0xC) = a5;
        *(short *)(v1 + 0xE) = a6;
        *(s32 *)v1 = a7;
        *(s32 *)(v1 + 4) = a9;
        v1[0x2A] = a10;
        *(s32 *)(v1 + 0x2C) = a11;
        v1[0x2B] = a12;
        s0[0x30] = 0xFF;
        *(u8 **)(s0 + 0xB8) = a1;
        s0[0x20] = 0;
        *(u8 **)(v1 + 0x20) = a2;
        *(u8 **)(v1 + 0x24) = obj;
        *(TI16 *)(s0 + 0x10) = *(TI16 *)obj;
        *(float *)(s0 + 0xF0) = func_002A7940();
        *(float *)(s0 + 0xF4) = func_002A7940();
        *(float *)(s0 + 0xF8) = func_002A7940();
        s0[0x20] = 0;
    }
    return s0;
}
