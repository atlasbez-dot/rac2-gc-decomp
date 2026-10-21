/* func_L06_00457920 (168 bytes) -- ABANDON (172 bytes; LICM wall).
 * retail materialises the constant argument address INSIDE the loop
 *   lui t2,0x1B ; addiu t2,t2,-0x70E0   (D_L06_001A8F20)
 * and hoists only the function pointer into $s3:
 *   lui v0,0x45 ; addiu s3,v0,0x79C8    (func_L06_004579C8)
 * gcc hoists the address constant too (into $s3, with the pointer in $s4),
 * which shifts the whole frame and adds one instruction, and it also fills the
 * loop back-edge delay slot with a hoisted `lh a2,0xAA(s1)` (bnel) instead of
 * the retail plain `bnez`. Tried both `for` and `do { } while` loop shapes.
 *
 * A later attempt (wave 24, worker 14) got the loop itself to match
 * instruction for instruction and is still 8 bytes over: see below.
 */

extern char *func_31B0D0(char *, int, int, int, float, float, char *, char *, char *, int);
extern void func_32D8A8(char *, char *);
extern void func_L06_004579C8(void);

void func_L06_00457920(char *a0)
{
    int i;

    for (i = 0; i < 0xF; i++) {
        char *p = func_31B0D0(a0, 2, *(short *)(a0 + 0xAA), i, 0.0f, 10.0f,
                             a0 + 0x10, a0 + 0xF0, D_L06_001A9020, 0xFF);

        if (p != 0) {
            char *q = *(char **)(p + 0x68);

            func_32D8A8(q, q + 0x20);
            *(char **)(p + 0x64) = (char *)func_L06_004579C8;
        }
    }
}

/* ---------------------------------------------------------------------------
 * wave 24, worker 14: the loop now matches instruction for instruction, and the
 * body below is 176 bytes against retail's 168; check.py: "176 bytes, expected
 * 168".  What matches: the frame (0x30), the saves of $s0-$s3 and $ra, the call
 * to func_31B0D0 with its ten arguments ($a0=the object, $a1=2, $a2=the halfword
 * at +0xAA, $a3=the counter, $f12=0.0f, $f13=10.0f, $t0=object+0x10,
 * $t1=object+0xF0, $t2=&D_L06_001A8F20, $t3=0xFF), the 0.002f argument of
 * func_32D8A8, the `sw $s3,0x64($s0)` of the callback's address, the
 * `slti $v0,$s2,0xF` test and the `addiu $s2,$s2,0x1` in the beqz delay slot.
 * What differs is one pair of instructions in the prologue.  Retail materialises
 * the callback's address once, in the prologue (`lui $v0,%hi(f_004579C8)` ;
 * `addiu $s3,$v0,%lo(f_004579C8)`), and materialises the table's address inside
 * the loop (`lui $t2,%hi(D_001A8F20)` ; `addiu $t2,$t2,%lo(D_001A8F20)`).  This
 * cc1 hoists the table's %hi out of the loop into a fifth saved register ($s3)
 * and adds the %lo inside the loop (`addiu $t2,$s3,%lo(D)`), which costs the
 * extra `lui $s3` and the extra save/restore of $s4: 8 bytes more than retail.
 * The hoisting is the loop optimiser's invariant motion: the %hi is a plain
 * register set and moving it is profitable (threshold = 1 + n_non_fixed_regs,
 * against the loop's insn count), while the %lo is a LO_SUM, which is not
 * offsettable and stays.  Retail's compiler did not move it.
 * Tried: the callback's address in a local (unsigned int, and a function
 * pointer), the table's address in a local inside the loop, a `for` loop instead
 * of the do-while, the object pointer used directly instead of a copy, and the
 * callback's address used inline.  All give the same eight bytes.
 * What would unblock it: a spelling that keeps the table's %hi inside the loop.
 */

extern void func_32D8A8(char *, char *, float);

extern char D_L06_001A8F20[];

extern void func_L06_004579C8(char *);

/* Spawns the fifteen particles of the object's burst, one per frame slot. */
void func_L06_00457920_w24(char *a0)
{
    char *s1 = a0;
    char *p;
    int i = 0;

    do {
        p = func_31B0D0(s1, 2, *(short *)(s1 + 0xAA), i, 0.0f, 10.0f, s1 + 0x10,
                        s1 + 0xF0, D_L06_001A8F20, 0xFF);
        if (p) {
            char *st = *(char **)(p + 0x68);

            func_32D8A8(st, st + 0x20, 0.002f);
            *(unsigned int *)(p + 0x64) = (unsigned int)func_L06_004579C8;
        }
        i++;
    } while (i < 15);
}
