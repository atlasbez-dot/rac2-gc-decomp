/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections.
 * Reported final C / retail: 820 / 876 bytes; size equality is not a match.
 * us: 0/27 placements; 820/876 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Text/argument lifetimes and the 0x240 frame differ from retail 0x250. -mno-split-addresses worsens size to 808 and was reverted. The three format strings keep measured extents 10,9,9 including terminators, with standard G16/Wa-G16; both buffers are 256 bytes. Reopen on formatted-text/width-result lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections
 * Measured text: 820 bytes; retail: 876 bytes. Stack frame 0x240.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 2 measured source/profile forms. Text/argument lifetimes and the 0x240 frame differ from
 * retail 0x250. -mno-split-addresses worsens size to 808 and was reverted. The three format
 * strings keep measured extents 10,9,9 including terminators, with standard G16/Wa-G16; both
 * buffers are 256 bytes. Reopen on formatted-text/width-result lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern unsigned char D_001A7A80[];
extern int D_L00_001A8E40[];
extern unsigned char D_00139568[];
extern char D_L00_00262570[];
extern char D_L00_001AD738[10] __attribute__((sda));
extern char D_L00_001AD748[9] __attribute__((sda));
extern char D_L00_001AD758[9] __attribute__((sda));
extern int D_L00_001AD718 __attribute__((sda));
extern int D_L00_001AD71C;
extern int D_L00_001AD724;
extern int D_L00_001AD728 __attribute__((sda));
extern int D_L00_001AD72C;
extern int D_L00_001AD730 __attribute__((sda));
extern int D_L00_001AD734;
extern float D_L00_001B25E0;
extern int func_00288FB8(int);
extern int func_00115DA8(char *, char *, ...);
extern int func_0027FB40(int, int, unsigned long long, unsigned char *, int);
extern void func_002F9BC0(char *, int);
extern int func_0028E588(int, int);
extern int func_L00_002E9120(unsigned char *, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern int func_002B0D70(void);

void func_L00_00377580(void) {
    char first[256];
    char second[256];
    unsigned int colors[4];
    char *model = D_L00_0022F7C0;
    char *row = model + *(int *)(model + 0x80) * 16;
    int group = *(int *)(row + 0x144);
    int slot = *(int *)(row + 0x140);
    unsigned char *text;
    unsigned char *description;
    unsigned char *suffix;
    int handle;
    int width;
    if ((D_001A7A80[group] & (1u << ((slot & 15) << 1)) & 255u) != 0) return;
    if (group != 0) {
        text = (unsigned char *)func_00288FB8(D_L00_001A8E40[slot]);
        description = (unsigned char *)func_00288FB8(*(int *)(D_L00_00262570 + (unsigned int)D_00139568[group] * 0xE0 + 8));
        func_00115DA8(first, D_L00_001AD738, text, description);
        func_0027FB40(D_L00_001AD728, (int)((float)D_L00_001AD72C * D_L00_001B25E0 + 0.5f),
                      0x80F0F0F0ULL, (unsigned char *)first, -1);
    }
    func_002F9BC0(first, *(int *)(model + 0x148 + *(int *)(model + 0x80) * 16));
    text = (unsigned char *)func_00288FB8(0x114E);
    suffix = (unsigned char *)func_00288FB8(0x3262);
    func_00115DA8(second, D_L00_001AD748, text, first, suffix);
    func_0027FB40(D_L00_001AD718, (int)((float)D_L00_001AD71C * D_L00_001B25E0 + 0.5f),
                  0x80F0F0F0ULL, (unsigned char *)second, -1);
    colors[0] = 0x60F0F0B0;
    colors[1] = 0x60F0F0B0;
    colors[2] = 0x60F0F0B0;
    colors[3] = 0x60F0F0B0;
    handle = func_0028E588(0xEAA2, 0);
    width = func_L00_002E9120((unsigned char *)second, -1);
    func_0028EA58(handle, D_L00_001AD718 + (width >> 1) + 4,
                  (int)((float)D_L00_001AD724 * D_L00_001B25E0 + 0.5f), 16,
                  (int)(D_L00_001B25E0 * 16.0f + 0.5f), colors);
    text = (unsigned char *)func_00288FB8(0x2F2D);
    width = func_002B0D70();
    suffix = (unsigned char *)func_00288FB8(0x3262);
    func_00115DA8(first, D_L00_001AD758, text, width, suffix);
    func_0027FB40(D_L00_001AD730, (int)((float)D_L00_001AD734 * D_L00_001B25E0 + 0.5f),
                  0x80F0F0F0ULL, (unsigned char *)first, -1);
    handle = func_0028E588(0xEAA2, 0);
    width = func_L00_002E9120((unsigned char *)first, -1);
    func_0028EA58(handle, D_L00_001AD730 + (width >> 1) + 4,
                  (int)((float)D_L00_001AD734 * D_L00_001B25E0 + 0.5f), 16,
                  (int)(D_L00_001B25E0 * 16.0f + 0.5f), colors);
}
