/* 0 of 1 places match - last line: 09_dobbo: instruction at +0x20 differs (208 bytes, retail 208)
   Samples the sub-object through the shared record starter and ramps the
   three floats it wrote into the object's 0x390/0x394/0x398 channels at 0.02
   per frame.  Needs the grouped quadword copy (-frac2-qcopy) for the eight
   bytes it copies out of the object's 0x10 pair.

   Measured with -O2 -G0 -ffunction-sections -frac2-qcopy: 4 of the 52 words
   differ, and they are the same four instructions in the other order - the
   4.0f constant's `lui`/`mtc1` pair and the copy's `lq`/`sq` pair.
   Retail: addiu $v1,$s1,0x10 ; lq $v0,0($v1) ; sq $v0,0($sp) ; lui $at,0x4080 ;
   mtc1 $at,$f0 ; lh $a0,0x32($s1) ; jal ; swc1 $f0,0xC($sp).
   This cc1: addiu $v1,$s1,0x10 ; lui $at,0x4080 ; mtc1 $at,$f0 ; lq $v0,0($v1) ;
   sq $v0,0($sp) ; lh $a0,0x32($s1) ; jal ; swc1 $f0,0xC($sp).
   Everything else is retail's word for word: the frame (0x40), the 4.0f
   constant, the `swc1` of the 4.0f in the call's delay slot, the three
   func_00282F20 calls with the 1.0f scale and the store of 2 at 0x42C.
   The `lui`/`mtc1` pair is the constant's materialisation: this cc1 hoists it
   to the top of the block, retail keeps it after the copy.  The copy is a
   `mode(TI)` assignment into the float array, and without -frac2-qcopy the
   constant offset is folded into the `lq` (lq $v0,0x10($s1)), which is the
   known constant-offset wall (docs/COMPILER-NOTES.md).
   Tried (about nine compiles): the union of a TI and a float[4] against a
   plain float[4], the constant before and after the copy, the store through a
   float pointer and through a char offset, the constant in a local, the copy
   through a char pointer, and -frac2-qcopy with -fno-schedule-insns; all of
   them give the same four words.
   Would unblock: a cc1 lever that keeps the constant's materialisation after
   the copy, or a source shape that makes the copy a scheduling barrier. */
typedef int TI __attribute__((mode(TI)));

extern int func_002A77E0(int);
extern float func_00283CE0(int);
extern int func_00283DB8(float *, float);
extern void func_0029FC20(char *, int, char *);
extern void func_00282F20(float *, float *, float);

void func_L09_003FDFF0(unsigned char *a0) {
    unsigned char *s1 = a0;
    unsigned char *s2 = *(unsigned char **)(s1 + 0x68);
    float buf[4];
    if (func_002A77E0(5) == 0)
        return;
    *(TI *)buf = *(TI *)(s1 + 0x10);
    buf[3] = 4.0f;
    if (func_00283DB8(buf, func_00283CE0(*(short *)(s1 + 0x32))) == -1)
        return;
    func_0029FC20((char *)s1, 1, (char *)(s2 + 0x340));
    func_00282F20((float *)(s2 + 0x340), (float *)(s2 + 0x340), 1.0f);
    func_00282F20((float *)(s2 + 0x350), (float *)(s2 + 0x350), 1.0f);
    func_00282F20((float *)(s2 + 0x360), (float *)(s2 + 0x360), 1.0f);
    *(int *)(s2 + 0x42C) = 2;
}
