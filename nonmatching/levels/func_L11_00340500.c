/* Near miss from src/levels/11_joba/L11_002DE9E0.c: the build refuses this body at its
   place — instruction at +0x8 differs. Kept as a starting point;
   not linked, not counted.
   Wave 9 (p1) re-measured it: 72 bytes, every instruction and every call matches, and
   one instruction sits one slot too late.  Retail copies the incoming pointer into $s1
   between the two callee-saved stores, this cc1 copies it after them:
     00340504  sd   $s1,0x18($sp)  |  sd   $s1,0x18($sp)
     00340508  daddu $s1,$a0,$zero |  sd   $s0,0x10($sp)
     0034050C  sd   $s0,0x10($sp)  |  daddu $s1,$a0,$zero
   The body is the twin of the matched func_L02_00333438
   (src/levels/shared/L02_002B5F50.c), which hands the shared helper its second
   argument; here the helper gets `a0 + 0x10` instead, so the two pointers live in
   $s1 and $s0 across the call.  Tried (all three give the same bytes): the plain
   form above, a local for `a0 + 0x10`, and a local for `a0` plus one for `a0 + 0x10`.
   What is left is a lever that puts the parameter copy between the two stores. */

/* Near miss: 68 against 72 bytes, one word out of place.  Level 11, 0x00340500.

   The body is retail's: the frame, the two calls (func_00282CF0 with the
   16-byte local, then func_L02_00333480) and the epilogue all match.  The
   only difference is where the copy of the incoming object pointer sits:

     retail: sd $s1,0x8($sp) ; sd $s0,0x0($sp) ; daddu $s1,$a0,$zero ;
             addu $s0,$s1,0x10 ; sd $ra,0x20($sp)
     here:  sd $s1,0x8($sp) ; daddu $s1,$a0,$zero ; sd $s0,0x0($sp) ;
             addu $s0,$s1,0x10 ; sd $ra,0x20($sp)

   The copy of the parameter into its callee-saved home is the reload's, and
   the reload puts it right after the save of the register it defines; the
   retail keeps it after the save of the other callee-saved register as well.
   Measured and identical: the local as `float buf[4]`, `char buf[16]`,
   `int buf[4]`, `double buf[2]`, `long long buf[2]`; the declaration order
   of the two pointers; the local declared before or after them; the
   parameter typed `char *` or `void *`; the second call taking `s1` or the
   parameter; the first call taking `&buf[0]`; the -G8 profile (the same
   output as -G0); and -fno-schedule-insns, which moves the copy one slot the
   other way (it leaves the saves in the order sd $s0 ; sd $s1).

   The retail's registers are the other way round from this candidate's
   ($s0 = the object, $s1 = the local + 0x10); no spelling measured here
   changes that. */


extern void func_00282CF0(void *, void *, void *);
extern void func_L02_00333480(char *, char *, void *);

void func_L11_00340500(char *a0, void *a1)
{
    char *s1 = a0;
    char *s0 = s1 + 0x10;
    float buf[4];

    func_00282CF0(buf, a1, s0);
    func_L02_00333480(s1, s0, buf);
}
