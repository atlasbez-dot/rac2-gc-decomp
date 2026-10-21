/* func_L03_003C4800 (524 bytes, 2 places) -- NEAR MISS, not integrated. Needs the -g8 profile
   (it reads the group count through $gp): src/levels/shared/L03_002AB5C8-g8.c.
   State: 524 bytes, retail's size; everything up to the inner loop is identical (the unrotated
   group walk, the 0x93C/0x940/0x964 switch with the gp-relative tables, the 0xFE/0xFD/0x31
   tests) and so are all the instructions of the loop body. check.py (03_endako) says
   "instruction at +0x10c differs"; by an aligned diff 16 of 131 words differ, all of them
   scheduling and one placement:
     - retail keeps `addiu $s3,$s3,0x10` in the delay slot of the second jal, `addiu $s2,$s2,4`
       right after it and `addiu $s1,$s1,-1` in the third jal's slot, and `lq`/`sq` adjacent;
       this cc1 hoists `addiu $s2` and `addiu $s1` above the first jal, puts the argument moves
       of the second call between the `lq` and its `sq`, and puts `addiu $s0,$sp,0x40` in the
       delay slot of the `beqz $v1` that guards the loop (retail: last of the pre-loop moves).
   Cause (measured, not a source shape): retail's 16-byte copy behaves as ONE scheduling barrier
   between the first and the second call. Compiling this very body with
   `__asm__ __volatile__("");` right after the `*(TI128 *)vp = vecs[j];` line (diagnostic only,
   never in src/) makes the whole loop match retail word for word; the 4 words left are the
   pre-loop block above (retail's `&v` is a loop-invariant hoisted by loop.c, because it is the
   operand of a register-constrained copy; here it has to be an explicit pointer). A `volatile
   TI128` store, or load and store, is not that barrier: still 16 words.
   Measured and right, worth keeping when the barrier is available:
   - `float *vp = v;` assigned right before the inner loop gives `sq $v0,0($s0)` with the address
     materialised (the plain array `v` folds to `sq $v0,0x40($sp)`, the known cse tie); `m` is
     declared before `v` so that `m` sits at sp+0 and `v` at sp+0x40; `v[3]` (the `lwc1`/`swc1` at
     0x4C($sp)) is read and written through the array, not through `vp`.
   - `for (j = 0; j < n; j++)` is the only loop form that gives 524 bytes (do/while, pointer
     walking and `j != n` are 516 to 532); the case labels must be in the order 0x940, 0x93C,
     0x964, default for the blocks to sit as in retail.
   - the id arrays and the 16-byte vectors of the first three classes are `extern int X
     __attribute__((sda));` (size at most 8) taken by `&X`, which gives `addiu $r,$gp,off`; the
     5-vector array at 0x29A880 (class 0x964) is absolute, `extern TI128 X[5]`.
   - flags screened on this body (one extra flag, config/ untouched): -fno-schedule-insns 24 words,
     -fno-schedule-insns2 33, -fno-sched-interblock and -fno-sched-spec the same 16, -fno-gcse,
     -fno-strength-reduce and -fno-delayed-branch change the size.
   What would unblock it: a compiler-side form of the quadword copy that is one scheduling unit
   (as an inline-asm `qcopy` is). */
#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern int D_L03_001B2A38 __attribute__((sda));
extern unsigned char *D_L03_001B2A1C[3] __attribute__((sda));
extern unsigned short *D_L03_001FB5A0[];

extern void func_0029FC20(void *, int, void *);
extern void func_002830C0(void *, void *, void *);
extern void func_L00_00325AE8(void *, int, float, float);

extern int D_L03_001AFF60 __attribute__((sda));
extern int D_L03_001AFF78 __attribute__((sda));
extern int D_L03_001AFF88 __attribute__((sda));
extern int D_L03_001AFF98 __attribute__((sda));
extern int D_L03_001AFFB0 __attribute__((sda));
extern int D_L03_001AFFE0 __attribute__((sda));
extern int D_L03_001B0010 __attribute__((sda));
extern TI128 D_L03_0029A880[5];

/* For each entity of the object's group whose byte at 0x31 is set and which is not in state 0xFE
   or 0xFD, it takes the table of points of its class (0x940, 0x93C, 0x964, else) and, for each
   point: the joint matrix of the entity (func_0029FC20), the point transformed by it
   (func_002830C0, w forced to 1.0) and an effect at it (func_L00_00325AE8: the point's own w
   as its size, 0.08). */
void func_L03_003C4800(unsigned char *a0) {
    unsigned short *q;
    unsigned char *e;
    int *ids;
    TI128 *vecs;
    int n;
    int j;
    float w;
    float m[16];
    float v[4];
    float *vp;

    for (q = D_L03_001FB5A0[a0[0x21]];
         a0[0x21] != 0xFF && a0[0x21] <= D_L03_001B2A38 && q != 0 &&
         ((q != 0 && (short)q[-1] >= 0) || q == D_L03_001FB5A0[a0[0x21]]);
         q++) {
        e = D_L03_001B2A1C[0] + ((*q & 0x7FFF) << 8);
        if (e == 0)
            break;
        if (e[0x31] == 0)
            continue;
        if (e[0x20] == 0xFE)
            continue;
        if (e[0x20] == 0xFD)
            continue;
        switch (*(short *)(e + 0xAA)) {
        case 0x940:
            ids = &D_L03_001AFF88;
            vecs = (TI128 *)&D_L03_001AFFE0;
            n = 3;
            break;
        case 0x93C:
            ids = &D_L03_001AFF78;
            vecs = (TI128 *)&D_L03_001AFFB0;
            n = 3;
            break;
        case 0x964:
            ids = &D_L03_001AFF60;
            vecs = D_L03_0029A880;
            n = 5;
            break;
        default:
            ids = &D_L03_001AFF98;
            vecs = (TI128 *)&D_L03_001B0010;
            n = 3;
            break;
        }
        vp = v;
        for (j = 0; j < n; j++) {
            func_0029FC20(e, ids[j], m);
            *(TI128 *)vp = vecs[j];
            w = v[3];
            v[3] = 1.0f;
            func_002830C0(vp, vp, m);
            func_L00_00325AE8(vp, *(int *)(e + 0x78), w, 0.08f);
        }
    }
}
