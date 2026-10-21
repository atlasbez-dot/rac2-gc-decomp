typedef unsigned int ti_word __attribute__((mode(TI)));
extern int ref_L08_003D8290_00(void *, void *, int, int, int);
extern float D_L08_001BFF68;

float func_L08_003D8290(void *raw, float first, float second) {
    char scratch[0x20];
    ti_word *input = (ti_word *)raw;
    *(ti_word *)scratch = *input;
    *(ti_word *)(scratch + 0x10) = *input;
    *(float *)(scratch + 8) = second;
    *(float *)(scratch + 0x18) = first;
    if (ref_L08_003D8290_00(scratch + 0x10, scratch, 2, 0, 0)) return D_L08_001BFF68;
    return 0.0f;
}

/* Wave 24 (worker 05): the same wall, measured again from the retail body.
   The retail keeps the address of the second transfer in a register and uses
   a zero displacement:

     addiu $a0, $sp, 0x10
     lq    $v0, 0x0($v1)        <- the source is the plain argument
     sq    $v0, 0x0($a0)        <- the destination is sp + 0x10

   while this cc1 folds the destination's offset into the instruction
   (`sq $v0,0x10($sp)`) and reuses the value loaded for the first copy, so
   the second `lq` disappears: check.py (08_tabora) reports
   "88 bytes, expected 96".

   What is measured and right: the 32-byte local is a mode(TI) object with a
   float written at its offset 8 (`swc1 $f13,0x8($sp)`) and at its offset
   0x18 (`swc1 $f12,0x18($sp)`); the call passes the second half of that
   object and the first half (a0 = sp+0x10, a1 = sp+0, a2 = 2, a3 = 0,
   t0 = 0); the result is the float at 0x1BFF68 when the call returns
   non-zero and 0.0f otherwise.  */
typedef union {
    ti_word v;
    float f[4];
} Quad;

extern int ref_L08_003D8290_00(void *, void *, int, int, int);
extern float D_L08_001BFF68;

float func_L08_003D8290_w24(void *a0, float f12, float f13) {
    Quad buf[2];

    buf[0].v = *(ti_word *)a0;
    buf[0].f[2] = f13;
    buf[1].v = *(ti_word *)a0;
    buf[1].f[2] = f12;
    if (ref_L08_003D8290_00(&buf[1], &buf[0], 2, 0, 0) != 0) {
        return D_L08_001BFF68;
    }
    return 0.0f;
}
