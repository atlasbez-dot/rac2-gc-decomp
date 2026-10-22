/* Near miss (292 bytes, level 16): the branch polarity, the register allocation
   and the two 128-bit copies differ; the calls and their order match.

   Retail: the long path falls through, the short path is the branch target
   (beql $v0, $zero), the handle is $s1 and its instance data $s0, and the two
   `mode(TI)` copies materialise the source address in a register (addiu
   $v1, $v1, 0x30) before the lq.  This cc1 tests the condition the other way
   round, keeps the handle in $s2 and the instance data in $s1, holds the
   level's table pointer in a fourth saved register, and folds the 0x30 and
   0x70 displacements into the lq instead of into the address - the same
   limitation the other level units record.

   The calls, their arguments and their order are right: func_L02_00327350 and
   func_L01_00323310 around the copies, the flag byte at 0x0013963B, then
   func_L16_004117A8, func_L16_00411F80, func_L00_003294F0, func_002DF3F8,
   func_L16_00412C58, func_0029B3E0 and func_002A7750.  Tried: the copies with
   the address in a variable (this cc1 still folds the displacement into the
   lq), the branch the other way round, and the two blocks in both orders.

   Kept as a starting point.  Removed from src/ on 2026-10-21. */

typedef int TI128 __attribute__((mode(TI)));

extern void func_L02_00327350(s32, s32);
extern void func_L01_00323310(s32, s32);
extern void func_L00_003294F0(void *, s32);
extern void func_002DF3F8(void *, void *);
extern void func_L16_00412C58(void *, s32, s32);
extern void func_L16_00411F80(u8 *, s32);
extern void func_L16_004117A8(u8 *);
extern void func_0029B3E0(s32, s32);
extern void func_002A7750(void *, s32, s32);

extern s32 D_L16_001B2C0C;
extern s32 D_L16_001B2B1C;
extern u8 D_0013963B;

void func_L16_00412D48(u8 *arg)
{
    u8 *s0;
    u8 *s1;
    TI128 *p;
    TI128 *q;
    s32 a0;
    s32 v0;

    s1 = arg;
    s0 = *(u8 **)(arg + 0x68);
    if (*(s32 *)(s0 + 0x1BC) != 0) {
        func_L02_00327350(*(s32 *)(s0 + 0x1B0), *(s32 *)(s0 + 0x1B4));
        *(s32 *)(s0 + 0x1BC) = 0;
        a0 = *(s32 *)(s0 + 0x1B8) << 7;
        p = (TI128 *)(D_L16_001B2C0C + a0 + 0x30);
        *(TI128 *)(arg + 0x10) = *p;
        q = (TI128 *)(D_L16_001B2C0C + a0 + 0x70);
        *(TI128 *)(arg + 0xF0) = *q;
        func_L01_00323310(*(s32 *)(s0 + 0x1A4), -1);
        v0 = 0;
    } else {
        func_L01_00323310(*(s32 *)(s0 + 0x1A4), *(s32 *)(s0 + 0x1AC));
        v0 = 1;
    }
    D_0013963B = v0;
    func_L16_004117A8(arg);
    func_L16_00411F80(arg, 1);
    func_L00_003294F0(D_L16_001B2B1C + (*(s32 *)(s0 + 0x190) << 8), 1);
    func_002DF3F8(D_L16_001B2C0C + (*(s32 *)(s0 + 0x198) << 7) + 0x30,
                  D_L16_001B2C0C + (*(s32 *)(s0 + 0x198) << 7) + 0x70);
    func_L16_00412C58(arg, 0, 2);
    func_0029B3E0(0, -1);
    func_002A7750(arg, 2, 1);
}
