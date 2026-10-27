/* Near miss (M5): 796/792 B under `-O2 -G8 -ffunction-sections -frac2-qcopy`, 0/27.
   Solved: the three level ints are incomplete sda arrays read/written as [0] (retail's tied
   `lui $r; lw $r` / `lui $at; sw` forms) and D_L00_001AF0E4 a sized sda float ($gp), which
   needs the -G8 profile; the yaw/pitch test is `if (D_L00_001A8FF0[0]) zeros else angles`;
   the three trailing zeros are float stores through one register (mtc1 $zero, chained here).
   Left: retail's copy into `start` folds the source offset (`lq $v0,0x10($s2)`, ordinary
   TI lowering) while its other three copies use register addresses; -frac2-qcopy gives
   registers for all four (+1 insn), the default profile folds all four (768 B). Also the
   0x30/0x20/0x31/0x32 byte-store order and the $s0/$s1 pair for side/actor+0xE0.
   The asm qcopy() helper in the earlier draft is not honest C. */
#include "include_asm.h"
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct {
    char pad00[0x110]; float velocity[4]; char pad120[0x21C]; u8 *supportObject;
    char pad340[0x420]; float axis[4]; char pad770[0x1A90]; float matrix[2][16];
    char *current; char pad2284[0xC]; char *object;
} TetherHero;
extern TetherHero D_00189E20;
extern int D_L00_001B1BE8[] __attribute__((sda)), D_L00_001B1A4C[] __attribute__((sda)), D_L00_001A8FF0[] __attribute__((sda));
extern float D_L00_001AF0E4 __attribute__((sda));
extern float D_L00_001BF220[4];
extern char *func_0029EFD0(int);
extern s32 func_002AD0B0(u8 *);
extern float func_00282DF0(void *);
extern void func_L00_00390E10(void *), func_002A0F48(void *);
extern char *func_L00_004282F0(void *);
extern void func_L00_002C42E0(int a0, int a1);
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
    float start[4] __attribute__((aligned(16)));
    float side[4];
    if (actor) {
        state = *(char **)(actor + 0x68);
        D_L00_001B1BE8[0] = 1;
        D_00189E20.current = actor;
        *(u8 *)(actor + 0x30) = 0xFF;
        *(u8 *)(actor + 0x20) = 1;
        *(u8 *)(actor + 0x31) = 1;
        *(u16 *)(actor + 0x32) = 0xFF;
        if (D_L00_001A8FF0[0]) {
            *(float *)(actor + 0xF8) = 0;
            *(float *)(actor + 0xF4) = 0;
        } else {
            *(float *)(actor + 0xF8) = yaw;
            *(float *)(actor + 0xF4) = pitch;
        }
        *(float *)(actor + 0xF0) = 0;
        *(float *)(actor + 0xFC) = 0;
        *(float **)(state + 0x24) = D_00189E20.matrix[0];
        *(float **)(state + 0x28) = D_00189E20.matrix[1];
        *(char **)state = owner;
        *(Quad *)(actor + 0x10) = *(Quad *)(position);
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
        *(Quad *)(start) = *(Quad *)(owner + 0x10);
        start[2] = ((float *)position)[2];
        if (func_002761F8(start, position, 0, D_00189E20.object, 0)) {
            *(u8 *)(actor + 0xBC) = 1;
            *(Quad *)(actor + 0x10) = *(Quad *)(D_L00_001BF220);
        }
        D_L00_001B1A4C[0] = 1;
        func_002B0CE0(6, 0, 1);
        if (D_L00_001A8FF0[0]) {
            *(u16 *)(actor + 0x34) |= 0x100;
            *(Quad *)(actor + 0xC0) = *(Quad *)(D_00189E20.axis);
            func_002AFFD8(actor + 0x10, actor + 0xE0, 1);
            func_00282DD8(side, actor + 0xC0, actor + 0xE0);
            func_00282F20(actor + 0xD0, side, 1.0f);
            func_00282DD8(actor + 0xE0, actor + 0xD0, actor + 0xC0);
            *(float *)(actor + 0xCC) = *(float *)(actor + 0xEC) = *(float *)(actor + 0xDC) = 0.0f;
        }
        *(int *)(state + 0x4C) = func_002FED90(actor, 0, 1.0f, 1.0f, 1.0f);
    }
    return actor;
}
