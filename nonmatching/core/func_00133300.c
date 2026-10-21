/* from src/core/00131780-g8.c: the catalogue row is 16 bytes too long.
 *
 * func_00133300's row (0x00133300, 60 bytes) opens with two
 *
 *     addiu $sp,$sp,0x20 ; nop
 *
 * pairs that belong to no function: a linker remnant of the 989snd unit, the
 * kind rac1-decomp splits off as core_text/func_0012ED40 next to its cmd-0x34
 * wrapper func_0012ED10 (rac1-decomp src/core/989snd.c), which is the
 * function this row is. The remnant is dead-stripped code, not part of the
 * function, and no C emits a stack-pointer increase at function entry, so the
 * row as it stands cannot be matched from C. A tools/levels.py split (the row
 * starts at 0x00133310, 44 bytes) unblocks it.
 *
 * The function itself is exact below: the 44 bytes at 0x00133310 are
 * reproduced word for word - the same shape as the cmd-0x18 wrapper
 * func_00132AA0 next door, with the command id 0x34.
 *
 * Unit: the -g8 sibling (the game compiler at -O2 -G8 -ffunction-sections).
 * The SDK compiler makes this a sibling call (24 bytes), which is not what
 * retail has.
 *
 * Verified: compiled with the unit's own flags and compared with retail at
 * 0x00133310, 44 bytes: 0 of 11 words differ.
 */

extern void func_00132DF0(int, int, int, long, int);

void func_00133300(void) {
    func_00132DF0(0x34, 0, 0, 0, 0);
}
