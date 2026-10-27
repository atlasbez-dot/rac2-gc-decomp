/* func_0030DE88 (420 bytes, 28 places), closer M2: best under
 *     -O2 -G8 -ffunction-sections -frac2-zero-ti-por
 * (-G8 gives retail's $gp reads of D_001AF044, -frac2-zero-ti-por its por zero vector;
 * func_002C2210 takes (void *, float, float, s32, s32, float, s32, s32, void *, s32), the
 * order found by search on func_00302848). Left: loop.c hoists the 0.15f constant of the
 * second spawn into $f23 (one more saved FPR) where retail rematerialises it in the loop;
 * the 0.3f is hoisted in both. A goto loop hoists nothing (worse).
 * M16 (-dL): loop2 sees 55 real insns, threshold 61 (call in loop), life-1 movables in
 * order 0.3f, 0x7F000000, 0.15f, 0.5f: 61, 58, 55 >= 55 move, 52 does not. Retail's set
 * needs 56-58 loop2 insns with the same movables. The for/while forms instead leave
 * high(D_0018A550) to loop2 (life 4, moved first) at 56-57 insns, so 0x7F000000 stays in
 * the loop; they would need 53-55. 48 loop-form x call-spelling x decrement-position
 * variants and ten local/copy spellings hit neither window. */
#include "common.h"

typedef int Quadword_0030DE88 __attribute__((mode(TI)));
typedef union {
    Quadword_0030DE88 bits;
    float f[4];
} Vec4_0030DE88;

extern float D_001AF044 __attribute__((sda));
extern char D_0018A550[];

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002A7A00(void *, float, float);
extern float func_00282C48(float);
extern int func_002A7820(int, int);
extern float func_002A7878(float, float);
extern int func_0030CAA0(void);
extern void func_002C2210(void *, float, float, s32, s32, float, s32, s32, void *, s32);

void func_0030DE88(u8 *obj, int count)
{
    Vec4_0030DE88 v;
    Vec4_0030DE88 w;
    int n;

    v.bits = 0;
    v.f[1] = -0.9f;
    func_00283098(&v, &v, obj + 0xC0);
    func_00282CC0(&v, &v, obj + 0x10);
    if (count > 0) {
        n = count;
        do {
            int r;
            float s;
            float t;
            func_002A7A00(&w, 0.0f, D_001AF044);
            n = n - 1;
            w.f[0] = func_00282C48(w.f[0]);
            func_00283098(&w, &w, D_0018A550);
            r = func_002A7820(-8, 8);
            s = func_002A7878(0.2f, 0.6f);
            t = s * 0.3f;
            func_002C2210(&v, t, s, 0xF, func_0030CAA0() | 0x7F000000, 0.0f, 0, r, &w, 0);
            func_002C2210(&v, s * 0.15f, s * 0.5f, 0xF, 0x307F7F7F, 0.0f, 0, -r, &w, 0);
        } while (n != 0);
    }
}
