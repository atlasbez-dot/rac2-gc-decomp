/* func_L22_003A3B50 (284 bytes, 2 places: 22:003A3B50, 23:003A8188), -G8 profile.
   Wave 2 worker 7: 216 bytes, sixty-eight short, and the shape of the switch and of the
   row walk is not recovered.

   It reaches its global through $gp (`lw $v0,0x324($gp)`, the small-data word
   D_L22_001AF314), so it only reproduces in a -G8 unit: it belongs in
   src/levels/shared/L22_0039D708-g8.c, next to func_L22_003A48F8, which reads the same
   word. The draft below was measured in that unit.

   What the retail bytes say, in order:

   - D_0018C0B0 (the hero) and D_L22_001AF314 are read, and the byte at +0x43 of each
     is compared with 6 and with 4. The two tests leave one value behind: a dead
     `addiu $a1,$zero,0x3` in the first branch's delay slot and the 4 the second
     test compares with. The call that follows is func_002A77E0 with 2 in both
     argument registers, so the "3" never reaches it.
   - the return value of that call is turned into a row of D_L22_0023B530: 1 for a
     return of 0, 2 for a return of 1, 0 for anything else. The retail's chain of
     tests (a `beq` against 1, a `slti` against 2, a `beqz`, a `beq` against 2) and
     the two dead stores in it (a `s0 = 1` in the return-of-1 path, a `s0 = 2` in its
     delay slot) are what the draft does not reproduce.
   - the row is walked from its first word: the loop counts to 0x32, stops at a zero
     word and stops at D_L22_001AF314. The bound shows as `slti $v0,$a1,0x32` with a
     dead `addiu $a0,$zero,0x31` in the delay slot, which is the front end's
     `i < 0x32` written as `i <= 0x31`.
   - the row's index and the call's first argument are handed to func_L22_003A39C8
     with D_L22_001AF314 and the first parameter.

   The draft has the calls, the row and the final call, but not the shape of the
   switch: it comes to 216 bytes against retail's 284.

   Measured with tools/check.py func_L22_003A3B50 in the -G8 unit: 216 bytes
   against retail's 284, "instruction at +0x0 differs" (the frame size), then the
   differences above. */

extern int D_L22_001AF314 __attribute__((sda));
extern char *D_0018C0B0;
extern int D_L22_0023B530[3][60];
extern int func_002A77E0(int, int);
extern void func_L22_003A39C8(void *, char *, int, int);

void func_L22_003A3B50(char *a0, int a1) {
    int n = 3;
    int m = 4;
    int v;
    int mode = 0;
    int i;
    int *row;
    char *g = (char *)D_L22_001AF314;
    char *mob = D_0018C0B0;

    if (mob[0x43] == 6) {
        n = 2;
    } else {
        if (g[0x43] == 4) {
            m = 2;
        }
        n = 2;
    }
    v = func_002A77E0(n, n);
    switch (v) {
    case 0:
        mode = 1;
        break;
    case 1:
        mode = 2;
        break;
    case 2:
        mode = 0;
        break;
    }
    row = D_L22_0023B530[mode];
    if (*row != 0) {
        i = 0;
        do {
            i++;
            if (i >= 0x32) break;
            row++;
            if (*row == 0) break;
        } while (i != D_L22_001AF314);
    }
    func_L22_003A39C8(D_L22_001AF314, a0, mode, a1);
}
