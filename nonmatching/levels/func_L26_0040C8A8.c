/* func_L26_0040C8A8 (232 bytes, 1 placement, level 26 jamming array): NEAR MISS.
   This plain C compiles to 228 bytes and matches retail's first 0xBC bytes; the last
   difference is the 16-byte clear of the local quadword and the delay slot that follows
   the kind test.

   Measured with the project compiler (-O2 -G0 -ffunction-sections), the shape that
   reproduces retail's switch layout (both case bodies out of line, `beqz $v1` to the
   kind-0 body, `beq $v1,$v0` to the kind-1 body) is a `switch` on the moby's kind byte,
   not an if/else chain: with if/else cc1 keeps the kind-0 body inline and emits
   `bne $v1,$zero` instead. The float constant is 1.7f (0x3FD9999A) and the three
   records are cleared in the order 0xD4, 0xD0, 0x100.

   What is left:
     - the 16-byte clear. Retail materialises the address and stores the
       architectural zero: `addiu $v0,$sp,0x20 ; sq $zero,0($v0)`. This cc1 folds the
       frame offset into the store and materialises the zero instead:
       `por $v0,$zero,$zero ; sq $v0,0x20($sp)`. The project's fold transformer
       (tools/compiler/transformers/fold_zero_ti_store.py) only folds a zero TImode
       store into `sq $zero` when the destination address is a plain register, and
       retail's cc1 keeps a TImode address in a register (the rule measured in
       nonmatching/game/func_002EE988.c and nonmatching/game/func_002B5678.c: retail
       never lets cse rewrite a TImode store's address from a register to
       register-plus-constant). A frame slot at a non-zero offset is therefore always
       `sq $zero,off($sp)` here, and the fold cannot fire. Spellings measured and
       rejected: a TI128 local, `*(TI128 *)&v = 0`, a TI128 pointer to the local, a
       `void *`/`char *` alias of it, an `aligned(16)` struct, a union, `memset`, and
       passing the same pointer to the call (the address is still folded).
     - the delay slot of the second `beq`. Retail sets up both the first argument of
       the kind-0 call (`daddu $a0,$s1,$zero`) and the first argument of the kind-1
       call (`addiu $a1,$s0,0x60`) and puts the first of the two in the slot; this
       cc1 puts the second one there and never sets the first up again, so the body
       is one instruction short (228 bytes against retail's 232). The two choices are
       the same kind of delay-slot fill and depend on the block order.

   The declarations below are the ones the body needs; the file it came from is
   src/levels/26_jamming_array/L26_002EC840.c. */

typedef unsigned char u8;
typedef int TI128_L26_0040C8A8 __attribute__((mode(TI)));

typedef struct {
    int a;
    float b;
    int c;
    int d;
} Quad_L26_0040C8A8;

extern void func_002B41A8(char *, char *, char *, char *, char *, char *, char *, char *,
                          char *, char *, char *);
extern void func_002A7750(char *, int, int);
extern void func_002B44C0(char *, char *);

void func_L26_0040C8A8(char *a0) {
    char *s1 = a0;
    char *s0 = *(char **)(s1 + 0x68);
    Quad_L26_0040C8A8 v;

    switch (*(u8 *)(s1 + 0x20)) {
    case 0:
        *(TI128_L26_0040C8A8 *)&v = 0;
        if (*(int *)(s0 + 0x120) != 0)
            v.b = (float)*(int *)(s0 + 0x120) * 1.7f;
        func_002B41A8(s1, s0 + 0x60, (char *)&v, 0, 0, 0, 0, 0, 0, 0, 0);
        if (*(int *)(s0 + 0x120) != 0) {
            *(int *)(s0 + 0xD4) = 0;
            *(int *)(s0 + 0xD0) = 0;
            *(int *)(s0 + 0x100) = 0;
        }
        func_002A7750(s1, 1, -1);
        break;
    case 1:
        func_002B44C0(s0 + 0x60, 0);
        break;
    }
}
