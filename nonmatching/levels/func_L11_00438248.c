/* func_L11_00438248 (212 bytes, 1 place) -- NEAR MISS, not integrated.
   state: 216 bytes against the retail's 212; the call sequence, the twelve
   rounds and the two quadword copies are the retail's; the register
   allocation and the copy operands are not.
   check.py (11_joba), with the source below:
     11_joba: 216 bytes, expected 212
     func_L11_00438248: 0 of 1 places match (src/levels/11_joba/L11_00432628.c)

   What is measured and right:
   - the body is func_002833F0(obj + 0xC0, obj + 0xF0), then two quadword
     copies of obj + 0x10 into state + 0x100 and state + 0x1D0, then
     func_00282D30(&v, obj + 0xC0, -1.0f), then twelve rounds of
     func_00282F20(&v, &v, timer[i]), func_003004E0(a + 1, a, &v) and
     *(b + 1) = *(a + 1).
   - the three helpers are the level's own places of the VU0 routines:
     func_00282D30 at 11:00300580 scales a vector by a float, func_00282F20
     at 11:003007F8 normalises it and func_003004E0 at 11:003004E0 adds two
     of them.  The boot's func_00282CC0 (11:003004B0, the vector-zero store)
     is a different function and must not be used for the sum.
   - the twelve rounds are a downcounter from 11, so the source loop is `i < 12`.
   - the two quadword copies are `lq`/`sq` pairs: a `mode(TI)` copy, not a
     struct assignment (a struct assignment gives ldl/ldr/sdl/sdr).

   What is left:
   - the register allocation: the retail keeps the state pointer in $s1 and the
     chain pointer in $s3, this draft keeps them in $s1 and $s2, and the retail
     copies the chain pointer with `daddu $s3, $s0, $zero` where this draft adds
     0x10 to it.  The retail reuses $s1 for the timer pointer and $s3 for the
     chain pointer once the state and the obj + 0xC0 pointers are dead; this
     draft needs one callee-saved register more, so the frame is 0x50 against
     the retail's 0x40.
   - the copy of the next link: the retail materialises the next pointers ($s0
     and $v1) and copies through them (`lq $v0, 0x0($s0); sq $v0, 0x0($v1)`),
     this draft folds the +0x10 into the lq/sq operands (`lq $v0, 0x10($s1)`).
     The same happens for the two copies before the loop: the retail keeps
     state + 0x100, state + 0x1D0 and obj + 0x10 in registers, this draft folds
     them into the lq/sq offsets.
   - the retail's timer pointer advances by four bytes each round
     (`addiu $s1, $s1, 0x4` in the branch's delay slot), this draft computes
     the address from the index.

   Tried and not enough: the chain pointers as TI128* and as char*, the timer
   as an index (state + 0x2F0 + 4 * i) and as a float pointer, the next link
   as a1/b1 temporaries inside the body and at function scope, the two copies
   written before and after the obj + 0x10 pointer, and `a++` against
   `a += 1`. */

extern void func_002833F0(char *, char *);
extern void func_00282D30(char *, char *, float);
extern void func_00282F20(char *, char *, float);
extern void func_003004E0(void *, void *, void *);

typedef int TI128 __attribute__((mode(TI)));

void func_L11_00438248(char *obj)
{
    char *state;
    TI128 *a;
    TI128 *b;
    TI128 *a1;
    TI128 *b1;
    TI128 v;
    int i;

    func_002833F0(obj + 0xC0, obj + 0xF0);
    state = *(char **)(obj + 0x68);
    a = (TI128 *)(state + 0x100);
    b = (TI128 *)(state + 0x1D0);
    *a = *(TI128 *)(obj + 0x10);
    *b = *(TI128 *)(obj + 0x10);
    func_00282D30((char *)&v, obj + 0xC0, -1.0f);
    for (i = 0; i < 12; i++) {
        func_00282F20((char *)&v, (char *)&v, *(float *)(state + 0x2F0 + 4 * i));
        a1 = a + 1;
        b1 = b + 1;
        func_003004E0(a1, a, &v);
        *b1 = *a1;
        a = a1;
        b = b1;
    }
}
