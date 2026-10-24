/* 2026-10-23 readable reconstruction. Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * 472/472 bytes, 0/3 placements in each of us, us2 and pal. First mismatch +0x60: first add call lacks retail a2 reload; following hazards/alignment differ until the sample loop. Default profile was 464 bytes; -g restores size. Reopen with a measured copy/call scheduling mechanism.
 * Earlier screening-only commentary is preserved below as historical context.
 */
/* from src/levels/shared/L11_002C5E80.c: not written this wave. Retail 472 bytes, 3 place(s), first word at L11:003f4198.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f4198  addiu       $sp, $sp, -0xA0
 *   0x003f419c  sd          $s2, 0x40($sp)
 *   0x003f41a0  sd          $s5, 0x58($sp)
 *   0x003f41a4  daddu       $s2, $a2, $zero
 *   0x003f41a8  sd          $s6, 0x60($sp)
 *   0x003f41ac  daddu       $s5, $a0, $zero
 * Kept as data for the maintainers. */

typedef int Vec128_00414660 __attribute__((mode(TI)));
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283CE0(int);
extern float func_002A7878(float, float);
extern void func_L00_00412110(void *, void *, void *, void *, void *, float);

void func_L11_003F4198(float (*points)[4], int count, float (*control)[4], float displacement)
{
    float before[4] __attribute__((aligned(16)));
    float after[4] __attribute__((aligned(16)));
    float offset[4] __attribute__((aligned(16)));
    float step;
    int i;
    *(Vec128_00414660 *)before = *(Vec128_00414660 *)control[2];
    func_00282CC0(before, before, control[0]);
    *(Vec128_00414660 *)after = *(Vec128_00414660 *)control[3];
    func_00282CC0(after, after, control[1]);
    step = 1.0f / func_00283CE0(count - 2);
    for (i = 0; i < count - 1; i++) {
        func_L00_00412110(points[i], control[0], control[1], before, after, func_00283CE0(i) * step);
        if (i > 0 && i < count - 2) {
            offset[3] = 0.0f;
            offset[0] = func_002A7878(-1.0f, 1.0f);
            offset[1] = func_002A7878(-1.0f, 1.0f);
            offset[2] = func_002A7878(-1.0f, 1.0f);
            func_00282F20(offset, offset, displacement);
            func_00282CC0(points[i], points[i], offset);
        }
    }
    func_00282CF0(offset, points[count - 2], points[count - 3]);
    func_00282CC0(points[count - 1], points[count - 2], offset);
}
