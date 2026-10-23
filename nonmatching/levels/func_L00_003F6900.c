/* from src/levels/shared/L00_003EE100.c: not written this wave.
 *
 * func_L00_003F6900 (340 bytes, 27 places), retail's shape:
 *   - the grouped lq/sq copy: `lq $v0,0($s2) ; sq $v0,0($s1)`, the sixteen-byte block of
 *     the second argument copied into the record at s1+0x10. It is reachable in plain
 *     C with `typedef int TI128 __attribute__((mode(TI)));` and the opt-in profile
 *     -frac2-qcopy -frac2-qcopy-barrier (as in the matched func_L00_003F34D8 and
 *     func_L00_003EFA00);
 *   - the rest is a chain of float calls: func_00283CE0 (0x3C8EFA36 as the scale),
 *     func_002A7878 eight times with the constants read through $gp at +0x19D4, +0x19D8,
 *     +0x19DC, +0x19E0, +0x19E4, +0x19E8, +0x19EC, +0x19F0, +0x1A04, +0x1A08, +0x1A0C and
 *     +0x1A10, each result stored in the record, and the countdown `slti $v0,$a0,0x78`.
 */
