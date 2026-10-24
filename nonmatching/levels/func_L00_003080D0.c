/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_003080D0-g8.c
 * Game compiler profile: -O2 -G8 -ffunction-sections
 * Compiled/US retail bytes: 800/820.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: 0/27 (exit 1).
 * Residual: 0xf0 frame versus retail 0xe0; bitmap-address/loop allocation and temporary spill layout differ.
 * Reopen only for: A measured live-range model for the nested bitmap loop and the seven full-width temporary spills.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Packed map neighbourhood erasure. Coordinates and both bitmap strides are in cells. */
extern unsigned char D_L00_001C93A0[];
extern int D_001A79F0;
extern int func_L00_00308538(void);
extern int func_L00_00308700(int);
extern void func_00297FE8(float, float, float *, float *, int);
void func_L00_003080D0(float *position)
{
    float px, py;
    int x, y, minX, maxX, minY, maxY;
    int row, col, colour, sample, offset;
    unsigned char *cell;
    int bit;
    if (*(int *)(D_L00_001C93A0 + 0x28) == 0)
        return;
    if (func_L00_00308538())
        return;
    func_00297FE8(position[0], position[1], &px, &py, D_001A79F0);
    x = (int)(px * 512.0f) + 1;
    y = (int)(py * 512.0f) + 1;
    if (x < 0 || y < 0 || x >= 512 || y >= 512)
        return;
    maxX = x + 16;
    maxY = y + 16;
    minY = y - 16;
    minX = x - 16;
    if (maxX >= 512) maxX = 511;
    if (maxY >= 512) maxY = 511;
    if (minY < 0) minY = 0;
    if (minX < 0) minX = 0;
    func_L00_00308700((x >> 5) + (y >> 5) * 16);
    sample = (*(unsigned char **)(D_L00_001C93A0 + 0x38))[(x & 31) / 2 + (y & 31) * 16];
    if (x & 1) colour = sample >> 4;
    else colour = sample & 15;
    for (row = minY; row < maxY; row++) {
        for (col = minX; col < maxX; col++) {
            cell = *(unsigned char **)(D_L00_001C93A0 + 0x0c) + row * 64 + col / 8;
            if (*cell != 0) {
                bit = 1 << (col & 7);
                if (*cell & bit) {
                    offset = col - x + 16;
                    if (((D_L00_001C93A0 + 0x1b0)[(col - x + 16) / 8 + (row - y + 16) * 4] >> (offset % 8)) & 1)
                        continue;
                    func_L00_00308700((col >> 5) + (row >> 5) * 16);
                    sample = (*(unsigned char **)(D_L00_001C93A0 + 0x38))[(col & 31) / 2 + (row & 31) * 16];
                    if (col & 1) sample >>= 4;
                    else sample &= 15;
                    if (colour == sample)
                        *cell &= ~bit;
                }
            }
        }
    }
}
