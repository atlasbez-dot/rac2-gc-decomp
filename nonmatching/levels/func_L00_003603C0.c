/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
 * Reported final C / retail: 896 / 948 bytes; size equality is not a match.
 * us: 0/27 placements; 896/948 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Interaction branch/vehicle-state sharing, frame allocation and vector scheduling differ. Callback identities are catalogue-resolved 002ECB70 and 002E6B78; A89A8 keeps its float return. All three vectors retain 16-byte extents. Reopen on the original proximity branch and vector lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * Measured text: 896 bytes; retail: 948 bytes. Stack frame 0x70.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Interaction branch/vehicle-state sharing, frame allocation
 * and vector scheduling differ. Callback identities are catalogue-resolved 002ECB70 and
 * 002E6B78; A89A8 keeps its float return. All three vectors retain 16-byte extents. Reopen on
 * the original proximity branch and vector lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef void (*DrawCallback)(void *);
extern int D_L00_001A8F00;
extern char *D_L00_00220DA0[];
extern short D_L00_001A8F80[2];
extern unsigned int D_001A7AF0;
extern Vector D_L00_001B8DC0;
extern Vector D_00189EA0;
extern char *D_0018A15C;
extern unsigned int D_00138324;
extern Vector D_00152C70, D_00152C80;
extern short D_00152C26;
extern int D_L00_001B1AE0;
extern void func_002E64A0(void *);
extern void func_L00_002E6EF8(DrawCallback, void *);
extern void func_L00_002E6CF0(DrawCallback, void *);
extern void func_002ECB70(void *);
extern void func_002E6B78(void *);
extern float func_00282E80(void *, void *);
extern float func_00282E48(void *, void *);
extern float func_00283CE0(int);
extern float func_00283180(float);
extern int func_002B0C28(int, int, int);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A89A8(void *, int, float);
extern float func_00283B98(float, float);
extern int func_L00_003268E8(int);

void func_L00_003603C0(char *object) {
    Vector position;
    Vector offset;
    Vector angles;
    char *private = *(char **)(object + 0x68);
    char **slot;
    char *vehicle;
    float distance;
    unsigned int shade;
    int active_vehicle;
    int available;
    if (!D_L00_001A8F00) func_002E64A0(object);
    if ((unsigned char)object[0x31]) {
        private[0xE] = (unsigned char)private[0xE] + 2;
        for (slot = D_L00_00220DA0; *slot; slot++) {
            if (*(short *)(*slot + 0xAA) == *(short *)((char *)D_L00_001A8F80 + ((D_001A7AF0 >> 3) & 2))) {
                shade = (int)(func_00283180(func_00283CE0((unsigned char)private[0xE] - 128) * 0.024543693f) * 50.0f) + 140;
                *(unsigned int *)(*slot + 0x78) = shade | (shade << 8) | (shade << 16);
                *(unsigned short *)(*slot + 0x34) |= 0x10;
                break;
            }
        }
        func_L00_002E6EF8(func_002ECB70, object);
        if (func_00282E80(object + 0x10, &D_L00_001B8DC0) < 32.0f)
            func_L00_002E6CF0(func_002E6B78, object);
    }
    vehicle = D_0018A15C;
    active_vehicle = vehicle && *(short *)(vehicle + 0xAA) == 0xD54 &&
        (signed char)vehicle[0x20] != -2 && (signed char)vehicle[0x20] != -3;
    if (*(short *)(private + 0xC) == 0) {
        distance = func_00282E80(object + 0x10, &D_00189EA0);
        if (!(8.0f <= distance) || active_vehicle) {
            distance = func_00282E48(object + 0x10, &D_00189EA0);
            if (!(6.0f <= distance) || active_vehicle) *(short *)(private + 0xC) = 1;
        }
    } else {
        distance = func_00282E48(object + 0x10, &D_00189EA0);
        if (!(distance <= 6.1f) && !active_vehicle) *(short *)(private + 0xC) = 0;
    }
    if (*(unsigned short *)(object + 0x34) & 1) *(short *)(private + 0xC) = 0;
    if (*(short *)(private + 0xC)) {
        available = func_002B0C28(2, 0x2798, 1);
        if ((D_00138324 & 0x10) && available) {
            offset.q = 0;
            angles.q = 0;
            offset.f[0] = 1.48f;
            offset.f[1] = 2.64f;
            angles.f[0] = -0.021118486f;
            angles.f[1] = 0.0588176f;
            angles.f[2] = 1.2252212f;
            func_00283098(&position, &offset, object + 0xC0);
            func_00282CC0(&position, &position, object + 0x10);
            position.f[2] = func_002A89A8(&position, 0, 0.5f);
            angles.f[2] = func_00283B98(angles.f[2], *(float *)(object + 0xF8));
            D_00152C70.q = position.q;
            D_00152C80.q = angles.q;
            func_L00_003268E8(2);
            D_00152C26 = 0;
            D_L00_001B1AE0 = 1;
        }
    }
}
