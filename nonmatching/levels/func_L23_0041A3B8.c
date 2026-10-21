/* func_L23_0041A3B8 (652 bytes, 1 place: 23:0041A3B8) -- EXACT, but only with a `do { ... } while (0)`
   around the kind-0xF effect, which the task rules ("no construct whose only purpose is to steer the
   compiler") keep out of src/. Installed temporarily as src/levels/23_damosel_orbit/L23_0041A3B8-g8.c
   with the config/cflags.txt line `-O2 -G8 -ffunction-sections -mno-split-addresses` and the marker
   in L23_00416388.c replaced by a "matched in" comment, tools/check.py printed
   "func_L23_0041A3B8: 1 of 1 places match"; everything was then taken out again.
   Why the flags: `-mno-split-addresses` keeps retail's adjacent `lui`/`addiu` address pairs of
   D_L23_001B3850/3870 (default split form: 656-660 bytes); the -g8 name gives the $gp loads of
   D_L23_001B3728/1454; the alias names of D_L23_001B3850 keep its three uses from sharing one register,
   which is retail's re-materialisation.
   Why the loop: the kind-0xF arm of retail has `lui/addiu $a0` (the address) before the two
   frame-address setups `addiu $a1,$sp,0x20` / `addiu $a2,$sp,0x30`. Written plainly, this
   scheduler orders it the other way (5 words) because the arm's second call, func_L00_0035F5A0, is in the
   same basic block: `-fsched-verbose-5` shows every insn that reads the frame ($sp) getting one more
   dependent (an edge to that next call) than the `la`, so the two setups win the tie. The loop notes of
   a one-pass `do { } while (0)` are scheduling barriers (the lever recorded in func_L23_0041C8C0 and
   func_00124818): the second call no longer sees those readers, and the order is retail's, with the
   layout, the cross-jump of the kind-0xF tail into the kind-0x10 tail and every register unchanged.
   Probes without a following call in the block, or with it behind a join, give the same order; a source
   `goto` that shares the kind-0xF tail (with the kind-0xC arm: one word off, the jump target; with the
   kind-0x10 arm: 12 words off in that arm's argument order) cannot reproduce retail's layout.
   For the lead: if non-empty `do { ... } while (0)` wrappers are accepted (src/ already has two used as
   this lever: func_L23_0041C8C0 in L23_00416388.c and the one in src/core/00124568.c), moving this body
   to the unit above is the whole job. */

extern float D_L23_001B3728 __attribute__((sda));

extern float D_L23_001B1454 __attribute__((sda));

extern int D_L23_001B3784;

extern char D_L23_001B3850[];

extern char D_L23_001B3850_b[] __asm__("D_L23_001B3850");

extern char D_L23_001B3850_c[] __asm__("D_L23_001B3850");

extern char D_L23_001B3870[];

extern void func_00282F20(char *, char *, float);

extern void func_00282CF0(char *, char *, char *);

extern void func_L23_00422540(char *, char *, float *);

extern void func_L23_004280D8(char *, char *, char *, int, float);

extern int func_L00_0035F5A0(int, int, int);

extern void func_0032C700(char *, int, int, int, int, int, int, int, float, float, int, int, int, int);

extern void func_L23_0041BF18(char *, float, float);

int func_L23_0041A3B8(char *arg0, char *arg1) {
    char *state = *(char **)(arg0 + 0x68);
    float tmp;
    float vec[4];
    int kind = *(unsigned char *)(arg0 + 0x20);

    if (kind != 0xF) {
        if (kind == 0x10 || kind == 0xC) {
            if (D_L23_001B3784 == 0)
                return 0;
        } else
            return 0;
    } else {
        if ((*(unsigned short *)(arg0 + 0x96) & 3) != 2)
            return 1;
        do {
            func_00282F20((char *)vec, D_L23_001B3870, *(short *)(state + 0x33A) * 0.016666668f);
            tmp = *(float *)(state + 0x300) * 1.5f;
            func_L23_00422540(D_L23_001B3850, (char *)vec, &tmp);
        } while (0);
        func_L00_0035F5A0(0x21, 0, 0);
        return 1;
    }
    if (!(D_L23_001B3728 >= D_L23_001B1454))
        return 1;
    func_L23_0041BF18(arg0, 2.0f, 2.0f);
    if (*(unsigned char *)(arg0 + 0x20) == 0x10) {
        int m = *(short *)(state + 0x336);
        if ((*(unsigned short *)(arg0 + 0x96) & ((1 << (9 - m)) - 1)) != ((1 << (9 - m)) - 1))
            return 1;
        func_00282CF0((char *)vec, arg1, D_L23_001B3850);
        func_00282F20((char *)vec, (char *)vec, *(short *)(state + 0x33C) * 0.016666668f);
        func_L23_004280D8(arg0, (char *)vec, D_L23_001B3850_b, 0, *(float *)(state + 0x304));
        func_0032C700(D_L23_001B3850_c, 0, 2, 3, 2, 2, 0xA, 0, 0.5f, 20.0f, 1, 1, 0, 0);
        func_L00_0035F5A0(0x1A, 0, 0);
    } else {
        int m = *(short *)(state + 0x334);
        if ((*(unsigned short *)(arg0 + 0x96) & ((1 << (9 - m)) - 1)) != ((1 << (9 - m)) - 1))
            return 1;
        func_00282CF0((char *)vec, arg1, D_L23_001B3870);
        func_00282F20((char *)vec, (char *)vec, *(short *)(state + 0x33A) * 0.016666668f);
        func_L23_00422540(D_L23_001B3850, (char *)vec, (float *)(state + 0x300));
        func_L00_0035F5A0(0x21, 0, 0);
    }
    return 1;
}
