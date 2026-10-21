/* func_001337C8 - catalogue defect (wave 24, worker 02).
 *
 * The catalogue row for func_001337C8 is 76 bytes at 0x001337C8 and opens on the
 * linker's filler: five `addiu $sp,$sp,0x10/0x20; nop` pairs.  Those words are a stack restore and its
 * padding, not code - a function never starts with a stack restore - and
 * the row continues into the real function at 0x001337F0, which is 36
 * bytes long.  The C below is that inner function; it cannot be matched
 * under the catalogue row because the row's first 40 bytes are the
 * filler.  This is the same defect family as func_L00_00304AE8 and
 * func_L00_00358670 in nonmatching/README.md: the extent opens on
 * `addiu $sp,$sp,N; nop`.  It needs a tools/levels.py split.
 *
 * tools/check.py func_001337C8 --diff:
 *   boot: 36 bytes, expected 76
 *   func_001337C8: 0 of 1 places match
 */

extern int D_001A7490 __attribute__((sda));
extern int func_001245D0(void);
extern int func_00132C48(int, int, void *);
extern void func_00132DF0(int, int, void *, int, int);

int func_001337C8(void)
{
    return func_00132C48(0x4A, 0, 0);
}
