/* 0 of 5 places match - last line: 04_barlow: 60 bytes, expected 68
   The loop, the walking pointer, the `sltiu` bound and the `div.s`/`mul.s`/`swc1`
   body all match; the eight bytes missing are the two `nop`s retail leaves between
   the `lwc1 $f0,0x40($v0)` that loads the divisor and the `div.s $f12,$f12,$f0`
   (retail +0x14 and +0x18). This cc1 emits the division one instruction after the
   load instead. Three spellings (index loop, walking pointer, explicit divisor
   variable) give the same 60 bytes, so it is the unit's FPR hazard model, not the
   source shape. */

typedef float f32;
typedef unsigned int u32;

extern f32 D_002A7A40[];

/* divides FACTOR by the table's sixteenth entry and scales the whole table by it */
void func_L04_0039FEA8(f32 factor) {
    f32 scale = factor / D_002A7A40[0x10];
    u32 i;

    for (i = 0; i < 0x5C; i++)
        D_002A7A40[i] = D_002A7A40[i] * scale;
}
