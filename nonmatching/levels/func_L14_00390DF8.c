/* Not landable: this body reaches a 128-bit copy through `qcopy`/`qzero` or a local
   `__asm__` helper, and AGENTS.md's "Plain C" rule (no inline assembly in a function)
   forbids that as a matching route. Kept as a starting point. Removed from src/ 2026-10-13.

   Wave 24 (worker 06) re-measured it: the copies do not need the helper, a
   128-bit type does them -
       typedef int TI __attribute__((mode(TI)));
       TI buf;                                  /* the local at sp+0 */
       *(TI *)D_0018A0E0 -> buf;                /* a symbol: reachable */
       *(TI *)(arg0 + 0x30) = *(TI *)arg1;      /* base + const: not reachable */
       *(TI *)arg0 = *(TI *)arg2;               /* a plain pointer: reachable */
   - the copy from the symbol and the copy to the plain pointer come out exactly
     as the retail has them (lui + addiu for the symbol, lq/sq with a zero
     displacement), and the copy to the stack slot at sp+0 is the "stack slot at
     offset 0" case.
   - the second copy, to arg0+0x30, is the "source address is base + const"
     case: the reload folds plus(reg,const) into a TImode address
     (`sq $v0,0x30($s0)`) where the retail materialises it
     (`addiu $v1,$s0,0x30 ; sq $v0,0($v1)`).  That case is out of C's reach
     (the common file's wall), so this body is not landable as plain C.
   - the rest of the body (the four calls, the 1.0f and -1.0f) is plain C.

   Wave 24 (worker 06) compiled the body with the 128-bit type: 192 of the
   retail's 196 bytes.  The copy from the symbol and the copy to the plain
   pointer come out exactly as the retail has them, the second copy's
   destination folds (`sq $v0,0x30($s0)` where the retail has
   `addiu $v1,$s0,0x30 ; sq $v0,0($v1)`), and this cc1 hoists the two copies
   through arg0 above the func_2F5CC0 call where the retail keeps them below
   it. */

func_L14_00390DF8(char *arg0, char *arg1, char *arg2) {
    char buf[16];

    qcopy(buf, D_0018A0E0);
    ((void (*)(void *, void *, float))func_2F5CC0)(buf, buf, -1.0f);
    qcopy(arg0 + 0x30, arg1);
    qcopy(arg0, arg2);
    {
        float one = 1.0f;

        func_2F5F18(arg0, arg0, one);
        func_2F5D68(arg0 + 0x10, arg0, buf);
        func_2F5F18(arg0 + 0x10, arg0 + 0x10, one);
        func_2F5D68(arg0 + 0x20, arg0 + 0x10, arg0);
    }
}
