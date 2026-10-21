/* func_00283BE0 -- the difference of two angles, wrapped to [-pi, pi],
   72 bytes in retail.  It is func_00283B98 with a subtraction.

   Measured with tools/check.py in src/game/0027F128.c (the -O2 -G0 profile):
   "func_00283BE0: 0 of 28 places match", 92 bytes against retail's 72.

   What differs: the same as func_00283B98 (the compare and the branch shape
   now match, the float register allocation does not: retail keeps the
   difference in `$f0` and pi in `$f14`, this cc1 keeps it in `$f12` and the
   constants in `$f1`/`$f0`).
*/
typedef float f32;

f32 func_00283BE0(f32 a0, f32 a1) {
    f32 r = a0 - a1;
    f32 p = 3.1415927f;
    f32 n = -3.1415927f;

    if (r < p) {
        if (r < n) {
            r = r + p;
            r = r + p;
        }
        return r;
    }
    r = r - p;
    r = r - p;
    return r;
}
