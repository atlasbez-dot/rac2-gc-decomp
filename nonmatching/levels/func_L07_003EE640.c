/* Draft for func_L07_003EE640 (200 bytes, 07_siberius).
 *
 * State: 200 bytes (exact size) with every instruction equal to retail except
 * the five-instruction loop preheader at +0x54..+0x64, which comes out in the
 * order [q = o][p = o + 8][i = 7][-1][D_00189EA0] where retail has
 * [q = o][-1][D_00189EA0][p = q + 8][i = 7].
 * check.py says: "instruction at +0x54 differs".
 *
 * Other attempts (kept here so the next worker does not repeat them):
 *   - indexing the object as o[15 - i] / o[8 - i] with a countdown i: the loop
 *     shape changes completely (184 bytes, counter in $s1, addresses as
 *     -0x1C/-0x20($s0)).
 *   - hoisting the -1 and the D_00189EA0 address into locals `none` and `tbl`
 *     assigned in retail's order: drops $s4, 184 bytes.
 */

extern void func_002A7750(int, int, int);

extern int func_002ACBC8(int, int);

extern void func_L02_0031F858(int, int);

extern char D_00189EA0[];

void func_L07_003EE640(char *arg)
{
    int *o = *(int **)(arg + 104);
    int *p;
    int *q;
    int i;

    switch (*(unsigned char *)(arg + 0x20)) {
    case 0:
        func_002A7750(arg, 1, -1);
        break;
    case 1:
        p = o + 8;
        q = o;
        for (i = 7; i >= 0; i--) {
            if (*p != -1) {
                if (func_002ACBC8((int)D_00189EA0, *q) != 0) {
                    func_L02_0031F858(*p, 1);
                    *p = -1;
                }
            }
            q++;
            p++;
        }
        break;
    }
}

/* Second attempt (wave 24, worker 15): re-measured with the catalogue names
   (func_002A7750, func_002ACBC8, func_L02_0031F858 are the retail's
   f_003109C8, f_00316808 and f_00311B80 at level 07 - the names matter, the
   addresses are per level).
   check.py (07_siberius): "07_siberius: instruction at +0x54 differs", the
   same line and the same five-instruction loop preheader as above: this cc1
   hoists the -1 and the D_00189EA0 address ahead of `p = o + 8` and the loop
   counter, retail keeps them behind.  Tried again and identical: the two
   pointers assigned the other way round (that restructures the loop and
   drops to 184 bytes), the -1 in a named local (212 bytes), the table
   address in a named local, and the loop as a for over a counted index.
   */
