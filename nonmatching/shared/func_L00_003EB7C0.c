/* func_L00_003EB7C0 (near miss, 292 bytes at 27 places).
 *
 * The body is read from the retail bytes: it takes two pointers, the second
 * one being the object, and works on the 16-byte scratch buffer at the
 * bottom of its frame.  It asks the level helper for the scale of
 * object+0x38 and for the scale of 3, divides pi by the second, multiplies
 * the first result with that quotient, and then for three offsets of the
 * table reached through the word at 0x189E20+0x2290 it copies the scratch
 * buffer and adds it to the object with the level helpers.
 *
 * Measured: the body has the retail's 292 bytes and the same instructions
 * except for the schedule of the second and third pointer load.  Retail
 * keeps the load before the call and puts the offset addition in the call's
 * delay slot:
 *
 *     lw    $s0,0x2290($s1)
 *     mov.s $f12,$f20
 *     jal   ...
 *     addiu $s0,$s0,0xE0
 *
 * while this compiler moves the load into the delay slot and leaves the
 * addition after the floating-point constants:
 *
 *     mov.s $f12,$f20
 *     jal   ...
 *     lw    $s0,0x2290($s1)
 *     ...
 *     addiu $s0,$s0,0xE0
 *
 * The registers, the frame and the two nops before the div.s all match.  The
 * two nops before the div.s need this unit to be compiled with -g
 * (config/cflags.txt: src/levels/shared/L00_003EA0E0.c), which is what
 * func_002B5EF8 uses for the same pattern; with the default flags the body
 * is 20 bytes shorter.  Tried: the three pointers in one variable, in two
 * and in three; the offset added in the call instead of in the variable; the
 * load and the addition in one statement; the base assigned before the
 * calls and after them.  The pointer variables change which registers the
 * three values take (the retail has the parameter in $s2, the base in $s1
 * and the pointer in $s0), and the two-variable form reproduces that, but
 * no form reproduces the delay-slot choice.
 */

extern char D_00189E20[];

extern float func_00283CE0(int);

extern float func_00283180(float);

extern float func_00283198(float);

extern void func_00282F20(char *dst, char *src, float scale);

extern void func_00282CC0(char *a, char *b, char *c);

void func_L00_003EB7C0(char *unused, char *p)
{
    char buf[16];
    char *q;
    char *q3;
    char *base;
    float f;
    float g;
    float h;

    f = func_00283CE0(*(int *)(p + 0x38));
    g = func_00283CE0(3);
    base = D_00189E20;
    h = 3.1415927f / g;
    q = *(char **)(base + 0x2290);
    q += 0xD0;
    f = f * h;
    g = func_00283180(f);
    func_00282F20(buf, q, g * 1.2f);
    func_00282CC0(p, buf, base + 0x80);
    q = *(char **)(base + 0x2290);
    q += 0xE0;
    g = func_00283198(f);
    func_00282F20(buf, q, g * 1.2f + 2.2f);
    func_00282CC0(p, p, buf);
    q3 = *(char **)(base + 0x2290);
    q3 += 0xC0;
    g = func_00283198(f);
    func_00282F20(buf, q3, g + g);
    func_00282CC0(p, p, buf);
}
