/* func_002A88A0 - 264 bytes, 28 places (boot and every level).
   Four plain-C source forms were checked. The best draft is 244 bytes and
   passes 0/28 places in USA v1.01, PAL v1.00, and USA v2.00. Its non-NOP
   instruction sequence matches after accounting for relocated calls and
   branch displacements; retail has five extra NOP words around the three
   floating-point divisions. Reopen with evidence for the compiler's source
   shape or scheduling behavior that emits those NOPs. Do not add barriers. */

typedef int s32;
typedef float f32;

extern f32 func_00282C48(f32);
extern f32 func_00282C10(f32);

s32 func_002A88A0(f32 *root0, f32 *root1, f32 a, f32 b, f32 c) {
    f32 discriminant = b * b - a * (c * 4.0f);

    if (discriminant == 0.0f) {
        *root0 = -b / (a + a);
        return 1;
    }

    {
        f32 square_root = func_00282C10(func_00282C48(discriminant));
        *root0 = (-b + square_root) / (a + a);
        *root1 = (-b - square_root) / (a + a);
        if (*root0 < *root1) {
            f32 temporary = *root1;
            *root1 = *root0;
            *root0 = temporary;
        }
    }

    return discriminant > 0.0f ? 2 : 0;
}
