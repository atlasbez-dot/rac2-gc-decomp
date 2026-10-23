/* func_L05_00422540 (252 bytes, 1 place: level 05_feltzin_system at 0x00422540)
   -- NEAR MISS, not integrated.

   What retail does (0x00422540..0x0042263C):
     - a 0xA0 frame: the local area is 0x60 bytes and the saved registers start at
       0x60 ($s0 0x60, $s1 0x68, $s2 0x70, $s3 0x78, $s4 0x80, $ra 0x88, $f20 0x90);
     - the local area holds a 16-byte vector at 0x00 (cleared with
       `por $v0,$zero,$zero` + `sq $v0,0($sp)`, then `swc1 $f20,0x8($sp)`), the two
       16-byte temporaries at 0x10 and 0x20, and 0x30 bytes that retail never touches;
     - the register plan: $s1 = the argument, $s4 = the object pointer, $s0 = the
       second call's result, $s3 = &temp1, $s2 = &temp2; the addresses p+0xD0 and
       p+0xC0 are materialised only at their first use (0x004225DC and 0x004225D0),
       after the two 128-bit copies;
     - the first call passes two arguments (0x10F5 and 1), so func_0037B440 takes
       (id, handler).

   The attempt below (the source of the draft) gets the calls, the copies, the
   `por`/`sq` clear and the tail right, but the compiler needs one saved register
   more than retail and materialises the two address expressions too early:

     00422540  addiu $sp, $sp, -0xB0   | addiu $sp, $sp, -0xA0
     00422548  sd    $s5, 0x88($sp)     | sd    $s1, 0x68($sp)
     0042254C  daddu $s5, $a0, $zero   | daddu $s1, $a0, $zero
     0042259C  addiu $s0, $s4, 0xD0    | daddu $s0, $v0, $zero
     004225A0  daddu $s1, $v0, $zero   | addiu $s3, $sp, 0x10
     004225A4  addiu $s2, $sp, 0x20    | daddu $a0, $s1, $zero
     004225A8  addiu $a2, $sp, 0x10    | daddu $a1, $s0, $zero
     004225B4  addiu $s3, $s4, 0xC0    | jal   func_329960
     004225B8  daddu $a0, $s5, $zero   | daddu $a2, $s3, $zero

   check.py (05_feltzin_system), with the source below:
     05_feltzin_system: instruction at +0x0 differs
     func_L05_00422540: 0 of 1 places match

   Measured and right:
   - the file needs `-frac2-zero-ti-por` (config/cflags.txt) for the clear: without it
     this cc1 prints `sq $zero,0($sp)` where retail has `por $v0,$zero,$zero` +
     `sq $v0,0($sp)`; with it the pair comes out exactly and the compiled body is
     the retail's 252 bytes (248 without the switch, tested).
   - the 96-byte local area needs one `mode(TI)` array whose address is taken
     (a `TI128 v[6]`): three separate locals give vars=48 and a 0x70 frame, and an
     unused `TI128 pad[3]` is optimised away, so the frame stays short.
   - the 128-bit temporaries must be reached through a pointer variable: with
     `&v[1]` written inline the compiler rematerialises `sp+0x10`/`sp+0x20` and
     retail keeps them in $s3/$s2 (the `lq`/`sq` copies read through the register).
   - the two calls that take the temporaries need three arguments; func_0037B440
     takes two, the second one 1: retail materialises `$a1 = 1` at the top of the
     function, before the register saves.

   Tried and not enough: the temporaries as separate locals; `TI128 v[6]` with the
   elements used directly; the temporaries as `u8 *` pointer variables assigned before
   the calls; `p + 0xD0` / `p + 0xC0` written inline three times (this cc1 CSEs them
   and hoists both into the first block, which costs the register that $s3/$s2 need);
   the same two addresses as local variables assigned just before the last three
   calls (the compiler hoists the assignment the same way).

   What is left to try: the source shape that keeps both address expressions late
   (so $s3 and $s2 can hold the two temporary addresses and only five registers are
   saved) while the compiler still copies the temporaries through a register; every
   spelling tried so far hoists the CSEd address, which is the one register too many.
   This is a register-allocation difference, not a call or data difference.

   Drafted against src/levels/05_feltzin_system/L05_00420360.c, -O2 -G0
   -ffunction-sections -frac2-zero-ti-por. */

typedef int TI128 __attribute__((mode(TI)));
typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

extern u8 *func_0037B440(s32 a0, s32 a1);
extern s32 func_00332AF8(s32 a0, s32 a1);
extern void func_00329960(u8 *a0, u8 *a1, u8 *a2);
extern void func_003298C0(u8 *a0, u8 *a1, u8 *a2);
extern void func_00306748(u8 *a0, u8 *a1, u8 *a2);
extern void func_003068F8(u8 *a0, u8 *a1, f32 f12);
extern void func_0037D210(u8 *a0);

void func_L05_00422540(u8 *arg0) {
    TI128 v[6];
    u8 *pw;
    u8 *px;
    u8 *p;
    s32 t;

    p = func_0037B440(0x10F5, 1);
    *(TI128 *)&v[0] = 0;
    ((f32 *)&v[0])[2] = 1.0f;
    if (p == 0)
        return;
    t = func_00332AF8(0, 4);
    pw = (u8 *)&v[1];
    px = (u8 *)&v[2];
    func_00329960(arg0, t, pw);
    func_003298C0(arg0, t, px);
    *(TI128 *)(p + 0x10) = *(TI128 *)pw;
    *(TI128 *)(p + 0xC0) = *(TI128 *)px;
    func_00306748(p + 0xD0, p + 0xC0, (u8 *)&v[0]);
    func_003068F8(p + 0xD0, p + 0xD0, 1.0f);
    func_00306748(p + 0xE0, p + 0xD0, p + 0xC0);
    func_0037D210(p);
}
