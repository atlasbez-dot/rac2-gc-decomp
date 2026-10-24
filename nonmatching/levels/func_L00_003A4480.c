/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Manual fragment/smoke loops1096/1104 with qcopy/barrier G8.
 * Remaining: Scalar and vector lifetimes, table address formation and particle-call setup differ. Conditional drift-buffer initialization follows retail and needs semantic investigation before native-port use.
 * Reopen with typed effect state and lifetime/ABI witnesses.
 * The qualified R5900 view decodes the cited SPECIAL2 word as por, not an unknown instruction.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* MMI (SPECIAL2) instruction: no C spelling. 1104 bytes, level
   00_aranos_tutorial. Retail at 0x003A4480 carries the SPECIAL2 word
   0x700014A9 (+0x0014) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern float D_0018A550[4], D_0018A560[4], D_00189F30[4];
extern int D_0018A160 NOT_SDA;
extern float D_L00_001AF62C __attribute__((sda));
extern float D_L00_001AF630 __attribute__((sda));
extern int D_L00_001AF634 __attribute__((sda));
extern int D_L00_001AF638 __attribute__((sda));
extern unsigned int D_L00_001AF63C __attribute__((sda));
extern float D_L00_001AF640 __attribute__((sda));
extern float D_L00_001AF644 __attribute__((sda));
extern float D_L00_001AF648 __attribute__((sda));
extern float D_L00_001AF64C __attribute__((sda));
extern float D_L00_001AF650 __attribute__((sda));
extern float D_L00_001AF654 __attribute__((sda));
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACEC0(void *, void *, void *, float);
extern float func_002A7878(float, float);
extern float func_00283B98(float, float);
extern void func_00282D30(void *, void *, float);
extern char *func_L00_00333F90(void *, void *);
extern float func_00282C48(float);
extern void func_002AB668(void *, int, float);
extern void func_002ACDE8(void *, void *, void *);
extern float func_002A78D8(float, float);
extern int func_00283CF0(float);
extern void func_00282CF0(void *, void *, void *);
extern void func_002C16C0(void *, void *, unsigned int, int, int, int, float, float, float, float, float);

/* Emit a rotating fan of fragments followed by smoke particles. */
void func_L00_003A4480(char *moby)
{
    float rotation[4], direction[4], base[4], origin[4], velocity[4], jitter[4], drift[4];
    float angle = 0.0f;
    int count;
    *(VectorBits *)base = 0;
    base[0] = 0.3f;
    base[1] = -1.0f;
    base[3] = 1.0f;
    func_00283098(base, base, moby + 0xC0);
    func_00282CC0(origin, moby + 0x10, base);
    *(unsigned char *)(moby + 0xBC) = 6;
    func_002ACEC0(base, D_0018A550, D_0018A560, 0.3490659595f);
    *(VectorBits *)direction = *(VectorBits *)base;
    for (count = 19; count >= 0; count--) {
        char *fragment;
        angle = func_00283B98(angle, func_002A7878(0.0f, 0.6283186078f));
        func_00282D30(velocity, direction, func_002A7878(0.1000000089f, 0.3f));
        fragment = func_L00_00333F90(origin, velocity);
        if (fragment) {
            func_00282D30(velocity, direction, 0.75f);
            func_00282CC0(fragment + 0x10, origin, velocity);
            *(VectorBits *)(fragment + 0x20) = *(VectorBits *)origin;
            *(float *)(fragment + 0x3C) = 2.0f;
            *(int *)(fragment + 0xC) = 0x307F7F7F;
            *(float *)(fragment + 0x1C) = 0.05f;
            *(float *)(fragment + 0x2C) = 0.5f;
            *(int *)(fragment + 4) = 0x307F7F7F;
        }
        if (func_00282C48(angle) > 0.00001f) {
            func_002AB668(rotation, (int)D_0018A550, angle);
            func_002ACDE8(direction, base, rotation);
        }
    }
    angle = 0.0f;
    func_002ACEC0(base, D_0018A550, D_0018A560, D_L00_001AF62C * 0.017453294f);
    *(VectorBits *)direction = *(VectorBits *)base;
    if (D_0018A160)
        func_00282D30(drift, D_00189F30, 1.7f);
    for (count = 19; count >= 0; count--) {
        unsigned int color;
        int spin;
        float size;
        angle = func_00283B98(angle, func_002A7878(0.0f, 0.6283186078f));
        func_00282D30(velocity, direction, func_002A7878(D_L00_001AF644 * (1.0f / 60.0f),
                                                       D_L00_001AF648 * (1.0f / 60.0f)));
        func_00282CC0(velocity, velocity, drift);
        color = D_L00_001AF63C;
        spin = func_00283CF0(func_002A78D8(1.0f, 2.0f));
        jitter[0] = origin[0] + func_002A78D8(0.0f, D_L00_001AF630);
        jitter[1] = origin[1] + func_002A78D8(0.0f, D_L00_001AF630);
        jitter[2] = origin[2] + func_002A78D8(0.0f, D_L00_001AF630);
        size = func_002A7878(D_L00_001AF64C, D_L00_001AF650) * 210000.0f;
        func_00282CF0(jitter, jitter, velocity);
        func_002C16C0(jitter, velocity, color, D_L00_001AF634, D_L00_001AF638, spin,
                      size, D_L00_001AF654, D_L00_001AF640, 0.0f, 0.0f);
        if (func_00282C48(angle) > 0.00001f) {
            func_002AB668(rotation, (int)D_0018A550, angle);
            func_002ACDE8(direction, base, rotation);
        }
    }
}
