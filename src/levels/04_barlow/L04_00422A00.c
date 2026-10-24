#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef float f32;


extern u8 D_L04_001395C7;
extern u8 D_L04_002CA518;

extern void func_2CC1F0(void *a0);
extern void func_30EA08(void *a0);
extern void func_33B9B0(void *a0, s32 a1, s32 a2);
extern void func_3317E8(void *a0);
extern void func_340BB8(void *a0, void *a1);
extern void func_345328(void *a0, void *a1, s32 a2, f32 f12, f32 f13);
extern void func_348708(void *a0, void *a1, s32 a2, s32 a3, f32 f12);
extern int func_34C4C8(void);
extern void *func_33E6B0(void *a0, s32 a1, s32 a2);
extern void func_40A090(int a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4, u8 *a5);

extern void func_0029F338(void *a0);
extern int func_002B38B8(u8 *a0);
extern void func_002A0430(u32 a0);
extern s32 func_00288AA0(u8 *a0, s32 a1);
extern s32 func_00288BE8(void *a0);
extern void func_002F5CC8(void);
extern float func_002AA3A8(float *a0, float *a1, float f12, float f13, float f14, float f15);
extern void func_002E5CF8(s32 a0, s32 a1, char *a2);

extern u8 D_0019B2E8[];
extern int D_001A79F0 __attribute__((sda));
extern int D_L04_001B24DC __attribute__((sda));
extern u8 D_L04_001BF880[];

/* Defined in L04_00422D40-qcopy.c. */
INCLUDE_ASM("asm/levels", func_L04_00422DA8);
INCLUDE_ASM("asm/levels", func_L04_00423258);
/* Counts the object's state up, easing its timer down while it is over the
   limit, and hands the level's recorder the object's channel when it runs out. */
void func_L04_0042BF58(u8 *a0) {
    u32 *s1 = *(u32 **)(a0 + 0x68);

    if (a0[0x20] == 0)
        a0[0x20] = 1;
    if (a0[0x20] == 2) {
        f32 f1 = *(f32 *)(a0 + 0x18);
        if (f1 >= 30.0f)
            *(f32 *)(a0 + 0x18) = f1 - 0.28333336114883423f;
        if (*(f32 *)(a0 + 0x18) < 30.0f)
            a0[0x20] = 4;
    }
    if (a0[0x20] == 3) {
        func_002AA3A8((f32 *)(a0 + 0x18), (f32 *)s1, 55.0f,
                      0.008333333767950535f, 0.013888888992369175f,
                      0.45000001788139343f);
        if (55.0f <= *(f32 *)(a0 + 0x18)) {
            func_002E5CF8(0, 0, (char *)a0);
            s1[1] = 0;
            a0[0x20] = 1;
        }
    }
}
INCLUDE_ASM("asm/levels", func_L04_00434BB0);
INCLUDE_ASM("asm/levels", func_L04_004389C0);
struct BarlowEntry { u8 bytes[256]; };
extern u8 D_00189EA0[];
extern u16 *D_L04_001FB1E0[];
extern u8 D_L04_001B1218[];
extern u8 D_L04_001B1230[];
extern int func_002ACBC8(void *, int);
extern int func_002A8508(int, int);
extern void func_0026FEB8(const char *, ...);

void func_L04_00438B50(u8 *object) {
    int *data = *(int **)(object + 0x68);
    int i;
    if (object[0x20] == 0) {
        if (func_002ACBC8(D_00189EA0, data[4]))
            object[0x20] = 1;
    }
    if (object[0x20] == 1) {
        u16 *ids;
        u8 *entry;
        struct BarlowEntry *base;
        for (i = 0; i < 4; i++) {
            if (D_L04_001FB1E0[*(int *)((u32)data + (i << 2))] && func_002A8508(*(int *)((u32)data + (i << 2)), -1) >= 2) {
                base = (struct BarlowEntry *)D_L04_001B24DC;
                ids = D_L04_001FB1E0[*(int *)((u32)data + (i << 2))];
                do {
                    entry = base[*ids & 0x7FFF].bytes;
                    *(u16 *)(entry + 0x34) |= 0x43;
                    *(int *)(entry + 0x98) = 0;
                } while ((s16)*ids++ >= 0);
            }
        }
        func_0026FEB8(D_L04_001B1218);
        object[0x20] = 2;
    }
    if (object[0x20] == 2) {
        if (!func_002ACBC8(D_00189EA0, data[4]))
            object[0x20] = 3;
    }
    if (object[0x20] == 3) {
        u16 *ids;
        u8 *entry;
        struct BarlowEntry *base;
        for (i = 0; i < 4; i++) {
            if (D_L04_001FB1E0[*(int *)((u32)data + (i << 2))] && func_002A8508(*(int *)((u32)data + (i << 2)), -1) >= 2) {
                base = (struct BarlowEntry *)D_L04_001B24DC;
                ids = D_L04_001FB1E0[*(int *)((u32)data + (i << 2))];
                do {
                    entry = base[*ids & 0x7FFF].bytes;
                    *(u16 *)(entry + 0x34) &= ~0x41;
                    *(int *)(entry + 0x98) = *(int *)(*(u8 **)(entry + 0x24) + 0x10);
                    *(u16 *)(entry + 0x34) &= ~2;
                } while ((s16)*ids++ >= 0);
            }
        }
        func_0026FEB8(D_L04_001B1230);
        func_0029F338(object);
    }
}

/* func_L04_00439870 is defined in L04_00422A00-g8.c (this unit's -G8 profile gives the
   retail's address forms). */
INCLUDE_ASM("asm/levels", func_L04_00439950);
extern void func_40A090(int a0, u8 *a1, u8 *a2, u8 *a3, u8 *a4, u8 *a5);

extern u8 D_L04_001B12B0[] __attribute__((sda));
extern u8 D_L04_001B12E8[] __attribute__((sda));
extern u8 D_L04_001B1300[] __attribute__((sda));
extern u8 D_L04_001B1330[] __attribute__((sda));
extern u8 D_L04_001B1348[] __attribute__((sda));
extern u8 D_L04_001B3280[] __attribute__((sda));
extern u8 D_L04_001B32B0[] __attribute__((sda));
extern u8 D_L04_001B32E0[] __attribute__((sda));
extern u8 D_L04_001B3300[] __attribute__((sda));
extern u8 D_L04_001B3320[] __attribute__((sda));
extern u8 D_L04_001B3330[] __attribute__((sda));
extern u8 D_L04_001B3360[] __attribute__((sda));
extern u8 D_L04_001B3378[] __attribute__((sda));
extern u8 D_L04_001B33A0[] __attribute__((sda));
extern u8 D_L04_001B33B0[] __attribute__((sda));
extern u8 D_L04_001B33B8[] __attribute__((sda));
extern u8 D_L04_001B33D8[] __attribute__((sda));
extern u8 D_L04_001B33E8[] __attribute__((sda));
extern u8 D_L04_001B3418[] __attribute__((sda));
extern u8 D_L04_001B3430[] __attribute__((sda));
extern u8 D_L04_001B3458[] __attribute__((sda));
extern u8 D_L04_001B3468[] __attribute__((sda));
extern u8 D_L04_001B3470[] __attribute__((sda));
extern u8 D_L04_001B3474[] __attribute__((sda));
extern u8 D_L04_001B3478[] __attribute__((sda));
extern u8 D_L04_001B347C[] __attribute__((sda));
extern u8 D_L04_001B3480[] __attribute__((sda));
extern u8 D_L04_001B3484[] __attribute__((sda));
extern u8 D_L04_001B3488[] __attribute__((sda));
extern u8 D_L04_0026D370[];
extern u8 D_L04_0026D3E0[];
extern u8 D_L04_0026D490[];
extern u8 D_L04_0026D4F0[];
extern u8 D_L04_002CA3E0[];
extern u8 D_L04_002CA438[];

extern void func_L04_0040A090(int, void *, void *, void *, void *, void *);

void func_L04_0043ABE0(void) {
    func_L04_0040A090(7, D_L04_001B12B0, D_L04_0026D370, D_L04_001B3300, D_L04_001B33B8, D_L04_001B3470);
    func_L04_0040A090(3, D_L04_001B12E8, D_L04_001B3280, D_L04_001B3320, D_L04_001B33D8, D_L04_001B3474);
    {
        u8 *data = D_L04_002CA3E0;
        func_L04_0040A090(11, data, D_L04_0026D3E0, D_L04_001B3330, D_L04_001B33E8, D_L04_001B3478);
    }
    func_L04_0040A090(6, D_L04_001B1300, D_L04_0026D490, D_L04_001B3360, D_L04_001B3418, D_L04_001B347C);
    func_L04_0040A090(9, D_L04_002CA438, D_L04_0026D4F0, D_L04_001B3378, D_L04_001B3430, D_L04_001B3480);
    func_L04_0040A090(3, D_L04_001B1330, D_L04_001B32B0, D_L04_001B33A0, D_L04_001B3458, D_L04_001B3484);
    func_L04_0040A090(2, D_L04_001B1348, D_L04_001B32E0, D_L04_001B33B0, D_L04_001B3468, D_L04_001B3488);
}


INCLUDE_ASM("asm/levels", func_L04_0043AD48);

void func_L04_00441178(u8 *a0) {
    if (a0[0x20] != 0)
        return;
    if (func_34C4C8() != 0) {
        func_2CC1F0(&D_L04_002CA518);
        D_L04_001395C7 = 1;
        func_33B9B0(a0, 1, -1);
    }
}
/* func_L04_0044AAC8 is defined in L04_00422A00-g8.c (it reads small data through $gp). */
INCLUDE_ASM("asm/levels", func_L04_0044BC90);
INCLUDE_ASM("asm/levels", func_L04_0044C598);
INCLUDE_ASM("asm/levels", func_L04_0044D0C0);
INCLUDE_ASM("asm/levels", func_L04_0044D428);
extern void func_30E9D8(void *a0);
extern f32 func_30F468(f32 a, f32 b);
extern f32 func_30FE88(f32 a, f32 b);
extern f32 func_30FE40(f32 a, f32 b);

/* Counts the object up, turns it towards the hero and keeps the turn inside
   a sixty degree limit, then hands the result to the frame helpers. */
void func_L04_0044D6A0(u8 *a0) {
    u8 *s1 = *(u8 **)(a0 + 0x68);
    u8 *v0;
    f32 f0, f1, f12, f13, lim;

    func_340BB8(a0, s1 + 0x50);
    func_30E9D8(s1 + 0x2FC);
    func_30EA08(s1 + 0x302);
    if (*(u16 *)(a0 + 0x96) <= 0xFFFE)
        *(u16 *)(a0 + 0x96) = *(u16 *)(a0 + 0x96) + 1;
    if (a0[0x95] == 2) {
        v0 = *(u8 **)(s1 + 0x250);
        f12 = *(f32 *)(v0 + 0x10) - *(f32 *)(a0 + 0x10);
        f13 = *(f32 *)(v0 + 0x14) - *(f32 *)(a0 + 0x14);
        lim = 1.047197699546814f;
        f0 = func_30F468(f12, f13);
        f0 = func_30FE88(f0, *(f32 *)(a0 + 0xF8));
        if (lim < f0) {
            f0 = lim;
        } else {
            f1 = -lim;
            if (f0 < f1)
                f0 = f1;
        }
        if (*(u16 *)(a0 + 0x34) & 0x8000)
            f0 = -f0;
        f0 = func_30FE40(f0, *(f32 *)(s1 + 0x2C8));
        *(f32 *)(s1 + 0x2C8) = f0;
        if (lim < f0) {
            *(f32 *)(s1 + 0x2C8) = lim;
        } else {
            f1 = -lim;
            if (f0 < f1)
                *(f32 *)(s1 + 0x2C8) = f1;
        }
    }
    func_348708(a0, s1 + 0x260, 1, 1, 2.5f);
}
INCLUDE_ASM("asm/levels", func_L04_0044D860);

/* subtracts the sub-structure's field from the owner's timer and reports it */
int func_L04_0044DAC8(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    char *r = func_33E6B0(*(char **)(s0 + 0x290), 0x10000, 0);

    if (r != 0) {
        *(f32 *)(s0 + 0x20) -= *(f32 *)(r + 0x2C);
        return 1;
    }
    return 0;
}
INCLUDE_ASM("asm/levels", func_L04_0044DB18);

void func_L04_00450268(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    void *p;

    p = *(void **)(s0 + 0x2AC);
    if (p != 0) {
        func_3317E8(p);
        *(void **)(s0 + 0x2AC) = 0;
    }
    p = *(void **)(s0 + 0x288);
    if (p != 0) {
        func_3317E8(p);
        *(void **)(s0 + 0x288) = 0;
    }
    p = *(void **)(s0 + 0x290);
    if (p != 0) {
        func_3317E8(p);
        *(void **)(s0 + 0x290) = 0;
    }
}
INCLUDE_ASM("asm/levels", func_L04_004502D0);
extern float func_00282DF0(void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_L02_0032E998(void *, void *, void *, void *, int, void *, void *, f32, f32);
extern void func_002AAA00(void *, f32, f32, f32, f32, void *, int);
extern f32 func_00283C80(f32, f32);
extern void func_002AA548(void *, void *, f32, f32, f32, f32);
extern f32 func_002AA2E8(f32 *, f32, f32);
extern void func_00282F20(void *, void *, f32);
extern void func_00282CC0(void *, void *, void *);
extern int func_002A7EA0(void *, void *, void *, f32, f32, f32, f32, int);

int func_L04_00450D50(u8 *object, void *target, f32 desiredHeading, f32 speed, f32 stopDistance, f32 margin) {
    f32 delta[4], displacement[4], destination[4];
    f32 angle, frameSpeed = 0.0f;
    u8 *data = *(u8 **)(object + 0x68);
    int done = 0;
    f32 distance, acceleration;
    func_00282CF0(delta, target, object + 0x10);
    delta[2] = 0.0f;
    distance = func_00282DF0(delta);
    acceleration = speed * 0.0008333333535119891f;
    if (stopDistance < distance) {
        int collision = *(int *)(data + 0x540);
        angle = 0.0f;
        func_L02_0032E998(object + 0x10, target, &angle, data + 0x340, collision, data + 0x550, data + 0x554, margin, 0.4f);
        func_002AAA00(object + 0xF8, angle, 0.006981317885220051f, 0.0034906589426100254f, 0.20943954586982727f, data + 0x28C, 0);
        if (func_00283C80(*(f32 *)(object + 0xF8), angle) < 0.523598849773407f) {
            func_002AA548(&frameSpeed, data + 0x558, distance, acceleration, acceleration, speed * 0.01666666753590107f);
        } else {
            *(f32 *)(data + 0x558) = 0.0f;
        }
    } else {
        func_002AAA00(object + 0xF8, desiredHeading, 0.006981317885220051f, 0.2f, 0.20943954586982727f, data + 0x28C, 0);
        func_002AA2E8((f32 *)(data + 0x558), 0.0f, acceleration);
        if (*(f32 *)(data + 0x558) == 0.0f && func_00283C80(*(f32 *)(object + 0xF8), desiredHeading) < 0.0872664749622345f) {
            *(f32 *)(data + 0x28C) = 0.0f;
            done = 1;
        }
    }
    func_00282F20(displacement, object + 0xC0, *(f32 *)(data + 0x558));
    func_00282CC0(destination, displacement, object + 0x10);
    if (!func_002A7EA0(object, object + 0x10, destination, 0.75f, 0.75f, 0.4f, 0.523598849773407f, 0))
        *(int *)(data + 0x55C) += 1;
    if (*(int *)(data + 0x55C) >= 30) {
        *(int *)(data + 0x55C) = 0;
        done = 1;
    }
    return done;
}


void func_L04_00451018(char *a0) {
    char *s0 = *(char **)(a0 + 0x68);
    u16 v;

    func_340BB8(a0, s0 + 0x50);
    func_30EA08(s0 + 0x270);
    func_30EA08(s0 + 0x272);
    func_30EA08(s0 + 0x26);
    v = *(u16 *)(a0 + 0x96);
    if (v <= 0xFFFE) {
        *(u16 *)(a0 + 0x96) = v + 1;
    }
    s0 += 0x2C0;
    func_345328(a0, s0, 4, 0.03f, 0.3f);
    func_348708(a0, s0, 4, 1, 2.5f);
}
/* Starts the object's encounter state and, once it is running, hands the level's
   camera table the object's slot and asks the frame helpers to update it. */
void func_L04_00455520(u8 *a0) {
    u32 *a1 = *(u32 **)(a0 + 0x68);

    if (a0[0x20] == 0) {
        if (D_0019B2E8[a0[0xB0] + D_001A79F0 * 16] & 0x80) {
            func_0029F338(a0);
            return;
        }
        a0[0x20] = 1;
    }
    if (a0[0x20] == 1) {
        if (func_002B38B8((u8 *)(D_L04_001B24DC + (*a1 << 8)))) {
            func_002A0430(a0[0xB0]);
            func_00288AA0(D_L04_001BF880, 0x38);
            func_00288BE8(D_L04_001BF880);
            func_002F5CC8();
            func_0029F338(a0);
        }
    }
}
INCLUDE_ASM("asm/levels", func_L04_00456628);
