/* 0 of 1 places match - 128-bit LQ/SQ stores (out of C reach).
   Level 7 (07_siberius), 0x002E2090, 112 bytes. Two `.word 0x7C400000` /
   `.word 0x7C600000` (opcode 0x1F = SQ, EE 128-bit store) hold the two 16-byte
   writes to the stack temporaries; the rest of the body is ordinary COP1 float
   work (lwc1/sub.s/mul.s with 0x3ECCCCCD = 0.4f and neg.s), so only the SQ pair
   blocks the match.
   MEASURED (this session, on func_L03_0041F048, same family): a 16-byte aggregate
   copy `*dst = *src;` compiles to 92 bytes of ld/sd word moves here, NOT to lq/sq -
   this cc1 does not emit the 128-bit forms from C. Both functions therefore need
   ASM_FUNC (lead decision) unless a builtin/attribute for the EE vector moves is
   found.

   Wave 24 (worker 06) corrects the second half of that note: this cc1 DOES emit
   lq/sq from C, with a 128-bit type,
       typedef int TI __attribute__((mode(TI)));
   and the copy is then `lq $v0,0($a) ; sq $v0,0($b)`.  A 16-byte *struct* is
   what copies as ld/sd word moves; the TI mode is the 128-bit type.  With the TI
   type the body compiles to 112 of the retail's 112 bytes and the only difference
   is the two zero stores' addresses:
       retail:  addiu $v0,$sp,0x10 ; sq $zero,0($v0)
                addiu $v1,$sp,0x20 ; sq $zero,0($v1)
       here:    sq $zero,0x10($sp) ; sq $zero,0x20($sp)
   the reload folds plus(reg,const) into a TImode address, and the "source
   address is base + const" case is out of C's reach (the common file's wall).
   What else the measurement settles:
   - the two locals are a union of the TI value and a float[4]: the float is
     written at offset 8 of the local (swc1 $f1,0x18($sp) for the first one),
     which is the second half of the 16 bytes.
   - the eight arguments follow the PS2 ABI ($a0-$a3 then $t0-$t3), and the
     retail shuffles them for the call: the callee gets
     (a0, a1, &v1, a2, &v2, a3, t0, t1) while the caller's seventh argument
     (t2) is the callee's ninth and goes on the stack (sw $t2,0($sp)); the
     caller's eighth argument is unused.  The callee is func_L04_0030C4C0.
   - the float work matches: f = (a2->f[2] - a1->f[2]) * 0.4f, stored into
     v1.f[2], and v2.f[2] = -f.
   - the zeroing of the two locals shares one zero register here
     (por $7,$0,$0 ; sq $7,16($sp) ; sq $7,32($sp)) where the retail has two
     independent `sq $zero`; the project's fold_zero_ti_store transformer only
     folds the register form back when the register is dead after the store,
     and here it feeds two stores. */

#include "include_asm.h"

INCLUDE_ASM("asm/levels", func_L07_002E2090);
