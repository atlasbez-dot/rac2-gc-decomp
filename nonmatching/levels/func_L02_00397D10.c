/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 1044 bytes; retail: 1044 bytes.
 * Remaining difference: Same 1044-byte size; first differing instruction at +0xEC in class-table height calculation. Byte-base/stride temporaries and query-field scheduling still differ; later hit/spawn allocation also differs.
 * Reopen only with: A qualified class-table access shape or genuine object/probe lifetime that explains the retail A0/A1/V0/V1 allocation, rather than another declaration-order permutation.
 * Earlier complete variants and command logs are preserved privately.
 */
#include "include_asm.h"
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float pos[4] __attribute__((aligned(16)));
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

typedef union { TI128 quad; float f[4]; } L02_WorkVector;
typedef struct { L02_WorkVector c,a,b; L02_Probe probe; L02_WorkVector dpos,dvel; } L02_Workspace;

void func_L02_00397D10(char *self) {
    L02_Workspace local;

    char *state;
    char *fx;
    float *pv;
    int i, n;
    float ang, spd;

    *(TI128 *)local.a.f = 0;
    local.a.f[2] = 0.033333335f;
    state = *(char **)(self + 0x68);
    *(TI128 *)local.b.f = 0;
    local.b.f[2] = 1.0f;
    qcopy(local.c.f,self + 0x10);
    func_00282CC0(self + 0x10, state, self + 0x10);
    func_002FEE70(*(int *)(state + 0x1C), state, 0);
    func_00300190(self + 0x10, self + 0x10);
    func_00300248(state, state);
    func_002FE880(self + 0x10, state, 0.0030555557f);
    func_L00_0038F178(self);
    local.probe.owner = self;
    local.probe.flags = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        local.probe.flags = 0x830001;
    local.probe.one = 1;
    {
        unsigned int classIndex=D_00139574;
        L02_Rec *classTable=D_L02_00264A70;
        local.probe.height=classTable[classIndex].height;
    }
    qcopy(local.probe.pos,state);
    func_00282F70(local.probe.pos, local.probe.pos, 1.0f);
    local.probe.mode = 2;
    local.probe.pos[3] = 5627.9248046875f;
    local.probe.type = *(u16 *)(self + 0xAA);
    local.probe.pos[2] = 1.0f;
    local.probe.on = 1;
    if (func_002761F8(local.c.f, self + 0x10, 0x10, self, &local.probe) != 0) {
        char *rec;

        if (func_00278E78() == 0 && *(float *)(state + 8) < 0.0f) {
            func_002FD1B8(D_L02_001B3D30, D_L02_001B3D38, 1, *(float *)(self + 0x10),
                          *(float *)(self + 0x14), 0.5f, -0.35f);
            *(int *)(state + 0x14) = 1;
            func_00282C88(state);
            *(float *)(state + 8) = -0.025000002f;
            local.dpos.f[0] = *(float *)(self + 0x10);
            local.dpos.f[1] = *(float *)(self + 0x14);
            local.dpos.f[2] = D_L02_001C0940.pos[2];
            fx = func_00312D58(local.dpos.f, 2.0f);
            if (fx != 0)
                *(u8 *)(fx + 0x23) = 0x70;
            pv = local.dvel.f;
            for (i = 15; i >= 0; i--) {
                ang = func_002A7940();
                spd = func_002A7878(0.0f, 0.050000004f);
                local.dvel.f[0] = func_00283180(ang) * spd;
                local.dvel.f[1] = func_00283198(ang) * spd;
                local.dvel.f[2] = func_002A7878(0.050000004f, 0.10833334f);
                n = func_002A7820(0x5A, 0x78);
                func_002BFB38(local.dpos.f, pv, func_002A77E0(2), n);
            }
            goto flag;
        }
        rec = (char *)&D_L02_001C0940;
        if (*(char **)(rec + 0x18) != 0) {
            char *hitObject=*(char **)(rec + 0x18);
            if ((hitObject == D_0018C0B0 || *(s16 *)(hitObject + 0xAA) == 0xC0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto flag;
            rec = (char *)&D_L02_001C0940;
            {
            char *classObject=*(char **)(rec + 0x18);
            if (!(*(int *)(classObject + 0x64) != D_L02_001AC850 ||
                  *(s16 *)(classObject + 0xAA) == 0x336))
                goto flag;
            }
        } else if (*(int *)(rec + 0x1C) <= 0) {
            goto flag;
        }
        *(u8 *)(self + 0xBC) = 1;
        {
                    char *hitPosition=rec + 0x20;
                    qcopy(self + 0x10,hitPosition);
                }
        rec += 0x40;
        func_00283028(local.a.f, state, rec);
        func_00282F20(local.a.f, local.a.f, 0.033333335f);
        func_00282F20(local.b.f, rec, 1.0f);
    } else if (func_00282948(state + 0x18) != 0) {
        *(u8 *)(self + 0xBC) = 1;
        func_00282CC0(local.a.f, local.a.f, state);
    }
flag:
    if (*(u8 *)(self + 0xBC) != 0) {
        func_002FEE50(*(int *)(state + 0x1C));
        func_L00_0038DE70(self, local.a.f, local.b.f);
    }
}
