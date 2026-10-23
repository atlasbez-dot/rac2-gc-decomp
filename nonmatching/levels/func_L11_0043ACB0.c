/* func_L11_0043ACB0 (240 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 228 bytes against the retail's 240; 56 of the 60 words differ, the
   five calls and the arithmetic are the retail's, the frame and the register
   allocation are not.
   check.py (11_joba), with the source below:
     11_joba: 228 bytes, expected 240
     func_L11_0043ACB0: 0 of 1 places match (src/levels/11_joba/L11_00432628.c)

   What is measured and right:
   - the signature is (float *obj, char *arg1, float f12, float f13, float f14):
     the retail never sets $a2, so the third parameter is a float and the two
     calls to func_00283180 and func_00283198 take only the float argument (both
     bodies read $f12 alone).
   - the three floats come from the second argument, copied into a sixteen-byte
     local with an `lq`/`sq` pair. The copy fills eight bytes only, so the third
     float of the local is the uninitialised one the retail reads back at +0x68
     and stores at obj + 8; the local is therefore a three-float struct written
     through a TI128 pointer, and reading a float out of a `mode(TI)` local is an
     internal compiler error in this cc1.
   - the first difference is func_00283248(obj[0] - v.x, obj[1] - v.y), then the
     two draws func_002A7878(-g, g) and func_002A7878(-f14, f14), the second of
     which is added to the first float argument.

   What is left:
   - the retail keeps $sp in $s1 and reads the local through it (`lq $v0,
     0x0($s1)`), this draft reads it through $sp, which is one register shorter
     and makes the frame 0x40 against the retail's 0x50.
   - the first multiply: the retail has `mul.s $f0, $f22, $f0` (the limit times
     the result) and this draft has `mul.s $f0, $f0, $f22`.
   - the last two stores: the retail writes obj + 8 before obj + 4, this draft
     writes obj + 4 first.

   Tried and not enough: the three orders of the last two stores, the local as a
   `mode(TI)` with the floats read through a float pointer (internal compiler
   error), and the local as a union of TI128 and float[4]. */

extern float func_00283248(float, float);
extern float func_00283180(float);
extern float func_00283198(float);
extern float func_002A7878(float, float);

typedef int TI128 __attribute__((mode(TI)));

void func_L11_0043ACB0(float *obj, char *arg1, float f12, float f13, float f14)
{
    struct {
        float x;
        float y;
        float z;
    } v;
    float f;
    float g;
    float h;
    float t;

    *(TI128 *)&v = *(TI128 *)arg1;
    f = func_00283248(obj[0] - v.x, obj[1] - v.y);
    g = f13 * 0.017453294f;
    h = func_002A7878(-g, g);
    f = f + h;
    h = func_002A7878(-f14, f14);
    f12 = f12 + h;
    *(TI128 *)obj = *(TI128 *)&v;
    t = func_00283180(f);
    t = f12 * t;
    obj[0] = obj[0] + t;
    func_00283198(f);
    f12 = f12 * t;
    obj[2] = v.z;
    obj[1] = obj[1] + f12;
}
