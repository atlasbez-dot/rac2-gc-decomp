/* from src/levels/shared/L22_0039D708-g8.c: a near miss, 400 bytes against retail's 388.
 * Needs the -G8 unit (the $gp-relative float constants) to be checked again, and the
 * level's own jump table must be named the way splat names it, so that the build can
 * resolve the name from the retail's lui %hi / addiu %lo pair.
 *
 * tools/check.py func_L22_003A39C8 --diff:
 *   22_dobbo_orbit: 400 bytes, expected 388
 *   23_damosel_orbit: 400 bytes, expected 388
 *   func_L22_003A39C8: 0 of 2 places match (src/levels/shared/L22_0039D708-g8.c)
 *
 * What is left, from the diff:
 *  - retail keeps the row's %hi in $s2 and adds the %lo to it (daddu $s2,$v0,$zero then
 *    addiu $v1,$s2,-0x4AD0): the split 64-bit "la" that docs/COMPILER-NOTES.md records
 *    as unreproduced;
 *  - retail spills the 64-bit argument to the stack in the prologue (lq $v0,0($a1) ;
 *    sq $v0,0($sp)) and keeps the row base, the index and the slot index in $s0/$s1/$s2;
 *    C spills later and saves six callee-saved registers (frame 0x40, retail's is 0x30);
 *  - retail's scan walks the row with a pointer and counts in $s0 (bne $s0,$a0 with
 *    $a0 = 0x31), C counts in a separate variable and if-converts the "-1" case;
 *  - the case bodies are the level's own table at 0x002A6A10, reached by a computed
 *    goto; a C switch cannot be used, its table lands in the object's .rdata, which
 *    tools/build.py discards.
 */
extern void *jtbl_002A6A10[5];
extern void func_003FB1F8(void *, float);
extern void func_003FC780(void *, float);
extern void func_003FD1E8(void *, float);
extern float D_L22_001AF3A0 __attribute__((sda));
extern float D_L22_001AF3A4 __attribute__((sda));
extern float D_L22_001AF3AC __attribute__((sda));
extern int D_L22_001F530[];
extern int D_L22_001B2AB8[];
extern int D_L22_001B2AC4;

/* Finds the free slot of one row of the orbit's table, runs the row's own handler
 * and hands the new value to the slot's owner. */
int func_L22_003A39C8(void *a0, long long *a1, int a2, int a3) {
    /* The level's own table at 0x002A6A10 holds the addresses of the four bodies;
     * these keep them alive for the computed goto. */
    static void *volatile jtbl_003A39C8[5] = { &&L0, &&L1, &&L2, &&L3, &&L2 };
    void *t1 = a0;
    int s1 = a2;
    long long saved = *a1;
    int *p;
    int s0 = 0;
    int v0;

    p = (int *)((char *)D_L22_001F530 + s1 * 240);
    if (*p != 0) {
        for (s0 = 1; s0 < 50; s0++) {
            p++;
            if (*p == 0) {
                goto Lfree;
            }
        }
        s0 = -1;
    Lfree:
        ;
    }
    if (s0 == -1) {
        return s0;
    }
    if (s1 < 5) {
        goto *jtbl_002A6A10[s1];
    L0:
        func_003FB1F8(t1, D_L22_001AF3A0);
        goto Lstore;
    L1:
        func_003FC780(t1, D_L22_001AF3A4);
        goto Lstore;
    L3:
        func_003FC780(t1, D_L22_001AF3A4);
        goto Lstore;
    L2:
        func_003FD1E8(t1, D_L22_001AF3AC);
    Lstore:
        *(int *)((char *)D_L22_001F530 + s1 * 240 + s0 * 4) =
            (int)(void *)jtbl_002A6A10;
    }
    v0 = *(int *)((char *)D_L22_001F530 + s1 * 240 + s0 * 4);
    if (v0 == 0) {
        return s0;
    }
    D_L22_001B2AC4 = D_L22_001B2AC4 + 1;
    D_L22_001B2AB8[s1] = D_L22_001B2AB8[s1] + 1;
    *(long long *)(v0 + 0x10) = saved;
    return s0;
}
