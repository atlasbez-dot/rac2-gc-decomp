/* func_001336C0 - catalogue defect (wave 24, worker 02).
 *
 * The catalogue row for func_001336C0 is 64 bytes at 0x001336C0 and opens on the
 * linker's filler: two `addiu $sp,$sp,0x10; nop` pairs.  Those words are a stack restore and its
 * padding, not code - a function never starts with a stack restore - and
 * the row continues into the real function at 0x001336D0, which is 48
 * bytes long.  The C below is that inner function; it cannot be matched
 * under the catalogue row because the row's first 16 bytes are the
 * filler.  This is the same defect family as func_L00_00304AE8 and
 * func_L00_00358670 in nonmatching/README.md: the extent opens on
 * `addiu $sp,$sp,N; nop`.  It needs a tools/levels.py split.
 *
 * tools/check.py func_001336C0 --diff:
 *   boot: 44 bytes, expected 64
 *   func_001336C0: 0 of 1 places match
 */

extern int D_001A7490 __attribute__((sda));
extern int func_001245D0(void);
extern int func_00132C48(int, int, void *);
extern void func_00132DF0(int, int, void *, int, int);

int func_001336C0(int a0)
{
    D_001A7490 = a0;
    if (D_001A748C == 0) {
        func_001245D0();
    }
    return D_001A7490;
}
