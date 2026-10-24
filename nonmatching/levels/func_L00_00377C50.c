/* Retained manual C reconstruction; not linked or counted.
 * Retail: 1372 bytes. Checked trial: src/levels/shared/L00_00377C50-g8.c
 * Profile: -O2 -G8 -mno-split-addresses -ffunction-sections
 * us: 0/27 placements (exit 1), 1436 compiled bytes
 * us2: explicit catalogue absence (exit 1); no credit
 * pal: explicit catalogue absence (exit 1); no credit
 * Residual: Draw-branch layout, repeated class/cost lookups and the rounding/movz sequence retain different allocation and block scheduling. The scalar conversion is the valid R5900 cvt.w.s encoding, not a handwritten blocker.
 * Reopen: Reopen with a measured conditional shape that shares the retail draw tail while preserving the lookup side effects and 64-bit colour argument.
 * The ASM marker and trial-only file profile were restored after checks.
 */

#include "common.h"
extern u8 D_L00_0022F7C0[];
extern u8 D_00139568[];
extern int D_00139688[];
extern u8 D_L00_00262570[];
extern int D_001A79F8;
extern int D_001A7B90;
extern float D_L00_001B25E0;
extern int func_00288FB8(int id);
extern int func_002F6510(void);
extern int func_0027FB40(int x, int y, unsigned long style, u8 *text, int length);

#define SELECTED (D_L00_0022F7C0 + *(int *)(D_L00_0022F7C0 + 0x80) * 24)
#define KIND (*(int *)(SELECTED + 0x144))
#define ENTRY (D_L00_00262570 + D_00139568[*(int *)(SELECTED + 0x140)] * 224)
#define CAPPED (D_00139688[*(int *)(SELECTED + 0x140)] >= *(unsigned short *)(ENTRY + 0x8e))
#define AFFORDABLE (D_001A79F8 >= *(unsigned short *)(ENTRY + 0x88))
#define DRAW(X, ID) do { \
    int row = (int)(D_L00_001B25E0 * 164.0f + 0.5f); \
    if (D_001A7B90) row--; \
    func_0027FB40((X), row, 0x80f0f0f0UL, (u8 *)func_00288FB8((ID)), -1); \
} while (0)

void func_L00_00377C50(void)
{
    if (*(int *)(D_L00_0022F7C0 + 0x84)) {
        if (KIND == 1 && CAPPED) {
            DRAW(420, 0x1124);
        } else if (KIND == 1) {
            if (AFFORDABLE) {
                DRAW(420, 0x1125);
            } else {
                DRAW(420, 0x1124);
            }
        } else if (D_001A79F8 >= func_002F6510()) {
            DRAW(80, 0x113b);
        } else {
            DRAW(420, 0x1124);
        }
        if (KIND == 1 && CAPPED)
            return;
        if (KIND == 1) {
            if (!AFFORDABLE)
                return;
            DRAW(420, 0x1124);
        } else {
            if (D_001A79F8 < func_002F6510())
                return;
            DRAW(420, 0x1138);
        }
    } else {
        if ((KIND == 0 && D_001A79F8 >= func_002F6510()) ||
            (KIND == 1 && !CAPPED && AFFORDABLE)) {
            DRAW(80, 0x1125);
        }
        DRAW(420, 0x2d4f);
    }
}
