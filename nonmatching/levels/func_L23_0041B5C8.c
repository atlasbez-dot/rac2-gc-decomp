/* func_L23_0041B5C8 (156 bytes, 1 place, -g8 unit) -- measured 0 of 1, candidate 160 bytes.
   (Recipe kept from wave 9 worker 16; not re-measured in wave 6.)

   Same pair of problems as func_L23_0041B498.c, same family (spring):
     retail: lwc1 $f1,0x74 ; lwc1 $f0,0x588 ; add.s $f1,$f1,$f1 ; sub.s $f12,$f0,$f12
     here:   lwc1 $f0,0x74 ; lwc1 $f1,0x588 ; add.s $f0,$f0,$f0 ; sub.s $f12,$f1,$f12
   and retail `bc1f` + `addiu $v0,$zero,1` in the slot against this cc1's `bc1tl` +
   `ld $s0` (one word more). The store order is right (0x58C = 0 then 0x5D8 = 1 in the
   emission, i.e. source order [0x5D8, 0x58C]).
   Keys: 1/60 = 0.016666668f (0x3C888889), 0.40833336f (0x3ED11112).
*/

extern void func_002AA548(char *, char *, float, float, float, float);
extern float func_00282C48(float);

void func_L23_0041B5C8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);

    if (*(int *)(state + 0x5D8) != 0)
        return;
    func_002AA548(state + 0x588, state + 0x58C, *(float *)(state + 0x5D4),
                  0.016666668f, 0.016666668f, 0.40833336f);
    *(float *)(state + 0x74) = *(float *)(state + 0x74) + *(float *)(state + 0x74);
    if (!(func_00282C48(*(float *)(state + 0x588) - *(float *)(state + 0x5D4)) < 0.1f)) {
        *(int *)(state + 0x5D8) = 1;
        *(int *)(state + 0x58C) = 0;
    }
}
