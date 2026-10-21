/* Not landable: this body reaches a 128-bit copy through `qcopy`/`qzero` or a local
   `__asm__` helper, and AGENTS.md's "Plain C" rule (no inline assembly in a function)
   forbids that as a matching route. Kept as a starting point. Removed from src/ 2026-10-13.

   Wave 24 (worker 06) re-measured it without the helper: the copy does not need
   one, a 128-bit type does it -
       typedef int TI __attribute__((mode(TI)));
       void func_L14_00328E70(TI *a0, TI *a1, TI *a2) {
           *a1 = *((TI *)((char *)a0 + 0x10));
           *a2 = *((TI *)((char *)a0 + 0xF0));
       }
   - but the two SOURCE addresses fold into the lq (`lq $v0,0x10($a0)`,
     `lq $v0,0xF0($a0)`) where the retail materialises them
     (`addiu $v1,$a0,0x10 ; lq $v0,0($v1)`), because the reload accepts
     plus(reg,const) as a TImode address.  The destinations are plain pointers
     and match (`sq $v0,0($a1)`, `sq $v0,0($a2)`).
   - the fold happens in every spelling tried (the direct cast, a TI *p variable
     - the CSE rewrites p to the plus -, a modified parameter, a struct member,
     a volatile source, a register pointer) and with every flag set tried
     (-O2 -G0, -O2 -G8, -O1).  A modified parameter materialises the first
     address but then folds the second one as lq $v1,0xE0($a0), and the retail
     needs the second address to be a0+0xF0 from the unmodified a0.
   - the "source address is base + const" case is out of C's reach (the common
     file's wall), so this body is not landable as plain C either. */

func_L14_00328E70(char *arg0, char *arg1, char *arg2) {
    qcopy(arg1, arg0 + 0x10);
    qcopy(arg2, arg0 + 0xF0);
}
