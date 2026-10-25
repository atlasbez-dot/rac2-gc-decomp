#include "include_asm.h"
#include "common.h"

extern void func_L00_00325AE8(void *, void *, float, float);

extern void *D_L02_001B17E8 __attribute__((sda));

extern float D_L02_001B17E4 __attribute__((sda));

extern float D_L02_001B17E0 __attribute__((sda));

extern float D_L02_001B17EC __attribute__((sda));

extern char *D_L02_001B1190[1] __attribute__((sda));

extern float func_00283CE0(int);

extern int func_00283CF0(float);

extern int func_L02_003F9B70(int);

extern int func_00288D58(void);

extern unsigned char D_001395B8[0x100];

/* Runs the kind's placement helper with the kind's own angles. */
void func_L02_00402440(char *a0) {
    if (*(unsigned char *)(a0 + 0x20) == 3)
        func_L00_00325AE8(a0 + 0x10, D_L02_001B17E8, D_L02_001B17E4, D_L02_001B17E0);
    else if (*(unsigned char *)(a0 + 0x20) == 2)
        func_L00_00325AE8(a0 + 0x10, D_L02_001B17E8, D_L02_001B17EC, D_L02_001B17E0);
}

#ifndef RAC2_T_TI128_L02
#define RAC2_T_TI128_L02
typedef int TI128 __attribute__((mode(TI)));
#endif

extern float D_L02_001B0180 __attribute__((sda));

extern float D_L02_001B0188 __attribute__((sda));

extern int D_L02_001B0184 __attribute__((sda));

extern float D_L02_001B0178 __attribute__((sda));

extern float D_L02_001B017C __attribute__((sda));

extern char D_L02_001BA500[];

extern void func_00282D30(void *, void *, float);

extern void func_00282CC0(void *, void *, void *);

extern void func_00282CF0(void *, void *, void *);

extern void func_00282F20(void *, void *, float);

extern float func_00282DB0(void *, void *);

/* The second declaration of the kind's helper in this unit: it takes the packed
   word where the call above takes a pointer. */
extern void func_L00_00325AE8_1(void *, int, float, float);

/* The 24-bit mask is written as 0xFFFFFF: the assembler expands `li` for 0xFF0000
   into `lui $v0,0xFF` and `ori $v0,$v0,0xFFFF`, so the register holds 0xFFFFFFFF. */
void func_L02_003D28E0(void *a0)
{
    void *s1 = a0;
    void *s2 = (char *)s1 + 0xE0;
    TI128 v0;
    TI128 v1;
    float f2;
    int a2;
    int a3;

    func_00282D30(&v0, s2, D_L02_001B0180);
    func_00282CC0(&v0, &v0, (char *)s1 + 0x10);
    func_00282CF0(&v1, D_L02_001BA500, (char *)s1 + 0x10);
    func_00282F20(&v1, &v1, 1.0f);
    f2 = func_00282DB0(&v1, s2);
    if (D_L02_001B0188 < f2) {
        a2 = D_L02_001B0184;
        f2 = f2 * f2;
        a3 = (int)(f2 * (float)(a2 >> 24));
        func_L00_00325AE8_1(&v0, (a2 & 0xFFFFFF) | (a3 << 24), D_L02_001B0178,
                            D_L02_001B017C);
    }
}

/* Near miss (best attempt in nonmatching/levels/func_L02_004013C0.c): the frame, the
   prologue, the two calls and the tail call match; the two words retail writes at
   sp+0 and sp+4 are the open difference, and they are no arguments of the call
   (the callee reads only $a0-$a3, $t0 and $f12). */
INCLUDE_ASM("asm/levels", func_L02_004013C0);

/* The kind's table gives a count; the kind's own helper gives the kind's id. */

/* The byte table the count is read from, at its address in the boot's resident memory. */

/* Scales the kind's own angle at +0xC down by 0.3 once per count the kind's byte table
   gives, keeps it inside the kind's own range, scales it by ten when the global flag is
   set, and hands it to the angle setter. */
int func_L02_003FCDF8(int a0) {
    float f20;
    int i = 0;

    f20 = func_00283CE0(*(int *)(D_L02_001B1190[a0] + 0xC));
    while (i < D_001395B8[func_L02_003F9B70(a0)]) {
        f20 *= 0.3f;
        i++;
    }
    {
        float f0 = (float)*(int *)(D_L02_001B1190[a0] + 0xC);

        if (f0 < f20)
            f20 = f0;
        else if (f20 < 500.0f)
            f20 = 500.0f;
    }
    if (func_00288D58() != 0)
        f20 *= 10.0f;
    return func_00283CF0(f20);
}

/* Near miss: same body with the other entry parameter (draft beside this one). */
int func_L02_003FCF08(int a0) {
    float f20;
    int i = 0;

    f20 = func_00283CE0(*(int *)(D_L02_001B1190[a0] + 0x10));
    while (i < D_001395B8[func_L02_003F9B70(a0)]) {
        f20 *= 0.33333f;
        i++;
    }
    {
        float f0 = (float)*(int *)(D_L02_001B1190[a0] + 0x10);

        if (f0 < f20)
            f20 = f0;
        else if (f20 < 5.0f)
            f20 = 5.0f;
    }
    return func_00283CF0(f20) << 5;
}

extern void func_00282C98(void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern void func_00282F70(void *, void *, float);
extern int func_L02_0032EF10(void *, char *, char *, int, float);

/* The level's 0x80-byte placement records, whose direction sits at +0x30. */
extern char *D_L02_001B368C;

/* Aligns the actor with the record its state names: the -1 case builds a direction from the
   +0x1F0 axis and the +0x340 vector and picks the 1.5-scaled or negated one by the sign of the
   dot product; the other case uses the 0x80-byte record from the boot table. The shared tail
   copies the +0x340 vector to the stack and hands it to the level's nine-place routine. */
int func_L02_003CCFE8(char *a0, char *a1)
{
    char *st = *(char **)(a0 + 0x68);
    TI128 a, b, c, d, e;
    int ret;

    if (*(int *)(st + 0x334) == -1) {
        func_00282CF0((float *)&a, (float *)(st + 0x1F0), (float *)(st + 0x340));
        func_00282C98(&b);
        func_00282DD8(&c, &a, &b);
        func_00282F20((char *)&c, (char *)&c, 1.5f);
        func_00282D30(&d, &c, -1.0f);
        func_00282CF0((float *)&e, a0 + 0x10, (float *)(st + 0x340));
        if (func_00282DB0(&e, &c) < 0.0f) {
            func_00282CC0(a1, &c, st + 0x340);
            ret = 1;
        } else {
            func_00282CC0(a1, &d, st + 0x340);
            ret = 0;
        }
    } else {
        func_00282CF0((float *)&a, (float *)(st + 0x1F0),
                      (float *)(D_L02_001B368C + (*(int *)(st + 0x334) << 7) + 0x30));
        ret = 1;
        func_00282F70((char *)&a, (char *)&a,
                      func_00282DF0(D_L02_001B368C + (*(int *)(st + 0x334) << 7)));
        func_00282CC0(a1, &a, D_L02_001B368C + (*(int *)(st + 0x334) << 7) + 0x30);
        func_00282CF0((float *)&b, a1, a0 + 0x10);
        if (!(0.0f <= func_00282DB0(&b, a0 + 0xD0)))
            ret = 0;
    }
    a = *(TI128 *)(st + 0x340);
    func_L02_0032EF10(&a, a1, a1, *(int *)(st + 0x318), *(float *)(st + 0x100));
    return ret;
}
