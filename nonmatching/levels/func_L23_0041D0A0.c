/* func_L23_0041D0A0 (336 bytes, 1 place: level 23) -- NEAR MISS, not integrated.
   Measured on 21 October 2026 in a unit of its own (src/levels/23_damosel_orbit/L23_0041D0A0-g8.c) built with
   `-O2 -G8 -ffunction-sections -frac2-qcopy`: 336 bytes, retail's size, and the register allocation, the
   restart loop, the table load and the epilogue are retail's, word for word. What is left is one
   instruction out of place: five words, +0x70 to +0x80. Retail has
       sll $v1,$v0,4 ; addu $v1,$v1,$s1 ; addiu $v1,$v1,0x10 ; lq $v0,0($v1) ; sq $v0,0($fp) ;
       daddu $a0,$fp,$zero ; jal func_L23_00418650 ; mov.s $f12,$f21
   and this cc1 hoists the argument setup: `sll ; daddu $a0,$fp,$zero ; addu ; addiu ; lq ; sq ; jal`.
   What fixed the earlier record's two other differences:
   - the success path (the second random index, the copy, the call) is written after the loop, which the loop
     leaves with `break`, instead of inside a `for (;;)` that returns. In the loop, arg0's three uses were
     weighted by the loop depth (refs 5) and its priority beat the others'; outside it arg0 has refs 3 and
     priority 698 against arg1's 909 (floor_log2(refs) * refs / live length), so global-alloc gives it the
     last register: arg0 $fp, arg1 $s7, slots $s6, the D_00189EA0 base $s5, as retail.
   - `char *slots` with `slots + (w << 2)` gives retail's `addu $v0,$s6,$v0` (base first).
   Cause of the five words (-dR -fsched-verbose-5, sched2, block of the success path): the second random-index
   call is followed by the chain sll, addu, addiu, then the copy; `$a0 = $fp` and `$f12 = $f21` only have to
   follow the call, so they take the free second issue slot of cycles 5 and 6. Retail has them after the sq. With
   the original's volatile asm macro (`__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(arg0),
   "r"(src) : "$2")`, scratch only) this file is exact except for the operand order of its `addu`, since an asm
   operand is not the TI dereference: the asm is a scheduling barrier, which keeps the argument setup after it.
   The qcopy insn is an ordinary insn (one insn, no barrier), so nothing keeps `$a0 = $fp` behind it.
   Tried without effect (same five words): the destination through a local pointer, the source as
   `((TI128 *)((char *)list + 0x10))[k]`, the copy written inside the call's argument with a comma expression,
   -frac2-zero-ti-barrier added (no change), and 50 single extra cc1 flags (-fno-schedule-insns makes it 12 words, -fno-schedule-insns2 30). A TI
   temporary (`TI128 t = *src; *dst = t;`) is separate lq and sq insns and loses 4 bytes. Needs a barrier
   model for qcopy (as the clear has) or a way to give the argument setup a dependence on the copy. */


typedef int TI128 __attribute__((mode(TI)));

extern char *D_L23_001B1484 __attribute__((sda));

extern int *D_L23_001FF300[];

extern char D_00189EA0[];

extern float func_00282E48(char *, char *);

extern int func_002A77E0(int);

extern int func_L23_00419CA0(int);

extern void func_L23_00418650(char *, float);

int func_L23_0041D0A0(char *arg0, int arg1, float arg2) {
    char *state = *(char **)(D_L23_001B1484 + 0x68);
    char *slots = state + 0x230;
    float best = 45.0f;
    int found;
    int w;
    int j;
    int *list;
    char *p;
    int k;

    for (;;) {
        found = 0;
        w = func_002A77E0(0x2F);
        list = D_L23_001FF300[*(int *)(slots + (w << 2))];
        p = (char *)list + 0x10;
        for (j = 0; j < *list; j++) {
            if (func_00282E48(D_00189EA0, p) < best) {
                found = 1;
                break;
            }
            p += 0x10;
        }
        if (found)
            continue;
        if (arg1 == 0)
            continue;
        if (func_L23_00419CA0(w) == 0)
            continue;
        break;
    }
    k = func_002A77E0(*list - 1);
    *(TI128 *)arg0 = *(TI128 *)((char *)list + k * 16 + 0x10);
    func_L23_00418650(arg0, arg2);
    return 1;
}
