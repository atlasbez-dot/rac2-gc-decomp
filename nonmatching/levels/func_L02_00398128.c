/* NEAR MISS: 776 bytes, the size of retail's, but about 43 of 194 words differ (level 2 only). The per-frame
   step of a moving object: it moves the position by the velocity at state+0, probes the world
   (func_002761F8 with a query record at sp+0x40), and on a hit reads the hit record D_L02_001C0940 (hit object
   at +0x18, a flag word at +0x1C, hit position at +0x20, normal at +0x40) to set the flag byte at +0xBC and
   the two direction vectors it hands to func_L00_0038DE70 / func_L00_0038E880.
   Needs the `-frac2-qcopy` profile (the four 16-byte copies go through register addresses): a unit of its own,
   src/levels/02_maktar_nebula/L02_00398128.c, with the config/cflags.txt line
   `-O2 -G0 -ffunction-sections -frac2-qcopy`.
   What matches: the frame (0xC0), the order of the stack locals (a at sp+0, b at sp+0x10, the copy of the
   position at sp+0x20, d at sp+0x30, the query record at sp+0x40), every call and argument, the likely-branch
   delay slots, retail's recompute of the hit record's address after the join (`addiu $s0,$a0,0x940` in the
   delay slots, from the gcse copy of the %hi: it needs `rec = &D_L02_001C0940;` written a SECOND time after the
   first tests, and a char pointer incremented in place for `rec += 0x40`), and the 0xE0-record height load
   (`lwc1 $f0,0x70($v0)` needs `D_L02_00264A70[D_00139574].height` as a struct array, not a byte offset).
   What differs, all of it scheduling or allocation around the lq/sq pairs:
   (1) prologue: retail issues the first zero store `sq $v0,0($sp)` at +0x28, among the saves, and the two
       argument moves `daddu $a0,$s3,$zero` / `daddu $a1,$s3,$zero` AFTER the first lq/sq pair; here the moves
       are hoisted above the pair and the first zero store sits next to the second, `sd $s0` comes first;
   (2) the temporaries of the record-height load (retail $a0 for the %hi of the byte, $a1 for 0xE0, $v1 for the
       array base; here $v1, $a0, $a2);
   (3) the %hi copy and the loaded hit object swap registers ($a0/$a1);
   (4) the two copies into the position: retail source $a0 / destination $v1, here $v1 / $a1; and one `lq/sq`
       pair is placed after the `addiu $s0,$s0,0x40` in retail, before it here.
   As in func_L02_0033C760, retail looks as if its lq/sq pairs were scheduling barriers (the argument moves
   stay behind the pair), which the grouped pair of -frac2-qcopy is not. -fno-schedule-insns (131 words) and -fno-schedule-insns2 (61) are worse;
   -frac2-zero-ti-barrier changes nothing (the zero feeds two stores, so it stays `por` + `sq`). */
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

void func_L02_00398128(char *self) {
    float a[4], b[4], c[4], d[4];
    L02_Probe probe;
    char *state;

    *(TI128 *)a = 0;
    *(TI128 *)b = 0;
    a[2] = 0.033333335f;
    b[2] = 1.0f;
    state = *(char **)(self + 0x68);
    *(TI128 *)c = *(TI128 *)(self + 0x10);
    func_00282CC0(self + 0x10, self + 0x10, state);
    func_002AFFD8(self + 0x10, d, 0);
    func_00282D30(d, d, 0.0003055555862374604f);
    func_L00_0038F3D8(self);
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
    *(int *)(state + 0x14) += 1;
    if (func_002761F8(c, self + 0x10, 0x10, self, &probe) != 0) {
        char *rec = (char *)&D_L02_001C0940;

        if (*(char **)(rec + 0x18) != 0) {
            if ((*(char **)(rec + 0x18) == D_0018C0B0 || *(s16 *)(*(char **)(rec + 0x18) + 0xAA) == 0xC0) &&
                *(int *)(state + 0x18) >= 0x122)
                goto flag;
            rec = (char *)&D_L02_001C0940;
            if (*(int *)(*(char **)(rec + 0x18) + 0x64) != D_L02_001AC850 ||
                *(s16 *)(*(char **)(rec + 0x18) + 0xAA) == 0x336) {
                *(u8 *)(self + 0xBC) = 1;
                *(TI128 *)(self + 0x10) = *(TI128 *)(rec + 0x20);
                rec += 0x40;
                func_00283028(a, state, rec);
                func_00282F20(a, a, 0.033333335f);
                func_00282F20(b, rec, 1.0f);
            }
        } else if (*(int *)(rec + 0x1C) > 0) {
            *(u8 *)(self + 0xBC) = 1;
            *(TI128 *)(self + 0x10) = *(TI128 *)(rec + 0x20);
            rec += 0x40;
            func_00283028(a, state, rec);
            func_00282F20(a, a, 0.033333335f);
            func_00282F20(b, rec, 1.0f);
        }
    } else if (func_00282948(state + 0x18) != 0) {
        *(u8 *)(self + 0xBC) = 1;
        func_00282CC0(a, a, state);
    }
flag:
    if (*(u8 *)(self + 0xBC) != 0) {
        func_002FEE50(*(int *)(state + 0x1C));
        if (*(int *)(state + 0x14) < 0x14)
            func_L00_0038DE70(self, a, b);
        else
            func_L00_0038E880(self, a, b);
    }
}
