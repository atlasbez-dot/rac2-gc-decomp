/* func_L00_003E9930 - 356 bytes, 27 places, level 00_aranos_tutorial, retail at
   0x003E9930.  NEAR MISS, not integrated.

   The candidate below is 348 bytes against retail's 356 and reads the same:
   it asks func_00283CE0 for a step, divides 2*pi (0x40C90FDB) by it, and then
   runs two rounds of a loop that funnels a value through func_00283B98, takes
   its sine and cosine, scales them by the argument and writes them into a
   16-byte record, before the three vector helpers at the end.

   What is measured and right: the frame (0x160) with the saved registers at
   +0xF0 and the three float registers $f20 (the loop value), $f21 (the
   argument) and $f22 (the angle); the 0xF0-byte local area with the 13
   records of the loop and the two at +0xD0 and +0xE0; the loop's two rounds
   (the counter starts at 1 and is decremented before the test); the stores
   of the record, the two calls with the vector at +0xC0 of the first
   argument, and the two 0x10-byte records the loop fills.

   What is left: retail has two `nop`s in front of the `div.s` (0x003E999C and
   0x003E99A0) and this build has none - the SN assembler inserts them when a
   division comes fewer than two instructions after a label, so retail's
   division stands at the head of a basic block and this one does not.  The
   prologue's save order and the two counters also differ: retail keeps the
   second argument in $s1 and the loop counter in $s2, this build the other
   way round, and retail takes the address of the loop's record after the
   division (0x003E99A8) where this build takes it in the prologue.

   Tried: the two stores of the record before and after the call they belong
   to (the store of +0x04 before the call keeps the value out of a saved
   register and the body then matches), the loop as a do-while and as a
   for, the angle as one expression and as two statements.  The two nops are
   a compiler-side matter: they need the division in a block of its own. */

typedef struct {
    int i0;
    float f4;
    float f8;
    int iC;
} Local9930;

extern float func_00283CE0(int a);

extern float func_00283B98(float a, float b);

extern float func_00283180(float a);

extern float func_00283198(float a);

extern void func_00283098(char *a, char *b, char *c);

extern void func_00282F38(char *a, char *b, char *c);

extern void func_00282CF0(char *a, char *b, char *c);

extern void func_00282DD8(char *a, char *b, char *c);

extern void func_00282F20(char *a, char *b, float c);

void func_L00_003E9930(char *a0, char *a1, char *a2, float f12)
{
    Local9930 buf[13];
    Local9930 v0;
    Local9930 v1;
    Local9930 *p = buf;
    float v = 0.0f;
    float angle;
    float f;
    float g;
    int i = 1;

    angle = 6.2831855f / func_00283CE0(11);
    do {
        v = func_00283B98(v, angle);
        i--;
        p->iC = 0;
        f = func_00283180(v) * f12;
        p->i0 = 0;
        p->f4 = f;
        g = func_00283198(v);
        p->f8 = -g * f12;
        func_00283098((char *)p, (char *)p, a0 + 0xC0);
        func_00282F38((char *)p, (char *)p, a1);
        p++;
    } while (i >= 0);
    func_00282CF0((char *)&v0, (char *)buf, a1);
    func_00282CF0((char *)&v1, (char *)&buf[1], a1);
    func_00282DD8(a2, (char *)&v0, (char *)&v1);
    func_00282F20(a2, a2, 1.0f);
}
