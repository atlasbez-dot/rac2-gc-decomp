/* func_L07_003EBAB8 (304 bytes, level 07_siberius) -- NEAR MISS, not integrated.
   state: the body is recovered (the mode change, the two VU calls on the
   scratch vector at +0x20, the 32-byte record the callee receives on the
   stack, the four calls and the float arguments), but one word of it is
   out of reach with plain C: the 16-byte zero store.

   Retail writes the scratch vector with
     003EBAFC  por $v0, $zero, $zero
     003EBB04  sq $v0, 0x20($sp)
     003EBB08  swc1 $f0, 0x28($sp)
   i.e. it materialises the 128-bit zero once and stores the register, and
   the zero feeds that one store.  This cc1 folds a TImode zero into the
   store that consumes it (`rac2_fold_zero_ti_store`, docs/COMPILER-NOTES.md):
   `*p = 0;` gives `sq $0,0($4)` and a zeroed local with one field written
   afterwards gives `sq $0,0($sp)` - both one word shorter than the retail.
   The `por` only survives when the zero feeds two or more stores (measured:
   two zero stores give `por $2,$0,$0 ; sq $2,0($4) ; sq $2,0($5)`), and
   this body has only one.

   The 16-byte copies this body does not have are the grouped `lq`/`sq`
   pairs of the retail's other functions; the file would need
     src/levels/07_siberius/L07_003EBAB8-rc2.c  -O2 -G0 -ffunction-sections -frac2-qcopy
   for them.

   What is measured and right:
   - the flags: `*(u16 *)(arg + 0x34) = (*(u16 *)(arg + 0x34) | 0x41) & 0xEFFF`
     - the retail masks with 0xEFFF after setting 0x41, the other way round
     from the two siblings in the same unit;
   - the 32-byte record the callee receives on the stack (its four words at
     +0, +8, +0x10, +0x18, the last one loaded from s2+0x314) is the
     callee's by-value argument, not a local: the retail never passes it;
   - the scratch vector at +0x20 is `{0, 0, 1.0f, 0}`: the zero store, then
     the float at +8;
   - func_0032C700 takes eight integer arguments (a0 = the scratch vector,
     a1 = 0, a2 = 0x19, a3 = 0x14, t0 = 0x14, t1 = 0x14, t2 = 0x2D, t3 = 1)
     and func_002B0A68 takes (arg, 0x7F8, &scratch, 0xFF) with f12 = 3.0f,
     f13 = 6.0f, f14 = 3.0f, f15 = 6.0f.

   Tried and not enough: the zero store as `*p = 0`, as a zeroed local with
   one field written afterwards and as a zeroed array; the record as a
   by-value argument and as a local; -frac2-qcopy (it does not reach the
   zero store, which is a store of a constant, not a copy). */
