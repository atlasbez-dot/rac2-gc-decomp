/* func_L11_00442B60 (284 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 280 bytes, 59 of 71 words differ from retail; the call sequence, the float
   constants and the lq/sq copy are right, the schedule is not.

   check.py (11_joba), with the source below, compiled in src/levels/11_joba/L11_0043E1A0.c
   (-O2 -G0 -ffunction-sections):
     00442B84  lq    $v0, 0x0($v1)      |  lq    $v1, 0x0($v0)
     00442B88  sq    $v0, 0x0($sp)      |  sq    $v1, 0x0($sp)
   What is measured and right:
   - the 16-byte copy of the level's D_L11_001BAAF0 needs a mode(TI) local: a plain
     struct assignment comes out ldl/ldr/sdl/sdr, a union with a float member comes
     out ld/sd, and only the TI typedef reaches retail's lq/sq pair;
   - the three buffers sit at the stack's 0, 0x10 and 0x20, each with the word at +8
     cleared before its own func_00282F20 call;
   - the calls are the boot's func_00282F20 (scale), func_00282CF0 (matrix), func_00282DB0
     (length) and func_00282E80 (distance), and the level's D_00189EA0 is the matrix;
   - the thresholds are 0.81915f (0x3F51B3D0) and 30.0f (0x41F00000), the natural
     spellings, not the bit patterns;
   - the result is 1 when the second measurement passes the second threshold.
   Tried and not enough:
   - a plain struct (16 bytes) for the three buffers: ldl/ldr instead of lq/sq, and the
     word at +8 cannot be named;
   - the union with a float member: ld/sd instead of lq/sq;
   - the zeroed word through a cast of the TI local: it lands, but the copy is scheduled
     after the call setup instead of right after the prologue, and the zero store takes
     the call's delay slot where retail keeps it before the call.
   Next idea: a source shape that keeps the copy in the prologue and the zero store
   before the call, i.e. the order retail emits, without the delay-slot fill. */

typedef float f32;
typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

typedef int TI128 __attribute__((mode(TI)));

extern TI128 D_L11_001BAAF0;

extern f32 D_00189EA0[];

extern void func_00282CF0(void *out, const void *in, const void *matrix);

extern f32 func_00282DB0(const void *v);

extern f32 func_00282E80(void *obj, const void *matrix);

extern void func_00282F20(void *out, const void *in, f32 scale);

/* Measures the actor's distance to the level's helper and reports whether it is
   past the level's threshold. */
s32 func_L11_00442B60(u8 *arg) {
    TI128 a = D_L11_001BAAF0;
    TI128 b;
    TI128 c;
    s32 result = 0;

    *(int *)((u8 *)&a + 8) = 0;
    func_00282F20(&a, &a, 1.0f);
    func_00282CF0(&b, arg + 0x10, D_00189EA0);
    *(int *)((u8 *)&b + 8) = 0;
    func_00282F20(&b, &b, 1.0f);
    func_00282CF0(&c, arg + 0x10, D_00189EA0);
    *(int *)((u8 *)&c + 8) = 0;
    func_00282F20(&c, &c, 1.0f);
    if (func_00282DB0(&a) > 0.81915f) {
        if (func_00282E80(arg + 0x10, D_00189EA0) > 30.0f) {
            result = 1;
        }
    }
    return result;
}
