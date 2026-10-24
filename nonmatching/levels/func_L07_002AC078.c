/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Retained near miss: O2 G0, 1044/1044 bytes, US, US2 and PAL 0/1.
   Nine bounded trials recovered the player prefix, float guards and two call sites.
   A persistent base pointer gave 1004 bytes. Direct global field access gave 1040;
   sda scalar declarations recovered absolute macros and the GP delay-slot load.
   A direct conditional call avoided movn/movz, reaching 1044. Branch sharing into
   the two final calls still differs (+0x1bc first mismatch); some constant
   assignments also occupy different delay slots. mno-split-addresses regressed
   the frame/base construction. Reopen with independent source evidence for the
   action-selection control flow; do not repeat equivalent ternary/goto forms.
   PlayerActionView is only a field prefix; no complete player extent is asserted.
   Canonical BE770 consumes two ints and returns explicit int 0/1, ignored here.
   All three releases carry one placement and fail at +0x1bc. No integrated match is claimed. */
/* Only the fields read here are described; this is a prefix view of the player. */
typedef struct {
    unsigned char before_time[0x88];
    float time;
    unsigned char before_velocity[0x118 - 0x8c];
    float vertical_velocity;
    unsigned char before_lock[0x1de - 0x11c];
    short lock;
    unsigned char before_age[0x31c - 0x1e0];
    float age;
    unsigned char before_action_times[0x330 - 0x320];
    float action_time, jump_time;
    unsigned char before_flags[0x340 - 0x338];
    int action_flags;
    unsigned char before_special[4];
    short special, unused34a, special_lock;
    unsigned char before_jump_lock[0x49e - 0x34e];
    unsigned char jump_lock;
    unsigned char before_input[0x1490 - 0x49f];
    struct {
        short action;
        unsigned char reserved, fire, unused4, unused5, jump, special, unused8, unused9, crouch, hover, grapple, saved, unused14, unused15;
    } input;
    unsigned char before_state[0x2294 - 0x14a0];
    int state;
    unsigned char unused2298[4];
    int previous_state;
    unsigned char before_special_block[0x22b4 - 0x22a0];
    unsigned char special_block;
    unsigned char unused22b5[4];
    unsigned char request;
    unsigned char unused22ba[3];
    unsigned char disabled;
    unsigned char before_jump_mode[0x24cc - 0x22be];
    int jump_mode;
} PlayerActionView;
extern PlayerActionView D_00189E20;
extern unsigned char D_001A7B0B __attribute__((sda));
extern int D_001A79F0 __attribute__((sda));
extern void func_00282A88(void *, int);
extern float func_00282C48(float);
extern int func_L07_002BE770(int, int);

/* Preserve the requested action while clearing its transient flags, then choose a transition. */
void func_L07_002AC078(void)
{
    short action = D_00189E20.input.action;
    unsigned char saved = D_00189E20.input.saved;
    int can_fire;
    int transition;
    func_00282A88(&D_00189E20.input, 0x10);
    D_00189E20.input.saved = saved;
    D_00189E20.input.action = action;
    D_00189E20.request = 0;
    D_00189E20.special = 0;
    if (D_00189E20.disabled)
        return;
    can_fire = 0;
    if (D_00189E20.action_flags || (D_00189E20.state == 0x7b && D_00189E20.age < 0.4f))
        can_fire = 1;
    if (action == -1)
        return;
    if (action == 2 && D_00189E20.lock == 0 && (D_00189E20.special_lock == 0 || D_00189E20.age < 2.5f)) {
        D_00189E20.input.special = 1;
        if (D_00189E20.special_block == 0 && D_001A7B0B != 0)
            D_00189E20.special = 1;
    }
    if (action == 3) D_00189E20.input.jump = 1;
    if (action == 11) D_00189E20.input.hover = 1;
    if (action == 4) D_00189E20.input.fire = 1;
    if (action == 13) D_00189E20.input.grapple = 1;
    if (action == 8) D_00189E20.input.crouch = 1;
    if (action == 12) D_00189E20.input.crouch = 1;
    if (D_00189E20.input.fire && can_fire && D_00189E20.previous_state != 0x10 &&
        D_00189E20.previous_state != 0x14 && D_00189E20.previous_state != 7) {
        transition = 0x30;
        goto change;
    } else if (D_00189E20.input.grapple && D_00189E20.state != 0x7c &&
        func_00282C48(D_00189E20.action_time - (D_00189E20.time + 0.25f)) < 1.0f &&
        D_00189E20.action_time - D_00189E20.time > 0.0f &&
        (D_00189E20.vertical_velocity < 0.0f || D_00189E20.state == 0x7b)) {
        transition = 0x7c;
        goto change;
    } else if (D_00189E20.input.jump && D_00189E20.state != 0x65 && D_00189E20.state != 0x78 &&
        func_00282C48(D_00189E20.jump_time - (D_00189E20.time + 0.25f)) < 1.0f &&
        D_00189E20.jump_time - D_00189E20.time > 0.0f &&
        (D_00189E20.state != 0x66 || D_00189E20.jump_lock != 0) &&
        (D_00189E20.vertical_velocity < 0.0f || D_00189E20.state == 0x7b)) {
        if (D_00189E20.jump_mode == 0) {
            func_L07_002BE770(0x78, 1);
            return;
        }
        transition = 0x65;
        goto change;
    } else {
        if (!D_00189E20.input.hover || D_00189E20.state == 0x78 || D_00189E20.state == 0x74 ||
            !(func_00282C48(D_00189E20.jump_time - (D_00189E20.time + 0.25f)) < 1.0f) ||
            !(D_00189E20.jump_time - D_00189E20.time > 0.0f) ||
            (!(D_00189E20.vertical_velocity < 0.0f) && D_00189E20.state != 0x7b))
            return;
        if (D_001A79F0 == 0xd) {
            transition = 0x74;
            goto change;
        }
        transition = 0x78;
        goto fallback;
    }
change:
    func_L07_002BE770(transition, 1);
    return;
fallback:
    func_L07_002BE770(transition, 1);
}
