/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * Measured text: 912 bytes; retail: 928 bytes. Stack frame 0xC0; retail 0xC0.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Six-vector table initialization, basis pointer allocation,
 * scalar scheduling and copies differ. Rotation matrices are 48 bytes and separate rotation
 * seed/output vectors preserve the observed copies. Reopen on initialization/local lifetimes
 * or basis pointer walks.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern int D_L26_001A8FF0;
extern Vector D_L26_002967A0[6];
extern Vector D_L26_001B1890;
extern float D_L26_001B0460 __attribute__((sda));
extern float D_L26_001B0464;
extern float D_L26_001B0458 __attribute__((sda));
extern float D_L26_001B045C;
extern int D_L26_001B0468[2] __attribute__((sda));
extern int D_L26_001B0470[2] __attribute__((sda));
extern unsigned char D_L26_001B1748;
extern void func_002833F0(void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern float func_00283B98(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002B0408(void *, void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_L26_00324DE8(unsigned char *, int);
extern int func_00282948(int *);
extern void func_L26_003D4930(unsigned char *);

void func_L26_003D4590(unsigned char *object) {
    Vector position;
    Vector tangent;
    Vector rotation;
    Vector rotation_seed;
    float matrix[12];
    char *private;
    float radius;
    float angle;
    unsigned int selection;
    if (!D_L26_001A8FF0 && object[0x20]) {
        object[0x31] = 0;
        *(unsigned short *)(object + 0x34) |= 1;
        return;
    }
    object[0x31] = 1;
    *(unsigned short *)(object + 0x34) &= 0xFFFE;
    private = *(char **)(object + 0x68);
    if (object[0x20] == 0) {
        if (D_L26_002967A0[0].f[3] == 0.0f) {
            position.q = 0;
            position.f[2] = 2.0943954f;
            func_002833F0(matrix, &position);
            D_L26_002967A0[1].f[3] = 1.0f;
            D_L26_002967A0[0].f[3] = 1.0f;
            func_00283098(D_L26_002967A0 + 2, D_L26_002967A0, matrix);
            func_00283098(D_L26_002967A0 + 3, D_L26_002967A0 + 1, matrix);
            func_00283098(D_L26_002967A0 + 4, D_L26_002967A0 + 2, matrix);
            func_00283098(D_L26_002967A0 + 5, D_L26_002967A0 + 3, matrix);
        }
        *(unsigned short *)(object + 0x32) = 0x200;
        object[0x30] = 0xFF;
        *(unsigned short *)(object + 0x34) |= 0x110;
        func_00282CF0(private + 0x50, object + 0x10, &D_L26_001B1890);
        radius = func_00282DF0(private + 0x50);
        func_00282F20(private + 0x60, object + 0xC0, radius);
        func_00282DD8(private + 0x70, private + 0x60, private + 0x50);
        func_00282F20(private + 0x70, private + 0x70, radius);
        func_00282DD8(private + 0x60, private + 0x50, private + 0x70);
        func_00282F20(private + 0x60, private + 0x60, radius);
        *(float *)(private + 0x188) = func_002A78D8(D_L26_001B0460, D_L26_001B0464) * 0.00029088825f;
        *(float *)(private + 0x180) = func_002A7878(D_L26_001B0458, D_L26_001B045C) * 0.00029088825f;
        *(float *)(private + 0x184) = func_002A7940();
        func_002A7750(object, 1, -1);
    } else if (object[0x20] == 1) {
        *(float *)(private + 0x184) = func_00283B98(*(float *)(private + 0x184), *(float *)(private + 0x180));
        position.f[0] = func_00283180(*(float *)(private + 0x184));
        position.f[1] = func_00283198(*(float *)(private + 0x184));
        position.f[2] = 0.0f;
        func_00283098(object + 0x10, &position, private + 0x50);
        func_00282CC0(object + 0x10, object + 0x10, &D_L26_001B1890);
        angle = func_00283B98(*(float *)(private + 0x184), 1.5707965f);
        tangent.f[0] = func_00283180(angle);
        tangent.f[1] = func_00283198(angle);
        tangent.f[2] = 0.0f;
        func_00283098(&tangent, &tangent, private + 0x50);
        func_002B0408(object + 0xC0, &tangent, 0);
        rotation_seed.q = 0;
        rotation_seed.f[2] = *(float *)(private + 0x188);
        rotation.q = rotation_seed.q;
        func_002833F0(matrix, &rotation);
        func_00283738(object + 0xC0, object + 0xC0, matrix);
        if (!D_L26_001B1748) func_L26_00324DE8(object + 0xC0, 0);
        if (func_00282948((int *)(private + 0x18C))) {
            selection = (object[0xBC] + 1) & 1;
            object[0xBC] = selection;
            *(int *)(object + 0x78) = D_L26_001B0468[selection];
            *(int *)(private + 0x18C) = D_L26_001B0470[selection];
        }
        func_L26_003D4930(object);
    }
}
