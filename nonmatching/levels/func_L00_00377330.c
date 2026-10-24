/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 588 / 588 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Equal text size and retail stack frame; first mismatch +0x10C. The color select uses reversed constants with MOVN instead of MOVZ, and later coordinate/row GPR allocation differs. Scalar macro addressing at G0 recovers 12 bytes; ordinary select-source variants do not resolve the color mismatch. Reopen on conditional selection and coordinate lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 588 bytes; retail: 588 bytes. Stack frame 0x150.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 4 measured source/profile forms. Equal text size and retail stack frame; first mismatch
 * +0x10C. The color select uses reversed constants with MOVN instead of MOVZ, and later
 * coordinate/row GPR allocation differs. Scalar macro addressing at G0 recovers 12 bytes;
 * ordinary select-source variants do not resolve the color mismatch. Reopen on conditional
 * selection and coordinate lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_001A79F8 __attribute__((sda));
extern int D_001A7B90 __attribute__((sda));
extern int func_00288FB8(int);
extern void func_0027FA10(int, int, unsigned long long, unsigned char *, int);
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern void func_002F9BC0(char *, int);
extern void func_0027F5B8(int, int, unsigned long long, unsigned char *, int);
extern unsigned int func_L00_002F3DD0(int);
extern int func_0027FB40(int, int, unsigned long long, unsigned char *, int);

void func_L00_00377330(void) {
    unsigned int colors[4];
    char text[256];
    char *model = D_L00_0022F7C0;
    int price = *(int *)(model + 0x144 + *(int *)(model + 0x80) * 12);
    int y;
    int normal_y;
    unsigned long long color;
    if (price > 0) {
        func_0027FA10(140, (int)(D_L00_001B25E0 * 290.0f + 0.5f), 0x80F0F0F0ULL,
                      (unsigned char *)func_00288FB8(0x114E), -1);
        colors[0] = 0x60F0F0B0;
        colors[1] = 0x60F0F0B0;
        colors[2] = 0x60F0F0B0;
        colors[3] = 0x60F0F0B0;
        func_0028EA58(func_0028E588(0x7567, 0), 156,
                      (int)(D_L00_001B25E0 * 290.0f + 0.5f), 16,
                      (int)(D_L00_001B25E0 * 16.0f + 0.5f), colors);
        func_002F9BC0(text, price);
        color = 0x802020F0ULL;
        if (price <= D_001A79F8) color = 0x80F0F0F0ULL;
        func_0027F5B8(176, (int)(D_L00_001B25E0 * 290.0f + 0.5f), color, (unsigned char *)text, -1);
        normal_y = (int)(D_L00_001B25E0 * 363.0f + 0.5f);
        y = normal_y + 7;
        if (!D_001A7B90) y = normal_y;
        func_0027FB40(256, y, 0x80F0F0F0ULL,
            (unsigned char *)func_00288FB8(func_L00_002F3DD0(*(int *)(model + 0x148 + *(int *)(model + 0x80) * 12))), -1);
    } else {
        normal_y = (int)(D_L00_001B25E0 * 363.0f + 0.5f);
        y = normal_y + 7;
        if (!D_001A7B90) y = normal_y;
        func_0027FB40(256, y, 0x80F0F0F0ULL, (unsigned char *)func_00288FB8(0x3188), -1);
    }
}
