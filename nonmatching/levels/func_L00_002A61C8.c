/* Current reconstruction, checked 2026-10-23.
   Game profile: -O2 -G0 -ffunction-sections.
   USA v1.01 and USA v2.00: 0/27 carrying placements each; absent from PAL.
   596/600 bytes, frame 0x60. Resident-base materialization/register roles and float-chain scheduling differ. Early-return, positive-condition/shared-effect, direct-field and measured-prefix forms were tried; disabling the first scheduling pass was neutral. Reopen with a source layout that preserves the retail resident-base lifetime.
   The historical screening comment below is superseded by these C measurements.
   No linked build was run for this draft.
*/

/* func_L00_002A61C8 - 600 bytes, 27 places, level 00_aranos_tutorial at 0x002A61C8.
   Wave 13 s4: not attempted, screened.  The body has no 128-bit copy, so the
   quad wall of func_L00_002A6008 does not apply here; what it has instead is
   a `div $zero,$v1,$v0` with the `break 0,7` guard, an integer-to-float
   conversion (`mtc1 $v1,$f12` then `cvt.s.w`), eight calls
   (func_00283CF0, func_L00_0035F6D8, func_0029FCC0, func_00283180,
   func_00283198, func_002A89A8, func_00283B98, func_00282F20,
   func_00282CC0, func_L00_0033BA68) and a long chain of float expressions
   whose result registers ($f0/$f1/$f12/$f13/$f20) have to be reproduced one
   by one, plus the `sltiu $a1,$s2,0x1` boolean-to-int form and a float
   constant in each branch.  The frame is 0x60 with $s0..$s3 and $f20 saved.
   Unblocker: the float register plan has to be found first; the argument
   order of func_L00_0035F6D8 (four integers plus the mode) is a lever the
   brief already measured for the fifth argument. */

extern unsigned char D_00189E20[];
extern int D_001A79F0;
extern int func_00283CF0(float);
extern int func_L00_0035F6D8(int, int, int, int, int, int);
extern void func_0029FCC0(char *, int, char *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_002A89A8(void *, int, float);
extern float func_00283B98(float, float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
typedef struct Obj_L00_0033BA68 Obj_L00_0033BA68;
extern Obj_L00_0033BA68 *func_L00_0033BA68(char *, int, float);

void func_L00_002A61C8(int kind, int side, int play_sound, int duration) {
    float point[4];
    float offset[4];
    unsigned char *hero;
    float heading;
    int special;
    int ticks;
    if (play_sound) {
        hero = D_00189E20;
        special = 0;
        if (*(int *)(hero + 0x1270)) {
            int mode = *(int *)(hero + 0x1298);
            if ((unsigned int)(mode - 19) < 2 || mode == 54)
                special = 1;
        }
        ticks = func_00283CF0((float)((duration << 10) / 30));
        func_L00_0035F6D8(kind, side, special, 0, *(int *)(hero + 0x2290), ticks);
    }
    if (D_001A79F0 == 7) {
        hero = D_00189E20;
        if (hero[0x149D] == 0) goto effect;
    }
    if (D_001A79F0 != 19) return;
    hero = D_00189E20;
    if (hero[0x149D] != 2) return;
effect:
    hero = D_00189E20;
    func_0029FCC0(*(void **)(hero + 0x2290), side + 22, (char *)point);
    point[0] += func_00283180(*(float *)(hero + 0x98)) * 0.05f;
    point[1] += func_00283198(*(float *)(hero + 0x98)) * 0.05f;
    point[2] = func_002A89A8(point, 0, 0.5f) + 0.057f;
    heading = *(float *)(hero + 0x98);
    if (*(int *)(hero + 0x2294) == 0 || *(int *)(hero + 0x229C) == 4) {
        if (side == 0) {
            heading = func_00283B98(heading, 0.436332345f);
            func_00282F20(offset, hero + 0x10, 0.037f);
            func_00282CC0(point, point, offset);
        } else {
            heading = func_00283B98(heading, -0.436332345f);
            func_00282F20(offset, hero + 0x10, -0.037f);
            func_00282CC0(point, point, offset);
        }
    }
    func_L00_0033BA68((char *)point, !side, heading);
}
