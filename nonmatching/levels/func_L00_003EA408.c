/* func_L00_003EA408, 00_aranos_tutorial + 14_aranos_prison, 312 bytes.
   Semantics fully decoded and reproduced (this deposit compiles at exact 316
   bytes, 0 of 2 places):
   - re-arm once: when *(u8 *)(obj+0x20) == 0 write the 0x32 field 0xAF0,
     the 0x30 field 0xFF, call func_2E54E0 and set the 0x20 flag to 1;
   - return unless the re-read flag == 1;
   - unless ref_L00_001A8F00_00 == 2 (level-bound global): func_2EE048 outputs
     nothing into the object. Instead the RETAIL body stores the INPUT of the
     helper (the angle minus 1.66666674613952641f, 0x3FD55556) back into the
     0x14 field in the helper's jal delay slot, and uses the helper's return
     only inside the wish (retail: ret = 3000.0f - returned; ret = 750.0f -
     ret; ret *= 0.00133333331905305f (0x3AAEC33E); wish = 1.0f - ret);
   - the 0x2C store of the looked-up value runs UNCONDITIONALLY in the final
     bc1f's (non-likely) delay slot, and 3000.0f goes back into the 0x14 field
     only when the re-read 0x14 angle <= -3000.0f.

   Measured residue (this deposit = best plain-C state, per-file plain
   -O2 -G0 -ffunction-sections, 316 bytes, both places):
   1. the init call's argument setup: ours emits the 3000.0f materialisation
      (lui/ori/mtc1 $at,$f12) before addiu $a0,$zero,1; retail has addiu a0
      first. Measured invariant: this cc1 materialises the float argument
      first no matter which position it has - tried prototypes (int, float)
      and (float, int) with matching call sites, and -fno-schedule-insns /
      -fno-schedule-insns2 alone and combined (with both scheds disabled the
      a0 setup even sinks into the jal's delay slot on its own). docs/
      MATCHING-BLOCKERS.md entry 45 records the same ABI-first rule.
   2. the post-call flag store: the C store re-computes the constant
      (li $v0,1 ; sb $v0,0x20) = 4 bytes longer than retail, whose jal delay
      slot holds sb $a0,0x20($s0) - the store reading the call's own argument
      register. That is reload assigning the store's pseudo to the arg
      register itself, which none of the tried C shapes produced (constant
      store after/before the call; a shared int local for arg and store).
      GCC's reorg does fill call delay slots from the insn after the call
      (measured with a `li $a0,1` in the delay under -fno-schedule-*), so the
      slot itself is not the blocker: the blocker is that reload keeps the
      store's constant out of the arg register.
   3. the ref-check block's register plan: ours materialises the 2 into $a0
      next to a `lui $v0,hi` address, retail into $v0 with the address in the
      same register as the value (lui $v1 / lw $v1,%lo). Same instruction
      count, pure register naming.

   Everything from the func_2EE048 call to the final stores matches retail
   word for word, so the body is one argument-block placement away. */

void func_L00_003EA408(char *a0)
{
    extern void func_2E54E0(int mode, float amount);
    extern float func_2EE048(float f);
    extern int ref_L00_001A8F00_00;

    char *obj = a0;

    if (*(unsigned char *)(obj + 0x20) == 0) {
        *(unsigned short *)(obj + 0x32) = 0xAF0;
        *(unsigned char *)(obj + 0x30) = 0xFF;
        func_2E54E0(1, 3000.0f);
        *(unsigned char *)(obj + 0x20) = 1;
    }
    if (*(unsigned char *)(obj + 0x20) != 1)
        return;

    if (ref_L00_001A8F00_00 != 2) {
        float slid;
        float ret;
        float wish;
        float value;

        slid = *(float *)(obj + 0x14) - 1.66666674613952641f;
        *(float *)(obj + 0x14) = slid;
        ret = func_2EE048(slid);
        wish = 1.0f - (750.0f - (3000.0f - ret)) * 0.00133333331905305f;
        if (wish > 3.0f)
            wish = 3.0f;
        if (wish < 0.0f)
            wish = 0.0f;
        value = *(float *)(*(int *)(obj + 0x24) + 0x24) * wish;
        *(float *)(obj + 0x2C) = value;
        if (*(float *)(obj + 0x14) <= -3000.0f)
            *(float *)(obj + 0x14) = 3000.0f;
    }
}
