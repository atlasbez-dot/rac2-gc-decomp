/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Reported final C / retail: 2804 / 2812 bytes; size equality is not a match.
 * us: 0/1 placements; 2804/2812 bytes.
 * us2: 0/1 placements; 2804/2812 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Complete combat update: 2800 then2804 bytes against2812. The0x60frame/prologue agrees; target-copy branch layout, boolean CFG, and ignored caller register setups differ. Local helpers audited: F1A88 consumes two pointers; F1BA8 consumes only the object and explicitly returns boolean; F1608 consumes only the object. Canonical FC248 and0042AB40 interfaces omit unused incoming setups. The retained8D70 selector is an integer, measured through9FCC0 to A3F10; current shared pointer declaration needs central repair before landing. Reopen with a concrete CFG hypothesis and that canonical interface repair.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */



/* Manual retained reconstruction; not an exact match.
 * Profile: -O2 -G0 -ffunction-sections -frac2-gcse-unsplit-edges.
 * Complete combat update: 2800 then2804 bytes against2812. The0x60frame/prologue agrees; target-copy branch layout, boolean CFG, and ignored caller register setups differ. Local helpers audited: F1A88 consumes two pointers; F1BA8 consumes only the object and explicitly returns boolean; F1608 consumes only the object. Canonical FC248 and0042AB40 interfaces omit unused incoming setups. The retained8D70 selector is an integer, measured through9FCC0 to A3F10; current shared pointer declaration needs central repair before landing. Reopen with a concrete CFG hypothesis and that canonical interface repair.
 * All carrying releases fail the final complete check; absent catalogue entries are not matches.
 */
#include "common.h"
extern void func_002A7750(u8 *, u8, s32);
extern int func_002A77E0(int);
extern void func_002A7470(char *, int, int, int);
extern float func_00283248(float, float);
extern s32 func_002B3868(u8 *);
typedef int ActorVectorQuad __attribute__((mode(TI)));
extern char D_00189EA0[];
extern char *D_0018C2BC;
extern void func_L02_003F1298(char *);
extern void func_L02_003F1578(char *);
extern void func_L02_003F1608(char *);
extern void func_L02_003F18E8(char *);
extern void func_L02_003F1A88(char *, char *);
extern void func_L02_003F1B70(char *);
extern int func_L02_003F1BA8(char *);
extern char *func_L02_003FC098(char *);
extern s32 func_L02_003FC0B8(char *);
extern void func_L02_003FC248(void *);
extern int func_L00_003206B8(void *, int);
extern int func_L00_0042AB40(void);
extern void func_L01_00321178(char *, char *);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern void func_L02_003F16A8(char *);
extern float func_00282E80(void *, void *);
extern float func_00283C80(float, float);
extern int func_002B3890(u8 *);
extern void *func_002B60B0(u8 *, float, float, float, float);
extern void func_002B5278(u8 *, float);
extern int func_002B4FF0(char *, float *, float);
extern int func_002B50E0(void *, void *, float);
extern float func_0029F530(char *);
/* Retail forwards this word as a one-element selector array to func_002A3F10.
 * The current shared C declaration calls it a pointer; repair that declaration
 * before this retained caller can be considered for src/. */
extern int func_002A8D70(float, float, float, void *, int, int, int, int, int);

typedef struct {
    u8 reserved_00[0x18];
    u8 enabled;
    u8 count;
    u8 kind;
    u8 reserved_1b[0x65];
    u8 payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
extern unsigned long func_002B1C20(void *, Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);

/* Update the combat actor's animation, steering and attack-state transitions. */
void func_L02_003F0798(char *object) {
    float target[4] __attribute__((aligned(16)));
    char *state;
    char *target_object;
    char *position;
    unsigned long flags;
    float heading;
    float distance;
    float angle;
    float animation_frame;
    float delta_x;
    float delta_y;
    int choice;
    unsigned char phase;

    phase = *(u8 *)(object + 0x20);
    if (phase == 1) return;
    if (object == 0) return;
    if (phase == 0xFE) return;
    if (phase == 0xFD) return;
    state = *(char **)(object + 0x68);
    func_L02_003F1298(object);
    phase = *(u8 *)(object + 0x20);
    if (phase == 1 || phase == 0xFE || phase == 0xFD) return;
    if (*(s16 *)(state + 0x4EA) == 0) {
        *(char **)(state + 0x4B0) = 0;
        if (*(u8 *)(object + 0x95) == 4) {
            func_002A7750((u8 *)object, 4, 2);
            if (func_002A77E0(2)) {
                if (*(u8 *)(object + 0x43) != 2) func_002A7470(object, 2, 0, 10);
            } else if (*(u8 *)(object + 0x43) != 3) func_002A7470(object, 3, 0, 10);
        }
    }
    target_object = *(char **)(state + 0x4B0);
    if (target_object != 0) {
        *(ActorVectorQuad *)target = *(ActorVectorQuad *)(target_object + 0x10);
        target_object = *(char **)(state + 0x4B0);
        delta_x = *(float *)(target_object + 0x10) - *(float *)(object + 0x10);
        delta_y = *(float *)(target_object + 0x14) - *(float *)(object + 0x14);
    } else {
        *(ActorVectorQuad *)target = *(ActorVectorQuad *)D_00189EA0;
        delta_x = *(float *)D_00189EA0 - *(float *)(object + 0x10);
        delta_y = *(float *)(D_00189EA0 + 4) - *(float *)(object + 0x14);
    }
    heading = func_00283248(delta_x, delta_y);
    position = object + 0x10;
    distance = func_00282E80(position, target);
    switch (*(u8 *)(object + 0x95)) {
    case 2:
        if (func_002B3890((u8 *)object)) {
            if (*(u8 *)(object + 0x43) != 11) func_002A7470(object, 11, 0, 10);
            *(u8 *)(object + 0xBC) = 0;
            func_002B60B0((u8 *)object, 0.002222222276031971f, 0.06666667014360428f,
                         0.0011635529808700085f, 0.10471977293491364f);
            func_L02_003F1A88(object, func_L02_003FC098(*(char **)(object + 0xB8)));
            *(u16 *)(object + 0x96) = 10000;
        }
        if (*(u8 *)(object + 0xBC) == 1 && *(u16 *)(object + 0x96) > 300) {
            choice = func_002A77E0(5);
            switch (choice) {
            case 0:
                if (*(u8 *)(object + 0x43) != 2) { choice = 2; goto set_idle_animation; }
                break;
            case 1:
                if (*(u8 *)(object + 0x43) != 3) { choice = 3; goto set_idle_animation; }
                break;
            case 2:
                if (*(u8 *)(object + 0x43) != 4) { choice = 4; goto set_idle_animation; }
                break;
            case 3:
                if (*(u8 *)(object + 0x43) != 6) {
                    choice = 6;
set_idle_animation:
                    func_002A7470(object, choice, 0, 10);
                }
                break;
            case 4: if (*(u8 *)(object + 0x43) != 7) func_002A7470(object, 7, 0, 10); break;
            }
            *(u16 *)(object + 0x96) = func_002A77E0(100);
        }
        if (*(s16 *)(state + 0x4EA) != 0) {
            func_002A7750((u8 *)object, 5, 4);
            if (func_002A77E0(2)) {
                if (*(u8 *)(object + 0x43) != 1) func_002A7470(object, 1, 0, 10);
            } else if (*(u8 *)(object + 0x43) != 5) func_002A7470(object, 5, 0, 10);
        }
        angle = func_00283248(target[0] - *(float *)(object + 0x10),
                             target[1] - *(float *)(object + 0x14));
        angle = func_00283C80(*(float *)(object + 0xF8), angle);
        if (angle > 2.7925272f) func_L02_003F1B70(object);
        if (*(u8 *)(object + 0xBC) != 0 || func_00282E80(position, state + 0x4A0) >= 0.5f)
            func_L01_00321178(object, state + 0x4A0);
        else *(u8 *)(object + 0xBC) = 1;
        break;
    case 5:
        flags = func_002B1C20(object, (Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state + 0x60));
        if ((*(u8 *)(object + 0x42) != 16 || func_002A77E0(30) != 0) && (flags & 1) == 0) {
            if (flags & 2) func_002A7750((u8 *)object, 7, 4);
        } else {
            func_L02_003FC248(object);
            func_L02_003F18E8(object);
        }
        break;
    }
    switch (*(u8 *)(object + 0x20)) {
    case 3:
        if (func_002B3868((u8 *)object)) {
            *(u8 *)(object + 0xBC) = 0;
            if (*(u8 *)(object + 0x43) != 2) func_002A7470(object, 2, 0, 0);
            *(int *)(state + 0x14C) = -1;
        }
        if (*(u8 *)(object + 0xBC) == 0 &&
            (long)*(s16 *)(state + 0x4F0) < (long)(unsigned long)*(u16 *)(object + 0x96)) {
            if (*(u8 *)(object + 0x43) != 11) func_002A7470(object, 11, 0, 10);
            *(u8 *)(object + 0xBC) = 1;
        } else if (*(u8 *)(object + 0xBC) == 1) {
            if (func_L00_003206B8(position, func_L02_003FC0B8(*(char **)(object + 0xB8)))) {
                func_002A7750((u8 *)object, 4, 2);
                *(int *)(state + 0x14C) = func_L00_0042AB40();
            }
            func_L01_00321178(object, func_L02_003FC098(*(char **)(object + 0xB8)));
        }
        break;
    case 5:
        if (*(u8 *)(object + 0x60) & 2) func_002A7750((u8 *)object, 7, -1);
        break;
    case 6:
        if (func_002B3868((u8 *)object)) {
            if (*(u8 *)(object + 0x43) != 10) func_002A7470(object, 10, 0, 10);
            func_002B60B0((u8 *)object, 0.004444444552063942f, 0.13333334028720856f,
                         0.006981317885220051f, 0.8377581834793091f);
        }
        func_002B5278((u8 *)object, heading);
        if (*(u8 *)(object + 0x60) & 2)
            func_002A7750((u8 *)object, *(s16 *)(state + 0x4EC), *(s16 *)(state + 0x4EE));
        break;
    case 7:
        if (func_002B3868((u8 *)object) && *(u8 *)(object + 0x43) != 11)
            func_002A7470(object, 11, 0, 15);
        if (*(u8 *)(object + 0x42) == 8 && distance > 15.0f) {
            if (*(u8 *)(object + 0x43) != 11) func_002A7470(object, 11, 0, 4);
            func_002B60B0((u8 *)object, 0.004444444552063942f, 0.13333334028720856f,
                         0.0011635529808700085f, 0.10471977293491364f);
        } else if (*(u8 *)(object + 0x42) == 11 && distance < 7.0f) {
            if (*(u8 *)(object + 0x43) != 8) func_002A7470(object, 8, 0, 4);
            func_002B60B0((u8 *)object, 0.004444444552063942f, 0.03333333507180214f,
                         0.0011635529808700085f, 0.10471977293491364f);
        }
        if (distance < 2.8f) {
            angle = func_00283C80(*(float *)(object + 0xF8),
                                 func_00283248(target[0] - *(float *)(object + 0x10),
                                               target[1] - *(float *)(object + 0x14)));
            if (0.38397247f <= angle) goto steer_toward_target;
            func_002A7750((u8 *)object, 8, -1);
            if (*(u8 *)(object + 0x43) != 12) func_002A7470(object, 12, 4, 3);
            *(int *)(state + 0x4D0) = 0;
        } else {
steer_toward_target:
            if (distance > 2.8f) {
                if (!func_L02_003F1BA8(object))
                    func_002B4FF0(object, target, *(float *)(state + 0x4B4));
            } else func_002B50E0(object, position, heading);
        }
        angle = func_00283248(target[0] - *(float *)(object + 0x10),
                             target[1] - *(float *)(object + 0x14));
        angle = func_00283C80(*(float *)(object + 0xF8), angle);
        if (angle > 2.7925272f) func_L02_003F1B70(object);
        break;
    case 8:
        if (*(u8 *)(object + 0x60) & 2) {
            *(float *)(state + 0x4CC) = 8.0f;
            if (D_0018C2BC == object) {
                func_002A7750((u8 *)object, 9, -1);
                if (*(u8 *)(object + 0x43) != 13) func_002A7470(object, 13, 0, 7);
            } else func_002A7750((u8 *)object, 7, -1);
        }
        animation_frame = func_0029F530(object);
        if (*(u8 *)(object + 0x42) == 12) {
            if (animation_frame >= 19.0f && animation_frame <= 25.0f) {
                func_002A8D70(0.35f, (float)*(u8 *)(state + 0x34), 1.0f, object, 0, 0x10001, 0, 1, 0);
                func_002A8D70(0.15f, (float)*(u8 *)(state + 0x34), 1.0f, object, 1, 0x10001, 0, 1, 0);
                func_002A8D70(0.15f, (float)*(u8 *)(state + 0x34), 1.0f, object, 2, 0x10001, 0, 1, 0);
            }
            if (*(u8 *)(object + 0x42) == 12 && animation_frame >= 17.0f && animation_frame <= 25.0f) {
                func_L00_002E6CF0((void (*)(void *))func_L02_003F16A8, object);
                func_L02_003F1608(object);
                *(float *)(state + 0x4CC) = 25.0f;
            }
        }
        func_002B50E0(object, position, heading);
        break;
    case 9:
        if (*(u8 *)(object + 0x60) & 2) func_002A7750((u8 *)object, 7, -1);
        break;
    }
    func_L02_003F1578(object);
}
