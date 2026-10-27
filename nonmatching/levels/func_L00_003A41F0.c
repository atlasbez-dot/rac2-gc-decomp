/* Reconstruction; not linked. Profile: -O2 -G0 -ffunction-sections.
 * 26 October 2026 (M14): 656/656 bytes, 53 differing lines (all register naming and call-argument
 * scheduling). Spark record written through a +0x20 sub-pointer taken before the brightness
 * call (retail's addiu s0, s1, 0x20 in the call slot), int style. Left: retail gives the record
 * s1 and the sub-pointer s0, hoists 8 into fp before the first call, and schedules the
 * func_002BDCE8 argument moves differently. In the permuter farm.
 */
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
    int style;
    float size;
    char *sub;
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
            sub = particle + 0x20;
            *(short *)(particle + 10) = 8;
            *(unsigned char *)(particle + 9) = ((*(short *)(moby + 0x32) >> 5) << 4) + func_00283CF0(4.0f);
            *(int *)(sub + 4) = 2;
            *(unsigned char *)(sub + 10) = 0x7F;
            *(unsigned char *)(sub + 11) = *(unsigned char *)(particle + 10);
        }
    }
    rotation = 16;
    style = 2;
    size = 15750.0009765625f;
    for (count = 2; count >= 0; count--) {
        char *particle = func_002BDCE8(position, rotation, velocity, 0x7FFFFFFF, 0,
                                      0.02f, 1.0f, 1.0f, size);
        if (particle) {
            int brightness;
            sub = particle + 0x20;
            brightness = func_00283CF0(4.0f);
            *(short *)(particle + 10) = style;
            *(unsigned char *)(particle + 9) = ((*(short *)(moby + 0x32) >> 5) << 4) + brightness;
            *(unsigned char *)(particle + 8) = func_002A77E0(255);
            *(int *)(sub + 4) = 2;
            *(unsigned char *)(sub + 10) = 0x7F;
            *(unsigned char *)(sub + 11) = *(unsigned char *)(particle + 10);
        }
        rotation = -rotation;
        style <<= 1;
        size -= 3150.0f;
    }
}
