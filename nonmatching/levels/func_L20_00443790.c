/* near-miss: func_L20_00443790 (20_yeedil, 372 bytes).
   Wave 5 (20_yeedil, 2026-10-21, worker 03).
 *
 * The candidate below is 368 bytes against the retail's 372 and matches the
 * retail INSTRUCTION FOR INSTRUCTION everywhere except the 16-byte copy:
 *
 *   retail:  addiu $v1, $s0, 0xF0 ; addiu $a1, $s3, 0xF0
 *            lq $v0, 0x0($v1)     ; sq $v0, 0x0($a1)
 *   this:    lq $v0, 0xF0($s0)    ; sq $v0, 0xF0($s3)
 *
 * i.e. the retail MATERIALISES the two 16-byte addresses into registers and
 * uses a zero displacement, and this cc1 folds the offsets into the
 * displacement.  That is the 128-bit copy wall the wave-4 note closed
 * (gcc/cse.c's find_best_addr substitutes the class member plus(reg, const)
 * for the address pseudo because ADDRESS_COST(REG) = 1 ties with
 * mips_address_cost(plus(reg, const)) = 1, and the reload then prints the
 * offset as the displacement); the retail's shape is the one an inline-asm
 * copy macro in the original source produced, and src/ does not allow one.
 *
 * The wall was re-measured on this body with these spellings, all of which
 * fold the offset into the displacement: the copy through two pointer
 * variables, through one pointer variable and one expression, through a
 * `mode(TI)` pointer, through a `mode(TI)` member of a struct, through a
 * union with a `mode(TI)` member, through `__builtin_memcpy` of 16 bytes
 * (which gcc expands as ldl/ldr/sdl/sdr), through a static helper (which is
 * NOT inlined - it becomes a call), and with the base pointer loaded from
 * memory or reassigned.  The plain-pointer, symbol and stack-slot escapes of
 * the wave-4 note do not apply: both addresses here are base+const with a
 * runtime base.
 *
 * The rest of the body is recovered and is worth keeping:
 *
 *  - the frame is 0x60, with $s0/$s1/$s2/$s3/$s4 at 0x10/0x18/0x20/0x28/0x30,
 *    $ra at 0x38 and $f20/$f21/$f22 at 0x40/0x48/0x50; the only local is the
 *    float at 0x0($sp), whose ADDRESS is the third argument of the call to
 *    func_L00_0031CDD0 (`daddu $a2,$sp,$zero`);
 *  - the function returns the allocated object: the early exit
 *    (`beqz $s3,.L004438D4`) jumps to the same `daddu $v0,$s3,$zero` the
 *    normal path ends in, so the source returns the object and not a
 *    constant zero (the candidate has to wrap the body in `if (obj != 0)`);
 *  - the three level globals are read through $gp, so the body needs a -G8
 *    unit: D_L20_001B2168 (8.0f, gp+0x3178) times 1/60, D_L20_001B216C
 *    (100.0f, gp+0x317C) times 1/3600 and D_L20_001B2170 (-700.0f,
 *    gp+0x3180) times 0.000290888245f;
 *  - the halfword at obj+0x34 is read once, OR-ed with 0x100, AND-ed with
 *    0xEFDF and stored back once;
 *  - the object is allocated by func_0029EFD0(arg1) - the second argument is
 *    the size - and the first thing done with it is func_002B37E8(obj, arg0);
 *  - the calls, in order: func_002B37E8(obj, arg0), func_002833F0(obj+0xC0,
 *    arg0), func_00282CF0(state, arg2, obj+0x10), func_00282F20(state,
 *    state, f20), func_00282DD8(state+0x10, state, obj+0xE0),
 *    func_002ACE78(state+0x10, state+0x10, func_00283198(...)),
 *    func_L00_0031CDD0(obj+0x10, arg2, &local, f20, -f21),
 *    func_00283CF0(local); the last one stores its int result at state+0x24
 *    and the object's callback pointer at obj+0x64 is func_L20_00443908.
 */

typedef int TI128 __attribute__((mode(TI)));

extern float D_L20_001B2168 __attribute__((sda));
extern float D_L20_001B216C __attribute__((sda));
extern float D_L20_001B2170 __attribute__((sda));

extern void *func_0029EFD0(void *);
extern void func_002B37E8(char *, char *);
extern void func_002833F0(char *, char *);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282F20(char *, char *, float);
extern void func_00282DD8(char *, char *, char *);
extern float func_00283198(float);
extern void func_002ACE78(char *, char *, float);
extern float func_L00_0031CDD0(char *, char *, int, float, float);
extern int func_00283CF0(float);
extern void func_L20_00443908(void);

char *func_L20_00443790(char *arg0, void *arg1, char *arg2) {
    char *obj = (char *)func_0029EFD0(arg1);
    char *state;
    char *p;
    float f20;
    float f21;
    float local;
    unsigned short flags;
    TI128 *src;
    TI128 *dst;

    if (obj != 0) {
        func_002B37E8(obj, arg0);
        src = (TI128 *)(arg0 + 0xF0);
        dst = (TI128 *)(obj + 0xF0);
        *dst = *src;
        func_002833F0(obj + 0xC0, arg0);
        flags = *(unsigned short *)(obj + 0x34);
        flags |= 0x100;
        flags &= 0xEFDF;
        state = *(char **)(obj + 0x68);
        f20 = D_L20_001B2168 * 0.0166666675f;
        f21 = D_L20_001B216C * 0.000277777785f;
        p = state + 0x10;
        *(unsigned short *)(obj + 0x34) = flags;
        local = 0.0f;
        func_00282CF0(state, arg2, obj + 0x10);
        *(float *)(state + 8) = 0.0f;
        func_00282F20(state, state, f20);
        func_00282DD8(p, state, obj + 0xE0);
        func_002ACE78(p, p, func_00283198(D_L20_001B2170 * 0.000290888245f));
        *(float *)(state + 8) = func_L00_0031CDD0(obj + 0x10, arg2, (int)&local, f20, -f21);
        *(float *)(state + 0x20) = f21;
        *(int *)(state + 0x24) = func_00283CF0(local);
        *(void (**)(void))(obj + 0x64) = func_L20_00443908;
    }
    return obj;
}
