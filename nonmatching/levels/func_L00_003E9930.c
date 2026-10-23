/* Near miss, remeasured 2026-10-23: 348 versus 356 bytes, 0/27 in US,
 * PAL and US2 with default -O2 -G0 -ffunction-sections.
 * Deferring the record-pointer initialization until after the angle calculation
 * restores retail's complete prologue, saved-register allocation and body order.
 * The remaining first difference is +0x6C: div.s starts where retail has the
 * first of two nops. The qualified label/branch division floors do not pad this
 * straight-line region. No manual padding, artificial label or output edit used.
 * Corrected the old draft's vector-add callee to canonical func_00282CC0.
 * Next useful work: establish a real shipping source/assembler condition for
 * this straight-line pre-division padding before changing the compiler.
 */
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

extern void func_00282CC0(char *a, char *b, char *c);

extern void func_00282CF0(char *a, char *b, char *c);

extern void func_00282DD8(char *a, char *b, char *c);

extern void func_00282F20(char *a, char *b, float c);

void func_L00_003E9930(char *a0, char *a1, char *a2, float f12)
{
    Local9930 buf[13];
    Local9930 v0;
    Local9930 v1;
    Local9930 *p;
    float v = 0.0f;
    float angle;
    float f;
    float g;
    int i = 1;

    angle = 6.2831855f / func_00283CE0(11);
    p = buf;
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
        func_00282CC0((char *)p, (char *)p, a1);
        p++;
    } while (i >= 0);
    func_00282CF0((char *)&v0, (char *)buf, a1);
    func_00282CF0((char *)&v1, (char *)&buf[1], a1);
    func_00282DD8(a2, (char *)&v0, (char *)&v1);
    func_00282F20(a2, a2, 1.0f);
}
