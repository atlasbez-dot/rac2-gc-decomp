/* from src/core/00131780-g8.c: the catalogue row is 24 bytes too long.
 *
 * func_00132A58's row (0x00132A58, 72 bytes) opens with three
 *
 *     addiu $sp,$sp,0x10 ; nop
 *
 * pairs that belong to no function: the linker remnant rac1-decomp splits
 * off as core_text/func_0012E490, right before its cmd-0x15 wrapper
 * func_0012E4A8 (rac1-decomp src/core/989snd.c), which is the function this
 * row is. The remnant is dead-stripped code, not part of the function, and
 * no C emits a stack-pointer increase at function entry, so the row as it
 * stands cannot be matched from C. A tools/levels.py split (the row starts
 * at 0x00132A70, 48 bytes) unblocks it.
 *
 * The function itself is exact below: the 48 bytes at 0x00132A70 are
 * reproduced word for word - the same shape as the matched cmd-0x16 wrapper
 * func_00132AF8 next door, with the command id 0x15.
 *
 * Unit: the -g8 sibling (the game compiler at -O2 -G8 -ffunction-sections),
 * which is the unit the 989snd object was built in. This wrapper has no
 * globals, so the SDK compiler's unit reproduces the same 48 bytes, but the
 * object it belongs to is the game's.
 *
 * Verified: compiled with the unit's own flags and compared with retail at
 * 0x00132A70, 48 bytes: 0 of 12 words differ.
 */

extern void func_00132DF0(int, int, int, long, int);

void func_00132A58(int value) {
    int payload[4];
    payload[0] = value;
    func_00132DF0(0x15, 4, (int)payload, 0, 0);
}
