/*
 * Retained reconstruction, 23 October 2026. USA v1.01: 2900/2940 bytes, 0/26 catalogue
 * placements. The canonical row is absent from USA v2.00 and PAL; neither absence is a match.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-keep-block-order
 * -frac2-gcse-unsplit-edges.
 * Six meaningful trials: a byte-addressed root compiled to 2920 bytes; the measured
 * HeroActionState prefix corrected root address formation (2904). Separate transition calls and
 * a required global target reload after atan reached 2900. Disabling GCSE gave 2964 with worse
 * allocation. Broad control-flow, saved-register lifetime and scheduling differences remain; the
 * frame and initial root addressing agree.
 * The seven dispatch destinations were read from all 56 retail table entries, not inferred from
 * source order. This source retains the actual table binding and uses the established local-
 * label keeper pattern. All helper current C definitions and unknown marker APIs were inspected
 * against retail: integer conversion, atan and angle difference return banks, input-history
 * output pointers, pointer-returning target search and the ignored incoming value 21 are
 * preserved.
 * Reopen with independently justified control-flow/live-range evidence for the buffered action
 * branches. Do not classify por, vector copies or instruction scheduling as handwritten
 * assembly. No strict linked build was run.
 */

#include "include_asm.h"

typedef int Quadword __attribute__((mode(TI)));
typedef unsigned int u32;
typedef unsigned long long u64;
/* Fields used here are a prefix of the resident hero state, not its total size. */
typedef struct {
    unsigned char pad_000[128];
    float position[4];
    unsigned char pad_090[8];
    float heading;
    unsigned char pad_09C[284];
    int frame;
    unsigned char pad_1BC[74];
    short control_lock;
    unsigned char pad_208[8];
    u64 motion_flags;
    unsigned char pad_218[260];
    float movement;
    unsigned char pad_320[32];
    int action_ready;
    unsigned char pad_344[4];
    short special_ready;
    unsigned char pad_34A[4];
    short extended_range;
    unsigned char pad_350[332];
    unsigned char grounded;
    unsigned char pad_49D[1];
    unsigned char fast_attack;
    unsigned char pad_49F[53];
    int attack_mode;
    unsigned char pad_4D8[84];
    unsigned char alternate_ready;
    unsigned char pad_52D[103];
    int attack_pending;
    unsigned char pad_598[40];
    char *aim_target;
    float target_angle;
    unsigned char pad_5C8[292];
    int attack_blocked;
    unsigned char pad_6F0[952];
    int nearby_ready;
    unsigned char pad_AAC[24];
    float nearby_distance;
    unsigned char pad_AC8[16];
    float alternate_distance;
    unsigned char pad_ADC[2];
    short alternate_target_ready;
    unsigned char pad_AE0[52];
    int second_target_ready;
    unsigned char pad_B18[228];
    short animation_index;
    unsigned char pad_BFE[46];
    int attack_delay;
    unsigned char pad_C30[8];
    float animation_frame;
    unsigned char pad_C3C[1508];
    char *object;
    unsigned char pad_1224[12];
    u32 buttons;
    unsigned char pad_1234[6];
    unsigned char input_locked;
    unsigned char pad_123B[5];
    int input_window;
    int control_mode;
    int action;
    unsigned char pad_124C[590];
    unsigned char action_locked;
    unsigned char pad_149B[3573];
    char *owner;
    int mode;
    unsigned char pad_2298[4];
    u32 state;
    unsigned char pad_22A0[20];
    unsigned char disabled;
    unsigned char pad_22B5[3];
    unsigned char changing_weapon;
    unsigned char pad_22B9[3];
    unsigned char special_control;
    unsigned char pad_22BD[39];
    int pending_action;
    unsigned char pad_22E8[464];
    float transition_progress;
} HeroActionState;
extern HeroActionState D_00189E20;
extern u32 D_00138320[];
extern unsigned char D_00139568[];
extern unsigned char D_001A7B2E[];
extern int D_001A739C[];
extern int D_L00_001A7CC4;
extern void *D_L00_002A0640[];
typedef struct { char pad[12]; int first_frame, trigger_frame; char rest[24]; } AnimationRange;
extern AnimationRange D_L00_0025D990[];
typedef struct { char pad[20]; int sound; char rest[200]; } EffectDefinition;
extern EffectDefinition D_L00_00262570[];

/* The retail helper consumes a button mask, a history window and optional age output. */
extern int func_L00_0032EF10(u32, int, int *);
extern int func_L00_002B3248(unsigned char *);
/* The incoming value is dead in the helper, but this caller supplies it. */
extern void func_L00_002BA508(int);
extern int func_00283CF0(float);
extern int func_L00_002C42E0(int, int);
extern int func_L00_002D4040(int);
extern int func_002E5DA0(int, int, char *, int);
extern char *func_L00_002AE888(void *, int, int, float, float, float, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern float func_00283248(float, float);
extern float func_00283BE0(float, float);
extern void func_L00_002C3BB0(void);
extern int func_L00_002C3E18(void);
extern int func_L00_002C40C0(void);
extern void func_L00_002AF568(void);
extern int func_002E5CF8(int, int, char *);
extern int func_00282948(int *);


/* Selects context-sensitive hero actions from buffered input and nearby targets. */
int func_L00_002C9448(void)
{
    /* The dispatch reads the retail table; this array retains its destination labels. */
    static void *cases[] = { &&state_10, &&state_22, &&state_46, &&state_13,
                            &&state_12, &&state_53, &&state_other };
    float point[4];
    int input_age, action_age, detach_age;
    int previous_frame, action, frame_window, difference, state;
    u32 mask;
    char *object;
    AnimationRange *range;
    float threshold, direction;

    if (D_00189E20.special_control) {
        if (D_00189E20.action != 10)
            return 0;
        if (D_00189E20.special_ready != 1)
            return 0;
    }
    if (D_00189E20.disabled) return 0;
    if (!D_00189E20.object) return 0;
    if (D_00189E20.input_locked) return 0;
    if (D_00189E20.control_mode != 2) return 0;

    state = D_00189E20.action;
    previous_frame = D_00189E20.frame;
    mask = D_00189E20.buttons;
    if ((u32)(state - 10) < 56)
        goto *D_L00_002A0640[state - 10];
    goto state_other;

state_10:
    if (D_00189E20.action_locked) goto state_other;
    if (D_00189E20.state < 2 || (D_00189E20.state == 4 && D_00189E20.grounded)) {
        if (func_L00_0032EF10(mask, 10, &input_age)) {
            object = D_00189E20.object;
            if (!object) goto clear_action;
            if (!func_L00_002B3248((unsigned char *)object) || *(unsigned char *)(object + 0x20))
                goto clear_action;
            if ((D_00138320[0] & 8) ||
                ((D_00189E20.mode == 1 || D_00189E20.mode == 29) && D_00189E20.frame >= 21)) {
                if ((D_00189E20.mode == 1 || D_00189E20.mode == 29) && D_00189E20.frame >= 21)
                    func_L00_002BA508(21);
                else
                    func_L00_002C42E0(21, 1);
            } else {
                func_L00_002C42E0(19, 1);
            }
            goto clear_action;
        }
        goto clear_action;
    }
    if (D_00189E20.mode == 7 || D_00189E20.mode == 9 || D_00189E20.mode == 137 ||
        D_00189E20.mode == 8 || D_00189E20.mode == 6 ||
        (D_00189E20.mode == 14 && D_00189E20.animation_frame > 32.0f))
        goto buffered_attack;
    if (D_00189E20.mode == 11) {
        if (D_00189E20.attack_mode != 3) {
            if (D_00189E20.animation_frame > 18.0f) goto buffered_attack;
            if (D_00189E20.attack_mode != 3) goto other_attack;
        }
        if (D_00189E20.animation_frame > 20.0f) goto buffered_attack;
    }
other_attack:
    if (D_00189E20.mode == 44 || D_00189E20.mode == 17)
        goto buffered_attack;
    goto ranged_attack;

buffered_attack:
    if (D_00189E20.frame < 11) goto ranged_attack;
    action = 14;
    if (D_00189E20.mode == 11 || D_00189E20.mode == 14)
        action = 18;
    if (!func_L00_0032EF10(mask, action, 0)) goto clear_action;
    threshold = D_00189E20.fast_attack ? 0.57f : 0.1f;
    if (D_00189E20.movement > threshold ||
        (D_00189E20.mode == 8 && D_00189E20.movement > 0.57f)) {
        if (D_00189E20.attack_blocked || D_00189E20.attack_pending) goto clear_action;
        func_L00_002C42E0(20, 1);
    } else {
        func_L00_002C42E0(19, 1);
    }
    goto clear_action;

ranged_attack:
    if (D_00189E20.state == 6) {
        range = &D_L00_0025D990[D_00189E20.animation_index];
        if (D_00189E20.mode == 21 && D_00189E20.frame >= 31) {
            if (D_00189E20.input_locked) goto clear_action;
            if (D_00189E20.attack_delay) goto clear_action;
            if ((float)range->trigger_frame <= D_00189E20.animation_frame && (D_00138320[0] & 8) &&
                func_L00_0032EF10(mask, 15, 0)) {
                func_L00_002C42E0(21, 1);
                goto state_other;
            }
        }
        if (!D_00189E20.attack_delay) {
            if (!D_00189E20.input_locked && (float)range->trigger_frame <= D_00189E20.animation_frame) {
                difference = (func_00283CF0(D_00189E20.animation_frame) - range->first_frame) * 2;
                action = 1;
                if (difference > 0) action = difference;
                if (action > 15) action = 15;
                if (func_L00_0032EF10(mask, action, 0)) {
                    if (D_00138320[0] & 8) {
                        func_L00_002C42E0(21, 1);
                        goto clear_action;
                    }
                    func_L00_002C42E0(19, 1);
                }
            }
        }
    }
clear_action:
    D_00189E20.attack_pending = 0;
    goto state_other;

state_22:
    if (D_00189E20.mode == 1 || D_00189E20.mode == 29) goto state_other;
    if (!(D_00189E20.state < 2 || D_00189E20.state == 12 ||
          (D_00189E20.state == 4 && D_00189E20.grounded))) goto state_other;
    if (D_00189E20.pending_action && D_00189E20.pending_action != 22 && D_00189E20.pending_action != 65)
        goto state_other;
    if (!(D_00138320[0] & 32) || D_00189E20.input_window < 23) goto state_other;
    if (func_L00_002D4040(state)) {
        func_L00_002C42E0(131, 1);
        goto state_other;
    }
    if (D_00138320[1] & 32)
        func_002E5DA0(0, 0, D_00189E20.owner, D_L00_00262570[D_00139568[state]].sound);
    goto state_other;

state_46:
    if (!(D_00138320[1] & mask)) goto state_other;
    if (D_00189E20.aim_target) {
        D_00189E20.aim_target = 0;
        goto state_other;
    }
    object = func_L00_002AE888(&D_00189E20, 21, 0, 20.0f, D_00189E20.heading,
                              0.5235988497734069824f, 0.6981317996978759766f);
    D_00189E20.aim_target = object;
    if (object) {
        *(Quadword *)point = *(Quadword *)(object + 16);
        point[2] += 0.5f;
        if (func_002761F8(point, (char *)&D_00189E20 + 0xE0, 2, object, 0))
            D_00189E20.aim_target = 0;
        else {
            object = D_00189E20.aim_target;
            direction = func_00283248(D_00189E20.position[0] - *(float *)(object + 16),
                                     D_00189E20.position[1] - *(float *)(object + 20));
            object = D_00189E20.aim_target;
            D_00189E20.target_angle = func_00283BE0(*(float *)(object + 0xF8), direction);
        }
    }
    goto state_other;

state_13:
    func_L00_002C3BB0();
    func_L00_002C3E18();
    func_L00_002C40C0();
    action = D_00189E20.extended_range ? 8 : 5;
    if (D_00189E20.mode == 40) action = 11;
    if (D_00189E20.mode == 39 && (D_00189E20.alternate_target_ready || D_00189E20.nearby_ready)) {
        if (func_L00_0032EF10(mask, action, 0) ||
            ((D_00138320[0] & mask) && D_00189E20.input_window >= 16)) {
            func_L00_002C42E0(40, 1);
            goto state_other;
        }
    }
    if (!(D_00189E20.state < 2 || D_00189E20.state == 12 || D_00189E20.state == 4 ||
          D_00189E20.state == 2 || D_00189E20.state == 30 || D_00189E20.state == 5 ||
          (D_00189E20.mode == 40 && D_00189E20.frame >= 6) || D_00189E20.mode == 29))
        goto state_other;
    if (!func_L00_0032EF10(mask, action, 0) &&
        (!(D_00138320[0] & mask) || D_00189E20.input_window < 16)) goto state_other;
    if (D_00189E20.alternate_target_ready) {
        if (D_00189E20.nearby_ready) {
            if (D_00189E20.alternate_distance < D_00189E20.nearby_distance) D_00189E20.nearby_ready = 0;
            else D_00189E20.alternate_target_ready = 0;
        }
        if (D_00189E20.alternate_target_ready && !D_00189E20.control_lock && D_00189E20.mode != 43) {
            func_L00_002C42E0(43, 1);
            goto state_other;
        }
    }
    if (D_00189E20.nearby_ready && !D_00189E20.control_lock) {
        func_L00_002C42E0(35, 1);
        goto state_other;
    }
    if (D_00189E20.second_target_ready) {
        func_L00_002C42E0(138, 1);
        goto state_other;
    }
    goto state_other;

state_12:
    if (!((D_00189E20.state == 0 && D_00189E20.mode != 29) || D_00189E20.state == 1 ||
          D_00189E20.state == 12 || D_00189E20.state == 5 || D_00189E20.state == 15 ||
          (D_00189E20.state == 4 && D_00189E20.alternate_ready) ||
          (D_00189E20.mode == 34 && D_00189E20.animation_frame > 55.0f))) goto state_other;
    if (D_00189E20.changing_weapon) goto state_other;
    frame_window = D_00189E20.input_window;
    action = frame_window < 7 ? frame_window : 7;
    if (!func_L00_0032EF10(mask, action, &action_age) && !(D_00138320[0] & 32)) goto state_other;
    if (frame_window < 23) goto state_other;
    if (func_L00_002D4040(-1)) {
        if (D_00189E20.state == 12 || D_00189E20.state == 0 || D_00189E20.mode == 3 ||
            (D_00189E20.state == 1 && D_00189E20.transition_progress < 0.7f)) {
            func_L00_002C42E0(34, 1);
            goto state_other;
        }
        func_L00_002AF568();
    } else if (D_00189E20.object && (D_00138320[1] & 32))
        func_002E5CF8(0, 0, D_00189E20.object);
    goto state_other;

state_53:
    if (!(D_00189E20.state < 2 || (D_00189E20.state == 4 && D_00189E20.grounded)))
        goto state_other;
    if (D_00189E20.mode != 1) {
        frame_window = D_00189E20.input_window;
        action = frame_window > 9 ? 10 : frame_window;
        if (!func_L00_0032EF10(mask, action, &detach_age)) goto state_other;
        if (D_00189E20.object) {
            func_L00_002C42E0(31, 1);
            if (D_00189E20.object) func_002E5CF8(0, 0, D_00189E20.object);
        }
    }
    goto state_other;

state_other:
    if (D_00189E20.frame == previous_frame && D_001A7B2E[0] && D_001A739C[0] == 54 &&
        D_00189E20.mode != 29 && D_00189E20.mode != 1 &&
        (D_00189E20.motion_flags & 0xffffffff00000000ULL) == 0) {
        func_00282948(&D_L00_001A7CC4);
        if (D_L00_001A7CC4 &&
            (D_00189E20.state < 2 || D_00189E20.state == 12 ||
             ((D_00189E20.state == 2 || D_00189E20.state == 4) && D_00189E20.action_ready)) &&
            (*(u64 *)D_00138320 & 0x800000008ULL) == 0x800000008ULL)
            func_L00_002C42E0(123, 1);
        if (D_00138320[1] & 8) D_L00_001A7CC4 = 30;
    }
    return D_00189E20.frame < previous_frame;
}
