/* func_L14_003E5218 (372 B, 1 place), M31 26 Oct 2026: size matches at the default -G0;
   about 50 lines differ, all scheduling and register choice (obj in $a1 vs $v1, the
   (f+1)%8 slt/addiu order, base+index operand order). Colour words are linear or-chains
   built over separate statements. */
#include "include_asm.h"
#include "common.h"

typedef struct {
    u8 pad00[0xC];
    f32 fC;
    u8 pad10[4];
    s32 base;
    s32 step;
    u8 pad1C[0x30 - 0x1C];
    u32 col0;
    u32 col1;
    u32 col2;
    u32 col3;
} Out3E5218;

typedef struct {
    u8 pad00[0x68];
    Out3E5218 *vars;
} Obj3E5218;

typedef struct {
    s16 tab[8];
    u8 pad10[4];
    s16 top;
    s16 frame;
    u8 pad18[0x28 - 0x18];
    Obj3E5218 *a;
    Obj3E5218 *b;
    u8 pad30[0x40 - 0x30];
    s16 c0[3];
    s16 c1[3];
} Vars3E5218;

typedef struct {
    u8 pad00[0x68];
    Vars3E5218 *vars;
} Moby3E5218;

void func_L14_003E5218(Moby3E5218 *self) {
    Vars3E5218 *v = self->vars;
    Out3E5218 *o;
    s32 f = v->frame;
    s32 cur;
    s32 nxt;
    u32 c;
    s16 *t = v->tab;

    if ((s16)(f % 2) == 1) {
        cur = t[f];
        nxt = t[(f + 1) % 8];
        if (v->a != 0) {
            o = v->a->vars;
            o->base = v->top - cur;
            o->step = cur - nxt;
            c = (v->c0[1] << 8) | 0x80000000;
            c = (v->c0[2] << 16) | c;
            c = c | v->c0[0];
            o->col0 = c;
            o->col2 = c;
            o->fC = 1.0f;
            c = (v->c1[1] << 8) | 0x80000000;
            c = (v->c1[2] << 16) | c;
            c = c | v->c1[0];
            o->col1 = c;
            o->col3 = c;
        }
        if (v->b != 0) {
            o = v->b->vars;
            o->base = v->top - cur;
            o->step = cur - nxt;
            c = (v->c0[1] << 8) | 0x80000000;
            c = (v->c0[2] << 16) | c;
            c = c | v->c0[0];
            o->col0 = c;
            o->col2 = c;
            o->fC = 1.0f;
            c = (v->c1[1] << 8) | 0x80000000;
            c = (v->c1[2] << 16) | c;
            c = c | v->c1[0];
            o->col1 = c;
            o->col3 = c;
        }
    }
}
