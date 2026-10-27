/* func_L08_0041EBF8 (7,128 B; levels 08 and 19): Sonnet first draft, 2026-10-26 (slate big12).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -ffast-math -g, as its own unit
 * (try src/levels/shared/L08_0041EBF8-x.c; delete the INCLUDE_ASM line from L08_003D3928.c).
 *  -G8: retail reads ~70 tuning floats/ints as one-instruction $gp loads outside delay slots
 *       (gp = 0x1AEFF0; declared below as sda scalars named by address D_<gp+off>); the level
 *       words read lui/lw (D_001A8F00, D_001A79F0, D_00138180 +0x1A0/+0x1A4, D_001B031C) are
 *       incomplete arrays [0] so -G8 leaves them absolute. D_001A8F00 is also read $gp-relative
 *       once (case 1): second name D_001A8F00_gp with the same asm label + sda.
 *  -ffast-math: the one min.s (case 3: min(k/60, f21) / (k/60)) comes from a ternary.
 *  -g: retail has the two nops before div.s at 0x41F55C.. (statement boundary); without -g
 *       7,008 B / 1,624 opcodes (3 fewer), so keep it.
 *  -frac2-qcopy: all lq/sq copies are plain TImode assignments (Quad); zeroing is `= 0`.
 * Step 0: one function (one prologue, one jr $ra, a 7-case jump table on obj[0x20]; this is the
 *  hero/Ratchet-NPC style state machine over the data block at obj+0x68). Twin search: no
 *  matched twin (nearest is the unmatched func_L08_003C6AB0, 0.65). Vehicle for declarations:
 *  func_L08_003CDF98's draft (same level, same globals D_00189E20/D_00188660/D_001B29DC).
 * Numbers (check.py, both places compile; 0 of 2 match): 7,032 of 7,128 bytes (24 instructions
 *  short); opcodes equal 1,627 of 1,782 (difflib, registers ignored); with registers equal 1,120.
 *  150 diff hunks, most 1-2 instructions.
 * What is right (structure matches retail case by case): the early-out block sits inline after the
 *  two tests (D_001A8F00 == 2 || *(g+0x2294) == 0x61 then return); the inner switch (cases 2/4/6
 *  empty, 0, 1 falling into 3, 5); case 3's b42/b43 test tree (the `!= st` compare against the
 *  loaded obj[0x20] and the redundant `b43 != 1`), the two loops (explicit pointer walks), the
 *  0x1A8-state record logic (`if (st == 2) {..} else {..}` order matters), the D_00188660
 *  record checks (`rp = base + i*0x70` then rp[0x88]/rp[0x74], via the RDEAD/RLIVE macros: any
 *  folded `base + 0x88 + i*0x70` form adds an addu), the tail (`if (d[0x5C] != 0.0f)` with the
 *  create-record arm first), the 8A state switch compare against the loaded state variable `st`.
 *  e[0..4] are the five spE0..spF0 floats (array so the order and the chained store
 *  `e4 = e0 = e1 = e2 = e3 = 0` give retail's mtc1 + five swc1); vs[12] is the 0x20..0xDF vector
 *  block (retail has 3 unused quads at 0xB0..0xDF; without them e[] lands at 0xB0, not 0xE0).
 * What still differs (Opus next steps):
 *  1. Register allocation is the bulk of the gap (1,627 vs 1,120). Retail: obj in $s5, d in $s2,
 *     the D_00189E20 base in $s3 only for the first region, and exactly six callee-saved FPRs
 *     (f20..f25) with p104/p108/p10C/pF8/pFC/p100 spilled to the stack (0x104,0x108,0x10C,
 *     0xF8,0xFC,0x100) and `entered` at 0xF4. Ours has obj in $s4, f20..f26 and keeps the
 *     pointers in $s6/$s7/$fp, so the frame is 0x180 against 0x190. Retail's 1.0f and the
 *     `sgn` (later -1.0f) share $f23; the 0.017453294f constant in $f20 is dead before
 *     func_00282C48's result lands in $f20. Ours keeps 1.0f in its own register and the
 *     constant alive to the later func_002AEF28 use. The case-5 re-assignments of
 *     p108/p10C/pF8 (and case 0's p104) are CSE'd away here but retail re-emits them
 *     (0x42028C: addiu a1/v0/v1 + three sw).
 *  2. Addressing form. Retail looks like -mno-split-addresses for the lui $at / lwc1 0x31C($at)
 *     of D_001B031C and `lui v1; lw v1,0x79F0(v1)` of D_001A79F0 (dest reuse), yet it keeps the
 *     D_00189E20 base in a register for a whole region (`addiu s3,v0,-0x61E0`, lw 0x2294(s3))
 *     and materialises D_001B99C0 as `addiu v0,v0,-0x6640` + 0x168/0x16C/0x160(v0). Tried
 *     -mno-split-addresses: the `lui $at` form appears, but opcodes drop to 1,588 and the G base
 *     is not kept in a register. D_001B031C as `sda` float gives `lwc1 0($gp)` (wrong); as an
 *     incomplete array under default flags gives lui+lwc1(%lo) (right opcode count). A local
 *     `u8 *g = D_00189E20` used across the whole function made $s7 permanent (worse); used for
 *     the first region and case 1's condition it is neutral.
 *  3. Small ordering items: vs[6] (sp80) is cleared by retail with `sq $zero,0($v0)` after
 *     `addiu v0,sp,0x80`; ours emits `por` + `sq` (any pointer spelling tried gives the same).
 *     DF(0x60) -= t[0x2C] loads 0x2C first in retail. DF(0x58) = OF(0x18) comes after the
 *     0x48 call's argument setup in retail (case 5 tail and the post-switch block).
 *     The case-0 `GF(0x1840)` ladder re-materialises the G base per arm in retail
 *     (lui a0/a1/v1/v0 + one addiu); ours reuses $s3.
 *  4. Case 3's float block: operand/load order of the e[]/gp loads (retail loads $f1=0xE0(sp)
 *     twice, mul by f20 each time); the min.s expression's two nops.
 * Callee prototypes: func_L08_0041EA88 takes ONE argument (m2c's second is stale);
 *  func_002ABBB8 is the 19-argument form (stack args 1, -1, 0, 0x810001);
 *  func_00277F48 takes (float, void *, int, void *, void *). */
#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; int i[4]; } Vec;

/* $gp-relative tuning constants (gp = 0x1AEFF0), one-instruction gp loads in retail. */
extern float D_001B18D0 __attribute__((sda));
extern float D_001B18D8 __attribute__((sda));
extern float D_001B18E0 __attribute__((sda));
extern float D_001B18E4 __attribute__((sda));
extern float D_001B18E8 __attribute__((sda));
extern float D_001B18EC __attribute__((sda));
extern float D_001B18F0 __attribute__((sda));
extern float D_001B18F4 __attribute__((sda));
extern float D_001B18F8 __attribute__((sda));
extern float D_001B18FC __attribute__((sda));
extern float D_001B1900 __attribute__((sda));
extern float D_001B1904 __attribute__((sda));
extern float D_001B1908 __attribute__((sda));
extern float D_001B190C __attribute__((sda));
extern float D_001B1910 __attribute__((sda));
extern float D_001B1914 __attribute__((sda));
extern s32 D_001B1918 __attribute__((sda));
extern s32 D_001B191C __attribute__((sda));
extern float D_001B1920 __attribute__((sda));
extern float D_001B1924 __attribute__((sda));
extern float D_001B1928 __attribute__((sda));
extern float D_001B192C __attribute__((sda));
extern float D_001B1930 __attribute__((sda));
extern float D_001B1934 __attribute__((sda));
extern float D_001B1938 __attribute__((sda));
extern float D_001B193C __attribute__((sda));
extern float D_001B1940 __attribute__((sda));
extern float D_001B1948 __attribute__((sda));
extern float D_001B194C __attribute__((sda));
extern float D_001B1950 __attribute__((sda));
extern float D_001B1954 __attribute__((sda));
extern float D_001B1958 __attribute__((sda));
extern float D_001B19B4 __attribute__((sda));
extern float D_001B19B8 __attribute__((sda));
extern float D_001B19BC __attribute__((sda));
extern float D_001B19C0 __attribute__((sda));
extern float D_001B19C4 __attribute__((sda));
extern float D_001B19C8 __attribute__((sda));
extern float D_001B19CC __attribute__((sda));
extern float D_001B19D0 __attribute__((sda));
extern float D_001B19D4 __attribute__((sda));
extern float D_001B19D8 __attribute__((sda));
extern float D_001B19E4 __attribute__((sda));
extern float D_001B1A14 __attribute__((sda));
extern float D_001B1A18 __attribute__((sda));
extern float D_001B1A1C __attribute__((sda));
extern float D_001B1A20 __attribute__((sda));
extern float D_001B1A24 __attribute__((sda));
extern float D_001B1A28 __attribute__((sda));
extern float D_001B1A30 __attribute__((sda));
extern s32 D_001B1A44 __attribute__((sda));
extern s32 D_001B1A48 __attribute__((sda));
extern s32 D_001B1A78 __attribute__((sda));
extern float D_001B1B1C __attribute__((sda));
extern float D_001B1B20 __attribute__((sda));
extern float D_001B1B24 __attribute__((sda));
extern s32 D_001B1B28 __attribute__((sda));
extern float D_001B1B2C __attribute__((sda));
extern float D_001B1B30 __attribute__((sda));
extern float D_001B1B34 __attribute__((sda));
extern float D_001B1B38 __attribute__((sda));
extern float D_001B1B3C __attribute__((sda));
extern s32 D_001B1B40 __attribute__((sda));
extern float D_001B1B44 __attribute__((sda));
extern float D_001B1B48 __attribute__((sda));
extern float D_001B1B4C __attribute__((sda));
extern float D_001B1B50 __attribute__((sda));
extern float D_001B1B54 __attribute__((sda));
extern s32 D_001B1B58 __attribute__((sda));
extern float D_001B1B5C __attribute__((sda));
extern float D_001B1B60 __attribute__((sda));
extern u8 D_001B1B64 __attribute__((sda));
extern float D_001B1B7C __attribute__((sda));
extern float D_001B1B80 __attribute__((sda));
extern s32 D_001A8F00[];
extern s32 D_001A8F00_gp __asm__("D_001A8F00") __attribute__((sda));
extern s32 D_001A79F0[];
extern float D_001B031C __attribute__((sda));
extern s32 D_00138180[];
extern char D_00189E20[];
extern char D_00189EA0[];
extern char D_00188660[];
extern char D_001B99C0[];
extern char D_001B9B00[];
extern char D_001BFF40[];
extern char D_001BFF60[];
extern char D_001BFF70[];
extern float D_001BFF80[];

extern void func_00277F48(float, void *, int, void *, void *);
extern int func_00277258(float *, int, float, void *);
extern int func_00278870(void *, float);
extern short func_00278E78(void);
extern void func_00282978(short *);
extern s32 func_002829A8(void *);
extern void func_00282948(void *);
extern float func_00282C48(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_00282E48(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00283698(void *, void *);
extern void func_00283898(void *, int, float);
extern float func_00283B98(float, float);
extern float func_00283BE0(float, float);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern void func_0029F338(void *);
extern void func_0029F978(void *, unsigned int, void *);
extern void func_0029FCC0(void *, int, void *);
extern void func_002A7470(void *, int, int, int);
extern int func_002A77E0(int);
extern float func_002A0558(void *, void *);
extern float func_002A89A8(void *, int, float);
extern void func_002A8C00(void *, void *, int, float, void *);
extern void func_002A93B0(void *);
extern u8 *func_002A9640(void *, int, int);
extern void func_002AB6D8(void *, void *);
extern void func_002AB800(void *, void *);
extern void func_002AB8C0(void *, void *);
extern void func_002ABBB8(void *, void *, void *, float, float, int, int, int,
                          float, float, float, float, int, float, int, int, int, int, int);
extern void func_002AEF28(float, float, void *, void *, float, void *);
extern int func_002B0C28(int, int, int);
extern void func_002E59F8(int);
extern int func_002E5DA0(int, int, void *, int);
extern void func_L00_002D2168(int, int, float);
extern void func_L01_00323310(int, int);
extern float func_L08_003277C0(int, float);
extern void func_L08_00318F90(int, void *, int);
extern void func_L08_00328BB0(s32, s32, s32, s32);
extern s32 func_L08_003391C0(u8 *, s32, s32, u8 *, f32, f32);
extern void func_L08_00339220(void *, void *, int, int, float);
extern int func_L08_002D2ED8(int, int);
extern void func_L08_0041D808(void);
extern void func_L08_0041E4F8(char *);
extern void func_L08_0041E630(float *, float *, float *, float *, float *);
extern void func_L08_0041E790(void *, void *, int, float, float, float, float, float, float);
extern void func_L08_0041EA88(void *);
extern void *func_L08_00435600(u8 *, void *);
extern void func_L08_004356A0(u8 *, void *);

#define OB(o) (*(u8 *)(obj + (o)))
#define OH(o) (*(u16 *)(obj + (o)))
#define OI(o) (*(s32 *)(obj + (o)))
#define OF(o) (*(float *)(obj + (o)))
#define DB(o) (*(u8 *)(d + (o)))
#define DH(o) (*(s16 *)(d + (o)))
#define DI(o) (*(s32 *)(d + (o)))
#define DF(o) (*(float *)(d + (o)))
#define GI(o) (*(s32 *)(D_00189E20 + (o)))
#define LI(o) (*(s32 *)(g + (o)))
#define GF(o) (*(float *)(D_00189E20 + (o)))
#define LF(o) (*(float *)(g + (o)))
#define GP(o) (*(u8 **)(D_00189E20 + (o)))
#define LP(o) (*(u8 **)(g + (o)))
#define RDEAD(i) (rp = D_00188660 + (i) * 0x70, (*(u8 **)(rp + 0x88) != obj || rp[0x74] == 0))
#define RLIVE(i) (rp = D_00188660 + (i) * 0x70, (*(u8 **)(rp + 0x88) == obj && rp[0x74] != 0))
#define FREEREC(i) if (RLIVE(i)) func_002E59F8(i)

void func_L08_0041EBF8(u8 *obj)
{
    Vec vs[12];
    float e[5];
    u8 *d = *(u8 **)(obj + 0x68);
    u8 *g = D_00189E20;
    u8 *a1, *p104, *p108, *p10C, *pF8, *pFC, *p100;
    int entered;
    u8 *rp;
    u8 st;

    if (D_001A8F00[0] == 2 || LI(0x2294) == 0x61) {
        OB(0x31) = 0;
        OH(0x34) = OH(0x34) | 1;
        return;
    }
    {
        OB(0x31) = 1;
        OH(0x34) = OH(0x34) & 0xFFFE;
        if (func_002829A8(d + 0x8B) != 0)
            DI(0xA0) = 0;
        if (OB(0x20) != 0) {
            u8 *t, *tp;
            OF(0x18) = DF(0x58);
            t = func_002A9640(obj, 1, 0);
            a1 = d + 0x90;
            if (t != 0 && (tp = *(u8 **)(t + 0x20)) != 0 && *(s16 *)(tp + 0xAA) != 0xEEF &&
                *(s16 *)(tp + 0xAA) != 0x942 && *(s16 *)(tp + 0xAA) != 0xFFF) {
                if (tp != *(u8 **)(d + 0xA0) || DB(0x8B) == 0) {
                    u8 *s0p = d + 0x90;
                    DB(0x98) = 0xD2;
                    DB(0x97) = 0xD2;
                    DB(0x99) = 0xD2;
                    func_002AB800(obj, s0p);
                    DF(0x60) = DF(0x60) - *(float *)(t + 0x2C);
                    LF(0x183C) = DF(0x60);
                    a1 = s0p;
                    if (DF(0x60) <= 0.0f)
                        OB(0x20) = 5;
                    *(u8 **)(d + 0xA0) = *(u8 **)(t + 0x20);
                    DB(0x8B) = D_001B1B64;
                }
            }
            OB(0xA8) = 0xFF;
        } else {
            a1 = d + 0x90;
            DF(0x58) = OF(0x18);
        }
        func_002AB8C0(obj, a1);
        OF(0x2C) = *(float *)(*(u8 **)(obj + 0x24) + 0x24) * D_001B19B4;
        if (GP(0x1830) == obj && OB(0x20) != 0)
            GI(0x1848) = (int)(GF(0x183C) / GF(0x1840) * 200.0f);
        else
            GI(0x1848) = 0xC8;
        entered = 0;
        if (DI(0x18C) != -1)
            func_L08_00328BB0(DI(0x18C), -1, -1, 1);
        p10C = d + 0x54;
        pF8 = d + 0x1AC;
        p108 = d + 0x50;
        switch (OB(0x20)) {
        case 2:
        case 4:
        case 6:
            break;
        case 0:
            if (OB(0x43) != 0)
                func_002A7470(obj, 0, 0, 0xA);
            if (DB(0xB1) == 0) {
                int i;
                for (i = 0; i < 3; i++)
                    func_0029F978(obj, i + 2, d + 0xB0 + i * 0x40);
            }
            p104 = obj + 0x10;
            p108 = d + 0x50;
            p10C = d + 0x54;
            pF8 = d + 0x1AC;
            DI(0xA4) = 0;
            DI(0xA8) = 0xFF;
            *(Quad *)(d + 0x30) = *(Quad *)p104;
            *(Quad *)d = 0;
            if (D_001A79F0[0] != 8) {
                if (D_001A79F0[0] != 0x13)
                    GF(0x1840) = D_001B19D0;
                else
                    GF(0x1840) = D_001B19D8;
            } else
                GF(0x1840) = D_001B19D4;
            DF(0x60) = GF(0x1840);
            GF(0x183C) = GF(0x1840);
            DI(0x74) = 0;
            OB(0x20) = 1;
            DI(0x1A4) = -1;
            DF(0x78) = 0.0f;
            DI(0x1AC) = 0;
            DI(0x1B0) = 0;
            break;
        case 1: {
            u8 *g = D_00189E20;
            if (LI(0x2294) != 0x1C && LI(0x2294) != 0x16 && LI(0x2294) != 0x39 &&
                LI(0x2294) != 0x6F && LI(0x229C) != 2 && LI(0x229C) != 4 && LI(0x229C) != 3 &&
                LI(0x229C) < 0xD && LI(0x229C) != 7 && LI(0x229C) != 0xA && LI(0x229C) != 0x10 &&
                LI(0x229C) != 5 && LI(0x2294) != 0x62 && LI(0x24CC) > 0 && D_001A8F00_gp == 0 &&
                LI(0x340) != 0 &&
                (LP(0x33C) == 0 ||
                 (*(s16 *)(LP(0x33C) + 0xAA) != 0x13E && *(s16 *)(LP(0x33C) + 0xAA) != 0x46F)) &&
                func_002A0558(obj, LP(0x2290)) < D_001B18E0 && LI(0x2294) != 0x31) {
                int ok = func_002B0C28(7, 0x2798, 1) != 0;
                if ((D_00138180[0x69] & 0x10) && ok) {
                    int r;
                    DI(0x190) = 0;
                    entered = 1;
                    func_L08_00318F90(0, func_L08_0041D808, 1);
                    func_L01_00323310(DI(0x194), DI(0x19C));
                    func_L08_002D2ED8(0x31, 0);
                    func_L00_002D2168(D_001B1918, 0, 15.0f);
                    *(Quad *)(g + 0x90) = *(Quad *)(obj + 0xF0);
                    *(Quad *)(g + 0x80) = *(Quad *)(obj + 0x10);
                    LP(0x1830) = obj;
                    OB(0x20) = 3;
                    r = DI(0x1B4);
                    if (r != -1) {
                        FREEREC(r);
                    }
                    DI(0x1B4) = -1;
                    *(s32 *)(GP(0x2290) + 0x9C) = -1;
                    *(s8 *)(D_00189E20 + 0x22B5) = 1;
                }
            }
            if (RDEAD(DI(0x1B4)))
                DI(0x1B4) = func_002E5DA0(9, 4, obj, 0x85C);
            }
            /* fallthrough */
        case 3:
            OI(0x98) = 0;
            func_00282978((short *)(d + 0x7C));
            e[4] = e[0] = e[1] = e[2] = e[3] = 0.0f;
            st = OB(0x20);
            if (st == 3) {
                *(s8 *)(D_00189E20 + 0x22B5) = 1;
                if (D_00138180[0x68] & 0x80) {
                    int b42 = OB(0x42);
                    u8 b43;
                    if ((u32)(b42 - 1) >= 3U && (b43 = OB(0x43)) != 1 && b43 != 2 && b43 != st) {
                        if (b43 != 1)
                            func_002A7470(obj, 1, 0, 0xA);
                    } else if (OB(0x60) & 2) {
                        b43 = OB(0x43);
                        if ((u8)b42 == 1) {
                            if (b43 != 2)
                                func_002A7470(obj, 2, 0, 0xA);
                        } else if ((b43 == 3 || b43 == 0) && b43 != 1) {
                            func_002A7470(obj, 1, 0, 0xA);
                        }
                    }
                    DF(0x78) = DF(0x78) - D_001B1A14;
                    if (func_002A77E0(9) == 0 || (D_00138180[0x69] & 0x80))
                        func_L08_0041E4F8(obj);
                } else {
                    if (OB(0x60) & 2) {
                        if ((u32)(OB(0x42) - 1) < 2U || OB(0x43) == 1 || OB(0x43) == 2) {
                            if (OB(0x43) != 3)
                                func_002A7470(obj, 3, 0, 0xA);
                        } else if (OB(0x43) != 0) {
                            func_002A7470(obj, 0, 0, 0xA);
                        }
                    }
                    DF(0x78) = DF(0x78) + D_001B1A18;
                }
                if (D_001B191C != D_001B1918 && D_001B1918 != -1)
                    func_L00_002D2168(D_001B1918, 0, 15.0f);
                func_L08_0041E630(&e[0], &e[1], &e[2], &e[3], &e[4]);
                e[0] *= DF(0x78);
            } else {
                DF(0x78) = DF(0x78) - D_001B1A14;
                if (OB(0x60) & 2) {
                    if ((u32)(OB(0x42) - 1) < 2U || OB(0x43) == 1 || OB(0x43) == 2) {
                        if (OB(0x43) != 3)
                            func_002A7470(obj, 3, 0, 2);
                    } else if (OB(0x43) != 0) {
                        func_002A7470(obj, 0, 0, 2);
                    }
                }
            }
            if (DF(0x78) > 1.0f)
                DF(0x78) = 1.0f;
            else if (DF(0x78) < 0.0f)
                DF(0x78) = 0.0f;
            {
                float sgn = 1.0f;
                float f25, f21, f22, f20, f0, f6, f21b, m, den;
                int s0, s4;
                int i;
                float *sp104f;

                e[1] = e[1] * DF(0x78);
                e[3] += 1.0f - DF(0x78);
                e[4] *= DF(0x78);
                f25 = D_001B190C * DF(0x78) + D_001B1A1C * (1.0f - DF(0x78));
                if (OB(0x20) == 3)
                    f25 = D_001B190C * DF(0x78) + D_001B1A20 * (1.0f - DF(0x78));
                DF(0x5C) = e[1];
                e[2] = e[2] * 0.017453294f * D_001B1948;
                f21 = func_00282DF0(d) * DF(0x78);
                den = D_001B1950 * 0.016666668f;
                m = den < f21 ? den : f21;
                f22 = D_001B1908 * 0.016666668f;
                DF(0x28) = func_00283B98(DF(0x28),
                    D_001B18F8 * (e[0] * (((m / den) * D_001B194C) + (1.0f - D_001B194C) +
                    (D_001B1A24 * (1.0f - DF(0x78)))) * 0.00029088825f));
                DF(0x20) = DF(0x20) + (((D_001B1930 * (e[0] * 0.017453294f) * DF(0x78) *
                    ((D_001B193C * e[1]) + (1.0f - D_001B193C))) - OF(0xF0)) * D_001B192C);
                vs[0].f[0] = func_00283180(DF(0x28));
                vs[0].f[1] = func_00283198(DF(0x28));
                vs[0].f[2] = 0.0f;
                if (e[1] < vs[0].f[2])
                    e[1] *= D_001B1934;
                if (e[1] < vs[0].f[2])
                    sgn = -1.0f;
                p104 = obj + 0x10;
                p108 = d + 0x50;
                p10C = d + 0x54;
                f0 = func_00282C48(e[0]);
                pF8 = d + 0x1AC;
                f6 = func_L08_003277C0(2, (f22 - f21) / f22);
                pFC = (u8 *)&vs[2];
                p100 = (u8 *)&vs[4];
                DF(0x180) = DF(0x78) * 0.00029088825f * D_001B18D0;
                f21b = (e[1] + (D_001B1938 * f0 * sgn)) * 0.00027777778f * D_001B1904 * f6;
                {
                    float *w = (float *)(d + 0x184);
                    i = 1;
                    do {
                        int odd = i & 1;
                        float t = (f21 / f22) + e[1];
                        float x;
                        if (odd == 0)
                            x = t - e[0];
                        else
                            x = t + e[0];
                        x = x * (D_001B18D8 * 0.00029088825f) * 0.5f;
                        if (odd != 0)
                            x = -x;
                        *w = x;
                        i++;
                        w++;
                    } while (i < 3);
                }
                {
                    float *pa = (float *)(d + 0x180);
                    float *pb = (float *)(d + 0x170);
                    u8 *pc = d + 0xC0;
                    i = 0;
                    do {
                        float f13 = *pa;
                        float r;
                        int sel;
                        pa++;
                        r = func_00283B98(*pb, f13);
                        *pb = r;
                        sel = (i == 0) ? 2 : 0;
                        i++;
                        func_00283898(pc, sel, r);
                        pc += 0x40;
                        pb++;
                    } while (i < 3);
                }
                s0 = 0;
                func_00282CC0(pFC, p104, d);
                f20 = func_002A89A8(pFC, 0, 0.5f);
                if (func_00278E78() == 1 || func_00278E78() == 0xB)
                    s0 = 1;
                f0 = f20 + f25;
                if (OF(0x18) < f0 + 0.3f && s0 != 0)
                    OB(0x20) = 5;
                s4 = 1;
                DF(8) = DF(8) - D_001B1920 * 0.00027777778f;
                if (f20 != 0.0f) {
                    u8 *s3;
                    func_00282F20(&vs[5], D_001BFF80, 1.0f);
                    func_00282DD8(p100, obj + 0xC0, &vs[5]);
                    func_00282DD8(&vs[3], p100, &vs[5]);
                    vs[6].q = 0;
                    func_002AB6D8(&vs[3], &vs[7]);
                    s3 = obj + 0xC0;
                    DF(0x24) = func_00283B98(DF(0x24),
                        func_00283BE0(func_00283B98(-vs[7].f[1], e[2] * 0.5f *
                        (D_001B1A28 * (DF(0x78) + 1.0f))), DF(0x24)) * D_001B1940);
                    if (vs[2].f[2] < f0 + 0.2f) {
                        float f2, f1;
                        s4 = 0;
                        if ((vs[2].f[2] + 0.1f) < f20 || s0 != 0) {
                            vs[2].f[2] = f20;
                            func_00282D30(d, d, D_001B1928);
                        }
                        f2 = D_001B1910;
                        f1 = DF(8);
                        DF(8) = f1 + ((((f0 - vs[2].f[2]) * f2) - f1) * f2);
                        if (e[3] > 0.0f) {
                            f1 = 1.0f - (D_001B1954 * e[3]);
                            DF(4) = DF(4) * f1;
                            DF(0) = DF(0) * f1;
                        }
                        func_00282D30(d, d, D_001B18FC);
                        func_00283698(&vs[8], s3);
                        func_002830C0(d, d, &vs[8]);
                        DF(4) = DF(4) * D_001B1900;
                        func_00283098(d, d, s3);
                    }
                    func_00282F20(&vs[1], s3, f21b);
                    if (DF(0x24) < -0.78539824f) {
                        if (vs[1].f[2] > 0.0f)
                            vs[1].f[2] = 0.0f;
                        func_00282F20(&vs[1], &vs[1], f21b);
                    } else {
                        float t = D_001B1920 * 0.000069444446f;
                        if (t < vs[1].f[2])
                            vs[1].f[2] = t;
                        func_00282F20(&vs[1], &vs[1], f21b);
                    }
                    func_00282F20(&vs[8], obj + 0xD0, D_001B1A30 * (e[4] * 0.00027777778f) * DF(0x78));
                    func_00282CC0(&vs[1], &vs[1], &vs[8]);
                    func_00282CC0(d, d, &vs[1]);
                }
                *(Quad *)p104 = *(Quad *)pFC;
                func_0029FCC0(obj, 0, &vs[3]);
                vs[3].f[2] += D_001B1914 - D_001B1A1C;
                func_00282CF0(p100, p104, &vs[3]);
                OI(0x98) = 0;
                i = func_00278870(&vs[3], D_001B1914);
                if (i == 0) {
                    float f12 = D_001B1914;
                    if (D_001A79F0[0] == 0x13) {
                        s32 sv = *(s32 *)(GP(0x2290) + 0x98);
                        *(s32 *)(GP(0x2290) + 0x98) = 0;
                        i = func_00277258((float *)&vs[3], 0, f12, obj);
                        *(s32 *)(GP(0x2290) + 0x98) = sv;
                    } else {
                        i = func_00277258((float *)&vs[3], 2, f12, obj);
                    }
                }
                OI(0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
                if (i != 0) {
                    if (func_00278E78() == 1 || func_00278E78() == 0xB)
                        OB(0x20) = 5;
                    if (*(u8 **)(D_001BFF40 + 0x18) != GP(0x2290)) {
                        float f20b = 1.0f;
                        u8 *s0p;
                        if (s4 != 0) {
                            float f3 = *(float *)(D_001BFF40 + 0x30) - vs[3].f[0];
                            float f1;
                            *(float *)(D_001BFF40 + 0x30) = f3;
                            *(float *)(D_001BFF40 + 0x34) = *(float *)(D_001BFF40 + 0x34) - vs[3].f[1];
                            if (f3 < 0.050000004f)
                                *(float *)(D_001BFF40 + 0x30) = f3 * DF(0x78);
                            f1 = *(float *)(D_001BFF40 + 0x34);
                            if (f1 < 0.050000004f)
                                *(float *)(D_001BFF40 + 0x34) = f1 * DF(0x78);
                            *(float *)(D_001BFF40 + 0x30) = *(float *)(D_001BFF40 + 0x30) + vs[3].f[0];
                            *(float *)(D_001BFF40 + 0x34) = *(float *)(D_001BFF40 + 0x34) + vs[3].f[1];
                        } else {
                            f20b = DF(0x78);
                        }
                        func_00282CC0(p104, D_001BFF70, p100);
                        s0p = D_001BFF70 + 0x10;
                        func_00282DD8(&vs[6], s0p, d);
                        func_00282DD8(&vs[5], &vs[6], s0p);
                        func_00282F20(&vs[5], &vs[5], 1.0f);
                        func_00282F20(d, &vs[5], func_00282DB0(d, &vs[5]) * f20b);
                        func_00282D30(d, d, D_001B1924);
                        if (OF(0x18) < DF(0x17C))
                            OB(0x20) = 5;
                    }
                }
            }
            if (OB(0x20) == 3) {
                float f1 = OF(0x18);
                if (f1 < *(float *)(D_001BFF40 + 0x28))
                    *(float *)(D_001BFF40 + 0x28) = f1;
                if (DF(0x78) < 0.98f && (D_00138180[0x68] & 0x80)) {
                    if (DI(0x1A8) == 0) {
                        if (DI(0x1AC) == 0)
                            func_002E5DA0(1, 0, obj, 0x85C);
                        DI(0x1A8) = 2;
                        DI(0x1AC) = 0xF;
                    } else if (DI(0x1A8) == 2) {
                        if (RDEAD(DI(0x1A4))) {
                            int r;
                            DI(0x1A4) = func_002E5DA0(2, 4, obj, 0x85C);
                            r = DI(0x1B4);
                            if (r != -1) {
                                FREEREC(r);
                            }
                            DI(0x1B4) = -1;
                        }
                    }
                    if (DF(0x68) < D_001B031C) {
                        func_L08_0041E790(obj, D_001BFF60, D_001B1B40, D_001B1B38, D_001B1B3C, D_001B1B34, D_001B1B34,
                                          D_001B1B44, D_001B1B48);
                        if (func_002A77E0(0xB) == 0) {
                            *(s32 *)(D_001B99C0 + 0x168) = 0xF;
                            *(s32 *)(D_001B99C0 + 0x16C) = 0;
                            *(float *)(D_001B99C0 + 0x160) = (1.0f - DF(0x78)) * 0.05f;
                        }
                    } else {
                        func_L08_0041E790(obj, D_001BFF60, D_001B1B58, D_001B1B50, D_001B1B54, D_001B1B4C, D_001B1B4C,
                                          D_001B1B5C, D_001B1B60);
                    }
                    {
                        int r = DI(0x1B4);
                        if (r != -1) {
                            FREEREC(r);
                        }
                    }
                    DI(0x1B4) = -1;
                } else {
                    if (DI(0x1A8) == 2) {
                        int r = DI(0x1A4);
                        if (r != -1) {
                            FREEREC(r);
                        }
                        DI(0x1A4) = -1;
                        if (DI(0x1AC) == 0)
                            func_002E5DA0(4, 0, obj, 0x85C);
                        DI(0x1A8) = 0;
                        DI(0x1AC) = 0xF;
                    } else {
                        if (RDEAD(DI(0x1B4)))
                            DI(0x1B4) = func_002E5DA0(9, 4, obj, 0x85C);
                    }
                }
                func_L08_0041E790(obj, D_001BFF60, D_001B1B28, D_001B1B20, D_001B1B24, D_001B1B1C, D_001B1B2C, D_001B1B30, 1.0f);
            }
            func_0029FCC0(obj, 0, &vs[3]);
            {
                float f12 = D_001B19B8;
                vs[3].f[2] += D_001B19C8;
                switch (D_001A79F0[0]) {
                case 19:
                    f12 = D_001B19C0;
                    break;
                case 8:
                    f12 = D_001B19BC;
                    break;
                }
                func_002A8C00(&vs[5], obj, 0x10000, f12, d);
            }
            func_00277F48(D_001B1958, &vs[3], 0, obj, &vs[5]);
            if (D_001B19CC * 0.016666668f < func_00282DF0(d)) {
                func_0029FCC0(obj, 1, &vs[8]);
                func_00277F48(D_001B19C4, &vs[8], 0, obj, &vs[5]);
            }
            if (entered == 0 && GP(0x1830) == obj && (D_00138180[0x69] & 0x10)) {
                func_L08_0041EA88(obj);
                OB(0x20) = 1;
                if (RDEAD(DI(0x1B4)))
                    DI(0x1B4) = func_002E5DA0(9, 4, obj, 0x85C);
            }
            break;
        case 5:
            func_L08_0041EA88(obj);
            func_0029FCC0(obj, 0, &vs[0]);
            func_002ABBB8(obj, d, &vs[0], 0.0f, 0.0f, 0xA, 3, 0x10, 4.0f, 2.0f, 9.0f, 1.0f, -1, 15.0f,
                          1, 1, -1, 0, 0x810001);
            *(Quad *)(obj + 0x10) = *(Quad *)(d + 0x30);
            OB(0x20) = 0;
            p108 = d + 0x50;
            p10C = d + 0x54;
            pF8 = d + 0x1AC;
            break;
        }
        DF(0x58) = OF(0x18);
        DF(0x48) = func_00283B98(DF(0x48), D_001B18E8 * (DF(0x78) * 0.00029088825f));
        DF(0x4C) = func_00283198(DF(0x48)) * D_001B18E4 * DF(0x78);
        OF(0x18) = OF(0x18) + DF(0x4C) * DF(0x78);
        {
            float t = DF(0x78) * 0.00029088825f;
            func_002AEF28(D_001B18EC * 0.017453294f, D_001B18F0 * t, obj, p108, D_001B18F4 * t, p10C);
        }
        OF(0xF8) = DF(0x28);
        OF(0xF0) = func_00283B98(OF(0xF0), DF(0x20));
        OF(0xF4) = func_00283B98(OF(0xF4), DF(0x24));
        st = OB(0x20);
        if (st == 3) {
            if (D_001A79F0[0] == 8 || D_001A79F0[0] == 0x13) {
                u8 b = DB(0x8A);
                int n;
                u8 *a1p, *a0p;
                switch (b) {
                case 0:
                    if (DF(0x68) < D_001B031C) {
                        DB(0x8A) = 1;
                        DH(0x88) = 0;
                    }
                    break;
                case 1:
                    DH(0x88) = (u16)DH(0x88) + 1;
                    if (D_001B1A78 < DH(0x88))
                        DH(0x88) = (u16)D_001B1A78;
                    if (D_001B031C < DF(0x68))
                        DB(0x8A) = st;
                    else if (DH(0x88) >= D_001B1A78)
                        DB(0x8A) = 2;
                    break;
                case 2:
                    if (D_001B031C < DF(0x68))
                        DB(0x8A) = st;
                    break;
                default:
                    if (b == st) {
                        func_00282978((short *)(d + 0x88));
                        if (!(DF(0x68) < D_001B031C)) {
                            if (DH(0x88) == 0)
                                DB(0x8A) = 0;
                        } else {
                            DB(0x8A) = 1;
                        }
                    }
                    break;
                }
                n = 0x200;
                if (DB(0x8A) != 0) {
                    u8 *p = *(u8 **)(d + 0x6C);
                    if (p != 0) {
                        u8 *q = *(u8 **)(p + 0x68);
                        float f20 = func_00283CE0(*(s32 *)(q + 4));
                        n = func_00283CF0((D_001B19E4 * f20) / (func_00283CE0(*(s32 *)q) * 60.0f));
                    }
                }
                DH(0x8C) = n;
                a1p = *(u8 **)(d + 0x6C);
                a0p = *(u8 **)(d + 0x74);
                if (a1p != 0) {
                    if (a0p == 0)
                        *(u8 **)(d + 0x74) = (u8 *)func_L08_00435600(obj, (void *)(a1p + 0x10));
                    else
                        func_L08_004356A0(a0p, a1p + 0x10);
                } else if (a0p != 0) {
                    func_0029F338(a0p);
                    *(u8 **)(d + 0x74) = 0;
                }
            }
            func_00282F20(&vs[0], obj + 0xC0, -0.5f);
            if (vs[0].f[2] < 0.0f)
                vs[0].f[2] = 0.0f;
            vs[0].f[2] += 1.5f;
            func_00282CC0(D_00189EA0, &vs[0], obj + 0x10);
            *(Quad *)(D_00189EA0 + 0x250) = *(Quad *)D_00189EA0;
            *(float *)(D_00189EA0 + 0x258) = OF(0x18);
            *(Quad *)(D_00189EA0 + 0x10) = *(Quad *)(obj + 0xF0);
        }
        OI(0x98) = *(s32 *)(*(u8 **)(obj + 0x24) + 0x10);
        if (OB(0x31) != 0 && func_00282E48(obj + 0x10, D_001B9B00) < 64.0f) {
            func_002A93B0(obj);
            OB(0x6F) = 0x3C;
        }
        if (DI(0x18C) != -1)
            func_L08_00328BB0(DI(0x18C), -1, 0, 0);
        if (DF(0x5C) != 0.0f) {
            u8 *s0 = d + 0x1C0;
            if (RDEAD(DI(0x1A4))) {
                int v = func_002E5DA0(0, 4, obj, 0x85C);
                DI(0x1A4) = v;
                func_L08_003391C0(obj, v, 0, s0, D_001B1B7C, D_001B1B80);
            } else {
                int r;
                func_00282CF0(&vs[0], obj + 0x10, s0);
                vs[0].f[2] = 0.0f;
                func_L08_00339220(obj, s0, D_001B1A44, D_001B1A48, func_00282DF0(&vs[0]));
                r = DI(0x1B4);
                if (r != -1) {
                    FREEREC(r);
                }
                DI(0x1B4) = -1;
            }
        } else {
            if (DI(0x1A8) != 2) {
                int r = DI(0x1A4);
                if (r != -1) {
                    FREEREC(r);
                }
                DI(0x1A4) = -1;
            }
        }
        func_00282948(pF8);
    }
}
