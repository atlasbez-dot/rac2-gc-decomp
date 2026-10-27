/* Retained nonmatching C (Opus big42), first full reconstruction, 26 October 2026.
 * Profile: -O2 -G8 -ffunction-sections. 860/847 instructions; about 180 lines differ
 * ignoring registers and relocated offsets. Same control flow and calls as retail.
 * Kept: the resident words read lui/lw (D_001A7288, D_001A79F0, D_001A72F4, D_001A7304,
 * D_001A7290, D_001A7A18, D_001A72C0, D_001A72C4, D_001A7A0A) as incomplete arrays read
 * [0]; a sized declaration puts them in $gp range under -G8, which retail does not use.
 * Level counters (D_L00_001B24D8 and the three others) are plain sized ints: retail stores
 * them through $gp in a delay slot and reads them lui/lw in the loops, the -G8 plain-scalar
 * form. func_00291EC0 takes one argument ($a1 only holds the %hi of D_L00_001BF140).
 * Left: the GS word OR-chains (operand grouping and constant synthesis order), the
 * prologue's param spills (load/resume live in 0x0/0x4($sp)), store scheduling around the
 * D_00152C00/D_L00_001DA680 block, D_L00_001A9520 passed as $gp+offset (needs a sized sda
 * declaration; its extent is not measured), and the D_L00_001C9340 copy block's order.
 * Reopen from this draft; the structure is retail's.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef union { unsigned char b[0x400]; short h[0x200]; unsigned short uh[0x200]; int i[0x100];
                char *p[0x100]; unsigned long long d[0x80]; TI128 q[0x40]; } Blk;
typedef union { int i[0x40]; unsigned short uh[0x80]; short h[0x80]; } Hdr;
typedef struct {
    unsigned char pad0[4];
    unsigned char b4;
    unsigned char pad5[0xDB];
} ClassEntry;
typedef struct {
    unsigned char pad0[0x1A];
    short h1A;
    int i1C;
} Slot32;
typedef struct {
    int pad0;
    int f4;
    unsigned char pad8[0xC - 8];
    unsigned char bC;
    unsigned char bD;
    unsigned char padE[0x28 - 0xE];
    Slot32 *slots;
    unsigned char pad2C[0x48 - 0x2C];
    int f48[1];
} Bank;

extern Blk D_L00_001BF140;
extern Blk D_L00_001C9340;
extern char *D_001A7288[];
extern int D_001A79F0[];
extern int D_001A72F4[];
extern int D_001A7304[];
extern unsigned char D_0019B2E8[];
extern TI128 D_L00_001B1CE0;
extern unsigned long long D_L00_001B1CF0[3];
extern unsigned long long D_L00_001B1D08[3];
extern int D_L00_001B24D8;
extern int D_L00_001B1E8C;
extern int D_L00_001B2550;
extern int D_L00_001B2410;
extern int D_L00_00225900[];
extern int D_L00_001DC980[];
extern int D_L00_0022D200[];
extern int D_L00_0021FBA0[];
extern Blk D_00152CD0;
extern Blk D_00152C00;
extern int D_L00_001B1A40;
extern int D_L00_001B2420;
extern int D_L00_001B1A44;
extern int D_L00_001B1A48;
extern unsigned long long D_L00_001C91C0[3];
extern int D_L00_001A9520[] __attribute__((sda));
extern int D_L00_001B1E80;
extern int D_L00_001DD180[];
extern short D_L00_001DA680[];
extern Bank *D_L00_001D9F00[];
extern unsigned char D_L00_001DA860[];
extern short D_001A7A18[];
extern int D_001A7290[];
extern int D_001A72C0[];
extern int D_001A72C4[];
extern unsigned char D_00139568[];
extern ClassEntry D_L00_00262570[];
extern int D_L00_00226700;
extern int D_L00_0021EA20;
extern int D_L00_001B1944;
extern TI128 D_L00_001B1D20, D_L00_001B1D30, D_L00_001B1D40, D_L00_001B1D50;
extern int D_L00_001B1D60;
extern int D_L00_001B24D4;
extern Slot32 *D_L00_001B19EC;
extern int D_L00_001B19E8;
extern char D_L00_001A95B8[];
extern char D_L00_001A95D8[];
extern short D_00152CE4[];
extern unsigned char D_001A7A0A[];
extern int D_L00_001B1AD8;
extern int D_L00_001B1E9C;
extern int D_L00_001B1EA0;
extern int D_L00_001B19C8;

extern void func_00292888(void);
extern void func_L00_0036ADB0(void);
extern void func_00282B50(void *, void *, int);
extern void func_00282AB0(void *, void *, int);
extern void func_00293000(void *, int, int, void *);
extern void func_0011AEA0(int);
extern int func_0029D4D0(void *, char *);
extern int func_00282A18(int);
extern void func_L00_00300090(char *, void *);
extern void func_00291EC0(char *);
extern void func_L00_00300378(char *);
extern void func_00293890(char *, void *, void *, int);
extern void func_L00_00300438(void *, int, void *);
extern void func_00292328(int);
extern void func_002934B8(Bank *, int);
extern void func_L00_002FE268(void);
extern void func_00293260(Bank *, int);
extern void func_L00_002FF6A8(char *, void *, void *, int);
extern void func_L00_00300610();
extern void func_L00_002FFAB8(char *, void *, void *, void *, int);
extern void func_00291DE0(void *, int);
extern void func_L00_002FD480(char *);
extern void func_00291CA8(void *, char *, void *, int);
extern void func_0026FEB8(const char *, ...);
extern int func_L00_00300618(int);
extern void func_L00_003032F0(void);
extern void func_L00_00303418(int);
extern void func_L00_00358B30(void);
extern void func_L00_003588A8(void);
extern void func_L00_002E3BA0(int);
extern void func_L00_0032CF60(void);

int func_L00_00303990(int load, int resume)
{
    Hdr *h = (Hdr *)D_L00_001BF140.p[0xC / 4];
    char *f = D_001A7288[0];
    char *base;
    char *end;
    int i;
    int fx;
    int fy;
    char *e;
    int *out;
    int idx;
    int *list;
    short *sp;
    int j;
    Bank *bank;
    Slot32 *slot;
    char *tab;
    char *tab2;
    short *ent;
    int cnt;
    unsigned int mem;
    int n;
    unsigned short *us;

    if (load)
        func_00292888();
    base = D_L00_001BF140.p[0x18 / 4];
    if (load) {
        func_L00_0036ADB0();
        D_L00_001C9340.i[0] = 0;
        func_00282B50(h, f + *(int *)(f + 8), *(int *)(f + 0xC));
        func_00282AB0(&D_L00_001B1CE0, D_0019B2E8 + D_001A79F0[0] * 16, 16);
        func_00293000(f + *(int *)(f + 0x10), h->i[0], h->i[0x84 / 4], (char *)h + h->i[1]);
        func_0011AEA0(0);
        end = (char *)func_0029D4D0(f + *(int *)(f + 0x48), base);
        fx = D_001A72F4[0];
        fy = D_001A7304[0];
        D_L00_001BF140.p[0x2C / 4] = base + h->i[0x60 / 4];
        D_L00_001B1CF0[0] = (unsigned long long)((fy + h->i[0x90 / 4] * 4) >> 8 | 0x1DB08000) |
                            ((unsigned long long)((fx + h->i[0x94 / 4]) >> 8) << 37 | 0x5C0000000ULL) |
                            0x8000000000000000ULL;
        D_L00_001B1CF0[1] = 0xFFA0000000E0ULL;
        D_L00_001B1CF0[2] = 0x40000400004000ULL;
        D_L00_001B1D08[0] = (unsigned long long)((fy + h->i[0x98 / 4] * 4) >> 8 | 0x19B04000) |
                            ((unsigned long long)((fx + h->i[0x9C / 4]) >> 8) << 37 | 0x580000000ULL) |
                            0x8000000000000000ULL;
        D_L00_001B1D08[1] = 0xFFA0000000E0ULL;
        D_L00_001B1D08[2] = 0x40000400004000ULL;

        e = (char *)h + h->i[0x34 / 4];
        D_L00_001B24D8 = h->i[0x30 / 4];
        for (i = 0; i < D_L00_001B24D8; i++) {
            D_L00_00225900[i] = D_L00_001BF140.i[0x2C / 4] + *(int *)(e + i * 16) +
                                (func_00282A18(*(unsigned short *)(e + i * 16 + 4)) << 28);
        }
        end = base + (int)end;
        e = (char *)h + h->i[0x3C / 4];
        D_L00_001B1E8C = h->i[0x38 / 4];
        for (i = 0; i < D_L00_001B1E8C; i++) {
            D_L00_001DC980[i] = D_L00_001BF140.i[0x2C / 4] + *(int *)(e + i * 16) +
                                (func_00282A18(*(unsigned short *)(e + i * 16 + 4)) << 28);
        }
        qcopy(&D_00152CD0, e + h->i[0x80 / 4] * 16);
        D_00152CD0.uh[0x10 / 2] = h->uh[0x80 / 2];
        e = (char *)h + h->i[0x44 / 4];
        D_L00_001B2550 = h->i[0x40 / 4];
        for (i = 0; i < D_L00_001B2550; i++) {
            D_L00_0022D200[i] = D_L00_001BF140.i[0x2C / 4] + *(int *)(e + i * 16) +
                                (func_00282A18(*(unsigned short *)(e + i * 16 + 4)) << 28);
        }
        e = (char *)h + h->i[0x4C / 4];
        D_L00_001B2410 = h->i[0x48 / 4];
        for (i = 0; i < D_L00_001B2410; i++) {
            D_L00_0021FBA0[i] = D_L00_001BF140.i[0x2C / 4] + *(int *)(e + i * 16) +
                                (func_00282A18(*(unsigned short *)(e + i * 16 + 4)) << 28);
        }
        D_L00_001BF140.p[0x1C / 4] = base + h->i[0x8 / 4];
        func_L00_00300090(D_L00_001BF140.p[0x1C / 4], (char *)h + h->i[0x34 / 4]);
        D_L00_001C9340.p[0x8 / 4] = D_L00_001BF140.p[0x1C / 4];
        if (h->i[0xC / 4] != 0) {
            D_L00_001BF140.p[0x20 / 4] = base + h->i[0xC / 4];
            D_L00_001B1A40 = (int)(base + h->i[0xC / 4]);
        } else {
            D_L00_001BF140.p[0x20 / 4] = 0;
            D_L00_001B1A40 = 0;
        }
        if (h->i[0x10 / 4] != 0) {
            D_L00_001BF140.p[0x24 / 4] = base + h->i[0x10 / 4];
            func_00291EC0(base + h->i[0x10 / 4]);
        } else {
            D_L00_001B2420 = 0;
            D_L00_001BF140.p[0x24 / 4] = 0;
        }
        D_L00_001BF140.p[0x28 / 4] = base + h->i[0x14 / 4];
        func_L00_00300378(base + h->i[0x14 / 4]);
        D_L00_001C9340.p[0x4 / 4] = D_L00_001BF140.p[0x28 / 4];
        e = (char *)h + h->i[0x1C / 4];
        for (i = 0; i < h->i[0x18 / 4]; i++, e += 0x20) {
            char *p = *(int *)e != 0 ? base + *(int *)e : 0;
            if (*(int *)(e + 8) != 0) {
                D_L00_001C91C0[0] = D_00152C00.d[0x38 / 8];
                D_L00_001C91C0[1] = 0xFFA0000000E0ULL;
                D_L00_001C91C0[2] = 0x40000400004000ULL;
                func_00293890(p, 0, D_L00_001A9520, *(int *)(e + 4));
                D_L00_001DD180[D_L00_001B1E80 - 1] = 0xFFFC0000;
            } else {
                func_00293890(p, (char *)h + h->i[0x3C / 4], e + 0x10, *(int *)(e + 4));
            }
        }
        D_L00_001BF140.p[0x38 / 4] = (char *)D_L00_001D9F00[0];
        func_L00_00300438((char *)h + h->i[0x1C / 4], h->i[0x18 / 4], (char *)h + h->i[0x24 / 4]);
        n = D_L00_001B1E80;
        D_00152C00.i[0x1C / 4] = n;
        D_L00_001DA680[D_00152C00.i[0x1C / 4]] = 0xD54;
        D_L00_001D9F00[D_00152C00.i[0x1C / 4]] = (Bank *)D_L00_001BF140.p[0x70 / 4];
        D_L00_001DD180[D_00152C00.i[0x1C / 4]] = 0xFFFC0000;
        D_L00_001DA860[0xD54] = D_00152C00.b[0x1C];
        D_00152CD0.h[0x12 / 2] = n + 1;
        D_L00_001B1E80 = n + 2;
        if (D_001A7290[0] != D_001A7A18[0]) {
            func_00292328(D_001A7A18[0]);
            D_001A7290[0] = D_001A7A18[0];
        }
        func_002934B8(D_L00_001D9F00[0], D_L00_001BF140.i[0x78 / 4]);
        D_L00_001DD180[0] = 0xFFFC0000;
        if (D_L00_001DA860[0xD54] != 0xFF) {
            bank = D_L00_001D9F00[D_L00_001DA860[0xD54]];
            if (((unsigned char *)bank)[6] != 0) {
                char *q = *(char **)bank + ((unsigned char *)bank)[7] * 16;
                q = *(char **)q + *(int *)(q + 4) * 16;
                *(unsigned long long *)(q - 0x20) = D_L00_001B1CF0[0];
                *(unsigned long long *)(q - 0x10) = D_L00_001B1CF0[2];
            }
        }
        if (D_001A72C0[0] != D_L00_00262570[D_00139568[0xA]].b4)
            func_L00_002FE268();
        D_001A72C4[0] = D_L00_001DA860[0x47];
        func_002934B8(D_L00_001D9F00[D_L00_001DA860[0x47]], D_L00_001BF140.i[0x74 / 4]);
        D_L00_001DD180[D_001A72C4[0]] = 0xFFFC0000;
        us = (unsigned short *)((char *)h + h->i[0xAC / 4]);
        while ((short)*us >= 0) {
            if (D_L00_001DA860[(short)*us] != 0xFF)
                D_L00_001DD180[D_L00_001DA860[(short)*us]] = 0xFFF00000;
            us++;
        }
        list = (int *)((char *)h + h->i[0x78 / 4]);
        for (i = 0; i < D_L00_001D9F00[0]->bC; i++) {
            if (list[i] != 0) {
                D_L00_001D9F00[0]->f48[i] = (int)(base + list[i]);
                func_00293260(D_L00_001D9F00[0], i);
            }
        }
        D_L00_001BF140.i[0x44 / 4] = D_L00_001D9F00[0]->f48[0];
        e = (char *)h + h->i[0x24 / 4];
        for (i = 0; i < h->i[0x20 / 4]; i++, e += 0x20)
            func_L00_002FF6A8(base + *(int *)e, (char *)h + h->i[0x44 / 4], e + 0x10, *(int *)(e + 4));
        if (D_L00_00226700 != 0)
            D_L00_001BF140.i[0x3C / 4] = D_L00_00226700;
        func_L00_00300610((char *)h + h->i[0x24 / 4], h->i[0x20 / 4]);
        e = (char *)h + h->i[0x2C / 4];
        for (i = 0; i < h->i[0x28 / 4]; i++, e += 0x30)
            func_L00_002FFAB8(base + *(int *)e, (char *)h + h->i[0x4C / 4], e + 0x10, e + 0x20, *(int *)(e + 4));
        if (D_L00_0021EA20 != 0)
            D_L00_001BF140.i[0x40 / 4] = D_L00_0021EA20;
        D_L00_001BF140.p[0x34 / 4] = base + h->i[0x68 / 4];
        D_L00_001B1944 = (int)(base + h->i[0x68 / 4]);
        func_00291DE0((char *)h + h->i[0x5C / 4], h->i[0x58 / 4]);
        if (h->i[0xA4 / 4] != 0) {
            func_L00_002FD480(base + h->i[0xA4 / 4]);
        } else {
            qzero(&D_L00_001B1D20);
            qzero(&D_L00_001B1D30);
            qzero(&D_L00_001B1D40);
            qzero(&D_L00_001B1D50);
            D_L00_001B1D60 = 0;
        }
        if (h->i[0xA8 / 4] != 0)
            D_L00_001B1A44 = (int)(base + h->i[0xA8 / 4]);
        else
            D_L00_001B1A44 = 0;
        if (h->i[0xB0 / 4] != 0)
            D_L00_001B1A48 = (int)(base + h->i[0xB0 / 4]);
        else
            D_L00_001B1A48 = 0;
        D_L00_001BF140.p[0x30 / 4] = base + h->i[0x64 / 4];
        func_00291CA8((char *)h + h->i[0x6C / 4], base + h->i[0x64 / 4], (char *)h + h->i[0x54 / 4], h->i[0x50 / 4]);
        mem = ((unsigned int)end + 0x3F) & ~0x3F;
        if (D_L00_001B24D4 != D_L00_001C9340.i[0x18 / 4]) {
            D_L00_001C9340.i[0x10 / 4] = mem;
            func_00282B50((void *)mem, (char *)h + h->i[0x34 / 4], h->i[0x30 / 4] * 16);
            mem += h->i[0x30 / 4] * 16;
            D_L00_001C9340.i[0x14 / 4] = mem;
            mem = (mem + D_L00_001C9340.i[0x18 / 4] * 2 + 0x7F) & ~0x3F;
        }
        tab = (char *)h + h->i[0x70 / 4];
        cnt = ((short *)tab)[1];
        D_L00_001B19EC = (Slot32 *)mem;
        D_L00_001B19E8 = cnt;
        func_00282AB0((void *)mem, tab + ((short *)tab)[0], cnt * 32);
        mem += cnt * 32;
        ent = (short *)(tab + 4);
        tab2 = tab + ent[0];
        for (i = 0; i < D_L00_001B19E8; i++) {
            if (D_L00_001B19EC[i].h1A >= ent[1]) {
                func_0026FEB8(D_L00_001A95B8);
                D_L00_001B19EC[i].h1A = -1;
            } else {
                D_L00_001B19EC[i].h1A = *(unsigned short *)(tab2 + D_L00_001B19EC[i].h1A * 4);
            }
            D_L00_001B19EC[i].i1C = 0;
        }
        ent += 2;
        e = (char *)h + h->i[0x1C / 4];
        for (i = 0; i < h->i[0x18 / 4]; i++, ent += 2, e += 0x20) {
            idx = D_L00_001DA860[*(int *)(e + 4)];
            if (D_L00_001DA680[idx] == *(int *)(e + 4)) {
                if ((ent[1] != 0 || D_L00_001D9F00[idx]->bD != 0) && ent[1] - 1 != D_L00_001D9F00[idx]->bD)
                    func_0026FEB8(D_L00_001A95D8);
                {
                    int *src = (int *)(tab + ent[0]);
                    for (j = 0; j < D_L00_001D9F00[idx]->bD; j++) {
                        D_L00_001D9F00[idx]->slots[j].h1A = *(unsigned short *)(src + 1 + j);
                        D_L00_001D9F00[idx]->slots[j].i1C = src[0] + 1;
                    }
                }
            }
        }
        D_L00_001BF140.i[0x48 / 4] = (mem + 0x3F) & ~0x3F;
    }
    D_L00_001BF140.i[0x68 / 4] = func_L00_00300618(load);
    if (load)
        D_00152CE4[0] = -1;
    if (D_L00_001C9340.i[0xC / 4] != 0) {
        if (load)
            func_L00_003032F0();
        func_L00_00303418(D_L00_001C9340.i[0]);
    }
    if (resume)
        func_L00_00358B30();
    else
        func_L00_003588A8();
    D_L00_001B1AD8 = 0;
    if (D_001A7A0A[0] != 0) {
        for (i = D_L00_001B1E9C; i != D_L00_001B1EA0; i += 0x100)
            func_L00_002E3BA0(i);
    }
    func_L00_0032CF60();
    D_L00_001B19C8++;
    return 0;
}
