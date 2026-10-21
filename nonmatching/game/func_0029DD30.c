/* func_0029DD30 - near miss (wave 2, worker 5).
 *
 * The retail body (boot 0x0029DD30, 140 bytes; the same code is in the 27 levels):
 *
 *   lui $v0,0x14 ; daddu $a1,$v0,$zero ; addiu $v0,$v0,-0x6A48
 *   lbu $v1,0x1D($v0)                    ; the byte at 0x001395D5, read twice
 *   bnez $v1, C
 *     lui $a0,0x14
 *   addiu $v0,$a0,-0x6898 ; lw $v1,0x5C($v0)   ; the word at 0x001397C4, read three times
 *   bltzl $v1, C
 *     addiu $v0,$a1,-0x6A48
 *   addiu $v0,$zero,0x1F ; lui $v1,%hi(S) ; sh $v0,%lo(S)($v1) ; jr $ra ; return 0
 *   C: addiu $v0,$a1,-0x6A48 ; lbu $v1,0x1D($v0)
 *      beqz $v1, E
 *        addiu $v0,$a0,-0x6898
 *      lw $v1,0x5C($v0) ; bltz $v1, G
 *      addiu $v0,$zero,0x20 ; lui $v1,%hi(S) ; sh $v0,%lo(S)($v1) ; jr $ra ; return 1
 *      E: lw $v1,0x5C($v0) ; bgez $v1, G
 *         addiu $v0,$zero,0x1F ; lui $v1,%hi(S) ; sh $v0,%lo(S)($v1) ; jr $ra ; return 2
 *      G: jr $ra ; return 0
 *
 * Recovered:
 *   - the byte at 0x001395D5 and the word at 0x001397C4 are read through volatile
 *     pointers: the retail loads them twice and three times and never merges the
 *     loads, so the source reads them again each time;
 *   - the halfword that is stored (0x00257582 in the boot, 0x0027FFC2 in level 00)
 *     differs from program to program, so it is named ref_L00_0030EDB0_00.  In a
 *     -G8 unit the symbol must be declared as an array (an object of a known size
 *     would become small data and the store would come out as `sh $v0,0($gp)`);
 *   - the control flow is the `&&` spelling below: it gives the retail's size
 *     (140 bytes) and its block structure.
 *
 * What still differs (the compiled body is the right size, the branch structure
 * and the stores are the retail's, but these instructions differ):
 *   - the retail keeps the high half of an address in a register and adds the low
 *     half again at every use (`daddu $a1,$v0,$zero` ; `addiu $v0,$a1,-0x6A48`),
 *     where this compiler keeps the whole address in one register and reuses it;
 *   - the retail materialises the second address late (in the delay slot of the
 *     first branch), this compiler hoists both to the top;
 *   - the registers follow from those two points.
 *
 * The split form needs the "symbol + offset" spelling (`(D_00140000 - 0x6A48)`),
 * which this compiler does produce (work/c_dd30e.c), but tools/build.py reads the
 * value of a symbol from the %hi/%lo pair of the retail bytes, so it would give
 * that symbol the address *with* the offset (0x001395B8) instead of its own
 * (0x00140000) and the linker would then place it wrongly.  The build's
 * derivation cannot express a symbol whose address is used with an offset.
 *
 * The two data addresses can also be read as one symbol at 0x00140000 with the
 * offsets -0x6A48 and -0x6898; that is the form the retail's %hi (0x14 in both
 * uses) shows.
 */
extern char D_001395B8[];
extern char D_00139768[];
extern unsigned short ref_L00_0030EDB0_00[];

typedef struct {
    unsigned char pad[0x1D];
    volatile unsigned char v;
} Flag_29DD30;

typedef struct {
    unsigned char pad[0x5C];
    volatile int v;
} Word_29DD30;

int func_0029DD30(void)
{
    Flag_29DD30 *f = (Flag_29DD30 *)D_001395B8;
    Word_29DD30 *w = (Word_29DD30 *)D_00139768;

    if (f->v == 0 && w->v >= 0) {
        ref_L00_0030EDB0_00[0] = 0x1F;
        return 0;
    }
    if (f->v == 0) {
        if (w->v >= 0)
            return 0;
        ref_L00_0030EDB0_00[0] = 0x1F;
        return 2;
    }
    if (w->v < 0)
        return 0;
    ref_L00_0030EDB0_00[0] = 0x20;
    return 1;
}
