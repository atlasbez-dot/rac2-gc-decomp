/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-por.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 * Corrected func_0032C700 to return its allocated 32-bit pointer and to name the final nullable
 * stack pointer as a pointer. Eight GPR inputs, two FP inputs and four stack inputs keep their
 * existing order and values. The original 1544/1536 measurement predates this declaration edit;
 * this corrected source has not been recompiled.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por
 * Measured text: 1544 bytes; retail: 1536 bytes. Stack frame 0x80; retail 0x80.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 3 measured source/profile forms. Eight-byte text gap plus register/control-flow
 * differences. A real shared 16-byte workspace for mutually exclusive death-position and
 * animation-choice uses recovers the retail stack frame. 32C700 keeps all twelve GPR
 * arguments, including stack tail 0,1,0,0, and both floats. B1C20 keeps its 64-bit flag
 * return. Reopen on state dispatch and local lifetimes.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef union { unsigned long long pair[2]; int action[4]; } ActionChoices;
extern int D_L26_001A8FF0;
extern ActionChoices D_L26_001B05C8;
extern float D_L26_001B05C0 __attribute__((sda));
extern float D_00189EA0[4];
extern int func_L26_003DBE18(unsigned char *);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern unsigned long func_002B1C20(void *, void *);
extern void func_00325D30(char *, char *);
extern void func_002A6C58(void *, int, int);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_002E5CF8(int, int, char *);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, void *, float, float);
extern void func_002AB6D8(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002B0A68(char *, int, int, unsigned char, float, float, float, float);
extern void func_0029F338(void *);
extern int func_002A7820(int, int);
extern int func_002B3868(unsigned char *);
extern int func_002A77E0(int);
extern void func_002A7470(void *, int, int, int);
extern int func_L02_00332630(char *, void *);
extern void func_L02_00333438(char *, char *);
extern float func_L26_00324598(unsigned char *, void *, void *);
extern float func_00282C48(float);
extern float func_0029F530(char *);
extern int func_002A8C28(void *, void *, int, int, int, int, float, float, float);
extern void func_L26_003DC048(void *);

void func_L26_003DB818(unsigned char *object) {
    /* Mutually exclusive uses of the same 16-byte retail workspace. */
    union { ActionChoices choices; Vector position; } workspace;
    Vector seed;
    Vector velocity;
    char *private;
    unsigned long flags;
    float time;
    int next;
    int i;
    if (!D_L26_001A8FF0) return;
    private = *(char **)(object + 0x68);
    if (func_L26_003DBE18(object)) goto destroy;
    if (object[0x95] == 0) {
        if (*(short *)(private + 0x224) == 1) {
            func_002A7750(object, object[0x20] == 1 ? 4 : 5, 2);
        } else if (*(short *)(private + 0x226)) {
            func_002A7750(object, 3, 1);
            *(short *)(private + 0x226) = 0;
            if (*(short *)(private + 0x220) < 300)
                *(short *)(private + 0x220) = func_002A7820(480, 600);
        }
    } else if (object[0x95] == 1) {
        if (*(short *)(private + 0x224) == 1)
            func_002A7750(object, 5, 2);
        else if (*(short *)(private + 0x220) == 0 && (object[0x60] & 2))
            func_002A7750(object, 2, 0);
    } else if (object[0x95] == 2) {
        if (*(short *)(private + 0x224) != 1 && object[0x20] != 6) {
            func_002A7750(object, 3, 1);
            *(short *)(private + 0x220) = func_002A7820(580, 600);
        }
    } else if (object[0x95] == 3) {
        flags = func_002B1C20(object, private + 0x50);
        if ((flags & 1) || *(float *)(private + 0x20) <= 0.0f) {
            func_00325D30((char *)object, private + 0x270);
            func_002A6C58(object, 0, 3);
            seed.q = 0;
            seed.f[2] = 1.0f;
            func_00283098(&workspace.position, &seed, object + 0xC0);
            func_00282CC0(&workspace.position, &workspace.position, object + 0x10);
            func_002E5CF8(13, 0, (char *)object);
            func_0032C700(&workspace.position, 0, 25, 20, 20, 20, 45, 0, 0, 1, 0, 0, 0.8f, 20.0f);
            func_002AB6D8(object + 0xC0, object + 0xF0);
            func_00282F20(&velocity, private + 0xD0, 0.083333336f);
            func_002B0A68((char *)object, 0x3F8, (int)&velocity, 0xFF, 3.0f, 6.0f, 3.0f, 6.0f);
            goto destroy;
        }
        if ((flags & 2) || (unsigned char)private[0x6A] > 1) {
            func_002A7750(object, 6, 2);
            *(short *)(private + 0x220) = func_002A7820(580, 600);
        }
    }
    switch (object[0x20]) {
    case 2:
        if (func_002B3868(object) && object[0x43] != 2)
            func_002A7470(object, 2, 0, 20);
        break;
    case 3:
        workspace.choices.pair[0] = D_L26_001B05C8.pair[0];
        workspace.choices.pair[1] = D_L26_001B05C8.pair[1];
        if (func_002B3868(object) && object[0x43] != workspace.choices.action[func_002A77E0(4)])
            func_002A7470(object, workspace.choices.action[func_002A77E0(4)], 0, 20);
        func_L02_00332630((char *)object, D_00189EA0);
        if (object[0x60] & 2) {
            next = workspace.choices.action[func_002A77E0(4)];
            if (next == object[0x43]) next = (next + func_002A77E0(3)) % 4;
            if (object[0x43] != next) func_002A7470(object, next, 0, 20);
        }
        break;
    case 4:
        if (func_002B3868(object) && object[0x43] != 4)
            func_002A7470(object, 4, 0, 10);
        if (object[0x60] & 2) func_002A7750(object, 5, -1);
        break;
    case 5:
        if (func_002B3868(object) && object[0x43] != 8)
            func_002A7470(object, 8, 0, 20);
        func_L02_00333438((char *)object, private + 0x1F0);
        if (!(D_L26_001B05C0 <= *(float *)(private + 0x1CC)) &&
            !(0.17453295f <= func_00282C48(func_L26_00324598(object, private + 0x1F0, private + 0x230))))
            func_002A7750(object, 6, -1);
        break;
    case 6:
        if (func_002B3868(object) && object[0x43] != 9)
            func_002A7470(object, 9, 8, 20);
        if (object[0x60] & 2) func_002A7750(object, 5, -1);
        time = func_0029F530((char *)object);
        if (object[0x42] == object[0x43] && time >= 18.0f && time <= 24.0f) {
            for (i = 0; i < 2; i++)
                func_002A8C28(object, *(char **)(private + 0x270 + i * 4) + 0x10,
                              0x4000001, 0, 1, 0, 0.333f, (float)(unsigned char)private[0x34], 1.0f);
        }
        break;
    }
    func_L26_003DC048(object);
    return;
destroy:
    func_0029F338(object);
}
