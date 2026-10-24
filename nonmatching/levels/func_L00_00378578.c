/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 640 / 668 bytes; size equality is not a match.
 * us: 0/27 placements; 640/668 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: The retail frame is recovered, but branch/common-expression and register allocation differ. Real scalar macro accesses improve the frame from 0x30 to 0x20. The two labels retain their measured seven- and five-byte extents. Reopen on the status/message branch layout and global expressions.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 640 bytes; retail: 668 bytes. Stack frame 0x20.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 2 measured source/profile forms. The retail frame is recovered, but
 * branch/common-expression and register allocation differ. Real scalar macro accesses improve
 * the frame from 0x30 to 0x20. The two labels retain their measured seven- and five-byte
 * extents. Reopen on the status/message branch layout and global expressions.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_001A79FC __attribute__((sda));
extern char D_L00_001AD788[7];
extern char D_L00_001AD790[5];
extern int func_00288FB8(int);
extern int func_0027FB40(int, int, unsigned long long, unsigned char *, int);
extern int func_0028E588(int, int);
extern void func_0028E868(int, int, int, int, int, int);

void func_L00_00378578(void) {
    char *model = D_L00_0022F7C0;
    int message;
    if (*(int *)(model + 0x84) == 0) {
        func_0027FB40(438, (int)(D_L00_001B25E0 * 190.0f + 0.5f), 0x80F0F0F0ULL,
                      (unsigned char *)func_00288FB8(0x1125), -1);
        func_0027FB40(438, (int)(D_L00_001B25E0 * 214.0f + 0.5f), 0x80F0F0F0ULL,
                      (unsigned char *)func_00288FB8(0x2D4F), -1);
    } else {
        message = 0x1124;
        if (*(int *)(model + 0x144 + *(int *)(model + 0x80) * 28) <= D_001A79FC) {
            func_0027FB40(438, (int)(D_L00_001B25E0 * 190.0f + 0.5f), 0x80F0F0F0ULL,
                          (unsigned char *)func_00288FB8(0x113B), -1);
            message = 0x1138;
        }
        func_0027FB40(438, (int)(D_L00_001B25E0 * 214.0f + 0.5f), 0x80F0F0F0ULL,
                      (unsigned char *)func_00288FB8(message), -1);
    }
    func_0028E868(func_0028E588(0xEAA8, 1), 402, (int)(D_L00_001B25E0 * 64.0f + 0.5f), 89,
                  (int)(D_L00_001B25E0 * 115.0f + 0.5f), 64);
    func_0027FB40(445, (int)(D_L00_001B25E0 * 130.0f + 0.5f), 0x80F0F0F0ULL,
                  (unsigned char *)D_L00_001AD788, -1);
    func_0027FB40(445, (int)(D_L00_001B25E0 * 148.0f + 0.5f), 0x80F0F0F0ULL,
                  (unsigned char *)D_L00_001AD790, -1);
}
