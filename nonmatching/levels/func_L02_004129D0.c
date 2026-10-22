/* func_L02_004129D0 - 892 bytes at its one place (level 02). This C gives 904 bytes (built with
   -O2 -G0 -ffunction-sections -frac2-qcopy, the profile of func_L02_003CAE68 and func_L02_003D4ED0
   in this level); against retail's 892 the instruction stream is shifted from +0x18 on, 182 words
   differ.

   Known wall, measured here: retail's grouped 16-byte copy `lq $v0,0($s1)` / `sq $v0,0($v1)`
   (+0x174/+0x178, vector v into the first point of the polyline) is also a scheduling barrier,
   which `-frac2-qcopy` is not. In retail the five insns of the loop-1 set-up (`daddu $s5,$v1`,
   `daddu $s4,$s0`, `daddu $s0,$s5`, `addiu $s1,$sp,0x80`, `addiu $s2,$zero,0xB`) all stay behind
   the copy, as gcse's copies of the shared frame addresses are emitted at the end of the block;
   here sched1/sched2 float them up (the counter's `addiu $s2,$zero,0xB` ends up in the prologue,
   the copies far above the copy, and everything after them is shifted). Same C in a SCRATCH
   copy outside src/ with the copy written as a volatile asm (`lq $2,0(%1)` / `sq $2,0(%0)`, memory
   clobber, operands buf and &v): 892 bytes, and what is left is a few words (an aligned diff
   shows 1 inserted, 2 deleted and 17 replaced), none of them scheduling:
   - loop 1: retail keeps the buffer address in $s5 (a gcse temp, `daddu $s5,$v1,$zero` straight
     after the `sq`) and initialises the walking pointer from it (`daddu $s0,$s5,$zero`); here the
     pointer is copied from $v1 and the temp from the pointer (`daddu $s2,$v1` / `daddu $s5,$s2`),
     and the walking pointer / counter / out pointer land in $s2/$s0/$s1 against retail's
     $s0/$s2/$s1 (every other register of the function is retail's);
   - the zero of the vector `x` at +0x2A4: retail materialises the address (`addiu $v0,$sp,0x160;
     sq $zero,0($v0)`), this C folds it (`por $v0,$zero,$zero` ... `sq $v0,0x160($sp)`).
   So the C below is right in everything but those two and the barrier, and the barrier needs
   inline asm.

   Spellings that were needed (all measured): the seven constant blocks copied into locals as small
   structs (a 16-byte one gives retail's `ldl/ldr/sdl/sdr` pairs; a 2-byte one `lb/sb`); `const` on
   the tables; the second colour call as its own statement (nested in the argument list it hoisted
   the two `lbu` of the byte pair above the call); a block-local `Vec4 *q = &buf[j]` in loop 2 (it
   gives retail's `addiu $s0,$s5,0x10` and the 8-byte displacement) and two separate counters for
   the two loops (retail keeps them in different registers, $s2 and $s1);
   the random float as a temporary before the `func_00282D08` call. Tried without effect on the
   loop-1 registers: one pointer with `out - 1`, a derived pointer variable, a counting-down loop,
   array indexing (`&buf[i + 1]`: 912 bytes), and the order of the two pointer
   initialisations. */

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;
typedef int TI128 __attribute__((mode(TI)));
typedef struct {
    float x, y, z, w;
} Vec4;

struct F4 {
    float f[4];
};
struct F2 {
    float f[2];
};
struct W2 {
    u32 w[2];
};
struct B4 {
    u8 b[4];
};
struct B2 {
    u8 b[2];
};

extern const struct F4 D_L02_001B1C10;
extern const struct F2 D_L02_001B1C20;
extern const struct W2 D_L02_001B1C28;
extern const struct B4 D_L02_001B1C30;
extern const struct F2 D_L02_001B1C38;
extern const struct B2 D_L02_001B1C40;
extern const struct W2 D_L02_001B1C48;
extern u8 *D_L02_001B368C __attribute__((sda));
extern s32 D_L02_001A8F00 __attribute__((sda));

extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00283CE0(int);
extern void func_00282D30(void *, void *, float);
extern float func_00283198(float);
extern float func_00283B98(float, float);
extern int func_00283D38(int, int, float);
extern void func_L00_002EBE88(void *, int, int, int, int, int, float, float, float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern int func_002A7820(int, int);
extern void func_00282D08(void *, void *, void *, float);
extern void func_002C3150(void *, void *, int, int, int, int, float);

void func_L02_004129D0(u8 *a0) {
    struct F4 a = D_L02_001B1C10;
    struct F2 b = D_L02_001B1C20;
    struct W2 c = D_L02_001B1C28;
    struct B4 d = D_L02_001B1C30;
    struct F2 e = D_L02_001B1C38;
    struct B2 f = D_L02_001B1C40;
    struct W2 g = D_L02_001B1C48;
    Vec4 buf[13];
    Vec4 w;
    Vec4 v;
    Vec4 x;
    Vec4 y;
    Vec4 *in;
    Vec4 *out;
    u8 *state;
    float ph;
    float step;
    float amp;
    float t;
    int i;
    int j;
    int col0;
    int col1;
    int k;
    int n;

    amp = 1.0f;
    *(TI128 *)&v = 0;
    v.z = 1.5f;
    state = *(u8 **)(a0 + 0x68);
    func_00283098(&v, &v, a0 + 0xC0);
    func_00282CC0(&v, &v, a0 + 0x10);
    func_00282CF0(&w, D_L02_001B368C + (*(s32 *)state << 7) + 0x30, &v);
    func_00282D30(&w, &w, amp / func_00283CE0(12));
    *(TI128 *)&buf[0] = *(TI128 *)&v;
    in = buf;
    out = buf + 1;
    for (i = 0; i < 12; i++) {
        func_00282CC0(out, in, &w);
        out->w = e.f[0];
        in++;
        out++;
    }
    ph = *(float *)(state + 0x14);
    step = 1.0f / func_00283CE0(13) * 3.1415927f;
    for (j = 1; j < 13; j++) {
        Vec4 *q = &buf[j];

        t = func_00283198(ph);
        q->z += amp * t * func_00283198((float)j * step);
        ph = func_00283B98(ph, step + step);
    }
    col0 = func_00283D38(g.w[0] & 0xFFFFFF, g.w[0], *(float *)(state + 0xC));
    col1 = func_00283D38(g.w[1] & 0xFFFFFF, g.w[1], *(float *)(state + 0xC));
    func_L00_002EBE88(buf, f.b[0], f.b[1], 13, col0, col1, e.f[0], e.f[1],
                      *(float *)(state + 0x10));
    if (D_L02_001A8F00 == 0) {
        *(TI128 *)&x = 0;
        k = func_002A77E0(12);
        t = func_002A7878(0.0f, 1.0f);
        func_00282D08(&y, &buf[k], &buf[k + 1], t);
        x.z = -(func_002A7878(a.f[2], a.f[3]) * 0.016666668f);
        n = (u8)func_002A7820(d.b[2], d.b[3]);
        func_002C3150(&y, &x, c.w[1], n, (u8)func_002A77E0(255), 0, b.f[1]);
    }
}
