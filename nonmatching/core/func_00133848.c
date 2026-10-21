/* func_00133848 - catalogue defect (wave 24, worker 02).
 *
 * The catalogue row for func_00133848 is 68 bytes at 0x00133848 and opens on the
 * linker's filler: one `addiu $sp,$sp,0x10; nop` pair.  Those words are a stack restore and its
 * padding, not code - a function never starts with a stack restore - and
 * the row continues into the real function at 0x00133850, which is 60
 * bytes long.  The C below is that inner function; it cannot be matched
 * under the catalogue row because the row's first 8 bytes are the
 * filler.  This is the same defect family as func_L00_00304AE8 and
 * func_L00_00358670 in nonmatching/README.md: the extent opens on
 * `addiu $sp,$sp,N; nop`.  It needs a tools/levels.py split.
 *
 * tools/check.py func_00133848 --diff:
 *   boot: 60 bytes, expected 68
 *   func_00133848: 0 of 1 places match
 */

extern int D_001A7490 __attribute__((sda));
extern int func_001245D0(void);
extern int func_00132C48(int, int, void *);
extern void func_00132DF0(int, int, void *, int, int);

int func_00133848(int a0, int a1, int a2, int a3, int a4, int a5)
{
    int payload[6];
    payload[0] = a0;
    payload[1] = a1;
    payload[2] = a2;
    payload[3] = a3;
    payload[4] = a4;
    payload[5] = a5;
    return func_00132C48(0x3B, 0x18, payload);
}
