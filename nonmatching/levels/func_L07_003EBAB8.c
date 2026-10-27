/* Nonmatching: 304/304 bytes.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final placement checks: US: 0/1; US2: 0/1; PAL absent from catalogue.
 * 304/304 bytes. The first remaining instruction difference is +0x108: final argument setup schedules a3=255 before f14/f15 copies rather than in the call delay slot. All earlier instructions agree after relocation. PAL has no catalogue row.
 * Reopen with evidence for the final call scheduling or true source argument lifetimes, keeping the canonical unsigned-char argument and four float arguments.
 */
#include "common.h"
typedef unsigned int QuadBAB8 __attribute__((mode(TI)));
extern void func_002A6C58(char *, int, int);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, void *);
extern int func_002E5CF8(int, int, char *);
extern void func_00282F20(void *, void *, float);
extern void func_002B0A68(char *, int, float *, unsigned char, float, float, float, float);
/* Emit the impact effect and particles using the four real stack argument slots. */
void func_L07_003EBAB8(char *actor)
{
    float position[4] __attribute__((aligned(16)));
    float direction[4] __attribute__((aligned(16)));
    char *state = *(char **)(actor + 0x68);
    *(int *)(actor + 0x98) = 0;
    *(unsigned short *)(actor + 0x34) = (*(unsigned short *)(actor + 0x34) | 0x41) & 0xefff;
    func_002A6C58(actor, 0, 3);
    *(QuadBAB8 *)position = 0;
    position[2] = 0.75f;
    func_00283098(position, position, actor + 0xc0);
    func_00282CC0(position, position, actor + 0x10);
    func_0032C700(position, 0, 25, 20, 20, 20, 45, 1, 0.6f, 20.0f,
                 1, 0, 0, *(void **)(state + 0x314));
    func_002E5CF8(9, 0, actor);
    func_00282F20(direction, state + 0x1c0, 0.0500000045f);
    func_002B0A68(actor, 0x7f8, direction, 0xff, 3.0f, 6.0f, 3.0f, 6.0f);
}
