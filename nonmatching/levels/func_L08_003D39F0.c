/* Retained complete C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -mno-split-addresses
 * 920/912 bytes; 0/3 placements in us and us2; pal has no catalogue entry.
 * Residual: The bounded three-record window and every 48-byte copy are preserved. Global-base/copy address lifetimes still enlarge the frame from 0x30 to 0x40.
 * Reopen: Independent record-window address/lifetime evidence removing saved bases without artificial barriers or changing real record extents.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"
typedef int TrackQuad __attribute__((mode(TI)));
typedef struct { TrackQuad position; u8 *owner; float distance; int ticks; int duration; int initialized; int tail[3]; } TrackRecord;
typedef struct { float f0,f4,f8,f12,f16,f20; u8 f24,f25; short f26; u8 f28,f29,f30,f31; u8 pad32[16]; short f48,f50; int f52,f56,f60; } PoolRecord64;
/* The three consecutive 48-byte records are independently addressed in retail.
 * This bounded aggregate models that accessed span, not a larger global. */
typedef struct { TrackRecord current, candidate, previous; } TrackWindow;
extern TrackWindow D_L08_001B3490;
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
    float offset[4] __attribute__((aligned(16)));
    u8 *vehicle;
    int limit;
    switch (object[0x20]) {
    case 0:
        func_00115484(&D_L08_001B3490.current, 0, 48);
        func_00115484(&D_L08_001B3490.candidate, 0, 48);
        func_00115484(&D_L08_001B3490.previous, 0, 48);
        D_L08_001B3490.previous.ticks = 65535;
        D_L08_001B3490.previous.distance = 100000.0f;
        D_L08_001B3490.current.distance = 100000.0f;
        D_L08_001B3490.current.ticks = 65535;
        D_L08_001B3490.candidate.distance = 100000.0f;
        D_L08_001B3490.candidate.ticks = 65535;
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
        func_00282CC0(&D_L08_001B3490.current.position, offset, vehicle + 0x10);
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
    if (D_L08_001B3490.previous.owner == D_L08_001B3490.candidate.owner)
        D_L08_001B3490.candidate.duration = D_L08_001B3490.previous.duration + 1;
    if (D_L08_001B3490.candidate.owner != D_L08_001B3490.current.owner && D_L08_001B3490.candidate.owner != 0) {
        limit = D_L08_001B3490.candidate.duration;
        if (limit < D_L08_001B02FC)
            limit = D_L08_001B02FC;
        D_L08_001B3490.current.ticks++;
        if (D_L08_001B3490.current.ticks >= limit) {
            qcopy(&D_L08_001B3490.current, &D_L08_001B3490.candidate);
            qcopy((u8 *)&D_L08_001B3490.current + 16, (u8 *)&D_L08_001B3490.candidate + 16);
            qcopy((u8 *)&D_L08_001B3490.current + 32, (u8 *)&D_L08_001B3490.candidate + 32);
            D_L08_001B3490.current.initialized = 1;
        }
    } else if (D_L08_001B3490.current.initialized == 0) {
        qcopy(&D_L08_001B3490.current, &D_L08_001B3490.candidate);
            qcopy((u8 *)&D_L08_001B3490.current + 16, (u8 *)&D_L08_001B3490.candidate + 16);
            qcopy((u8 *)&D_L08_001B3490.current + 32, (u8 *)&D_L08_001B3490.candidate + 32);
        D_L08_001B3490.current.initialized = 1;
    }
    if (D_L08_001B3490.current.owner != 0) {
        if (D_L08_001B0318 == 0) {
            D_L08_001B0318 = func_L00_002D70A0(5);
            if (D_L08_001B0318 == 0)
                return;
        }
        D_L08_001B0318->f31 = 1;
        D_L08_001B0318->f0 = 7.0f;
update_vector:
        func_00282CF0(D_L08_001B0318->pad32, &D_L08_001B3490.current.position, &D_L08_001B9B00);
    } else if (D_L08_001B0318 != 0) {
        func_L00_002D7140((u8 *)D_L08_001B0318);
        D_L08_001B0318 = 0;
    }
    qcopy(&D_L08_001B3490.previous, &D_L08_001B3490.candidate);
    qcopy((u8 *)&D_L08_001B3490.previous + 16, (u8 *)&D_L08_001B3490.candidate + 16);
    qcopy((u8 *)&D_L08_001B3490.previous + 32, (u8 *)&D_L08_001B3490.candidate + 32);
    func_00115484(&D_L08_001B3490.candidate, 0, 48);
    D_L08_001B3490.candidate.ticks = 65535;
    D_L08_001B3490.candidate.distance = 100000.0f;
    D_L08_001B3490.current.initialized = 0;
}
