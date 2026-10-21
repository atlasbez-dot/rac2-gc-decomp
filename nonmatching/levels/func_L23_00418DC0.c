/* func_L23_00418DC0 (360 bytes, level 23 only) -- NEAR MISS, not integrated.
   Measured on 21 October 2026 in a unit of its own (src/levels/23_damosel_orbit/L23_00418DC0.c) built with
   `-O2 -G0 -ffunction-sections -frac2-qcopy`: 360 bytes, retail's size. Only the entry block differs: 32
   words between +0x04 and +0x80 (the register saves, the 16-byte copy of arg0+0x10, the first call's
   arguments, the two float constants and i = 0 are interleaved in another order). From +0x84 to
   the end, including the loop registers (k in $s1, the object in $s2, i in $s3) and the nop at
   the inner loop entry, it matches. check.py reports "instruction at +0x8 differs".
   What fixed the earlier 356-byte attempt: the inner loop indexes the entries
   (`obj + 0x10 + k * 0x10`) instead of walking a pointer, which keeps sched1 from hoisting the
   pointer increment and the call arguments above the compare; and `char *slots` with
   `slots + (i << 2)` gives retail's `addu v0,s7,v0`.
   What remains is the entry block. Retail:
       sd $s5,0x48($sp) ; sd $fp,0x60($sp) ; daddu $s5,$a0,$zero ; sd $s0 ; daddu $fp,$a1,$zero ; sd $s1 ;
       addiu $a1,$s5,0x10 ; sd $s2,$s3,$s4,$s7,$ra ; swc1 $f20 ; sd $s6 ; lw $s6,0x68($s5) ;
       lq $v0,0($a1) ; sq $v0,0($sp) ; addiu $s0,$sp,0x10 ; lui $a2 ; addiu $a2 ; jal ; daddu $a0,$s0 ;
       addiu $s7,$s6,0x230 ; (the two float constants) ...
   i.e. everything before the copy in source order (the saves, the argument copies, the state load) comes
   before it, and the copy's address is `$a1`, the same register the first call takes it in; the local's address,
   the base of D_00189EA0 and the slots pointer come after. This cc1 hoists `lui $a2 ; addiu $a2`, the local's
   address and `i = 0` above the copy, and keeps the copy's address in $v1 with `daddu $a1,$v1,$zero` for the call.
   Cause (measured, -dR -dc -fsched-verbose-5): (1) the copy is an ordinary insn of priority 9 that waits for
   its address; the local's address and the `lui` of D_00189EA0 (priority 10) are ready in the first cycles
   and outrank it (the copy is issued in cycle 5 of sched1). (2) before sched1 the address pseudo dies at the
   argument setup `$5 = src`, which comes after the copy, so the copy carries no REG_DEAD for it: sched1's
   register-weight tie-break (smaller weight first) puts the setup before the copy, the address then dies at
   the copy, and local-alloc cannot give it `$a1` (it is live across the setup's own copy): hence `$v1` +
   `daddu $a1,$v1,$zero`.
   With the original's volatile asm copy (`__asm__ __volatile__("lq $2,0(%1)\n\tsq $2,0(%0)" :: "r"(&loc.a),
   "r"(src) : "$2")`, scratch only) this file is exact (0 words differ, derive OK) in the source order
   state load, copy, first call, `slots = state + 0x230`: the asm keeps everything after it behind it. The C
   below has that order (the earlier record formed slots first; both give 32 words with qcopy, and so does adding
   -frac2-zero-ti-barrier; of 50 single extra cc1 flags none helps: -fno-schedule-insns2 36 words, -fno-gcse 356 bytes). The qcopy insn is not a
   barrier.
   func_L23_00419088 is called unprototyped because the unit defines it with an s16 parameter
   (a prototype makes this caller sign-extend i). Measured on 20 October 2026: that definition
   still matches 1 of 1 with an s32 parameter, so whoever integrates this can prototype the call.
*/


typedef int s32;
typedef short s16;
typedef int TI128 __attribute__((mode(TI)));

extern void func_00282CF0(float *, const float *, const float *);

extern void func_00282F20(char *, char *, float);

extern void func_00282CC0(char *, char *, char *);

extern float func_00282E48(char *, char *);

extern char D_00189EA0[];

extern int *D_L23_001FF300[];

extern s32 func_L23_00419CA0(s32 arg0);

/* Picks the nearest entry of the object each measured slot names, and stores the index found. */
void func_L23_00418DC0(char *arg0, s32 arg1) {
    extern void func_L23_00419088();
    struct {
        TI128 a;
        float b[4];
    } loc;
    char *src = arg0 + 0x10;
    char *state;
    char *slots;
    float best;
    s32 i;

    state = *(char **)(arg0 + 0x68);
    loc.a = *(TI128 *)src;
    func_00282CF0(loc.b, (float *)src, (float *)D_00189EA0);
    slots = state + 0x230;
    best = 30000.0f;
    func_00282F20((char *)loc.b, (char *)loc.b, 4.0f);
    func_00282CC0((char *)&loc.a, (char *)&loc.a, (char *)loc.b);
    for (i = 0; i < 0x2F; i++) {
        int *obj;
        s32 k;

        if (arg1 != 0 && func_L23_00419CA0(i) == 0)
            continue;
        obj = D_L23_001FF300[*(int *)(slots + (i << 2))];
        for (k = 0; k < *obj; k++) {
            float d = func_00282E48((char *)obj + 0x10 + k * 0x10, (char *)&loc.a);

            if (d < best) {
                best = d;
                func_L23_00419088(arg0, i);
                *(s16 *)(state + 0x396) = k;
            }
        }
    }
}
