/* Near miss for func_002C5068 (boot 0x002C5068, 180 bytes, 28 places).
 *
 * The catalogue row is eight bytes too long at the front: the extent opens
 * with
 *
 *   002C5068  addiu $sp, $sp, 0x30
 *   002C506C  nop
 *
 * and the real function starts at 0x002C5070 with its own frame setup
 * ("addiu $sp, $sp, -0x30").  The eight bytes are a frame *restore* at a
 * function's entry, which no compiler emits, and they are not the previous
 * function's epilogue either (func_002C5020 ends at 0x002C5064 with
 * "jr $ra ; addiu $sp, $sp, 0x10" in its delay slot).  The same eight bytes
 * stand in the boot and in every level copy, so they are not the linker's
 * alignment of one program.  The same class of bytes fills the rows the first
 * wave found to be residues (e.g. func_002ED8F0: several frame restores in a
 * row and a 0xCDCDCDCD word).
 *
 * The body itself is ordinary C and this C matches it byte for byte:
 * the candidate is 172 bytes and every word of the retail's 0x002C5070..
 * 0x002C511B is the same (the call words differ only in the relocation, which
 * the object does not carry).  Measured with work/side2.py:
 *
 *   python3 work/side2.py func_002C5068 0x8
 *   func_002C5068: candidate 172 bytes, retail 172 bytes from 0x2c5070
 *   differing words: 6 of 43        (the six jal words, unrelocated)
 *
 * So a tools/levels.py correction that moves the start of this row by eight
 * bytes (the pattern LEVEL_ENTRY_OFFSETS already has for the levels) turns it
 * into a match at once.  The same is to be expected of the other rows that
 * open on the group: func_002C64D8, func_002C29A0, func_002C01F8,
 * func_002C00F0, func_002C43C8 and func_002C7620.
 *
 * What was measured to get the body:
 *  * the 16-byte copy of the quad at 0x20 needs the mode(TI) vector type
 *    (V4_Fc3cb9262), as in the matched func_002C2658 and func_002C7538;
 *  * the two scales are 38.0f (0x42180000) and 33.0f (0x42040000);
 *  * the word at 4 holds the first helper's result shifted left by 24 and or'd
 *    with 0x808080, and it is stored in the delay slot of the second helper
 *    call, so the source stores it before that call;
 *  * the byte at 8 holds the second helper's result and is stored before the
 *    call of func_00282CC0, which is where the retail has it;
 *  * the clear of the copy's fourth float and the division: the source has
 *    the clear before the division, and the scheduler then puts the clear in
 *    the delay slot of the helper call, as the retail has it.  With the clear
 *    after the call in the source, the compiler sinks the load of the float
 *    into the delay slot instead and the two differ.
 */

extern float func_00283CE0_2(int v);
extern int func_00283CF0_6(float f);
extern void func_00282CC0_17(char *dst, char *src, char *vec);
extern int func_00282978_9(char *p);
extern void func_002B9180_13(char *self);

typedef int V4_Fc3cb9262 __attribute__((mode(TI)));

/* The particle update: the quad at 0x20 is copied to the stack, the value of
   the helper at 0xA is divided by the copy's fourth float, the two scaled
   results are packed into the word at 4 and the byte at 8. */
void func_002C5068(char *self)
{
    V4_Fc3cb9262 vec;
    float f3;
    float f21;
    int v;

    vec = *(V4_Fc3cb9262 *)(self + 0x20);
    f3 = ((float *)&vec)[3];
    ((float *)&vec)[3] = 0.0f;
    f21 = func_00283CE0_2(*(short *)(self + 0xA)) / f3;
    v = func_00283CF0_6(f21 * 38.0f);
    *(int *)(self + 4) = (v << 24) | 0x808080;
    v = func_00283CF0_6(f21 * 33.0f);
    *(char *)(self + 8) = (char)v;
    func_00282CC0_17(self + 0x10, self + 0x10, (char *)&vec);
    if (func_00282978_9(self + 0xA) != 0) {
        func_002B9180_13(self);
    }
}
