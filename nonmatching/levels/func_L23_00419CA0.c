/* func_L23_00419CA0 (64 bytes, 1 place, -g8 unit: $gp + absolute $1B38C0)
   -- measured 0 of 1; best candidate differs in TWO WORDS.
   (Measurement from wave 9 worker 16, kept here; not re-measured in wave 6.)

   Registers follow the DECLARATION ORDER of the locals:
     `int *p = &D_L23_001B1658; int i = 0;`  -> i = $v1, p = $a1   (retail)
     `int i = 0; int *p = &D_L23_001B1658;`  -> i = $a1, p = $v1   (wrong)
   A `for` loop adds a pre-test (double blez, 72 bytes): stay in do/while.

   Two measured forms, each two words from retail:
     (A) `int n = D_L23_001B38C0;` + `while (i < n)`  -> 64 bytes, but the global is
         loaded straight into $a2 (retail loads into $v0 then COPIES: `daddu $a2,$v0,$zero`)
         and the blez delay slot is a nop instead of the copy.
     (B) `while (i < D_L23_001B38C0)` (the global re-read in the condition) -> the copy
         appears (CSE keeps the node in $v0, the loop invariant goes to $a2), but the
         init order becomes [a2=n, a1=&tab, v1=0] where retail has [v1=0, a2=n, a1=&tab]
         (the counter's init belongs in the blez delay slot).
   The untried lead: get BOTH -- a source that reads the global twice (for the copy) while
   the counter's init is emitted first (e.g. `int i;` declared after the pointer and
   `i = 0;` as the first statement of the body).
*/

extern int D_L23_001B38C0;
extern int D_L23_001B1658 __attribute__((sda));

int func_L23_00419CA0(int arg0) {
    int n = D_L23_001B38C0;

    if (n > 0) {
        int *p = &D_L23_001B1658;
        int i = 0;

        do {
            if (*p == arg0)
                return 0;
            i++;
            p++;
        } while (i < D_L23_001B38C0);
    }
    return 1;
}
