/* func_L07_003F8C38 -- best attempt (wave 3, worker w05, file src/levels/07_siberius/L07_003F4578.c)
 * Residual: size AND register allocation IDENTICAL (s0=a0, s2=0x68, s1=result,
 * obtained by declaring the result before the pointer). Only scheduling transpositions
 * of a few independent instructions are left:
 *   * addiu $a0,0x5 / daddu $a1,0 reversed for the call func_002E5CF8(5,0,a0)
 *   * the table base is loaded into $a1 instead of $v0 (hence addu $v1,$v1,$a1 vs $v0)
 *   * daddu $a0,$s1 placed after the table load instead of before
 */
typedef struct { u8 pad38[0x38]; f32 f38; u8 rest[128 - 0x3C]; } SibRec128;
extern SibRec128 *D_L07_001B23CC;
extern u8 *func_L07_003F6B88(u8 *a);
extern void func_L07_003F6C40(u8 *a, u8 *b, void *c, f32 d);
extern void func_0029FCC0(u8 *a, s32 b, void *c);
extern void func_002E5CF8(s32 a, s32 b, u8 *c);

void func_L07_003F8C38(u8 *a0)
{
    u8 *s1;
    u8 *s2 = *(u8 **)(a0 + 0x68);
    u8 buf[16];

    s1 = func_L07_003F6B88(*(u8 **)(s2 + 0x184));
    if (s1 == 0)
        return;
    func_0029FCC0(a0, 0, buf);
    func_002E5CF8(5, 0, a0);
    func_L07_003F6C40(s1, a0, buf, D_L07_001B23CC[*(s32 *)(s2 + 0x174)].f38 + 0.5f);
}

/* wave 24, worker 03 (src/levels/07_siberius/L07_003F8C38.c, file
   src/levels/07_siberius/L07_003F4578.c): the body is reached and the size is
   the retail's - tools/check.py func_L07_003F8C38 prints "instruction at
   +0x3c differs", the first 15 instructions are exact - but three
   instructions are transposed:

     retail   daddu $a0, $s1, $zero       (arg 1 of the last call)
              lui $v0, %hi(D_1B23CC)
              lw $v0, %lo(D_1B23CC)($v0)  (the table pointer in $v0)
              daddu $a1, $s0, $zero       (arg 2)
              ...
              daddu $a2, $sp, $zero       (arg 3)
     this cc1  lui $v0, %hi(D)
              lw $a1, %lo(D)($v0)          (the table pointer in $a1)
              daddu $a0, $s1, $zero
              ...
              daddu $a2, $sp, $zero
              daddu $a1, $s0, $zero       (arg 2, last)

   and the argument set-up of the middle call is reversed:

     retail   addiu $a0, $zero, 0x5 ; daddu $a1, $zero, $zero
     this cc1  daddu $a1, $zero, $zero ; addiu $a0, $zero, 0x5

   The two are the same thing: this cc1 evaluates the call's arguments right to
   left (the float argument first), so the table pointer lands in $a1 and the
   second argument's move is left until just before the call, while the retail
   sets the arguments up in the source order and keeps the table pointer in
   $v0.  Measured, all of them compiling to the same bytes: the float argument
   in the call and in a local assigned before it; the index in a local; the
   table pointer in a local; the float's expression written through a byte
   pointer; the declaration order of the locals (buf first, s2 first, s1
   assigned at its declaration); the prototype with the float as the first
   parameter (the ABI mapping is the same, $f12 and $a0-$a2, and the order
   does not change the expansion); and -fno-schedule-insns2, which does put the
   table pointer in $v0 but leaves the argument moves in the wrong place.  The
   body is otherwise exact, so this is a register-allocation and scheduling tie
   rather than a missing shape. */
