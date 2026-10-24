/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 996 / 1024 bytes; size equality is not a match.
 * us: 0/27 placements; 996/1024 bytes.
 * us2: absent from catalogue (not a match).
 * pal: 0/27 placements; 996/1024 bytes.
 * Residual: The 0x190 frame differs from retail 0x1A0; scalar, layout/color workspace and vararg lifetimes differ. G0 scalar macro addressing gives 996 versus the first 988-byte draft, with closer address forms. The real 24-byte layout/color union, 256-byte text buffer and measured seven-/three-byte formats are preserved. Reopen on layout/vararg lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections
 * Measured text: 996 bytes; retail: 1024 bytes. Stack frame 0x190.
 * Final coverage: US 0/27, US2 absent, PAL 0/27. Absences are not matches.
 * 3 measured source/profile forms. The 0x190 frame differs from retail 0x1A0; scalar,
 * layout/color workspace and vararg lifetimes differ. G0 scalar macro addressing gives 996
 * versus the first 988-byte draft, with closer address forms. The real 24-byte layout/color
 * union, 256-byte text buffer and measured seven-/three-byte formats are preserved. Reopen on
 * layout/vararg lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef struct { short field[12]; } TextLayout;
extern char D_L00_0022F7C0[];
extern unsigned char D_00139568[];
extern char D_L00_00262570[];
extern float D_L00_001B25E0 __attribute__((sda));
extern int D_L00_001B25A8 __attribute__((sda));
extern int D_001A79F8 __attribute__((sda));
extern char D_L00_001AD798[7] __attribute__((sda));
extern char D_L00_001AD6C8[3] __attribute__((sda));
extern void *func_00115484(void *, int, unsigned int);
extern int func_00288FB8(int);
extern void func_00280200(TextLayout *, unsigned long long, unsigned char *, int);
extern int func_00115DA8(char *, char *, ...);
extern void func_0027FA10(int, int, unsigned long long, unsigned char *, int);
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);
extern int func_002F6510(void);

void func_L00_00378818(void) {
    TextLayout copy;
    /* This 24-byte workspace becomes the four-color array after drawing text. */
    union { TextLayout layout; unsigned int colors[4]; } seed;
    char text[256];
    char *model = D_L00_0022F7C0;
    int index;
    int message;
    unsigned int unit_price;
    if (*(int *)(model + 0x84) == 0) return;
    func_00115484(&seed.layout, 0, 24);
    seed.layout.field[0] = 120;
    seed.layout.field[1] = (short)(D_L00_001B25E0 * 200.0f + 0.5f);
    seed.layout.field[2] = 160;
    seed.layout.field[3] = 352;
    seed.layout.field[4] = 256;
    seed.layout.field[5] = (short)(D_L00_001B25E0 * 160.0f + 0.5f);
    seed.layout.field[6] = 184;
    seed.layout.field[7] = (short)(D_L00_001B25E0 * 72.0f + 0.5f);
    seed.layout.field[8] = 16;
    seed.layout.field[9] = 3;
    copy = seed.layout;
    index = *(int *)(model + 0x80);
    if (*(int *)(model + 0x144 + index * 24) == 1) {
        message = 0x1128;
        unit_price = *(unsigned short *)(D_L00_00262570 +
            (unsigned int)D_00139568[*(int *)(model + 0x140 + index * 24)] * 0xE0 + 0x88);
        if ((int)unit_price <= D_001A79F8) {
            copy.field[9] = 1;
            copy.field[5] = (short)(D_L00_001B25E0 * 132.0f + 0.5f);
            func_00280200(&copy, 0x80F0F0F0ULL, (unsigned char *)func_00288FB8(0x1127), -1);
            func_00115DA8(text, D_L00_001AD798, D_L00_001B25A8);
            copy.field[5] = (short)((float)(copy.field[0] + 40) * D_L00_001B25E0 + 0.5f);
            func_00280200(&copy, 0x80F0F0F0ULL, (unsigned char *)text, -1);
            index = *(int *)(model + 0x80);
            unit_price = *(unsigned short *)(D_L00_00262570 +
                (unsigned int)D_00139568[*(int *)(model + 0x140 + index * 24)] * 0xE0 + 0x88);
            func_00115DA8(text, D_L00_001AD6C8, (unsigned int)D_L00_001B25A8 * unit_price);
            func_0027FA10(256, (int)(D_L00_001B25E0 * 180.0f + 0.5f), 0x80F0F0F0ULL, (unsigned char *)text, -1);
            seed.colors[0] = 0x60F0F0B0;
            seed.colors[1] = 0x60F0F0B0;
            seed.colors[2] = 0x60F0F0B0;
            seed.colors[3] = 0x60F0F0B0;
            func_0028EA58(func_0028E588(0x7567, 0), 260, (int)(D_L00_001B25E0 * 180.0f + 0.5f),
                          16, (int)(D_L00_001B25E0 * 16.0f + 0.5f), seed.colors);
            return;
        }
    } else {
        if (D_001A79F8 < func_002F6510()) {
            func_00280200(&copy, 0x80F0F0F0ULL, (unsigned char *)func_00288FB8(0x1128), -1);
            return;
        }
        message = 0x1129;
        copy.field[9] = 1;
        copy.field[5] = (short)((float)(copy.field[0] + 6) * D_L00_001B25E0 + 0.5f);
    }
    func_00280200(&copy, 0x80F0F0F0ULL, (unsigned char *)func_00288FB8(message), -1);
}
