/* Near miss: func_0029B0B0 (184 bytes in every program), FillSaveSlotInfo.
 *
 * The function fills one entry of the save-slot table with fields read out of
 * a save header.  What the retail bytes say:
 *
 *  - the table is at 0x0013F3E0, the stride of a slot is 0xA0 and the stride
 *    of a directory inside a slot is 0x1C (the slot entry is
 *    0x0013F3E0 + slot * 0xA0 + dir * 0x1C);
 *  - the header passed in a0 is read at +0x10 (int), +0x1C (int), +0x2E
 *    (byte), +0x64 (int) and +0x70 (16 bytes);
 *  - the entry receives them at +0x30, +0x34, +0x38, +0x3C and +0x40, and
 *    the flag "func_0029AF58(a0) == 0" at +0x48;
 *  - the 16 bytes are copied with one R5900 unaligned 16-byte idiom
 *    (ldl/ldr + sdl/sdr).
 *
 * The C below is right about all of that but comes out 192 bytes: this cc1
 * copies a 16-byte aggregate as two 8-byte unaligned copies (eight
 * instructions) where retail uses one 16-byte copy (four instructions), and
 * it does not reproduce retail's register allocation (retail keeps the
 * header pointer and the index in $s0/$s1/$s2 and copies the entry pointer
 * into four argument registers before the first store).
 *
 * Measured: a `mode(TI)` copy through a TI16* gives lq/sq (the compiler
 * takes the cast's 16-byte alignment), a packed struct holding a mode(TI)
 * member gives uld/por/usd, and every 16-byte aggregate (int[4], float[4],
 * packed, char[16], memcpy) gives the two 8-byte ldl/ldr copies.  The single
 * 16-byte unaligned copy is not reachable from C with this compiler.
 */
extern char D_0013F3E0[];

extern int func_0029AF58(char *p);

typedef struct { int a, b, c, d; } Quad;

void func_0029B0B0(int a0, int a1, int a2)
{
    char *src = (char *)a0;
    int flag = func_0029AF58(src);
    char *rec = (char *)D_0013F3E0 + a1 * 0xA0 + a2 * 0x1C;
    int *f1 = (int *)(rec + 0x30);
    int *f2 = (int *)(rec + 0x34);
    int *f3 = (int *)(rec + 0x38);
    int *f4 = (int *)(rec + 0x3C);

    *(int *)(rec + 0x48) = flag == 0;
    *f1 = *(int *)(src + 0x10);
    *f2 = *(int *)(src + 0x1C);
    *f3 = *(unsigned char *)(src + 0x2E);
    *f4 = *(int *)(src + 0x64);
    *(Quad *)(rec + 0x40) = *(Quad *)(src + 0x70);
}
