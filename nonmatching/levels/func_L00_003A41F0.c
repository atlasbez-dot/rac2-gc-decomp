/* Reconstruction checked 23 October 2026.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final check.py coverage: us 0/27, us2 0/27.
 * Default and -g produced648/656.
 * Remaining: Constant/tag register persistence, entry scheduling and spark-loop register allocation differ.
 * Reopen with a matching particle metadata/tag lifetime witness.
 * Historical screening below is preserved; its blanket C/ISA claims are not acceptance evidence.
 */

/* func_L00_003A41F0 - 656 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x003a41f0. Screened with tools/w10_screen.py: 13 call(s)
   [func_002829A8@003A4238, func_00282D30@003A4258, func_00282CC0@003A4270,
   func_00282D30@003A428C, func_00282CC0@003A429C, func_00282D30@003A42B8,
   func_002A77E0@003A42C0, func_002A77E0@003A42CC, func_002BDCE8@003A4318,
   func_00283CF0@003A4338, func_002BDCE8@003A43D4, func_00283CF0@003A43F0,
   func_002A77E0@003A4414]; data addresses materialised [0x3dcc0000,
   0x3e8c0000, 0x3dcc0000, 0x3d230000, 0x7f200000, 0x3f660000, 0x474d0000,
   0x46760000, 0x45440000, 0x3ca30000, 0x7fff0000]; float constants
   [0x3f800000, 0x40800000, 0x3f800000, 0x40800000]; $gp-relative small
   data: no   saves: -; callee-saved registers saved [-]; words plain C
   cannot emit [-]. Head: addiu $sp, $sp, -0xA0 ; sd $s3, 0x48($sp) ; sd
   $s0, 0x30($sp) ; daddu $s3, $a0, $zero ; sd $s1, 0x38($sp) ; sd $s2,
   0x40($sp). Not matched in this wave: the body is straight-line code whose
   register allocation and the materialisation of its constant addresses
   have to be reproduced word for word. What would unblock it: the exact
   source expression tree, so this cc1 picks the same registers in the same
   order. */

#include "common.h"
extern void func_002829A8(void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002A77E0(int);
extern char *func_002BDCE8(void *, int, void *, unsigned int, int, float, float, float, float);
extern int func_00283CF0(float);

/* Emit layered sparks while the object's effect timer remains active. */
void func_L00_003A41F0(char *moby)
{
    float position[4], offset[4], velocity[4];
    int count, rotation;
    short style;
    float size;
    if (!*(unsigned char *)(moby + 0xBC))
        return;
    func_002829A8(moby + 0xBC);
    func_00282D30(position, moby + 0xD0, 0.1f);
    func_00282CC0(position, position, moby + 0x10);
    func_00282D30(offset, moby + 0xC0, 0.275f);
    func_00282CC0(position, position, offset);
    func_00282D30(velocity, moby + 0xD0, 0.1000000089f);
    for (count = 3; count >= 0; count--) {
        char *particle;
        rotation = func_002A77E0(16);
        if (func_002A77E0(2))
            rotation = -rotation;
        particle = func_002BDCE8(position, rotation, velocity, 0x7F204080, 0,
                                 0.04f, 1.0f, 0.9f, 52500.0f);
        if (particle) {
            *(short *)(particle + 10) = 8;
            *(unsigned char *)(particle + 9) = ((*(short *)(moby + 0x32) >> 5) << 4) + func_00283CF0(4.0f);
            *(int *)(particle + 0x24) = 2;
            *(unsigned char *)(particle + 0x2A) = 0x7F;
            *(unsigned char *)(particle + 0x2B) = *(unsigned char *)(particle + 10);
        }
    }
    rotation = 16;
    style = 2;
    size = 15750.0009765625f;
    for (count = 2; count >= 0; count--) {
        char *particle = func_002BDCE8(position, rotation, velocity, 0x7FFFFFFF, 0,
                                      0.02f, 1.0f, 1.0f, size);
        if (particle) {
            int brightness = func_00283CF0(4.0f);
            *(short *)(particle + 10) = style;
            *(unsigned char *)(particle + 9) = ((*(short *)(moby + 0x32) >> 5) << 4) + brightness;
            *(unsigned char *)(particle + 8) = func_002A77E0(255);
            *(int *)(particle + 0x24) = 2;
            *(unsigned char *)(particle + 0x2A) = 0x7F;
            *(unsigned char *)(particle + 0x2B) = *(unsigned char *)(particle + 10);
        }
        rotation = -rotation;
        style <<= 1;
        size -= 3150.0f;
    }
}
