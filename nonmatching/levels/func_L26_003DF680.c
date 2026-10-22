/* func_L26_003DF680 (356 bytes, 1 placement, level 26 jamming array): NEAR MISS.
   This plain C compiles to 356 bytes in the same frame as retail (0x40, five saved
   GPRs and two saved FP registers) and matches retail word for word from the prologue
   to +0x80; the rest differs in the loop's induction variables and in one register.

   Measured with the project compiler (-O2 -G8 -ffunction-sections, the unit is the
   -g8 sibling because the frame time is read through $gp), the body was recovered:
   kind 0 clears the record and switches it to kind 1 (the byte at +0x30 becomes 0xFF,
   func_002A7750(moby,1,-1) runs, the record's first word becomes 0 and the word at +4
   becomes 0.5f); kind 1 advances two wrapped counters by a sixtieth of the frame time
   and then runs func_L00_002E6CF0 with the address of the record's own update.
   Spellings that matter and were measured:
     - the constants are 0.5f (0x3F00), 0.333f (0x3EAA7EFA) and 0.666f (0x3F2A7EFA),
       not 1/3 and 2/3, and the frame time is multiplied by 0.016666667f (0x3C888889);
     - the two counters are two float arrays: the first at the record's own address,
       the second eight bytes further, and the second array is indexed by (i+1)&1;
     - the call to func_002A7878 feeds the second half of the first block: its result
       is what the second block adds to the other counter (this is what keeps the
       working value in $f0 across the call, as retail does, instead of a saved FP
       register);
     - the two array bases have to be separate variables inside the case-1 block, or
       cc1 keeps one of them in a caller-saved register and the frame grows;
     - the frame time is read through $gp, so the unit must be built with -G8.

   What is left (the body is otherwise identical):
     - the loop's induction variables. Retail keeps the loop counter in a caller-saved
       temporary ($v1) and derives the two induction values from it: `sll $s0,$v1,2` for
       the index and `addiu $s1,$v1,0x1` for the next index, the counter's next value
       being `daddu $v1,$s1,$zero`. This cc1 keeps the counter itself in a saved
       register ($s0) and recomputes the next index in a temporary. Spellings measured:
       `for (i = 0; i < 2; i++)` with the index used directly, with an explicit
       `int j = i + 1`, with the counter declared before the pointers, and with the
       pointer variables moved into the loop body. The last one is the shape kept here:
       it reproduces retail's block order and frame exactly, but cc1's induction
       variable expansion still splits the counter differently.
     - the destination of the first add: retail reuses the register of the loaded
       counter (`add.s $f0,$f0,$f1`), this cc1 reuses the register of the scaled frame
       time (`add.s $f1,$f0,$f1`), and it then copies the call's result with
       `mov.s $f1,$f0`. The two follow from the induction variables above.

   The declarations below are the ones the body needs; the file it came from is
   src/levels/26_jamming_array/L26_002EC840-g8.c. */

typedef unsigned char u8;

extern void func_002A7750(unsigned char *, int, int);
extern float func_002A7878(float, float);
extern void func_L00_002E6CF0(void *, void *);
extern void func_L26_003DF7E8(void);

extern int D_L26_001A8FF0;
extern float D_L26_001B0660 __attribute__((sda));

void func_L26_003DF680(char *a0) {
    char *s3 = a0;
    char *s4 = *(char **)(s3 + 0x68);
    int i;

    switch (*(u8 *)(s3 + 0x20)) {
    case 0:
        *(u8 *)(s3 + 0x30) = 0xFF;
        func_002A7750((unsigned char *)s3, 1, -1);
        *(int *)s4 = 0;
        *(float *)(s4 + 4) = 0.5f;
        break;
    case 1:
        if (D_L26_001A8FF0 != 0) {
            for (i = 0; i < 2; i++) {
                float *g = (float *)((char *)s4 + 8);
                float *f = (float *)s4;
                float v;

                v = f[i] + D_L26_001B0660 * 0.016666667f;
                if (1.0f < v) {
                    f[i] = v;
                    v = v - 1.0f;
                    f[i] = v;
                    v = func_002A7878(0.333f, 0.666f);
                }
                v = g[(i + 1) & 1] + v;
                if (1.0f < v) {
                    g[i] = v;
                    v = v - 1.0f;
                    g[i] = v;
                }
            }
            func_L00_002E6CF0((void *)func_L26_003DF7E8, s3);
        }
        break;
    }
}
