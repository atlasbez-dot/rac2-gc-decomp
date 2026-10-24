/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 936 / 928 bytes; size equality is not a match.
 * us: 0/1 placements; 936/928 bytes.
 * us2: 0/1 placements; 936/928 bytes.
 * pal: 0/1 placements; 936/928 bytes.
 * Residual: 8 excess bytes; partial state view gives retail prologue but branch-likely scheduling and mixed absolute/GP resident reads differ.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Bounded retail reconstruction; 936/928 bytes, remaining branch/register scheduling and mixed absolute/GP reads.
 * Default -O2 -G0 -ffunction-sections; all three releases remain nonmatching. */
#include "include_asm.h"
extern unsigned char D_001A7B0B;
extern int D_001A79F0;
extern int D_L16_001A9010;
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern int func_L16_002C0BC8(int, int);
/* Partial view of the measured player-state fields. */
typedef struct PlayerStateView {
    unsigned char pad_0[0x88];
    float positionZ;
    unsigned char pad_8C[0x8C];
    float verticalVelocity;
    unsigned char pad_11C[0xC2];
    short movementLock;
    unsigned char pad_1E0[0x13C];
    float groundDistance;
    unsigned char pad_320[0x14];
    float groundZ;
    unsigned char pad_338[0x8];
    int movementMode;
    unsigned char pad_344[0x4];
    short canJump;
    unsigned char pad_34A[0x2];
    short groundState;
    unsigned char pad_34E[0x150];
    unsigned char actionReady;
    unsigned char pad_49F[0xFF1];
    short pendingAction;
    unsigned char pad_1492[0x3];
    unsigned char requestJump;
    unsigned char requestFall;
    unsigned char requestGround;
    unsigned char pad_1498[0x2];
    unsigned char requestLand;
    unsigned char requestSpecial;
    unsigned char pad_149C[0x1];
    unsigned char savedFlag;
    unsigned char pad_149E[0xDF2];
    char * player;
    int currentAction;
    unsigned char pad_2298[0x1C];
    unsigned char blocked;
    unsigned char pad_22B5[0x4];
    unsigned char transitionFlag;
    unsigned char pad_22BA[0x3];
    unsigned char disabled;
    unsigned char pad_22BE[0x20E];
    int alternateMode;
} PlayerStateView;
extern PlayerStateView D_00189E20;

/* Restore the pending movement flags and select the resulting player state. */
void func_L16_002AD320(void) {
    short pending = D_00189E20.pendingAction;
    unsigned char saved = D_00189E20.savedFlag;
    int nearGround;
    int action;
    func_00282A88((unsigned char *)&D_00189E20 + 0x1490, 16);
    D_00189E20.savedFlag = saved;
    D_00189E20.pendingAction = pending;
    D_00189E20.transitionFlag = 0;
    D_00189E20.canJump = 0;
    if (D_00189E20.disabled) return;
    nearGround = 0;
    if (D_00189E20.movementMode == 0 && D_00189E20.currentAction == 123 && D_00189E20.groundDistance < 0.4f)
        nearGround = 1;
    if (pending == -1) return;
    if (pending == 2 && D_00189E20.movementLock == 0 &&
        (D_00189E20.groundState == 0 || D_00189E20.groundDistance < 2.5f)) {
        D_00189E20.requestGround = 1;
        if (D_00189E20.blocked == 0 && D_001A7B0B != 0) D_00189E20.canJump = 1;
    }
    if (pending == 3) D_00189E20.requestFall = 1;
    if (pending == 11) D_00189E20.requestSpecial = 1;
    if (pending == 1) D_00189E20.requestJump = 1;
    if (pending == 8) D_00189E20.requestLand = 1;
    if (pending == 12) D_00189E20.requestLand = 1;
    if (D_00189E20.requestJump && nearGround && (D_00189E20.currentAction != 56 || D_00189E20.actionReady)) {
        action = 56;
        if (!D_00189E20.alternateMode) {
            if (D_001A79F0 == 2 && D_L16_001A9010) action = 125;
            else if (*(int *)(*(char **)(*(char **)((unsigned char *)&D_00189E20 + 0x2290) + 0x24) + 0x1F0)) action = 121;
            else action = 57;
        }
        func_L16_002C0BC8(action, 1);
        return;
    }
    if (D_00189E20.requestFall && D_00189E20.currentAction != 101 && D_00189E20.currentAction != 120 &&
        func_00282C48(D_00189E20.groundZ - (D_00189E20.positionZ + 0.25f)) < 1.0f &&
        D_00189E20.groundZ - D_00189E20.positionZ > 0.0f &&
        (D_00189E20.currentAction != 102 || D_00189E20.actionReady) &&
        (D_00189E20.verticalVelocity < 0.0f || D_00189E20.currentAction == 123)) {
        if (D_00189E20.alternateMode) action = 101;
        else action = 120;
        func_L16_002C0BC8(action, 1);
        return;
    }
    if (D_00189E20.requestSpecial && D_00189E20.currentAction != 120 && D_00189E20.currentAction != 116 &&
        func_00282C48(D_00189E20.groundZ - (D_00189E20.positionZ + 0.25f)) < 1.0f &&
        D_00189E20.groundZ - D_00189E20.positionZ > 0.0f &&
        (D_00189E20.verticalVelocity < 0.0f || D_00189E20.currentAction == 123)) {
        if (D_001A79F0 == 13) func_L16_002C0BC8(116, 1);
        else func_L16_002C0BC8(120, 1);
    }
}
