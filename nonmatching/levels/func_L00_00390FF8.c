/* Nonmatching: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: func_L00_00390FF8: 0 of 27 places match (src/levels/shared/L00_00390FF8-g8.c); us2: func_L00_00390FF8: 0 of 27 places match (src/levels/shared/L00_00390FF8-g8.c); pal: absent. Two source trials792 then788/792 bytes, original0x70 frame. Correct two GPR pointer plus two float incoming ABI, AD0B0 live support-object input, float vector length return and camera allocator pointer return. Typed resident view covers exact matrix/support/axis fields; real64-byte matrices. Remaining initialization scheduling/branch polarity and three zero W fields use integer stores versus retail COP1 stores. Reopen with source layout/zero-store evidence; no volatile/barrier tricks. */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    char pad00[0x110]; float velocity[4]; char pad120[0x21C]; u8 *supportObject;
    char pad340[0x420]; float axis[4]; char pad770[0x1A90]; float matrix[2][16];
    char *current; char pad2284[0xC]; char *object;
} TetherHero;
extern TetherHero D_00189E20;
extern int D_L00_001B1BE8, D_L00_001B1A4C, D_L00_001A8FF0;
extern float D_L00_001AF0E4 __attribute__((sda));
extern float D_L00_001BF220[4];
extern char *func_0029EFD0(int);
extern s32 func_002AD0B0(u8 *);
extern float func_00282DF0(void *);
extern void func_L00_00390E10(void *), func_002A0F48(void *);
extern char *func_L00_004282F0(void *);
extern int func_L00_002C42E0(int, int);
extern void func_00282A60(void *, int, int), func_0029F978(u8 *, u32, u8 *);
extern char *func_L00_00395240(char *);
extern void func_002AB650(u8 *);
extern int func_002E5CF8(int, int, char *), func_002761F8(void *, void *, int, void *, int), func_002B0CE0(int, int, int);
extern void func_002AFFD8(char *, char *, int), func_00282DD8(void *, void *, void *), func_00282F20(void *, void *, float);
extern int func_002FED90(void *, int, float, float, float);
/* Creates the active tether actor and its attachments, inheriting the hero's support frame. */
char *func_L00_00390FF8(char *owner, char *position, float yaw, float pitch) {
    char *actor = func_0029EFD0(0xAC);
    char *state;
    float start[4], side[4];
    if (actor) {
        state = *(char **)(actor + 0x68);
        D_L00_001B1BE8 = 1;
        D_00189E20.current = actor;
        *(u8 *)(actor + 0x30) = 0xFF;
        *(u8 *)(actor + 0x20) = 1;
        *(u8 *)(actor + 0x31) = 1;
        *(u16 *)(actor + 0x32) = 0xFF;
        if (D_L00_001A8FF0 == 0) {
            *(float *)(actor + 0xF8) = yaw;
            *(float *)(actor + 0xF4) = pitch;
        } else {
            *(float *)(actor + 0xF8) = 0;
            *(float *)(actor + 0xF4) = 0;
        }
        *(float *)(actor + 0xF0) = 0;
        *(float *)(actor + 0xFC) = 0;
        *(float **)(state + 0x24) = D_00189E20.matrix[0];
        *(float **)(state + 0x28) = D_00189E20.matrix[1];
        *(char **)state = owner;
        *(Quad *)(actor + 0x10) = *(Quad *)position;
        *(int *)(state + 8) = 0;
        *(int *)(state + 0xC) = 0;
        if (D_00189E20.supportObject && func_002AD0B0(D_00189E20.supportObject))
            *(float *)(state + 4) = func_00282DF0(D_00189E20.velocity);
        else *(float *)(state + 4) = 0;
        *(int *)(state + 0x18) = 0;
        *(int *)(state + 0x1C) = 0;
        *(int *)(state + 0x14) = 0;
        *(float *)(state + 0x44) = 0.4f;
        *(int *)(state + 0x10) = 3000;
        func_L00_00390E10(actor);
        func_002A0F48(actor);
        *(char **)(state + 0x14) = func_L00_004282F0(actor);
        func_L00_002C42E0(28, 1);
        func_00282A60(*(void **)(state + 0x24), 0, 64);
        func_00282A60(*(void **)(state + 0x28), 0, 64);
        func_0029F978((u8 *)actor, 0, *(u8 **)(state + 0x24));
        func_0029F978((u8 *)actor, 1, *(u8 **)(state + 0x28));
        *(char **)(state + 0x20) = func_L00_00395240(actor);
        *(float *)(state + 0x48) = D_L00_001AF0E4 * 0.016666668f;
        func_002AB650((u8 *)actor);
        *(int *)(state + 0x2C) = func_002E5CF8(0, 4, actor);
        *(Quad *)start = *(Quad *)(owner + 0x10);
        start[2] = ((float *)position)[2];
        if (func_002761F8(start, position, 0, D_00189E20.object, 0)) {
            *(u8 *)(actor + 0xBC) = 1;
            *(Quad *)(actor + 0x10) = *(Quad *)D_L00_001BF220;
        }
        D_L00_001B1A4C = 1;
        func_002B0CE0(6, 0, 1);
        if (D_L00_001A8FF0) {
            *(u16 *)(actor + 0x34) |= 0x100;
            *(Quad *)(actor + 0xC0) = *(Quad *)D_00189E20.axis;
            func_002AFFD8(actor + 0x10, actor + 0xE0, 1);
            func_00282DD8(side, actor + 0xC0, actor + 0xE0);
            func_00282F20(actor + 0xD0, side, 1.0f);
            func_00282DD8(actor + 0xE0, actor + 0xD0, actor + 0xC0);
            *(float *)(actor + 0xCC) = 0;
            *(float *)(actor + 0xEC) = 0;
            *(float *)(actor + 0xDC) = 0;
        }
        *(int *)(state + 0x4C) = func_002FED90(actor, 0, 1.0f, 1.0f, 1.0f);
    }
    return actor;
}

/* Historical screening only; superseded by the measured reconstruction above. */
/* func_L00_00390FF8 - 792 bytes, 27 place(s), level 00_aranos_tutorial,
   retail at 0x00390ff8. Screened with tools/w10_screen.py: 21 call(s)
   [func_0029EFD0@00391034, func_002AD0B0@003910DC, func_00282DF0@003910EC,
   func_L00_00390E10@00391128, func_002A0F48@00391130,
   func_L00_004282F0@00391138, func_L00_002C42E0@00391148,
   func_00282A60@00391158, func_00282A60@00391168, func_0029F978@00391178,
   func_0029F978@00391188, func_L00_00395240@00391190,
   func_002AB650@003911B4, func_002E5CF8@003911C4, func_002761F8@003911F0,
   func_002B0CE0@00391228, func_002AFFD8@00391264, func_00282DD8@0039127C,
   func_00282F20@00391290, func_00282DD8@003912A0, func_002FED90@003912D0];
   data addresses materialised [0x190000, 0x1b0000, 0x1b0000, 0x190000,
   0x3ecc0000, 0x3c880000, 0x1c0000, 0x1b0000, 0x1b0000]; float constants
   [0x3f800000, 0x3f800000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [LQ/SQ
   7A220000@0x00c8, LQ/SQ 7C620000@0x00cc, LQ/SQ 7A420010@0x01e4, LQ/SQ
   7FA20000@0x01f0, LQ/SQ 78620000@0x0214, LQ/SQ 7E620000@0x0218, LQ/SQ
   78820000@0x0258, LQ/SQ 7E420000@0x025c]. Head: addiu $sp, $sp, -0x70 ; sd
   $s2, 0x30($sp) ; sd $s1, 0x28($sp) ; daddu $s2, $a0, $zero ; swc1 $f21,
   0x68($sp) ; daddu $s1, $a1, $zero. Not matched in this wave: the 128-bit
   copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */
