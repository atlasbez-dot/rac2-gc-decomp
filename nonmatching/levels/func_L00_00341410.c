/* Readable C reconstruction, measured 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/27, us2: 0/27, pal: not carried.
 * 580 bytes, retail580. Raw US instruction diff shows three permuted argument moves at +0xF8; relocation derivation stops at that mismatch.
 * Tried: Scalar/vector union and partial owner types, source lifetime/colour store spelling and -g profile. Several final forms tie.
 * Reopen: A demonstrated argument scheduling remedy for the transform call.
 * Historical screening notes follow unchanged. No handwritten-assembly inference.
 */

/* func_L00_00341410 - 580 bytes, 27 places (every level), retail at 0x00341410.
 *
 * Screened, not matched in wave 13 (worker s1): 15 call(s), no $gp-relative small-data
 * access, MMI words [lq $s6 / sq $v1].  The 16-byte copy is retail's
 * materialised-pointer form and the tested source forms folded a constant offset into the
 * lq/sq pair.  Twenty spellings were measured and all of them fold it.  No C was
 * written in this wave.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct {
    unsigned char unknown_00[0x10];
    Vector position;
    unsigned char unknown_20[0xA0];
    float matrix[16];
} ParticleOwner;
extern unsigned char *func_002B9030(int);
extern int func_00283CF0(float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern int func_002A7820(int, int);
extern float func_002A7940(void);
extern unsigned char *D_L00_001FEAF8;
extern void func_00282C88(Quadword *);
extern void func_00283098(void *, const void *, const void *);
extern void func_00282CC0(void *, const void *, const void *);
extern void func_002FE8D8(void *, void *);
extern void func_00282D30(void *, const void *, float);

unsigned char *func_L00_00341410(ParticleOwner *owner, Quadword *position,
                              int flags, int minimum, int maximum, float scale) {
    union { Quadword q; float f[4]; } direction;
    unsigned char *particle = func_002B9030(0x6E);
    unsigned char *motion;
    Vector *origin;
    int shade;
    if (particle) {
        motion = particle + 0x20;
        particle[9] = func_00283CF0(4.0f) + 0x40;
        particle[3] = flags;
        particle[1] = 0;
        particle[8] = func_002A77E0(255);
        particle[2] = *D_L00_001FEAF8;
        *(short *)(particle + 0xA) = func_002A7820(minimum, maximum);
        *(int *)(motion + 0x18) = *(short *)(particle + 0xA);
        *(float *)(particle + 0xC) = scale * 630000.0f;
        if (((float *)position)[3] == -1.0f) {
            Vector *basis = &owner->position;
            func_00282C88(&direction.q);
            direction.f[3] = 1.0f;
            direction.f[0] = -0.3f;
            func_00283098(&direction, &direction, owner->matrix);
            func_00282CC0(particle + 0x10, &direction, basis);
        } else {
            *(Quadword *)(particle + 0x10) = *position;
        }
        origin = &owner->position;
        *(float *)(particle + 0x10) += func_002A7878(-0.015f, 0.015f);
        *(float *)(particle + 0x14) += func_002A7878(-0.015f, 0.015f);
        *(float *)(particle + 0x18) += func_002A7878(-0.015f, 0.015f);
        func_002FE8D8(origin, &direction);
        func_00282D30(motion, &direction, func_002A7878(0.01f, 0.015f));
        *(int *)(motion + 0x10) = func_002A7820(80, 200);
        shade = func_002A7820(96, 128);
        *(int *)(motion + 0x14) = shade + (shade << 8) + (shade << 16);
        *(unsigned int *)(particle + 4) = *(int *)(motion + 0x14) | (*(unsigned int *)(motion + 0x10) << 24);
    }
    return particle;
}
