/* NEAR MISS, level 7 (siberius), func_L07_00378898: 572 bytes against retail's 580, 0 of 1 places.

   The body is right; what is left is allocation and scheduling that follow from one structural
   difference. Retail (read from 0x378898 on):
     - the walk's outer index `i` lives in $s2 (callee-saved) and the next index `i + 1` in $s7.
       `addiu $s7,$s2,1` appears twice: in the delay slot of the `beq` that skips an empty group
       (0x378938) and in the delay slot of the `b` into the walk test (0x378994), i.e. AFTER the
       angle call. That second copy is what keeps `i` alive across `func_00283B98` and so in $s2.
       Here gcse's PRE inserts both copies too (PRE/HOIST at the end of the first block and at the
       end of the pre-header), but cse2 sees them in one extended block and turns the second into
       a no-op, so `i` dies before the call and takes $a0, and `addiu $s7` ends up before the
       `addu` of the group address.
     - the group word is re-read after the call as `addu $a0,$s6,$s4 ; lw $v0,0($a0)` ($s4 = i*4,
       a copy made by PRE); here cse1/cse2 reuse the first address (`addu $s1,$s6,$v1`, kept in
       $s1 across the call) and read `lw $v0,0($s1)`. The same cause: retail has something between
       the first read and the post-call read that ends a cse extended block (a label that is
       folded away afterwards), this C has not.
     - the load of D_L07_001C9780 is `lui $v0 ; lw $v1,lo($v0)` in retail (hi and value in two
       registers), `lui $v0 ; lw $v0,lo($v0)` here.
   Everything else matches word for word (prologue, the switch, the sda array address with
   `addiu $v0,$gp,-0x3F8`, the float constant 0x3998825C, the two copy loops, the three calls,
   the walk test with `bgezl`, the epilogue); `tools/check.py` reports "instruction at +0x7c
   differs".

   What reaches the rest of the retail's shape (each measured with tools/check.py --diff):
     - `switch (a0[0x20])` with cases 0 and 1 (an if chain lays the cases out the other way round);
     - a struct for the state with `int groups[3]` then `float angles[3]` (angles at +0xC as a
       separate base: `addiu $s0,$s6,0xC ; addu $s0,$s0,$s4`), the group word read again at every
       use;
     - `float v[4]` declared before `float loc[3]` (frame order), zeroed with
       `*(TI128 *)v = 0` (gives `sq $zero,0($sp)`), `v[2]` stored as a plain float, and a pointer
       `q = loc` taken inside the walk body (gives the $s2 pointer to sp+0x10 in the delay slot of
       the loop-back branch); two different counters for the two 3-iteration copy loops;
     - the sda array must be declared with at most 8 bytes (`float X[2]`): `float X[3]` gives
       `lui/addiu` instead of `addiu $v0,$gp,...`; the constant is `0.00029088824f` (0.00029088821f
       and 0.0002908882f give 0x...825B / 0x...825A);
     - the angle must not share the float variable with the row length `t` (a shared `t` puts the
       angle in $f20 across the walk: an extra `mov.s $f20,$f0`).
   Tried without moving the remaining differences: int-pointer state with casts instead of a
   struct; if/else, while, do-while and `continue` forms of the outer loop; a separate next-index
   variable; the double `p != 0` walk test; a do-while(0) around the angle update (cuts cse1 but
   not cse2); a single-iteration loop around it (turns into a real loop); TI128 variables for v
   and loc; the zero store before/after the angle; operand orders of every sum; char/unsigned char
   entity pointer; a constant flag branch. A shape that puts a real label (cse2 stops at one)
   between the first group read and the angle call, and nothing visible in the final code, would
   be the thing to look for. */

#include "include_asm.h"

typedef int TI128 __attribute__((mode(TI)));

extern void func_002A7750(unsigned char *, int, int);
extern float func_00283B98(float, float);
extern float func_00282DF0(void *);
extern void func_002833F0(void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_0036AE00(int, int);

extern int D_L07_001C9780;
extern unsigned short **D_L07_001A9014;
extern unsigned char *D_L07_001B295C;
extern float D_L07_001AEBF8[2] __attribute__((sda));

typedef struct {
    int groups[3];
    float angles[3];
} RotState;

void func_L07_00378898(unsigned char *a0)
{
    RotState *s6 = *(RotState **)(a0 + 0x68);
    int i;
    unsigned short *p;
    unsigned char *e;
    float v[4];
    float loc[3];
    float *q;
    int k;
    int m;
    float t;
    float ang;

    switch (a0[0x20]) {
    case 0:
        a0[0x30] = 0xFF;
        func_002A7750(a0, 1, -1);
        break;
    case 1:
        if (D_L07_001C9780 != 0)
            return;
        for (i = 0; i < 3; i++) {
            if (s6->groups[i] == -1)
                continue;
            *(TI128 *)v = 0;
            ang = func_00283B98(s6->angles[i], D_L07_001AEBF8[i] * 0.00029088824f);
            s6->angles[i] = ang;
            v[2] = ang;
            for (p = D_L07_001A9014[s6->groups[i]];
                 p != 0 && ((short)p[-1] >= 0 || p == D_L07_001A9014[s6->groups[i]]);
                 p++) {
                e = D_L07_001B295C + ((*p & 0x7FFF) << 6);
                if (e == 0)
                    break;
                q = loc;
                for (k = 0; k < 3; k++)
                    q[k] = *(float *)(e + 0xC + k * 16);
                t = func_00282DF0(e);
                func_002833F0(e, v);
                func_00282F20(e, e, t);
                func_00282F20(e + 0x10, e + 0x10, t);
                for (m = 0; m < 3; m++)
                    *(float *)(e + 0xC + m * 16) = q[m];
                func_L00_0036AE00(*p & 0x7FFF, 1);
            }
        }
        break;
    }
}
