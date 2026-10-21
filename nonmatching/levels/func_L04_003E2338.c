/* Near miss: the loop, the branch-likely form and the tail are right; the register
   allocation, the placement of the values[] store and the zero-extension of the byte
   index are not. Retail at 0x003E2338, level 04 (252 bytes, 1 place) walks the four
   slots of an object, counts how many of them are live and copies a 16-byte record
   out of the table it picked:

     void f(char *a0)
     {
         char *s4 = *(char **)(a0 + 0x68);
         int values[3];
         int cur = 0;
         int count = 0;
         char *p = s4 + 0x2F0;
         int neg = -1;

         func_00115484(values, 0, 12);            /* memset: func_00115484 is the SDK's */
         for (;;) {
             if (cur != *(unsigned char *)(s4 + 0x306)) {
                 if (*(int *)p != neg) {
                     count++;
                     if (count >= 4)
                         break;
                     values[count - 1] = cur;
                     func_00282A28();             /* the teq trap */
                 }
             }
             cur++;
             if (cur >= 4)
                 break;
             p += 4;
         }
         if (count != 0) {
             int idx = func_002A7820(0, count - 1);
             int pick = *(unsigned char *)&values[idx];

             *(unsigned char *)(s4 + 0x306) = pick;
             *(TI128 *)(s4 + 0x280) = *(TI128 *)((char *)(*(int *)(s4 + pick * 4 + 0x2F0) * 128
                                                        + D_L04_001B25CC) + 0x30);
         }
     }

   probes "as measured": the two compares of the loop are the branch-likely form with the
   increment in the delay slot (`beql $s0,$v0` + `addiu $s0,$s0,1`), which on this R5900
   annuls the slot when the branch is NOT taken - the same rule the matched
   src/core/001163E0.c (newlib's strstr) shows. The loop's condition sits at the bottom
   (`slti $v0,$s0,4` + `bnez` back), so the source is a `for (;;)` with the test inside,
   not a `while`. The values[] store is `values[count - 1] = cur`; the pointer it induces
   starts at values-1 (`addiu $s1,$sp,-4`), so the index is count-1 and not count. The
   16-byte copy at the end is a `mode(TI)` copy, which this cc1 emits as `lq`/`sq`
   (0x78430030 / 0x7E830280 in retail).

   Remaining gap: the candidate is 244 bytes, retail 252, and three things differ. The
   loop's two counters land in $s0/$s1 the other way round (retail: `cur` in $s0, the
   values[] pointer in $s1; ours: the pointer in $s0, `cur` in $s1), which moves every
   instruction of the loop. The store of `cur` into values[] sits in the `jal`'s delay
   slot here, retail puts it in the delay slot of a `b` before the call. The byte index
   is not zero-extended here (`andi $v1,$v0,0xFF` in retail), because the compiler
   knows the unsigned char is 0..255; a `volatile` read of the byte keeps the mask and
   puts it before the `sb` instead of after it. Tried and did not move it: the order of
   the declarations, an explicit pointer for the store, `cur` declared before the
   array, the byte read through a `char *`, and the index as `long long`. Register
   allocation, the wall already paid. */
