/* func_L00_003BCDC0 (100 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * Docker-free ruler (scratch/wslcmp.py): the body is now the retail's 100 bytes and
 * every instruction matches except the branch that skips the call.
 *
 * What is now right (the previous record's two points are fixed):
 *   - the walk is a do-while over an `int` holding the byte address: retail compares
 *     with the signed `slt $v0,$s0,$s2`, and an int loop variable gives that; a char*
 *     loop variable gives `sltu`;
 *   - the base is materialised first (`lui $v0,0x24 ; addiu $s0,$v0,-0xFA0`) and the
 *     limit is derived from it (`addiu $s2,$s0,0xB00`), so the source assigns the base
 *     to the loop variable before it computes the limit; a limit written as a constant
 *     expression makes this cc1 materialise `base+0xB00` first and derive the base
 *     from it;
 *   - retail has no loop precondition test, so the source is a do-while.
 *
 * What still differs: retail's branch that skips the call is an annulled `bnel
 * $v0,$s1,+5` whose delay slot holds the increment (`addiu $s0,$s0,0xB0`), and the
 * call's two arguments are computed after it (`daddu $a0,$s1,$zero` in the branch's
 * fall-through, `daddu $a1,$s0,$zero` in the jal's delay slot). This cc1 emits a plain
 * `bne` and hoists `daddu $a1,$s0,$zero` and the increment above the branch.
 *
 * The annulled branch is the reorg pass's "likely" decision (reorg.c, mostly_true_jump):
 * it needs a code label in front of the delay slot, and the retail's one is there. The
 * EXPECT annotation (__builtin_expect) cannot be the source of it: condjump_expect_p
 * only accepts a comparison against a constant, while retail compares two registers.
 *
 * To retake: a source form whose flow graph marks the "no match" edge as the likely
 * one, so the branch that skips the call is emitted as `bnel` and the increment moves
 * into its delay slot. Tried: int and char* loop variables, a do-while and a for with
 * a precondition test, __builtin_expect(compare,0) and (compare,1) on both the == and
 * the != form, the increment inside and outside the if, -frac2-keep-block-order,
 * -fcse-skip-blocks and -fbranch-count-reg.
 */

extern char D_0023F060[];

extern void func_L00_003BCE28(char *a0, char *a1);

void func_L00_003BCDC0(char *a0)
{
    int p;
    int end;

    p = (int)D_0023F060;
    end = p + 0xB00;
    do {
        if (*(int *)(p + 0xA0) == (int)a0) {
            func_L00_003BCE28(a0, (char *)p);
        }
        p += 0xB0;
    } while (p < end);
}
