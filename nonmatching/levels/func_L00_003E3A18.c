/* Retained nonmatching C (Opus big40), measured 26 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -g (a `-g8.c` unit; the -g nop pairs before div.s).
 * us 0/27. 2796/2796 bytes, about 29 instruction lines differ, all register choices.
 * Agrees: control flow, frame, the scope state switch, the zoom clamp, the lock-on test,
 * the buffer setup, the flash light. Forms: the zoom camera block 0x1B05C4..D0 as four
 * sized sda floats ($gp everywhere); 0x1B15CC..D8 as MACRO_ADDR scalars (lui $at in
 * flow, $gp in delay slots; scalars, so their loads move over the ScopeVars stores as in
 * retail); D_L00_001AA0F8 and D_L00_001B19C8 as incomplete sda arrays; func_00291308 is
 * declared (pos, float, float, colour) because retail sets $f12 before $a1 (its own code
 * reads a1 as the colour; the int position is not proven).
 * Left: the flash-light block: retail computes &end once into $s1 before the
 * HERO 0x24EC test (both arms call func_0029FCC0) and keeps the hero base in $s4 across
 * that call; here &end is computed per arm with a PRE copy to $s4 and the hero base gets
 * $s1. A pointer variable for &end (set before the test or in both arms) reorders the
 * whole allocation (moby moves from $s3 to $s4).
 * The permuter refused the job: its prep strips the sda/MACRO_ADDR attributes.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad quad; float f[4]; } Vector;
typedef union { u8 b[0x2600]; s16 h[0x1300]; s32 i[0x980]; u32 u[0x980]; f32 f[0x980]; char *ptr[0x980]; Quad q[0x260]; } Hero;

typedef struct Moby Moby;
struct Moby {
    u8 pad00[0x10];
    Vector position;
    u8 state;
    u8 pad21[3];
    struct { u8 pad00[0x46]; s16 kind; } *model;
    u8 pad28[9];
    u8 alive;
    s16 health;
    u8 pad34[0xE];
    u8 animation;
    u8 nextAnimation;
    u8 pad44[0x1C];
    u8 flags;
    u8 pad61[7];
    void *vars;
    u8 pad6C[0x3E];
    s16 objectClass;
    u8 padAC[0x14];
    Vector right;
    Vector forward;
    Vector up;
};

typedef struct {
    s16 zoomed;
    s16 fireTimer;
    float cooldown;
    float zoomFar;
    float zoom;
    int light;
    int lightTimer;
    int effect;
    int sound;
    char *buffers;
    int unknown24;
    s16 locked;
    s16 blink;
    Moby *lockTarget;
} ScopeVars;

typedef struct { float radius, spread, power, reserved; Vector position; } ScopeLight;
typedef struct { u8 pad00[0x54]; float rate; u8 pad58[0x88]; } WeaponEntry;
typedef struct { int unknown00[6]; Moby *hit; } CollisionResult;

extern u8 D_00189E20[], D_00139568[];
extern u32 D_00138180[];
extern u32 D_00138320 NOT_SDA;
extern float D_L00_001B05C4 __attribute__((sda)), D_L00_001B05C8 __attribute__((sda));
extern float D_L00_001B05CC __attribute__((sda)), D_L00_001B05D0 __attribute__((sda));
extern float D_L00_001B15CC MACRO_ADDR;
extern float D_L00_001B15D0 MACRO_ADDR;
extern float D_L00_001B15D4 MACRO_ADDR;
extern float D_L00_001B15D8 MACRO_ADDR;
extern int D_L00_001AA0F8[] __attribute__((sda));
extern int D_L00_001B19C8[] __attribute__((sda));
extern float D_L00_001BD370 NOT_SDA;
extern Vector D_L00_001B8DC0[];
extern CollisionResult D_L00_001BF200;
extern ScopeLight D_L00_001C6F40[];
extern WeaponEntry D_00262570[];
extern u8 D_00296AA0[];

extern void func_002A75E0(void *, int, int, int, int);
extern void func_0026FF08(int, int, float, float, float, float);
extern void func_00291450(int);
extern void func_L00_00368F58(int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, int);
extern float *func_002AB1F0(Moby *);
extern int func_002ABB78(Moby *);
extern int func_L00_002D4040(int);
extern void func_00273318(void *, float, unsigned int, void *, int, float, int, float, int);
extern float func_00283248(float, float);
extern int func_L00_00329E90(Moby *, int, int *);
extern char *func_L00_0032A088(int, int);
extern int *func_L00_0032A0B8(int, int);
extern char *func_L00_00329FF0(char *);
extern void func_00282A88(void *, int);
extern void func_L00_003F5658(int);
extern void func_L00_002C42E0(int, int);
extern int func_00282948(int *);
extern int func_L00_002D3F30(int, int);
extern void func_L00_002AF568(void);
extern int func_L00_002D6998(void *);
extern void func_002A7470(void *, int, int, int);
extern int func_002E5CF8(int, int, void *);
extern void func_L00_002D6B70(int);
extern int func_00282978(short *);
extern void func_L00_003E4508(Moby *);
extern int func_002829D8(void *);
extern s16 func_00291308(void *, float, float, unsigned int);
extern void func_0029FCC0(void *, int, void *);
extern float func_00283CE0(int);

#define HERO ((Hero *)D_00189E20)

/* The sniper scope: zoom, lock-on marker, the shot and its flash light. */
void func_L00_003E3A18(Moby *moby)
{
    ScopeVars *vars = moby->vars;
    Vector position, end, offset;
    int found;
    int ready;

    if (moby->animation == moby->nextAnimation && (moby->flags & 2))
        func_002A75E0(moby, 1, 0, 2, 0);
    if (HERO->i[0x1244 / 4] == 3) {
        if (moby->state != 0) {
            D_L00_001B15D0 = D_L00_001B05C4;
            D_L00_001B15D4 = D_L00_001B05C8;
            D_L00_001B15D8 = D_L00_001B05CC;
            D_L00_001B15CC = D_L00_001B05D0;
            func_0026FF08(0, 3, 1.1243411f, 0.005f, 0.2f, 0.0f);
            if (vars->light >= 0)
                func_00291450(vars->light);
            vars->light = -1;
            D_L00_001AA0F8[0] = 0xE0;
            func_L00_00368F58(1);
        }
        return;
    }
    if (HERO->i[0x2294 / 4] == 0x6F) {
        if (moby->state != 4) {
            moby->state = 4;
            if (vars->light >= 0)
                func_00291450(vars->light);
            vars->light = -1;
            D_L00_001B15D0 = D_L00_001B05C4;
            D_L00_001B15D4 = D_L00_001B05C8;
            D_L00_001B15D8 = D_L00_001B05CC;
            D_L00_001B15CC = D_L00_001B05D0;
            func_0026FF08(0, 3, 1.1243411f, 0.005f, 0.2f, 0.0f);
            func_L00_00368F58(1);
        }
        return;
    }
    if (moby->state == 4)
        moby->state = 1;
    qcopy(&position, &moby->position);

    if (HERO->i[0x1500 / 4] != 0) {
        if (D_L00_001B19C8[0] & 4) {
            vars->lockTarget = 0;
            vars->locked = 0;
            func_00282F20(&end, &D_L00_001B8DC0[0x23], 128.0f);
            func_00282CC0(&end, &end, &D_L00_001B8DC0[0]);
            if (func_002761F8(&D_L00_001B8DC0[0], &end, 0x10, HERO->ptr[0x2290 / 4], 0)) {
                Moby *hit = D_L00_001BF200.hit;
                if (hit != 0 && hit->alive) {
                    float *hp = func_002AB1F0(hit);
                    if (func_002ABB78(hit) ||
                        (hp != 0 && *hp > 0.0f && hit->model != 0 && hit->model->kind == 5)) {
                        vars->lockTarget = hit;
                        vars->locked = 1;
                    }
                }
            }
        }
        if (HERO->i[0x2534 / 4] == 0) {
            unsigned int color;
            if (vars->locked != 0) {
                if (++vars->blink > 20)
                    vars->blink = 0;
                if (vars->cooldown <= 0.0f && func_L00_002D4040(-1) && vars->blink >= 11)
                    func_00273318(moby, 1.5f, 0x400000FF, 0, 0x20, 0.0f, -1, 90.0f, 4);
            }
            if (vars->cooldown > 0.0f && func_L00_002D4040(-1))
                color = 0x600000FF;
            else
                color = 0x600FFF0F;
            func_00273318(moby, 2.0f, color, 0, 0x27, 0.0f, -1, 90.0f, 4);
        }
    }

    switch (moby->state) {
    case 0: {
        float zoom;
        vars->zoomed = 0;
        vars->cooldown = 0.36666667f;
        moby->state = 3;
        zoom = func_00283248(1.0f, D_L00_001BD370);
        zoom = zoom + zoom;
        vars->zoomFar = zoom;
        vars->zoom = zoom + (0.17453295f - zoom) * 0.25f;
        D_L00_001B05C4 = D_L00_001B15D0;
        D_L00_001B05C8 = D_L00_001B15D4;
        D_L00_001B05CC = D_L00_001B15D8;
        D_L00_001B05D0 = D_L00_001B15CC;
        vars->lightTimer = 0;
        vars->locked = 0;
        vars->blink = 0;
        vars->lockTarget = 0;
        vars->light = -1;
        vars->effect = func_L00_00329E90(moby, 0, &found);
        if (found == 0) {
            char *base, *p;
            int *offsets;
            int i;
            p = func_L00_0032A088(moby->objectClass, vars->effect);
            vars->buffers = p;
            base = p;
            offsets = func_L00_0032A0B8(moby->objectClass, vars->effect);
            p = func_L00_00329FF0(base + 0xC);
            for (i = 0; i < 3; i++) {
                ((char **)base)[i] = p;
                p += 0xF00;
            }
            p = func_L00_00329FF0(p);
            offsets[0] = p - base;
            func_00282A88(p, 0x120);
            p = func_L00_00329FF0(p + 0x120);
            offsets[1] = p - base;
            func_00282A88(p, 0x1E00);
        }
        if (vars->effect >= 0)
            func_L00_003F5658(vars->effect);
        break;
    }
    case 1:
        if (HERO->i[0x2294 / 4] == 1)
            func_L00_002C42E0(0x1D, 1);
        if (HERO->i[0x1500 / 4] != 0) {
            if (vars->zoomed == 0)
                D_L00_001AA0F8[0] = 0;
            vars->zoomed = 1;
        }
        if (HERO->i[0x1450 / 4] != 0)
            HERO->i[0xBF8 / 4] = HERO->i[0x1450 / 4];
        if (HERO->i[0x1500 / 4] != 0) {
            u32 pad = D_00138320;
            if (pad & 8)
                vars->zoom -= 0.01f;
            else if (pad & 2)
                vars->zoom += 0.01f;
            if (vars->zoom > vars->zoomFar)
                vars->zoom = vars->zoomFar;
            else if (vars->zoom < 0.17453295f)
                vars->zoom = 0.17453295f;
            func_0026FF08(0, 3, vars->zoom, 0.02f, 0.2f, 0.0f);
            func_L00_00368F58(0);
        } else if (vars->zoomed != 0) {
            float zoom = vars->zoomFar;
            vars->zoom = zoom + (0.17453295f - zoom) * 0.25f;
            func_0026FF08(0, 3, zoom, 0.005f, 0.2f, 0.0f);
            vars->zoomed = 0;
            D_L00_001AA0F8[0] = 0xE0;
            func_L00_00368F58(1);
        }
        {
            float t = (vars->zoom - 0.17453295f) / (vars->zoomFar - 0.17453295f);
            D_L00_001B15D0 = (D_L00_001B05C4 - 0.03f) * t + 0.03f;
            D_L00_001B15D4 = (D_L00_001B05C8 - 0.4f) * t + 0.4f;
            D_L00_001B15CC = (D_L00_001B05D0 - 0.010471977f) * t + 0.010471977f;
        }
        ready = 1;
        if (HERO->i[0x1500 / 4] != 0) {
            if (!func_00282948(&HERO->i[0x2534 / 4]))
                ready = 0;
        } else {
            HERO->i[0x2534 / 4] = 0x28;
        }
        if (HERO->b[0x22BC] == 0 && (D_00138180[0x1A4 / 4] & HERO->u[0x1230 / 4]) && ready) {
            if (func_L00_002D3F30(-1, 1)) {
                func_L00_002AF568();
                vars->sound = func_L00_002D6998(D_00296AA0);
                vars->fireTimer = 2;
                moby->state = 2;
                func_002A7470(moby, 2, 0, 0);
            } else {
                func_002E5CF8(1, 0, moby);
            }
            if (!((D_00138180[0x1A0 / 4] & HERO->u[0x1230 / 4]) && func_L00_002D4040(-1) && HERO->b[0x22B8]) &&
                vars->sound >= 0) {
                func_L00_002D6B70(vars->sound);
                vars->sound = -1;
            }
        }
        break;
    case 2:
        if (HERO->i[0x1450 / 4] != 0)
            HERO->i[0xBF8 / 4] = HERO->i[0x1450 / 4];
        if (func_00282978(&vars->fireTimer) || vars->zoomed != 0) {
            WeaponEntry *weapon;
            func_002E5CF8(0, 0, moby);
            func_L00_003E4508(moby);
            weapon = D_00262570 + D_00139568[0x17];
            vars->cooldown = 1.0f / weapon->rate;
            moby->state = 3;
        }
        break;
    case 3:
        if (func_002829D8(&vars->cooldown))
            moby->state = 1;
        break;
    }

    if (vars->lightTimer != 0) {
        if (func_00282948(&vars->lightTimer)) {
            if (vars->light >= 0)
                func_00291450(vars->light);
            vars->light = -1;
        } else {
            if (vars->light == -1)
                vars->light = func_00291308(&moby->position, 10.0f, 0.0f, 0xFF0000FF);
            if (vars->light >= 0) {
                Vector *axis;
                float scale;
                float fade;
                if (HERO->h[0x24EC / 2] == 1) {
                    func_0029FCC0(moby, 0, &end);
                    scale = -1.5f;
                    axis = &moby->forward;
                } else {
                    func_0029FCC0(moby, 0, &end);
                    scale = 1.5f;
                    axis = (Vector *)&HERO->q[0x760 / 16];
                }
                func_00282F20(&offset, axis, scale);
                func_00282CC0(&D_L00_001C6F40[vars->light].position, &end, &offset);
                D_L00_001C6F40[vars->light].position.f[3] = 10.0f;
                fade = func_00283CE0(vars->lightTimer) / func_00283CE0(30);
                D_L00_001C6F40[vars->light].radius = fade;
                D_L00_001C6F40[vars->light].spread = fade * 0.7f;
                D_L00_001C6F40[vars->light].power = 0.0f;
            }
        }
    }
}
