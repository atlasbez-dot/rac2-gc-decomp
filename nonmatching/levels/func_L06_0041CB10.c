/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Retained near miss: 2200/2200 bytes; US and US2 0/1, PAL absent.
   Profile: O2 G0 ffunction-sections frac2-qcopy frac2-qcopy-barrier.
   Complete readable C, canonical calls and full 16-byte vector locals. The collision
   record is only a prefix view, without an assertion about its complete extent.
   1 meaningful trials. First retail difference at +0x5c: s5/s6 allocation is
   swapped; the loop also swaps s4/s5, and its setup schedules differently.
   The state-1 height call reverses a0/a1 setup order, and the second vector copy
   uses 0(s3)->0(a1), rather than 0x10(s1)->0x10(sp). Reversing the collision
   predicate source order recovered retail block layout and exact size. Representative 3F4080 whole-union
   assignments regressed to 2200/2184, qcopy without barrier gave 2188/2184;
   an early loop-counter initialization worsened allocation. The fading successor
   is scoped separately to recover its v1 register. Reopen with independently
   supported typed owner/state layouts or original copy expansion policy.
   Callee 761F8: five GPR inputs, explicit v0 0/1; 77258: three GPR + f12,
   explicit v0 0/1. A89A8: vector,selector,f12 -> f0. A9288: owner,f12,
   return ignored and unresolved. Local replacement helper returns pointer32.
   No integrated match is claimed. */
typedef unsigned int Quadword __attribute__((mode(TI)));
typedef union { Quadword whole; float f[4]; } Vector;
/* Collision-query prefix, including the three complete result vectors. */
typedef struct { unsigned char prefix[0x18]; char *object; int polygon; Vector point, offset, normal; } CollisionView;
extern CollisionView D_L06_001BFC80;
extern void func_002829A8(unsigned char *);
extern int func_00282978(unsigned char *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00283028(void *, void *, void *);
extern float func_00282E20(void *);
extern float func_00282DF0(void *);
extern float func_00283248(float, float);
extern int func_002761F8(void *, void *, int, void *, int);
extern int func_00277258(void *, int, void *, float);
extern int func_00278E78(void);
extern float func_002A7878(float, float);
extern int func_002E5CF8(int, int, char *);
extern float func_002ABB18(float);
extern float func_002A89A8(void *, int, float);
extern void func_002A9288(char *, float);
extern char *func_L04_003EDD40(char *, Vector *);
extern void func_L06_0041CAB0(char *, char *);

/* Move a small flock member, separating it from walls and its live siblings. */
void func_L06_0041CB10(char *object)
{
    char *state = *(char **)(object + 0x68);
    Vector old_position, probe, separation;
    char *other;
    char *position;
    char **siblings;
    int i;
    float distance;
    *(unsigned int *)(object + 0x78) = 0x80808080;
    func_002829A8((unsigned char *)state + 0x1b);
    old_position.whole = ((Vector *)(object + 0x10))->whole;
    switch (*(unsigned char *)(object + 0x20)) {
    case 0:
        *(float *)(object + 0x2c) += (*(float *)(*(char **)(object + 0x24) + 0x24) - *(float *)(object + 0x2c)) * 0.05f;
        func_00282CC0(object + 0x10, object + 0x10, state);
        func_00282F20(&probe, state, 0.2f);
        func_00282CC0(&probe, &probe, object + 0x10);
        *(int *)(object + 0x98) = 0;
        *(int *)(*(char **)(state + 0x10) + 0x98) = 0;
        if (func_002761F8(&old_position, &probe, 4, object, 0)) {
            func_00282CF0(&probe, &D_L06_001BFC80.point, &probe);
            func_00282F20(&probe, &probe, 0.215f);
            func_00282CC0(object + 0x10, object + 0x10, &probe);
            if (D_L06_001BFC80.polygon >= 0) {
                func_00283028(state, state, &D_L06_001BFC80.normal);
                if (func_00283248(D_L06_001BFC80.normal.f[2], func_00282E20(&D_L06_001BFC80.normal)) < 0.69813179969787597656f && func_00278E78() == -1) {
                    func_00282D30(state, state, 0.5f);
                    if (func_00282DF0(state) < 0.025f)
                        *(unsigned char *)(object + 0x20) = 1;
                }
            } else {
                if (*(short *)(D_L06_001BFC80.object + 0xaa) != 0xb66) {
                    func_00283028(state, state, &D_L06_001BFC80.normal);
                    if (func_00283248(D_L06_001BFC80.normal.f[2], func_00282E20(&D_L06_001BFC80.normal)) < 0.69813179969787597656f && func_00278E78() == -1)
                        func_00282D30(state, state, 1.2f);
                } else {
                    *(float *)(state + 8) *= func_002A7878(0.9f, 1.1f);
                }
            }
            if (*(unsigned char *)(state + 0x1b) == 0) {
                func_002E5CF8(0, 0, object);
                *(unsigned char *)(state + 0x1b) = 12;
            }
        }
        position = object + 0x10;
        if (func_00277258(position, 4, object, 0.2f)) {
            func_00282CF0(&probe, &D_L06_001BFC80.point, &D_L06_001BFC80.offset);
            func_00282F20(&probe, &probe, 0.015f);
            func_00282CC0(position, &D_L06_001BFC80.offset, &probe);
            if (D_L06_001BFC80.object == 0) {
                func_00283028(state, state, &D_L06_001BFC80.normal);
                if (func_00283248(D_L06_001BFC80.normal.f[2], func_00282E20(&D_L06_001BFC80.normal)) < 0.69813179969787597656f && func_00278E78() == -1) {
                    func_00282D30(state, state, 0.5f);
                    if (func_00282DF0(state) < 0.025f)
                        *(unsigned char *)(object + 0x20) = 1;
                }
            } else if (*(short *)(D_L06_001BFC80.object + 0xaa) != 0xb66) {
                func_00283028(state, state, &D_L06_001BFC80.normal);
                if (func_00283248(D_L06_001BFC80.normal.f[2], func_00282E20(&D_L06_001BFC80.normal)) < 0.69813179969787597656f && func_00278E78() == -1)
                    func_00282D30(state, state, 1.2f);
            } else {
                *(float *)(state + 8) *= func_002A7878(0.9f, 1.1f);
            }
            if (*(unsigned char *)(state + 0x1b) == 0) {
                func_002E5CF8(0, 0, object);
                *(unsigned char *)(state + 0x1b) = 12;
            }
        }
        siblings = (char **)(*(char **)(*(char **)(state + 0x10) + 0x68) + 0xa0);
        for (i = 19; i >= 0; i--, siblings++) {
            other = *siblings;
            if (other != object && other != 0 && *(short *)(other + 0xaa) == 0xb66 && *(unsigned char *)(other + 0x20) != 0xfe && *(unsigned char *)(other + 0x20) != 0xfd) {
                func_00282CF0(&separation, position, other + 0x10);
                separation.f[2] = 0;
                distance = func_00282DF0(&separation);
                if (distance < 1.8f) {
                    func_00282D30(&separation, &separation, (1.8f - distance) * 0.5f);
                    func_00282CC0(position, position, &separation);
                }
            }
        }
        if (func_00282978((unsigned char *)state + 0x18))
            *(unsigned char *)(object + 0x20) = 2;
        *(float *)(object + 0xf0) = func_002ABB18(*(float *)state);
        *(float *)(object + 0xf4) = func_002ABB18(*(float *)(state + 4));
        *(int *)(object + 0x98) = *(int *)(*(char **)(object + 0x24) + 0x10);
        *(int *)(*(char **)(state + 0x10) + 0x98) = *(int *)(*(char **)(*(char **)(state + 0x10) + 0x24) + 0x10);
        *(float *)(state + 8) -= 0.0027222223579883575439f;
        *(float *)(object + 0xf0) += 0.01f;
        *(float *)(object + 0xf4) += 0.02f;
        break;
    case 1:
        *(float *)(object + 0x18) = func_002A89A8(object + 0x10, 0, 0.5f) + 0.2f;
        *(int *)(object + 0x1c) = 0;
        probe.whole = ((Vector *)(object + 0x10))->whole;
        *(char **)(state + 0x14) = func_L04_003EDD40(*(char **)(state + 0x10), &probe);
        *(unsigned char *)(object + 0x20) = 2;
        break;
    case 2: {
        char *successor;
        *(float *)(object + 0x2c) -= *(float *)(object + 0x2c) * 0.05f;
        successor = *(char **)(state + 0x14);
        if (successor != 0 && *(unsigned char *)(state + 0x1a) != 0)
            *(float *)(successor + 0x2c) += (*(float *)(*(char **)(successor + 0x24) + 0x24) - *(float *)(successor + 0x2c)) * 0.05f;
        if (*(float *)(object + 0x2c) < *(float *)(*(char **)(object + 0x24) + 0x24) * 0.05f) {
            *(float *)(object + 0x2c) = 0.0001f;
            successor = *(char **)(state + 0x14);
            if (successor == 0 || *(unsigned char *)(successor + 0x20) == 0xfe || *(unsigned char *)(successor + 0x20) == 0xfd || *(unsigned char *)(state + 0x1a) == 0 || *(float *)(successor + 0x2c) >= *(float *)(*(char **)(successor + 0x24) + 0x24) - 0.01f)
                func_L06_0041CAB0(object, state);
        }
        break;
    }
    }
    func_002A9288(object, (*(float *)(object + 0x2c) * 0.3f) / *(float *)(*(char **)(object + 0x24) + 0x24));
    if (*(float *)(object + 0x18) < 5.0f || *(float *)(object + 0x18) > 500.0f) {
        func_L06_0041CAB0(object, state);
    } else {
        if (*(float *)(object + 0x10) < 5.0f) *(float *)(object + 0x10) = 5.0f;
        if (*(float *)(object + 0x10) > 1018.0f) *(float *)(object + 0x10) = 1018.0f;
        if (*(float *)(object + 0x14) < 5.0f) *(float *)(object + 0x14) = 5.0f;
        if (*(float *)(object + 0x14) > 1018.0f) *(float *)(object + 0x14) = 1018.0f;
        if (*(float *)(object + 0x18) < 5.0f) *(float *)(object + 0x18) = 5.0f;
        if (*(float *)(object + 0x18) > 1018.0f) *(float *)(object + 0x18) = 1018.0f;
    }
}
