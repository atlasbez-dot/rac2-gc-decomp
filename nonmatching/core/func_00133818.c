/* func_00133818 - catalogue defect (wave 24, worker 02).
 *
 * The catalogue row for func_00133818 is 44 bytes at 0x00133818 and opens on the
 * linker's filler: one `addiu $sp,$sp,0x10; nop` pair.  Those words are a stack restore and its
 * padding, not code - a function never starts with a stack restore - and
 * the row continues into the real function at 0x00133820, which is 36
 * bytes long.  The C below is that inner function; it cannot be matched
 * under the catalogue row because the row's first 8 bytes are the
 * filler.  This is the same defect family as func_L00_00304AE8 and
 * func_L00_00358670 in nonmatching/README.md: the extent opens on
 * `addiu $sp,$sp,N; nop`.  It needs a tools/levels.py split.
 *
 * tools/check.py func_00133818 --diff:
 *   boot: 36 bytes, expected 44
 *   func_00133818: 0 of 1 places match
 */

extern int D_001A7490 __attribute__((sda));
extern int func_001245D0(void);
extern int func_00132C48(int, int, void *);
extern void func_00132DF0(int, int, void *, int, int);

int func_00133818(void)
{
    return func_00132C48(0x4B, 0, 0);
}
