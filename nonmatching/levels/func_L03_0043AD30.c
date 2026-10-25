/* 0 of 12 places match - last line: 03_endako: 500 bytes, expected 512
   The guard chain, the two vector measures and the slot update are retail's shape, but
   retail carries two hazard `nop`s before each `div.s` and this body does not, and the
   first three callee-saved saves are emitted in another order. Retained: the whole -G8
   sibling source with the calibrated constants (pi/2 = 0x3FC90FDB, 0.6283186f). */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef float f32;

/* The angle limits, the reference axis and the slot field the elevation accumulates into. */
extern f32 D_00138284;

extern u8 D_L03_00189EA0[];

extern u8 D_L03_001B9840[];

extern f32 D_L03_001B21B8 __attribute__((sda));

extern f32 func_00282C48(f32);

extern f32 func_00282DB0(float *, float *);

extern f32 func_00282DF0(float *);

extern f32 func_002831B0(f32);

typedef struct {
    u32 occupant;
    u32 owner;
    f32 size;
    f32 level;
} AimSlot;

/* Keeps the camera target on the object the slot holds: measures the object against the
   reference axis, refuses anything outside the size window, turns the angle to the slot's
   facing into a normalised elevation and folds it into the slot's level. */
void func_L03_0043AD30(u8 *a0) {
    u8 *base = D_L03_001B9840;
    u8 *cur = *(u8 **)(base + 0x190);
    AimSlot *slot = (AimSlot *)(base + 0x3A0);
    f32 v[4];
    f32 size;
    f32 angle;

    if (*(short *)(cur + 0x86) != 0)
        return;
    if (func_00282C48(D_00138284) > 0.05f)
        return;
    func_00282CF0(v, (float *)(a0 + 0x10), (float *)D_L03_00189EA0);
    size = func_00282DF0(v);
    if (size >= 22.0f)
        return;
    if (size <= 0.0f)
        return;
    if (size >= slot->size)
        return;
    if (!(0.0f < v[2]))
        return;
    angle = 1.5707964f - func_002831B0(func_00282DB0((float *)cur, v) / size);
    if (angle < 1.1170108f) {
        func_00282CF0(v, (float *)(a0 + 0x10), (float *)(cur + 0x30));
        size = func_00282DF0(v);
        if (size == 0.0f)
            size = 0.0001f;
        angle = 1.5707964f - func_002831B0(func_00282DB0((float *)cur, v) / size);
        if (angle < 0.6283186f) {
            slot->occupant = (u32)cur;
            slot->size = size;
            slot->owner = (u32)a0;
            slot->level += D_L03_001B21B8;
            if (slot->level > 1.0f)
                slot->level = 1.0f;
        }
    }
}
