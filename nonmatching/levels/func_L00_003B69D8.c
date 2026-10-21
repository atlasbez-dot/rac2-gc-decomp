/* func_L00_003B69D8 (180 bytes, 27 places) -- NEAR MISS, not integrated.

   New measurement (wave 12, worker s4): with the *catalogue* names of the callees
   (func_L00_003B6B70, func_L00_003B6F88, func_00283098, func_00282CC0,
   func_002833F0, func_002A0F48 - the earlier deposit used the level-code names,
   func_3B6B70 and friends, which the linker cannot resolve) the candidate is
   *exactly* retail's 180 bytes and every instruction but the register assignment
   matches.

   What is left is the callee-saved allocation.  Retail: $s0 = the parameter and
   then the walked array pointer, $s1 = the fresh load of a0->f68 and then that
   pointer plus 0x10, $s2 = the constant 0x001B8FF0, $s3 = the counter.  This
   cc1: $s0 = the constant, $s1 = the fresh load, $s2 = that pointer plus 0x10,
   $s3 = the counter - i.e. the constant takes the first callee-saved register
   and the parameter never gets a copy.  Five spellings measured (the two
   pointers declared in both orders, the declarations moved after the calls, an
   explicit `NODE *o = a0` copy, the constant introduced through a local
   variable): the last one is 184 bytes (the constant needs a register of its
   own), the others keep the same allocation.

   The single-base form of 0x001B8FF0 is required: the second call's argument is
   `0x001B8FF0 - 0x230`, computed from the same base (retail: `addiu $a2,$s2,-0x230`).

   Wave 12 (worker s4). */
typedef struct NODE {
    char pad0[0x68];
    void *f68;
} NODE;

extern void func_L00_003B6B70();

extern void func_L00_003B6F88();

extern void func_00283098(void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

extern void func_002833F0(void *, void *);

extern void func_002A0F48(void *);

extern char D_L00_001B8FF0[];

void func_L00_003B69D8(NODE *a0)
{
    char *q = (char *)a0->f68 + 0x10;
    void **p = a0->f68;
    int i;

    func_L00_003B6B70();
    func_L00_003B6F88(a0);
    for (i = 1; i >= 0; i--) {
        func_00283098((char *)*p + 0x10, q, D_L00_001B8FF0);
        q += 0x10;
        func_00282CC0((char *)*p + 0x10, (char *)*p + 0x10, D_L00_001B8FF0 - 0x230);
        func_002833F0((char *)*p + 0xC0, (char *)*p + 0xF0);
        func_002A0F48(*p);
        p++;
    }
}
