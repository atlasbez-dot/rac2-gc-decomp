/* func_L11_00444400 (L11 only, 4,684 B): draws the level's race/timer HUD: six text boxes laid out
 * from the level's box table (each coordinate scaled by D_L11_001B3E04 and rounded), then per mode
 * (pvars + 0x1F0 == 5, 9, 8, 12, else) the titles, the time or count via sprintf (func_115DA8) and
 * strlen (func_1157AC), and the boss health bar (func_004442B0).
 * Opus handoff (big21 slate), DRAFT: about 388 of 1171 instructions aligned, size 1158/1171.
 * Profile so far: -O2 -G8 -ffunction-sections -mno-split-addresses (retail reads the scale and the
 *   box table's lui-form fields as `lui $at; lwc1 %lo($at)` macros, the $gp-form ones as sda scalars;
 *   d_001A904C is an sda array: lui form normally, $gp form in delay slots).
 * Blocker: retail computes each box's three scaled values strictly one after another
 *   (cvt.s.w, mul.s, add.s, cvt.w.s, mfc1 into the argument register, f0/f2 reused), with the scale
 *   loaded once per box; ours interleaves them (sched1, and sched2 after it), also with an inline
 *   Scale() helper. -fno-schedule-insns, -O1 and -g don't reproduce it. Find what serialises them
 *   before spelling the rest. The draft still uses TITLE/LABEL/SUM/DRAW macros for the repeated
 *   blocks; expand them when it matches. Twin: func_L02_003FE8B8 (0.78 opcode-similar, unmatched).
 */
#include "common.h"

typedef struct {
    s32 w[8];
} Rect;

extern s32 D_L11_001A904C[] __attribute__((sda));
extern f32 D_L11_001B3E04;
extern f32 D_L11_001BEDC0[];
extern char D_L11_001B17E8[];
extern char D_L11_001B17F0[];
extern char D_L11_001B17F8[];
extern char D_L11_001B1800[];
extern s32 D_L11_001B14B8[] __attribute__((sda));
extern s32 D_L11_001B14D0[] __attribute__((sda));
extern s32 D_L11_001B14D8[] __attribute__((sda));
extern s16 *D_L11_001B14F8[] __attribute__((sda));
extern s32 D_L11_001B1718 __attribute__((sda));

extern s32 D_L11_001B1798 __attribute__((sda));
extern s32 D_L11_001B179C __attribute__((sda));
extern s32 D_L11_001B17A0 __attribute__((sda));
extern s32 D_L11_001B17A4[];
extern s32 D_L11_001B17A8[];
extern s32 D_L11_001B17AC[];
extern s32 D_L11_001B1780 __attribute__((sda));
extern s32 D_L11_001B1784 __attribute__((sda));
extern s32 D_L11_001B1788 __attribute__((sda));
extern s32 D_L11_001B178C[];
extern s32 D_L11_001B1790[];
extern s32 D_L11_001B1794[];
extern s32 D_L11_001B1738 __attribute__((sda));
extern s32 D_L11_001B173C __attribute__((sda));
extern s32 D_L11_001B1740 __attribute__((sda));
extern s32 D_L11_001B1744[];
extern s32 D_L11_001B1748[];
extern s32 D_L11_001B174C[];
extern s32 D_L11_001B171C __attribute__((sda));
extern s32 D_L11_001B1720 __attribute__((sda));
extern s32 D_L11_001B1728 __attribute__((sda));
extern s32 D_L11_001B172C[];
extern s32 D_L11_001B1730[];
extern s32 D_L11_001B1734[];
extern s32 D_L11_001B1768 __attribute__((sda));
extern s32 D_L11_001B176C __attribute__((sda));
extern s32 D_L11_001B1770 __attribute__((sda));
extern s32 D_L11_001B1774[];
extern s32 D_L11_001B1778[];
extern s32 D_L11_001B177C[];
extern s32 D_L11_001B1750 __attribute__((sda));
extern s32 D_L11_001B1754 __attribute__((sda));
extern s32 D_L11_001B1758 __attribute__((sda));
extern s32 D_L11_001B175C[];
extern s32 D_L11_001B1760[];
extern s32 D_L11_001B1764[];

extern s32 D_L11_001B17B0 __attribute__((sda));
extern s32 D_L11_001B17B4 __attribute__((sda));
extern s32 D_L11_001B17B8 __attribute__((sda));
extern s32 D_L11_001B17BC __attribute__((sda));
extern s32 D_L11_001B17C0 __attribute__((sda));
extern f32 D_L11_001B17C4 __attribute__((sda));
extern f32 D_L11_001B17C8 __attribute__((sda));
extern f32 D_L11_001B17CC __attribute__((sda));
extern f32 D_L11_001B17D0 __attribute__((sda));
extern f32 D_L11_001B17D4 __attribute__((sda));
extern f32 D_L11_001B17D8 __attribute__((sda));
extern f32 D_L11_001B17DC __attribute__((sda));
extern s32 D_L11_001B17E0 __attribute__((sda));
extern s32 D_L11_001B17E4 __attribute__((sda));

extern void func_002F6B90(void);
extern void func_002FBF70(Rect *, s32, char *, s32);
extern void func_002FBFE0(Rect *, s32, char *, s32);
extern void func_002FC050(Rect *, s32, char *, s32);
extern void func_002FC0C0(Rect *, s32, s32, s32, s32, s32, s32, s32, s32);
extern f32 func_003016F0(s32);
extern char *func_00306B18(s32);
extern void func_0038FD70(u32, u64);
extern void func_00390018(void);
extern void func_00394D98(char *, s32, f32, f32, f32, f32, f32);
extern void func_004442B0(f32);
extern char *func_0048DFD0(s32, s32);
extern s32 func_1157AC(char *);
extern s32 func_115DA8(char *, char *, ...);

static inline s32 Scale(f32 v)
{
    return v * D_L11_001B3E04 + 0.5f;
}


#define TITLE() \
        func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4C), D_L11_001B17E4, D_L11_001B17D0, \
                      Scale(D_L11_001B17D4), -1.0f, D_L11_001B17C4, 0.0f); \
        func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4D), D_L11_001B17E0, D_L11_001B17D0, \
                      Scale(D_L11_001B17D4), -1.0f, D_L11_001B17C4, 0.0f)
#define LABEL() \
            func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4C), D_L11_001B17E4, D_L11_001B17C8, \
                          Scale(D_L11_001B17CC), D_L11_001B17C4, 1.0f, 0.0f); \
            func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4D), D_L11_001B17E0, D_L11_001B17C8, \
                          Scale(D_L11_001B17CC), D_L11_001B17C4, 1.0f, 0.0f)
#define LABEL50() \
            func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x50), D_L11_001B17E0, D_L11_001B17BC, \
                          Scale(D_L11_001B17C0), D_L11_001B17C4, 1.0f, 0.0f)
#define SUM() \
            sum = 0; \
            for (i = 0; i < 8; i++) { \
                sum += ((s32 *)(data + 0x100))[i]; \
            }
#define DRAW(fn, r, s) \
            str = (s); \
            fn((r), D_L11_001B1718, str, func_1157AC(str))
#define sprintf_n func_115DA8

void func_L11_00444400(u8 *moby)
{
    char buf[0x40];
    Rect r50;
    Rect r70;
    Rect r90;
    Rect rB0;
    Rect rD0;
    Rect rF0;
    u8 *data;
    u8 *obj;
    u8 *pv;
    f32 save;
    s32 sum;
    s32 i;
    s32 n;
    s32 t;
    char *str;

    if (D_L11_001A904C[0] == 0) {
        return;
    }
    func_00390018();
    data = *(u8 **)(moby + 0x68);
    func_002FC0C0(&r50, Scale(D_L11_001B17A0), Scale(D_L11_001B17A4[0]),
                  D_L11_001B17A8[0], D_L11_001B17AC[0], D_L11_001B1798, Scale(D_L11_001B179C), 0, 3);
    func_002FC0C0(&r70, Scale(D_L11_001B1788), Scale(D_L11_001B178C[0]),
                  D_L11_001B1790[0], D_L11_001B1794[0], D_L11_001B1780, Scale(D_L11_001B1784), 0, 3);
    func_002FC0C0(&r90, Scale(D_L11_001B1740), Scale(D_L11_001B1744[0]),
                  D_L11_001B1748[0], D_L11_001B174C[0], D_L11_001B1738, Scale(D_L11_001B173C), 0, 3);
    func_002FC0C0(&rB0, Scale(D_L11_001B1728), Scale(D_L11_001B172C[0]),
                  D_L11_001B1730[0], D_L11_001B1734[0], D_L11_001B171C, Scale(D_L11_001B1720), 0, 3);
    func_002FC0C0(&rF0, Scale(D_L11_001B1770), Scale(D_L11_001B1774[0]),
                  D_L11_001B1778[0], D_L11_001B177C[0], D_L11_001B1768, Scale(D_L11_001B176C), 0, 3);
    func_002FC0C0(&rD0, Scale(D_L11_001B1758), Scale(D_L11_001B175C[0]),
                  D_L11_001B1760[0], D_L11_001B1764[0], D_L11_001B1750, Scale(D_L11_001B1754), 0, 3);
    save = D_L11_001BEDC0[0xB0 / 4];
    D_L11_001BEDC0[0xB0 / 4] = 0.62f;
    func_002F6B90();
    if (*(s16 *)(data + 0x1F0) == 5) {
        TITLE();
        sprintf_n(buf, D_L11_001B17E8, 0x5A - *(s32 *)(data + 0x188) / 60);
        DRAW(func_002FC050, &r90, buf);
        DRAW(func_002FBF70, &rB0, func_00306B18(0x2F63));
        LABEL();
        SUM();
        func_115DA8(buf, D_L11_001B17E8, D_L11_001B14B8[*(s16 *)(data + 0x1F2)] + sum - *(s32 *)(data + 0x140));
        DRAW(func_002FC050, &r50, buf);
        DRAW(func_002FBF70, &r70, func_00306B18(0x2F61));
    } else if (*(s16 *)(data + 0x1F0) == 9) {
        TITLE();
        t = *(s32 *)(data + 0x188);
        func_115DA8(buf, D_L11_001B17F0, 2 - t / 3600, 0x3B - t / 60 % 60);
        DRAW(func_002FBFE0, &r90, buf);
        DRAW(func_002FBF70, &rB0, func_00306B18(0x2F63));
        LABEL();
        LABEL50();
        pv = *(u8 **)(*(u8 **)(data + 0x180) + 0x68);
        func_004442B0(*(f32 *)(pv + 0x20) / func_003016F0(*(s16 *)(pv + 0x24)));
        func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0xE3), D_L11_001B17B0, D_L11_001B17B4, D_L11_001B17B8, D_L11_001B17C4, 1.0f, 1.0f);
    } else if (*(s16 *)(data + 0x1F0) == 8) {
        TITLE();
        sprintf_n(buf, D_L11_001B17E8, 0x3C - *(s32 *)(data + 0x188) / 60);
        DRAW(func_002FC050, &r90, buf);
        DRAW(func_002FBF70, &rB0, func_00306B18(0x2F63));
        LABEL();
        SUM();
        func_115DA8(buf, D_L11_001B17E8, D_L11_001B14D0[*(s16 *)(data + 0x1F2)] + sum - *(s32 *)(data + 0x140));
        DRAW(func_002FC050, &r50, buf);
        DRAW(func_002FBF70, &r70, func_00306B18(0x2F61));
    } else if (*(s16 *)(data + 0x1F0) == 0xC) {
        TITLE();
        n = 100 - *(s32 *)(data + 0x188) / 60;
        func_115DA8(buf, D_L11_001B17E8, n);
        if (n >= 100) {
            DRAW(func_002FBF70, &r90, buf);
        } else {
            DRAW(func_002FC050, &r90, buf);
        }
        DRAW(func_002FBF70, &rB0, func_00306B18(0x2F63));
        if (moby[0xBC] != 0) {
            LABEL();
            SUM();
            if (moby[0xBC] < 2) {
                func_115DA8(buf, D_L11_001B17E8, D_L11_001B14D8[*(s16 *)(data + 0x1F2)] + sum - *(s32 *)(data + 0x140));
                DRAW(func_002FC050, &r50, buf);
            } else {
                func_115DA8(buf, D_L11_001B17E8, 100);
                DRAW(func_002FBF70, &r50, buf);
            }
            DRAW(func_002FBF70, &r70, func_00306B18(0x2F61));
        }
    } else {
        if (*(u8 **)(data + 0x180) != 0) {
            LABEL();
            LABEL50();
            obj = *(u8 **)(data + 0x180);
            if (*(s16 *)(obj + 0xAA) == 0xB3A) {
                pv = *(u8 **)(obj + 0x68);
                func_004442B0(*(f32 *)(pv + 0x20) / func_003016F0(*(s16 *)(pv + 0x24)));
                func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0xE3), D_L11_001B17B0, D_L11_001B17B4, D_L11_001B17B8, D_L11_001B17C4, 1.0f, 2.0f);
            } else if (*(s16 *)(obj + 0xAA) == 0xD4A) {
                pv = *(u8 **)(obj + 0x68);
                if (*(f32 *)(pv + 0x20) > 0.0f) {
                    func_004442B0(*(f32 *)(pv + 0x20) / func_003016F0(*(s16 *)(pv + 0x24)));
                }
                func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0xE3), D_L11_001B17B0, D_L11_001B17B4, D_L11_001B17B8, D_L11_001B17C4, 1.0f, 1.0f);
            }
        }
        func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4E), D_L11_001B17E4, D_L11_001B17D8,
                      Scale(D_L11_001B17DC), -1.0f, D_L11_001B17C4, 0.0f);
        func_00394D98(func_0048DFD0(D_L11_001A904C[0] + 0x8710, 0x4F), D_L11_001B17E0, D_L11_001B17D8,
                      Scale(D_L11_001B17DC), -1.0f, D_L11_001B17C4, 0.0f);
        if (*(s16 *)(data + 0x1F0) == 0xA) {
            func_115DA8(buf, D_L11_001B17F8, *(s16 *)(data + 0x1F2) + 1);
        } else {
            func_115DA8(buf, D_L11_001B1800, *(s16 *)(data + 0x1F2) + 1, *D_L11_001B14F8[*(s16 *)(data + 0x1F0)]);
        }
        DRAW(func_002FC050, &rF0, buf);
        DRAW(func_002FBF70, &rD0, func_00306B18(0x2F60));
    }
    func_0038FD70(0x47, 0x5360B);
    func_0038FD70(0x47, 0x5360B);
    D_L11_001BEDC0[0xB0 / 4] = save;
    func_002F6B90();
}
