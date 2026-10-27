/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * Compiled 3720 bytes; retail 3716 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: Integer charge/age fields, complete effect vectors, the 48-byte rotation output and
 * existing 16-byte effect blocks/12-byte color view remain. Every color shift first converts its
 * component to u32. The absolute LD/SD at D_L23_001A8AC8 is a scalar 64-bit field view,
 * replacing the old two-element extent; this reduces 3728 to 3720 bytes while frame 0x150
 * agrees. Emitter ownership globals and random-vector output use pointers; the 82 static call
 * sites remain but phase order and allocation differ.
 * Reopen: Independent emitter/particle phase lifetime evidence preserving the actual
 * pointer/FP/stack contracts and all true data widths.
 */

#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef struct ProjectileEffectState {
    float velocity[4] __attribute__((aligned(16)));
    int charge_ticks;
    int age_ticks;
    u8 pad_18[0x2C - 0x18];
    short light_index;
    short restart;
    float frame_vector[4];
    short kind;
    short pad_42;
    int use_custom_velocity;
    u8 pad_48[8];
    float custom_velocity[4];
} ProjectileEffectState;
typedef struct Vec16_F5621621c { float x, y, z, w; } Vec16_F5621621c;
/* Partial resident player layout, with offsets established by these retail uses. */
typedef struct PlayerView {
    u8 pad_0000[0x98];
    float heading;
    u8 pad_009C[0x2290 - 0x9C];
    u8 *object;
    u8 pad_2294[0x22B4 - 0x2294];
    u8 mode;
} PlayerView;
extern PlayerView D_00189E20;
extern int D_L23_001A8FF0;
extern u8 *D_L23_001B1954 __attribute__((sda)), *D_L23_001B1958 __attribute__((sda));
extern int D_L23_001B194C __attribute__((sda)), D_L23_001B1950 __attribute__((sda));
extern float D_L23_001B1934 __attribute__((sda)), D_L23_001B1938 __attribute__((sda));
extern int D_L23_001A8AB0[4] __attribute__((sda));
extern int D_L23_001A8AC0[4] __attribute__((sda));
extern u32 D_L23_001A8AC4[3] __attribute__((sda));
/* The measured absolute LD/SD is the 64-bit field inside the 16-byte effect block. */
extern u64 D_L23_001A8AC8 NOT_SDA;
extern u32 D_L23_001B22C8;
extern u8 D_L23_001C87C0[];
extern u8 D_L23_001C4B00[];
extern float D_L23_001B3704;
extern u8 *D_L23_002001EC;
extern float D_L23_001A8F20[4];
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CD8(void *, void *, void *);
extern void func_L22_003398B8(u32, void *, void *);
extern void func_L22_00334F78(void *, int, int, int, int, float, float);
extern short func_00291308(Quadword *, int, float, float);
extern int func_L00_0035F5A0(int, int, int);
extern void func_002E59F8(int);
extern float func_00283180(float), func_00283198(float);
extern void func_00282D30(void *, void *, float);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282DD8(void *, void *, void *);
extern float func_00282DF0(void *), func_00282C10(float);
extern void func_00283958(void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_00291450(int);
extern void func_0029F338(void *);
extern int func_00277F48(void *, int, void *, void *, float);
extern void func_002A9850(void *, Vec16_F5621621c *, int *, int, int, int, int, int, float, float, float);
extern void *func_0032C700(void *, int, int, int, int, int, int, int, float, float, int, int, int, void *);
extern void func_L04_00358868(void *, u32, int, int, float);
extern void func_002A7988(float *, float, float);
extern void func_002BCB00(void *, void *, u32, u32, int, int, int, int, int, float);
extern u8 *func_L08_0034A078(void *, void *, int, void *);
extern int func_002A77E0(int);
extern void func_L00_00325600(void *, void *, void *);
#define LIGHT ((float *)(D_L23_001C87C0 + vars->light_index * 0x20))

void func_L23_004236B8(u8 *object) {
    float particle[4] __attribute__((aligned(16))), velocity[4], offset[4], motion[4];
    float rotation[12] __attribute__((aligned(16))), perpendicular[4], scaled[4], normalized[4];
    ProjectileEffectState *vars = *(ProjectileEffectState **)(object + 0x68);
    u8 **word = &D_L23_001B1958;
    int i, red, green, blue, alpha, ticks, hit, count, side;
    u8 *emitter;
    float strength, spread, radius, extent, value, sign;
    float *position;
    {
        PlayerView *player = &D_00189E20;
        if (*(u8 **)(object + 0xB8) == player->object) word = &D_L23_001B1954;
    }
    switch (object[0x20]) {
    case 0: goto charge;
    case 1: goto flight;
    default: goto finish;
    }
charge: {

        if (vars->restart == 0) {
            D_L23_001A8AB0[0] = 0;
            goto launch;
        }
        if (D_00189E20.mode != 2 && vars->kind != 0) {
            D_L23_001A8AB0[0] = 0;
            goto launch;
        }
        if (vars->charge_ticks == 0 && word == &D_L23_001B1958) {
            D_L23_001A8AC0[0] = 1;
            D_L23_001A8AC4[0] = 0xFFFF00;
        }
        ++vars->charge_ticks;
        strength = func_00283CE0(vars->charge_ticks) * 0.033333335f;
        if (strength > 1.0f) strength = 1.0f;
        spread = 5.0f;
        if (vars->kind) spread = 10.0f;
        i = 0;
        while (i < func_00283CF0(strength * strength * spread)) {
            *(Quadword *)velocity = 0;
            velocity[0] = func_002A7878(-1.0f, 1.0f);
            velocity[1] = func_002A7878(-1.0f, 1.0f);
            qcopy(particle ,velocity);
            particle[2] = func_002A7878(-1.0f, 1.0f);
            velocity[2] = particle[2];
            if (vars->kind == 0) {
                blue = 0x6F;
                green = 0x1F;
                red = 0xF;
            } else {
                blue = 0x4F;
                green = 0xAF;
                red = 0xFF;
            }
            green = func_002A7820(blue, green);
            red = func_002A7820(blue, red);
            if (red > 255) red = 255;
            if (green > 255) green = 255;
            radius = func_002A7878(15.0f, 30.0f);
            func_00282F20(particle, particle, radius);
            func_00282CD8(velocity, particle, ((float *)(object + 0x10)));
            func_L22_003398B8((((u32)green << 8) | 0x7F000000) | ((u32)red << 16) | blue, particle, object);
            ++i;
        }
        if (vars->charge_ticks < 50) {
            alpha = D_L23_001A8AC4[0] >> 24;
            if (D_L23_001A8AC8 == 0 && alpha == 255) alpha = 37;
            ticks = alpha + 1;
            if (alpha > 35) ticks = 37;
            D_L23_001A8AC8 = 0x1F00000042LL;
            D_L23_001A8AC4[0] = (D_L23_001A8AC4[0] & 0xFFFF00) | ((u32)ticks << 24);
        } else D_L23_001A8AC4[0] |= 0xFF000000;
        if (vars->light_index == -1) {
            if (!(D_L23_001B22C8 & 3)) vars->light_index = func_00291308((Quadword *)((float *)(object + 0x10)), 0, 0, 0);
        } else {
            LIGHT[4] = ((float *)(object + 0x10))[0];
            LIGHT[5] = ((float *)(object + 0x10))[1];
            LIGHT[6] = ((float *)(object + 0x10))[2];
            ticks = vars->charge_ticks;
            if (ticks > 50) ticks = 50;
            if (ticks < 0) ticks = 0;
            LIGHT[7] = func_00283CE0(ticks) * 0.14f;
            strength = func_00283CE0(vars->charge_ticks) * 0.033333335f;
            if (strength > 1) strength = 1;
            side = vars->light_index;
            red = (u8)func_002A7820(15, 47);
            green = (u8)func_002A7820(47, 63);
            blue = (u8)func_002A7820(63, 127);
            func_L22_00334F78(D_L23_001C87C0 + side * 32 + 16, red, green, blue, 20, strength * 840000.0f, 0);
            LIGHT[0] = func_002A7878(LIGHT[0] * 0.8f, (LIGHT[7] + LIGHT[7]) * 0.14285715f);
            value = LIGHT[0];
            strength = LIGHT[1] * 0.8f;
            if (strength >= value) strength = value;
            LIGHT[1] = func_002A7878(strength, value);
        }
        goto finish;
    launch:
        D_L23_001A8AC0[0] = 0;
        vars->charge_ticks = 0;
        func_L00_0035F5A0(22, 0, 0);
        if (vars->kind == 0) {
            if (D_L23_001B1950 != -1) {
                func_002E59F8(D_L23_001B1950);
                D_L23_001B1950 = func_L00_0035F5A0(21, 0, 0);
            }
        } else if (D_L23_001B194C != -1) {
            func_002E59F8(D_L23_001B194C);
            D_L23_001B194C = func_L00_0035F5A0(21, 0, 0);
        }
        if (D_L23_001A8FF0 == 0) {
            vars->velocity[0] = func_00283180(D_00189E20.heading) * 0.6666667f;
            vars->velocity[1] = func_00283198(D_00189E20.heading) * 0.6666667f;
            vars->velocity[2] = 0;
        } else func_00282D30(vars, object + 0xC0, 2.0f);
        object[0x20] = 1;
        vars->age_ticks = 0;
        goto finish;
    }
flight:
    position = (float *)(object + 0x10);
    radius = func_00283CE0(vars->age_ticks);
    ++vars->age_ticks;
    radius = radius * 0.33333334f + 1.3f;
    extent = radius + 3.5f;
    func_002AFFD8((char *)position, (char *)offset, 1);
    if (vars->kind == 0) func_00282F20(motion, object + 0xC0, 3.5f);
    else func_00282F20(motion, object + 0xC0, 2.0f);
    func_00282F20(scaled, offset, 1.0f);
    func_00282DD8(perpendicular, object + 0xE0, scaled);
    value = D_L23_001B1938;
    if (vars->kind == 0) value = D_L23_001B1934;
    func_00282D30(perpendicular, perpendicular, value);
    sign = func_00282DF0(perpendicular);
    perpendicular[3] = -func_00282C10(1.0f - sign * sign);
    func_00283958(perpendicular, rotation);
    func_00283738(object + 0xC0, rotation, object + 0xC0);
    if (vars->use_custom_velocity) {
        if (vars->kind == 0) func_00282D30(motion, vars->custom_velocity, 1.0f);
        else func_00282D30(motion, vars->custom_velocity, 0.6666667f);
        func_00282F20(normalized, motion, 1.0f);
        qcopy((object + 0xC0) ,normalized);
    }
    qcopy(vars ,motion);
    if (vars->light_index != -1) {
        LIGHT[7] *= 0.39999998f;
        if (LIGHT[7] < 0.0001f) {
            func_00291450(vars->light_index);
            vars->light_index = -1;
        }
    }
    if (vars->age_ticks >= 51 || D_00189E20.mode != 2) goto retire;
    func_00282CD8(offset, position, vars);
    if (position[0] < 2.0f || position[0] > 1021.0f || position[1] < 2.0f || position[1] > 1021.0f || position[2] < 2.0f || position[2] > 1021.0f) goto retire;
    if (vars->kind == 0) {
        hit = func_00277F48(position, 16, *(u8 **)(object + 0xB8), 0, radius);
        qcopy(offset ,position);
        func_002A9850(object, (Vec16_F5621621c *)offset, (int *)D_L23_001C4B00, hit, 0, 0x8B0007, 2, 1, D_L23_001B3704, 1.0f, 1.0f);
        if (hit) func_0032C700(position, 0, 25, 20, 20, 20, 45, 1, 1.0f, 20.0f, 1, 0, 0, 0);
        value = extent * 105000.0f;
        count = 50 - vars->age_ticks;
        if (count > 5) count = 5;
        red = func_002A7820(15, 47);
        green = func_002A7820(47, 63);
        blue = func_002A7820(63, 127);
        func_L04_00358868(object, (((u32)green << 8) | 0x4F000000) | ((u32)red << 16) | blue, count, -1, value);
        func_002A7988(particle, extent * 0.016666668f, (extent + extent) * 0.016666668f);
        red = func_002A7820(15, 47);
        green = func_002A7820(31, 47);
        blue = func_002A7820(63, 127);
        func_002BCB00(position, particle, (((u32)green << 8) | 0x7F000000) | ((u32)red << 16) | blue, 0x4F1F1F7F, 45, 1, *D_L23_002001EC, -1, 0, 210000.0f);
    } else {
        hit = func_00277F48(position, 16, object, 0, radius);
        qcopy(offset ,position);
        func_002A9850(object, (Vec16_F5621621c *)offset, (int *)D_L23_001C4B00, hit, 0, 0x8B0000, 2, 1, D_L23_001B3704, 1.0f, 1.0f);
        if (hit) func_0032C700(position, 0, 25, 20, 20, 20, 45, 1, 1.0f, 20.0f, 1, 0, 0, 0);
        value = extent * 105000.0f;
        count = 50 - vars->age_ticks;
        if (count > 5) count = 5;
        red = func_002A7820(63, 127);
        green = func_002A7820(47, 63);
        blue = func_002A7820(15, 47);
        func_L04_00358868(object, (((u32)green << 8) | 0x4F000000) | ((u32)red << 16) | blue, count, -1, value);
        spread = extent + extent;
        func_002A7988(particle, extent * 0.016666668f, spread * 0.016666668f);
        red = func_002A7820(63, 127);
        green = func_002A7820(47, 63);
        blue = func_002A7820(15, 47);
        func_002BCB00(position, particle, (((u32)green << 8) | 0x7F000000) | ((u32)red << 16) | blue, 0x4F7F4F2F, 45, 1, *D_L23_002001EC, -1, 0, 210000.0f);
        i = 5;
        do {
            func_002A7988(particle, extent * 0.016666668f, spread * 0.016666668f);
            func_002A7988(velocity, 0, extent * 0.5f);
            func_00282CD8(offset, velocity, position);
            emitter = func_L08_0034A078(velocity, particle, 127, object);
            --i;
            if (emitter) *(float *)(emitter + 0xC) = func_002A7878(6000.0f, 32000.0f) * extent * 0.4f;
        } while (i >= 0);
        for (i = 0; i < 8; ++i) {
            emitter = func_L08_0034A078(position, D_L23_001A8F20, 127, object);
            if (emitter) {
                if (i == 2 && func_002A77E0(8) == 0) *(float *)(emitter + 0xC) = 180000.0f;
                else *(float *)(emitter + 0xC) = func_002A7878(80000.0f, 120000.0f);
                *(short *)(emitter + 10) = 2;
                *(float *)(emitter + 0xC) *= extent;
                *(short *)(emitter + 0x36) = 3;
                *(int *)(emitter + 0x38) = 0x7F7F7F;
                *(float *)(emitter + 0x30) = 1.0f / func_00283CE0(2);
            }
        }
    }
finish:
    if (D_L23_001A8FF0) {
        func_002AFFD8((char *)object + 0x10, (char *)vars->frame_vector, 0);
        func_L00_00325600(object + 0xC0, vars->frame_vector, 0);
    }
    vars->restart = 0;
    return;
retire:
    if (*(u8 **)(object + 0xB8) != D_00189E20.object) {
        if (D_L23_001B1950 != -1) {
            func_002E59F8(D_L23_001B1950);
            D_L23_001B1950 = -1;
        }
    } else if (D_L23_001B194C != -1) {
        func_002E59F8(D_L23_001B194C);
        D_L23_001B194C = -1;
    }
    func_0029F338(*word);
    *word = 0;
}
