/* func_00133700 - catalogue defect (wave 24, worker 02).
 *
 * The catalogue row for func_00133700 is 80 bytes at 0x00133700 and opens on the
 * linker's filler: two `addiu $sp,$sp,0x20; nop` pairs.  Those words are a stack restore and its
 * padding, not code - a function never starts with a stack restore - and
 * the row continues into the real function at 0x00133710, which is 64
 * bytes long.  The C below is that inner function; it cannot be matched
 * under the catalogue row because the row's first 16 bytes are the
 * filler.  This is the same defect family as func_L00_00304AE8 and
 * func_L00_00358670 in nonmatching/README.md: the extent opens on
 * `addiu $sp,$sp,N; nop`.  It needs a tools/levels.py split.
 *
 * tools/check.py func_00133700 --diff:
 *   boot: 60 bytes, expected 80
 *   func_00133700: 0 of 1 places match
 */

extern int D_001A7490 __attribute__((sda));
extern int func_001245D0(void);
extern int func_00132C48(int, int, void *);
extern void func_00132DF0(int, int, void *, int, int);

int func_00133700(int a0, int a1, int a2, int a3, int a4)
{
    int payload[4];
    payload[0] = a0;
    payload[1] = a1;
    payload[2] = a2;
    payload[3] = a3;
    func_00132DF0(0x50, 0x14, payload, 0, a4);
    return 0;
}
