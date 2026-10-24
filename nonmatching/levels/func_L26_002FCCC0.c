/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 636 bytes; retail: 672 bytes. Stack frame 0xD0; retail 0xD0.
 * Final coverage: US 0/1, US2 absent, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Table/null control flow, base allocation and mixed
 * GP/absolute current-level accesses differ. The transform is 64 bytes and the two input
 * vectors form a real 32-byte array. The ninth BAA28 argument is -1 on the stack. Reopen on
 * source control flow and actual lifetimes; do not introduce a second identity for the
 * current-level word.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern char D_L26_001BC880[];
extern int D_001A79F0 __attribute__((sda));
extern float D_L26_001A9450[2][4] __attribute__((sda));
extern float D_L26_001A9420 __attribute__((sda));
extern float D_L26_001A9424;
extern unsigned int D_L26_001A9428 __attribute__((sda));
extern unsigned int D_L26_001A942C;
extern int D_L26_001A9430 __attribute__((sda));
extern int D_L26_001A9434, D_L26_001A9438, D_L26_001A943C;
extern int D_L26_001A9440, D_L26_001A9444;
extern void func_L00_002FC980(void);
extern void func_002E64A0(void *);
extern void func_L00_00326048(char *, float *, int, int, float);
extern void func_0029FC20(char *, int, char *);
extern void func_002830C0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_002A7878(float, float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern int func_002A7820(int, int);
extern char *func_002BAA28(void *, void *, void *, unsigned int, unsigned int, int, int, int, int);
extern int func_00283CF0(float);

void func_L26_002FCCC0(void) {
    float transform[16];
    Vector position;
    Vector velocity;
    Vector acceleration;
    char *hero = D_L26_001BC880;
    char **slot;
    char *object;
    char *effect;
    unsigned int color;
    int duration;
    int speed;
    int size;
    int i;
    short id;
    func_L00_002FC980();
    slot = (char **)(hero + 0x18C);
    for (i = 0; i < *(short *)(hero + 0x44); i++, slot++) {
        object = *slot;
        id = *(short *)(object + 0xAA);
        if (object && id == 0xE29) {
            *(unsigned short *)(object + 0x34) |= 0x800;
            id = *(short *)(object + 0xAA);
        }
        if (id == 0xD54) func_002E64A0(object);
        if (object && *(short *)(object + 0xAA) == 4000 && *(char **)(object + 0x68))
            func_L00_00326048(object, (float *)(*(char **)(object + 0x68) + 0xC),
                              (int)0x80AAAAD2, (int)0x80396464, 0.061086535f);
    }
    if (D_001A79F0 == 26 && *(int *)(hero + 0x30) == 0 && *(int *)(hero + 0x34) < 260) {
        object = *(char **)(hero + 0x198);
        func_0029FC20(object, 0, (char *)transform);
        *(Quad *)(transform + 12) = *(Quad *)(object + 0x10);
        for (i = 0; i < 8; i++) {
            func_002830C0(&position, D_L26_001A9450[i & 1], transform);
            func_00282F20(&velocity, transform, 0.06666667f);
            velocity.f[3] = D_L26_001A9420;
            acceleration.q = 0;
            acceleration.f[3] = D_L26_001A9424;
            color = func_00283D38(D_L26_001A9428, D_L26_001A942C, func_002A7878(0.0f, 1.0f));
            duration = func_002A7820(D_L26_001A9430, D_L26_001A9434);
            speed = func_002A7820(D_L26_001A9438, D_L26_001A943C);
            size = func_002A7820(D_L26_001A9440, D_L26_001A9444);
            effect = func_002BAA28(&position, &velocity, &acceleration, color, color & 0xFFFFFF,
                                   duration, speed, size, -1);
            if (effect) effect[9] = func_00283CF0(2.0f) - 16;
        }
    }
}
