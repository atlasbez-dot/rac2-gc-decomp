/* func_002914B8 (388 B, 28 places), M31 26 Oct 2026: as src/game/002914B8-g16.c with
   -O2 -G16 -Wa,-G16 -ffunction-sections (16-byte camera vector at $gp-0x5E60, boot). The
   listener part matches; in the channel loop retail walks two pointers straight at the pos
   fields (+0x20 stride 0x30, +0x10 stride 0x20, state at -0x10) and needs one saved
   register fewer. Per-program callee ref_L00_002FD068_00. */
#include "common.h"

typedef int TI __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x10];
    f32 pos[4];
} Emit2914B8;

typedef struct {
    u8 pad00[0x10];
    s32 state;
    u8 pad14[0xC];
    f32 pos[4];
} Chan2914B8;

typedef struct {
    u8 pad000[0x340];
    f32 pos[4];
    f32 dir[4];
} Snd2914B8;

extern TI D_001A9190 __attribute__((sda));
extern Snd2914B8 D_001C2740;
extern f32 D_001B5358[];
extern Emit2914B8 D_001C2B40[8];
extern Chan2914B8 D_001C2C40[8];

extern float func_00282C48(float);
extern float func_00282E48(void *, void *);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_00283B98(float, float);
extern void func_00291640(int);
extern void ref_L00_002FD068_00(int);

void func_002914B8(void) {
    Emit2914B8 *em;
    Chan2914B8 *ch;
    f32 ang;
    s32 i;

    qcopy(D_001C2740.pos, &D_001A9190);
    ang = func_00283B98(D_001B5358[0], -0.8f);
    D_001C2740.dir[0] = func_00283180(ang) * 0.866f;
    D_001C2740.dir[1] = func_00283198(ang) * 0.866f;
    D_001C2740.dir[2] = -0.5f;
    D_001C2740.dir[3] = 0.0f;
    em = D_001C2B40;
    ch = D_001C2C40;
    for (i = 0; i < 8; i++) {
        if (ch->state != 0) {
            if (1.0f < func_00282E48(em->pos, ch->pos) || 1.0f < func_00282C48(em->pos[3] - ch->pos[3])) {
                qcopy(ch->pos, em->pos);
                if (ch->state == 1) {
                    func_00291640(i);
                    ch->state = 2;
                } else if (ch->state == 2) {
                    ref_L00_002FD068_00(i);
                }
            }
        }
        ch++;
        em++;
    }
}
