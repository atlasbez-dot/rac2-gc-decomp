/* func_L02_003E6D70 (1 place, 1,536 bytes): slot-machine actor update.
 * Opus pass (big38), 2026-10-26; not linked. Profile: -O2 -G8 -ffunction-sections.
 * 382/384 words, ~50 opcodes off (was 55). Changes: a plain switch with an empty case 1 instead of
 * the computed goto (same 6-entry table); D_L02_001AEC78, D_001A79F8, D_L02_001B0A18/1C and
 * D_L02_001B093C/094C are plain sized scalars (gp only in delay slots, lui/lw elsewhere);
 * D_L02_001A8F20 is an address (array, not sda); D_00139647 is byte 0x8F of D_001395B8 through a
 * union view (retail keeps the base in s0); hero XY through the Hero view.
 * Left: retail stores the three float zeroes from $f0 (mtc1 $zero) and does not use s2 for the
 * rate loop; store order of the hit packet bytes; the sound-slot index tests (a1 vs a2).
 */
#include "common.h"
extern float D_L02_001B0A18, D_L02_001B0A1C;
typedef union { u8 b[0x200]; u32 w[0x80]; } GameFlags;
extern u8 D_001395B8[];
#define FLAG (((GameFlags *)D_001395B8)->b[0x8F])
extern int D_L02_001B093C, D_L02_001B094C;
extern char D_L02_001B0978[], D_L02_001B09A8[];
extern char D_00188660[];
typedef int TI128 __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; f32 f[0x980]; } Hero;
extern u8 D_00189E20[];
extern char D_L02_001A8F20[];
extern int D_L02_001AEC78, D_001A79F8;
extern void func_L00_002E6CF0(void (*)(char *), void *);
extern void func_L02_003E7B58(char *);
extern void func_002A7750(void *, int, int);
extern float func_002A7878(float, float);
extern int func_002A77E0(int), func_002B3868(void *);
extern void func_002A7470(void *, int, int, int);
extern void func_L00_0030C710(int);
extern int func_0026FEB8(char *, ...);
extern int func_002AEB60(char *, float);
extern int func_002E5CF8(int, int, void *);
extern void func_L02_003E75A8(void *), func_L02_003E77E0(void *), func_002E59F8(int);
extern void func_002A7398(void *, int, int);
extern void func_L02_003E7370(void *);
extern void func_L01_0031A278(void *, void *, float, float, float);
extern void func_002A8BD0(void *, void *, int, float);
extern void func_00277F48(void *, int, void *, void *, float);
extern void func_0032C700(void *, int, int, int, int, int, int, int, int, int, int, int, float, float);
extern char *func_L02_003CEBB8(int);
extern void func_L02_003CED70(void *, void *, void *);
extern float func_00283248(float, float);
extern void func_0029F338(void *);
extern char *func_002A9640(void *, int, int);
extern void func_L02_003E79F8(void *);
/* Updates the slot-machine actor, including a triggered prize or destruction. */
void func_L02_003E6D70(char *actor) {
    char *state = *(char **)(actor + 0x68);
    float point[4], prizePoint[4];
    char hit[48];
    char *contact, *other;
    int i, index;
    float *rate;
    if (*(unsigned char *)(actor + 0x31)) func_L00_002E6CF0(func_L02_003E7B58, actor);
    switch (*(unsigned char *)(actor + 0x20)) {
    case 0:
    func_002A7750(actor, 1, -1);
    *(float *)(state + 0x20) = 3.0f;
    *(short *)(state + 0x24) = 3;
    *(float *)(state + 0x30) = 1.0f;
    *(float *)(state + 0x60) = 0.0f;
    *(int *)(state + 0xA4) = 0;
    *(float *)(state + 0x68) = 0.0f;
    *(float *)(state + 0x64) = 0.0f;
    rate = (float *)(state + 0x84);
    for (i = 2; i >= 0; i--) *rate++ = func_002A7878(D_L02_001B0A18, D_L02_001B0A1C) * 0.016666668f;
    if (func_002A77E0(2) == 0) *(unsigned short *)(actor + 0x34) &= 0x7FFF;
    else *(unsigned short *)(actor + 0x34) |= 0x8000;
    *(unsigned short *)(actor + 0x34) |= 0x4000;
        break;
    case 2:
    if (func_002B3868(actor)) {
        if (*(unsigned char *)(actor + 0x43) != 1) func_002A7470(actor, 1, 0, 1);
        func_L00_0030C710(0xF0);
        if (FLAG < 0x7F) FLAG++;
        if (FLAG > 0x24 && D_L02_001B094C < 30) {
            D_L02_001B093C -= 40;
            D_L02_001B094C += 40;
            func_0026FEB8(D_L02_001B0978);
        }
        func_0026FEB8(D_L02_001B09A8, FLAG);
    }
    if (*(unsigned char *)(actor + 0x43) == 1) {
        if (*(unsigned char *)(actor + 0x60) & 2) {
            *(unsigned short *)(actor + 0x96) = 0;
            func_002A7470(actor, 0, 0, 1);
            func_002A7750(actor, 3, -1);
        } else if (func_002AEB60(actor, 10.0f)) {
            char *slot = D_00188660 + *(int *)(state + 0x54) * 0x70;
            if (*(char **)(slot + 0x88) != actor || *(unsigned char *)(slot + 0x74) == 0)
                *(int *)(state + 0x54) = func_002E5CF8(1, 4, actor);
        }
    }
        break;
    case 3:
    func_L02_003E75A8(actor);
        break;
    case 4:
    if (func_002B3868(actor)) {
        char *slot;
        index = *(int *)(state + 0x54);
        *(int *)(state + 0x50) = 60;
        slot = D_00188660 + index * 0x70;
        if (index != -1 && *(char **)(slot + 0x88) == actor && *(unsigned char *)(slot + 0x74)) func_002E59F8(index);
        *(int *)(state + 0x54) = -1;
    }
    func_L02_003E77E0(actor);
        break;
    case 5:
    {
        char *slot;
        index = *(int *)(state + 0x54);
        slot = D_00188660 + index * 0x70;
        if (index != -1 && *(char **)(slot + 0x88) == actor && *(unsigned char *)(slot + 0x74)) func_002E59F8(index);
    }
    *(int *)(state + 0x54) = -1;
    func_002A7398(actor, 0, 0);
    func_002E5CF8(0, 0, actor);
    func_L02_003E7370(actor);
    *(unsigned short *)(actor + 0x34) = (*(unsigned short *)(actor + 0x34) & 0xBFFF) | 2;
    if (*(int *)(state + 0xA4)) {
        func_L01_0031A278(actor, point, 0.0f, 0.0f, 1.5f);
        func_002A8BD0(hit, actor, 0x810001, 2.0f);
        *(short *)(hit + 0x1A) = *(short *)(actor + 0xAA);
        *(unsigned char *)(hit + 0x19) = 1;
        *(unsigned char *)(hit + 0x18) = 2;
        func_00277F48(point, 16, actor, hit, 4.0f);
        func_0032C700(actor + 0x10, 1, 25, 20, 20, 20, 45, 0, 1, 1, 0, 0, 1.5f, 20.0f);
        if (*(int *)(state + 0x58)) {
            for (i = 0; i < 2; i++) {
                char *prize = func_L02_003CEBB8(*(int *)(state + 0x58));
                if (prize) {
                    func_L01_0031A278(actor, prizePoint, 0.5f, (float)i * 0.9f - 0.45f, 0.0f);
                    func_L02_003CED70(prize, prizePoint, D_L02_001A8F20);
                    *(float *)(prize + 0xF8) = func_00283248(((Hero *)D_00189E20)->f[0x80 / 4] - *(float *)(prize + 0x10), ((Hero *)D_00189E20)->f[0x84 / 4] - *(float *)(prize + 0x14));
                }
            }
        }
    }
    func_0029F338(actor);
    return;
    case 1:
        break;
    }
    contact = func_002A9640(actor, 0x10000, 0);
    if (!contact) return;
    other = *(char **)(contact + 0x20);
    if (other && *(short *)(other + 0xAA) != 0 && *(short *)(other + 0xAA) != 0x47 && *(float *)(contact + 0x2C) > 2.0f) {
        D_L02_001AEC78--;
        func_002A7750(actor, 5, -1);
    } else if (*(unsigned char *)(actor + 0x20) == 1 && other && *(short *)(other + 0xAA) == 0x47 && D_001A79F8 > 9) {
        D_001A79F8 -= 10;
        func_L02_003E79F8(actor);
        func_002A7750(actor, 2, -1);
    }
    *(unsigned char *)(actor + 0xA8) = 0xFF;
}
