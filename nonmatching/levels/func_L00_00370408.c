/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 1080 / 1112 bytes; size equality is not a match.
 * us: 0/27 placements; 1080/1112 bytes.
 * us2: 0/27 placements; 1080/1112 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Sequence-controller state/base expressions, branches and saved-register lifetimes differ. Startup, abort, object interpolation/update and all teardown calls are complete. F5AF8 keeps its integer return and the button mask keeps all 64 bits. Reopen on the original controller-field expressions and actor-loop lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 1080 bytes; retail: 1112 bytes. Stack frame 0x80.
 * Final coverage: US 0/27, US2 0/27, PAL absent. Absences are not matches.
 * 1 measured source/profile forms. Sequence-controller state/base expressions, branches and
 * saved-register lifetimes differ. Startup, abort, object interpolation/update and all
 * teardown calls are complete. F5AF8 keeps its integer return and the button mask keeps all
 * 64 bits. Reopen on the original controller-field expressions and actor-loop lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_001BCAC0[];
extern char D_L00_001BEFC0[];
extern float D_L00_001B18E0;
extern unsigned int D_001A7A08;
extern int D_001A7478, D_001A79F0, D_001A7B90;
extern unsigned long long D_00138320;
extern short D_001A63AC;
extern void func_00288BB8(void *);
extern int func_002B4B70(int, int);
extern void func_002F5220(void);
extern void func_L00_002FC7A8(void);
extern void func_002B6658(void);
extern void func_002E5F60(void);
extern void func_L00_002A6DD0(void);
extern void func_002B9390(void);
extern float func_002AA2E8(float *, float, float);
extern int func_002B6D28(void);
extern int func_00288BE8(void *);
extern short func_002B7CE0(int);
extern void func_00293D30(void);
extern int func_L00_003046D0(int);
extern int func_002F5AF8(void);
extern void func_0029F390(unsigned char *);
extern float func_00283CE0(int);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002A0F48(unsigned char *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern void func_002ECB70(void *);
extern void func_002A93B0(void *);
extern void func_L00_002D4E58(void *, int);
extern void func_L00_002A70F8(void *);
extern void func_L00_002FCBE8(void);
extern void func_002E4AC8(void);
extern void func_002914B8(void);
extern void func_0029FFB8(void);
extern void func_002F52B8(void);

void func_L00_00370408(void) {
    float first[4];
    float second[4];
    char *state = D_L00_001BCAC0;
    unsigned char *object;
    char *path;
    int abort;
    int threshold;
    int complete;
    int i;
    short id;
    if (*(int *)(state + 0x58)) return;
    if (*(int *)(state + 0x40) == 0) {
        func_00288BB8(D_L00_001BEFC0);
        *(int *)(state + 0x58) = 1;
        func_002B4B70(0, 0);
        return;
    }
    func_002F5220();
    func_L00_002FC7A8();
    func_002B6658();
    func_002E5F60();
    func_L00_002A6DD0();
    func_002B9390();
    ++*(int *)(state + 0x34);
    ++*(int *)(state + 0x38);
    if (*(int *)(state + 0x34) < 18) {
        func_002AA2E8(&D_L00_001B18E0, 0.0f, 0.16666667f);
        if (D_L00_001B18E0 > 1.0f) D_L00_001B18E0 = 1.0f;
    }
    if (*(int *)(state + 0x48) <= *(int *)(state + 0x34)) func_002B6D28();
    abort = 0;
    if (*(int *)(state + 0x34) > 17 && D_L00_001B18E0 == 0.0f) {
        if (((D_001A7A08 & 0xFFFF0000u) == 0 && D_001A7478 == 0 && D_001A79F0 > 0) ||
            !((unsigned int)(D_00138320 >> 32) & 0x800)) {
            if ((D_00138320 & 0x8000000000FULL) == 0x8000000000FULL) abort = 1;
        } else abort = 1;
    }
    if (abort) {
        *(int *)(D_L00_001BEFC0 + 0x3C) = 1;
        func_00288BB8(D_L00_001BEFC0);
        *(int *)(state + 0x58) = 1;
    } else {
        if (*(int *)(state + 0x34) < *(int *)(state + 0x40)) {
            threshold = D_001A7B90 ? 80 : 96;
            if (*(int *)(state + 0x38) >= threshold) {
                ++*(int *)(state + 0x3C);
                if (D_001A63AC) func_002B7CE0(1);
                func_00293D30();
                func_L00_003046D0(*(int *)(state + 0x3C) + 1);
            }
            complete = func_002F5AF8();
            for (i = 0; i < *(int *)(state + 0x44); i++) {
                object = *(unsigned char **)(state + 0x18C + i * 4);
                object[0x41] = (*(int *)(state + 0x38) >> 1) + 1;
                object[0x40] = *(int *)(state + 0x38) >> 1;
                func_0029F390(object);
                *(float *)(object + 0x44) = func_00283CE0(*(int *)(state + 0x38) & 1) * 0.5f;
                if (complete && (*(int *)(state + 0x38) & 1)) *(float *)(object + 0x44) = 1.0f;
                path = *(char **)(object + 0x68);
                func_00282D30(first, path + object[0x40] * 16, 1.0f - *(float *)(object + 0x44));
                func_00282D30(second, path + object[0x41] * 16, *(float *)(object + 0x44));
                func_00282CC0(object + 0x10, first, second);
                object[0x61] = 0xFF;
                func_002A0F48(object);
                if (*(short *)(object + 0xAA) == 0xD54) func_L00_002E6EF8(func_002ECB70, object);
                if (object[0x6F]) func_002A93B0(object);
                id = *(short *)(object + 0xAA);
                if (id == 0 || id == 0xF6B) func_L00_002D4E58(object, 0);
                id = *(short *)(object + 0xAA);
                if (id == 10 || id == 0x1159 || id == 0x57 || id == 0xD6B) func_L00_002A70F8(object);
            }
            goto finish;
        }
        *(int *)(state + 0x58) = 1;
        if (func_00288BE8(D_L00_001BEFC0)) goto finish;
    }
    func_002B4B70(0, 0);
finish:
    func_L00_002FCBE8();
    func_002E4AC8();
    func_002914B8();
    func_0029FFB8();
    func_002F52B8();
}
