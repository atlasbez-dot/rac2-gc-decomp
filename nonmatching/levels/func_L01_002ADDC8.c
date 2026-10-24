/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Retained manual reconstruction, 23 October 2026; NOT MATCHING.
 *
 * Profile: -O2 -G8 -ffunction-sections
 *
 * Meaningful bounded trials: 8.
 *
 * USA v1.01, USA v2.00 and PAL: 856/860 bytes, 0/1 placements each. The frame and much of the
 * transient-action setup agree; control-flow merging and saved-register lifetimes remain
 * different. A typed accessed resident prefix recovered the retail base reuse. Plain G8
 * preserves the observed mixed GP/absolute load forms; sda and no-split-address trials were
 * discarded.
 *
 * Reopen with independently supported lifetime/control-flow changes for the shared transition
 * call and the special-mode flag load.
 *
 * No strict linked build or runtime validation is claimed.
 */
#include "common.h"

/* Only the accessed resident prefix is described. */
typedef struct PlayerActionView {
    unsigned char pad0[0x88]; float height;
    unsigned char pad8C[0x118 - 0x8C]; float verticalSpeed;
    unsigned char pad11C[0x1DE - 0x11C]; short blocked;
    unsigned char pad1E0[0x31C - 0x1E0]; float elapsed;
    unsigned char pad320[0x334 - 0x320]; float groundHeight;
    unsigned char pad338[0x340 - 0x338]; int active;
    unsigned char pad344[4]; short request;
    unsigned char pad34A[2]; short groundFlag;
    unsigned char pad34E[0x49E - 0x34E]; unsigned char allowAction;
    unsigned char pad49F[0x1490 - 0x49F]; short action;
    unsigned char pad1492; unsigned char jump;
    unsigned char pad1494[2]; unsigned char climb; unsigned char interact;
    unsigned char pad1498[2]; unsigned char alternate; unsigned char fall;
    unsigned char pad149C; unsigned char saved;
    unsigned char pad149E[0x2294 - 0x149E]; int state;
    unsigned char pad2298[4]; int mode;
    unsigned char pad22A0[0x22B4 - 0x22A0]; unsigned char specialMode;
    unsigned char pad22B5[4]; unsigned char transient;
    unsigned char pad22BA[3]; unsigned char locked;
    unsigned char pad22BE[0x24CC - 0x22BE]; int alternateState;
} PlayerActionView;
extern PlayerActionView D_00189E20;
extern unsigned char D_001A7B0B __attribute__((section(".data")));
extern int D_001A79F0;
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern int func_L01_002BEB90(int, int);

/* Restore transient action flags before processing contextual transitions. */
void func_L01_002ADDC8(void)
{
    short action = D_00189E20.action;
    unsigned char saved = D_00189E20.saved;
    int active;
    int next;

    func_00282A88(&D_00189E20.action, 16);
    D_00189E20.saved = saved;
    D_00189E20.action = action;
    D_00189E20.transient = 0;
    D_00189E20.request = 0;
    if (D_00189E20.locked != 0) return;
    active = 0;
    if (D_00189E20.active != 0) active = 1;
    else if (D_00189E20.state == 0x7B && D_00189E20.elapsed < 0.4f) active = 1;
    if (action == -1) return;
    if (action == 2 && D_00189E20.blocked == 0 &&
        (D_00189E20.groundFlag == 0 || D_00189E20.elapsed < 2.5f)) {
        D_00189E20.interact = 1;
        if (D_00189E20.specialMode == 0 && D_001A7B0B != 0) D_00189E20.request = 1;
    }
    if (action == 3) D_00189E20.climb = 1;
    if (action == 11) D_00189E20.fall = 1;
    if (action == 4) D_00189E20.jump = 1;
    if (action == 8) D_00189E20.alternate = 1;
    if (action == 12) D_00189E20.alternate = 1;
    if (D_00189E20.jump && active && D_00189E20.mode != 16 &&
        D_00189E20.mode != 20 && D_00189E20.mode != 7) {
        next = 48;
    } else if (D_00189E20.climb && D_00189E20.state != 101 &&
        D_00189E20.state != 120 &&
        func_00282C48(D_00189E20.groundHeight - (D_00189E20.height + 0.25f)) < 1.0f &&
        D_00189E20.groundHeight - D_00189E20.height > 0.0f &&
        (D_00189E20.state != 102 || D_00189E20.allowAction != 0) &&
        (D_00189E20.verticalSpeed < 0.0f || D_00189E20.state == 123)) {
        if (D_00189E20.alternateState == 0) { next = 120; goto change; }
        next = 101;
    } else if (D_00189E20.fall && D_00189E20.state != 120 &&
        D_00189E20.state != 116 &&
        func_00282C48(D_00189E20.groundHeight - (D_00189E20.height + 0.25f)) < 1.0f &&
        D_00189E20.groundHeight - D_00189E20.height > 0.0f &&
        (D_00189E20.verticalSpeed < 0.0f || D_00189E20.state == 123)) {
        if (D_001A79F0 == 13) {
            func_L01_002BEB90(116, 1);
            return;
        }
        next = 120;
    } else return;
change:
    func_L01_002BEB90(next, 1);
}
