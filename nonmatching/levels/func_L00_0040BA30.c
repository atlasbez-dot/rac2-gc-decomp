/* Retained nonmatching C (Opus big42), measured 26 October 2026.
 * Profile: -O2 -G8 -ffunction-sections. 874/874 instructions, frame 0x150 as retail;
 * about 130 lines differ ignoring registers (493 positions identical with registers).
 * Kept: the hero, D_0018BE30, D_00139568, D_L00_001BF200 and D_L00_001FE940 reads
 * through union views (retail keeps each base in a register and uses offsets);
 * D_L00_001A8F20 as an sda incomplete array (retail rebuilds the lui/addiu pair at every
 * call); one float local per random draw (a shared one costs a mov.s and f20 in loop 1);
 * separate counters per loop (one shared counter steals the callee-saved register that
 * retail gives `self`); the 0xFE/0xFD tests as separate statements; the remove paths
 * written out (cross-jumped into one block after the state-1 test, as retail);
 * a switch on the state byte.
 * Left: (1) spill-slot order: retail puts &v40 at 0x9C and the gcse-made vars+0x30/0x60/0x70
 * pointers at 0xA0/0xA4/0xA8 (this C: vars+0x30 first), the gcse bucket-order note;
 * (2) state 0's class lookup: retail keeps 0xE0 in a register across the join and reloads
 * D_00139568[9] on the else path (cse follows the then-arm), this C does the opposite;
 * (3) the hit-record byte/half stores are scheduled before the angle test in retail;
 * (4) func_002E5DA0's arguments are set a0..a3 in retail (a3 first here), which moves the
 * join's first insn into the branch delay slots; (5) loop-2 copies of the gcse pointers.
 * Register choice (s2/s3/s4, s6/s7) follows from these.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { unsigned char b[0x2600]; short h[0x1300]; int i[0x980]; float f[0x980]; char *ptr[0x980]; TI128 q[0x260]; } Hero;
extern Hero D_00189E20;
typedef union { unsigned char b[0x400]; short h[0x200]; int i[0x100]; float f[0x100]; char *p[0x100]; TI128 q[0x40]; } Blk;
extern Blk D_0018BE30;
extern Blk D_00139568;
typedef struct {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad5[0x6B];
    float f70;
    unsigned char pad74[0x6C];
} ClassEntry;
extern ClassEntry D_L00_00262570[];
extern Blk D_L00_001BF200;
extern Blk D_L00_001FE940;
extern char D_L00_001A8F20[] __attribute__((sda));
extern unsigned char *D_L00_001FE9F4[];
extern float D_L00_001B1008 __attribute__((sda));
extern float D_L00_001B1000 __attribute__((sda));
extern int D_L00_001B0FE4 __attribute__((sda));
extern int D_L00_001B0FEC __attribute__((sda));
extern int D_L00_001B0FF0 __attribute__((sda));
extern int D_L00_001B0FE8 __attribute__((sda));
extern int D_L00_001B0FF4 __attribute__((sda));
extern int D_L00_001B19C8 __attribute__((sda));

extern void func_002AFFD8(char *, void *, int);
extern void func_0029FCC0(int, int, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern float func_00282DF0(void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern int func_002A77E0(int);
extern void func_002ACEC0(void *, void *, void *, float);
extern char *func_002AB1F0(char *);
extern int func_00282948(void *);
extern void func_00291450(int);
extern void func_0029F338(char *);
extern int func_002E5DA0(int, int, char *, int);
extern int func_002761F8(void *, void *, int, int, void *);
extern void func_L00_0040CCA0(void *, int, int);
extern int func_L00_002FCF18(void *, float, float, float, float, float);
extern char *func_002C65A0(void *, void *, int, unsigned int, int, int, int, float, float, float, int);
extern void func_L00_0040B398(char *);
extern void func_L00_002E6EF8(void (*)(char *), char *);
extern void func_L00_0040C7D8(char *);

typedef struct {
    float v[4];
    char *owner;
    int flags;
    signed char b18;
    signed char b19;
    unsigned short h1A;
    float f1C;
    int f20;
} Hit;

void func_L00_0040BA30(char *self)
{
    float old0[4];
    float mtx[4];
    float old20[4];
    float dir[4];
    float v40[4];
    float v50[4];
    Hit hit;
    char *vars = *(char **)(self + 0x68);
    float ang;
    float r;
    int i;
    int j;
    int m;
    unsigned int k;
    int flags;
    char *t;
    char *p;
    float s1, s2, s3, s4, s5, s6, s7, s8, s9;
    int n;
    ClassEntry *tbl;

    qcopy(old0, self + 0x10);
    func_002AFFD8(self + 0x10, mtx, 1);
    n = D_00189E20.i[0x1314 / 4];
    func_0029FCC0(n, 6, vars + 0x60);
    func_0029FCC0(n, 7, vars + 0x70);
    qcopy(old20, self + 0x10);
    func_00282CF0(dir, vars + 0x30, &D_00189E20.b[0x2010]);
    func_00282F20(dir, dir, 1.0f);
    ang = func_00283248(*(float *)(D_00189E20.ptr[0x18D0 / 4] + 0x10) - D_00189E20.f[0x80 / 4],
                        *(float *)(D_00189E20.ptr[0x18D0 / 4] + 0x14) - D_00189E20.f[0x84 / 4]);
    if (ang < 1.5707964897155762f)
        r = func_002A7878(0.0f, -0.7853982448577881f);
    else
        r = func_002A7878(0.0f, 0.7853982448577881f);
    qcopy(vars + 0x40, &D_0018BE30);
    *(float *)(vars + 0x48) -= D_L00_001B1008;
    func_00282CF0(vars + 0x40, vars + 0x40, &D_0018BE30);
    func_002ACEC0(vars + 0x40, vars + 0x40, dir, r);
    func_00282CC0(vars + 0x40, &D_0018BE30, vars + 0x40);
    t = *(char **)(vars + 0xC);
    if (t != 0) {
        if (*(unsigned char *)(t + 0x20) == 0xFE) {
            *(char **)(vars + 0xC) = 0;
        } else if (*(unsigned char *)(t + 0x20) == 0xFD) {
            *(char **)(vars + 0xC) = 0;
        } else {
            func_00282CF0(v40, t + 0x10, self + 0x10);
            if (func_00282DF0(v40) != 0.0f) {
                if ((p = func_002AB1F0(*(char **)(vars + 0xC))) != 0) {
                    func_00282D30(v50, mtx, *(float *)(p + 0x10));
                    func_00282CC0(v40, v40, v50);
                    func_00282DF0(v40);
                }
            } else {
                *(char **)(vars + 0xC) = 0;
            }
        }
    }
    ang = func_00283C80(func_00283248(*(float *)(D_00189E20.ptr[0x18D0 / 4] + 0x10) - D_00189E20.f[0x80 / 4],
                                      *(float *)(D_00189E20.ptr[0x18D0 / 4] + 0x14) - D_00189E20.f[0x84 / 4]),
                        D_00189E20.f[0x98 / 4]);
    switch (*(unsigned char *)(self + 0x20)) {
    case 0:
        tbl = D_L00_00262570;
        if (tbl[D_00139568.b[9]].b4 != 0) {
            k = D_00139568.b[0x49];
            flags = 0x110000;
        } else {
            k = D_00139568.b[9];
            flags = 0x10000;
        }
        hit.flags = flags;
        hit.owner = self;
        hit.f20 = 1;
        hit.f1C = tbl[k].f70;
        qcopy(hit.v, vars + 0x50);
        func_00282F20(&hit, &hit, 0.2f);
        hit.b19 = 1;
        hit.v[3] = 5627.9248046875f;
        hit.h1A = *(unsigned short *)(self + 0xAA);
        hit.b18 = 1;
        if (D_L00_001B1000 * 0.01745329424738884f < ang) {
            if (*(int *)(vars + 0x1C) == 0)
                { func_0029F338(self); return; }
            if (func_002761F8(&D_0018BE30, vars + 0x30, 0, D_0018BE30.i[0x280 / 4], &hit) == 0)
                { func_0029F338(self); return; }
            if (D_L00_001BF200.i[0x1C / 4] > 0)
                { func_0029F338(self); return; }
            if (D_L00_001BF200.p[0x18 / 4] == 0)
                func_L00_0040CCA0(&D_L00_001BF200.b[0x20], 0xF, 1);
            else if (*(int *)(D_L00_001BF200.p[0x18 / 4] + 0x98) != 0)
                func_L00_0040CCA0(&D_L00_001BF200.b[0x20], 0xA, 1);
        } else {
            if (func_002761F8(&D_0018BE30, vars + 0x30, 0, D_0018BE30.i[0x280 / 4], &hit) == 0)
                { func_0029F338(self); return; }
            if (D_L00_001BF200.i[0x1C / 4] > 0)
                { func_0029F338(self); return; }
            if (D_L00_001BF200.p[0x18 / 4] == 0)
                func_L00_0040CCA0(&D_L00_001BF200.b[0x20], 0xF, 0);
            else if (*(int *)(D_L00_001BF200.p[0x18 / 4] + 0x98) != 0)
                func_L00_0040CCA0(&D_L00_001BF200.b[0x20], 0xA, 0);
        }
        func_002E5DA0(0x15, 0, self, 0);
        *(unsigned char *)(self + 0x20) = 1;
        *(unsigned short *)(self + 0x34) |= 0x41;
        *(int *)(vars + 0x10) = D_L00_001B0FE4;
        func_00282CF0(v40, vars + 0x30, &D_0018BE30);
        func_00282F20(v40, v40, func_00282DF0(v40) * 0.5f);
        func_00282CC0(v40, &D_0018BE30, v40);
        if (D_L00_001B1000 * 0.01745329424738884f < ang) {
            if (*(int *)(vars + 0x1C) == 0)
                goto bounds;
            *(int *)(vars + 0x18) = func_L00_002FCF18(v40, 10.0f, 0.0f, 1.0f, 0.1f, 0.1f);
        } else {
            *(int *)(vars + 0x18) = func_L00_002FCF18(v40, 10.0f, 0.0f, 0.1f, 1.0f, 0.1f);
        }
        break;
    case 1:
        if (func_00282948(vars + 0x10) != 0) {
            *(char **)(vars + 0xC) = 0;
            if (*(int *)(vars + 0x18) != -1)
                func_00291450(*(int *)(vars + 0x18));
            func_0029F338(self);
            return;
        }
        if (D_L00_001B1000 * 0.01745329424738884f < ang) {
            if (*(int *)(vars + 0x1C) != 0) {
                for (i = 0; i < 10; i++) {
                    s1 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v40, vars + 0x30, vars + 0x60);
                    func_00282F20(v40, v40, s1 * func_00282DF0(v40));
                    func_00282CC0(v40, vars + 0x60, v40);
                    s2 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v50, vars + 0x30, vars + 0x70);
                    func_00282F20(v50, v50, s2 * func_00282DF0(v50));
                    func_00282CC0(v50, vars + 0x70, v50);
                    n = func_002A77E0(0xFF);
                    s3 = func_002A7878(0.35f, 0.5f);
                    p = func_002C65A0(v40, D_L00_001A8F20, D_L00_001B0FEC, D_L00_001B0FF0, n, 0x30, 0,
                                      s3 * 210000.0f, s3 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[7];
                    p = func_002C65A0(v50, D_L00_001A8F20, D_L00_001B0FEC, D_L00_001B0FF0, n, 0x30, 0,
                                      s3 * 210000.0f, s3 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[7];
                }
                for (j = 0; j < 20; j++) {
                    s4 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v40, vars + 0x30, vars + 0x60);
                    func_00282F20(v40, v40, s4 * func_00282DF0(v40));
                    func_00282CC0(v40, vars + 0x60, v40);
                    s5 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v50, vars + 0x30, vars + 0x70);
                    func_00282F20(v50, v50, s5 * func_00282DF0(v50));
                    func_00282CC0(v50, vars + 0x70, v50);
                    n = func_002A77E0(0xFF);
                    s6 = func_002A7878(0.2f, 0.35f);
                    v40[0] += func_002A78D8(0.0f, 0.02f);
                    v40[1] += func_002A78D8(0.0f, 0.02f);
                    v40[2] += func_002A78D8(0.0f, 0.02f);
                    p = func_002C65A0(v40, D_L00_001A8F20, D_L00_001B0FE8, D_L00_001B0FF4, n, 0x30, 0,
                                      s6 * 210000.0f, s6 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[6];
                    s6 *= 0.5f;
                    p = func_002C65A0(v40, D_L00_001A8F20, D_L00_001B0FE8, 0x808080, n, 0x30, 0,
                                      s6 * 210000.0f, s6 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[6];
                    v50[0] += func_002A78D8(0.0f, 0.02f);
                    v50[1] += func_002A78D8(0.0f, 0.02f);
                    v50[2] += func_002A78D8(0.0f, 0.02f);
                    p = func_002C65A0(v50, D_L00_001A8F20, D_L00_001B0FE8, D_L00_001B0FF4, n, 0x30, 0,
                                      s6 * 210000.0f, s6 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[6];
                    s6 *= 0.5f;
                    p = func_002C65A0(v50, D_L00_001A8F20, D_L00_001B0FE8, 0x808080, n, 0x30, 0,
                                      s6 * 210000.0f, s6 * 42000.0f, 0.0f, 0);
                    if (p != 0)
                        p[2] = (D_L00_001FE940.p[0x184 / 4])[6];
                }
                if (*(char **)(vars + 0xC) != 0 && D_L00_001B19C8 % 5 == 0) {
                    s7 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v40, vars + 0x30, vars + 0x60);
                    func_00282F20(v40, v40, s7 * func_00282DF0(v40));
                    func_00282CC0(v40, vars + 0x60, v40);
                    s8 = func_002A7878(0.0f, 1.0f);
                    func_00282CF0(v50, vars + 0x30, vars + 0x70);
                    func_00282F20(v50, v50, s8 * func_00282DF0(v50));
                    func_00282CC0(v50, vars + 0x70, v50);
                    p = func_002C65A0(v40, D_L00_001A8F20, 0x1E, 0x202080, 0, 0x40, 0,
                                      2100.0f, 126000.0078125f, 0.0f, 0);
                    if (p != 0)
                        p[2] = *D_L00_001FE9F4[0];
                    p = func_002C65A0(v50, D_L00_001A8F20, 0x1E, 0x202080, 0, 0x40, 0,
                                      2100.0f, 126000.0078125f, 0.0f, 0);
                    if (p != 0)
                        p[2] = *D_L00_001FE9F4[0];
                }
            }
        } else {
            for (m = 0; m < 10; m++) {
                s9 = func_002A7878(0.25f, 0.4f) * 210000.0f;
                p = func_002C65A0(&D_00189E20.b[0x2010], D_L00_001A8F20, 2, 0x108010, 2, 0x7F, 0x10,
                                  s9, s9, 0.0f, 0);
                if (p != 0)
                    p[2] = *D_L00_001FE940.p[0x64 / 4];
                p = func_002C65A0(&D_00189E20.b[0x2010], D_L00_001A8F20, 2, 0x208020, -1, 0x7F, 0x10,
                                  s9, s9, 0.0f, 0);
                if (p != 0)
                    p[2] = *D_L00_001FE940.p[0x64 / 4];
            }
        }
        func_L00_0040B398(self);
        func_L00_002E6EF8(func_L00_0040C7D8, self);
        break;
    }
bounds:
    if (*(float *)(self + 0x10) < 2.0f || *(float *)(self + 0x10) > 1021.0f ||
        *(float *)(self + 0x14) < 2.0f || *(float *)(self + 0x14) > 1021.0f ||
        *(float *)(self + 0x18) < 2.0f || *(float *)(self + 0x18) > 1021.0f)
        func_0029F338(self);
}
