/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: SDK EE-GCC 2.9-ee-991111-01.
 * Profile: sdk -O2 -G2 -ffunction-sections.
 * Reported final C / retail: 144 / 144 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: not run: US candidate failed.
 * pal: not run: US candidate failed.
 * Residual: Retained explicit exponent/mantissa scalar C. Same-size 144 bytes; entry argument copy, allocator and branch-likely differ.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* from src/core/0011BF18.c: a 144-byte 64-bit integer/double helper. It takes the value
   in $a0 (copied to $a1), takes the exponent field with `dsll $v0,$a1,1; dsrl32 $a2,$v0,21`,
   subtracts 0x433, returns 0 below -53 and 9999 at or above 13 - a saturating fixed-point
   conversion. Below the range it rebuilds the mantissa (clearing the top 12 bits, setting
   bit 52) and shifts, with a round-to-nearest step through `bnel` and `movn`. No C attempt:
   the first instruction is a copy of the argument register that no plain-C body produces,
   which suggests the original was built from a 32-bit-argument prototype this catalogue row
   does not record; that is where a next attempt should start.
 *
 * Wave 24 (worker 07): the conversion is not the wall, the toolchain is.
 * `(int)double` compiles under the SDK profile (`sdk -O2 -G2
 * -ffunction-sections`, the unit's own line) and under the game compiler
 * to a call of the libgcc helper `dptoli` (a frame, a `jal dptoli`, the
 * return) - 20 bytes, not the retail's 144.  The retail's body is the
 * old gcc's inline `fixdfsi` expansion (the exponent out of the high
 * word, the 0x433 bias, the -53 and 13 limits, the 9999 saturation), and
 * no spelling of the cast reaches it: the inline expansion is what this
 * compiler does not do.  The body would need the compiler to expand the
 * conversion, not a different C.
 */

/* Expanded screening: sdk -O2 -G2 -ffunction-sections.
 * Five forms, including a double union view: best scalar body was 144/144 bytes, but entry argument-copy/register allocation and branch-likely selection differ. No cast-only compiler-expansion assumption is required; explicit exponent/mantissa C is retained. Reopen with a grounded allocator/ABI hypothesis.
 * tools/check.py func_0011C000 --diff --version us: 0 of 1 places; exit 1.
 */
int func_0011C000(unsigned long bits) {
    long exponent;
    unsigned long mantissa;
    unsigned long shifted;
    exponent = (long)((bits << 1) >> 53) - 0x433;
    if (exponent < -53) return 0;
    if (exponent >= 13) return 9999;
    mantissa = ((bits << 12) >> 12) | 0x10000000000000UL;
    if (exponent < 0) {
        shifted = mantissa >> (int)(-exponent - 2);
        if ((shifted & 3) == 3) mantissa = (shifted >> 2) + 1;
        else mantissa = shifted >> 2;
    } else {
        mantissa <<= (int)exponent;
    }
    return (int)mantissa;
}
