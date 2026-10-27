/* M21 2026-10-26: first C. 444 of 444 bytes with -O2 -G0 -ffunction-sections -frac2-qcopy
   (us level 08). Two spots off, order/addressing only: (1) the entry copy of `dir` stores
   through $s3 here (sq 0($s3)); retail stores 0x10($sp) directly and only later uses $s3/$s5
   (the vector-address pointer locals); (2) before the first func_L04_00358868 call retail
   leaves the b23 store for the jal slot; here a3 = -1 takes it. func_L04_00358868 is
   (void *, float, int, int, int) by its callers' setup order. Permuter queued. */

#include "common.h"

typedef int Quad_L08_003B2DB0 __attribute__((mode(TI)));

typedef struct {
    float dir[4];                 /* 0x00 */
    float f10;                    /* 0x10 */
    int f14;                      /* 0x14 */
    int owner;                    /* 0x18 */
    short h1C, h1E;               /* 0x1C */
    float f20;                    /* 0x20 */
    int f24, f28;                 /* 0x24 */
} Bolt_L08_003B2DB0;
typedef struct {
    char pad0[0x10];
    float pos[4];                 /* 0x10 */
    char pad20[0x23 - 0x20];
    u8 b23;                       /* 0x23 */
    char pad24[0x2C - 0x24];
    float scale;                  /* 0x2C */
    u8 b30, b31;                  /* 0x30 */
    short h32;                    /* 0x32 */
    u16 h34;                      /* 0x34 */
    char pad36[0x68 - 0x36];
    Bolt_L08_003B2DB0 *state;     /* 0x68 */
    char pad6C[0xF0 - 0x6C];
    int fF0;                      /* 0xF0 */
    float fF4, fF8;               /* 0xF4 */
} Moby_L08_003B2DB0;

extern char D_00189EA0[];
extern Moby_L08_003B2DB0 *func_0029EFD0(int);
extern float func_00282E20(void *);
extern float func_00283248(float, float);
extern float func_002A7878(float, float);
extern float func_00282E48(void *, void *);
extern void func_L04_00358868(void *, float, int, int, int);
extern void func_002A0F48(void *);

Moby_L08_003B2DB0 *func_L08_003B2DB0(int owner, float *pos, float *dir, int life)
{
    float p[4] __attribute__((aligned(16)));
    float d[4] __attribute__((aligned(16)));
    Moby_L08_003B2DB0 *moby;
    Bolt_L08_003B2DB0 *state;
    int n;
    float *pp = p;
    float *dd = d;

    *(Quad_L08_003B2DB0 *)p = *(Quad_L08_003B2DB0 *)pos;
    *(Quad_L08_003B2DB0 *)d = *(Quad_L08_003B2DB0 *)dir;
    moby = func_0029EFD0(0x4EA);
    if (moby) {
        state = moby->state;
        state->owner = owner;
        moby->fF0 = 0;
        moby->scale *= 4.0f;
        moby->b30 = 0xFF;
        moby->h32 = 0xFF;
        moby->b31 = 1;
        moby->fF4 = -func_00283248(func_00282E20(dd), dd[2]);
        moby->fF8 = func_00283248(d[0], dd[1]);
        qcopy(moby->pos, pp);
        qcopy(state->dir, dd);
        state->f10 = func_002A7878(-0.02617994323372841f, 0.02617994323372841f);
        state->f14 = 0;
        state->h1C = life;
        state->h1E = life;
        state->f20 = func_00282E48(moby->pos, D_00189EA0);
        state->f24 = 0;
        state->f28 = 0;
        n = life * 5 / 4;
        moby->h34 |= 0x200;
        moby->b23 = 0x40;
        func_L04_00358868(moby, 400000.0f, 0x2F7F4F4F, n, -1);
        func_L04_00358868(moby, 160000.0f, 0x4F7F7F7F, n, -1);
        func_002A0F48(moby);
    }
    return moby;
}
