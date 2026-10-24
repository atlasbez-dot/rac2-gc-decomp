/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 924 / 960 bytes; size equality is not a match.
 * us: 0/27 placements; 924/960 bytes.
 * us2: 0/27 placements; 924/960 bytes.
 * pal: 0/27 placements; 924/960 bytes.
 * Residual: Screen-coordinate scheduling, integer/soft-double temporary lifetimes and addressing differ. Canonical SF-to-DF, DF compare/subtract and DF-to-integer calls keep their actual 64-bit GPR values. Seven GPR inputs to 85548, including the complete sign-extended color, are preserved. Reopen on coordinate and double temporary lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections
 * Measured text: 924 bytes; retail: 960 bytes. Stack frame 0x70.
 * Final coverage: US 0/27, US2 0/27, PAL 0/27. Absences are not matches.
 * 1 measured source/profile forms. Screen-coordinate scheduling, integer/soft-double
 * temporary lifetimes and addressing differ. Canonical SF-to-DF, DF compare/subtract and
 * DF-to-integer calls keep their actual 64-bit GPR values. Seven GPR inputs to 85548,
 * including the complete sign-extended color, are preserved. Reopen on coordinate and double
 * temporary lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_001A7B90;
extern int D_001A7340, D_001A7344;
extern void func_002FC620(int, int, int, int);
extern int func_00282C30(int);
extern void func_00285548(int, int, int, int, int, int, unsigned long long);
extern int func_0028E588(int, int);
extern double func_001234F0(float);
extern int func_00123028(double, double);
extern double func_00122A98(double, double);
extern int func_00123130(double);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);

void func_L00_00376600(void) {
    unsigned int colors[4];
    char *model = D_L00_0022F7C0;
    int top;
    int bottom;
    int y;
    int pulse;
    int relative;
    int x;
    int slot;
    int handle;
    int first_alpha;
    int second_alpha;
    unsigned int shade;
    double distance;
    y = (int)(D_L00_001B25E0 * 185.0f + 0.5f);
    if (D_001A7B90) y += 4;
    func_002FC620(48, 298, (int)(D_L00_001B25E0 * 120.0f + 0.5f), y);
    if (*(int *)(model + 0x6C) < 0) *(int *)(model + 0x6C) += 4;
    else if (*(int *)(model + 0x6C) > 0) *(int *)(model + 0x6C) -= 4;
    pulse = func_00282C30((*(int *)(model + 4) & 15) * 4 - 32);
    if (*(int *)(model + 0x144 + *(int *)(model + 0x80) * 12) > 0) {
        shade = (pulse + 64) * 0x10202;
        top = (int)(D_L00_001B25E0 * 123.0f + 0.5f);
        bottom = (int)(D_L00_001B25E0 * 179.0f + 0.5f);
        if (D_001A7B90) { top += 4; bottom += 4; }
        func_00285548(101, top, 157, bottom, D_001A7340, D_001A7344,
                      (unsigned long long)(int)(shade | 0x80000000u));
        top = (int)(D_L00_001B25E0 * 125.0f + 0.5f);
        bottom = (int)(D_L00_001B25E0 * 177.0f + 0.5f);
        if (D_001A7B90) { top += 4; bottom += 4; }
        func_00285548(103, top, 155, bottom, D_001A7340, D_001A7344, (unsigned long long)(int)0x80442D00);
    }
    x = *(int *)(model + 0x6C) - 63;
    for (relative = -3; relative < 5; relative++, x += 56) {
        slot = relative + *(int *)(model + 0x80);
        if (slot < 0 || slot >= *(int *)(model + 0x740)) continue;
        handle = func_0028E588(*(int *)(model + 0x140 + slot * 12), 0);
        distance = func_001234F0(150.0f - (float)(x + 2));
        if (func_00123028(distance, 0.0) < 0) distance = func_00122A98(0.0, distance);
        first_alpha = 128 - func_00123130(distance);
        distance = func_001234F0(150.0f - (float)(x + 40));
        if (func_00123028(distance, 0.0) < 0) distance = func_00122A98(0.0, distance);
        second_alpha = 128 - func_00123130(distance);
        if (first_alpha < 0) first_alpha = 0;
        if (second_alpha < 0) second_alpha = 0;
        colors[0] = ((unsigned int)first_alpha << 24) | 0xF0F0B0;
        colors[1] = ((unsigned int)second_alpha << 24) | 0xF0F0B0;
        colors[2] = colors[0];
        colors[3] = colors[1];
        y = (int)(D_L00_001B25E0 * 129.0f + 0.5f);
        if (D_001A7B90) y += 4;
        func_0028EA58(handle, x + 2, y, 40, (int)(D_L00_001B25E0 * 40.0f + 0.5f), colors);
    }
}
