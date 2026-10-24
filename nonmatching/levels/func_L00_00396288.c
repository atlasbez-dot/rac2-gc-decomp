/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00396288: 0 of 27 places match (src/levels/shared/L00_00396288.c); us2: func_L00_00396288: 0 of 27 places match (src/levels/shared/L00_00396288.c); pal: absent. Two manual trials; final1552/1604 frame0x60. Corrected state+0x20 to target pointer (retail integer loads), removing spurious FP save. State timer/light/fade/sound are integers; full light allocator twoGPR/twoFP inputs preserved. Remaining global base sharing, branch/switch and register allocation differences; reopen with source layout evidence. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef struct {
    Vector start, end;
    void *target;
    float length;
    int unknown28, timer, light, fade;
    short cooldown;
    char unknown3A[6];
    int sound;
} BeamState;
extern char D_00189E20[] NOT_SDA, D_00138180[] NOT_SDA, D_00188660[] NOT_SDA;
extern float D_0025C64C NOT_SDA;
extern float D_0018A550[4][4] NOT_SDA, D_L00_001B8FF0[4][4];
extern float D_L00_001C6F40[8][8];
extern int D_L00_001AF2E0 __attribute__((sda));
extern int func_00291308(void *, int, float, float), func_00282948(int *);
extern void func_00291450(int), func_00283098(void *, void *, void *);
extern void func_0029FCC0(char *, int, char *), func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *), func_0030CAD0(char *), func_0030CCD0(char *);
extern void func_0030DE88(char *, int), func_L00_002AF568(void), func_L00_002AF7D0(void);
extern void func_0030D430(void *), func_L00_002E6EF8(void (*)(void *), void *);
extern void func_002E59F8(int);
extern int func_002E5CF8(int, int, char *);
extern float func_00283CE0(int);
/* Maintains the beam's endpoint, light fade and looping sound state. */
void func_L00_00396288(char *actor) {
    Vector offset;
    BeamState *beam = *(BeamState **)(actor + 0x68);
    char *player = D_00189E20, *input = D_00138180;
    char *sound;
    float fade;
    int stopping = *(int *)(player + 0x1244) == 3;
    int active = 0;
    if ((*(u32 *)(input + 0x1A4) & *(u32 *)(player + 0x1230)) && !((u8 *)player)[0x22BC])
        beam->length = 0.8f;
    D_0025C64C = 0.9f;
    if (!*(int *)(player + 0x5C0)) beam->target = 0;
    else if ((u8)actor[0x20] == 4) beam->target = 0;
    else if (!(u8)actor[0x20]) beam->target = 0;
    else if (((u8 *)player)[0x22BC]) beam->target = 0;
    else if (*(int *)(player + 0x2294) == 0x6F) beam->target = 0;
    else if (!beam->timer) {
        if (beam->light == -1) beam->light = func_00291308(actor + 0x10, 0, 7.5f, 0);
        else if (beam->fade < 10) beam->fade++;
        active = 1;
        beam->start.quad = *(Quad *)(actor + 0x10);
        beam->start.f[2] += 0.7f;
        beam->end.quad = beam->start.quad;
        beam->length += (12.0f - beam->length) * 0.07f;
        if (*(int *)(player + 0x2294) == 1) {
            offset.f[0] = 1.2f; offset.f[1] = 0; offset.f[2] = 0;
            func_00283098(&offset, &offset, D_L00_001B8FF0);
            beam->start.f[2] = offset.f[2] + *(float *)(actor + 0x18);
            beam->start.f[0] = offset.f[0] + *(float *)(player + 0x80);
            beam->start.f[1] = offset.f[1] + *(float *)(player + 0x84);
            offset.f[0] = beam->length; offset.f[1] = 0; offset.f[2] = 0;
            func_00283098(&offset, &offset, D_L00_001B8FF0);
            func_00282CC0(&beam->end, &beam->start, &offset);
        } else if (*(short *)(player + 0x24EC) == 1) {
            func_0029FCC0(actor, 0, (char *)&beam->start);
            offset.f[0] = 0; offset.f[1] = -beam->length; offset.f[2] = 0;
            func_00283098(&offset, &offset, actor + 0xC0);
            func_00282CC0(&beam->end, &beam->start, &offset);
        } else {
            func_0029FCC0(actor, 0, (char *)&beam->start);
            func_00282F20(&beam->end, D_0018A550, beam->length);
            func_00282CC0(&beam->end, &beam->start, &beam->end);
        }
        func_0030CAD0(actor); func_0030CCD0(actor);
        func_L00_002E6EF8(func_0030D430, actor);
    }
    if (!active) {
        D_L00_001AF2E0 = 1;
        if (beam->fade > 0) beam->fade--;
    }
    switch ((u8)actor[0x20]) {
    case 0:
        beam->timer = 16;
        beam->light = func_00291308(&beam->start, 0, 0, 0);
        D_L00_001AF2E0 = 1;
        actor[0x20] = 1;
        beam->sound = -1; beam->target = 0; beam->cooldown = 20;
        func_002E5CF8(1, 0, actor);
        break;
    case 1:
        func_00282948(&beam->timer);
        sound = D_00188660 + beam->sound * 0x70;
        if (beam->sound != -1 && *(char **)(sound + 0x88) == actor && sound[0x74])
            func_002E59F8(beam->sound);
        beam->sound = -1;
        if (active) { func_L00_002AF568(); actor[0x20] = 3; }
        if ((*(u32 *)(input + 0x1A4) & *(u32 *)(player + 0x1230)) && !((u8 *)player)[0x22BC]) {
            func_0030DE88(actor, 20);
            if (active) { func_L00_002AF568(); actor[0x20] = 3; }
            else { func_002E5CF8(2, 0, actor); beam->target = 0; actor[0x20] = 1; func_L00_002AF7D0(); }
        }
        break;
    case 3:
        sound = D_00188660 + beam->sound * 0x70;
        if (*(char **)(sound + 0x88) != actor || !sound[0x74]) beam->sound = func_002E5CF8(0, 4, actor);
        if ((*(u32 *)(input + 0x1A8) & *(u32 *)(player + 0x1230)) || !active || ((u8 *)player)[0x22BC]) {
            beam->target = 0; beam->length = 0;
            func_L00_002AF7D0(); actor[0x20] = 1;
        }
        break;
    case 2: case 4: case 5: default: break;
    }
    if (beam->light != -1) {
        offset.quad = 0;
        offset.f[0] = 2; offset.f[2] = 2;
        func_00283098(&offset, &offset, D_0018A550);
        D_L00_001C6F40[beam->light][4] = *(float *)(player + 0x80) + offset.f[0];
        D_L00_001C6F40[beam->light][5] = *(float *)(player + 0x84) + offset.f[1];
        D_L00_001C6F40[beam->light][6] = *(float *)(player + 0x88) + offset.f[2];
        D_L00_001C6F40[beam->light][7] = 7.5f;
        fade = func_00283CE0(beam->fade) * 0.1f;
        D_L00_001C6F40[beam->light][2] = fade;
        D_L00_001C6F40[beam->light][1] = fade * 0.7f;
        D_L00_001C6F40[beam->light][0] = D_L00_001C6F40[beam->light][1];
        if (!stopping) return;
        if (beam->light != -1) { func_00291450(beam->light); beam->light = -1; }
    }
    if (stopping && beam->light == -1) actor[0x20] = 4;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00396288 - 1604 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00396288. Screened with tools/w10_screen.py: 25 call(s)
   [func_00291308@00396394, func_00283098@0039644C, func_0029FCC0@003964B4,
   func_00283098@003964DC, func_00282CC0@003964EC, func_0029FCC0@00396500,
   func_00282F20@00396510, func_00282CC0@00396520, func_0030CAD0@00396528,
   func_0030CCD0@00396530, func_L00_002E6EF8@00396540,
   func_00291308@003965B0, func_002E5CF8@003965E4, func_00282948@003965F4,
   func_002E59F8@00396634, func_L00_002AF568@00396648,
   func_0030DE88@00396684, func_L00_002AF568@00396694,
   func_002E5CF8@003966A8, func_L00_002AF7D0@003966B8,
   func_002E5CF8@00396700, func_L00_002AF7D0@00396740,
   func_00283098@00396784, func_00283CE0@00396804, func_00291450@00396874];
   data addresses materialised [0x190000, 0x140000, 0x3f4c0000, 0x3f660000,
   0x3f330000, 0x3d8f0000, 0x3f990000, 0x1c0000, 0x390000, 0x2a0000,
   0x190000, 0x190000, 0x1c0000, 0x3dcc0000, 0x3f330000]; float constants
   [0x260000, 0x40f00000, 0x41400000, 0x190000, 0x40000000, 0x40f00000];
   $gp-relative small data: yes   saves: -; callee-saved registers saved
   [-]; words plain C cannot emit [LQ/SQ 7A020000@0x0134, LQ/SQ
   7E420000@0x0138, LQ/SQ 7A420000@0x015c, LQ/SQ 7E220000@0x0160, LQ/SQ
   7FA00000@0x04d8]. Head: addiu $sp, $sp, -0x60 ; lui $v1, 0x19 ; sd $s3,
   0x28($sp) ; lui $v0, 0x14 ; sd $s6, 0x40($sp) ; addiu $a3, $v1, -0x61E0.
   Not matched in this wave: the 128-bit copy needs an `lq`/`sq` pair; plain
   C reaches it only through a `mode(TI)` local, and this cc1 folds the
   destination offset into the `sq` where retail materialises the pointer
   first. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */
