/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections
 * Measured text: 556 bytes; retail: 556 bytes. Stack frame 0x30; retail 0x30.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 4 measured source/profile forms. Equal text size; first mismatch +0x30, with f20/f21
 * allocation and initializer store scheduling differing. Separating height and turn lifetimes
 * recovered the size. Reordering independent initializers improved the constant ordering;
 * -fno-schedule-insns moved the first mismatch earlier and was reverted. Reopen on the live
 * float ranges around initialization.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

extern float D_L26_001B05D8 __attribute__((sda));
extern unsigned short D_L26_001B05E0 __attribute__((sda));
extern unsigned short D_L26_001B05E4;
extern float D_L26_001B8B80[4];
extern float func_002B0360(char *);
extern int func_002A77E0(int);
extern void func_00325B70(char *, char **, int, int);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern void func_002A7470(void *, int, int, int);
extern float func_00282E48(void *, void *);
extern void func_002A93B0(void *);
extern int func_002B0ED8(void *, void *, int);
extern void func_L26_003DC128(void *);
extern int func_002B3BA8(void *, int, void *, int, float, float);
extern void func_00283698(void *, void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00325D30(char *, char *);

int func_L26_003DBE18(unsigned char *object) {
    char *private = *(char **)(object + 0x68);
    float height;
    float turn;
    if (object[0x20] == 0) {
        *(int *)(private + 0x98) = 3;
        *(float *)(private + 0x80) = 1.0f;
        *(float *)(private + 0x8C) = 0.15f;
        private[0x60] = 7;
        *(float *)(private + 0x84) = 0.8f;
        height = func_002B0360((char *)object + 0x10) - 1.5f;
        turn = D_L26_001B05D8;
        *(float *)(private + 0x100) = 1.0f;
        turn *= 0.017453294f;
        *(float *)(private + 0x90) = height;
        *(float *)(private + 0x104) = 0.5f;
        if (func_002A77E0(2)) turn = -turn;
        *(float *)(private + 0x1DC) = turn;
        *(unsigned short *)(private + 0x1E2) = D_L26_001B05E0;
        *(unsigned short *)(private + 0x1E4) = D_L26_001B05E4;
        private[0x2E] = 1;
        *(unsigned short *)(object + 0x34) |= 0x100;
        if (*(float *)(private + 0x20) == 0.0f) {
            *(short *)(private + 0x24) = 3;
            *(float *)(private + 0x20) = 3.0f;
        }
        func_00325B70((char *)object, (char **)(private + 0x270), 0, 2);
        func_002A7750(object, 1, 0);
        if (object[0x43]) func_002A7470(object, 0, 0, 0);
    }
    if (object[0x31] && func_00282E48(object + 0x10, D_L26_001B8B80) < 24.0f) {
        func_002A93B0(object);
        object[0x6F] = 0x16;
    }
    if (func_002B0ED8(object, private + 0x50, 0)) func_L26_003DC128(object);
    *(short *)(private + 0x224) = func_002B3BA8(object, *(int *)(private + 0x210), 0, 0, 16.0f, 0.0f);
    func_00283698(private + 0x230, object + 0xC0);
    func_002AFFD8((char *)object + 0x10, private + 0x260, 0);
    if ((unsigned char)private[0x2E] == 2) {
        func_00325D30((char *)object, private + 0x270);
        return 1;
    }
    return 0;
}
