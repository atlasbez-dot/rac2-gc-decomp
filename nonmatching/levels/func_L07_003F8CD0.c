/* func_L07_003F8CD0, 188 bytes, 1 placement.  NOT ATTEMPTED - screened out (MMI class).
   `.word 0x700014A9` (pcpyld $v0,$zero,$zero) at +0x30, followed by
   `.word 0x7FA20030` (sq $v0,0x30($sp)): the same 128-bit zero materialisation the
   func_L00_003ACC88 near miss records, folded to `sq $zero` by rac2_fold_zero_ti_store because
   the register is dead afterwards.  The rest of the body is ordinary calls (func_307940 =
   func_0029FCC0, func_2E45F0 = func_00282F20, func_L07_003F6528, func_2E2100 =
   func_L04_0030C4C0, func_L07_003F65E8).  Near miss deposited instead of C, as the brief asks
   for the MMI class. */

/* wave 24, worker 03: the body is not MMI - it is the project's own
   `rac2_fold_zero_ti_store` wall plus a five-call body.  The retail's
   `por $v0,$zero,$zero ; sq $v0,0x30($sp)` is a 128-bit zero that this
   project folds back into `sq $zero` whenever the register is dead after the
   store; in the retail $v0 is still live there, because the same register
   takes the return value of f_003F65E8 further down (`daddu $s0, $v0, $zero`),
   so the fold does not fire there.  Whether this cc1 keeps the same register
   for the two is a register-allocation question, and the rest of the body
   (the three stack buffers at sp+0x10, sp+0x20 and sp+0x30, the 5.0f at
   sp+0x38, the five calls and the rotated loop) still has to be found.
   Left unattempted: the budget of the wave went on the bodies above. */
