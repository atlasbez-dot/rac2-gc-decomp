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
