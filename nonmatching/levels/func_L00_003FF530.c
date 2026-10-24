/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Reported final C / retail: 632 / 644 bytes; size equality is not a match.
 * us: 0/27 placements; 632/644 bytes.
 * us2: 0/27 placements; 632/644 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Complete632/644-byte surface-aligned fragment burst; frame0xE0 agrees. Loop counter, mixed GP/absolute materialization and wide-call scheduling differ. Eight GPRs, two floats, four tail words and explicit pointer return were audited for0032C700; its last tail word is an owner pointer.
 * Reopening condition: New ABI/CFG/allocator evidence or a measured compiler-model improvement; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Retained complete manual reconstruction; not an exact match.
 * Source profile: -O2 -G8 -ffunction-sections (suffix profile).
 * Complete632/644-byte surface-aligned fragment burst; frame0xE0 agrees. Loop counter, mixed GP/absolute materialization and wide-call scheduling differ. Eight GPRs, two floats, four tail words and explicit pointer return were audited for0032C700; its last tail word is an owner pointer.
 */
#include "common.h"
extern int func_002E5CF8(int, int, char *);
/* Observed eight GPR arguments, two FP arguments and four stack words. */
extern void *func_0032C700(float, float, void *, int, int, int, int, int, int, int, int, int, int, void *);
extern void func_002FE8D8(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern void func_002AF000(float *, float, float, float);
extern void func_00283098(void *, void *, void *);
extern char *func_L00_00409558(void *, void *, int, int);
extern void func_002FEE50(int);
extern void *D_L00_001ADB2C __attribute__((sda));
extern int D_L00_001B0C24 __attribute__((sda));

/* Build a surface-aligned frame, then launch the configured number of fragments. */

void func_L00_003FF530(char *object) {
    float basis[3][4];
    float perpendicular[4];
    float direction[4];
    char *state = *(char **)(object + 0x68);
    char *position = object + 0x10;
    char *fragment;
    float strength = 0.7f;
    float heading;
    float elevation;
    float speed;
    int i;

    func_002E5CF8(0, 0, object);
    for (i = 1; i >= 0; i--) {
        func_0032C700(strength, 20.0f, position, 1, 14, 10, 15, 10, 20, 1,
                       0, 1, 0, D_L00_001ADB2C);
        strength += 0.3f;
    }
    func_002FE8D8(position, basis[2]);
    perpendicular[0] = basis[2][2];
    perpendicular[1] = basis[2][2];
    perpendicular[2] = -(basis[2][0] + basis[2][1]);
    func_00282F20(basis[0], perpendicular, 1.0f);
    func_00282DD8(basis[1], basis[0], basis[2]);
    basis[0][3] = 0.0f;
    basis[2][3] = 0.0f;
    basis[1][3] = 0.0f;
    for (i = 0; i < D_L00_001B0C24; i++) {
        heading = func_002A7940();
        if (*(int *)(state + 0x2C) != 0) {
            elevation = func_002A7878(0.698131799697876f, 1.3089970350265503f);
            speed = func_002A7878(4.0f, 12.0f);
        } else {
            elevation = func_002A7878(0.8726646900177002f, 1.5707964897155762f);
            speed = func_002A7878(4.0f, 9.0f);
        }
        func_002AF000(direction, speed * 0.016666668f, heading, elevation);
        direction[3] = 0.0f;
        func_00283098(direction, direction, basis);
        fragment = func_L00_00409558(position, direction, i, *(int *)(state + 0x2C));
        if (fragment != 0) *(int *)(fragment + 0xB8) = *(int *)(object + 0xB8);
    }
    func_002FEE50(*(int *)(state + 0x30));
}
