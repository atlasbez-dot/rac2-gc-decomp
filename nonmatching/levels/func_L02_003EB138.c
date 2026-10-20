/* func_L02_003EB138 (288 bytes, level 2, src/levels/02_maktar_nebula/L02_003DB310.c; one $gp
 * access, so it belongs in the -g8 sibling L02_003DB310-g8.c, where this was compiled).
 *
 * NEAR MISS: 288 of 288 bytes, every instruction present and in retail's order of blocks and
 * branches (the bottom test closes with `bgezl` then `beql`, the `movn`, the `bnel` with `p++`
 * in its slot, `jal` + `nop`), but the callee-saved registers play different roles and the
 * prologue is permuted to match. tools/check.py: 0 of 1 places.
 *
 *   retail: s0=p  s1=a0  s2=result  s3=hi part of D_L02_001FC060  s4=a1
 *   ours:   s0=p  s1=a0  s2=result  s3=a1                         s4=hi part
 *
 * Retail copies the `lui` result into s3 last (`daddu $s3,$v0,$zero` in the delay slot of the
 * entry jump) and keeps the lui in $v0 while lo_sum writes $a0; we copy it right after the lui
 * (it is a GCSE reaching-register copy: "PRE: redundant insn ... reaching reg is 137"), so the
 * lo_sum reuses $v1 and the hoisted copy is saved in s4. Cause traced: the copy's pseudo has one
 * set and is live out of the block, so haifa-sched's adjust_priority (birthing_insn_p) raises it
 * to the block's maximum priority and it issues in cycle 2; and in the global allocator the
 * hi pseudo (refs 2, live_length 102) ranks after a1 (refs 2, live_length 49), where retail
 * ranks it before. Nothing in the source moved either.
 *
 * What was measured (cmp = instruction-by-instruction, immediates ignored):
 *   - this goto form, one exit label `done`:                 18 differing words
 *   - the same with `return result;` at four exits:          25 (also swaps s1/s2: result gets
 *     a higher allocation priority than a0 with more exits)
 *   - a structured `while (A && B && C && (D || E))`:        364 bytes (loop.c hoists 0xAAF, 0xFF,
 *     1 and the symbol parts into s5-s7/fp; retail has none of that, so retail's loop has no
 *     loop notes: it is written with gotos)
 *   - `do { ... test: ; } while (...)` entered by goto:      292 bytes, wrong branch shape
 *   - declaration/initialisation order of result, p, rec; table typed unsigned int, short *,
 *     char * or int: no change at all.
 * Not tried (would need a hint from retail's RTL): anything that gives the hi pseudo a second
 * set, or a second available `high D_L02_001FC060` occurrence.
 *
 * The body, with D_L02_001B35B8 a $gp symbol (`sda`) and D_L02_001B359C a plain extern (retail
 * reads it with lui/lw even in this -G8 unit):
 */
extern int D_L02_001B35B8 __attribute__((sda));
extern char *D_L02_001B359C;
extern unsigned int D_L02_001FC060[];
extern char D_00189E20[];
extern int func_002AD0B0(char *);
extern void func_002AD6F0(void *, void *, void *, void *);

int func_L02_003EB138(char *a0, void *a1) {
    int result = 0;
    short *p = (short *)D_L02_001FC060[*(unsigned char *)(a0 + 0x21)];
    char *rec;

    goto test;
body:
    rec = D_L02_001B359C + ((*(unsigned short *)p & 0x7FFF) << 8);
    if (rec == 0)
        goto done;
    if (*(short *)(rec + 0xAA) == 0xAAF) {
        char *g = D_00189E20;
        void *v;

        if (rec == *(char **)(g + 0x33C)) {
            if (*(int *)(g + 0x340) != 0)
                result = 1;
        }
        v = (void *)func_002AD0B0(rec);
        if (v != 0)
            func_002AD6F0(v, a1, a0 + 0xF0, a0 + 0xF0);
    }
    p++;
test:
    if (*(unsigned char *)(a0 + 0x21) == 0xFF)
        goto done;
    if (D_L02_001B35B8 < *(unsigned char *)(a0 + 0x21))
        goto done;
    if (p == 0)
        goto done;
    if (p[-1] >= 0)
        goto body;
    if (p == (short *)D_L02_001FC060[*(unsigned char *)(a0 + 0x21)])
        goto body;
done:
    return result;
}
