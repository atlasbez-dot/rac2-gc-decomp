/* Retained nonmatching C (Opus big37), measured 26 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -g. us 0/27, us2 0/27, pal catalogue absent.
 * 2800/2824 bytes under the default compiler; 2808/2824 with branch
 * compiler/div-label-after-call, which gives retail's nop pair before the div.s at +0x210
 * (jal, delay, nop, nop, div.s after the `dot` statement's line label). About 75
 * instructions still differ: the target-lost and target-copy paths re-store the spilled
 * `dir` pointer (0xE4) with a fresh sp+0x50 where this C keeps one copy; the
 * func_002ACAD0 calls set $a1 before $a0 and their address pair never fills the bounds
 * branches' delay slots in retail (an `la`-like single insn; -mno-split-addresses gives
 * that but breaks the other address pairs); the spill slots of &query (0xE8) and the
 * hit-path register choices follow from those.
 * Kept: the 0xFE/0xFD tests as separate statements (one `||` folds them into a range test),
 * the emitter address written out at each use, chained zero stores, separate `dot` and
 * `dist / speed` statements.
 * Reopen: a source shape for the three `dir = &step` stores, or the cprop/movsi path that
 * emits the func_002ACAD0 address as one insn.
 */

#include "common.h"

typedef struct Vec4_0040A4A8 {
    f32 x, y, z, w;
} __attribute__((aligned(16))) Vec4_0040A4A8;

typedef struct Target_0040A4A8 {
    u8 pad0[0x10];
    Vec4_0040A4A8 pos;
    u8 kind;
} Target_0040A4A8;

typedef struct Vars_0040A4A8 {
    f32 aim[3];                     /* 0x00 */
    void *owner;                    /* 0x0C */
    Target_0040A4A8 *target;        /* 0x10 */
    f32 offset;                     /* 0x14 */
    f32 speed;                      /* 0x18 */
    f32 spin;                       /* 0x1C */
    f32 roll_rate;                  /* 0x20 */
    s16 timer;                      /* 0x24 */
    u8 homing;                      /* 0x26 */
    u8 steps;                       /* 0x27 */
    f32 roll;                       /* 0x28 */
    s32 trail;                      /* 0x2C */
    Vec4_0040A4A8 heading;          /* 0x30 */
    Vec4_0040A4A8 lead;             /* 0x40 */
    s32 sound;                      /* 0x50 */
    s32 effect;                     /* 0x54 */
} Vars_0040A4A8;

typedef struct Moby_0040A4A8 {
    u8 pad0[0x10];
    Vec4_0040A4A8 pos;              /* 0x10 */
    u8 pad20[0x48];
    Vars_0040A4A8 *vars;            /* 0x68 */
    u8 pad6C[0x3E];
    u16 aa;                         /* 0xAA */
    u8 padAC[0x10];
    u8 hit;                         /* 0xBC */
    u8 padBD[3];
    Vec4_0040A4A8 m[3];             /* 0xC0 */
} Moby_0040A4A8;

typedef struct Emitter_0040A4A8 {
    u8 pad0[0x74];
    u8 active;                      /* 0x74 */
    u8 pad75[0x13];
    void *owner;                    /* 0x88 */
} Emitter_0040A4A8;

typedef struct Hit_0040A4A8 {
    u8 pad0[0x18];
    void *moby;                     /* 0x18 */
    s32 count;                      /* 0x1C */
    Vec4_0040A4A8 pos;              /* 0x20 */
    Vec4_0040A4A8 normal;           /* 0x30 */
} Hit_0040A4A8;

typedef struct Query_0040A4A8 {
    Vec4_0040A4A8 dir;              /* 0x00 */
    void *moby;                     /* 0x10 */
    s32 mask;                       /* 0x14 */
    u8 a;                           /* 0x18 */
    u8 b;                           /* 0x19 */
    u16 c;                          /* 0x1A */
    f32 radius;                     /* 0x1C */
    s32 one;                        /* 0x20 */
} Query_0040A4A8;

typedef struct Level_0040A4A8 {
    u8 pad0[0x2C];
    u8 index;
} Level_0040A4A8;

typedef union {
    u8 b[0x2600];
    s32 i[0x980];
    void *ptr[0x980];
} Hero_0040A4A8;

extern u8 D_00188660[];
extern Level_0040A4A8 D_00139568;
extern char D_00189E20[];
extern Vec4_0040A4A8 D_00189EA0;
typedef struct Kind_0040A4A8 {
    u8 pad0[0x70];
    f32 radius;                     /* 0x70 */
    u8 pad74[0x6C];
} Kind_0040A4A8;

extern Kind_0040A4A8 D_L00_00262570[];
extern u16 D_L00_001B1FB0[];
extern Vec4_0040A4A8 D_L00_001B8DC0;
extern Hit_0040A4A8 D_L00_001BF200;
extern Vec4_0040A4A8 D_L00_00255BA0[][4];
extern void *D_L00_001ADB2C[];

extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_00282978(s16 *);
extern float func_00282C48(float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *);
extern float func_00282E80(void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00283198(float);
extern float func_002831B0(float);
extern float func_00283B98(float, float);
extern void func_0029F338(void *);
extern int func_002A77E0(int);
extern float func_002A89A8(void *, int, float);
extern float *func_002AB1F0(void *);
extern void func_002AB668(void *, void *, float);
extern void func_002ACAD0(void *, u16 *);
extern void func_002ACDE8(void *, void *, void *);
extern void func_002AFFD8(void *, void *, int);
extern void func_002E59F8(int);
extern int func_002E5CF8(int, int, void *);
extern void func_002FEE50(int);
extern void func_002FEE70(int, void *, int);
extern void func_00300190(void *, void *);
extern void ref_L00_0040A4A8_00(void (*)(Moby_0040A4A8 *), void *);
extern void func_L00_0040B330(Moby_0040A4A8 *);
extern void func_L00_0040B2C0(void *, void *);
extern void func_L00_0040B098(void *, void *);
extern void func_L00_0040AFB8(void *, void *, void *);
extern char *func_L00_00414020(float, void *, int, int, int, int, int, int, int, int, int, int, void *);

void func_L00_0040A4A8(Moby_0040A4A8 *self)
{
    Vec4_0040A4A8 saved;
    Vec4_0040A4A8 fwd;
    Vec4_0040A4A8 aim;
    Vec4_0040A4A8 step;
    Vars_0040A4A8 *vars;
    Target_0040A4A8 *target;
    Emitter_0040A4A8 *e;
    void *hitter;
    Vec4_0040A4A8 *dir;

    hitter = 0;
    vars = self->vars;
    target = vars->target;
    qcopy(&saved, &self->pos);
    func_002AFFD8(&self->pos, &fwd, 1);
    if (((Emitter_0040A4A8 *)(D_00188660 + vars->sound * 0x70))->owner != self
        || ((Emitter_0040A4A8 *)(D_00188660 + vars->sound * 0x70))->active == 0)
        vars->sound = func_002E5CF8(1, 4, self);
    dir = &step;

    if (target != 0) {
        float *health = func_002AB1F0(target);

        if (target->kind == 0xFE)
            goto lost;
        if (target->kind == 0xFD)
            goto lost;
        if (health != 0 && *health <= 0.0f) {
        lost:
            vars->target = 0;
            target = 0;
        } else {
            qcopy(&aim, &target->pos);
            func_00282D30(dir, &fwd, vars->offset);
            func_00282CC0(&aim, &aim, dir);
        }
    }

    if (target != 0 && vars->timer < 0x127 && (s8)target->kind >= 0 && vars->homing != 0) {
      {
        Vec4_0040A4A8 to_aim;
        Vec4_0040A4A8 lead;
        Vec4_0040A4A8 to_lead;
        Vec4_0040A4A8 axis;
        Vec4_0040A4A8 side;
        Vec4_0040A4A8 quat;
        float dist;
        float lead_dist;

        step.x = vars->aim[0];
        step.y = vars->aim[1];
        step.z = vars->aim[2];
        step.w = 0.0f;
        func_00282CF0(&to_aim, &aim, dir);
        dist = func_00282DF0(&to_aim);
        func_00282CC0(&lead, &aim, &vars->lead);
        func_00282CF0(&to_lead, &self->pos, &lead);
        lead_dist = func_00282DF0(&to_lead);
        if (lead_dist != 0.0f) {
            float dot = func_00282DB0(&to_lead, &to_aim);
            float angle = 1.5707964f - func_002831B0(dot / lead_dist);
            float turn;

            func_00282DD8(&axis, &to_aim, &to_lead);
            func_00282DD8(&side, &to_aim, &axis);
            if (func_00282DB0(&to_lead, &side) < 0.0f)
                angle = -angle;
            turn = dist / vars->speed;
            turn = turn * func_00283198(angle);
            while (turn > 1.0f)
                turn -= 1.0f;
            while (turn < -1.0f)
                turn += 1.0f;
            turn = func_002831B0(turn);
            func_00282D30(&to_lead, &to_lead, -1.0f);
            func_00282F20(&to_lead, &to_lead, 1.0f);
            if (func_00282C48(turn) > 0.00001f) {
                func_00282F20(&quat, &axis, 1.0f);
                func_002AB668(&quat, &quat, turn);
                func_002ACDE8(&self->m[0], &to_lead, &quat);
                func_00282DD8(&self->m[1], &self->m[0], &fwd);
                func_00282F20(&self->m[1], &self->m[1], 1.0f);
                func_00282DD8(&self->m[2], &self->m[1], &self->m[0]);
                qcopy(&vars->heading, &self->m[0]);
            }
        }
      }
    } else {
        func_002FEE70(vars->effect, &vars->heading, 0);
        qcopy(&self->m[0], &vars->heading);
        func_00282DD8(&self->m[1], &self->m[0], &fwd);
        func_00282F20(&self->m[1], &self->m[1], 1.0f);
        func_00282DD8(&self->m[2], &self->m[1], &self->m[0]);
    }

    if (target != 0) {
        vars->aim[0] = aim.x;
        vars->aim[1] = aim.y;
        vars->aim[2] = aim.z;
    }

    if (func_00282C48(vars->spin) > 0.0021f) {
      {
        Vec4_0040A4A8 quat;

        qcopy(dir, &self->m[0]);
        func_002AB668(&quat, &self->m[1], vars->spin * 0.017453294f);
        func_002ACDE8(&self->m[0], &self->m[0], &quat);
        func_002ACDE8(&self->m[2], &self->m[2], &quat);
        func_002AB668(&quat, dir, vars->roll);
        func_002ACDE8(&self->m[0], &self->m[0], &quat);
        func_002ACDE8(&self->m[1], &self->m[1], &quat);
        func_002ACDE8(&self->m[2], &self->m[2], &quat);
        func_002AB668(&quat, &self->m[0], vars->roll);
        func_002ACDE8(&self->m[1], &self->m[1], &quat);
        func_002ACDE8(&self->m[2], &self->m[2], &quat);
        vars->roll = func_00283B98(vars->roll, vars->roll_rate * 0.017453294f);
      }
    }

    self->m[0].w = self->m[1].w = self->m[2].w = 0.0f;
    func_00282D30(dir, &self->m[0], vars->speed);
    func_00282CC0(&self->pos, &self->pos, dir);
    func_00300190(&self->pos, &self->pos);

    if (self->pos.x < 2.0f || self->pos.x > 1021.0f || self->pos.y < 2.0f || self->pos.y > 1021.0f
        || self->pos.z < 2.0f || self->pos.z > 1021.0f) {
        func_002ACAD0(self, D_L00_001B1FB0);
        func_0029F338(self);
        return;
    }

    {
        Vec4_0040A4A8 sample;
        Vec4_0040A4A8 from;
        Vec4_0040A4A8 to;
        Query_0040A4A8 query;
        Vec4_0040A4A8 *trail;
        int i;

        func_L00_0040B2C0(self, &sample);
        trail = D_L00_00255BA0[vars->trail];
        for (i = 3; i > 0; i--)
            qcopy(&trail[i], &trail[i - 1]);
        qcopy(&trail[0], &sample);
        if (++vars->steps >= 4)
            ref_L00_0040A4A8_00(func_L00_0040B330, self);
        func_L00_0040B098(self, &saved);
        qcopy(&from, &self->pos);
        func_00282D30(&to, &fwd, -0.3f);
        func_00282CC0(&to, &self->pos, &to);
        if (func_002761F8(&from, &to, 2, 0, 0) != 0) {
            func_00282D30(&from, &fwd, 0.3f);
            func_00282CC0(&self->pos, &D_L00_001BF200.pos, &from);
        }
        query.mask = 0x830000;
        query.moby = self;
        query.one = 1;
        query.radius = D_L00_00262570[D_00139568.index].radius;
        qcopy(&query.dir, dir);
        func_00282F20(&query.dir, &query.dir, 1.0f);
        query.dir.w = 5627.925f;
        query.a = 3;
        query.b = 1;
        query.c = self->aa;
        if (func_002761F8(&saved, &self->pos, 0, ((Hero_0040A4A8 *)D_00189E20)->ptr[0x2290 / 4], &query) != 0) {
            if (D_L00_001BF200.moby != 0) {
                if (D_L00_001BF200.moby != ((Hero_0040A4A8 *)D_00189E20)->ptr[0x2290 / 4]
                    && D_L00_001BF200.moby != vars->owner) {
                    self->hit = 2;
                    qcopy(&self->pos, &D_L00_001BF200.pos);
                    hitter = self;
                }
            } else if (D_L00_001BF200.count > 0) {
                self->hit = 1;
                qcopy(&self->pos, &D_L00_001BF200.pos);
            }
        }

        if (self->hit != 0) {
            Vec4_0040A4A8 up;
            Vec4_0040A4A8 normal;
            int stick;

            if (vars->sound != -1) {
                e = (Emitter_0040A4A8 *)(D_00188660 + vars->sound * 0x70);
                if (e->owner == self && e->active != 0)
                    func_002E59F8(vars->sound);
            }
            vars->sound = -1;
            func_002E5CF8(0, 0, self);
            qcopy(&self->pos, &D_L00_001BF200.pos);
            func_002AFFD8(&self->pos, &up, 1);
            stick = 1;
            if (D_L00_001BF200.moby != 0 && D_L00_001BF200.count <= 0) {
                func_00282CF0(&normal, &D_L00_001B8DC0, &self->pos);
                func_00282F20(&normal, &normal, 1.0f);
            } else {
                func_00282F20(&normal, &D_L00_001BF200.normal, 1.0f);
                if (func_00282C48(func_00282DB0(&normal, &up)) >= 0.1f)
                    stick = 0;
            }
            if (stick)
                func_002A89A8(&self->pos, 0, 0.5f);
            func_L00_00414020(0.5f, &self->pos, 1, 0xF, 0, 0, 8, 0xF, 0, 1, 0, func_002A77E0(5) == 0,
                              D_L00_001ADB2C[0]);
            func_L00_0040AFB8(self, &up, hitter);
            func_002ACAD0(self, D_L00_001B1FB0);
            func_002FEE50(vars->effect);
            func_0029F338(self);
        } else if (func_00282978(&vars->timer) != 0 || func_00282E80(&self->pos, &D_00189EA0) > 60.0f) {
            if (vars->sound != -1) {
                e = (Emitter_0040A4A8 *)(D_00188660 + vars->sound * 0x70);
                if (e->owner == self && e->active != 0)
                    func_002E59F8(vars->sound);
            }
            vars->sound = -1;
            func_002ACAD0(self, D_L00_001B1FB0);
            func_002FEE50(vars->effect);
            func_0029F338(self);
        }
    }
}
