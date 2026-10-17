/* func_L23_0041B968 (136 bytes, 1 place, -g8 unit) -- measured 0 of 1, best candidate 120 bytes.
   (Measurement from wave 9 worker 16; the walk below is wave 6's reading of retail.)

   Retail picks the most negative live slot measure that is <= the level threshold
   D_L23_001B13CC and <= the running best (which starts at 0.0f), and stores its index
   in state+0x60C:
     lw  $v0,0x2494($gp) ; lw $a1,0x68($v0) ; lw $v1,0x60C($a1)
     beq $v1,-1 -> return                       (delay: a2 = -1, the index)
     mtc1 $zero,$f1 (0.0f) ; lwc1 $f2,D_L23_001B13CC
     loop i = 0..4 over the pointers at state+0x358:
       beql null -> next
       lwc1 $f0,0x20(*(p+0x68))
       c.olt.s $f2,$f0 ; bc1fl next      ; if (threshold < v) continue
       c.olt.s $f1,$f0 ; bc1fl next      ; if (best < v)   continue   <- REUSES $f1
       mov.s $f1,$f0 ; daddu $a2,$a0,$zero ; (i++)
     sw $a2,0x60C($a1)

   Note the second test reuses $f1 -- the same register the best is kept in -- so the
   source compares against the running best, not against a fresh 0.0f constant. The
   `i++` copies in the two branch delay slots are reorg duplications (likely branches),
   so a single shared `i++` in the source is expected.
   The 120-byte candidate loses a word: one `continue` disappears.
*/

typedef short s16;

extern char *D_L23_001B1484 __attribute__((sda));
extern float D_L23_001B13CC;

void func_L23_0041B968(void) {
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    float best = 0.0f;
    int index = -1;
    int i;

    if (*(int *)(state + 0x60C) == -1)
        return;
    for (i = 0; i < 5; i++) {
        char *p = *(char **)(state + 0x358 + i * 4);

        if (p == 0)
            continue;
        {
            float v = *(float *)(*(char **)(p + 0x68) + 0x20);

            if (D_L23_001B13CC < v)
                continue;
            if (best < v)
                continue;
            best = v;
        }
        index = i;
    }
    *(int *)(state + 0x60C) = index;
}
