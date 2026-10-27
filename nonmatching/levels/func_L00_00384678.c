/* func_L00_00384678 - 1448 bytes, 27 places. Opus first C draft (M18), replacing the "not C" note: the MMI word is por (qzero), so -frac2-zero-ti-por in its own unit. Control flow and calls follow retail; 1468/1448 B. Left: retail keeps &va/&vb in stack spill slots (0x40/0x44, frame 0xC0) and uses all nine callee-saved registers; the 24-tile pointer table is walked by pointer. ~360 diff lines. */
   the lift vector): -frac2-zero-ti-por. */
#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    char pad00[0x24];
    char *cls;
    char pad28[0x34 - 0x28];
    u16 flags;
} Tile_384678;

typedef struct {
    char pad00[0x50];
    float x;
    float y;
    float pad58;
    float sway;
    char pad60[0x6C - 0x60];
    s32 liftTimer;
    s32 rounds;
    float drop;
    s32 timer;
} Board_384678;

extern char *D_L00_00232A60[24];
extern float D_L00_001AED40[4] __attribute__((sda));
extern float D_L00_001AEDF0[];
extern float D_L00_001AEDE0[] __attribute__((sda));
extern float D_L00_001AEE00 __attribute__((sda));
extern float D_L00_001AEE04 __attribute__((sda));
extern float D_L00_001AED60 __attribute__((sda));
extern float D_L00_001AEDB8 __attribute__((sda));
extern char D_L00_001B8FF0[];
extern char D_L00_001B8DC0[];

extern float func_002AA2E8(float *, float, float);
extern int func_002E5CF8(int, int, char *);
extern int func_00282948(void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void *func_002A9640(void *, u32, s32);
extern int func_002A77E0(int);
extern void func_00282F20(void *, void *, float);
extern void func_L00_003851A0(char *, void *);
extern void func_002A05A8(char *);
extern void func_002A0F48(char *);
extern s32 func_L00_0031D620(s32, s32, f32);
extern void func_L00_00384D40(char *, void *, void *);

void func_L00_00384678(char *obj)
{
    Board_384678 *st;
    float base[4] __attribute__((aligned(16)));
    float va[4] __attribute__((aligned(16)));
    float vb[4] __attribute__((aligned(16)));
    float vc[4] __attribute__((aligned(16)));
    float *a, *b;
    int all, i, hit, pick;
    float t;

    st = *(Board_384678 **)(obj + 0x68);
    if (0.0f < st->drop)
        func_002AA2E8(&st->drop, 0.0f, 0.004166667f);
    else
        func_002AA2E8(&st->drop, -0.2f, 0.00033333333f);
    all = 1;
    a = va;
    b = vb;
    for (i = 0; i < 24; i++) {
        if ((((Tile_384678 *)D_L00_00232A60[i])->flags ^ 1) & 1) {
            all = 0;
            break;
        }
    }
    if (all) {
        st->timer = 0x2D;
        st->drop = 0.5f;
        st->rounds++;
        for (i = 0; i < 24; i++) {
            ((Tile_384678 *)D_L00_00232A60[i])->flags &= ~0x41;
            ((Tile_384678 *)D_L00_00232A60[i])->flags |= 0x1000;
            *(s32 *)(D_L00_00232A60[i] + 0x98) = *(s32 *)(((Tile_384678 *)D_L00_00232A60[i])->cls + 0x10);
        }
    }
    if (st->timer != 0 && st->timer % 5 == 0)
        func_002E5CF8(0, 0, D_L00_00232A60[0]);
    func_00282948(&st->timer);
    qcopy(base, D_L00_001AED40);
    base[1] += st->x - st->drop;
    base[2] += st->y;
    if (st->sway == 0.0f)
        st->sway = D_L00_001AEE04 * 0.016666668f;
    st->y += st->sway;
    if (D_L00_001AEE00 < st->y)
        st->sway = -(D_L00_001AEE04 * 0.016666668f);
    else if (st->y < -D_L00_001AEE00)
        st->sway = D_L00_001AEE04 * 0.016666668f;

    hit = 0;
    for (i = 0; i < 24; i++) {
        func_00282D30(a, D_L00_001AEDF0, (float)(i / 8));
        func_00282D30(b, D_L00_001AEDE0, (float)(i % 8));
        func_00282CC0(a, a, b);
        func_00282CC0(a, a, base);
        func_00283098(D_L00_00232A60[i] + 0x10, a, D_L00_001B8FF0);
        func_00282CC0(D_L00_00232A60[i] + 0x10, D_L00_00232A60[i] + 0x10, D_L00_001B8DC0);
        *(float *)(D_L00_00232A60[i] + 0x2C) = *(float *)(((Tile_384678 *)D_L00_00232A60[i])->cls + 0x24) * D_L00_001AED60;
        if ((((Tile_384678 *)D_L00_00232A60[i])->flags ^ 1) & 1) {
            hit++;
            if (func_002A9640(D_L00_00232A60[i], -1, 0)) {
                if (!func_002A77E0(3))
                    func_002E5CF8(0, 0, D_L00_00232A60[i]);
                ((Tile_384678 *)D_L00_00232A60[i])->flags |= 0x41;
                ((Tile_384678 *)D_L00_00232A60[i])->flags &= 0xEFFF;
                *(s32 *)(D_L00_00232A60[i] + 0x98) = 0;
                *(u8 *)(D_L00_00232A60[i] + 0xA8) = 0xFF;
                func_00282F20(vc, D_L00_00232A60[i] + 0xE0, 0.05f);
                func_00282CC0(vc, vc, D_L00_00232A60[i] + 0x10);
                func_L00_003851A0(D_L00_00232A60[i], vc);
            }
            func_002A05A8(D_L00_00232A60[i]);
            func_002A0F48(D_L00_00232A60[i]);
        }
    }
    pick = func_002A77E0(hit);
    if (hit != 0 && func_00282948(&st->liftTimer)) {
        for (i = 0; i < 24; i++) {
            if (!((((Tile_384678 *)D_L00_00232A60[i])->flags ^ 1) & 1))
                continue;
            if (--pick != 0)
                continue;
            t = 1.0f / ((float)(st->rounds + 1) * 0.5f);
            if (1.0f < t)
                t = 1.0f;
            else if (t < 0.0f)
                t = 0.0f;
            st->liftTimer = func_L00_0031D620(1, 0xF0, t);
            *(TI128 *)a = 0;
            a[2] = 0.05f;
            func_00283098(a, a, D_L00_00232A60[i] + 0xC0);
            func_00282CC0(a, a, D_L00_00232A60[i] + 0x10);
            func_00282F20(b, D_L00_00232A60[i] + 0xC0, D_L00_001AEDB8 * 0.016666668f);
            func_L00_00384D40(D_L00_00232A60[i], a, b);
        }
    }
}
