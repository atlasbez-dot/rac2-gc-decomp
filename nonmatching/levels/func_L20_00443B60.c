/* func_L20_00443B60 (396 bytes, level 20): near miss, 392 bytes against the retail's 396.
 *
 * The candidate below is the retail's body: the same eleven calls in the same order with
 * the same arguments, the same 16-bit copies, the same float constants and the same
 * seven callee-saved registers in the same registers ($s0 = the state, $s2 = arg0,
 * $s4 = arg1, $s5 = arg3, $s6 = arg2, $s1 = &v6).  TWO things are still wrong.
 *
 * 1. THE FRAME IS 0xB0 AGAINST THE RETAIL'S 0xD0.  The retail has 0x20 bytes of OUTGOING
 *    ARGS between the locals (0x00-0x5F) and the saved registers (0x80-0xB8); this
 *    candidate has none.  A call in the retail's source must need 0x20 bytes of stack
 *    arguments (a 16-byte struct passed BY VALUE would be aligned to 16 and give
 *    exactly that), but none of the retail's eleven calls shows a stack argument, so
 *    the source shape that produced it is still unknown.  Every stack offset in the
 *    candidate is 0x20 below the retail's because of this.
 *
 * 2. THE THIRD 16-BYTE ZERO STORE.  The retail materialises the zero a second time
 *    after the first call and stores it through the register:
 *        por $v0,$zero,$zero ; sq $v0,0x40($sp)
 *    this candidate stores the zero register directly:
 *        sq $zero,0x30($sp)
 *    This is the `rac2_fold_zero_ti_store` wall the wave-4 note reported for
 *    func_L20_004424A0: the pass folds a `por`+`sq` into `sq $zero` whenever the
 *    register is dead after the store, and the retail only ever uses the zero register
 *    as the source of a 128-bit store when the DISPLACEMENT IS ZERO.  Here the
 *    displacement is 0x40, so the retail keeps the `por`.
 *
 * THE LOCALS (the frame is 0xD0 in the retail, and the order of the declarations is
 * what puts them at these offsets):
 *
 *     sp+0x00  16 bytes  a zeroed vector whose word 0 is then 5.0f and whose word 2
 *                       is then 5.5f
 *     sp+0x10  16 bytes  a vector
 *     sp+0x20  16 bytes  a zeroed vector whose word 1 is then the result of the first
 *                       call
 *     sp+0x30  16 bytes  the destination of func_002833F0
 *     sp+0x40  16 bytes  a zeroed vector whose word 2 is then state->0x298 * 0.5f
 *     sp+0x50  16 bytes  the destination of func_002833F0 and of the two
 *                       func_00283098 calls
 *
 * The three locals that carry floats are a UNION of a 16-byte value and four floats:
 * the float words are at +0 (5.0f), +4 (the first call's result) and +8 (5.5f and
 * state->0x298 * 0.5f), and the 16-byte zero store covers the whole local.  Writing a
 * float into a plain TI128 local does not work: the compiler emits a read-modify-write
 * (measured).  The union gives the retail's `sq` + `swc1` sequence, and it also keeps
 * the float store alive: a float that is stored into a local and never read is a DEAD
 * STORE and the compiler deletes it (that is what happened in the first attempt, whose
 * frame was 0xA0).
 *
 * THE CALLS (the retail's order):
 *
 *     func_002A7878(-1.0f, 1.0f)      the result goes to sp+0x24
 *     func_002833F0(&v6, &v4)         the 16 bytes of v5 go to v4 BEFORE the call
 *     func_00283738(&v6, &v6, arg0+0xC0)
 *     func_00282CC0(&v1, &v1, &v2)
 *     func_00283098(&v1, &v1, &v6)
 *     func_00282CC0(arg1, &v1, arg0+0x10)
 *     func_002A7878(5.0f, 10.0f)      the result goes to sp+0x10
 *     func_002A7878(4.0f, 6.0f)       the result goes to sp+0x18
 *     func_00283098(&v3, &v2, &v6)
 *     func_00282D30(arg2, &v3, 0.016666668f)
 *     *arg3 = *arg3 * v2.f.y;         the float at sp+0x14, i.e. the copy of the
 *                                      first call's result
 *
 * The candidate:
 */

typedef int TI128 __attribute__((mode(TI)));
typedef float f32;

typedef union {
    TI128 v;
    struct { f32 x, y, z, w; } f;
} L20_V4;

extern float func_002A7878(float, float);
extern void func_002833F0(TI128 *, TI128 *);
extern void func_00283738(TI128 *, TI128 *, char *);
extern void func_00282CC0(char *, char *, char *);
extern void func_00283098(char *, char *, char *);
extern void func_00282D30(char *, char *, float);

void func_L20_00443B60(char *arg0, char *arg1, char *arg2, float *arg3) {
    char *state = *(char **)(arg0 + 0x68);
    L20_V4 v1;
    L20_V4 v2;
    L20_V4 v3;
    L20_V4 v5;
    TI128 v4;
    TI128 v6;
    f32 r;

    v1.v = 0;
    v3.v = 0;
    v1.f.x = 5.0f;
    v1.f.z = 5.5f;
    r = func_002A7878(-1.0f, 1.0f);
    v3.f.y = r;
    v5.v = 0;
    v2.v = v3.v;
    v5.f.z = *(float *)(state + 0x298) * 0.5f;
    v4 = v5.v;
    func_002833F0(&v6, &v4);
    func_00283738(&v6, &v6, arg0 + 0xC0);
    func_00282CC0((char *)&v1, (char *)&v1, (char *)&v2);
    func_00283098((char *)&v1, (char *)&v1, (char *)&v6);
    func_00282CC0(arg1, (char *)&v1, arg0 + 0x10);
    r = func_002A7878(5.0f, 10.0f);
    v2.f.x = r;
    r = func_002A7878(4.0f, 6.0f);
    v2.f.z = r;
    func_00283098((char *)&v3, (char *)&v2, (char *)&v6);
    func_00282D30(arg2, (char *)&v3, 0.016666668f);
    *arg3 = *arg3 * v2.f.y;
}
