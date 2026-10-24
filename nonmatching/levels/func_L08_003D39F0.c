/* Retained manual C reconstruction; not linked or counted.
 * Retail: 912 bytes. Checked trial: src/levels/shared/L08_003D39F0-g8.c
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * us: 0/3 placements (exit 1), 968 compiled bytes
 * us2: 0/3 placements (exit 1), 968 compiled bytes
 * pal: explicit catalogue absence (exit 1); no credit
 * Residual: The 48-byte records and 64-byte pool record are preserved, including the two early allocation failures. The compiler retains extra global bases and emits a 0x40-byte frame instead of retail 0x30.
 * Reopen: Reopen with a measured record-address lifetime shape that removes the extra saved globals without barriers or false extents.
 * The ASM marker and trial-only file profile were restored after checks.
 */

#include "common.h"
typedef int TrackQuad __attribute__((mode(TI)));
typedef struct { TrackQuad position; u8 *owner; float distance; int ticks; int duration; int initialized; int tail[3]; } TrackRecord;
typedef struct { float f0,f4,f8,f12,f16,f20; u8 f24,f25; short f26; u8 f28,f29,f30,f31; u8 pad32[16]; short f48,f50; int f52,f56,f60; } PoolRecord64;
extern TrackRecord D_L08_001B3490, D_L08_001B34C0, D_L08_001B34F0;
extern PoolRecord64 *D_L08_001B0318;
extern int D_L08_001B02FC __attribute__((sda));
extern float D_L08_001B0300 __attribute__((sda));
extern float D_L08_001B0304 __attribute__((sda));
extern float D_L08_001B0308 __attribute__((sda));
extern float D_L08_001B0310 __attribute__((sda));
extern float D_L08_001B0314 __attribute__((sda));
extern u8 D_00189E20[];
extern TrackQuad D_L08_001B9B00;
extern int D_L08_001B258C __attribute__((sda));
extern void *func_00115484(void *dst, int value, unsigned int size);
extern int func_002ACBC8(void *point, int index);
extern void func_002AF000(float *p, float a, float b, float c);
extern void func_00282CC0(void *out, void *a, void *b);
extern void func_00282CF0(void *out, void *a, void *b);
extern PoolRecord64 *func_L00_002D70A0(int kind);
extern void func_L00_002D7140(u8 *object);

void func_L08_003D39F0(u8 *object)
{
    float offset[4];
    u8 *vehicle;
    int limit;
    switch (object[0x20]) {
    case 0:
        func_00115484(&D_L08_001B3490, 0, 48);
        func_00115484(&D_L08_001B34C0, 0, 48);
        func_00115484(&D_L08_001B34F0, 0, 48);
        D_L08_001B34F0.ticks = 65535;
        D_L08_001B34F0.distance = 100000.0f;
        D_L08_001B3490.distance = 100000.0f;
        D_L08_001B3490.ticks = 65535;
        D_L08_001B34C0.distance = 100000.0f;
        D_L08_001B34C0.ticks = 65535;
        D_L08_001B0318 = 0;
        object[0x20] = 1;
        return;
    case 1: break;
    default: return;
    }
    if (**(int **)(object + 0x68) != -1 && func_002ACBC8(&D_L08_001B9B00, **(int **)(object + 0x68)))
        D_L08_001B258C = 2;
    vehicle = *(u8 **)(D_00189E20 + 0x1830);
    if (*(int *)(D_00189E20 + 0x2294) == 0x31 && vehicle != 0) {
        func_002AF000(offset, D_L08_001B0300, *(float *)(vehicle + 0xf8), -*(float *)(vehicle + 0xf4) * 0.5f);
        func_00282CC0(&D_L08_001B3490.position, offset, vehicle + 0x10);
        if (D_L08_001B0318 == 0) {
            D_L08_001B0318 = func_L00_002D70A0(5);
            if (D_L08_001B0318 == 0)
                return;
        }
        vehicle = *(u8 **)(D_00189E20 + 0x1830);
        if (*(short *)(vehicle + 0xaa) == 0x905) {
            D_L08_001B0318->f0 = D_L08_001B0304;
            D_L08_001B0318->f8 = -1.0f;
            D_L08_001B0318->f12 = -1.0f;
        } else {
            D_L08_001B0318->f0 = D_L08_001B0308;
            D_L08_001B0318->f8 = D_L08_001B0314;
            D_L08_001B0318->f12 = D_L08_001B0310;
        }
        D_L08_001B0318->f31 = 1;
        goto update_vector;
    }
    if (D_L08_001B34F0.owner == D_L08_001B34C0.owner)
        D_L08_001B34C0.duration = D_L08_001B34F0.duration + 1;
    if (D_L08_001B34C0.owner != D_L08_001B3490.owner && D_L08_001B34C0.owner != 0) {
        limit = D_L08_001B34C0.duration;
        if (limit < D_L08_001B02FC)
            limit = D_L08_001B02FC;
        D_L08_001B3490.ticks++;
        if (D_L08_001B3490.ticks >= limit) {
            D_L08_001B3490 = D_L08_001B34C0;
            D_L08_001B3490.initialized = 1;
        }
    } else if (D_L08_001B3490.initialized == 0) {
        D_L08_001B3490 = D_L08_001B34C0;
        D_L08_001B3490.initialized = 1;
    }
    if (D_L08_001B3490.owner != 0) {
        if (D_L08_001B0318 == 0) {
            D_L08_001B0318 = func_L00_002D70A0(5);
            if (D_L08_001B0318 == 0)
                return;
        }
        D_L08_001B0318->f31 = 1;
        D_L08_001B0318->f0 = 7.0f;
update_vector:
        func_00282CF0(D_L08_001B0318->pad32, &D_L08_001B3490.position, &D_L08_001B9B00);
    } else if (D_L08_001B0318 != 0) {
        func_L00_002D7140((u8 *)D_L08_001B0318);
        D_L08_001B0318 = 0;
    }
    D_L08_001B34F0 = D_L08_001B34C0;
    func_00115484(&D_L08_001B34C0, 0, 48);
    D_L08_001B34C0.ticks = 65535;
    D_L08_001B34C0.distance = 100000.0f;
    D_L08_001B3490.initialized = 0;
}
