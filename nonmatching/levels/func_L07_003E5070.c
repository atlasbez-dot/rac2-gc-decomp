/* func_L07_003E5070 (292 bytes, level 07_siberius) -- NEAR MISS, not integrated.
   state: the body is recovered (the VU call on the object, the two 16-byte
   locals, the four calls and the float arguments), but the 16-byte zero
   store is out of reach with plain C, the same way it is in
   func_L07_003EBAB8.

   Retail writes the second local with
     003E50BC  por $v0, $zero, $zero
     003E50D0  sq $v0, 0x220($sp)
     003E50D4  addiu $a1, $sp, 0x220
     003E50D8  swc1 $f0, 0x21C($sp)
     003E50DC  daddu $a0, $s2, $zero
     003E50E0  jal func_2E4B70
     003E50E4  swc1 $f1, 0x228($sp)
   i.e. it materialises the 128-bit zero once and stores the register, and
   the zero feeds that one store.  This cc1 folds a TImode zero into the
   store that consumes it (`rac2_fold_zero_ti_store`, docs/COMPILER-NOTES.md):
   `*p = 0;` gives `sq $0,0($4)` and a zeroed local with one field written
   afterwards gives `sq $0,0($sp)` - both one word shorter than the retail.
   The `por` only survives when the zero feeds two or more stores (measured:
   two zero stores give `por $2,$0,$0 ; sq $2,0($4) ; sq $2,0($5)`).

   The 16-byte copy at +0x210 is the retail's grouped `lq $v0,0($s0) ;
   sq $v0,0($v1)` pair, so the file would need
     src/levels/07_siberius/L07_003E5070-rc2.c  -O2 -G0 -ffunction-sections -frac2-qcopy
   for it; the grouped copy does not reach the zero store, which is a store
   of a constant, not a copy.

   What is measured and right:
   - the frame is 0x260 with the two 16-byte locals at +0x210 and +0x220 and
     the five saved registers at +0x230..+0x258;
   - the second local is `{0, 0, 0.32f, 0}` - the zero store, then the
     float at +8 - and the first float of the pair at +0x21C belongs to a
     separate one-float local;
   - the calls: func_00283658(object+0xC0, &scratch), func_002833F0(&scratch,
     &other), func_L01_0031BC68(D_..., f), func_00283D38(mask, mask),
     func_L02_002EF968(sp, 5, D_..., 1, table+0x40) twice and
     func_L01_002E1510(sp, 2, 0x20, &scratch, &other).

   Tried and not enough: the zero store as `*p = 0`, as a zeroed local with
   one field written afterwards and as a zeroed array; the two locals as one
   array and as separate variables; -frac2-qcopy (it does not reach the
   zero store). */
