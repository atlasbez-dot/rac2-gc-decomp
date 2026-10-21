/* NEAR MISS: 1,044 bytes, the size of retail's, but about 35 of 261 words differ (level 2 only). The per-frame
   step of a moving object, the sibling of func_L02_00398128 (same query record, same hit record at
   D_L02_001C0940, same two direction vectors): after the probe (func_002761F8) a hit that is not "blocked"
   (func_00278E78 == 0) while state+8 is negative spawns a sixteen-particle burst (func_002BFB38, speed and
   angle from func_002A7878 / func_002A7940) at the object's x/y and the hit's z, with func_00312D58 as the
   effect; otherwise the hit record decides the flag byte at +0xBC exactly as in func_L02_00398128, and
   func_L00_0038DE70 gets the two vectors at the end.
   Needs a unit of its own, src/levels/02_maktar_nebula/L02_00397D10-g8.c: -G8 (the two burst pointers
   D_L02_001B3D30 / D_L02_001B3D38 are `lw ...($gp)` outside a delay slot, declared `sda` with a size of at most
   8) and the `-frac2-qcopy` profile (three 16-byte copies through register addresses), so the config/cflags.txt
   line is `-O2 -G8 -ffunction-sections -frac2-qcopy`.
   What matches: the frame (0xE0) and the order of the locals (copy of the position at sp+0, the two direction
   vectors at sp+0x10/0x20, the query record at sp+0x30, the burst position/velocity at sp+0x60/0x70), every call
   with its arguments (func_00312D58 takes the burst position as its first argument), the sixteen-iteration
   loop with its `nop` slot, the likely-branch slots, retail's recompute of the hit record's address after the
   join (the second `rec = &D_L02_001C0940;`), and the two-register load of the player pointer (D_0018C0B0 is
   `nosda` in a -G8 unit).
   What differs, all scheduling or allocation around the lq/sq pairs (the same wall as func_L02_00398128 and
   func_L02_0033C760): retail issues the first zero store `sq $v0,0x10($sp)` among the prologue saves and keeps
   the argument moves of the calls that follow each pair (`daddu $a0,$s1,$zero` ... `daddu $a2,$s1,$zero`;
   `daddu $a0,$s0,$zero` / `daddu $a1,$s0,$zero`) behind the pair, where this compile hoists them above it; the
   temporaries of the record-height load differ ($a0/$a1/$v1 in retail); the %hi copy and the hit object swap
   $a0/$a1; and three address computations (`addiu $s4,$sp,0x70`, `addiu $s0,$sp,0x10`, the `swc1 $f20,0x38`
   store) sit one slot apart. Retail looks as if its lq/sq pairs were scheduling barriers. */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float pos[4];
    char *owner;
    int flags;
    u8 mode;
    u8 on;
    s16 type;
    float height;
    int one;
} L02_Probe;

typedef struct {
    u8 pad00[0x18];
    char *obj;
    int count;
    float pos[4];
    float pad30[4];
    float normal[4];
} L02_Hit;

typedef struct {
    u8 pad00[0x70];
    float height;
    u8 pad74[0xE0 - 0x74];
} L02_Rec;

extern void func_00282CC0(void *, void *, void *);
extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void func_00300248(void *, void *);
extern void func_002FE880(void *, void *, float);
extern void func_L00_0038F178(char *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00278E78(void);
extern void func_002FD1B8(void *, void *, int, float, float, float, float);
extern void func_00282C88(void *);
extern char *func_00312D58(void *, float);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002BFB38(void *, void *, int, int);
extern int func_00282948(void *);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(char *, void *, void *);

extern u8 D_00139574;
extern L02_Rec D_L02_00264A70[];
extern char *D_0018C0B0 __attribute__((nosda));
extern int D_L02_001AC850;
extern L02_Hit D_L02_001C0940;
extern void *D_L02_001B3D30 __attribute__((sda));
extern void *D_L02_001B3D38 __attribute__((sda));

void func_L02_00397D10(char *self) {
    float c[4], a[4], b[4];
    L02_Probe probe;
    float dpos[4], dvel[4];
    char *state;
    char *fx;
    float *pv;
    int i, n;
    float ang, spd;

    *(TI128 *)a = 0;
    *(TI128 *)b = 0;
    a[2] = 0.033333335f;
    b[2] = 1.0f;
    state = *(char **)(self + 0x68);
    *(TI128 *)c = *(TI128 *)(self + 0x10);
    func_00282CC0(self + 0x10, state, self + 0x10);
    func_002FEE70(*(int *)(state + 0x1C), state, 0);
    func_00300190(self + 0x10, self + 0x10);
    func_00300248(state, state);
    func_002FE880(self + 0x10, state, 0.0030555557f);
    func_L00_0038F178(self);
    probe.owner = self;
    probe.flags = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        probe.flags = 0x830001;
    probe.one = 1;
    probe.height = D_L02_00264A70[D_00139574].height;
    *(TI128 *)probe.pos = *(TI128 *)state;
    func_00282F70(probe.pos, probe.pos, 1.0f);
    probe.mode = 2;
    probe.pos[3] = 5627.9248046875f;
    probe.type = *(u16 *)(self + 0xAA);
    probe.pos[2] = 1.0f;
    probe.on = 1;
    if (func_002761F8(c, self + 0x10, 0x10, self, &probe) != 0) {
        char *rec;

        if (func_00278E78() == 0 && *(float *)(state + 8) < 0.0f) {
            func_002FD1B8(D_L02_001B3D30, D_L02_001B3D38, 1, *(float *)(self + 0x10),
                          *(float *)(self + 0x14), 0.5f, -0.35f);
            *(int *)(state + 0x14) = 1;
            func_00282C88(state);
            *(float *)(state + 8) = -0.025000002f;
            dpos[0] = *(float *)(self + 0x10);
            dpos[1] = *(float *)(self + 0x14);
            dpos[2] = D_L02_001C0940.pos[2];
            fx = func_00312D58(dpos, 2.0f);
            if (fx != 0)
                *(u8 *)(fx + 0x23) = 0x70;
            pv = dvel;
            for (i = 15; i >= 0; i--) {
                ang = func_002A7940();
                spd = func_002A7878(0.0f, 0.050000004f);
                dvel[0] = func_00283180(ang) * spd;
                dvel[1] = func_00283198(ang) * spd;
                dvel[2] = func_002A7878(0.050000004f, 0.10833334f);
                n = func_002A7820(0x5A, 0x78);
                func_002BFB38(dpos, pv, func_002A77E0(2), n);
            }
            goto flag;
        }
        rec = (char *)&D_L02_001C0940;
        if (*(char **)(rec + 0x18) != 0) {
            if ((*(char **)(rec + 0x18) == D_0018C0B0 || *(s16 *)(*(char **)(rec + 0x18) + 0xAA) == 0xC0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto flag;
            rec = (char *)&D_L02_001C0940;
            if (!(*(int *)(*(char **)(rec + 0x18) + 0x64) != D_L02_001AC850 ||
                  *(s16 *)(*(char **)(rec + 0x18) + 0xAA) == 0x336))
                goto flag;
        } else if (*(int *)(rec + 0x1C) <= 0) {
            goto flag;
        }
        *(u8 *)(self + 0xBC) = 1;
        *(TI128 *)(self + 0x10) = *(TI128 *)(rec + 0x20);
        rec += 0x40;
        func_00283028(a, state, rec);
        func_00282F20(a, a, 0.033333335f);
        func_00282F20(b, rec, 1.0f);
    } else if (func_00282948(state + 0x18) != 0) {
        *(u8 *)(self + 0xBC) = 1;
        func_00282CC0(a, a, state);
    }
flag:
    if (*(u8 *)(self + 0xBC) != 0) {
        func_002FEE50(*(int *)(state + 0x1C));
        func_L00_0038DE70(self, a, b);
    }
}
