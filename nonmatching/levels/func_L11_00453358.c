/* func_L11_00453358 (4,524 B, 1 place): Opus first draft (big33, 2026-10-26).
 * Profile: -O2 -G8 -ffunction-sections in its own -g8.c unit ($gp reads of
 * D_L11_001A8FF4 and D_L11_001B1D40; D_L11_001B1D44/48 are absolute).
 * 1127/1131 instructions, 933 aligned with registers (big25 scorer).
 * All twelve states, the shared tail and the jump table are retail's; the
 * case-14 loop is written with indexed expressions so gcse hoists
 * pv+0x1B0 / self+0xC0 / self+0xF0 (retail's 0x88/0x8C/0x90 spills).
 * Remaining:
 *  - frame 0x100 vs 0x110: retail spills self+0x10 (pos) to 0x84 and keeps
 *    case 14's &m in $fp; here the pos pseudo wins $fp in global alloc, so
 *    every pos use is a register instead of lw 0x84($sp).
 *  - pv lands in $s1, retail $s3 (two higher-priority pseudos take $s0/$s1
 *    first in retail: case 7's index and case 11's hero %hi anchor).
 *  - the entry copy from the hero (lq a0 from D_00189E20+0x80 with the base
 *    rederived as v0-0x80) folds into lq v0,0x80(v1) here.
 *  - case 3 keeps self->0xBC in a0 with an andi 0xFF (a u8 local) in retail.
 */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));
typedef union { u8 b[0x2600]; s16 h[0x1300]; s32 i[0x980]; f32 f[0x980]; u8 *ptr[0x980]; TI128 q[0x260]; } Hero;

extern char D_00189E20[];
extern s32 D_L11_001A8FF4 __attribute__((sda));
extern f32 D_L11_001B1D40 __attribute__((sda));
extern f32 D_L11_001B1D44;
extern f32 D_L11_001B1D48;
extern u8 *D_L11_001FF580[];

extern s32 func_002F0318(void *, void *, s32, u8 *, s32);
extern s32 func_002F1378(void *, s32, u8 *, f32);
extern f32 func_00300450(f32);
extern void func_003004E0(void *, void *, void *);
extern void func_00300510(void *, void *, void *);
extern void func_00300580(void *, void *, f32);
extern f32 func_003006B8(void *, void *);
extern f32 func_003006F0(void *, void *);
extern void func_003007F8(void *, void *, f32);
extern void func_00300BD0(f32, f32);
extern void func_00300D78(void *, void *);
extern f32 func_003015A8(f32, f32);
extern void func_0032BA0C(u8 *);
extern void func_0032C700(u8 *, s32, s32, s32);
extern void func_0032C9E0(u8 *, s32, s32);
extern s32 func_0032CAB0(s32);
extern f32 func_0032CB48(f32, f32);
extern void func_0032CD98(void *, f32, f32);
extern void func_0032E480(u8 *, void *, s32, f32, f32, f32, s32, s32, s32);
extern void func_0032E5C8(u8 *, s32, s32, f32, f32, f32, s32, s32, s32);
extern f32 func_0032FC98(f32, f32, f32);
extern void func_00330130(void *, void *, f32, f32, f32, f32);
extern void func_003313B8(void *, void *);
extern s32 func_0033C290(u8 *);
extern s32 func_0033C2B8(u8 *);
extern void func_0033D328(u8 *, void *, f32, f32, f32);
extern void func_0033E3F0(u8 *, void *);
extern void func_0033E520(u8 *, void *, f32);
extern void func_0033E7C8(u8 *, void *);
extern void func_0033F660(u8 *, f32, f32, f32, f32);
extern void func_003402D0(u8 *, void *);
extern void func_0034D250(void *, s32, s32, s32, s32, void *, s32, f32, f32, f32);
extern u8 *func_L11_004417E8(s32);
extern s32 func_L11_00441808(s32, void *);
extern void func_L11_00441A38(u8 *, s32, s32);
extern void func_L11_00454508(u8 *);
extern void func_L11_00454AE0(u8 *);
extern void func_L11_00454DD8(u8 *);

void func_L11_00453358(u8 *self)
{
    f32 v00[4];
    f32 v10[4];
    f32 v20[4];
    f32 v30[4];
    f32 m[4][4];
    u8 *pv;
    u8 *target;
    f32 dist;

    pv = *(u8 **)(self + 0x68);
    if (self[0x20] == 1)
        return;
    if (*(s16 *)(pv + 0x1FC) != 0 && D_L11_001A8FF4 == 0 && self[0x20] != 0xE && self[0x20] != 0xD)
        return;
    func_L11_00454508(self);
    if (*(u8 **)(pv + 0x1C4) != 0) {
        *(TI128 *)v00 = *(TI128 *)(*(u8 **)(pv + 0x1C4) + 0x10);
        func_00300BD0(*(f32 *)(*(u8 **)(pv + 0x1C4) + 0x10) - *(f32 *)(self + 0x10),
                      *(f32 *)(*(u8 **)(pv + 0x1C4) + 0x14) - *(f32 *)(self + 0x14));
    } else {
        *(TI128 *)v00 = ((Hero *)D_00189E20)->q[0x80 / 16];
        func_00300BD0(((Hero *)D_00189E20)->f[0x80 / 4] - *(f32 *)(self + 0x10),
                      ((Hero *)D_00189E20)->f[0x84 / 4] - *(f32 *)(self + 0x14));
    }
    dist = func_003006B8((self + 0x10), v00);
    if (self[0x20] == 1)
        return;
    if (*(s16 *)(pv + 0x1FC) != 0 && D_L11_001A8FF4 == 0)
        return;
    target = 0;
    if (*(s32 *)(self + 0xB8) != 0)
        target = func_L11_004417E8(*(s32 *)(self + 0xB8));

    switch (self[0x20]) {
    case 3: {
        u8 st;
        if (func_0033C290(self) != 0) {
            func_0033F660(self, 0.027777778f, 1.6666667f, 0.001163553f, 0.10471977f);
            self[0xBC] = 0;
            *(u16 *)(self + 0x96) = 0;
        }
        st = self[0xBC];
        if (st == 0 && *(s16 *)(pv + 0x1EE) < *(u16 *)(self + 0x96)) {
            self[0xBC] = 1;
            break;
        }
        if (st == 1) {
            if (func_L11_00441808(*(s32 *)(self + 0xB8), (self + 0x10)) != 0)
                func_0032C9E0(self, 7, 3);
            func_0033E3F0(self, func_L11_004417E8(*(s32 *)(self + 0xB8)));
        }
        break;
    }
    case 4:
        if (func_0033C290(self) != 0)
            *(u16 *)(self + 0x96) = 0;
        if (*(u16 *)(self + 0x96) < 0x1A)
            break;
        if (self[0x43] != 0)
            func_0032C700(self, 0, 0, 5);
        func_0032C9E0(self, 8, 3);
        break;
    case 7: {
        u8 *path;
        u8 *p;
        s32 i;
        s32 best;
        f32 d;
        f32 lim;

        path = D_L11_001FF580[*(s16 *)(pv + 0x1FC) != 0 ? *(s32 *)(pv + 0x1E0) : *(s32 *)(pv + 0x1C0)];
        if (func_0033C290(self) != 0) {
            p = path + 0x10;
            i = 0;
            best = 0;
            func_0033F660(self, 0.027777778f, 3.3333335f, 0.001163553f, 0.10471977f);
            *(f32 *)(pv + 0x1C8) = func_0032CB48(1.0f, 3.0f);
            d = func_003006B8((self + 0x10), p);
            for (; i < *(s32 *)path - 1; i++, p += 0x10) {
                f32 e = func_003006B8((self + 0x10), p);
                if (e < d) {
                    d = e;
                    best = i;
                }
            }
            *(s32 *)(pv + 0x1D4) = best;
            *(s16 *)(pv + 0x1E8) = func_0032CAB0(2);
        } else {
            qcopy(v10, path + 0x10 + (*(s32 *)(pv + 0x1D4) << 4));
            if (*(s16 *)(pv + 0x1FC) != 0) {
                func_00300510(v30, v10, target);
                v30[2] = 0.0f;
                func_003007F8(v30, v30, 15.0f - *(f32 *)(pv + 0x1C8));
                v10[0] = *(f32 *)(target + 0) + v30[0];
                v10[1] = *(f32 *)(target + 4) + v30[1];
            } else {
                v10[2] = *(f32 *)(pv + 0x1C8) + *(f32 *)(target + 8);
            }
            func_00300510(v20, v10, (self + 0x10));
            lim = 2.0f;
            func_003007F8(v20, v20, *(f32 *)(pv + 0x1D8));
            func_003004E0((self + 0x10), (self + 0x10), v20);
            if (*(s16 *)(pv + 0x1FC) != 0)
                lim = 4.0f;
            if (*(s16 *)(pv + 0x1E8) != 0) {
                if (func_003006B8((self + 0x10), v10) < lim)
                    *(s32 *)(pv + 0x1D4) -= 1;
                if (*(s32 *)(pv + 0x1D4) < 0)
                    *(s32 *)(pv + 0x1D4) = *(s32 *)path - 1;
            } else {
                if (func_003006B8((self + 0x10), v10) < lim)
                    *(s32 *)(pv + 0x1D4) += 1;
                if (*(s32 *)(pv + 0x1D4) >= *(s32 *)path)
                    *(s32 *)(pv + 0x1D4) = 0;
            }
            if (*(s32 *)(pv + 0x1D4) >= *(s32 *)path - 6 && *(f32 *)(pv + 0x1D8) >= 0.10000001f)
                *(f32 *)(pv + 0x1D8) = *(f32 *)(pv + 0x1D8) - 0.0025f;
            func_0032BA0C(self);
            if (*(s16 *)(pv + 0x1FC) != 0) {
                func_003402D0(self, v10);
            } else {
                func_0033E520(self, v10, *(f32 *)(pv + 0x1D0));
                func_00330130(self + 0x18, pv + 0x108, *(f32 *)(pv + 0x1C8), 0.00055555557f, 0.00055555557f,
                              0.16666667f);
            }
        }
        if (*(s16 *)(pv + 0x1EC) != 0)
            func_0032C9E0(self, 8, 3);
        break;
    }
    case 8: {
        s32 flag;
        if (func_0033C290(self) != 0)
            func_0033F660(self, 0.011111111f, 1.3333334f, 0.001163553f, 0.10471977f);
        flag = 0;
        if (*(s16 *)(pv + 0x1FC) != 0) {
            if (4.0f < dist) {
                func_00300510(v10, v00, (self + 0x10));
                func_003007F8(v10, v10, 10.0f);
                func_003004E0(v10, v10, (self + 0x10));
                func_003402D0(self, v10);
            } else {
                func_003402D0(self, v00);
            }
            flag = dist < 4.0f;
        } else {
            f32 z = *(f32 *)(target + 8) + 0.5f;
            func_00330130(self + 0x18, pv + 0x108, z, 0.0055555557f, 0.027777778f, 0.16666667f);
            func_0033E520(self, v00, *(f32 *)(pv + 0x1D0));
            if (func_00300450(*(f32 *)(self + 0x18) - z) < 0.1f &&
                func_003006F0((self + 0x10), &((Hero *)D_00189E20)->q[0x80 / 16]) < 2.0f)
                flag = 1;
        }
        if (flag) {
            *(u16 *)(self + 0x96) = 0;
            func_0032C9E0(self, 10, -1);
        }
        func_0032E480(self, (self + 0x10), 1, 0.3f, (f32)pv[0x34], 1.0f, 0, 1, 0);
        break;
    }
    case 9:
        if (func_0033C290(self) != 0 && self[0x43] != 2)
            func_0032C700(self, 2, 0, 3);
        if (!(self[0x60] & 2))
            break;
        if (self[0x43] != 3)
            func_0032C700(self, 3, 0, 5);
        func_0032C9E0(self, 11, -1);
        break;
    case 11: {
        s32 i;
        f32 lim;
        if (func_0033C2B8(self) != 0) {
            func_0033F660(self, 0.0022222223f, 0.06666667f, 0.001163553f, 0.10471977f);
            *(u16 *)(self + 0x96) = 0;
        }
        *(f32 *)(self + 0x48) = 1.75f;
        for (i = 0; i < 4; i++)
            func_0032E5C8(self, i, 1, 0.5f, (f32)pv[0x34], 1.0f, 0, 1, 0);
        lim = 1.8f;
        if (lim <= func_003006B8((self + 0x10), &((Hero *)D_00189E20)->q[0x80 / 16])) {
            qcopy(v10, v00);
        } else if (func_003006B8((self + 0x10), &((Hero *)D_00189E20)->q[0x80 / 16]) < lim) {
            func_00300510(v10, (self + 0x10), v00);
            func_003007F8(v10, v10, 2.0f);
            func_003004E0(v10, v10, (self + 0x10));
        } else {
            qcopy(v10, (self + 0x10));
        }
        if (*(s16 *)(pv + 0x1FC) != 0) {
            func_003402D0(self, v10);
        } else {
            func_00330130(self + 0x18, pv + 0x108, *(f32 *)(target + 8) + 0.5f, 0.0055555557f, 0.027777778f,
                          0.16666667f);
            func_0033E3F0(self, v10);
        }
        if (((Hero *)D_00189E20)->ptr[0x249C / 4] == self) {
            func_0032C9E0(self, 12, -1);
            if (self[0x43] != 4)
                func_0032C700(self, 4, 0, 5);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        if (func_003006B8((self + 0x10), &((Hero *)D_00189E20)->q[0x80 / 16]) > 4.0f && *(u16 *)(self + 0x96) >= 0x79) {
            if (self[0x43] != 5)
                func_0032C700(self, 5, 0, 15);
            func_0032C9E0(self, 4, -1);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        break;
    }
    case 12:
        if (!(self[0x60] & 2))
            break;
        if (self[0x43] != 0)
            func_0032C700(self, 0, 0, 15);
        func_0032C9E0(self, 8, -1);
        break;
    case 10:
        if (*(u16 *)(self + 0x96) >= 0xF) {
            func_0032C9E0(self, 9, -1);
            if (self[0x43] != 2)
                func_0032C700(self, 2, 0, 2);
            *(f32 *)(self + 0x48) = 1.0f;
        }
        qcopy(v10, (self + 0x10));
        if (dist < 1.0f)
            func_0032E480(self, v10, 1, 0.3f, (f32)pv[0x34], 1.0f, 0, 1, 0);
        break;
    case 13:
        qcopy(v10, (self + 0x10));
        *(f32 *)(pv + 0x108) = *(f32 *)(pv + 0x108) - *(f32 *)(pv + 0x8C);
        func_003004E0((self + 0x10), (self + 0x10), pv + 0x100);
        if (func_002F0318(v10, (self + 0x10), 0, self, 0) == 0 && func_002F1378((self + 0x10), 4, self, 0.3f) == 0 &&
            func_0032CAB0(0x1E) != 0)
            break;
        func_0032E480(self, (self + 0x10), 0x10000, 0.5f, (f32)pv[0x34], 1.0f, 0, 1, 0);
        if (*(f32 *)(pv + 0x20) > 0.0f) {
            func_0032C9E0(self, 8, 3);
            if (self[0x43] != 0)
                func_0032C700(self, 0, 0, 5);
        } else if (*(s16 *)(pv + 0x1FC) != 0 && func_0032CAB0(2) == 0) {
            func_0032C9E0(self, 14, -1);
        } else {
            func_L11_00441A38(self, 0, 1);
            func_L11_00454DD8(self);
        }
        break;
    case 14: {
        s32 i;
        u8 *t;
        if (func_0033C290(self) != 0) {
            t = func_L11_004417E8(*(s32 *)(self + 0xB8));
            func_00300510(pv + 0x100, t, (self + 0x10));
            *(f32 *)(pv + 0x108) = 0.0f;
            func_003007F8(pv + 0x100, pv + 0x100, func_0032CB48(3.0f, 5.0f) * 0.016666668f);
            *(s16 *)(pv + 0x1FC) = 0;
            for (i = 0; i < 3; i++) {
                ((f32 *)(pv + 0x1B0))[i] = func_0032CB48(240.0f, 720.0f) * 0.00029088825f;
                qcopy(m[i], self + 0xC0 + i * 0x10);
            }
            func_003313B8(m, self + 0xF0);
            *(u16 *)(self + 0x34) &= 0xEFFF;
        }
        *(f32 *)(pv + 0x108) = *(f32 *)(pv + 0x108) - *(f32 *)(pv + 0x8C);
        func_0033E7C8(self, pv + 0x100);
        func_00300580(pv + 0x1B0, pv + 0x1B0, 0.98f);
        *(TI128 *)v20 = 0;
        v20[2] = *(f32 *)(pv + 0x30);
        *(TI128 *)v10 = *(TI128 *)v20;
        func_0033D328(self, v10, *(f32 *)(pv + 0x1B0), *(f32 *)(pv + 0x1B4), *(f32 *)(pv + 0x1B8));
        func_00300D78(self + 0xC0, self + 0xF0);
        t = func_L11_004417E8(*(s32 *)(self + 0xB8));
        if (*(f32 *)(self + 0x18) < *(f32 *)(t + 8) + 5.0f || func_0032CAB0(0x1C2) == 0 ||
            *(u16 *)(self + 0x96) >= 0x12D) {
            func_L11_00441A38(self, 0, -1);
            func_L11_00454DD8(self);
        }
        break;
    }
    }

    if (*(s16 *)(pv + 0x1FC) != 0 && self[0x95] != 4) {
        f32 z = *(f32 *)(self + 0x18);
        func_00300510(v10, (self + 0x10), target);
        v10[2] = 0.0f;
        func_003007F8(v10, v10, 14.3f);
        func_003004E0((self + 0x10), v10, target);
        *(f32 *)(self + 0x18) = z;
    }
    if (self[0x20] != 0xE) {
        *(f32 *)(pv + 0x1B0) = func_0032FC98(*(f32 *)(pv + 0x1B0), D_L11_001B1D40 * 0.00029088825f, 0.0625f);
        *(f32 *)(pv + 0x1B4) = func_0032FC98(*(f32 *)(pv + 0x1B4), D_L11_001B1D44 * 0.00029088825f, 0.0625f);
        *(f32 *)(pv + 0x1B8) = func_0032FC98(*(f32 *)(pv + 0x1B8), D_L11_001B1D48 * 0.00029088825f, 0.0625f);
        *(f32 *)(self + 0xF0) = func_003015A8(*(f32 *)(self + 0xF0), *(f32 *)(pv + 0x1B0));
        *(f32 *)(self + 0xF4) = func_003015A8(*(f32 *)(self + 0xF4), *(f32 *)(pv + 0x1B4));
        *(f32 *)(self + 0xF8) = func_003015A8(*(f32 *)(self + 0xF8), *(f32 *)(pv + 0x1B8));
    }
    if (target != 0 && *(s16 *)(pv + 0x1FC) == 0 && *(f32 *)(self + 0x18) <= *(f32 *)(target + 8) + 0.4f) {
        if (self[0x31] == 0) {
            *(f32 *)(pv + 0x108) = 0.016666668f;
            *(f32 *)(self + 0x18) = *(f32 *)(target + 8) + 0.3f;
        } else if (func_002F1378((self + 0x10), 6, 0, 0.3f) != 0) {
            f32 s;
            s32 n;
            *(f32 *)(pv + 0x108) = 0.016666668f;
            *(f32 *)(self + 0x18) = *(f32 *)(target + 8) + 0.3f;
            v10[0] = *(f32 *)(self + 0x10) + func_0032CB48(-0.01f, 0.01f);
            v10[1] = *(f32 *)(self + 0x14) + func_0032CB48(-0.01f, 0.01f);
            v10[2] = *(f32 *)(self + 0x18) - 0.3f;
            s = func_0032CB48(0.3f, 0.8f);
            n = func_0032CAB0(2);
            if (n == 0)
                n--;
            func_0032CD98(v20, 0.0008333334f, 0.050000004f);
            v20[2] = func_0032CB48(1.0f, 5.0f) * 0.016666668f;
            func_0034D250(v10, 0x3C, 0x7F007F7F, 0, n, v20, 0, s * 0.1f, s, 0.002f);
        }
    }
    func_0032E480(self, (self + 0x10), 0x4000000, 0.8f, 5.0f, 1.0f, 0, 1, 0);
    func_L11_00454AE0(self);
}
