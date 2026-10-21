/* func_L00_003E7650 (268 bytes, 27 places) -- NEAR MISS, not integrated.
   state: 260 bytes against retail's 268; the body, the calls and the store
   order are retail's, but the frame is eight bytes short and two float
   constants sit in the wrong registers.
   check.py (00_aranos_tutorial), with the source below:
     003E7674  addiu $a0, $zero, 0xC07  |  addiu $a0, $zero, 0xC07
     003E7678  jal   func_000000       |  sd    $ra, 0x28($sp)
     003E767C  addiu $a0, $zero, 0xC07 |  swc1  $f21, 0x38($sp)
     003E7680  daddu $s1, $v0, $zero   |  jal   func_3100D8
     003E7684  beqz  $s1, ...          |  swc1  $f20, 0x30($sp)
     003E7688  addiu $v1, $zero, 0xFF  |  daddu $s1, $v0, $zero
     003E768C  addiu $v0, $zero, 0xFF  |  beqz  $s1, ...
     003E7690  sh    $v1, 0x32($s1)    |  addiu $v0, $zero, 0xFF
     003E7694  sb    $v0, 0x30($s1)    |  lw    $s0, 0x68($s1)
     003E7698  sb    $zero, 0x20($s1)  |  sb    $v0, 0x30($s1)
     003E769C  lw    $s0, 0x68($s1)    |  addiu $v1, $s1, 0x10
     003E76A0  lq    $v0, 0x0($s2)     |  sh    $v0, 0x32($s1)
     003E76A4  lui   $at, 0x3C23       |  sb    $zero, 0x20($s1)
     003E76B0  sq    $v0, 0x10($s1)    |  lq    $v0, 0x0($s2)
     003E76B4  lui   $at, 0x3D56       |  sq    $v0, 0x0($v1)
     003E76B8  ori   $at, $at, 0x8464  |  lq    $v0, 0x0($s3)
   Three measured differences:
   1. The two float constants 0x3D567752 (0.052359886f) and 0x3DD67752
      (0.104719773f) are materialised into the callee-saved $f20 and $f21 in
      retail and re-materialised into $f12/$f13 at each call in this cc1.  The
      frame follows: 0x40 bytes with $f20/$f21 against 0x30 without.  A float
      local at function scope that is used across a call does take a
      callee-saved register (the matched func_002ACB48 keeps `negative` in
      $f20), but a local initialised with a literal is folded away by the
      tree level, and what is left is a constant that this cc1 rematerialises.
      The retail source's two bounds are therefore not literals in this cc1's
      view, yet retail materialises them with lui/ori, so they are constants
      that retail keeps in a register.  Spelling not found.
   2. The destination of the first 16-byte copy is retail's
      `addiu $v1, $s1, 0x10` + `sq $v0, 0x0($v1)`; this cc1 folds the offset
      into the store and gives `sq $v0, 0x10($s1)`.  The same body with a
      plain-pointer destination (the matched func_002A8C00) does give the
      `sq $v0, 0x0($reg)` form, so the pointer has to reach the store as a
      register; every spelling measured here folds the offset.
   3. The two 0xFF stores (byte 0x30 and halfword 0x32) come out in two
      registers and in the wrong order; retail keeps one $v0 for both and
      stores the byte first.  The matched func_00310960 writes the same two
      fields the same way and is a copy of the same idiom.

   The rest of the body is retail's: the `if (obj != 0) { ... } return obj;`
   shape (the branch goes to the one exit where $v0 = obj), the two `lq`/`sq`
   copies, the 0.01f store in the delay slot of the first random call, the
   second random call's result stored in the delay slot of the next call, and
   the child record's five stores. */

extern int func_0029EFD0(int id);

extern float func_002A7878(float a, float b);

extern int func_002FED90(void *obj, int zero, float f12, float f13, float f14);

extern void func_002A0F48(void *obj);

typedef int TI128 __attribute__((mode(TI)));

/* Creates an object of type 0xC07, fills its identity fields, copies two 16-byte blocks
   into it, then sets up the child record through three helpers. */
void *func_L00_003E7650(void *a0, void *a1, void *a2)
{
    char *obj;
    char *sub;
    char *dst;
    float r1;
    float r2;
    int r3;
    float lo = 0.05235988646745682f;
    float hi = 0.10471977293491364f;

    obj = (char *)func_0029EFD0(0xC07);
    if (obj != 0) {
        sub = *(char **)(obj + 0x68);
        *(unsigned char *)(obj + 0x30) = 0xFF;
        *(unsigned short *)(obj + 0x32) = 0xFF;
        *(unsigned char *)(obj + 0x20) = 0;
        dst = obj + 0x10;
        *(volatile TI128 *)dst = *(TI128 *)a1;
        *(volatile TI128 *)sub = *(TI128 *)a2;
        *(float *)(obj + 0x2C) = 0.01f;
        r1 = func_002A7878(lo, hi);
        *(float *)(sub + 0x10) = r1;
        r2 = func_002A7878(lo, hi);
        *(int *)(sub + 0x30) = (int)a0;
        *(int *)(sub + 0x18) = 0;
        *(float *)(sub + 0x14) = r2;
        r3 = func_002FED90(obj, 0, 1.0f, 1.0f, 1.0f);
        *(int *)(sub + 0x34) = r3;
        func_002A0F48(obj);
    }
    return obj;
}
