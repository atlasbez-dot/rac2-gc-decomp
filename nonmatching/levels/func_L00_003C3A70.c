/* M12, 2026-10-26: not linked. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * (split addresses: retail schedules the lui/lbu pairs apart, which -mno-split-addresses cannot).
 * 800/800 bytes; us: 0/27. Changes: D_L00_001D9F00 and the three cleared tables are MACRO_ADDR
 * (retail lui/addiu of D+offset in one register), the body runs under if (owner) with one return,
 * forward/side are written at each use (retail copies them from the argument register), position stays
 * a local (spilled to 0($sp) as in retail), state words stored -1 then 30.
 * Residual: the three clear loops swap counter/pointer registers (v0/v1), the D_L00_001DB2BC lui uses
 * v0 where retail uses a0, and the owner+0x34 |= 0x41 read-modify-write is scheduled after the
 * forward address. With only D_L00_001B2940 MACRO_ADDR its loop allocates as retail.
 */
#include "common.h"


typedef int UiQuadword __attribute__((mode(TI)));
extern char *D_L00_001AFF98 __attribute__((sda));
extern unsigned char D_L00_001DB2BC;
extern char *D_L00_001D9F00[] MACRO_ADDR;
extern UiQuadword D_00189EA0[];
extern int D_L00_001B2940[] MACRO_ADDR;
extern int D_L00_001B2950[] MACRO_ADDR;
extern short D_L00_001B2990[] MACRO_ADDR;
extern UiQuadword D_L00_001B2900, D_L00_001B2910, D_L00_001B2920, D_L00_001B2930;
extern float D_L00_001AFF4C __attribute__((sda));
extern float D_L00_001B29D4 __attribute__((sda));
extern char D_L00_0023FB80[];
extern int func_L00_002D3F30(int, int);
extern int func_002E5AD0(void *, int, int, void *, int);
extern unsigned char *func_0029EFD0(int);
extern void func_002833F0(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_L00_0037E670(int);
extern float func_L00_0037E668(void);
extern int func_002E5CF8(int, int, char *);

unsigned char *func_L00_003C3A70(int mode)
{
    unsigned char *owner;
    char *state;
    void *forward, *up, *side;
    UiQuadword *position;
    short *entries;
    int *words;
    int i;
    if (D_L00_001AFF98 != 0) {
        func_002E5AD0(*(char **)(D_L00_001D9F00[D_L00_001DB2BC] + 0x28) + 0x80,
                      0, 0, D_00189EA0, 0x400);
        return 0;
    }
    if (func_L00_002D3F30(45, 1) == 0) {
        func_002E5AD0(*(char **)(D_L00_001D9F00[D_L00_001DB2BC] + 0x28),
                      0, 0, D_00189EA0, 0x400);
        return 0;
    }
    owner = func_0029EFD0(mode ? 0x1192 : 0xA5C);
    if (owner != 0) {
    state = *(char **)(owner + 0x68);
    D_L00_001AFF98 = owner;
    *(unsigned short *)(owner + 0x34) |= 0x41;
    owner[0x30] = 0xFF;
    owner[0x20] = 1;
    func_002833F0((owner + 0xC0), owner + 0xF0);
    up = owner + 0xE0;
    position = (UiQuadword *)(owner + 0x10);
    for (i = 3; i >= 0; i--)
        D_L00_001B2940[i] = 0;
    func_00282F20(D_L00_0023FB80, (owner + 0xC0), D_L00_001AFF4C);
    qcopy(&D_L00_001B2900, up);
    func_00282F20(D_L00_0023FB80 + 0x140, (owner + 0xD0), D_L00_001AFF4C);
    qcopy(&D_L00_001B2910, (owner + 0xC0));
    func_00282F20(D_L00_0023FB80 + 0x280, up, D_L00_001AFF4C);
    qcopy(&D_L00_001B2920, (owner + 0xD0));
    func_00282CC0(D_L00_0023FB80 + 0x3C0, (owner + 0xC0), up);
    entries = (short *)(state + 0x18);
    func_00282F20(D_L00_0023FB80 + 0x3C0, D_L00_0023FB80 + 0x3C0, D_L00_001AFF4C);
    words = (int *)(state + 0x20);
    func_00282DD8(&D_L00_001B2930, D_L00_0023FB80 + 0x3C0, (owner + 0xD0));
    for (i = 7; i >= 0; i--)
        D_L00_001B2950[i] = 0;
    for (i = 4; i >= 0; i--)
        D_L00_001B2990[i] = 0;
    D_L00_001B29D4 = 1.0f;
    func_L00_0037E670(mode);
    *(float *)state = func_L00_0037E668();
    qcopy(position, D_00189EA0);
    *(int *)(state + 0xC) = -1;
    *(int *)(state + 0x14) = 30;
    *(int *)(state + 0x10) = 0;
    for (i = 3; i >= 0; i--)
        entries[i] = 0;
    for (i = 3; i >= 0; i--)
        words[i] = 0;
    func_002E5CF8(1, 0, (char *)owner);
    }
    return owner;
}
