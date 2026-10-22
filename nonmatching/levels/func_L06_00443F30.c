/* Near miss: the body is one instruction away from retail.
 *
 * func_L06_00443F30 (level 06, 312 bytes).  The candidate is the same size as retail and
 * every instruction matches except one: retail materialises the first stack argument
 * (the literal 1) between the two float constants,
 *
 *     lui $at,0x41A0 ; mtc1 $at,$f13      ; 20.0f  -> $f13
 *     addiu $v0,$zero,0x1                 ; the stack argument 1
 *     lui $at,0x3EAA ; ori $at,$at,0x7EFA ; 0.333f -> $f12
 *
 * while this candidate emits the literal 1 first and the two float constants after it.
 * The order is the one cc1 gives when it expands the outgoing stack arguments before the
 * register arguments; it was not reachable by moving the argument between the float
 * parameters, by typing the zero arguments as pointers (the retail's `daddu $x,$zero,$zero`
 * needs the 64-bit pointer type) or by typing the literal 1 as a pointer.
 *
 * The float constants are retail's bits, not the natural spellings: 0x3EAA7EFA (0.333f) and
 * 0x3DCCCCCE (one ulp above 0.1f, spelled 0.10000000894069672f).
 */

#include "include_asm.h"

/* A quadword, zeroed as retail's por/sq pair. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_002A6C58(char *, int, int);
extern int func_002E5CF8(int, int, char *);
extern void func_00283098(char *, char *, char *);
extern void func_00282CC0(char *, char *, char *);
extern void func_0032C700(void *, void *, void *, void *, void *, int, int, void *,
                           float, float, int, int, int, int);
extern void func_00282CF0(float *, float *, float *);
extern void func_00282F20(float *, float *, float);
extern void func_002B0A68(char *, int, char *, float, float, float, float, int);
extern void func_0029F338(char *);

extern char D_L06_00189EA0[];

/* Gives the object its new direction, then lets it move. */
void func_L06_00443F30(char *a0)
{
    char *s1 = a0;
    char *s2 = a0 + 0x10;
    float v[4];
    float dir[4];
    float buf[4];

    func_002A6C58(a0, 0, 3);
    func_002E5CF8(1, 0, s1);
    *(TI128 *)dir = 0;
    dir[2] = 1.0f;
    func_00283098((char *)v, (char *)dir, s1 + 0xC0);
    func_00282CC0((char *)v, (char *)v, s2);
    func_0032C700(s2, 0, 0, 0, 0, 10, 20, 0, 0.333f, 20.0f, 1, 0, 0, 0);
    func_00282CF0((float *)buf, (float *)s2, (float *)D_L06_00189EA0);
    buf[2] = 0.0f;
    func_00282F20((float *)buf, (float *)buf, 0.10000000894069672f);
    func_002B0A68(s1, 0x1F, (char *)buf, 3.0f, 6.0f, 3.0f, 6.0f, 0xFF);
    func_0029F338(s1);
}
