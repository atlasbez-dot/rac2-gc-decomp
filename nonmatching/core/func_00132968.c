/* from src/core/00131780.c: the retail prologue this compiler does not write */
/*
 * Command 0xD with two ints: func_00132DF0(0xD, 8, payload, 0, 0).
 *
 * The body is the retail's, instruction for instruction: the two stores into
 * the payload, the five arguments of the call and the frame (0x20, with $ra
 * at 0x10) all come out as they are in the retail, and the candidate is 52
 * bytes against the retail's 68.
 *
 * What is missing is the retail's prologue:
 *
 *     addiu $sp,$sp,0x10 ; nop ; addiu $sp,$sp,0x10 ; nop
 *
 * two positive stack adjustments the epilogue never gives back (the frame is
 * 0x20 and the epilogue restores 0x20), so the function leaves the stack 0x20
 * bytes higher than its caller. The same pair opens 77 other boot functions,
 * and every one of the 78 is a function nothing in the program calls: no jal
 * in the boot targets any of them, none of the 2,137 called boot functions
 * opens with the pair, and none of the 78 addresses appears anywhere in the
 * boot's data either, so they are dead code. The amounts are multiples of 16
 * and uncorrelated with the body.
 *
 * What would unblock it: the compiler that built the retail wrote that
 * prologue for the functions nothing calls; neither compiler in this tree
 * (SDK 2.9-ee-991111-01, game 2.9-ee-991111b) writes it for any C, under any
 * flag combination tried (-O0/-O1/-O2/-O3, -G0/-G2/-G8, -mastra-quad-saves,
 * -mno-split-addresses, -mastra-split-trunc-slot).
 */
extern void func_00132DF0(int, int, int, long, int);

void func_00132968(int first, int second) {
    int payload[4];
    payload[0] = first;
    payload[1] = second;
    func_00132DF0(0xD, 8, (int)payload, 0, 0);
}
