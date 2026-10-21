/* func_L00_0031C3D0 - 340 bytes, 27 places, retail at 0x0031C3D0 (level 00): seven
   integer arguments (a0, a1, a2, a3, t0, t1, t2), one float local that the retail
   never initialises (the callee-saved $f20), a second one in $f21 (1.0f divided by
   what func_00283CE0 returns for the seventh argument), four 16-byte stack vectors
   and a loop that scales two of them, adds two more and calls func_002761F8.

   NEAR MISS, not integrated.  Checked in src/levels/shared/L00_00316F60.c with
   `python3 tools/check.py func_L00_0031C3D0 --diff`:

     00_aranos_tutorial: 316 bytes, expected 340
     ... (the same at every one of the 27 places)
     func_L00_0031C3D0: 0 of 27 places match (src/levels/shared/L00_00316F60.c)

   The frame (0xA0), the calls, their order, the `div.s $f21,$f1,$f0`, the loop's
   `blez`/`bnez` pair and the `add.s $f20,$f20,$f21` in the back edge's delay slot
   are the retail's; what is left is the register allocation and two instructions
   that the candidate does not have at all.

   What differs, measured:
   - the prologue's save order: retail saves $s3, $s1, $s4, $s5, $s6, $s7 and $s2
     with the argument copies interleaved between them, the candidate groups the
     copies together;
   - the seventh argument (the count) is $s3 in the retail and $s2 in the candidate,
     and the loop counter is $s2 in the retail and $s4 in the candidate;
   - the retail's `blez` delay slot holds `mov.s $f12,$f21`, a copy this cc1 does
     not emit at all: the retail's scale argument is $f12 for the first scaled copy
     and $f20 for the second, and the candidate passes $f20 to both;
   - the candidate is six instructions short.

   Four spellings measured (four vector locals, four byte arrays, an array of four
   vectors, and the loop written as a while instead of a do-while); the do-while
   and the while give the same body, the array of vectors gives the same again.

   What would unblock it: the shape that makes the retail's prologue interleave the
   argument copies with the saves, and the spelling of the scale argument that
   leaves a dead `mov.s $f12,$f21` in the branch's delay slot. */

extern float func_00283CE0(void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, void *, void *, void *);

typedef struct {
    float x, y, z, w;
} V4;

void func_L00_0031C3D0(char *a0, char *a1, char *a2, char *a3, void *a4, void *a5, int a6)
{
    V4 local0, local1, local2, local3;
    float f20;
    float f21;
    int count = 0;

    f21 = 1.0f / func_00283CE0(a6);
    func_00282CF0(&local0, a0, a2);
    func_00282CF0(&local1, a1, a3);
    while (count < a6) {
        func_00282D30(&local2, &local0, f20);
        func_00282D30(&local3, &local1, f20);
        func_00282CC0(&local2, &local2, a2);
        func_00282CC0(&local3, &local3, a3);
        if (func_002761F8(&local2, &local2, 0, a4, a5) != 0)
            break;
        count++;
        f20 += f21;
    }
}
