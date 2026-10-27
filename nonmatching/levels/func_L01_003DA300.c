/* Bounded manual reconstruction, 2026-10-25; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 236/236 bytes; us: 0/1 placements; us2: 0/1 placements; pal: 0/1 placements.
 * Legacy factory/RNG names now use their canonical pointer-return and f0 contracts. The stored
 * handle is a pointer and the state prefix retains its complete 16-byte point. Both genuine
 * position copies remain. Size and operation shape agree; the two saved source registers are
 * mirrored from +0x4. The mode-helper integer inputs are observed, but its discarded original
 * result is unqualified.
 * Reopen with independently observed source/state live ranges. The measured typed-state view gave
 * the same body; do not permute prototypes or add fake references.
 * Original variants, retail context and allocator diagnostics remain private.
 * No exact-C, linked-build or runtime credit is claimed.
 */
#include "common.h"



extern u8 *func_0029EFD0(s32);
extern f32 func_002A7940(void);
extern void func_002A7470(u8 *, s32, s32, s32);
extern f32 D_L01_001B0828 __attribute__((sda));

typedef int SpawnQuad __attribute__((mode(TI)));
/* Measured state prefix; total allocation extent is unspecified. */
struct SpawnState {
    SpawnQuad position;
    u8 *handle;
    u8 unknown14[4];
    f32 weight;
};

/* Creates the 0xB24 object, seeds its state block and copies the two vectors in. */
u8 *func_L01_003DA300(u8 *a0, u8 *a1, u8 *a2, f32 f12)
{
    u8 *s2 = a2;
    u8 *s3 = a0;
    u8 *s4 = a1;
    f32 f20 = f12;
    u8 *s1;
    struct SpawnState *state;

    s1 = func_0029EFD0(0xB24);
    if (s1 != 0) {
        *(u8 *)(s1 + 0x30) = 0xFF;
        *(u16 *)(s1 + 0x32) = 0xFF;
        *(u8 *)(s1 + 0x31) = 1;
        *(u8 *)(s1 + 0x20) = 0;
        state = *(struct SpawnState **)(s1 + 0x68);
        *(f32 *)(s1 + 0xF8) = func_002A7940();
        *(f32 *)(s1 + 0xF4) = func_002A7940();
        *(f32 *)(s1 + 0xF0) = func_002A7940();
        *(f32 *)(s1 + 0x2C) = *(f32 *)(*(u8 **)(s1 + 0x24) + 0x24) * D_L01_001B0828;
        state->handle = s2;
        state->weight = f20;
        qcopy(s1 + 0x10, s3);
        qcopy(&state->position, s4);
        if (*(u8 *)(s1 + 0x43) != 0)
            func_002A7470(s1, 0, 0, 0xA);
    }
    return s1;
}
