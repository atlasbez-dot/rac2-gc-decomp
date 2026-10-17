/* func_L23_0041B498 (164 bytes, 1 place, -g8 unit) -- measured 0 of 1, candidate 168 bytes.
   (Recipe kept from wave 9 worker 16; not re-measured in wave 6.)

   Two words from retail: the temporary of the difference wants $f1 (retail
   `lwc1 $f1,0x5C8($s0)` / `sub.s $f12,$f1,$f12`) where this cc1 gives $f0, and the
   guard is `bc1f` + `addiu $v0,$zero,1` in the delay slot against this cc1's `bc1tl`
   + `ld $s0` (one word more, hence 168). The multiply order, the delay slots and the
   two stores (0x5CC then 0x5DC) are right.
   The `extern float func_00282C48(float);` prototype above is mandatory: without it
   the call is int(int) and the floats are promoted to double (24 bytes more).
   Keys: 0.00027777778f (0x3991A2B4), 0.016666668f (0x3C888889), 0.1f.
   The three globals are $gp (0x2410/0x2414/0x2418) and belong in the -g8 sibling.
*/

extern void func_002AA548(char *, char *, float, float, float, float);
extern float func_00282C48(float);
extern float D_L23_001B1400 __attribute__((sda));
extern float D_L23_001B1404 __attribute__((sda));
extern float D_L23_001B1408 __attribute__((sda));

void func_L23_0041B498(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (*(int *)(state + 0x5DC) != 0)
        return;
    func_002AA548(state + 0x5C8, state + 0x5CC, *(float *)(state + 0x5D0),
                  D_L23_001B1400 * 0.00027777778f, D_L23_001B1404 * 0.00027777778f,
                  D_L23_001B1408 * 0.016666668f);
    if (!(func_00282C48(*(float *)(state + 0x5C8) - *(float *)(state + 0x5D0)) < 0.1f)) {
        *(int *)(state + 0x5DC) = 1;
        *(int *)(state + 0x5CC) = 0;
    }
}
