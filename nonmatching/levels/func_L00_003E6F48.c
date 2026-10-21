/* func_L00_003E6F48 - NOT MATCHED, best attempt - 124 bytes expected, 27 places.
 * last check.py line: "func_L00_003E6F48: 0 of 27 places match (src/levels/shared/L00_003E3258-g8.c)"
 * with "00_aranos_tutorial: instruction at +0x2c differs" - the body is the exact
 * 124 bytes of the retail.
 *
 * The body needs a -G8 unit: the retail reloads the table pointer through $gp
 * (lw $v0, 0x3B64($gp)) at the back edge, so the function belongs in the
 * L00_003E3258-g8.c sibling, and it needs the two names of the table pointer
 * (one absolute for the first read, one with __attribute__((sda)) for the
 * reload). With that the prologue, the loop, the branch-likely back edge and the
 * reload all match. What is left:
 *
 *   retail: sll $v1, $s0, 7 ; addiu $s0, $s0, 0x1 ; addu $v1, $v1, $v0
 *   ours:   sll $v1, $s0, 7 ; addiu $a3, $zero, 0x2E ; addu $v0, $v0, $v1
 *
 * retail keeps the table pointer in $v0 and writes the record pointer into $v1
 * (the register of the scaled index); this compiler reuses the table pointer's
 * register for the record pointer (the table pointer is dead after the first
 * iteration because it is read again at the back edge) and puts the index
 * increment later. Measured: the same for every spelling of the addition
 * (base + (i << 7), (i << 7) + base, base + i * 128, the offset in a variable,
 * an integer addition, a typed pointer, a for loop, a while loop, the table
 * pointer read inside the loop) - the commutative add is always emitted with the
 * table pointer first, so the destination register cannot be moved.
 */

extern char *D_L00_001B2B54;

extern char *D_L00_001B2B54_1 __attribute__((sda));

extern void func_L00_003E70B8(char *rec, int a, int b, int c, float d, float e, float f, int g);

void func_L00_003E6F48(char *rec)
{
    int i;
    char *base;
    char *p;

    i = 0;
    do {
        base = D_L00_001B2B54;
        p = base + (i << 7);
        i++;
        if (*(char **)(p + 0x7C) == rec)
            func_L00_003E70B8(p, *(int *)(p + 0x68), *(int *)(p + 0x60), 46,
                              *(float *)(p + 0x48), *(float *)(p + 0x34), 0.25f, *(int *)(p + 0x70));
        base = D_L00_001B2B54_1;
    } while (i < 320);
}
