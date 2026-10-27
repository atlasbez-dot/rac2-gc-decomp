/* func_L00_004224D0 (2,916 bytes, 27 level places; US only, in neither the PAL nor the us2
 * catalogue). Opus big39, 26 October 2026. G8 draft: check as src/levels/shared/L00_004224D0-g8.c
 * (default -O2 -G8 -ffunction-sections) with the INCLUDE_ASM removed from L00_004224D0.c.
 *
 * Per-frame camera tuning from the hero's state (0x2294, 0x229C, 0x22B4, 0x24A0), the
 * level's camera block at D_L00_001B8C80 (hook at +0x3B0, target at +0x284, timer at
 * +0x288) and the pvars at self+0x70; it ends counting the active handles in D_L00_001C3280.
 *
 * Status: 2908 of 2916 bytes, 727/729 instructions; control flow, calls, frame, constants,
 * gp/macro/absolute addressing forms and most registers agree. Left:
 *  - the setup block under 22B4 == 2: retail keeps the hero position (H + 0x80) in $s5
 *    derived from the hero base register and rebuilds D_0018A0E0 for the second
 *    func_00282D30 (lui in the argument register), while cse here keeps D_0018A0E0 in a
 *    saved register (qcopy) or rebuilds both (qcopy_nc on the first copy, as here);
 *    the base/q/qt/o pointers then take other saved registers;
 *  - the block-local G = D_L00_001B8C80 after the hook: retail forms G as sub - 0x3A0 in
 *    $s1 (cse related value); here the two land in one register;
 *  - the sum loop: loop.c eliminates the counter here (biv only used by givs) and counts
 *    down with bgez; retail keeps i in $s0 with slti 4;
 *  - the `400` clamp after the increment (sw order) and two registers in the camera-block
 *    timer code.
 * Findings: the min-against-2.0 and 1.0 clamps are `if (s > 2.0f) s = 2.0f`; the D_001A79F0
 * reads are MACRO_ADDR (gp in delay slots), D_L00_001A8FF0 and D_L00_001A8900 tied macro
 * forms (sda incomplete arrays), the 0x24B4..0x25B4 floats sized sda under -G8.
 */
#include "common.h"

typedef union {
    u8 b[0x2600];
    s8 c[0x2600];
    s16 h[0x1300];
    u16 uh[0x1300];
    s32 i[0x980];
    f32 f[0x980];
    char *p[0x980];
} Hero_004224D0;

typedef void (*Hook_004224D0)(void);

extern char D_00189E20[];
extern char D_00189EA0[];
extern char D_0018A0E0[];
extern char D_00138180[];
extern s32 D_001A79F0 MACRO_ADDR;
extern s32 D_L00_001A8FF0[] __attribute__((sda));
extern f32 D_L00_001A8900[] __attribute__((sda));
extern f32 D_L00_001B14A4 __attribute__((sda));
extern s32 D_L00_001B1590 __attribute__((sda));
extern f32 D_L00_001B1594 __attribute__((sda));
extern f32 D_L00_001B1598 __attribute__((sda));
extern f32 D_L00_001B159C __attribute__((sda));
extern f32 D_L00_001B15A0 __attribute__((sda));
extern f32 D_L00_001B15A4 __attribute__((sda));
extern f32 D_L00_001B1578 __attribute__((sda));
extern f32 D_L00_001B157C __attribute__((sda));
extern char D_L00_001B8C80[];
extern char D_L00_001B8E20[];
extern char *D_L00_001C3280[];

extern s32 func_L00_002D71A0(void);
extern s32 func_00277F48(f32, void *, s32, s32, s32);
extern s32 func_00282948(void *);
extern s32 func_00282978(s16 *);
extern f32 func_00282C48(f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, f32);
extern f32 func_00283180(f32);
extern f32 func_00283198(f32);
extern f32 func_00283B98(f32, f32);
extern f32 func_00283C80(f32, f32);
extern f32 func_00283CE0(s32);
extern char *func_002AB1F0(char *);
extern void func_L00_00423038(s32);
extern void func_L00_00424A08(s32, f32, f32);
extern void func_L00_00424A50(f32, f32);
extern void func_L00_00424A88(f32, s32, f32);
extern void func_L00_00424B20(f32);
extern void func_L00_00424B48(s32);
extern void func_L00_00424B70(f32, f32);
extern void func_L00_00424BB8(f32, f32);
extern void func_L00_00424C00(void);
extern void func_L00_00424C28(void);
extern void func_L00_00424C60(void);
extern void func_L00_00424F00(void *, f32, f32);
extern void func_L00_00424F58(char *, f32, f32);

void func_L00_004224D0(char *self)
{
    float v[4] __attribute__((aligned(16)));
    char *pv;
    char *blk;
    char *cam;
    char *top;
    char *g;
    s32 r;
    s32 busy;
    s32 n;
    s32 i;

    busy = 0;
    pv = *(char **)(self + 0x70);
    blk = pv + 0x240;
    top = pv + 0x1F0;
    cam = pv + 0x60;
    r = func_L00_002D71A0();
    if (((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x7C
        || ((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x78)
        *(s16 *)(top + 0x4E) = 1;
    if (((Hero_004224D0 *)D_00189E20)->i[0x340 / 4] == 0 || *(s32 *)(cam + 0xF4) != 0) {
        float s = *(float *)(cam + 0xF0);

        if (s > 2.0f)
            s = 2.0f;
        *(float *)(cam + 0xE4) = (D_L00_001B14A4 - 0.002f) * (s * 0.5f) + 0.002f;
        if (((Hero_004224D0 *)D_00189E20)->i[0x340 / 4] != 0)
            func_00282948(cam + 0xF4);
        else
            *(s32 *)(cam + 0xF4) = 15;
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x229C / 4] == 0x1E) {
        *(float *)(*(char **)(self + 0x70) + 0x110) = 0.75f;
        func_L00_00424BB8(0.04f, 0.2f);
    }
    if (D_001A79F0 == 1 && ((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x30
        && 75.0f < ((Hero_004224D0 *)D_00189E20)->f[0x88 / 4]
        && ((Hero_004224D0 *)D_00189E20)->f[0x88 / 4] < 105.0f) {
        func_L00_00424B20(0.8726647f);
        func_L00_00424C60();
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x24A0 / 4] == 13
        && ((Hero_004224D0 *)D_00189E20)->h[0x21A / 2] != 0) {
        float a = func_00283B98(((Hero_004224D0 *)D_00189E20)->f[0x574 / 4], 3.141593f);

        v[0] = func_00283180(a);
        v[1] = func_00283198(a);
        v[2] = 0.0f;
        func_L00_00424F00(v, 0.20943953f, v[2]);
        func_L00_00424C28();
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x229C / 4] == 0x11) {
        *(float *)(*(char **)(self + 0x70) + 0x110) = 0.25f;
        func_L00_00424A50(0.5f, 0.003f);
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x229C / 4] == 5 && D_L00_001A8FF0[0] == 0) {
        char *c;

        busy = 1;
        c = *(char **)(self + 0x70) + 0x60;
        if (((Hero_004224D0 *)D_00189E20)->b[0x22B4] == 1 && r == -1) {
            *(float *)(c + 0xB0) = 0.25f;
            func_L00_00424A50(1.5f, 0.003f);
        } else {
            *(float *)(c + 0xB0) = 0.25f;
            func_L00_00424A50(2.5f, 0.003f);
        }
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x229C / 4] == 0x10)
        *(float *)(*(char **)(self + 0x70) + 0x110) = 0.25f;
    if (((Hero_004224D0 *)D_00189E20)->b[0x22B4] == 1) {
        if (*(s32 *)blk == 0 && r == -1) {
            char *c = *(char **)(self + 0x70) + 0x60;

            func_L00_00424A08(1, 3.0f, 0.003f);
            if (busy == 0) {
                *(float *)(c + 0xB0) = 1.0f;
                func_L00_00424A50(1.0f, 0.003f);
            }
        }
        *(float *)(*(char **)(self + 0x70) + 0x22C) = 0.6f;
    }
    if (((Hero_004224D0 *)D_00189E20)->b[0x22B4] == 2) {
        if (*(s32 *)(blk + 0x10) < 2) {
            func_L00_00424A88(D_L00_001B1594, 0, 0.005f);
            func_L00_00424A08(1, D_L00_001B1598, 0.003f);
            func_L00_00424A50(D_L00_001B159C, 0.003f);
            if (*(s32 *)(D_L00_001B8C80 + 0x404) < 2) {
                char *aim = cam + 0x50;
                char *base = *(char **)(self + 0x70);
                char *at = self + 0x30;
                char *hpos = D_00189E20 + 0x80;
                char *look = base + 0x160;
                char *o;
                char *q;
                char *qt;

                *(float *)(look + 0x2C) = D_L00_001B1598;
                *(float *)(look + 0x30) = D_L00_001B159C;
                *(float *)(cam + 0xB0) = D_L00_001B1594;
                func_L00_00423038(1);
                q = *(char **)(self + 0x70);
                qt = q + 0x1F0;
                o = q + 0x20;
                func_00282D30(v, D_0018A0E0, -*(float *)(look + 0x30));
                func_00282CC0(aim, hpos, v);
                func_00282CF0(look, at, aim);
                qcopy_nc(base + 0x170, look);
                func_00282D30(v, D_0018A0E0, -*(float *)(cam + 0xB0));
                func_00282CC0(cam + 0x40, hpos, v);
                qcopy(cam + 0x90, cam + 0x40);
                qcopy(cam, hpos);
                qcopy(cam + 0x60, cam);
                qcopy(q, at);
                qcopy(q + 0x210, at);
                *(s32 *)(qt + 0x30) = 0;
                *(s32 *)(o + 0x14) = 0;
                *(float *)(o + 0x4) = *(float *)(cam + 0xB0);
                *(float *)(o + 0xC) = *(float *)(o + 0x14);
                *(float *)(o + 0x8) = *(float *)(look + 0x30);
                *(s16 *)(o + 0x2) = 0;
                *(float *)(o + 0x18) = *(float *)(o + 0x14);
                *(float *)(o + 0x10) = *(float *)(o + 0x14);
            }
        }
        func_L00_00424C00();
        *(float *)(*(char **)(self + 0x70) + 0x1F0 + 0x3C) = D_L00_001B15A4;
        *(float *)(*(char **)(self + 0x70) + 0x1F0 + 0x44) = D_L00_001B15A0;
    }
    {
        char *sub = D_L00_001B8C80 + 0x3A0;

        if (*(Hook_004224D0 *)(sub + 0x10) != 0)
            (*(Hook_004224D0 *)(sub + 0x10))();
    }
    g = D_L00_001B8C80;
    if (*(char **)(g + 0x284) != 0 && *(s32 *)(blk + 0x10) < 2) {
        u8 s = (*(char **)(g + 0x284))[0x20];

        if (s == 0xFE) {
            *(char **)(g + 0x284) = 0;
        } else if (s == 0xFD) {
            *(char **)(g + 0x284) = 0;
        } else {
            float t;

            if (0.3f <= func_00282C48(*(float *)(D_00138180 + 0x100))
                || 0.3f <= func_00282C48(*(float *)(D_00138180 + 0x104)))
                *(s32 *)(g + 0x288) = 0x280;
            if (*(s32 *)(D_L00_001B8C80 + 0x288) > 400) {
                func_00282948(D_L00_001B8C80 + 0x288);
                if (*(s32 *)(D_L00_001B8C80 + 0x288) <= 400)
                    *(s32 *)(D_L00_001B8C80 + 0x288) = 0;
            } else {
                *(s32 *)(D_L00_001B8C80 + 0x288) = *(s32 *)(D_L00_001B8C80 + 0x288) + 1;
                if (*(s32 *)(D_L00_001B8C80 + 0x288) > 400)
                    *(s32 *)(D_L00_001B8C80 + 0x288) = 400;
                t = func_00283CE0(*(s32 *)(D_L00_001B8C80 + 0x288)) / func_00283CE0(400);
                func_L00_00424F58(*(char **)(D_L00_001B8C80 + 0x284) + 0x10, t * 1.5707965f, 0.0f);
                func_L00_00424C28();
                func_L00_00424B70(0.03f, 0.2f);
            }
        }
    }
    if (((Hero_004224D0 *)D_00189E20)->p[0x1450 / 4] != 0
        && ((Hero_004224D0 *)D_00189E20)->p[0x1450 / 4][0x20] >= 0) {
        float t;

        *(s32 *)(D_L00_001B8C80 + 0x288) = *(s32 *)(D_L00_001B8C80 + 0x288) + 1;
        if (*(s32 *)(D_L00_001B8C80 + 0x288) > 400)
            *(s32 *)(D_L00_001B8C80 + 0x288) = 400;
        t = func_00283CE0(*(s32 *)(D_L00_001B8C80 + 0x288)) / func_00283CE0(400);
        func_L00_00424F58(((Hero_004224D0 *)D_00189E20)->p[0x1450 / 4] + 0x10, t * 1.5707965f, 0.0f);
        func_L00_00424C28();
        func_L00_00424B70(0.03f, 0.2f);
    }
    if (*(char **)(D_L00_001B8C80 + 0x284) == 0 && ((Hero_004224D0 *)D_00189E20)->p[0x1450 / 4] == 0)
        *(s32 *)(D_L00_001B8C80 + 0x288) = 0;
    if (((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x81) {
        func_L00_00424C28();
        func_L00_00424B70(1.0f, 1.0f);
        func_L00_00424BB8(0.06f, 0.2f);
        func_L00_00424C00();
    }
    if (((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x7B) {
        func_L00_00424B70(0.04f, 0.2f);
        func_L00_00424F00(((Hero_004224D0 *)D_00189E20)->p[0x2290 / 4] + 0xC0, 0.78539824f, 0.0f);
        func_L00_00424A08(0, 3.0f, 0.003f);
        func_L00_00424C00();
    }
    if (*(s32 *)(blk + 0x10) < 2 && ((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] != 0x81
        && (((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x7E
            || ((Hero_004224D0 *)D_00189E20)->i[0x2294 / 4] == 0x82
            || ((Hero_004224D0 *)D_00189E20)->h[0x1454 / 2] != 0)
        && (*(s32 *)(D_00138180 + 0x1A0) & 3) != 0) {
        char *c;

        func_L00_00424B48(0);
        func_L00_00424C28();
        func_L00_00424B70(0.04f, 0.2f);
        c = *(char **)(self + 0x70);
        *(s16 *)(c + 0x14) = 0;
        *(s16 *)(c + 0x16) = 0;
        *(s16 *)(c + 0x12) = 0;
    } else if (D_L00_001B1590 != 0) {
        char *c = *(char **)(self + 0x70);
        float *a = (float *)(D_L00_001B8E20 + 0xB0);
        float sum = 0.0f;
        float k;

        for (i = 0; i < 4; i++) {
            v[i] = func_00283C80(a[i - 1], a[i]);
            sum += v[i];
        }
        sum *= 0.25f;
        k = sum * 5.0f;
        if (k > 1.0f)
            k = 1.0f;
        if (1.0f - k < D_L00_001B1578)
            *(s16 *)(c + 0x12) = 32;
        if (*(s16 *)(c + 0x12) != 0) {
            float t;

            if (func_00282978((s16 *)(c + 0x12)) != 0)
                *(s16 *)(c + 0x14) = 45;
            func_L00_00424C28();
            *(s16 *)(c + 0x16) = *(s16 *)(c + 0x16) + 1;
            if (*(s16 *)(c + 0x16) > 30)
                *(s16 *)(c + 0x16) = 30;
            t = func_00283CE0(*(s16 *)(c + 0x16)) / func_00283CE0(30);
            func_L00_00424B70((D_L00_001B157C - 0.015f) * t + 0.015f, 0.2f);
            D_L00_001A8900[0] = 0.0f;
        } else {
            if (*(s16 *)(c + 0x14) != 0) {
                float t;

                func_00282978((s16 *)(c + 0x14));
                t = func_00283CE0(*(s16 *)(c + 0x14)) / func_00283CE0(45);
                D_L00_001A8900[0] = t * -0.85f + 0.85f;
            } else {
                D_L00_001A8900[0] = 0.85f;
            }
            *(s16 *)(c + 0x16) = 0;
        }
    }
    *(s32 *)(blk + 0x10) = 0;
    n = func_00277F48(15.0f, D_00189EA0, 1, *(s32 *)(D_00189EA0 + 0x2210), 0);
    for (i = 0; i < n; i++) {
        char *m = func_002AB1F0(D_L00_001C3280[i]);

        if (m != 0 && (float)(u8)m[0xD] != 0.0f) {
            *(s32 *)(blk + 0x10) = 1;
            break;
        }
    }
}
