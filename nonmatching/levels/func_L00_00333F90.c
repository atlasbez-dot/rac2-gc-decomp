/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 280/276 bytes; us: 0/27 placements; us2: 0/27 placements; pal: 0/27 placements.
 * The old alpha computation from the packed color is corrected: retail calls the integer conversion
 * helper on 2.0f and adds 0x20. The known 64-byte header/vector prefix and complete
 * position/difference/endpoint vectors remain. Multiplication destination, saved source-pointer
 * reuse and store scheduling differ.
 * Reopen with actual packed-value and vector-pointer live ranges. Keep the separate alpha
 * conversion; never infer alpha from the color word.
 * Original complete variants and allocator diagnostics are preserved privately.
 * No candidate or linked-build credit is claimed.
 */
#include "common.h"

#ifndef RAC2_T_TI128_33F90
#define RAC2_T_TI128_33F90
typedef int TI128_33F90 __attribute__((mode(TI)));
#endif

extern void *func_002B9030(int);

extern int func_002A77E0(int);
extern int func_00283CF0(float);

extern void func_00282CF0(char *dst, char *first, char *second);

extern unsigned char *D_L00_001FE98C;

/* Allocates the 0x13 object, fills its flags and its two 16-byte copies, and runs the
   two bound helpers over the record at +0x20. */
typedef union { TI128_33F90 q; float f[4]; } EffectVector;
/* The observed header and three complete vectors form a known 64-byte prefix. */
typedef struct {
    u8 b0,b1,b2,b3;
    int word4;
    u8 b8,b9;
    u16 fieldA;
    int wordC;
    EffectVector position, difference, endpoint;
} EffectPrefix;

void *func_L00_00333F90(void *a0, void *a1)
{
    EffectPrefix *record = func_002B9030(0x13);
    EffectVector *position = a0;
    EffectVector *endpoint;
    EffectVector *difference;
    int packed;
    if (!record)
        return record;
    packed = (func_002A77E0(6) * 6 + 0x40) | 0x78404000;
    record->wordC = packed;
    record->word4 = packed;
    record->b9 = func_00283CF0(2.0f) + 0x20;
    record->b3 = 0x48;
    record->b1 = 3;
    record->b2 = *D_L00_001FE98C;
    qcopy(&record->position, position);
    endpoint = &record->endpoint;
    qcopy(endpoint, a1);
    difference = &record->difference;
    func_00282CF0((char *)difference, (char *)position, (char *)endpoint);
    func_00282CF0((char *)difference, (char *)difference, (char *)endpoint);
    endpoint->f[3] = 6.0f;
    record->position.f[3] = 0.09f;
    difference->f[3] = 0.5f;
    return record;
}
