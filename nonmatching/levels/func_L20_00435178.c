/* 0 of 1 places match - last line: 20_yeedil: instruction at +0xc differs
   Distance test against a per-object threshold: v = func_341B78(object); when v is
   0 and the index argument is not -1, call func_302440(object + 0x10,
   table[arg] + (*(s16 *)(state + 0x1CA) << 4) + 0x10) and set v = 1 when the
   returned float is below *(f32 *)(state + 0x134); return v. The state word at
   0x68 is read after the first call (retail loads it in that call's delay slot),
   and retail ends with the FP compare hazard `c.olt.s $f0,$f1; nop; bc1tl`.
   Measured: three spellings reach 152 ("instruction at +0xc differs") and 160
   bytes against retail's 156 - the extra/missing word is the `nop` this cc1
   schedules differently around that compare and the -1 materialisation.
   Blocker: that FP-compare scheduling (the hazard-`nop` class already recorded
   for func_L04_0039FEA8 and func_L22_003A2DF8). */
typedef char *ptr;
typedef char *ptr;
typedef short s16;
typedef int s32;
typedef float f32;

extern s32 func_L09_00329028(char *);
extern f32 func_00282E80(void *, void *);
extern ptr D_L20_004303C0[];

s32 func_L20_00435178(char *a0, s32 a1)
{
    char *s3;
    s32 v;

    v = func_L09_00329028(a0);
    s3 = *(char **)(a0 + 0x68);
    if (v == 0) {
        if (a1 != -1) {
            f32 f = func_00282E80(a0 + 0x10,
                                  D_L20_004303C0[a1] + (s32)(*(s16 *)(s3 + 0x1CA) << 4) + 0x10);

            if (f < *(f32 *)(s3 + 0x134))
                v = 1;
        }
    }
    return v;
}
