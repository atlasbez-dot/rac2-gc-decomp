/* func_L00_003E7650 - 268 bytes, 27 places, level 00_aranos_tutorial, retail at
   0x003E7650.  NEAR MISS, not integrated.

   The candidate below is retail's size exactly (268 bytes) and its instruction
   sequence word for word, with two instructions in the wrong place: retail
   keeps the two 16-byte copies next to each other

     003E76A8  lq $v0, 0x0($s2)      003E76B0  lq $v0, 0x0($s3)
     003E76AC  sq $v0, 0x0($v1)      003E76B4  sq $v0, 0x0($s0)

   while this build puts the two float constants (0x052359886 and 0x10471977)
   between them and the second copy after them:

     003E76A8  lq $v0, 0x0($s2)
     003E76AC  lui $at, 0x3D56 ...    003E76B8  lq $v0, 0x0($s3)
     ... 0x3DD67752 ...              003E76BC  sq $v0, 0x0($s0)

   Everything else is retail's: the 0xC07-byte allocation, the 0xFF/0xFF/0
   header stores through one register, the two `lq`/`sq` copies (the 16-byte
   ones need the `mode(TI)` type and the `-frac2-qcopy` file profile, see
   config/cflags.txt), the two calls to func_002A7878 with 0.052359886 and
   0.10471977 (the constants are 2 ulp above pi/60 and 2*pi/60), the three
   floats of func_002FED90 (1.0, 1.0, 1.0) and the single exit.

   What was measured: the file's RTL has the copies before the constants
   (the front end's order is right), and the second flow pass (jump2) moves
   the two constant sets in front of the second copy, so the copy cannot come
   back.  Ten source shapes were tried - the constants inline, as two
   variables, as two assignments, the 0x01f store before, between and after
   the copies, the two copies in the other order, the destinations through
   pointer variables, a `volatile` copy, `-fno-schedule-insns`,
   `-fno-schedule-insns2` and `-fno-gcse` - and every one of them leaves the
   two constant loads between the two copies.  The pointer register of the
   first copy ($v1) and the two argument registers of the second call
   ($f13 then $f14) also move.

   Next idea: a source shape where the constant pseudos are not shared by the
   two calls (so the second flow pass has nothing to move), or a compiler-side
   look at what jump2 does with the two identical calls. */

typedef int TI128 __attribute__((mode(TI)));

extern char *func_0029EFD0(int size);

extern float func_002A7878(float lo, float hi);

extern int func_002FED90(char *object, int a, float b, float c, float d);

extern void func_002A0F48(char *object);

char *func_L00_003E7650(int a0, TI128 *a1, TI128 *a2)
{
    char *p;
    char *s0;
    float r;
    float lo;
    float hi;

    p = func_0029EFD0(0xC07);
    if (p != 0) {
        short v = 0xFF;

        s0 = *(char **)(p + 0x68);
        *(short *)(p + 0x32) = v;
        *(char *)(p + 0x30) = v;
        *(char *)(p + 0x20) = 0;
        *(TI128 *)(p + 0x10) = *a1;
        *(TI128 *)s0 = *a2;
        *(float *)(p + 0x2C) = 0.01f;
        lo = 0.052359886f;
        hi = 0.10471977f;
        r = func_002A7878(lo, hi);
        *(float *)(s0 + 0x10) = r;
        r = func_002A7878(lo, hi);
        *(float *)(s0 + 0x14) = r;
        *(int *)(s0 + 0x30) = a0;
        *(int *)(s0 + 0x18) = 0;
        *(int *)(s0 + 0x34) = func_002FED90(p, 0, 1.0f, 1.0f, 1.0f);
        func_002A0F48(p);
    }
    return p;
}
