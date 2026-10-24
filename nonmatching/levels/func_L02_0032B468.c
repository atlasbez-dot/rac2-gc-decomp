/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * US: 828 versus 840; union vectors fix scalar/TI alias lowering and most copy blocks; float/divide scheduling and delay slots remain.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

typedef int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float f[4]; } Vec4;
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern char *func_0029EFD0(int kind);
extern void func_002833F0(void *, void *);
extern float func_002A7878(float, float);
extern int func_00283CF0(float);
extern float func_00282DF0(void *);
extern void func_002A7A00(void *, float, float);
extern void func_00282D30(void *, void *, float);
extern void func_002A0F48(void *);

char *func_L02_0032B468(char *source, int kind, TI128 *position, void *rotation,
                      int lifetime, int flags, TI128 *velocity, TI128 *spin,
                      TI128 *bounds, float speed) {
    Vec4 temporary;
    unsigned char *object = (unsigned char *)func_0029EFD0(kind);
    char *state;
    float scale, angle, radial;
    if (object) {
    *(float *)(object + 0x2C) = *(float *)(*(char **)(object + 0x24) + 0x24) *
        (*(float *)(source + 0x2C) / *(float *)(*(char **)(source + 0x24) + 0x24));
    *(char *)(object + 0x31) = 1;
    *(unsigned short *)(object + 0x34) |= 0x100;
    state = *(char **)(object + 0x68);
    *(long long *)(object + 0x38) = *(long long *)(source + 0x38);
    object[0x20] = 1;
    *(TI128 *)(object + 0x10) = *position;
    func_002833F0(object + 0xC0, rotation);
    object[0x30] = 0xFF;
    *(short *)(object + 0x32) = 0x80;
    *(int *)(object + 0x98) = 0;
    if (!lifetime) *(int *)(state + 0x30) = func_00283CF0(func_002A7878(60.0f, 120.0f));
    else *(int *)(state + 0x30) = lifetime;
    *(int *)(state + 0x34) = flags;
    if (*(float *)(state + 0x38) == 0.0f)
        *(float *)(state + 0x38) = func_002A7878(10.0f, 15.0f) * 0.00027777778f;
    else *(float *)(state + 0x38) = speed;
    if (func_00282DF0(velocity) == 0.0f) {
        angle = func_002A7940();
        radial = func_002A7878(2.0f, 4.0f) * (1.0f / 60.0f);
        temporary.f[0] = func_00283180(angle) * radial;
        temporary.f[1] = func_00283198(angle) * radial;
        temporary.f[2] = 0.0f;
        temporary.f[2] = func_002A7878(5.0f, 8.0f) * (1.0f / 60.0f);
        *(TI128 *)state = temporary.q;
    } else *(TI128 *)state = *velocity;
    if (func_00282DF0(spin) == 0.0f) {
        func_002A7A00(&temporary, 0.052359887f, 0.10471977f);
        *(TI128 *)(state + 0x10) = temporary.q;
    } else *(TI128 *)(state + 0x10) = *spin;
    if (func_00282DF0(bounds) == 0.0f && ((float *)bounds)[3] == 0.0f) {
        temporary.q = *(TI128 *)(*(char **)(object + 0x24) + 0x30);
        {
            float boundsScale = *(float *)(object + 0x2C) * 0.0009765625f;
            func_00282D30(&temporary, &temporary, boundsScale);
            temporary.f[3] *= boundsScale;
        }
        *(TI128 *)(state + 0x20) = temporary.q;
    } else *(TI128 *)(state + 0x20) = *bounds;
    func_002A0F48(object);
    }
    return object;
}
