/* from src/core/00131780.c: the retail prologue this compiler does not write */
/*
 * Command 0x11 with six ints; the last two arguments are passed through:
 * func_00132DF0(0x11, 0x18, payload, arg6, arg7).
 *
 * The body is the retail's, instruction for instruction: the six stores into
 * the payload, the five arguments of the call (the fourth and the fifth
 * sign-extended out of $t2 and $t3) and the frame (0x30, with $ra at 0x20)
 * all come out as they are in the retail, and the candidate is 72 bytes
 * against the retail's 104.
 *
 * What is missing is the retail's prologue:
 *
 *     addiu $sp,$sp,0x20 ; nop ; addiu $sp,$sp,0x20 ; nop
 *     addiu $sp,$sp,0x30 ; nop ; addiu $sp,$sp,0x30 ; nop
 *
 * four positive stack adjustments the epilogue never gives back (the frame is
 * 0x30 and the epilogue restores 0x30), so the function leaves the stack 0xA0
 * bytes higher than its caller. The same pairs open 77 other boot functions,
 * and every one of the 78 is a function nothing in the program calls: no jal
 * in the boot targets any of them, none of the 2,137 called boot functions
 * opens with them, and none of the 78 addresses appears anywhere in the
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

void func_001329F0(int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7) {
    int payload[8];
    payload[0] = a0;
    payload[1] = a1;
    payload[2] = a2;
    payload[3] = a3;
    payload[4] = a4;
    payload[5] = a5;
    func_00132DF0(0x11, 0x18, (int)payload, a6, a7);
}
