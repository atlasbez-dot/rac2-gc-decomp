/* M21 2026-10-26: 612 of 612 bytes with -O2 -G8 -ffunction-sections (us level 00), about
   20 lines off in two spots: (1) the recoil block reloads the state into $a2 here, $a0 in
   retail (register only); (2) the view tail: retail loads D_L00_001B14A0/14A4 before the bD6
   byte store and keeps 0.2f in $f0 for both stores; here sb goes first (all 120 statement
   orders give the same). What closed the rest: per-arm func_002702C8 calls (retail
   duplicates the argument loads in both arms and cross-jumps the call), struct views for
   recoil/view/motion/aim/sway (lets sched group the $gp loads), the temp block kept as a
   byte pointer (keeps the D_L00_001BB040 load after its stores), D_L00_001B1854 MACRO_ADDR,
   defaults before defaultView, and a chained 0.2f store. Permuter queued. */

#include "common.h"

typedef struct {
    short h0, h2;                 /* 0x00 */
    char pad4[0x1C - 0x4];
    float f1C, f20;               /* 0x1C */
    char pad24[0x28 - 0x24];
    float f28, f2C, f30;          /* 0x28 */
    float f34, f38;               /* 0x34 */
} Recoil_L00_00422268;
typedef struct {
    char pad0[0xB0];
    float fB0, fB4, fB8;          /* 0xB0 */
    float vBC[4];                 /* 0xBC */
    char padCC[0xD6 - 0xCC];
    u8 bD6;                       /* 0xD6 */
    char padD7[0xDA - 0xD7];
    short hDA;                    /* 0xDA */
    float fDC, fE0, fE4, fE8;     /* 0xDC */
    u16 hEC;                      /* 0xEC */
} View_L00_00422268;
typedef struct {
    char pad0[0x2C];
    float f2C, f30;               /* 0x2C */
    char pad34[0x3C - 0x34];
    short h3C, h3E;               /* 0x3C */
    float f40;                    /* 0x40 */
    float v44[1];                 /* 0x44 */
    float f48, f4C;               /* 0x48 */
    float v50[1];                 /* 0x50 */
    float f54, f58;               /* 0x54 */
} Motion_L00_00422268;
typedef struct {
    char pad0[0x10];
    int f10;                      /* 0x10 */
    float f14;                    /* 0x14 */
    char pad18[4];
    float f1C;                    /* 0x1C */
    int f20, f24;                 /* 0x20 */
} Temp_L00_00422268;
typedef struct {
    char pad0[0x3C];
    float f3C, f40, f44;          /* 0x3C */
    int f48;                      /* 0x48 */
    char pad4C[2];
    short h4E;                    /* 0x4E */
} Aim_L00_00422268;
typedef struct {
    char pad0[6];
    short h6;                     /* 0x06 */
    char pad8[4];
    float fC;                     /* 0x0C */
} Sway_L00_00422268;
typedef struct {
    char pad0[0x10];
    short h10;                    /* 0x10 */
    char pad12[0x20 - 0x12];
    Recoil_L00_00422268 recoil;   /* 0x20 */
    char pad5C[0x60 - 0x5C];
    View_L00_00422268 view;       /* 0x60 */
    char pad150[0x160 - 0x150];
    Motion_L00_00422268 motion;   /* 0x160 */
    char pad1BC[0x1C0 - 0x1BC];
    Temp_L00_00422268 temp;       /* 0x1C0 */
    char pad1E8[0x1F0 - 0x1E8];
    Aim_L00_00422268 aim;         /* 0x1F0 */
    char pad240[0x240 - 0x240];
    Sway_L00_00422268 sway;       /* 0x240 */
} State_L00_00422268;

extern float D_001A8904;
extern State_L00_00422268 *D_L00_001BB040 __attribute__((nosda));
extern float D_L00_001B14F8 __attribute__((sda)), D_L00_001B14FC __attribute__((sda));
extern float D_L00_001B14A0 __attribute__((sda)), D_L00_001B14A4 __attribute__((sda));
extern unsigned short D_L00_001B1514 __attribute__((sda));
extern float D_L00_001B14DC __attribute__((sda)), D_L00_001B14D4 __attribute__((sda)), D_L00_001B14D8 __attribute__((sda));
extern int D_L00_001B1854 MACRO_ADDR;
extern float D_L00_001B1510 __attribute__((sda));
extern float func_002702C8(float *, float, float, float, float, float);
extern float func_002AA548(float *, float *, float, float, float, float);

void func_L00_00422268(char *object)
{
    State_L00_00422268 *state;
    Motion_L00_00422268 *motion, *defaults;
    View_L00_00422268 *view, *defaultView;
    Recoil_L00_00422268 *recoil;
    char *temporary;
    Aim_L00_00422268 *aim;
    Sway_L00_00422268 *sway;

    temporary = *(char **)(object + 0x70) + 0x1C0;
    *(float *)(temporary + 0x14) = D_001A8904;
    *(int *)(temporary + 0x1C) = 0;
    *(int *)(temporary + 0x20) = 0;
    *(int *)(temporary + 0x10) = 0;
    *(int *)(temporary + 0x24) = 0;
    state = *(State_L00_00422268 **)(object + 0x70);
    motion = &state->motion;
    view = &state->view;
    defaults = &D_L00_001BB040->motion;
    defaultView = &D_L00_001BB040->view;
    if (motion->h3C)
        motion->f2C = func_002702C8(motion->v44, motion->f2C, motion->f40, motion->f48, D_L00_001B14F8, *(float *)(temporary + 0x1C));
    else
        motion->f2C = func_002702C8(motion->v44, motion->f2C, defaults->f2C, motion->f48, D_L00_001B14F8, *(float *)(temporary + 0x1C));
    if (motion->h3E)
        motion->f30 = func_002702C8(motion->v50, motion->f30, motion->f4C, motion->f54, D_L00_001B14FC, 0.0f);
    else
        motion->f30 = func_002702C8(motion->v50, motion->f30, defaults->f30, motion->f54, D_L00_001B14FC, 0.0f);
    if (view->hDA)
        view->fB0 = func_002702C8(view->vBC, view->fB0, view->fB4, view->fB8, 0.2f, 0.0f);
    else
        view->fB0 = func_002702C8(view->vBC, view->fB0, defaultView->fB0, view->fB8, 0.2f, 0.0f);
    motion->h3C = 0;
    motion->h3E = 0;
    *(int *)&motion->f40 = 0;
    *(int *)&motion->f4C = 0;
    motion->f58 = defaults->f2C;
    view->hDA = 0;
    view->fB4 = 0;
    (*(State_L00_00422268 **)(object + 0x70))->h10 = 1;
    state = *(State_L00_00422268 **)(object + 0x70);
    recoil = &state->recoil;
    recoil->f1C = 0.005f;
    recoil->f20 = 0.2f;
    recoil->h2 = 0;
    if (recoil->f2C != 0.0f)
        func_002AA548(&state->recoil.f28, &state->recoil.f30, recoil->f2C, recoil->f34, recoil->f38, 1.0f);
    else if (recoil->f28 != 0.0f)
        func_002AA548(&state->recoil.f28, &state->recoil.f30, 0.0f, recoil->f34, recoil->f38, 1.0f);
    *(int *)&recoil->f2C = 0;
    view->bD6 = 0;
    view->fDC = D_L00_001B14A0;
    view->fE0 = view->fE8 = 0.2f;
    view->hEC = D_L00_001B1514;
    view->fE4 = D_L00_001B14A4;
    aim = &(*(State_L00_00422268 **)(object + 0x70))->aim;
    aim->f3C = D_L00_001B14DC;
    aim->f44 = D_L00_001B14D4;
    aim->f40 = D_L00_001B14D8;
    aim->f48 = D_L00_001B1854;
    aim->h4E = 0;
    sway = &(*(State_L00_00422268 **)(object + 0x70))->sway;
    sway->fC = D_L00_001B1510;
    sway->h6 = 0;
}
