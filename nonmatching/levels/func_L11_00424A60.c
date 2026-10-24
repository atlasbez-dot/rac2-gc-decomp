/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 absent from catalogue; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Nonmatching reconstruction of func_L11_00424A60 (retail 3364 bytes).
 * Measured 2026-10-23: 3364 bytes, 0/1 US; absent in US2 and PAL catalogues.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * A later position-pointer form was 3372 bytes. The final source keeps real
 * pointer/float returns and the seven-input canonical002B3670 interface.
 * Retail frame 0x50 versus 0x70 generated: saved GPR/FPR allocation, constant
 * lifetimes and mixed absolute/GP accesses to the same globals remain.
 * Reopen with original local declarations/alias evidence; no false scalar
 * extents or aliases were introduced. No exact or linked credit claimed.
 */
#include "common.h"

typedef unsigned int QuadWord __attribute__((mode(TI)));
typedef union { QuadWord word; float v[4]; } Vector;
#define BYTE(p, o) (*(unsigned char *)((char *)(p) + (o)))
#define SIGNED_BYTE(p, o) (*(signed char *)((char *)(p) + (o)))
#define HALF(p, o) (*(short *)((char *)(p) + (o)))
#define UHALF(p, o) (*(unsigned short *)((char *)(p) + (o)))
#define WORD(p, o) (*(int *)((char *)(p) + (o)))
#define REAL(p, o) (*(float *)((char *)(p) + (o)))
#define POINTER(p, o) (*(char **)((char *)(p) + (o)))
#define QUAD(p, o) (*(QuadWord *)((char *)(p) + (o)))

extern int D_L11_001AED04;
extern int D_L11_001AED00 __attribute__((sda));
extern int D_L11_001B30C8 __attribute__((sda));
extern int D_L11_001B359C;
extern int D_L11_001B35B8;
extern unsigned short *D_L11_001FC420[];
extern Vector D_L11_001BA8C0;
extern char D_L11_001B0FD8[], D_L11_002BACF0[];
extern float func_002A89A8(void *, int, float);
extern int func_00283CF0(float);
extern int func_L02_0032E508(void *, int, void *, int);
extern void func_0026FEB8(const char *, ...);
extern float func_002A78D8(float, float);
extern int func_002A77E0(int);
extern void func_L00_003294F0(unsigned char *, int);
extern void *func_002B60B0(unsigned char *, float, float, float, float);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern void func_002A7470(void *, int, int, int);
extern char *func_0029EFD0(int);
extern void func_002A0F48(void *);
extern void func_002AF1D0(void *, void *, int, int);
extern float func_00282E48(void *, void *);
extern void func_002A93B0(void *);
extern void func_0029F338(void *);
extern void func_002AC728(void *, void *, int, float, float);
extern int func_002B0ED8(void *, void *, int);
extern void func_0029FCC0(char *, int, char *);
extern void func_L04_00451150(void *, int);
extern void func_002AB800(int, char *);
extern void func_L11_00425AF8(void *);
extern int func_002A8508(int, int);
extern int func_002B3670(void *, int *, int, int, void *, float, float);
extern void func_002A6C58(void *, int, int);

/* Initializes the rider, maintains its linked objects and handles damage/removal. */
int func_L11_00424A60(unsigned char *object)
{
    Vector hit_position;
    char *state = POINTER(object, 0x68);
    char *position = (char *)object + 0x10;
    char *linked, *other_state;
    unsigned short *ids;
    unsigned short id;
    int index, kind, result;
    float angle, ground;

    if (BYTE(object, 0x20) == 0) {
        BYTE(object, 0x30) = 0x80;
        ++D_L11_001AED04;
        POINTER(state, 0x18) = state + 0x140;
        REAL(object, 0x18) = func_002A89A8(position, 0, 0.5f);
        WORD(state, 0x554) = 0;
        WORD(state, 0x560) = 0;
        WORD(state, 0x568) = 0;
        BYTE(state, 0x48) = func_00283CF0(20.0f);
        BYTE(state, 0x4a) = func_00283CF0(14.0f);
        if (WORD(state, 0x528) != 0) {
            index = func_L02_0032E508(object, WORD(state, 0x524), state + 0x320, 16);
            WORD(state, 0x520) = index;
            func_0026FEB8(D_L11_001B0FD8, index);
        }
        angle = REAL(state, 0x298);
        if (angle == 0.0f) angle = func_002A78D8(15.0f, 25.0f);
        REAL(state, 0x298) = angle * 0.017453294f;
        if (func_002A77E0(2) == 1) {
            UHALF(object, 0x34) |= 0x8000;
            func_L00_003294F0(object, 1);
        }
        BYTE(state, 0x70) = 0x24;
        WORD(state, 0xa8) = 4;
        BYTE(state, 0x71) = 0x16;
        BYTE(state, 0x72) = 0x13;
        BYTE(state, 0x76) = 0x14;
        REAL(state, 0x7c) = 0.20000001788139343262f;
        REAL(state, 0x80) = 0.125f;
        REAL(state, 0x84) = 0.0055555556900799274445f;
        REAL(state, 0x88) = 0.0097222225740551948547f;
        REAL(state, 0x8c) = 0.0041666668839752674103f;
        BYTE(state, 0xcc) = 5;
        BYTE(state, 0xcd) = 10;
        BYTE(state, 0xce) = 8;
        BYTE(state, 0xcf) = 15;
        BYTE(state, 0xd2) = 6;
        BYTE(state, 0xd3) = 11;
        REAL(state, 0x10c) = 0.5f;
        REAL(state, 0xb8) = 0.18000000715255737305f;
        REAL(state, 0x90) = 0.75f;
        REAL(state, 0x94) = 0.75f;
        REAL(state, 0x9c) = 0.0f;
        if (WORD(state, 0x57c) != -1) WORD(state, 0xdc) = WORD(state, 0x57c);
        POINTER(state, 0x188) = state + 0x2a0;
        REAL(state, 0x174) = 0.25f;
        REAL(state, 0x14c) = 0.60000002384185791016f;
        REAL(state, 0x140) = 0.75f;
        REAL(state, 0x144) = 0.75f;
        REAL(state, 0x148) = 0.60000002384185791016f;
        if (WORD(state, 0x288) != -1) WORD(state, 0x17c) = WORD(state, 0x288);
        REAL(state, 0x170) = 1.4835300445556640625f;
        REAL(state, 0x150) = 1.5533431768417358398f;
        REAL(state, 0x16c) = 0.0013888889225199818611f;
        func_002B60B0(object, 0.0015277778729796409607f, 0.04583333432674407959f,
                     0.0011635529808700084686f, 0.10471977293491363525f);
        BYTE(state, 0x28) = 3;
        BYTE(state, 0x29) = 1;
        REAL(state, 0x30) = 0.75f;
        REAL(state, 0x28c) = (float)BYTE(state, 0x34);
        BYTE(state, 0x2e) = 1;
        if (WORD(state, 0x26c) == 0) {
            func_002A7750(object, 4, 0);
            if (BYTE(object, 0x43) != 0x24) func_002A7470(object, 0x24, 0, 0);
            kind = WORD(state, 0x540);
            if (kind == 1) {
                WORD(state, 0x55c) = D_L11_001B359C + WORD(state, 0x544) * 0x100;
                func_002A7750(object, 5, 0);
                if (BYTE(object, 0x43) != 0x1c) func_002A7470(object, 0x1c, 0, 0);
            } else if (kind == 2) {
                WORD(state, 0x55c) = D_L11_001B359C + WORD(state, 0x544) * 0x100;
                func_002A7750(object, 5, 0);
                if (BYTE(object, 0x43) != 0x1e) func_002A7470(object, 0x1e, 5, 0);
            } else if (kind == 3) {
                ids = D_L11_001FC420[BYTE(object, 0x21)];
                do {
                    id = *ids;
                    linked = (char *)(D_L11_001B359C + (id & 0x7fff) * 0x100);
                    if (SIGNED_BYTE(linked, 0x20) >= 0 && HALF(linked, 0xaa) == 0xcf5 &&
                        WORD(POINTER(linked, 0x68), 0x540) == 1) {
                        POINTER(state, 0x55c) = linked;
                        break;
                    }
                    ++ids;
                } while ((short)id >= 0);
                func_002A7750(object, 5, 0);
                if (BYTE(object, 0x43) != 0x1e) func_002A7470(object, 0x1e, 0, 0);
            } else if (WORD(state, 0x54c) != -1) {
                func_002A7750(object, 0xe, 0);
                if (BYTE(object, 0x43) != 0x10) func_002A7470(object, 0x10, 0, 0);
                if (WORD(state, 0x578) != 0) func_002A7750(object, 0xf, 0);
            }
            POINTER(state, 0x29c) = func_0029EFD0(0x9ac);
            if (POINTER(state, 0x29c) == 0) return 1;
            BYTE(POINTER(state, 0x29c), 0x30) = BYTE(object, 0x30);
            UHALF(POINTER(state, 0x29c), 0x32) = UHALF(object, 0x32);
            BYTE(POINTER(state, 0x29c), 0x31) = 1;
            *(long *)(POINTER(state, 0x29c) + 0x38) = *(long *)(object + 0x38);
            func_002A0F48(POINTER(state, 0x29c));
            WORD(POINTER(state, 0x29c), 0x98) = 0;
            func_002AF1D0(object, POINTER(state, 0x29c), 3, 0);
        } else {
            func_002A7750(object, 1, 5);
            if (WORD(state, 0x270) == -1) {
                func_0026FEB8(D_L11_002BACF0);
                --D_L11_001AED04;
                WORD(state, 0x26c) = 0;
                func_002A7750(object, 4, 0);
                return 1;
            }
            linked = (char *)(D_L11_001B359C + WORD(state, 0x270) * 0x100);
            POINTER(state, 0x274) = linked;
            QUAD(object, 0x10) = QUAD(linked, 0x10);
            QUAD(object, 0xf0) = QUAD(linked, 0xf0);
            WORD(object, 0x98) = 0;
            UHALF(object, 0x34) &= 0xafff;
            POINTER(POINTER(linked, 0x68), 0x27c) = (char *)object;
            POINTER(state, 0x280) = func_0029EFD0(0x911);
            if (POINTER(state, 0x280) == 0) return 1;
            BYTE(POINTER(state, 0x280), 0x30) = BYTE(object, 0x30);
            BYTE(POINTER(state, 0x280), 0x31) = 0;
            func_002A0F48(POINTER(state, 0x280));
            QUAD(POINTER(state, 0x280), 0x10) = QUAD(object, 0x10);
            REAL(POINTER(state, 0x280), 0x18) += 0.75f;
            POINTER(state, 0x278) = func_0029EFD0(0xff9);
            if (POINTER(state, 0x278) == 0) return 1;
            BYTE(POINTER(state, 0x278), 0x30) = BYTE(object, 0x30);
            UHALF(POINTER(state, 0x278), 0x32) = UHALF(object, 0x32);
            BYTE(POINTER(state, 0x278), 0x31) = 1;
            *(long *)(POINTER(state, 0x278) + 0x38) = *(long *)(object + 0x38);
            func_002A0F48(POINTER(state, 0x278));
            func_002AF1D0(object, POINTER(state, 0x278), 1, 0);
            WORD(state, 0x290) = 0;
        }
        if (WORD(state, 0x270) != -1 && POINTER(state, 0x278) == 0) {
            POINTER(state, 0x278) = func_0029EFD0(0xff9);
            if (POINTER(state, 0x278) == 0) return 1;
            BYTE(POINTER(state, 0x278), 0x30) = BYTE(object, 0x30);
            UHALF(POINTER(state, 0x278), 0x32) = UHALF(object, 0x32);
            BYTE(POINTER(state, 0x278), 0x31) = 1;
            *(long *)(POINTER(state, 0x278) + 0x38) = *(long *)(object + 0x38);
            func_002A0F48(POINTER(state, 0x278));
            func_002AF1D0(object, POINTER(state, 0x278), 1, 0);
            WORD(state, 0x290) = 0;
        }
        QUAD(state, 0x110) = QUAD(object, 0x10);
        REAL(state, 0x120) = 1.0f;
        REAL(state, 0x12c) = 8.0f;
        REAL(state, 0x130) = 10.0f;
    }
    if (BYTE(object, 0x31) != 0 && func_00282E48(position, &D_L11_001BA8C0) < 24.0f) {
        func_002A93B0(object);
        BYTE(object, 0x6f) = 0x16;
    }
    if (BYTE(state, 0x2e) == 2) {
        if (POINTER(state, 0x29c) != 0) {
            func_0029F338(POINTER(state, 0x29c));
            POINTER(state, 0x29c) = 0;
        }
        if (POINTER(state, 0x278) != 0) {
            func_0029F338(POINTER(state, 0x278));
            POINTER(state, 0x278) = 0;
        }
        if (POINTER(state, 0x280) != 0) {
            func_0029F338(POINTER(state, 0x280));
            POINTER(state, 0x280) = 0;
        }
        if (BYTE(object, 0xbc) == 1) {
            linked = (char *)(D_L11_001B359C + WORD(state, 0x548) * 0x100);
            if (BYTE(linked, 0x20) != 5) {
                BYTE(linked, 0x20) = 4;
                func_002A7470(linked, 0, 0, 5);
                REAL(linked, 0x48) = 1.0f;
                REAL(object, 0x48) = 1.0f;
                BYTE(object, 0xbc) = 0;
            }
        }
        return 1;
    }
    if (POINTER(state, 0x29c) != 0) func_002AF1D0(object, POINTER(state, 0x29c), 3, 0);
    if (REAL(state, 0x20) <= 1.0f) {
        if (POINTER(state, 0x29c) != 0) {
            func_002AC728(object, POINTER(state, 0x29c) + 0x10, -1, 0.5f, 3.0f);
            func_0029F338(POINTER(state, 0x29c));
            POINTER(state, 0x29c) = 0;
        }
        WORD(state, 0x290) = 0;
    }
    result = func_002B0ED8(object, state + 0x60, WORD(state, 0x290));
    if (result != 0) {
        linked = POINTER(state, 0x38);
        if (linked != 0) {
            kind = HALF(linked, 0xaa);
            if (kind != 0x47 && kind != 0xdd9 && kind != 0xd1b && kind != 0xce7 && kind != 0xd07 && kind != 0)
                D_L11_001AED00 = 0;
        }
        if (BYTE(object, 0xbc) == 1) {
            linked = (char *)(D_L11_001B359C + WORD(state, 0x548) * 0x100);
            if (result != 1 && BYTE(linked, 0x20) != 5) {
                BYTE(linked, 0x20) = 4;
                func_002A7470(linked, 0, 0, 5);
                REAL(linked, 0x48) = 1.0f;
                REAL(object, 0x48) = 1.0f;
                BYTE(object, 0xbc) = 0;
            }
        }
        if (REAL(object, 0x48) != 1.0f) REAL(object, 0x48) = 1.0f;
        if (WORD(state, 0x290) != 0) {
            func_0029FCC0((char *)object, 3, (char *)&hit_position);
            func_L04_00451150(&hit_position, 8);
        }
        if (result == 5) {
            REAL(state, 0xf4) = 0.83775818347930908203f;
            REAL(state, 0xf0) = 0.0f;
            if (POINTER(state, 0x29c) != 0) {
                func_002AC728(object, POINTER(state, 0x29c) + 0x10, -1, 0.5f, 3.0f);
                func_0029F338(POINTER(state, 0x29c));
                POINTER(state, 0x29c) = 0;
            }
        }
        WORD(state, 0x290) = 0;
        BYTE(state, 0x57) = 0xd2;
        func_002AB800((int)object, state + 0x50);
        if (BYTE(object, 0x95) != 2) func_L11_00425AF8(object);
        if ((unsigned int)(result - 4) < 2 && D_L11_001B35B8 >= BYTE(object, 0x21) &&
            func_002A8508(BYTE(object, 0x21), -1) >= 2) {
            ids = D_L11_001FC420[BYTE(object, 0x21)];
            do {
                id = *ids;
                linked = (char *)(D_L11_001B359C + (id & 0x7fff) * 0x100);
                if (HALF(linked, 0xaa) == 0xcf5 && WORD(POINTER(linked, 0x68), 0x294) == 0) {
                    WORD(POINTER(linked, 0x68), 0x294) = 1;
                    break;
                }
                ++ids;
            } while ((short)id >= 0);
        }
    }
    if (POINTER(state, 0x278) != 0 && WORD(state, 0x270) != -1)
        func_002AF1D0(object, POINTER(state, 0x278), 1, 0);
    HALF(state, 0x264) = func_002B3670(object, (int *)(state + 0x268), WORD(state, 0x250),
                                    WORD(state, 0x254), 0, REAL(state, 0x258), REAL(state, 0x25c));
    if (BYTE(object, 0x95) != 4 && BYTE(object, 0x20) != 0x25) {
        ground = func_002A89A8(position, 0, 0.5f);
        REAL(object, 0x18) -= 0.31333333253860473633f;
        if (REAL(object, 0x18) < ground) REAL(object, 0x18) = ground;
    }
    ground = func_002A89A8(position, 0, 0.5f);
    if (REAL(object, 0x18) - ground > 20.0f && ground < REAL(object, 0x18) && BYTE(object, 0x95) != 5) {
        func_002A7750(object, 0x25, 9);
        if (BYTE(object, 0x43) != 0x23) func_002A7470(object, 0x23, 0, 10);
    }
    if (REAL(object, 0x18) >= 75.0f || D_L11_001B30C8 < 6) return 0;
    func_002A6C58(object, 0, 3);
    if (D_L11_001B35B8 >= BYTE(object, 0x21) && func_002A8508(BYTE(object, 0x21), -1) >= 2) {
        ids = D_L11_001FC420[BYTE(object, 0x21)];
        do {
            id = *ids;
            other_state = POINTER((char *)(D_L11_001B359C + (id & 0x7fff) * 0x100), 0x68);
            if (WORD(other_state, 0x294) == 0) {
                WORD(other_state, 0x294) = 1;
                break;
            }
            ++ids;
        } while ((short)id >= 0);
    }
    if (POINTER(state, 0x29c) != 0) {
        func_002AC728(object, POINTER(state, 0x29c) + 0x10, -1, 0.5f, 3.0f);
        func_0029F338(POINTER(state, 0x29c));
        POINTER(state, 0x29c) = 0;
    }
    --D_L11_001AED04;
    return 1;
}
