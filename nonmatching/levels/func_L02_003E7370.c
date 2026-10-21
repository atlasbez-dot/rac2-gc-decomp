/* func_L02_003E7370, 564 bytes, 1 placement (level 2).  Near miss: 568 bytes against 564, and the
   whole difference is the two 16-byte clears of the particle vector.  Built in a -G8 unit (the
   function reads D_L02_001B096C through $gp outside a delay slot: `lw $v0,0x197C($gp)`), flags
   `-O2 -G8 -ffunction-sections` (adding `-frac2-gcse-unsplit-edges` changes nothing).  135 of
   retail's 141 words are the same, in the same order: the saves, the constants kept in $f21..$f23,
   both loop bodies, the `por $v0,$zero,$zero ; sq $v0,0x10($sp)` clear of the second vector and the
   `lw`/`sw` of D_L02_001B096C.  What differs (tools/check.py: 568 bytes, expected 564):
     retail  nop at +0x5C ; L1: sq $zero,0($sp) ... bnez $v0,L1 ; por $v0,$zero,$zero (delay slot)
     here    sq $zero,0($sp) at +0x5C ; L1: mov.s $f12,$f22 ... bnel $v0,$zero,L1 ; sq $zero,0($sp)
             (the annulled slot) ; por $v0,$zero,$zero after the branch
     retail  L2: sq $zero,0($sp) (8-byte aligned) ... bgtz $v1,L2 ; nop
     here    sq $zero,0($sp) ; nop (the loop's alignment pad) ; L2: mov.s ... bgtzl $v1,L2 ;
             sq $zero,0($sp)
   Cause (measured): retail's clear is not an ordinary store for the delay-slot filler.  Both
   quadword clears of its loops are the inline-asm macro the docs call the removed qzero helper,
   `asm volatile ("sq $0,0x0(%0)")`: reorg's resource model treats a volatile asm as conflicting
   with everything, so the loop-closing branch gets nothing from its target and takes the first
   insn of the fall-through thread instead (`por` for the first loop, nothing for the second) in
   a plain branch, and the loop label stays in front of the `sq`.  This cc1's TImode store of zero
   is an ordinary store: reorg copies it into the annulled slot of a branch-likely and moves the
   label behind the copy, which also moves the alignment pad.
   Measured in a scratch copy (not allowed in src/): with the two loop clears written as
   `__asm__ volatile ("sq $0,0x0(%0)" : : "r"(a));` the same C is exact (1 of 1 places), with and
   without `-frac2-gcse-unsplit-edges`, so nothing else differs.
   Tried, nothing moves the 568 bytes or the shape: the clear as `*(TI128 *)a = 0` (below),
   through a TI128 pointer local (580 bytes), on a struct {x, y, z, w} local, the loops as
   do-while; `__builtin_memset(a, 0, 16)` (a real call, 588 bytes); `-frac2-zero-ti-barrier` (it
   only gives the store a volatile asm's dependences in sched_analyze_insn: the output is the
   same), and one extra flag each on top of it: -g, -fno-schedule-insns, -fno-schedule-insns2,
   -fno-expensive-optimizations, -fno-delayed-branch (632), -fno-gcse, -fno-strength-reduce,
   -mno-split-addresses, -frac2-keep-block-order, -fno-rerun-cse-after-loop (596),
   -fno-cse-follow-jumps, -fno-thread-jumps.
   What would unblock it: the barrier profile also for reorg (the zero clear a volatile resource in
   mark_referenced_resources, so it never fills a delay slot); the C below would then go into a
   -G8 unit with that profile unchanged.
   Body measured in the -G8 unit: */

typedef int TI128 __attribute__((mode(TI)));

extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern void func_00283098(float *, float *, float *);
extern void func_00282CC0(float *, float *, float *);
extern char *func_00273730(char *, int, int, int, char *, char *, float *, int, float, float);
extern int func_00302470(char *, float *, float *, int, int, int);
extern int D_L02_001B096C __attribute__((sda));

/* Spawns five particles at the actor (the ids 0xCA5 to 0xCA9, each with a random velocity in a
   0.0167-scaled box rotated by the matrix at +0xC0), then, while D_L02_001B096C stays above 0, up
   to five more (-5 each) through func_00302470 around a point near the actor. */
void func_L02_003E7370(char *arg0) {
    float a[4];
    float b[4];
    char *pos = arg0 + 0x10;
    char *mat = arg0 + 0xC0;
    int i;

    for (i = 0xCA5; i < 0xCAA; i++) {
        *(TI128 *)a = 0;
        a[0] = func_002A7878(1.0f, 4.0f) * 0.016666668f;
        a[1] = func_002A78D8(1.0f, 3.0f) * 0.016666668f;
        a[2] = func_002A7878(4.0f, 9.0f) * 0.016666668f;
        func_00283098(a, a, (float *)(arg0 + 0xC0));
        func_00273730(arg0, 0, i, -1, arg0 + 0x10, arg0 + 0xF0, a, 0xFF,
                      func_002A7878(90.0f, 180.0f), func_002A7878(15.0f, 25.0f));
    }
    *(TI128 *)b = 0;
    b[2] = 1.5f;
    func_00283098(b, b, (float *)mat);
    func_00282CC0(b, b, (float *)pos);
    for (i = 0; i < 5 && D_L02_001B096C > 0; i++) {
        *(TI128 *)a = 0;
        a[0] = func_002A7878(1.0f, 4.0f) * 0.016666668f;
        a[1] = func_002A78D8(1.0f, 3.0f) * 0.016666668f;
        a[2] = func_002A7878(4.0f, 9.0f) * 0.016666668f;
        func_00283098(a, a, (float *)mat);
        func_00302470(arg0, b, a, 0, 5, 0);
        D_L02_001B096C -= 5;
    }
}
