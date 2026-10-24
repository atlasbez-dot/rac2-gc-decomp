/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections
 * Measured text: 1904 bytes; retail: 1988 bytes. Stack frame 0x50; retail 0x50.
 * Final coverage: US 0/1, US2 0/1, PAL absent. Absences are not matches.
 * 2 measured source/profile forms. Camera-control branches, interpolation scalar lifetimes
 * and addresses differ. Current helper definitions and call inputs were checked; ACBC8
 * retains its live index, and floating clamp polarity preserves the retail selection. Reopen
 * on camera-setting scalar lifetimes and branch structure.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

extern char *D_L26_001B15C4;
extern char *D_L26_001B8BD0;
extern int D_L26_001A8FF0;
extern int D_001A79F0;
extern int D_0018C0B4;
extern int D_0018C0BC;
extern unsigned char D_0018C0D4;
extern unsigned char D_0018A2BE;
extern short D_0018B274;
extern float D_0018A340;
extern float D_00189F90;
extern float D_00138280, D_00138284;
extern float D_00189EA0[4], D_00189ED0[4];
extern float D_L26_001B8B80[4];
extern char *D_0018C0B0;
extern float D_L26_001B133C __attribute__((sda));
extern float D_L26_001B1344 __attribute__((sda));
extern float D_L26_001B1348 __attribute__((sda));
extern float D_L26_001B134C __attribute__((sda));
extern float D_L26_001B1350 __attribute__((sda));
extern float D_L26_001B1354 __attribute__((sda));
extern float D_L26_001B1358 __attribute__((sda));
extern float D_L26_001B135C __attribute__((sda));
extern float D_L26_001B1360 __attribute__((sda));
extern float D_L26_001B1364 __attribute__((sda));
extern float D_L26_001B1368 __attribute__((sda));
extern float D_L26_001B136C __attribute__((sda));
extern float D_L26_001B1370 __attribute__((sda));
extern float D_L26_001B11BC __attribute__((sda));
extern int D_L26_001B17CC __attribute__((sda));
extern float func_00282E48(void *, void *);
extern float func_002B0360(char *);
extern int func_L00_00424940(int);
extern int func_L00_00424978(char *);
extern int func_002ACBC8(void *, int);
extern float func_00282C48(float);
extern void func_L00_00424C00(void);
extern void func_L00_00424B48(int);
extern void func_L00_00424C28(void);
extern void func_L00_00424B70(float, float);
extern int func_00282948(int *);
extern void func_L00_00424F00(char *, float, float);
extern float func_L00_002D2A10(float, float, float);
extern int func_00283CF0(float);
extern void func_L16_0042FB58(float, float);
extern void func_L00_00424BB8(float, float);
extern void func_L00_00424A88(int, float, float);
extern void func_L00_00424A08(int, float, float);
extern void func_L00_00424A50(float, float);
extern void func_L00_00424B20(float);

void func_L26_0041C598(char *object) {
    float point[4];
    char *record = D_L26_001B15C4 + *(short *)(object + 0x84) * 32;
    char *settings = *(char **)(record + 0x1C);
    float distance;
    float factor;
    float first;
    float second;
    int i;
    int duration;
    if (*(int *)(settings + 0x20) == 0) {
        if (!D_L26_001A8FF0 && (D_001A79F0 != 16 || D_0018C0B4 != 0x81)) return;
        point[0] = *(float *)record;
        point[1] = *(float *)(record + 4);
        point[2] = *(float *)(record + 8);
        point[3] = 0.0f;
        *(float *)(settings + 0x24) = func_00282E48(point, D_00189ED0);
        *(int *)(settings + 0x20) = 1;
    } else if (*(short *)(D_L26_001B8BD0 + 0x86) == 0 &&
               (D_L26_001A8FF0 || (D_001A79F0 == 16 && D_0018C0B4 == 0x81))) {
        if (func_L00_00424978(object) <= 0) return;
        for (i = 0; i < 6; i++) {
            int index = *(int *)(settings + 0x28 + i * 4);
            if (index < 0) break;
            if (func_002ACBC8(D_00189EA0, index)) {
                func_L16_0042FB58(0.04f, 0.2f);
                func_L00_00424A08(0, *(float *)(settings + 0x40), 0.003f);
                func_L00_00424A50(*(float *)(settings + 0x44), 0.003f);
                return;
            }
        }
        if (D_0018C0D4 != 2 || D_0018B274 != 0 || D_0018C0B4 == 0x5B ||
            func_00282C48(D_00138280) >= 0.3f || func_00282C48(D_00138284) >= 0.3f) {
            func_L00_00424C00();
            func_L00_00424B48(0);
        }
        func_L00_00424C28();
        func_L00_00424B70(D_L26_001B1344, 0.2f);
        if (func_00282948((int *)(settings + 0x50)) && D_00189F90 <= 0.005f)
            func_L00_00424F00(D_0018C0B0 + 0xC0, 0.0052359886f, 0.0f);
        if (func_00282C48(D_00138280) >= 0.3f || func_00282C48(D_00138284) >= 0.3f)
            *(int *)(settings + 0x50) = 300;
        if (D_0018C0D4 == 2) {
            *(int *)(*(char **)(D_L26_001B8BD0 + 0x70) + 0x250) = 2;
            duration = 0;
            if (D_0018A2BE)
                duration = func_00283CF0(func_L00_002D2A10(90.0f, D_0018A340, -1.0f));
            if (D_0018C0B4 == 0x5B && (!D_0018A2BE || duration > 19)) {
                func_L00_00424B70(0.5f, 1.0f);
                func_L16_0042FB58(0.05f, 0.2f);
                func_L00_00424BB8(0.04f, 0.0f);
                func_L00_00424A88(0, D_L26_001B1364, 0.005f);
                func_L00_00424A08(1, D_L26_001B1358, 0.01f);
                func_L00_00424A50(D_L26_001B135C, 0.01f);
                D_L26_001B11BC = D_L26_001B136C * 0.017453294f;
                func_L00_00424B20(D_L26_001B1368 * 0.017453294f);
            } else {
                func_L00_00424A88(0, D_L26_001B1360, 0.03f);
                if (D_0018C0BC == 2) func_L16_0042FB58(0.04f, 0.2f);
                else func_L16_0042FB58(0.015f, 0.2f);
                distance = func_00282E48(D_00189EA0, D_00189ED0) - *(float *)(settings + 0x24);
                factor = D_L26_001B133C;
                if (distance <= D_L26_001B133C) factor = distance < 0.0f ? 0.0f : distance;
                factor /= D_L26_001B133C;
                second = (D_L26_001B1354 - D_L26_001B134C) * factor + D_L26_001B134C;
                first = (D_L26_001B1350 - D_L26_001B1348) * factor + D_L26_001B1348;
                func_L00_00424A08(1, first, 0.005f);
                func_L00_00424A50(second, 0.005f);
            }
            D_L26_001B17CC = func_002B0360((char *)D_L26_001B8B80) > D_L26_001B1370 ? 3 : 0;
        } else if (D_0018C0B4 == 0x81) {
            func_L16_0042FB58(0.05f, 0.2f);
            func_L00_00424BB8(0.04f, 0.0f);
            if (D_001A79F0 == 16) {
                func_L00_00424A88(0, 0.5f, 0.04f);
                func_L00_00424A08(0, 4.0f, 0.002f);
                func_L00_00424A50(2.0f, 0.04f);
            } else {
                func_L00_00424A88(0, 1.0f, 0.04f);
                func_L00_00424A08(0, 2.0f, 0.002f);
                func_L00_00424A50(7.0f, 0.04f);
            }
        } else {
            if (D_0018C0BC == 2) func_L16_0042FB58(0.04f, 0.2f);
            else func_L16_0042FB58(0.015f, 0.2f);
            if (D_0018C0BC != 5) {
                distance = func_00282E48(D_00189EA0, D_00189ED0) - *(float *)(settings + 0x24);
                factor = D_L26_001B133C;
                if (distance <= D_L26_001B133C) factor = distance < 0.0f ? 0.0f : distance;
                factor /= D_L26_001B133C;
                second = (*(float *)(settings + 0x4C) - *(float *)(settings + 0x44)) * factor + *(float *)(settings + 0x44);
                first = (*(float *)(settings + 0x48) - *(float *)(settings + 0x40)) * factor + *(float *)(settings + 0x40);
                func_L00_00424A08(0, first, 0.003f);
                func_L00_00424A50(second, 0.003f);
            } else {
                func_L00_00424A08(0, 4.0f, 0.003f);
                func_L00_00424A50(6.0f, 0.003f);
            }
        }
    } else {
        D_L26_001B17CC = func_002B0360((char *)D_L26_001B8B80) > D_L26_001B1370 ? 3 : 0;
        func_L00_00424940((int)object);
    }
}
