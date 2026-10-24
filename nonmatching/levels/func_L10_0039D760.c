/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 10_hrugis_cloud: instruction at +0x4 differs; func_L10_0039D760: 0 of 2 places match (src/levels/shared/L10_0039D760-copy.c).
   us2: 10_hrugis_cloud: instruction at +0x4 differs; func_L10_0039D760: 0 of 2 places match (src/levels/shared/L10_0039D760-copy.c).
   pal: 10_hrugis_cloud: instruction at +0x4 differs; func_L10_0039D760: 0 of 2 places match (src/levels/shared/L10_0039D760-copy.c).
   Same 604-byte extent; saved-register allocation differs from +0x4. The function consumes the incoming object pointer, unlike the old no-argument declaration in its wrapper. Its four timer slots, four strips of eight vectors and six interior jitters are reconstructed. Reopen with a loop/local lifetime model.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_0039D760 - 604 bytes, 2 place(s), level 10_hrugis_cloud, retail
   at 0x0039d760. Screened with tools/w10_screen.py: 11 call(s)
   [func_00282978@0039D7C4, func_002A7878@0039D7F4, func_002A7878@0039D824,
   func_002A7878@0039D83C, func_00282CF0@0039D858, func_00282F20@0039D86C,
   func_00282CC0@0039D87C, func_L00_0031AA28@0039D8D4,
   func_002A78D8@0039D91C, func_002A78D8@0039D934, func_002A78D8@0039D94C];
   data addresses materialised [0x1b0000, 0x3dcc0000, 0x230000]; float
   constants [0x1b0000, 0x3f000000, 0x3f800000, 0x230000]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 7AA20000@0x0088, LQ/SQ 7FA20000@0x008c, COP1
   46800020@0x0148, LQ/SQ 7A420000@0x017c, LQ/SQ 7E020000@0x0180, LQ/SQ
   7A020000@0x01b0, LQ/SQ 7E220000@0x01b4, LQ/SQ 7A220000@0x0200, LQ/SQ
   7E020000@0x0204]. Head: addiu $sp, $sp, -0xA0 ; sd $s2, 0x50($sp) ; sd
   $s4, 0x60($sp) ; daddu $s2, $zero, $zero ; sd $fp, 0x80($sp) ; addiu $s4,
   $sp, 0x10. Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

typedef float f32;
typedef int Quad __attribute__((mode(TI)));
extern short D_L10_001B2DB8[4];
extern short D_L10_001B2DC0[4];
extern f32 D_L10_00234600[4][8][4];
extern int func_00282978(short *);
extern f32 func_002A7878(f32, f32);
extern f32 func_002A78D8(f32, f32);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, f32);
extern void func_00282CC0(void *, void *, void *);
extern void func_L00_0031AA28(void *, void *, void *, void *, void *, f32);

/* Rebuilds each expired lightning strip and jitters its interior control points. */
void func_L10_0039D760(void *object) {
    f32 point[4];
    f32 direction[4];
    f32 result[4];
    char *self = object;
    char *state = *(char **)(self + 0x68);
    f32 t;
    int strip, i;
    for (strip = 0; strip < 4; strip++) {
        if (func_00282978(&D_L10_001B2DB8[strip])) {
            D_L10_001B2DB8[strip] = 2;
            D_L10_001B2DC0[strip] = 0;
            *(Quad *)point = *(Quad *)state;
            point[0] += func_002A7878(0.0f, 0.0f);
            point[1] += func_002A7878(0.0f, 0.0f);
            point[2] += func_002A7878(0.0f, 0.0f);
            func_00282CF0(direction, point, self + 0x10);
            func_00282F20(direction, direction, 0.5f);
            func_00282CC0(direction, point, direction);
            for (i = 0; i < 8; i++) {
                t = (f32)i * 0.1f;
                if (i == 7) t = 1.0f;
                func_L00_0031AA28(result, self + 0x10, point, direction, direction, t);
                *(Quad *)D_L10_00234600[strip][i] = *(Quad *)result;
            }
            for (i = 1; i < 7; i++) {
                *(Quad *)result = *(Quad *)D_L10_00234600[0][i];
                result[0] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                result[1] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                result[2] += func_002A78D8(0.0f, *(f32 *)(state + 0x34));
                *(Quad *)D_L10_00234600[0][i] = *(Quad *)result;
            }
        }
    }
}
