/* func_L09_00403100 (212 bytes, 1 place: level 09_dobbo) - best attempt, NOT MATCHED.
 *
 * tools/check.py func_L09_00403100 --diff:
 *   09_dobbo: 208 bytes, expected 212
 *   func_L09_00403100: 0 of 1 places match (src/levels/09_dobbo/L09_003FEA48.c)
 *
 * The body is recovered: 49 of the 53 instructions are byte-identical, and everything
 * outside the loop's register allocation matches exactly - the prologue, the two calls
 * (func_L09_00403080 and func_002A8508), the guards, the table lookup at 0x1FB560 and
 * the epilogue.
 *
 * Retail (the loop, level 09):
 *
 *   loop: lhu $v0,0($a0) ; daddu $a1,$v0,$zero ; andi $v0,$v0,0x7FFF ; sll $v0,$v0,8
 *         ; addu $v0,$a2,$v0 ; lh $v1,0xAA($v0) ; bnel $v1,$t0,end ; sll $v0,$a1,16
 *         ; lw $v1,0x68($v0) ; lh $v0,0x26A($v1) ; bnez $v0,cont ; sll $v0,$a1,16
 *         ; b end ; sh $a3,0x26A($v1)
 *   cont: bgez $v0,loop ; addiu $a0,$a0,0x2
 *
 * Here (the same loop, 4 bytes shorter):
 *
 *   loop: lhu $a1,0($a0) ; andi $v0,$a1,0x7FFF ; sll $v0,$v0,8 ; addu $v0,$a2,$v0
 *         ; lh $v1,0xAA($v0) ; bne $v1,$t0,end ; sll $a1,$a1,16 ; lw $v1,0x68($a1)
 *         ; lh $v0,0x26A($v1) ; bnez $v0,cont ; nop ; b end ; sh $a3,0x26A($v1)
 *   cont: bgez $a1,loop ; addiu $a0,$a0,0x2
 *
 * What is left is the allocation of the 16-bit index in the loop.  Retail keeps the
 * index in $a1 (a copy of the loaded halfword) and computes "index << 16" into $v0,
 * twice: once for the address (in the delay slot of the `bnel`, which annuls it) and
 * once for the loop test (in the delay slot of the `bnez`), because the flag load
 * `lh $v0,0x26A($v1)` overwrites the first result.  This cc1 instead shifts in place
 * ($a1), so the index dies with the shift and the loop test reuses the shifted value:
 * one shift instead of two, a plain `bne` where retail has the `bnel`, and a `nop`
 * where retail has the second shift.
 *
 * The wall is this cc1's common-subexpression pass: the address's shift and the loop
 * test's shift are the same expression, so they are merged into one computation, which
 * then dies with the index and the shift can be done in place.  Retail's two shifts
 * mean the two uses were not merged there.
 *
 * Measured, no effect (all 208 bytes, the same four words):
 *   - the index as u16, as s32 and as int;
 *   - the loop test as (s16)index >= 0, as (s32)(index << 16) >= 0 and as
 *     (s32)((u32)index << 16) >= 0;
 *   - the address as ((u32)index << 16) + 0x68, as (index * 0x10000) + 0x68 and with
 *     the multiply spelled out;
 *   - the index copied into a second variable (u16, u32, u64) and the copy used by the
 *     address or by the test - copy propagation removes the copy again;
 *   - the address computed before the record (the shift then moves in front of the
 *     kind test) and after it (retail's order);
 *   - the address in a variable of its own (this cc1 then keeps the sub-object
 *     pointer in a saved register, $s2, where retail has it in $v1).
 *
 * The address expression is ((u32)index << 16) + 0x68: with a 64-bit shift this cc1
 * adds the sign extension of the 32-bit result (dsll32/dsra32) that retail does not
 * have, and it does not fold the +0x68 into the load.  The record's address is
 * D_L09_001B285C + ((index & 0x7FFF) << 8), the same shape as the matched
 * func_L09_00403080 in the same file, and the table at 0x1FB560 is D_L09_001FB560.
 *
 * Two things the next worker should know:
 *   - the table at 0x1FB560 is D_L09_001FB560 (as in L09_002B7238.c and
 *     L09_002F8BA0.c).  The name in L09_003FEA48.c is D_L09_001FFFB560 - nine digits,
 *     so the build does not check its value - and it stands for the same address.
 *   - the caller is func_L09_00403270 (matched, in L09_003FEA48-g8.c), which passes
 *     the result of func_002B0ED8 as the second argument: the retail's guard
 *     `addiu $v0,$s0,-0x4 ; sltiu $v0,$v0,0x2` accepts 4 and 5 only, so the second
 *     parameter is that result and the signature (char *, s32) is right.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed int s32;

extern void func_L09_00403080(char *a0);
extern s32 func_002A8508(s32 a0, s32 a1);
extern char *D_L09_001FB560[];
extern char *D_L09_001B285C;

void func_L09_00403100(char *a0, s32 a1) {
    char *s1 = a0;
    char *base;
    char *p;
    u16 v;
    char *rec;
    char *sub;

    if (a1 == 0) {
        return;
    }
    func_L09_00403080(a0);
    if ((u32)(a1 - 4) >= 2) {
        return;
    }
    if (*(u8 *)(s1 + 0x21) == 0xFF) {
        return;
    }
    if (func_002A8508(*(u8 *)(s1 + 0x21), -1) < 2) {
        return;
    }
    base = D_L09_001B285C;
    p = D_L09_001FB560[*(u8 *)(s1 + 0x21)];
    do {
        v = *(u16 *)p;
        rec = base + ((v & 0x7FFF) << 8);
        if (*(s16 *)(rec + 0xAA) != 0xD57) {
            break;
        }
        sub = *(char **)(((u32)v << 16) + 0x68);
        if (*(s16 *)(sub + 0x26A) == 0) {
            *(s16 *)(sub + 0x26A) = 1;
            break;
        }
        p += 2;
    } while ((s16)v >= 0);
}
