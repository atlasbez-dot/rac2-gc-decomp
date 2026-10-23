/* func_L00_003B0AB0 - NON MATCHEE (wave 8, agent w8-09).
 *
 * Nearest: 26 of 27 instructions byte-identical and size exact (108).
 * Last line of tools/check.py: "00_aranos_tutorial: instruction at +0x48 differs"
 *
 * The only difference is the operand order of the branch: retail compares the
 * loaded tag in $v0 with the index in $a2 (`bnel $v0,$a2`), this cc1 compares
 * the index in $a2 with the tag in $v0 (`bnel $a2,$v0`).  Everything else -
 * `andi $a2,$a0,0xFF`, the three-operand `mult $v1,$a2,$v1` (the R5900
 * three-register multiply: $v1 = index * 0x1C), the four absolute
 * materialisations of 0x0023BB78 and the call to func_32FC10 with
 * (object, &object->f20, index) - reproduces.
 *
 * Measured: this cc1 emits the comparison in source order and gives the
 * first operand of the comparison the $a2 argument register.  So
 *
 *   - `c == s->f17`  -> index in $a2, tag in $v0, branch `bnel $a2,$v0`
 *                       (the registers are right, the branch order is not);
 *   - `s->f17 == c`  -> tag in $a2, index in $a3, branch `bnel $a2,$a3`
 *                       (the branch order is right, the registers are not, and
 *                       the call then passes the tag in $a2 instead of the
 *                       index, so the body is also wrong).
 *
 * The `&&` spelling, the byte-pointer spelling of the tag, a local copy of the
 * tag, a prototyped callee and the natural order all give the same two
 * results.  The blocker is the allocator, not the spelling: the index has to
 * stay in $a2 (it is the third call argument) while the comparison has to name
 * the tag first.
 */

typedef struct SUB_3B0AB0 {
    char pad0[0x17];
    unsigned char f17;
} SUB_3B0AB0;

typedef struct OBJ_3B0AB0 {
    long f0;
    char pad0[0x20 - 8];
    SUB_3B0AB0 s20;
} OBJ_3B0AB0;

extern char D_L00_0023BB78[];

extern void func_32FC10();

void func_L00_003B0AB0(int idx)
{
    unsigned char c = idx;
    char *base = D_L00_0023BB78;
    char *at = base + 0x10;
    char *slot = at + (unsigned char)idx * 0x1C;
    OBJ_3B0AB0 *obj = *(OBJ_3B0AB0 **)slot;

    if (obj != 0) {
        SUB_3B0AB0 *s = &obj->s20;

        if ((obj->f0 & 0x80FF) == 0x51)
            if (c == s->f17) {
                func_32FC10(obj, s, c);
                *(OBJ_3B0AB0 **)slot = 0;
            }
    }
}
