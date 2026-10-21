/* Best attempt, wave 14 w8. Last check.py line:
   func_L06_003E4FA0: 0 of 5 places match (src/levels/shared/L06_0035EA68.c)
   retail 220 bytes, produced 220: the size, the prologue, the two early exits, the
   whole seven-iteration loop (the branch-likely back edge, its delay slot, the
   counter decrement between the two calls) and the epilogue are exact.  Only the
   order of the five loop-invariant setups differs, and the two self offsets swap
   their callee-saved registers with it:
     retail  addiu $s4,$a2,0x10 ; addiu $s2,$v0,-0x1090 ; addiu $s0,$v1,0x10
             addiu $s3,$a2,0xC0 ; addiu $s1,$zero,0x6
     here    addiu $s0,$v1,0x10 ; addiu $s2,$v0,0x0   ; addiu $s4,$a2,0x10
             addiu $s1,$zero,0x6 ; addiu $s3,$a2,0xC0
   The order is the compiler's, not the source's: sixteen spellings of the four
   assignments before the loop (each permutation, the offsets hoisted into
   variables, a do-while with the decrement in the body) all give the order
   above.  The retail's order needs self+0x10 to be computed first and to take
   the higher register, which no source order reached.
   The two level data addresses are level 06's: D_L06_001E500 (the table of
   entries), D_L06_0029EF70 (the source table) and D_L06_00199E20 (the index
   table; the entry written is at +0x24FE, and a struct member is the spelling
   that gives retail's lui+addiu+sh instead of the split form). */

extern void func_32DA88(void *, void *, void *);
extern void func_32D5C8(void *, void *, void *);
extern char *D_L06_001E500[];
extern char D_L06_0029EF70[];

/* The level's table of slot indices; the entry the function stores is at +0x24FE. */
typedef struct {
    char pad_00[0x24FE];
    unsigned short value_24FE;
} L06Table_00199E20;

extern L06Table_00199E20 D_L06_00199E20;

/* Walks the seven entries of the owner's table, scaling each of them by the
   owner's own transform, and stores the slot index in the level's table. */
void func_L06_003E4FA0(char *self)
{
    char *ctx;
    char *entry;
    char *base;
    char *src;
    int idx;
    int i;

    ctx = *(char **)(self + 0x68);
    idx = *(int *)(ctx + 0xF8);
    if (idx == -1)
        return;
    entry = D_L06_001E500[idx];
    if (*(int *)entry != 7)
        return;
    base = entry + 0x10;
    src = D_L06_0029EF70;
    for (i = 6; i >= 0; i--) {
        func_32DA88(base, src, self + 0xC0);
        src += 0x10;
        func_32D5C8(base, base, self + 0x10);
        base += 0x10;
    }
    D_L06_00199E20.value_24FE = *(unsigned short *)(ctx + 0xF8);
}
