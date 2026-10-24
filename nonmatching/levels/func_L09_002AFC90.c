/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 1088 / 1072 bytes; size equality is not a match.
 * us: 0/1 placements; 1088/1072 bytes.
 * us2: 0/1 placements; 1088/1072 bytes.
 * pal: 0/1 placements; 1088/1072 bytes.
 * Residual: 16 excess bytes; branch/address/register scheduling differs. Two additional pending-mode cases reconstructed from retail.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Bounded retail reconstruction; 1088/1072 bytes, remaining branch/register scheduling and mixed absolute/GP reads.
 * Default -O2 -G0 -ffunction-sections; all three releases remain nonmatching. */
#include "include_asm.h"
extern unsigned char D_00189E20[];
extern unsigned char D_001A7B0B;
extern int D_001A79F0;
extern int D_L09_001A9010;
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern int func_L09_002C3580(int, int);
#define S16(off) (*(short *)(D_00189E20 + (off)))
#define S32(off) (*(int *)(D_00189E20 + (off)))
#define F32(off) (*(float *)(D_00189E20 + (off)))
#define BYTE(off) (D_00189E20[(off)])

/* Restore the pending movement flags and select the resulting player state. */
void func_L09_002AFC90(void) {
    short pending = S16(0x1490);
    unsigned char saved = BYTE(0x149D);
    int nearGround;
    int action;
    func_00282A88(D_00189E20 + 0x1490, 16);
    BYTE(0x149D) = saved;
    S16(0x1490) = pending;
    BYTE(0x22B9) = 0;
    S16(0x348) = 0;
    if (BYTE(0x22BD)) return;
    nearGround = 0;
    if (S32(0x340) == 0 && S32(0x2294) == 123 && F32(0x31C) < 0.4f)
        nearGround = 1;
    if (pending == -1) return;
    if (pending == 2 && S16(0x1DE) == 0 &&
        (S16(0x34C) == 0 || F32(0x31C) < 2.5f)) {
        BYTE(0x1497) = 1;
        if (BYTE(0x22B4) == 0 && D_001A7B0B != 0) S16(0x348) = 1;
    }
    if (pending == 14) {
        BYTE(0x1494) = 1;
        F32(0x330) = F32(0x318) + 0.2f;
        F32(0x24C4) = 0.2f;
    }
    if (pending == 0) {
        F32(0x24C4) = F32(0x330) - F32(0x318);
        if (F32(0x24C4) < 0.85f && F32(0x24C4) > 0.25f) BYTE(0x22B9) = 1;
        BYTE(0x1494) = 1;
    }
    if (pending == 3) BYTE(0x1496) = 1;
    if (pending == 11) BYTE(0x149B) = 1;
    if (pending == 1) BYTE(0x1495) = 1;
    if (pending == 8) BYTE(0x149A) = 1;
    if (pending == 12) BYTE(0x149A) = 1;
    if (BYTE(0x1495) && nearGround && (S32(0x2294) != 56 || BYTE(0x49E))) {
        action = 56;
        if (!S32(0x24CC)) {
            if (D_001A79F0 == 2 && D_L09_001A9010) action = 125;
            else if (*(int *)(*(char **)(*(char **)(D_00189E20 + 0x2290) + 0x24) + 0x1F0)) action = 121;
            else action = 57;
        }
        func_L09_002C3580(action, 1);
        return;
    }
    if (BYTE(0x1496) && S32(0x2294) != 101 && S32(0x2294) != 120 &&
        func_00282C48(F32(0x334) - (F32(0x88) + 0.25f)) < 1.0f &&
        F32(0x334) - F32(0x88) > 0.0f &&
        (S32(0x2294) != 102 || BYTE(0x49E)) &&
        (F32(0x118) < 0.0f || S32(0x2294) == 123)) {
        if (S32(0x24CC)) action = 101;
        else action = 120;
        func_L09_002C3580(action, 1);
        return;
    }
    if (BYTE(0x149B) && S32(0x2294) != 120 && S32(0x2294) != 116 &&
        func_00282C48(F32(0x334) - (F32(0x88) + 0.25f)) < 1.0f &&
        F32(0x334) - F32(0x88) > 0.0f &&
        (F32(0x118) < 0.0f || S32(0x2294) == 123)) {
        if (D_001A79F0 == 13) func_L09_002C3580(116, 1);
        else func_L09_002C3580(120, 1);
    }
}
