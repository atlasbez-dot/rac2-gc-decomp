/* func_L05_00420FB0 (332 bytes, 1 place: level 05_feltzin_system at 0x00420FB0)
   -- NEAR MISS, not integrated.

   A second attempt at this function; the first is
   nonmatching/levels/func_L05_00420FB0-g8.c (328 bytes, the same three walls).
   This one compiles to the retail's 332 bytes and adds the measurements below.

   What retail does (0x00420FB0..0x004210FB):
     - a 0x50 frame with no local area: $s0..$s5, $ra and $f20;
     - the register plan: $s0 = the object array, $s1 = the loop counter, $s2 and
       $s3 = the two halves of the address of D_L05_00221D10, $s4 = 0xF73 and $s5 =
       the argument;
     - the loop over the objects: the type test at +0xAA is a branch-likely
       (`bnel $v0,$s4`) whose annulled delay slot holds the counter decrement
       (`addiu $s1,$s1,-0x1`), and a second decrement sits at the loop's bottom,
       right before `bnez $s1`; the skip path therefore never decrements the
       counter, and the array advances by 4 in the `bnez` delay slot;
     - the counter starts at the address of D_L05_00221D10 (0x00221D10), which the
       compiler materialises as `lui $s3,0x22` + `addiu` and copies into $s1;
     - the object array comes from the return value of func_00379EC8 (the count
       global), while the call to func_00379EB8 (the array of registered objects)
       has its result discarded: the loop walks the count as if it were the array.
       The C below reproduces that, whatever the intent was;
     - the prologue: the clear of D_L05_00221D10[11] first, then the call to
       func_003404B8 with the flag store D_001B1364 = 1 in its delay slot.

   The attempt below gets the calls, the loop, the register plan, the frame and the
   whole tail right; three things are still off:

     00420FE4  addiu $v0, $zero, 0x1   | addiu $v0, $s3, 0x1D10
     00420FE8  addiu $s1, $s3, 0x0     | addiu $v1, $zero, 0x1
     00420FEC  sw    $v0, 0x0($gp)    | sw    $zero, 0x2C($v0)
     00420FF0  jal   func_000000      | jal   func_3404B8
     00420FF4  sw    $zero, 0x2C($s1) | sw    $v1, 0x2374($gp)
     00421014  nop                    | daddu $s0, $v0, $zero
     00421040  bne   $v0, $s4, ...    | bnel  $v0, $s4, ...
     00421044  nop                    | addiu $s1, $s1, -0x1

   check.py (05_feltzin_system), with the source below:
     05_feltzin_system: instruction at +0x34 differs
     func_L05_00420FB0: 0 of 1 places match

   Measured and right:
   - the file needs -G8: the level's reset flag D_001B1364 is reached through $gp
     in retail (`lw $v0,0x2374($gp)`, `sw $v1,0x2374($gp)`), so the body has to live
     in a `-g8.c` unit (src/levels/05_feltzin_system/L05_00420360-g8.c).
   - the loop's entry guard is the raw return of func_00379EC8 (`blezl $v0`), and the
     array pointer is a copy of it (`daddu $s0,$v0,$zero`): with the test on the copy
     the compiler emits `blez $s0` instead.
   - the loop must be a do-while: with `while (n)` this cc1 peels the test to the
     top of the body (an extra `beqz` that retail does not have).
   - the objects must be read through the array pointer (`*p`) and not through a
     local: with a local the compiler keeps the object in a register and the frame
     grows past 0x50.
   - the two calls that take the entry take (object, entry + 0x30) with the entry
     index read from D_L05_00221D10[0] and scaled by 128 (D_001B2614 + index*128).

   Tried and not enough: the counter decrement at the start of the if body, in the
   middle of the if body and at its end (this cc1 always sinks it to just after the
   first call); two decrements in the if body (they come out adjacent); the counter
   decremented in the while condition (the delay slot then holds the copy for the
   test, `daddu $v0,$s1,$zero`); the type test written as `!=` with a `continue`
   (the compiler emits `beq` plus a `b`); the two prologue stores in either order
   (the compiler hoists the flag store and sinks the clear into the call's delay
   slot whichever order the source uses).

   What is left to try: the spelling that makes this cc1 take the branch-likely
   form on the type test with the decrement in the annulled slot, the way the
   matched func_L05_0037B280 does (`bnel` with the handler pointer advance in the
   slot) and the way func_L05_00421100 does (`bnel` with the counter decrement in
   the slot); and a spelling of the two prologue stores that keeps the clear first
   and the flag store in the call's delay slot.

   Drafted against src/levels/05_feltzin_system/L05_00420360-g8.c, -O2 -G8
   -ffunction-sections.  The INCLUDE_ASM marker for this function is still in
   src/levels/05_feltzin_system/L05_00420360.c; integrating this draft means
   moving it to the -g8 sibling, as func_L05_004209D8 already is. */

typedef unsigned char u8;
typedef signed int s32;
typedef unsigned short u16;
typedef float f32;

extern void func_003404B8(void);
extern void func_0037B210(void);
extern void func_00379F18(s32 a0);
extern u8 **func_00379EB8(void);
extern s32 func_00379EC8(void);
extern void func_0037B280(u8 *a0, s32 a1);
extern void func_0037CEE0(u8 *a0, u8 *a1, f32 f12);
extern void func_0037D608(u8 *a0, u8 *a1, f32 f12);
extern void func_L05_00420788(u8 *a0, s32 a1);

extern s32 D_001B1364 __attribute__((sda));
extern s32 D_L05_00221D10[];
extern s32 D_L05_001B2048;
extern u8 *D_001B2614;

void func_L05_00420FB0(u8 *arg0) {
    s32 n;
    s32 count;
    u8 **p;

    if (D_001B1364 == 0) {
        D_L05_00221D10[11] = 0;
        D_001B1364 = 1;
        func_003404B8();
        func_0037B210();
        func_00379F18(0);
        func_00379EB8();
        count = func_00379EC8();
        if (count > 0) {
            p = (u8 **)count;
            n = (s32)(u32)&D_L05_00221D10[0];
            do {
                if (*(s16 *)(*p + 0xAA) == 0xF73) {
                    func_0037B280(*p, 1);
                    func_0037CEE0(*p, (u8 *)D_001B2614 + (D_L05_00221D10[0] << 7) + 0x30, 64.0f);
                    func_0037D608(*p, (u8 *)D_001B2614 + (D_L05_00221D10[0] << 7) + 0x30, 64.0f);
                    n--;
                }
                p++;
            } while (n);
        }
    }
    if (D_L05_00221D10[4] == 0 && D_L05_001B2048 >= 6)
        func_L05_00420788(arg0, 2);
}
