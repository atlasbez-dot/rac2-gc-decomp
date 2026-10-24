/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 2264 / 2292 bytes; size equality is not a match.
 * us: 0/1 placements; 2264/2292 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: 28 fewer bytes; local frame0x80 vs retail0x100 and global access/register allocation differ. Real8x3 tables,4-slot initial table and16-byte start vector retained.
 * Reopening condition: New measured source/data-layout or allocator hypothesis; do not repeat retained flag/control-flow trials or use artificial aliases/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* 2264/2292 bytes after2 trials. Real8x3 tables and16-byte initial slot table. Remaining global address/allocation/local-frame differences. -fno-gcse regressed2188.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. */
#include "include_asm.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct LvlSlotNode { char pad00[0x1C]; struct LvlSlotNode *next; } LvlSlotNode;
typedef struct LvlSlotCtx { char pad00[0x50]; LvlSlotNode *head; } LvlSlotCtx;
extern int D_L23_001B3824;
extern int D_L23_001B3820;
extern int D_L23_001B1424 __attribute__((sda));
extern int D_L23_001B13EC __attribute__((sda));
extern int D_L23_001B3718;
extern int D_L23_001B3714;
extern int D_L23_001B16A0 __attribute__((sda));
extern int D_L23_001B16A4 __attribute__((sda));
extern int D_L23_001B16A8 __attribute__((sda));
extern int D_L23_001B1694 __attribute__((sda));
extern int D_L23_001B3780;
extern int D_L23_001B1434 __attribute__((sda));
extern float D_L23_001B36F0;
extern float D_L23_001B36F4;
extern float D_L23_001B36F8;
extern float D_L23_001B3700;
extern float D_L23_001B3704 __attribute__((sda));
extern int D_L23_001B1650 __attribute__((sda));
extern float D_L23_001B3708;
extern float D_L23_001B370C;
extern int D_L23_001B3758;
extern int D_L23_001B36B0;
extern float D_L23_001B1490 __attribute__((sda));
extern int D_L23_001B374C;
extern int D_L23_001B3754;
extern int D_L23_001B3894;
extern int D_L23_001B3890;
extern int D_L23_001B36AC __attribute__((sda));
extern float D_L23_001B36A4;
extern float D_L23_001B14D0 __attribute__((sda));
extern float D_L23_001B36FC;
extern float D_L23_001B13C8;
extern float D_L23_001B13CC;
extern int D_L23_001B38C0;
extern int D_L23_001B166C __attribute__((sda));
extern float D_L23_001B14C4 __attribute__((sda));
extern float D_L23_001B1470 __attribute__((sda));
extern int D_L23_001B14A0 __attribute__((sda));
extern int D_L23_001B3748 __attribute__((sda));
extern char *D_L23_001B1484 __attribute__((sda));
extern char *D_L23_001B14FC __attribute__((sda));
extern char *D_L23_001B13D0 __attribute__((sda));
extern char *D_L23_001B279C, *D_L23_001B27A0, *D_L23_001B27A8;
extern int *D_L23_001B36A8;
extern char *D_L23_001B3790[4];
extern int D_L23_001B17C0[4];
extern int D_L23_001B1658[4] __attribute__((sda));
extern Quad D_L23_001B13F0 __attribute__((sda));
extern Quad D_L23_001B3760, D_L23_001B3770;
extern int D_L23_00259320[8][3];
extern char *D_L23_00259380[8][3];
extern Quad D_L23_002593E0[8][3];
extern char *D_L23_00259560[];
extern unsigned char D_L23_002595C8[0xFE0];
extern unsigned char D_00189E20[];
extern unsigned int D_00138324;
extern void func_00282948(char *);
extern void func_001163A0(unsigned int);
extern void func_00282CF0(char *, char *, char *);
extern float func_00282DF0(char *);
extern void func_L23_00418650(char *, float);
extern void *func_002B60B0(unsigned char *, float, float, float, float);
extern void func_002A7750(unsigned char *, unsigned char, int);
extern void *func_00115484(void *, int, unsigned int);
extern void func_L23_004196B8(char *);
extern void func_L23_0041CA58(char *);
extern void func_L23_00419970(char *);
extern void func_0029B758(int, int);
extern void func_L23_0041B478(void);
extern int func_L23_0041DA48(void);
extern void func_L00_002AF7D0(void);
extern void func_L00_00310C88(LvlSlotCtx *, LvlSlotNode **);
extern int func_L22_002C9898(int, int);
extern int func_00288FB8(int);
extern int func_L00_0030DD70(int, int);
extern void func_002AFFD8(char *, char *, int);
extern void func_L00_00325600(void *, void *, void *);
extern void func_L23_0041B9F0(char *);
#define I(off) (*(int *)(state + (off)))
#define F(off) (*(float *)(state + (off)))
#define H(off) (*(short *)(state + (off)))
#define B(off) (((unsigned char *)state)[(off)])

/* Initialize the encounter objects and refresh their shared presentation state. */
void func_L23_004177F8(char *object) {
    struct { Quad origin, point; } local;
    char *state = *(char **)(object + 0x68);
    char *entity, *entry;
    char **parts, **out;
    int i, j, id;
    float health;
    func_00282948((char *)&D_L23_001B3748);
    if (((unsigned char *)object)[0x20] == 0) {
        D_L23_001B3824 = 0; D_L23_001B3820 = 0;
        D_L23_001B1424 = 1; D_L23_001B13EC = 0;
        D_L23_001B3718 = 0; D_L23_001B3714 = 0;
        D_L23_001B16A0 = 0; D_L23_001B16A4 = 0; D_L23_001B16A8 = 0;
        D_L23_001B1694 = 0; D_L23_001B3780 = 0; D_L23_001B1434 = 0;
        I(0x620) = 0; I(0x624) = 0;
        D_L23_001B36F0 = F(0x31C); D_L23_001B36F4 = F(0x308);
        D_L23_001B36F8 = F(0x30C); D_L23_001B3700 = F(0x310); D_L23_001B3704 = F(0x314);
        D_L23_001B1650 = 1; I(0x60C) = 0;
        if (H(0x334) > 8) H(0x334) = 8;
        D_L23_001B3708 = F(0x330); D_L23_001B36A8 = (int *)(state + 0x230);
        D_L23_001B370C = (float)H(0x338); H(0x336) = 2;
        parts = (char **)(state + 0x358);
        D_L23_001B3758 = 0; D_L23_001B36B0 = 0;
        F(0x5C8) = D_L23_001B1490; I(0x608) = 0; F(0x5D0) = D_L23_001B1490;
        I(0x5CC) = 0; I(0x5D8) = 0; I(0x5B0) = 0; I(0x5C4) = 0;
        I(0x594) = 0; I(0x590) = 0; I(0x59C) = 0; B(0x1B7) = 1;
        D_L23_001B1484 = object;
        func_001163A0(*(volatile unsigned int *)0x10000800);
        D_L23_001B374C = -1; D_L23_001B3754 = 0; I(0x408) = 0;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 3; j++) {
                D_L23_00259320[i][j] = 0;
                D_L23_00259380[i][j] = 0;
                D_L23_002593E0[i][j] = 0;
            }
        }
        for (i = 3; i >= 0; i--) D_L23_001B3790[i] = 0;
        D_L23_001B3894 = 0; D_L23_001B3890 = 0;
        F(0x57C) = 0.098174773f; I(0x578) = 0; D_L23_001B36AC = 0;
        local.origin = 0;
        out = D_L23_00259560;
        for (entity = D_L23_001B279C; entity < D_L23_001B27A0; entity += 0x100) {
            id = *(short *)(entity + 0xAA);
            if (id == 0x7E5) *out++ = entity;
            else if (id == 0x27D) { local.origin = *(Quad *)(entity + 16); *(Quad *)(D_00189E20 + 0x80) = *(Quad *)(entity + 16); }
            else if (id == 0xF7E) *parts++ = entity;
            else if (id == 0x120F) *(char **)(state + 0x610) = entity;
            else if (id == 0x123C) *(char **)(state + 0x614) = entity;
            else if (id == 0xF7F) D_L23_001B14FC = entity;
            else if (id == 0xF6E) {
                ((unsigned char *)entity)[0x30] = 255;
                entry = *(char **)(entity + 0x68);
                ((unsigned char *)entry)[12] = 255; entry[8] = 0; entry[10] = 0;
                D_L23_001B13D0 = entity;
            }
        }
        func_00282CF0((char *)&local.origin, (char *)&local.origin, (char *)D_00189E20 + 0xB0);
        D_L23_001B36A4 = func_00282DF0((char *)&local.origin);
        local.point = 0;
        ((float *)&local.point)[0] = 500.0f; ((float *)&local.point)[1] = 500.0f; ((float *)&local.point)[2] = 430.0f;
        func_L23_00418650((char *)&local.point, 0.0f); D_L23_001B3760 = local.point;
        local.point = 0;
        ((float *)&local.point)[0] = 500.0f; ((float *)&local.point)[1] = 500.0f; ((float *)&local.point)[2] = 552.0f;
        func_L23_00418650((char *)&local.point, 0.0f); D_L23_001B3770 = local.point;
        *(Quad *)(object + 16) = D_L23_001B13F0;
        func_L23_00418650(object + 16, D_L23_001B14D0);
        ((unsigned char *)object)[0x30] = 255; *(short *)(object + 0x32) = 255;
        *(unsigned short *)(object + 0x34) |= 0x100;
        health = (float)H(0x2F6);
        D_L23_001B36FC = health * F(0x328);
        D_L23_001B13C8 = health * F(0x320) * 0.2f;
        F(0x17C) = 0.15f; D_L23_001B13CC = D_L23_001B13C8 * 0.083333336f;
        F(0x20) = health; H(0x24) = H(0x2F6);
        F(0x170) = 0.5f; F(0x174) = 0.5f; B(0x150) = 20; I(0x188) = -1;
        F(0x32C) = 1.0f - (F(0x324) + F(0x320) + F(0x328));
        F(0x84) = 0.5f; F(0x54) = -7.0f; F(0x50) = 7.0f;
        F(0x5C) = 0.4f; I(0x88) |= 5; F(0x60) = 1.57079649f; F(0x80) = 1.55334318f; F(0x58) = 0.4f;
        func_002B60B0((unsigned char *)object, 0.019444445f, 0.6333334f, 0.0017453295f, 0.20943955f);
        func_002A7750((unsigned char *)object, 2, 0);
        func_00115484(D_L23_002595C8, 0, 0xFE0);
        H(0x398) = -1; H(0x390) = 0; H(0x39C) = -1; H(0x39A) = -1; H(0x39E) = 0;
        D_L23_001B38C0 = 4;
        for (i = 0; i < 4; i++) D_L23_001B1658[i] = D_L23_001B17C0[i];
        D_L23_001B166C = 0;
        func_L23_004196B8(object); func_L23_0041CA58(object);
        F(0x588) = D_L23_001B14C4; I(0x88) |= 16; *(short *)(object + 0x7C) = 15;
    } else {
        func_L23_00419970(object);
        id = ((unsigned char *)object)[0x20];
        if (id != 4 && id != 10 && id != 11) {
            parts = (char **)(state + 0x36C);
            for (i = 4; i >= 0; i--, parts++) if (*parts) *(unsigned short *)(*parts + 0x34) |= 0x41;
        }
        if (!I(0x620)) for (entity = D_L23_001B27A8; entity; entity = *(char **)(entity + 0x28)) {
            if (*(short *)(entity + 0xAA) == 0x1252) { *(char **)(state + 0x620) = entity; break; }
        }
        if (!I(0x624)) for (entity = D_L23_001B27A8; entity; entity = *(char **)(entity + 0x28)) {
            if (*(short *)(entity + 0xAA) == 0x1251) { *(char **)(state + 0x624) = entity; break; }
        }
    }
    func_0029B758((int)func_L23_0041B478, (int)func_L23_0041DA48);
    *(float *)(object + 0x2C) = *(float *)(*(char **)(object + 0x24) + 0x24) * D_L23_001B1470;
    parts = (char **)(state + 0x358);
    for (i = 9; i >= 0; i--, parts++) if (*parts)
        *(float *)(*parts + 0x2C) = *(float *)(*(char **)(*parts + 0x24) + 0x24) * D_L23_001B1470;
    entity = *(char **)(state + 0x610);
    if (entity) *(float *)(entity + 0x2C) = *(float *)(*(char **)(entity + 0x24) + 0x24) * D_L23_001B1470;
    entity = *(char **)(state + 0x614);
    if (entity) *(float *)(entity + 0x2C) = *(float *)(*(char **)(entity + 0x24) + 0x24) * D_L23_001B1470;
    if (D_L23_001B1424) {
        D_L23_001B1424++;
        *(short *)(D_00189E20 + 0x1E0) = 10;
        H(0x390) = 0;
        if (!(D_00138324 & 0x50)) {
            if (D_L23_001B1424 < 30) {
                *(int *)(D_00189E20 + 0x2294) = 0;
                func_L00_002AF7D0();
                func_L00_00310C88((LvlSlotCtx *)*(char **)(D_00189E20 + 0x2290), (LvlSlotNode **)(D_00189E20 + 0x1870));
                *(int *)(D_00189E20 + 0x187C) = 0;
                func_L22_002C9898(0, 1);
            }
        } else {
            D_L23_001B1424 = 0;
            func_002A7750((unsigned char *)object, 1, 0);
            *(short *)(D_00189E20 + 0x1E0) = 20;
            D_00138324 = 0; D_L23_001B3748 = D_L23_001B14A0;
            func_L00_0030DD70(func_00288FB8(0x3157), -1);
        }
    }
    func_002AFFD8(object + 16, state + 0x410, 0);
    func_L00_00325600(object + 0xC0, state + 0x410, 0);
    if (((unsigned char *)object)[0x20] != 7) func_L23_00418650(object + 16, F(0x588));
    func_L23_0041B9F0(object);
}
