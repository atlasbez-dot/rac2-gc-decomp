/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching reconstruction of func_L11_0042F018 (retail 10312 bytes).
 * Current 2026-10-23 measurement: 9604 bytes, 0/1 US; US2/PAL absent.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * The frame is the expected 0x110. Allocation, conditional/tail merging,
 * mixed GP/absolute accesses and scratch-buffer lifetimes still differ.
 * Reopen only with new evidence for original declarations/layout/control
 * flow. No exact-C or linked-build credit is claimed.
 *
 * This replaces the historical eleven-pass 10020-byte draft after a full
 * semantic review. That figure is not a current controlled baseline: the
 * draft used manufactured label tables/volatile arrays, a false resident
 * anchor and undersized buffers, so it was not mechanically recompiled.
 * Both dispatches are ordinary C switches (5 selectors, 27 action slots).
 *
 * Qualified repairs: atan2 returns float and feeds both angle-difference
 * arguments; both vector scales are 2.5f; dispatch flags use the canonical
 * unsigned-long 64-bit result. The area query receives all four GPR inputs,
 * radius 1.3f and a complete aligned 48-byte request. AE8C0 receives both
 * floats (0.35f, 0.25f). Particle allocation returns its pointer; the light
 * allocator retains five FP inputs. Known smoothing returns remain float.
 * Vector temporaries are complete 16-byte objects. The eight 32-byte light
 * records follow the allocator's verified eight-slot bound. Unknown game
 * objects and path payloads remain byte-based partial views, without a
 * fabricated whole-object extent or numeric resident pointer.
 *
 * Further corrected draft errors include overwritten sine/cosine results,
 * the animation-9 predicate, selector-2's level test, path double-indirection
 * and the unconditional clear at action 17's branch delay slot. Only the
 * class field is set by the beam caller after A8C00, as in retail; no zero
 * initialization was invented for the other request bytes or vector w.
 * Side-effect ASM helper scalar-return intent remains unclaimed where no
 * uniform result is established; conventional void spellings do not prove
 * an original source return type.
 */
#include "common.h"

typedef unsigned int QuadWord __attribute__((mode(TI)));
typedef union { QuadWord word; float v[4]; } Vector;
typedef struct { int a, b, c, d; } __attribute__((aligned(16))) Quad16;
typedef struct {
    Vector impulse;
    int owner, flags;
    unsigned char enabled, kind;
    unsigned short object_class;
    float damage;
    int active;
} DamageRequest;
typedef struct { float color[3], intensity; Vector position; } LightRecord;
/* Exact partial context view of canonical 002B1C20; not a whole game object. */
typedef struct {
    unsigned char reserved_00[0x18];
    unsigned char enabled, count, kind;
    unsigned char reserved_1b[0x65];
    unsigned char payload[1];
} Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext;
typedef unsigned long Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags;
struct family_27f9_object;
#define BYTE(p, o) (*(unsigned char *)((char *)(p) + (o)))
#define HALF(p, o) (*(short *)((char *)(p) + (o)))
#define UHALF(p, o) (*(unsigned short *)((char *)(p) + (o)))
#define WORD(p, o) (*(int *)((char *)(p) + (o)))
#define REAL(p, o) (*(float *)((char *)(p) + (o)))
#define POINTER(p, o) (*(char **)((char *)(p) + (o)))
#define QUAD(p, o) (*(QuadWord *)((char *)(p) + (o)))
extern int D_L11_001CAE40;
extern int D_0018C0B4;
extern char *D_0018C0B0;
extern Vector D_00189EA0, D_00189EF0;
extern char *D_L11_001FF580[];
extern char *D_L11_001B359C __attribute__((sda));
extern char *D_L11_001B368C __attribute__((sda));
extern int D_L11_001AED04 __attribute__((sda));
extern LightRecord D_L11_001C8A40[8];
extern Vector D_L11_001C0D20, D_L11_001A8F20;
extern void func_L11_00431860(unsigned char *);
extern int func_002B3890(unsigned char *);
extern void *func_002B60B0(unsigned char *, float, float, float, float);
extern void func_L11_0042EF90(unsigned char *, unsigned int, unsigned int, unsigned int, unsigned int);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern int func_002A7820(int, int);
extern int func_002A8AF0(float *, float *, int);
extern void func_002A7470(void *, int, int, int);
extern float func_002A7878(float, float);
extern Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags func_002B1C20(void *, Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *);
extern void func_002A6C58(void *, int, int);
extern void func_L01_003E9CF8(void *, int, void (*)(void *));
extern int func_00282948(int *);
extern float func_002AA2E8(float *, float, float);
extern int func_002A77E0(int);
extern int func_002B6120(char *, char *);
extern int func_002B6228(void *, void *, int, int);
extern void func_002AE8C0(void *, void *, float, float);
extern float func_002A7E08(struct family_27f9_object *, float *, float *, float, float, float);
extern void func_L11_00432628(void *, void *);
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern void func_L01_00321178(char *, char *);
extern void func_0029FCC0(char *, int, char *);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00282D30(void *, void *, float);
extern void func_002A8C00(char *, int, int, float, Quad16 *);
extern int func_00277F48(void *, int, void *, DamageRequest *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern int func_L02_00331440(void *, void *, int, float, float, float);
extern float func_0029F530(char *);
extern char *func_002C2210(void *, int, unsigned int, int, int, void *, int, float, float, float);
extern int func_002A8D70(float, float, float, void *, void *, int, int, int, int);
extern int func_002AEB60(char *, float);
extern void func_L00_003294F0(unsigned char *, int);
extern int func_L00_002FCF18(void *, float, float, float, float, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_002B38B8(unsigned char *);
extern void func_L04_003E5830(void *, int);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern void func_L11_00431E30(unsigned char *);
extern void func_00291450(int);
extern int func_002B50E0(void *, void *, float);
extern void func_L11_00431D50(unsigned char *);
extern void func_0029F338(void *);

void func_L11_0042F018(unsigned char *object)
{
    Vector point, side, normal, scaled, particle, point2;
    DamageRequest request;
    char *state, *linked, *path, *position;
    LightRecord *light;
    int index, spin, selected;
    float angle, distance, elapsed, strength, amplitude, damage;
    Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchFlags flags;

    if (D_L11_001CAE40 != 0 || D_0018C0B4 == 0x6f) {
        BYTE(object, 0xbc) = 1;
        WORD(object, 0x98) = 0;
        UHALF(object, 0x34) = (UHALF(object, 0x34) & 0xefff) | 0x41;
        return;
    }
    if (BYTE(object, 0xbc) != 0) {
        UHALF(object, 0x34) = (UHALF(object, 0x34) & 0xffbe) | 0x1000;
        WORD(object, 0x98) = WORD(POINTER(object, 0x24), 0x10);
        BYTE(object, 0xbc) = 0;
    }
    state = POINTER(object, 0x68);
    position = (char *)object + 0x10;
    func_L11_00431860(object);
    switch (BYTE(object, 0x95)) {
    case 0:
        if (func_002B3890(object) != 0) {
            func_002B60B0(object, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
            if (REAL(state, 0x290) < 0.2f) func_L11_0042EF90(object, 0, 0, 0, 12);
            if (WORD(state, 0x29c) != -1) {
                func_L11_0042EF90(object, 5, 4, 0, 12);
                func_002A7750(object, 5, -1);
            }
        }
        if (HALF(state, 0x274) == 2 && D_0018C0B4 != 0x6f && WORD(state, 0x2c8) == 0) {
            if (WORD(state, 0x294) != -1) goto begin_run;
            if (POINTER(state, 0x27c) == 0) func_L11_0042EF90(object, 2, 2, 0, 10);
            func_002A7750(object, 14, 2);
        } else if (HALF(state, 0x276) != 0) {
            func_002A7750(object, 11, 1);
            HALF(state, 0x276) = 0;
            if (HALF(state, 0x270) < 300) HALF(state, 0x270) = func_002A7820(480, 600);
            if (WORD(state, 0x29c) != -1) {
                func_002A7750(object, 11, 12);
                func_L11_0042EF90(object, 4, 3, 0, 12);
            }
        } else if (WORD(state, 0x2ac) != -1) {
            path = D_L11_001FF580[WORD(state, 0x2ac)];
            if (func_002A8AF0(D_00189EA0.v, (float *)(path + 0x10), WORD(path, 0)) != 0) {
            begin_run:
                func_L11_0042EF90(object, 6, 5, 0, 10);
                func_002B60B0(object, 0.016666667f, 0.5f, 0.001163553f, 0.10471977f);
                REAL(state, 0x164) = 0.0055555557f;
                func_002A7750(object, 17, 2);
            }
        }
        break;
    case 1:
        if (func_002B3890(object) != 0)
            func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
        if ((unsigned int)(UHALF(state, 0x274) - 1) < 2) {
            if (POINTER(state, 0x27c) == 0) {
                if (WORD(state, 0x294) != -1) goto begin_run;
                func_L11_0042EF90(object, 2, 2, 0, 10);
            }
            func_002A7750(object, 14, 2);
        } else if (HALF(state, 0x270) == 0) {
            func_002A7750(object, 1, 0);
            func_L11_0042EF90(object, 5, 4, 0, 12);
        }
        break;
    case 2:
        if (func_002B3890(object) != 0)
            func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
        if (WORD(state, 0x2ac) != -1) {
            path = D_L11_001FF580[WORD(state, 0x2ac)];
            if (func_002A8AF0(D_00189EA0.v, (float *)(path + 0x10), WORD(path, 0)) != 0) break;
        }
        if ((unsigned int)(UHALF(state, 0x274) - 1) > 1 && BYTE(object, 0x20) != 17 &&
            BYTE(object, 0x20) != 20 && BYTE(object, 0x20) != 16) {
            if (BYTE(object, 0x20) == 19) {
                func_L11_0042EF90(object, 8, 0, 1, 3);
                func_002A7750(object, 20, -1);
            } else if (WORD(state, 0x29c) != -1 && WORD(state, 0x294) == -1) {
                func_L11_0042EF90(object, 5, 4, 0, 12);
                func_002A7750(object, 5, 1);
            } else {
                WORD(state, 0x2a0) = 0;
                func_L11_0042EF90(object, 3, 1, 0, 12);
                func_002A7750(object, 11, 1);
                if (WORD(state, 0x2a4) != -1) {
                    QUAD(state, 0x110) = QUAD(D_L11_001B368C + WORD(state, 0x2a4) * 0x80, 0x30);
                    if (REAL(state, 0x12c) == 0.0f) REAL(state, 0x12c) = 4.0f;
                }
                HALF(state, 0x270) = func_002A7820(1200, 1300);
            }
        }
        if (D_0018C0B4 == 0x31 && WORD(state, 0x2c4) != -1) {
            if (BYTE(object, 0x43) != 6) func_002A7470(object, 6, 0, func_002A7820(5, 15));
            func_002A7750(object, 13, 4);
            func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.0033936962f, 0.26179942f);
        }
        if (WORD(state, 0x2bc) != -1 && HALF(state, 0x274) != 2 && POINTER(state, 0x27c) != 0 &&
            BYTE(D_L11_001B359C + WORD(state, 0x2bc) * 0x100, 0x20) != 2) {
            func_002A7750(object, 2, 0);
            func_L11_0042EF90(object, 4, 1, 0, 15);
            REAL(object, 0x48) = func_002A7878(0.5f, 1.25f);
        }
        break;
    case 3:
        flags = func_002B1C20(object, (Rac2Native_bf55aa2a4d0dd351_SDataCallDispatchContext *)(state + 0x60));
        if ((flags & 1) != 0) {
            --D_L11_001AED04;
            func_002A6C58(object, 0, 3);
            func_L01_003E9CF8(object, 0, 0);
            return;
        }
        if ((flags & 2) != 0) {
            if ((unsigned int)(UHALF(state, 0x274) - 1) < 2) {
                func_L11_0042EF90(object, 6, 5, 0, 10);
                func_002A7750(object, 15, 2);
                if (WORD(state, 0x2bc) != -1) {
                    func_002A7750(object, 24, -1);
                    func_L11_0042EF90(object, 15, 4, 0, 10);
                }
            } else {
                func_002A7750(object, 11, 1);
                func_L11_0042EF90(object, 1, 1, 0, 10);
                HALF(state, 0x270) = func_002A7820(580, 600);
                if (WORD(state, 0x29c) != -1) {
                    func_002A7750(object, 11, 12);
                    func_L11_0042EF90(object, 4, 3, 0, 12);
                }
            }
        }
        break;
    case 4:
        if (D_0018C0B4 != 0x31) {
            if (BYTE(object, 0x43) != 6) func_002A7470(object, 6, 0, 10);
            func_002A7750(object, 15, 2);
        }
        break;
    default:
        break;
    }
    switch (BYTE(object, 0x20)) {
    case 1:
        if (REAL(state, 0x290) > 0.2f) {
            func_00282948((int *)(state + 0x28c));
            if (WORD(state, 0x28c) < 21) func_002AA2E8((float *)(state + 0x124), 0.0f, 0.0011111111f);
            else REAL(state, 0x124) = 0.06666667f;
            if (BYTE(object, 0x43) == 5) {
                if (WORD(state, 0x28c) == 0) {
                    func_L11_0042EF90(object, 1, 1, 0, 12);
                    if (func_002A77E0(2) == 1) func_L11_0042EF90(object, 0, 0, 0, 12);
                }
                func_002AE8C0(object, state + 0x110, 0.35f, 0.25f);
            } else if (BYTE(object, 0x43) <= 1 && (BYTE(object, 0x60) & 2) != 0) {
                WORD(state, 0x28c) = func_002A7820(120, 700);
                func_L11_0042EF90(object, 5, 4, 0, 12);
            }
        } else if (POINTER(state, 0x27c) != 0 && BYTE(POINTER(state, 0x27c), 0x43) != 0) {
            func_L11_0042EF90(object, 0, 0, 0, 12);
        }
        break;
    case 2:
        if (BYTE(D_L11_001B359C + WORD(state, 0x2bc) * 0x100, 0x20) == 2 && POINTER(state, 0x27c) != 0) {
            func_002A7750(object, 3, -1);
            func_002A7470(POINTER(state, 0x27c), 11, 0, 15);
        }
        break;
    case 3:
        linked = POINTER(state, 0x27c);
        if ((BYTE(linked, 0x60) & 2) != 0 || linked == 0) func_002A7750(object, 14, 2);
        break;
    case 5:
    case 6:
        selected = BYTE(object, 0x20);
        if (WORD(state, 0x29c) != -1 && func_002B6120((char *)object, D_L11_001FF580[WORD(state, 0x29c)]) != 0) {
            func_002A7750(object, 7, -1);
            func_L11_0042EF90(object, 4, 3, 0, 10);
            func_002B6228(object, D_L11_001FF580[WORD(state, 0x29c)], selected == 5 ? 0 : 1, selected == 5 ? 1 : 0);
            WORD(state, 0x2c0) = selected == 5 ? 1 : 0;
        }
        break;
    case 7:
        if ((BYTE(object, 0x60) & 2) != 0) {
            func_L11_0042EF90(object, 14, 10, 0, 7);
            func_002A7750(object, 25, -1);
        }
        break;
    case 11:
        func_00282948((int *)(state + 0x28c));
        if (WORD(state, 0x28c) < 21) func_002AA2E8((float *)(state + 0x124), 0.0f, 0.0019444445f);
        else func_002AA2E8((float *)(state + 0x124), 0.06666667f, 0.0019444445f);
        if (BYTE(object, 0x43) == 6) {
            if (WORD(state, 0x28c) == 0) {
                func_L11_0042EF90(object, 3, 2, 0, 12);
                if (func_002A77E0(2) == 1) func_L11_0042EF90(object, 4, 3, 0, 12);
            }
            func_002AE8C0(object, state + 0x110, 0.35f, 0.25f);
        } else if ((unsigned char)(BYTE(object, 0x43) - 3) <= 1 && (BYTE(object, 0x60) & 2) != 0) {
            WORD(state, 0x28c) = func_002A7820(120, 700);
            func_L11_0042EF90(object, 6, 5, 0, 12);
        }
        break;
    case 12:
        if ((BYTE(object, 0x60) & 2) != 0) {
            func_L11_0042EF90(object, 5, 4, 0, 12);
            func_002A7750(object, 5, -1);
        }
        break;
    case 13:
        func_002B6120((char *)object, D_L11_001FF580[WORD(state, 0x2c4)]);
        break;
    case 14:
        func_002A7E08((struct family_27f9_object *)object, (float *)D_0018C0B0, (float *)(state + 0x284), 0.001f, 0.01f, 0.1f);
        if (POINTER(state, 0x27c) != 0) {
            func_002A7750(object, 24, -1);
            func_L11_0042EF90(object, 15, 4, 0, 10);
        } else if (WORD(state, 0x2a8) != 0) {
            func_002A7750(object, 19, -1);
            func_L11_0042EF90(object, 7, 5, 0, 10);
        } else goto route_unmounted;
        break;
    case 15:
        func_L11_00432628(object, &D_00189EA0);
        ++WORD(state, 0x280);
        if (POINTER(state, 0x27c) == 0) {
            if (func_00282E80(position, &D_00189EA0) < 2.7f) {
                angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
                if (func_00283C80(REAL(object, 0xf8), angle) < 0.3490659f) {
                    func_L11_0042EF90(object, 12, 0, 0, 5);
                    func_002A7750(object, 21, -1);
                }
            }
            distance = func_00282E80(position, &D_00189EA0);
            if (!(distance <= 2.7f) && (BYTE(object, 0x42) == 5 || BYTE(object, 0x42) == 15)) {
                func_L11_0042EF90(object, 6, 5, 0, 4);
                func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
            }
        } else if (!(20.0f <= func_00282E80(position, &D_00189EA0))) {
            angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
            if (!(0.17453295f <= func_00283C80(REAL(object, 0xf8), angle))) {
                func_L11_0042EF90(object, 9, 6, 0, 10);
                func_002A7750(object, 18, -1);
            }
        }
        break;
    case 16:
        if ((BYTE(object, 0x60) & 2) == 0) break;
    choose_motion:
        REAL(state, 0x164) = 0.00083333335f;
        if (POINTER(state, 0x27c) == 0) {
            func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
            func_L11_0042EF90(object, 6, 5, 0, 10);
            func_002A7750(object, 15, -1);
        } else {
            func_002B60B0(object, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
            func_L11_0042EF90(object, 9, 6, 0, 10);
            func_002A7750(object, 18, -1);
        }
        break;
    case 17:
        func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
        if (func_002B6120((char *)object, D_L11_001FF580[WORD(state, 0x294)]) != 0) {
            func_002A7750(object, 24, -1);
            func_L11_0042EF90(object, 15, 4, 0, 10);
            func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
            REAL(state, 0x164) = 0.00083333335f;
            WORD(state, 0x2ac) = -1;
            WORD(state, 0x294) = -1;
            if (POINTER(state, 0x27c) == 0) func_002A7750(object, 14, 2);
        }
        break;
    case 18:
        if (POINTER(state, 0x27c) != 0 && BYTE(object, 0x42) == 9) {
            linked = POINTER(POINTER(state, 0x27c), 0x68);
            func_0029FCC0(POINTER(linked, 0x278), 0, (char *)&point);
            side.v[0] = func_00283180(REAL(object, 0xf8)) * 0.1f;
            side.v[1] = func_00283198(REAL(object, 0xf8)) * 0.1f;
            side.v[2] = 0.0f;
            func_00282CC0(&point, &point, &side);
            point.v[2] -= 0.05f;
            elapsed = func_0029F530((char *)object);
            amplitude = func_002A7878(0.2f, 0.9f) * 0.2f * elapsed;
            spin = func_002A77E0(2);
            if (spin == 0) --spin;
            func_002C2210(&point, 2, 0x804020ffU, 0, spin, &D_L11_001A8F20, 0, amplitude * 0.3f, amplitude, 0.0f);
            func_002C2210(&point, 2, 0x7f6f6fffU, 1, -spin, &D_L11_001A8F20, 0, amplitude * 0.04f, amplitude * 0.4f, 0.0f);
            REAL(state, 0x288) = elapsed;
        }
        if ((BYTE(object, 0x60) & 2) != 0) {
            func_L11_0042EF90(object, 10, 7, 0, 10);
            func_002A7750(object, 22, -1);
        }
        break;
    case 19:
        REAL(state, 0x164) = 0.0069444445f;
        func_002B60B0(object, 0.006666667f, 0.20000002f, 0.001163553f, 0.10471977f);
        func_L01_00321178((char *)object, (char *)&D_00189EA0);
        func_002A7E08((struct family_27f9_object *)object, (float *)D_0018C0B0, (float *)(state + 0x284), 0.001f, 0.01f, 0.1f);
        ++WORD(state, 0x280);
        if (func_00282E80(position, &D_00189EA0) < 2.1f) {
            func_L11_0042EF90(object, 8, 0, 1, 3);
            REAL(object, 0x48) = 1.0f;
            func_002A7750(object, 20, -1);
        }
        func_0029FCC0((char *)object, 1, (char *)&point);
        normal.v[0] = func_00283180(REAL(object, 0xf8));
        normal.v[1] = func_00283198(REAL(object, 0xf8));
        normal.v[2] = 2.0f;
        scaled.word = normal.word;
        func_00282D30(&scaled, &scaled, 2.5f);
        scaled.v[3] = 5627.9248f;
        func_002A8C00((char *)&request, (int)object, 0x10001, REAL(state, 0x2b8), (Quad16 *)&scaled);
        request.enabled = 0;
        request.kind = 1;
        request.object_class = UHALF(object, 0xaa);
        func_00277F48(&point, 0, object, &request, 1.3f);
        break;
    case 20:
        func_002B60B0(object, 0.004166667f, 0.033333335f, 0.001163553f, 0.10471977f);
        point.v[0] = func_00283180(REAL(object, 0xf8)) * 4.0f;
        point.v[1] = func_00283198(REAL(object, 0xf8)) * 4.0f;
        point.v[2] = 0.0f;
        func_00282CC0(&point, position, &point);
        func_L01_00321178((char *)object, (char *)&D_00189EA0);
        ++WORD(state, 0x280);
        if ((BYTE(object, 0x60) & 2) != 0) {
            func_L11_0042EF90(object, 2, 2, 0, 10);
            func_002A7750(object, 16, -1);
            if (func_00282E80(position, &D_00189EA0) < 3.0f) {
                func_002B60B0(object, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
                if (BYTE(object, 0x43) != 16) func_002A7470(object, 16, 0, 10);
                func_002A7750(object, 27, -1);
            }
        }
        func_0029FCC0((char *)object, 1, (char *)&point2);
        normal.v[0] = func_00283180(REAL(object, 0xf8));
        normal.v[1] = func_00283198(REAL(object, 0xf8));
        normal.v[2] = 2.0f;
        scaled.word = normal.word;
        func_00282D30(&scaled, &scaled, 2.5f);
        scaled.v[3] = 5627.9248f;
        func_002A8C00((char *)&request, (int)object, 0x10001, REAL(state, 0x2b8), (Quad16 *)&scaled);
        request.enabled = 0;
        request.kind = 1;
        request.object_class = UHALF(object, 0xaa);
        func_00277F48(&point2, 0, object, &request, 1.3f);
        break;
    case 21:
        elapsed = func_0029F530((char *)object);
        if (BYTE(object, 0x42) == 12 && elapsed >= 10.0f && elapsed <= 15.0f)
            func_002A8D70(1.0f, REAL(state, 0x2b4), 1.0f, object, (void *)1, 1, 0, 1, 0);
        if ((BYTE(object, 0x60) & 2) == 0) break;
        if (func_00282E80(position, &D_00189EA0) < 2.7f) {
            angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
            if (func_00283C80(REAL(object, 0xf8), angle) < 0.3490659f) {
                func_L11_0042EF90(object, 12, 0, 0, 10);
                func_002A7750(object, 21, -1);
                break;
            }
        }
        func_002A7750(object, 15, -1);
        func_L11_0042EF90(object, 6, 5, 0, 10);
        func_002B60B0(object, 0.0033333334f, 0.10000001f, 0.001163553f, 0.10471977f);
        break;
    case 22:
        if (POINTER(state, 0x27c) == 0) {
            func_002A7750(object, 15, -1);
            func_L11_0042EF90(object, 6, 5, 0, 10);
        }
        if ((BYTE(object, 0x60) & 2) == 0) {
            if (func_002AEB60((char *)object, 3.0f) != 0 && POINTER(state, 0x27c) != 0) {
                angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
                distance = func_00283C80(REAL(object, 0xf8), angle);
                linked = POINTER(POINTER(state, 0x27c), 0x68);
                func_0029FCC0(POINTER(linked, 0x278), 0, (char *)&point);
                side.v[0] = func_00283180(REAL(object, 0xf8)) * 0.1f;
                side.v[1] = func_00283198(REAL(object, 0xf8)) * 0.1f;
                side.v[2] = 0.0f;
                func_00282CC0(&point, &point, &side);
                point.v[2] -= 0.05f;
                QUAD(state, 0x230) = point.word;
                if (distance < 0.78539824f) {
                    func_00282CF0(state + 0x250, &D_00189EF0, &point);
                } else {
                    side.v[0] = func_00283180(REAL(object, 0xf8)) * 25.0f;
                    side.v[1] = func_00283198(REAL(object, 0xf8)) * 25.0f;
                    side.v[2] = 0.0f;
                    func_00282CC0(&side, &side, position);
                    func_00282CF0(state + 0x250, &side, &point);
                }
                REAL(state, 0x298) = 0.0f;
                func_L00_003294F0(object, 0);
                index = func_L00_002FCF18(position, 5.0f, 0.0f, 1.0f, 0.0f, 0.0f);
                WORD(state, 0x2b0) = index;
                if (index >= 0) {
                    light = &D_L11_001C8A40[index];
                    light->position.word = QUAD(state, 0x230);
                    light->intensity = 0.0f;
                    light->position.v[3] = 5.0f;
                    light->color[0] = 1.0f;
                    light->color[1] = 0.0f;
                    light->position.v[2] += 1.0f;
                    light->color[2] = 0.0f;
                }
            }
        } else {
            distance = func_00282E80(position, &D_00189EA0);
            if (!(25.0f <= distance || POINTER(state, 0x27c) == 0 || WORD(state, 0x2a0) > 2)) {
                angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
                if (func_00283C80(REAL(object, 0xf8), angle) > 0.087266475f) {
                    func_002A7750(object, 24, -1);
                    func_L11_0042EF90(object, 15, 4, 0, 10);
                } else {
                    func_L11_0042EF90(object, 9, 6, 0, 10);
                    func_002A7750(object, 18, -1);
                }
            } else {
                distance = func_00282E80(position, &D_00189EA0);
                if (distance <= 10.0f || POINTER(state, 0x27c) == 0 || WORD(state, 0x2a0) < 3 || WORD(state, 0x2bc) != -1) {
                    func_002A7750(object, 24, -1);
                    func_L11_0042EF90(object, 15, 4, 0, 10);
                } else {
                    func_L11_0042EF90(object, 3, 2, 0, 10);
                    func_002A7750(object, 23, -1);
                    WORD(state, 0x2a0) = 0;
                }
            }
            if (POINTER(state, 0x27c) == 0) goto route_unmounted;
            ++WORD(state, 0x2a0);
        }
        elapsed = func_0029F530((char *)object);
        if (!(elapsed >= 3.0f && BYTE(object, 0x42) == 10) && POINTER(state, 0x27c) != 0) {
            linked = POINTER(POINTER(state, 0x27c), 0x68);
            func_0029FCC0(POINTER(linked, 0x278), 0, (char *)&point);
            side.v[0] = func_00283180(REAL(object, 0xf8)) * 0.1f;
            side.v[1] = func_00283198(REAL(object, 0xf8)) * 0.1f;
            side.v[2] = 0.0f;
            func_00282CC0(&point, &point, &side);
            point.v[2] -= 0.05f;
            amplitude = func_002A7878(0.2f, 0.9f) * 0.2f * REAL(state, 0x288);
            spin = func_002A77E0(2);
            if (spin == 0) --spin;
            func_002C2210(&point, 2, 0x804020ffU, 0, spin, &D_L11_001A8F20, 0, amplitude * 0.3f, amplitude, 0.0f);
            func_002C2210(&point, 2, 0x7f6f6fffU, 1, -spin, &D_L11_001A8F20, 0, amplitude * 0.04f, amplitude * 0.4f, 0.0f);
            REAL(state, 0x288) += 1.0f;
        }
        damage = (float)BYTE(state, 0x35);
        if (elapsed >= 3.0f && elapsed < 9.0f && BYTE(object, 0x42) == 10) {
            REAL(state, 0x298) += 1.0f;
            func_00282F20(state + 0x240, state + 0x250, REAL(state, 0x298));
            func_002A8C00((char *)&request, (int)object, 1, damage, (Quad16 *)(state + 0x240));
            request.object_class = UHALF(object, 0xaa);
            func_00282CC0(state + 0x240, state + 0x230, state + 0x240);
            if (func_002761F8(state + 0x230, state + 0x240, 0, object, &request) != 0) {
                QUAD(state, 0x240) = D_L11_001C0D20.word;
                if (func_002B38B8(object) == 0) {
                    func_L04_003E5830(&D_L11_001C0D20, 6);
                    func_L00_003294F0(object, 1);
                }
            }
            strength = func_002A7878(1.0f, 6.0f);
            spin = func_002A7820(25, 35);
            if (spin == 0) --spin;
            particle.word = QUAD(state, 0x240);
            particle.v[2] -= 0.1f;
            func_002C2210(&particle, 25, 0xff000080U, 0, spin, &D_L11_001A8F20, 0, strength * 0.3f, strength, 0.0f);
            spin = -spin;
            func_002C2210(&particle, 5, 0x7f6f6fffU, 1, spin, &D_L11_001A8F20, 0, strength * 0.04f, strength * 0.4f, 0.0f);
            func_002C2210(&particle, 20, 0xff4080ffU, 1, spin, &D_L11_001A8F20, 0, strength * 0.4f, strength * 0.2f, 0.0f);
            func_002C2210(state + 0x230, 10, 0x80ca00cbU, 0, spin, &D_L11_001A8F20, 0, strength * 0.3f, strength, 0.0f);
            func_002C2210(state + 0x230, 10, 0x7f6f6fffU, 1, -spin, &D_L11_001A8F20, 0, strength * 0.04f, strength * 0.4f, 0.0f);
            func_L00_002E6CF0((void (*)(void *))func_L11_00431E30, object);
            if (WORD(state, 0x2b0) >= 0) {
                light = &D_L11_001C8A40[WORD(state, 0x2b0)];
                light->position.word = QUAD(state, 0x240);
                light->intensity = 0.0f;
                light->position.v[3] = 5.0f;
                light->color[0] = 1.0f;
                light->position.v[2] += 1.0f;
                light->color[1] = 0.0f;
                light->color[2] = 0.0f;
            }
        }
        if (elapsed >= 9.0f && elapsed < 15.0f && BYTE(object, 0x42) == 10) {
            if (!(1.6666667f < func_00282E80(state + 0x230, state + 0x240))) goto release_light;
            REAL(state, 0x298) += 1.0f;
            func_00282F20(state + 0x240, state + 0x250, REAL(state, 0x298));
            func_002A8C00((char *)&request, (int)object, 1, damage, (Quad16 *)(state + 0x240));
            request.object_class = UHALF(object, 0xaa);
            func_00282CC0(state + 0x240, state + 0x230, state + 0x240);
            if (func_002761F8(state + 0x230, state + 0x240, 0, object, &request) != 0) {
                QUAD(state, 0x240) = D_L11_001C0D20.word;
                if (func_002B38B8(object) == 0) {
                    func_L04_003E5830(&D_L11_001C0D20, 6);
                    func_L00_003294F0(object, 1);
                }
            }
            func_00282F20(&normal, state + 0x250, 1.6666667f);
            func_00282CC0(state + 0x230, state + 0x230, &normal);
            strength = func_002A7878(1.0f, 6.0f);
            spin = func_002A7820(25, 35);
            if (spin == 0) --spin;
            particle.word = QUAD(state, 0x240);
            particle.v[2] -= 0.1f;
            func_002C2210(&particle, 25, 0xff000080U, 0, spin, &D_L11_001A8F20, 0, strength * 0.3f, strength, 0.0f);
            func_002C2210(&particle, 5, 0x7f6f6fffU, 1, -spin, &D_L11_001A8F20, 0, strength * 0.04f, strength * 0.4f, 0.0f);
            func_002C2210(&particle, 20, 0xff4080ffU, 1, -spin, &D_L11_001A8F20, 0, strength * 0.4f, strength * 0.2f, 0.0f);
            func_L00_002E6CF0((void (*)(void *))func_L11_00431E30, object);
            if (WORD(state, 0x2b0) >= 0) {
                light = &D_L11_001C8A40[WORD(state, 0x2b0)];
                light->position.word = QUAD(state, 0x240);
                light->intensity = 0.0f;
                light->position.v[3] = 5.0f;
                light->color[0] = 1.0f;
                light->position.v[2] += 1.0f;
                light->color[1] = 0.0f;
                light->color[2] = 0.0f;
            }
            break;
        }
        if (elapsed > 15.0f && BYTE(object, 0x42) == 10) {
        release_light:
            if (WORD(state, 0x2b0) >= 0) {
                func_00291450(WORD(state, 0x2b0));
                WORD(state, 0x2b0) = -1;
            }
        }
        break;
    case 23:
        if ((BYTE(object, 0x60) & 2) != 0) {
            if (func_00282E80(position, &D_00189EA0) >= 25.0f || POINTER(state, 0x27c) == 0) goto route_unmounted;
            func_002A7750(object, 24, -1);
            func_L11_0042EF90(object, 5, 4, 0, 10);
        } else if (!(6.0f <= func_00282E80(position, &D_00189EA0))) {
            func_L11_0042EF90(object, 9, 6, 0, 10);
            func_002A7750(object, 18, -1);
        }
        break;
    case 24:
        angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
        if (func_00283C80(REAL(object, 0xf8), angle) > 0.087266475f) {
            angle = func_00283248(D_00189EA0.v[0] - REAL(object, 0x10), D_00189EA0.v[1] - REAL(object, 0x14));
            func_002B50E0(object, position, angle);
        } else {
            func_L11_0042EF90(object, 9, 6, 0, 10);
            func_002A7750(object, 18, -1);
        }
        break;
    case 25:
        if ((BYTE(object, 0x60) & 2) == 0) {
            if (BYTE(object, 0x43) == 14) {
                func_002B60B0(object, 0.13333334f, 0.06666667f, 0.009696275f, 0.6981318f);
                func_002B6120((char *)object, D_L11_001FF580[WORD(state, 0x29c)]);
            }
        } else {
            func_L11_0042EF90(object, 5, 4, 0, 0);
            func_002A7750(object, WORD(state, 0x2c0) == 0 ? 5 : 6, -1);
        }
        break;
    case 27:
        func_002B60B0(object, 0.0011111111f, 0.033333335f, 0.001163553f, 0.10471977f);
        func_00282F20(&point, object + 0xc0, -5.5f);
        func_00282CC0(&point, &point, position);
        angle = func_00283248(point.v[0] - REAL(object, 0x10), point.v[1] - REAL(object, 0x14));
        func_L02_00331440(object, &point, 16, angle, -1.0f, -1.0f);
        if (UHALF(object, 0x96) >= 121) goto choose_motion;
        break;
    default:
        break;
    }
finish_update:
    func_L11_00431D50(object);
    if (REAL(object, 0x18) < 74.0f) {
        func_002A6C58(object, 0, 3);
        --D_L11_001AED04;
        func_0029F338(object);
    }
    return;
    /* Shared transition used by several actions when the mount is absent. */
route_unmounted:
    func_002A7750(object, 15, -1);
    func_L11_0042EF90(object, 6, 5, 0, 10);
    goto finish_update;
}

/* Historical analysis from the previous near miss is summarized below. Short
 * annotations describe that older source, not the corrected body above. The
 * complete source and instruction map remain private. */

/* Historical analysis (summary).
 * Historical manual analysis recorded an eleven-pass draft at 10020/10312 bytes, with no
 * matching placement. That draft was not a valid controlled baseline: it used artificial
 * label-retention tables, a numeric resident anchor and undersized buffers. Useful findings
 * included nested state guards, a shared probe tail, unconditional timer stores, signed failure
 * checks and complete helper inputs. The current manually corrected reconstruction and its own
 * 9604/10312 measurement are documented above. Earlier source and detailed instruction listings
 * remain private; no old instruction-map correspondence is attributed to the corrected body.
 */

/* The base of the block at 0x183CC0: the catalogue has no symbol for it (the
   boot's symbols jump from D_00188714 to D_00189E00), so it is spelled as the
   difference from D_00189EA0, which is how the retail computes it. */

/* The object's per-frame update: a latch test, a five-way dispatch on the byte at 0x95
   and a twenty-seven-way dispatch on the byte at 0x20. */

/* The latch and the "not armed yet" flag both lead to the arming block; the
       re-arm block falls through into the update. */

/* 0x430908: the "case 22" block: the latch on the other object, the 0x60 flag,
       the two distance windows, the two effect vectors and the timer window. */

/* 0x430AF0: the flag is not set: the other object builds the effect. */

/* 0x430B58: the small angle: one vector, then the record. */

/* 0x430C70: the wide angle: two vectors, no record. */

/* 0x430DC8: the timer of the other object. */

/* 0x430E08: the 0.2f/0.9f effect. */

/* 0x430F60 */

/* 0x430F6C */

/* 0x430F84: the window below 9.0f */

/* 0x430FA8: the 3.0f .. 9.0f window */

/* 0x431260: the 9.0f .. 15.0f window. */

/* 0x4312D4: the 9.0f .. 15.0f window */

/* 0x431544: the 15.0f test */

/* 0x43156C: the effect is released. */
