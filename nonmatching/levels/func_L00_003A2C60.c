/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Default G8 and -g checked; both636 bytes with entry differences.
 * Remaining: Stack frame and saved-register lifetimes differ despite equal function size.
 * Reopen with measured vector/workspace lifetime evidence.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A2C60 - 636 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a2c60. Screened with tools/w10_screen.py: 18 call(s)
   [func_00282CF0@003A2CA4, func_00282CF0@003A2CE8, func_00282F20@003A2D00,
   func_00282DB0@003A2D0C, func_00282D30@003A2D1C, func_00282CF0@003A2D2C,
   func_002A7878@003A2D50, func_002A77E0@003A2D5C, func_002A7878@003A2D88,
   func_002ACEC0@003A2D9C, func_002A7878@003A2DA8, func_00282F20@003A2DB8,
   func_002A7878@003A2DC4, func_00282C88@003A2DD4, func_002C2210@003A2E10,
   func_00283CF0@003A2E2C, func_002C2210@003A2E7C, func_00283CF0@003A2E98];
   data addresses materialised [0x1c0000, 0x1b0000, 0x190000, 0x3c880000,
   0x3f860000, 0xbf860000, 0x3dcc0000, 0x7f7f0000, 0x3d8f0000, 0x7fff0000,
   0x3f330000]; float constants [0x3f800000, 0x3f800000, 0x40800000,
   0x40800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [-]. Head: addiu $sp, $sp,
   -0x90 ; sd $s2, 0x50($sp) ; sd $s3, 0x58($sp) ; daddu $s2, $a1, $zero ;
   daddu $s3, $a0, $zero ; sd $s4, 0x60($sp). Not matched in this wave: the
   body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

#include "common.h"
extern float D_L00_001B8DC0[4];
extern float D_00189ED0[4];
extern int D_L00_001A8FF0 NOT_SDA;
extern float D_L00_001AF5F8 __attribute__((sda));
extern float D_L00_001AF5FC __attribute__((sda));
extern float D_L00_001AF600 __attribute__((sda));
extern float D_L00_001AF604 __attribute__((sda));
extern float D_L00_001AF60C __attribute__((sda));
extern float D_L00_001AF610 __attribute__((sda));
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_002ACEC0(void *, void *, void *, float);
typedef int VectorBits __attribute__((mode(TI)));
extern void func_00282C88(VectorBits *);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);
extern int func_00283CF0(float);

/* Spray paired particles perpendicular to the viewing direction. */
void func_L00_003A2C60(void *position, int count, float brightness)
{
    float velocity[4], lateral[4], axis[4], projected[4];
    func_00282CF0(lateral, D_L00_001B8DC0, position);
    if (D_L00_001A8FF0 == 0) {
        lateral[2] = 0.0f;
        axis[3] = 1.0f;
        axis[0] = 0.0f;
        axis[1] = 0.0f;
        axis[2] = 1.0f;
    } else {
        func_00282CF0(projected, position, D_00189ED0);
        func_00282F20(axis, projected, 1.0f);
        func_00282D30(projected, axis, func_00282DB0(axis, lateral));
        func_00282CF0(lateral, lateral, projected);
    }
    if (count > 0) {
        do {
            char *particle;
            float size = func_002A7878(D_L00_001AF60C, D_L00_001AF610);
            int spin = func_002A77E0(2);
            if (!spin)
                spin = -1;
            func_002ACEC0(velocity, lateral, axis, func_002A7878(-1.0471977f, 1.0471977f));
            func_00282F20(velocity, velocity, func_002A7878(D_L00_001AF5F8, D_L00_001AF5FC) * (1.0f / 60.0f));
            velocity[2] = func_002A7878(D_L00_001AF600, D_L00_001AF604) * (1.0f / 60.0f);
            func_00282C88((VectorBits *)velocity);
            particle = func_002C2210(position, 60, 0x7F7F2020, 0, spin, velocity, 1,
                                     size * 0.1f, size, brightness);
            if (particle)
                *(unsigned char *)(particle + 9) = func_00283CF0(4.0f) + 0x70;
            particle = func_002C2210(position, 60, 0x7FFF4040, 1, -spin, velocity, 1,
                                     size * 0.07f, size * 0.7f, brightness);
            count--;
            if (particle)
                *(unsigned char *)(particle + 9) = func_00283CF0(4.0f) + 0x70;
        } while (count);
    }
}
