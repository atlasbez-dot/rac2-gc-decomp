/*
 * Complete manual reconstruction retained as nonmatching; no exact-C, linked-build
 * or runtime credit. Fresh worker checks on 2026-10-25, base dcfcd1f90746f3fbba715825d25bf19e88bf875c.
 * Tested profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 * Coverage: US: 0/1 placements; US2: 0/1 placements; PAL: absent from both catalogues.
 * US compiled size: 776 bytes; retail: 776 bytes.
 * Remaining difference: Same 776-byte size; first differing instruction at +0x170. The hit-object and copied-position pointers occupy A0/A1 in the opposite allocation; later hit-branch copies and scheduling differ. The complete prologue and class-table height setup now agree.
 * Reopen only with: A source-derived lifetime for the hit record and hit-object pointer that changes their actual allocator interference, supported by an allocator dump or an independently qualified corresponding source.
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
extern void func_002AFFD8(void *, void *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_0038F3D8(char *);
extern void func_00282F70(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00282948(void *);
extern void func_002FEE50(int);
extern void func_00283028(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_0038DE70(char *, void *, void *);
extern void func_L00_0038E880(char *, void *, void *);

extern u8 D_00139574;
extern L02_Rec D_L02_00264A70[];
extern char *D_0018C0B0;
extern int D_L02_001AC850;
extern L02_Hit D_L02_001C0940;

typedef union { TI128 quad; float f[4]; } L02_WorkVector;
typedef struct { L02_WorkVector a,b,c,d; L02_Probe probe; } L02_Workspace;

void func_L02_00398128(char *self) {
    L02_Workspace local;

    char *state;

    *(TI128 *)local.a.f = 0;
    local.a.f[2] = 0.033333335f;
    state = *(char **)(self + 0x68);
    *(TI128 *)local.b.f = 0;
    local.b.f[2] = 1.0f;
    qcopy(local.c.f,self + 0x10);
    func_00282CC0(self + 0x10, self + 0x10, state);
    func_002AFFD8(self + 0x10, local.d.f, 0);
    func_00282D30(local.d.f, local.d.f, 0.0003055555862374604f);
    func_L00_0038F3D8(self);
    local.probe.owner = self;
    local.probe.flags = 0x830000;
    if (*(int *)(state + 0x18) < 0x122)
        local.probe.flags = 0x830001;
    local.probe.one = 1;
    {
        u8 classIndex=D_00139574;
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
    *(int *)(state + 0x14) += 1;
    if (func_002761F8(local.c.f, self + 0x10, 0x10, self, &local.probe) != 0) {
        char *rec = (char *)&D_L02_001C0940;

        if (*(char **)(rec + 0x18) != 0) {
            char *hitObject=*(char **)(rec + 0x18);
            if ((hitObject == D_0018C0B0 || *(s16 *)(hitObject + 0xAA) == 0xC0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto flag;
            rec = (char *)&D_L02_001C0940;
            {
            char *classObject=*(char **)(rec + 0x18);
            if (*(int *)(classObject + 0x64) != D_L02_001AC850 ||
                *(s16 *)(classObject + 0xAA) == 0x336) {
                *(u8 *)(self + 0xBC) = 1;
                {
                    char *hitPosition=rec + 0x20;
                    qcopy(self + 0x10,hitPosition);
                }
                rec += 0x40;
                func_00283028(local.a.f, state, rec);
                func_00282F20(local.a.f, local.a.f, 0.033333335f);
                func_00282F20(local.b.f, rec, 1.0f);
            }
            }
        } else if (*(int *)(rec + 0x1C) > 0) {
            *(u8 *)(self + 0xBC) = 1;
            {
                    char *hitPosition=rec + 0x20;
                    qcopy(self + 0x10,hitPosition);
                }
            rec += 0x40;
            func_00283028(local.a.f, state, rec);
            func_00282F20(local.a.f, local.a.f, 0.033333335f);
            func_00282F20(local.b.f, rec, 1.0f);
        }
    } else if (func_00282948(state + 0x18) != 0) {
        *(u8 *)(self + 0xBC) = 1;
        func_00282CC0(local.a.f, local.a.f, state);
    }
flag:
    if (*(u8 *)(self + 0xBC) != 0) {
        func_002FEE50(*(int *)(state + 0x1C));
        if (*(int *)(state + 0x14) < 0x14)
            func_L00_0038DE70(self, local.a.f, local.b.f);
        else
            func_L00_0038E880(self, local.a.f, local.b.f);
    }
}
