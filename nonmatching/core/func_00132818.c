/* from src/core/00131780.c: the retail prologue this compiler does not write */
/*
 * Command 8 with no data: func_00132DF0(8, 0, 0, 0, 0).
 *
 * The body is the retail's, instruction for instruction, once the prologue is
 * set aside:
 *
 *     addiu $sp,$sp,-0x10 ; addiu $a0,$zero,0x8 ; sd $ra,0x0($sp)
 *     daddu $a1,$zero,$zero ; daddu $a2,$zero,$zero ; daddu $a3,$zero,$zero
 *     jal func_00132DF0 ; daddu $t0,$zero,$zero
 *     ld $ra,0x0($sp) ; jr $ra ; addiu $sp,$sp,0x10
 *
 * Retail opens it with four instructions this compiler does not write:
 *
 *     addiu $sp,$sp,0x20 ; nop ; addiu $sp,$sp,0x30 ; nop
 *
 * a positive stack adjustment that the epilogue never gives back (the frame
 * is 0x10 and the epilogue restores 0x10), so the function leaves the stack
 * 0x50 bytes higher than its caller. The same pair opens 77 other boot
 * functions, and every one of the 78 is a function nothing in the program
 * calls: no jal in the boot targets any of them, none of the 2,137 called
 * boot functions opens with the pair, and none of the 78 addresses appears
 * anywhere in the boot's data either, so they are dead code. The amounts are
 * multiples of 16 and uncorrelated with the body (func_00132AA0, the same
 * command with no data either, gets 0xF0 against this one's 0x50).
 *
 * With the SDK compiler (the unit's profile, `sdk -O2 -G2 -ffunction-sections`)
 * the call is also the last statement, so it becomes a sibling call and the
 * function is 24 bytes: `j func_00132DF0` with no frame. The game's compiler
 * (2.9-ee, sibling calls off) writes retail's body exactly, frame and all.
 *
 * What would unblock it: the compiler that built the retail wrote that
 * prologue for the functions nothing calls; neither compiler in this tree
 * (SDK 2.9-ee-991111-01, game 2.9-ee-991111b) writes it for any C, under any
 * flag combination tried (-O0/-O1/-O2/-O3, -G0/-G2/-G8, -mastra-quad-saves,
 * -mno-split-addresses, -mastra-split-trunc-slot).
 */
extern void func_00132DF0(int, int, int, long, int);

void func_00132818(void) {
    func_00132DF0(8, 0, 0, 0, 0);
}
