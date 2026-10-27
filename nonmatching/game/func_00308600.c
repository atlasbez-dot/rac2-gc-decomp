/* Current final accounting: 356/360 bytes; us0/28 and us2 0/28, exit1; PAL absent, exit1, not a match. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse. Full retained body was checked in its temporary unit; markers and trial profiles were restored afterward. No strict build or native-behavior claim. */

/* Single sentinel-spelling control: assigning-1 through the existing unsigned byte type still becomes RTL byte255 before CSE1; the complete object is unchanged. The original255 spelling is retained below. */

/* 25 October 2026 diagnostic follow-up; retained near miss, not linked.
 * Initial RTL constructs separate halfword and byte255 values. CSE1 removes the
 * byte definition and reuses a lowpart of the halfword value, before allocation.
 * The position/vector/count allocation scores also tie in the measured dumps.
 * Restoring the missing instruction could change that tie, but this is an isolated
 * sensitivity model, not a compiled fix or proof of the original source.
 * The colour setter touches the separate64-bit colour field; it does not establish
 * a different flag width or justify using its incidental return for the byte flag.
 * Reopen only on independent cross-mode CSE or real source-lifetime evidence with
 * controls. Do not repeat typed-field/short-argument/helper/flag sweeps.
 */

/* Retained near miss: 356 bytes versus 360 retail bytes; 0/28 places match.
 * Trial profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 *                -frac2-qcopy-barrier -fno-gcse.
 * The copy profiles reproduce both grouped transfers. Disabling GCSE and
 * initializing the bounds after the copies restores the saved f20/f21 values
 * and 0x50-byte frame. Initial field stores still share one 255 constant where
 * retail materializes two, and saved integer-register allocation differs.
 * A short third argument only reaches 360 by adding unwanted sign extension;
 * it is not a match. Typed fields and scheduler/CSE toggles did not fix this.
 * Reopen with evidence for the original field types or constant lifetimes.
 */
typedef int TI128 __attribute__((mode(TI)));

extern unsigned char *func_0029EFD0(int);
extern int func_002A0488(void *, int, int, int);
extern float func_002A7878(float, float);
extern void func_002A0F48(void *);

unsigned char *func_00308600(char *position, char *vector, int count, int mode, int flag)
{
    unsigned char *p = func_0029EFD0(0x7A);
    char *state;
    float lo;
    float hi;

    if (p != 0) {
        p[0x31] = 1;
        p[0x23] = 0x80;
        *(short *)(p + 0x32) = 0xFF;
        state = *(char **)(p + 0x68);
        p[0x30] = 0xFF;
        func_002A0488(p, 0x7F, 0x7F, 0x7F);
        *(TI128 *)(p + 0x10) = *(TI128 *)position;
        *(TI128 *)state = *(TI128 *)vector;
        lo = 0.1047197729f;
        hi = 0.2094395458f;
        *(float *)(state + 0x10) = func_002A7878(lo, hi);
        *(float *)(state + 0x14) = func_002A7878(lo, hi);
        *(short *)(state + 0x18) = (short)count;
        *(short *)(state + 0x1A) = (short)count;
        if (mode == 2) {
            mode = 1;
            *(int *)(state + 0x20) = mode;
        }
        if (mode == 0)
            *(float *)(p + 0x2C) *= func_002A7878(0.5f, 0.75f);
        *(float *)(state + 0x1C) = *(float *)(p + 0x2C);
        p[0xBC] = (unsigned char)(mode | (flag << 1));
        func_002A0F48(p);
    }
    return p;
}
