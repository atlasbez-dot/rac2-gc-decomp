/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 1912/1932 bytes. us: 0/1 places; us2: absent; pal: absent.
 * Remaining: The actor-position snapshot uses real qcopy; signed short actor count,
 * three emission phases and all 47 terminal emissions are retained. Packed
 * color shifts use unsigned 32-bit operands, and grouped particle factories
 * retain pointer results and their GPR/FP input banks. The 0xC0 frame agrees;
 * cutscene high/base lifetime, mixed scalar accesses and loop allocation differ.
 * Retail genuinely reads the null-path class delay slot and consumes axis.X
 * without first initializing its stack word; these constraints are recorded
 * rather than silently replaced by initialization or new guards.
 * Reopen with: Independent cutscene-record and particle-loop lifetime evidence. A native
 * safety alternative for the recorded pre-initialization/low-memory reads must
 * be distinguished from this retained retail reconstruction.
 * Review correction: The overlapping float words at 0x1B2834/3C/40 are words 1/3/4 of the single incomplete D_L19_001B2830 array; no separate C objects or invented complete extent remain.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern int D_001A79F0 __attribute__((sda));
/* Retail addresses the cutscene record from this base, including its signed
 * 16-bit actor count and pointer slots. Its complete extent is not inferred. */
extern u8 D_L19_001BD740[];
#define CUT_STATE (*(int *)(D_L19_001BD740 + 0x30))
#define CUT_FRAME (*(int *)(D_L19_001BD740 + 0x34))
#define CUT_COUNT (*(short *)(D_L19_001BD740 + 0x44))
#define CUT_SLOTS ((u8 **)(D_L19_001BD740 + 0x18c))
#define CUT_PRIMARY (*(u8 **)(D_L19_001BD740 + 0x198))
#define CUT_SECONDARY (*(u8 **)(D_L19_001BD740 + 0x19c))
extern u8 *D_L19_001B2814 __attribute__((sda));
extern Vector D_L19_001B2820;
/* One observed float block: the earlier separate 2834/283C/2840
 * names alias words 1/3/4. Its complete external extent is unknown. */
extern float D_L19_001B2830[];
extern int D_L19_001B2844;
extern float D_L19_001B9A60;
extern int D_L19_001B9A68, D_L19_001B9A6C;
extern Vector D_L19_001A8F20;
extern void func_L00_002FC980(void);
extern void func_002E64A0(void *);
extern void func_L00_00326048(char *, float *, int, int, float);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern int func_00283D38(float, int, int);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AF000(float *, float, float, float);
/* The particle constructors consume three FP arguments independently of the
 * eight GPR arguments; their allocation result is returned in v0. */
extern void *func_002C7970(void *, void *, int, int, int, int, int, int, float, float, float);
extern void *func_002C7BB8(void *, void *, int, int, int, int, int, int, float, float, float);
extern void *func_002BDBC0(void *, void *, int, int, int, float);

void func_L19_002FA1A8(void)
{
    Vector position, direction, axis;
    u8 *actor;
    u8 **slot;
    int i;
    int color, life, style, red, gray;
    float speed, other, angle, pitch, radius;
    func_L00_002FC980();
    i = 0;
    slot = CUT_SLOTS;
    if (CUT_COUNT > 0) {
        do {
            actor = *slot;
            if (actor && *(short *)(actor + 0xaa) == 0xe29)
                *(unsigned short *)(actor + 0x34) |= 0x800;
            /* Retail reads this class in the normal null-branch delay slot;
             * the retained path assumes the same readable low-memory state. */
            if (*(short *)(actor + 0xaa) == 0xd54)
                func_002E64A0(actor);
            if (actor && *(short *)(actor + 0xaa) == 4000 && *(u8 **)(actor + 0x68))
                func_L00_00326048((char *)actor, (float *)(*(u8 **)(actor + 0x68) + 0xc), 0x80aaaad2, 0x80396464, 0.061086535f);
            ++i;
            ++slot;
        } while (i < CUT_COUNT);
    }
    if (D_001A79F0 == 19) {
        if (CUT_STATE == 4) {
            actor = D_L19_001B2814;
            if (CUT_FRAME == 1) {
                D_L19_001B2814 = CUT_PRIMARY;
                D_L19_001B2830[0] = 3.5f;
                D_L19_001B2830[1] = 11.0f;
                D_L19_001B2830[2] = 10.7f;
                D_L19_001B2830[3] = 0.0f;
                D_L19_001B2830[4] = 0.0f;
                D_L19_001B2844 = CUT_FRAME;
                actor = CUT_PRIMARY;
            }
            qcopy(&D_L19_001B2820, (actor + 0x10));
            if (CUT_FRAME == 750) {
                D_L19_001B9A60 = 1.0f;
                D_L19_001B9A68 = 15;
                D_L19_001B9A6C = 0;
            }
            if ((u32)(CUT_FRAME - 750) < 21) {
                D_L19_001B2830[4] += D_L19_001B2830[2];
                if (D_L19_001B2830[4] >= 1.0f) {
                    do {
                        direction.q = 0;
                        direction.f[1] = -0.72f;
                        direction.f[0] = 0.72f;
                        direction.f[3] = 1.0f;
                        color = ((u32)func_002A7820(96, 128) << 16) | 0x1e00;
                        position.f[0] = 0.0f;
                        position.f[1] = D_L19_001B2830[0] * func_002A7878(0.9f, 1.1f);
                        position.f[2] = 0.0f;
                        position.f[3] = 1.0f;
                        angle = func_002A7878(0.0f, 6.2831855f);
                        func_002ACEC0(&position, &position, &direction, angle);
                        func_00282CC0(&position, &position, &D_L19_001B2820);
                        func_00282F20(&direction, &direction, func_002A7878(1.5f, 2.5f));
                        func_00282CC0(&position, &position, &direction);
                        func_00282CC0(&position, &position, &direction);
                        D_L19_001B2830[4] = D_L19_001B2830[4] - 1.0f;
                        life = func_002A7820(4, 8);
                        speed = func_002A7878(0.6f, 0.8f) * 210000.0f;
                        func_002C7970(&position, &D_L19_001A8F20, 24, color, life, 128, 32, 0, speed, 21000.0f, 0.0f);
                        life = func_002A7820(4, 8);
                        speed = func_002A7878(0.6f, 0.8f) * 210000.0f;
                        style = func_002A7820(1, 7);
                        func_002C7970(&position, &D_L19_001A8F20, 24, color, life, 128, 32, style, speed, 21000.0f, 0.0f);
                    } while (D_L19_001B2830[4] >= 1.0f);
                }
            }
            if ((u32)(CUT_FRAME - 761) < 79) {
                D_L19_001B2830[3] = D_L19_001B2830[3] + D_L19_001B2830[1];
                if (D_L19_001B2830[3] >= 1.0f) {
                    do {
                        color = func_00283D38(func_002A7878(0.0f, 1.0f), 0x803c14, 0x400000);
                        position.f[2] = D_L19_001B2830[0] * -0.8f;
                        position.f[0] = 0.0f;
                        position.f[1] = 0.0f;
                        direction.f[1] = 0.0f;
                        direction.f[2] = 0.0f;
                        /* Retail first consumes axis.X without initializing its
                         * stack word; do not silently fabricate a zero here. */
                        axis.f[1] = 0.0f;
                        position.f[3] = 1.0f;
                        direction.f[0] = 1.0f;
                        direction.f[3] = 1.0f;
                        axis.f[2] = 1.0f;
                        axis.f[3] = 1.0f;
                        angle = func_002A7878(0.0f, 6.2831855f);
                        func_002ACEC0(&direction, &direction, &axis, angle);
                        angle = func_002A7878(0.0f, 1.5707964f);
                        func_002ACEC0(&position, &position, &direction, angle);
                        func_00282CC0(&position, &position, &D_L19_001B2820);
                        life = func_002A7820(22, 55);
                        style = func_002A7820(0, 10);
                        speed = func_002A7878(0.5f, 1.0f) * 21000.0f;
                        other = func_002A7878(0.7f, 1.0f) * 21000.0f;
                        func_002C7BB8(&position, &D_L19_001A8F20, life, color, style, 128, 0, 3, speed, other, 0.0033333334f);
                        D_L19_001B2830[3] = D_L19_001B2830[3] - 1.0f;
                    } while (D_L19_001B2830[3] >= 1.0f);
                }
            }
        }
        actor = CUT_SECONDARY;
        if (D_001A79F0 == 19 && CUT_STATE == 5 && CUT_FRAME == 1375) {
            i = 46;
            do {
                --i;
                radius = func_002A7878(0.0f, 0.37f);
                angle = func_002A7940();
                pitch = func_002A7940();
                func_002AF000(direction.f, radius, angle, pitch);
                func_00282CC0(&direction, &direction, actor + 0x10);
                radius = func_002A7878(0.006166667f, 0.023333333f);
                angle = func_002A7940();
                pitch = func_002A7940();
                func_002AF000(position.f, radius, angle, pitch);
                red = func_002A7820(47, 87);
                gray = func_002A7820(100, 220);
                speed = func_002A7878(70000.0f, 150000.0f);
                life = func_002A7820(13, 42);
                func_002BDBC0(&direction, &position, ((u32)red << 24) | ((u32)gray << 16) | ((u32)gray << 8) | gray,
                    ((u32)gray << 16) | ((u32)gray << 8) | gray, life, speed);
            } while (i >= 0);
        }
    }
}
