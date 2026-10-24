/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections.
 * Reported final C / retail: 500 / 552 bytes; size equality is not a match.
 * us: 0/27 placements; 500/552 bytes.
 * us2: 0/27 placements; 500/552 bytes.
 * pal: 0/27 placements; 500/552 bytes.
 * Residual: String scrolling, integer division, scalar scheduling and mixed GP/absolute scale accesses differ. The six-entry message table remains a complete 24-byte record under G32. Reopen on scroll/control-flow lifetimes and source division shape.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections
 * Measured text: 500 bytes; retail: 552 bytes. Stack frame 0x30.
 * Final coverage: US 0/27, US2 0/27, PAL 0/27. Absences are not matches.
 * 1 measured source/profile forms. String scrolling, integer division, scalar scheduling and
 * mixed GP/absolute scale accesses differ. The six-entry message table remains a complete
 * 24-byte record under G32. Reopen on scroll/control-flow lifetimes and source division
 * shape.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_001A7B90;
extern int D_L00_001AD690 __attribute__((sda));
extern int D_L00_001AD698[6] __attribute__((sda));
extern void func_002FC620(int, int, int, int);
extern unsigned int func_001157AC(const char *);
extern int func_002A77E0(int);
extern int func_00288FB8(int);
extern void func_002F88D8(void *);
extern void func_002F97A0(unsigned long long, unsigned char *, int, float, float, float);

void func_L00_00375718(void) {
    char *model = D_L00_0022F7C0;
    int baseline;
    float magnification;
    int length;
    int scroll;
    int choice;
    if (*(int *)(model + 0x50) == 2) {
        baseline = 20;
        magnification = 1.0f;
        func_002FC620(75, 355, (int)(D_L00_001B25E0 * 19.0f + 0.5f), (int)(D_L00_001B25E0 * 36.0f + 0.5f));
    } else {
        baseline = 60;
        magnification = 1.5f;
        func_002FC620(80, 432, (int)(D_L00_001B25E0 * 56.0f + 0.5f), (int)(D_L00_001B25E0 * 100.0f + 0.5f));
    }
    length = (int)func_001157AC(*(char **)(model + 0x3C));
    scroll = *(int *)(model + 0x64) + 2;
    if (length - *(int *)(model + 0x64) / 20 < 1) {
        scroll = *(int *)(model + 0x64);
        if (*(int *)(model + 0x744) == 0 && (unsigned int)(*(int *)(model + 0x50) - 1) > 1) {
            choice = func_002A77E0(12);
            if (choice < 6) func_002F88D8((void *)func_00288FB8(D_L00_001AD698[choice]));
            else func_002F88D8((void *)func_00288FB8(D_L00_001AD690));
            scroll = *(int *)(model + 0x64);
        }
    }
    *(int *)(model + 0x64) = scroll;
    baseline = (int)((float)baseline * D_L00_001B25E0 + 0.5f);
    if (D_001A7B90) baseline -= 4;
    func_002F97A0(0xF0C070ULL, *(unsigned char **)(model + 0x3C), -1,
                   (float)-*(int *)(model + 0x64), (float)baseline, magnification);
}
