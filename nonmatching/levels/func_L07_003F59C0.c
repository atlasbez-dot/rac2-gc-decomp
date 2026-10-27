/* func_L07_003F59C0 (396 B, 1 place), M31 26 Oct 2026: 384 of 396 bytes as
   L07_003F59C0-g8.c with -O2 -G8 -ffunction-sections -g. Left: (1) retail keeps the
   div-by-zero trap on % 60 and rematerialises li 60 at both uses, so 60 was a variable cc1
   could not fold (here it lands in $s0); (2) func_L01_0031AB20 argument setup: retail loads
   f12..f14 before a2, so its float parameters likely precede the int. */
#include "include_asm.h"
#include "common.h"

typedef int TI __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x24];
    f32 f24;
} Class3F59C0;

typedef struct {
    u8 pad00[0x50];
    u8 path[0x38];
    f32 f88;
    u8 pad8C[0xA0 - 0x8C];
    u8 spin[0xDC - 0xA0];
    s32 flags;
    s32 node;
} Vars3F59C0;

typedef struct {
    u8 pad00[0x10];
    f32 pos[4];
    u8 state;
    u8 pad21[3];
    Class3F59C0 *cls;
    u8 pad28[4];
    f32 f2C;
    u8 pad30;
    u8 spinning;
    u8 pad32[2];
    u16 flags;
    u8 pad36[0x68 - 0x36];
    Vars3F59C0 *vars;
    u8 pad6C[0x78 - 0x6C];
    s32 f78;
    u8 pad7C[0xF0 - 0x7C];
    f32 rot[4];
} Moby3F59C0;

extern s32 D_L07_001B0F30 __attribute__((sda));
extern s32 D_L07_001B0F34[] __attribute__((sda));
extern f32 D_L07_001B0F38 __attribute__((sda));
extern f32 D_L07_001B0F3C __attribute__((sda));
extern f32 D_L07_001B0F40 __attribute__((sda));
extern f32 D_L07_001B0F44 __attribute__((sda));
extern s32 D_L07_001B1E08 __attribute__((sda));

extern void func_00282CF0(void *, void *, void *);
extern float func_00283CE0(int);
extern void func_002A7750(void *, int, int);
extern void func_002AD6F0(void *, void *, void *, void *);
extern void func_L01_0031AB20(void *, void *, s32, f32, f32, f32);
extern s32 func_L01_0031BC68(s32, s32, f32);
extern void func_L07_003F5B50(void *);

void func_L07_003F59C0(Moby3F59C0 *self) {
    f32 old[4] __attribute__((aligned(16)));
    f32 oldRot[4] __attribute__((aligned(16)));
    f32 d[4] __attribute__((aligned(16)));
    Vars3F59C0 *vars = self->vars;
    f32 t;
    s32 period = 60;

    qcopy(old, self->pos);
    qcopy(oldRot, self->rot);
    self->f2C = self->cls->f24 * D_L07_001B0F44;
    switch (self->state) {
    case 0:
        self->flags |= 0x1000;
        vars->f88 = 9.0f;
        vars->flags |= 1;
        func_002A7750(self, 1, -1);
        break;
    case 1:
        func_L01_0031AB20(self, vars->path, vars->node, D_L07_001B0F38, D_L07_001B0F3C, D_L07_001B0F40);
        func_L07_003F5B50(self);
        break;
    }
    if (self->spinning != 0) {
        t = func_00283CE0(D_L07_001B1E08 % period) * 6.2831855f;
        self->f78 = func_L01_0031BC68(D_L07_001B0F30, D_L07_001B0F34[0], t / func_00283CE0(60) - 3.1415927f);
    }
    func_00282CF0(d, self->pos, old);
    func_002AD6F0(vars->spin, d, oldRot, self->rot);
}
