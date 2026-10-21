/* func_L00_002B9380: 340-byte candidate, 340-byte retail extent, 0 of 27 placements.
 * Rechecked with the current qualified compiler after correcting func_002AA898's
 * prototype to (position, velocity, direction, target, acceleration, damping, limit).
 * The original direction-last declaration conflicted with its definition in
 * src/game/002AA800.c. Its apparent byte match is not an accepted C implementation.
 *
 * The corrected declaration exchanges the integer zero setup and the float
 * argument move at +0xb0 and +0xc0. An isolated unit has the same difference;
 * -fno-gcse also leaves it. -fno-schedule-insns and -fno-schedule-insns2 introduce
 * earlier differences; -fno-expensive-optimizations produces 316 bytes. Passing
 * the known-zero mode gives the same result. Named float constants change the
 * first mismatch to +0x98. No instruction output or register assignments are patched.
 * Reopen with evidence for a natural call/source arrangement that preserves the
 * existing callee's type and matches every placement.
 */
#include "include_asm.h"
typedef unsigned char u8;
typedef unsigned int u32;
typedef int TI_F41eb487e __attribute__((mode(TI)));
extern char D_00189E20_5[];
extern void func_L00_002B91C0(void);
extern void func_L00_002B3DC0(float, float, float);
extern float func_002AA898(float *, float *, int, float, float, float, float);
void func_L00_002B9380(void)
{
    char *base = (char *)&D_00189E20_5;
    TI_F41eb487e v;
    int mode;
    int x;

    mode = *(u8 *)(base + 0x22C3);
    if (*(short *)(base + 0x218) != 0)
        mode = 1;

    if (mode == 0) {
        x = *(int *)(base + 0x2294);
        if ((u32)(x - 0x24) < 2)
            return;
        if (*(int *)(base + 0x229C) == 0x11 || *(int *)(base + 0x229C) == 0x15 ||
            *(int *)(base + 0x229C) == 0x16 || *(int *)(base + 0x229C) == 0x1F)
            return;
        if (x == 0x74 || x == 0x30 || x == 0x2C || x == 0x2B)
            return;
        v = *(TI_F41eb487e *)(base + 0x90);
        func_002AA898((float *)&v, (float *)(base + 0xA0), 0, 0.0f, 0.015f, 0.3f, 0.087266475f);
        func_002AA898((float *)&v + 1, (float *)(base + 0xA4), 0, 0.0f, 0.015f, 0.3f, 0.087266475f);
        func_L00_002B3DC0(*(float *)(base + 0xA0), *(float *)(base + 0xA4), 0.0f);
        return;
    }
    if (mode < 0)
        return;
    if (mode >= 3)
        return;
    func_L00_002B91C0();
}
