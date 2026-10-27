/* Retained C reconstruction, not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 336/328 bytes; 0/2 placements in each of us, us2 and pal.
 * Corrected the scratch-vector destinations: retail clears local w, writes its Z
 * product, then copies all four components to local v; it never clears or
 * overwrites the controller lanes. Load the controller before the setup call,
 * as in its retail delay slot. The absolute factor is an honest scalar view
 * with NOT_SDA, rather than an invented three-element array.
 * Remaining: The absolute factor address is hoisted into an extra saved s3 (0x70 versus
 * 0x60 frame); initial scheduling and loop delay-slot selection still differ.
 * Disabling strength reduction did not improve it.
 * Reopen with: Independent storage/lifetime evidence for the absolute factor or loop
 * locals; do not restore the false array extent or controller writes.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

/* the level's two blend words and the scale the placement call takes, all through $gp,
 * and the absolute factor the blend call takes. */
extern f32 D_L22_001AFF58 __attribute__((sda));

extern s32 D_L22_001AFF60 __attribute__((sda));

extern f32 D_L22_001AFF64 __attribute__((sda));

extern f32 D_L22_001AFF5C NOT_SDA;

extern void func_002820A0(void);

extern s32 func_002820D0(f32 *, s32, s32, f32, f32, f32);

extern void func_00283098(f32 *, f32 *, u8 *);

extern void func_00282CC0(u8 *, u8 *, u8 *);

extern f32 func_002AA140(f32, f32, f32);

extern s32 func_00283CF0(f32);

/* Walk the four controller entries, transform a cleared local vector with its Z
 * component scaled by the two controller lanes, then submit a weighted placement. */
void func_L22_003C9D48(u8 *a0) {
    u8 *obj = a0;
    s32 i = 3;
    u8 *p;
    u8 *ctl;
    f32 v[4];
    f32 w[4];
    f32 f;
    f32 t;
    s32 n;

    ctl = *(u8 **)(obj + 0x68);
    func_002820A0();
    p = ctl + 0x20;
    for (; i >= 0; i--) {
        *(TI128 *)w = 0;
        w[2] = *(f32 *)(p) * *(f32 *)(p - 0x10);
        *(TI128 *)v = *(TI128 *)w;
        func_00283098(v, v, obj + 0xC0);
        func_00282CC0(v, v, obj + 0x10);
        f = func_002AA140(D_L22_001AFF58, D_L22_001AFF5C, *(f32 *)(p));
        t = *(f32 *)(p);
        if (t < 0.1f)
            n = func_00283CF0((f32)D_L22_001AFF60 * t * 10.0f);
        else
            n = func_00283CF0((f32)D_L22_001AFF60 * (1.0f - t));
        func_002820D0(v, n, 0, f, D_L22_001AFF64, 0.08f);
        p += 4;
    }
}
