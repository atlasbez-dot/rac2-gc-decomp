/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L04_00416018-g8.c
 * Game compiler profile: -O2 -G8 -ffunction-sections -mno-split-addresses
 * Compiled/US retail bytes: 892/884.
 * Actual release checks: US: 0/2 (exit 1); US2: 0/2 (exit 1); PAL: catalogue absent (exit 1).
 * Residual: 0xa0 frame agrees but six saved FPRs replace five. Record addressing, point/age cursors, FP allocation and callback schedule differ.
 * Reopen only for: A concrete cursor/live-range model eliminating the extra saved FPR without artificial dependencies.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Eight-sample trail records; the retail loop visits 140 entries of stride 0x150. */
typedef unsigned int u32;
typedef unsigned int Quad416018 __attribute__((mode(TI)));
typedef struct Trail416018 {
    float points[8][4];
    float velocities[8][4];
    float origin[4];
    float *offset, *impulse;
    short ages[8], landed[8];
    int count, lifetime;
    u32 colour;
    int active;
    char *owner;
    int tail;
} Trail416018;
extern Trail416018 D_L04_00254E10[];
extern unsigned char D_00189E20[];
extern int D_L04_001B08F0;
extern void *D_L04_001B0914;
extern void func_00282CC0(float *, float *, float *);
extern void func_00282D30(float *, float *, float);
extern void func_00283098(float *, float *, char *);
extern int func_00282948(int *);
extern u32 func_00283D38(float, u32, u32);
typedef void (*TrailDrawCallback416018)(void *);
extern void func_L04_00415E28(void *);
extern void func_L00_002E6CF0(TrailDrawCallback416018, void *);
void func_L04_00416018(void)
{
    float local[4] __attribute__((aligned(16)));
    float floorZ, scale;
    Trail416018 *trail;
    float *point, *velocity;
    short *age;
    int i, j, count, last;
    char *owner;
    for (i = 0; i < 140; i++) {
        trail = &D_L04_00254E10[i];
        if (!trail->active)
            continue;
        owner = trail->owner;
        count = trail->count;
        if (*(short *)(owner + 0xaa) == 0xbbc)
            floorZ = *(float *)(D_00189E20 + 0x318) + 0.1f;
        else
            floorZ = *(float *)(owner + 0x18) - 0.25f;
        last = count - 1;
        point = trail->points[0];
        velocity = trail->velocities[0];
        age = trail->ages;
        for (j = 0; j < count; j++) {
            if ((*age)++ > 10)
                velocity[2] -= 0.0019444445f;
            scale = 1.0f - (*age - 5) * 0.01f;
            func_00282CC0(point, point, velocity);
            func_00282D30(local, trail->impulse, scale);
            func_00282CC0(point, point, local);
            if (point[2] < floorZ) {
                point[2] = floorZ;
                trail->landed[j] = 1;
            }
            point[3] = trail->ages[0] * 0.0009f + 0.01f + *age * 0.0009f;
            point += 4;
            velocity += 4;
            age++;
        }
        if (count < 8 &&
            ((*(short *)(trail->owner + 0xaa) == 0xbbc && D_L04_001B08F0) ||
             (*(short *)(trail->owner + 0xaa) == 0xb2d &&
              *(int *)(*(char **)(trail->owner + 0x68) + 0x244)))) {
            if (trail->ages[last] < 3)
                continue;
            point = trail->points[count];
            func_00283098(local, trail->origin, trail->owner + 0xc0);
            func_00282CC0(point, trail->offset, local);
            func_00282CC0(point, point, trail->impulse);
            *(Quad416018 *)trail->velocities[count] = *(Quad416018 *)local;
            point[3] = 0.005f;
            trail->ages[count] = 0;
            trail->count++;
        } else if (trail->landed[last] == 1) {
            if (func_00282948(&trail->lifetime)) {
                trail->active = 0;
            } else {
                trail->colour = func_00283D38(trail->lifetime * 0.033333335f,
                    0x00858585, 0x80858585);
            }
        }
    }
    func_L00_002E6CF0(func_L04_00415E28, D_L04_001B0914);
}
