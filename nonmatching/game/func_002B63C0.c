/* Near miss for func_002B63C0 (boot 0x002B63C0, 188 bytes, 23 places).
 *
 * tools/check.py func_002B63C0: 0 of 23 places match - every place reports
 * "instruction at +0x74 differs" (the same single word).
 *
 * Everything else matches byte for byte: the frame (0x20), the four saved
 * registers, the two float comparisons, the two calls, the global read at
 * -0x6350($gp) and the branch-likely join.
 *
 * The one word that differs is the branch out of the first path:
 *
 *   retail  002B6434  b . + 4 + (0x7 << 2)   -> 0x002B6454
 *   this    002B6434  b . + 4 + (0x8 << 2)   -> 0x002B6458
 *
 * Both branches land on the same block (the compare at 0x002B6450, the
 * interlock nop at 0x002B6454, the bc1tl at 0x002B6458), so the code is
 * equivalent; only the branch offset differs.  The cause is where the label
 * that the branch targets sits: the assembler emits the interlock nop of a
 * COP1 compare *before* the label that follows the compare, so the label
 * lands on the bc1tl, while the retail has the label in front of the nop.
 * The compiler emits no nop of its own there (the compare and the branch are
 * in different blocks, and the reconstruction only inserts the explicit nop
 * when they are in the same block).
 *
 * What was tried: the shape of the two paths (the comparison inside each
 * branch, so the two compare blocks stay separate and the branches merge),
 * the flag kept in a callee-saved register (the zero is set before the call,
 * so the flag is live across it), the "if (f < x) s2 = 1;" spelling (the
 * empty then-arm inverts the branch in this compiler, see the note below),
 * the __attribute__((sda)) global, and the call to the float helper as the
 * source of the compared value.
 *
 * Note on the compiler: with an empty branch arm this compiler emits the
 * branch with the opposite sense - "if (c) { } else { x = 1; }" and
 * "if (c) { x = 1; } else { }" produce "bc1fl" and "bc1tl" respectively, and
 * the assignment ends up in the other arm than the source says.  The
 * measured pair is in work/pol.c and work/pol2.c; the SDK compiler
 * (build/compiler/sdk) behaves the same way, so it is a property of the
 * compiler, not of this file.
 */

extern void *func_002AB220(void *);
extern float func_002B0360(void *);
extern int D_001A8CA0 __attribute__((sda));

/* Compares the object's float at 0x18 with the partner's float at 0x90 and, when the
   object is still smaller, with the found object's float at 0x40 less half; the
   float that is compared comes from the helper at 0x10 when the resident flag is
   set and from the object itself otherwise. */
int func_002B63C0(void *a0, void *a1)
{
    void *s0;
    int s2;
    float f;

    if (*(float *)((char *)a0 + 0x18) <= *(float *)((char *)a1 + 0x90)) {
        return 0;
    }
    s0 = func_002AB220(a0);
    if (s0 == 0) {
        return 0;
    }
    s2 = 0;
    if (D_001A8CA0 != 0) {
        f = func_002B0360((char *)a0 + 0x10);
        if (f < *(float *)((char *)s0 + 0x40) - 0.5f) {
            s2 = 1;
        }
    } else {
        f = *(float *)((char *)a0 + 0x18);
        if (f < *(float *)((char *)s0 + 0x40) - 0.5f) {
            s2 = 1;
        }
    }
    return s2;
}
