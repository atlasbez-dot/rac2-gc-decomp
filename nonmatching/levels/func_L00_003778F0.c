/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 856 / 860 bytes; size equality is not a match.
 * us: 0/27 placements; 856/860 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Four-byte text gap plus register/base scheduling differences. Standard G0 scalar macros recover the retail 0x160 frame and 16 bytes. A whole-model pointer expression does not close the remaining differences. The gradient is a complete 16-byte record and the text buffer is 256 bytes. Reopen on model/gradient lifetimes and store ordering.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 856 bytes; retail: 860 bytes. Stack frame 0x160.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 3 measured source/profile forms. Four-byte text gap plus register/base scheduling
 * differences. Standard G0 scalar macros recover the retail 0x160 frame and 16 bytes. A
 * whole-model pointer expression does not close the remaining differences. The gradient is a
 * complete 16-byte record and the text buffer is 256 bytes. Reopen on model/gradient
 * lifetimes and store ordering.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef struct { unsigned int word[4]; } PanelColors;
extern PanelColors D_L00_001AD768;
extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_L00_001B1BBC;
extern int D_001A7340 __attribute__((sda));
extern int D_001A79FC __attribute__((sda));
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern int func_00288FB8(int);
extern void func_0027FA10(int, int, unsigned long long, unsigned char *, int);
extern void func_002F9BC0(char *, int);
extern void func_0027F5B8(int, int, unsigned long long, unsigned char *, int);
extern int func_0027FB40(int, int, unsigned long long, unsigned char *, int);
extern void func_0027F980(int, int, unsigned long long, unsigned char *, int);

void func_L00_003778F0(void) {
    PanelColors colors;
    char text[256];
    char *model = D_L00_0022F7C0;
    int index = *(int *)(model + 0x80);
    colors = D_L00_001AD768;
    D_L00_001B1BBC = 0;
    func_0028EA58(func_0028E588(0xEAA8, 0), 16, (int)(D_L00_001B25E0 * 51.0f + 0.5f),
                  192, (int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 400, (int)(D_L00_001B25E0 * 51.0f + 0.5f),
                  -192, (int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 16, (int)(D_L00_001B25E0 * 243.0f + 0.5f),
                  192, -(int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0028EA58(func_0028E588(0xEAA8, 0), 400, (int)(D_L00_001B25E0 * 243.0f + 0.5f),
                  -192, -(int)(D_L00_001B25E0 * 96.0f + 0.5f), colors.word);
    func_0027FA10(270, (int)(D_L00_001B25E0 * 218.0f + 0.5f), 0x80F0F0F0ULL,
                  (unsigned char *)func_00288FB8(0x318C), -1);
    func_002F9BC0(text, *(int *)(model + 0x144 + index * 28));
    func_0027F5B8(270, (int)(D_L00_001B25E0 * 218.0f + 0.5f), 0x80F0F0F0ULL, (unsigned char *)text, -1);
    func_0027FB40(D_001A7340 >> 1, (int)(D_L00_001B25E0 * 277.0f + 0.5f), 0x80F0F0F0ULL,
                  *(unsigned char **)(model + 0x154 + index * 28), -1);
    colors.word[0] = 0x60F0F0B0;
    colors.word[1] = 0x60F0F0B0;
    colors.word[2] = 0x60F0F0B0;
    colors.word[3] = 0x60F0F0B0;
    func_002F9BC0(text, D_001A79FC);
    func_0027F980(444, 17, 0x80FFFFFFULL, (unsigned char *)text, -1);
    func_0028EA58(func_0028E588(0xEAA2, 3), 458, (int)(D_L00_001B25E0 * 15.0f + 0.5f),
                  32, (int)(D_L00_001B25E0 * 32.0f + 0.5f), colors.word);
}
