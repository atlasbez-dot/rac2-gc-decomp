/* func_L09_00406BF8, 108 bytes, 1 placement (level 9).  Best candidate 112 bytes against
   retail's 108 (frame 0x20 in both, this one saves $s2 as well).
   Retail keeps the outgoing kind in $a1 - it never spills it - and reaches the `kind = 2`
   arm with `beqz $v0` plus a `b`; this cc1 spills both locals ($s1 = kind, $s2 = ret) and
   turns the test into `beql` with `addiu $s1,$zero,0x2` in the annulled slot (the same
   annulled-slot idiom the README records for func_L12_00427C58 / func_L05_0037BB28).
   The body: */

typedef unsigned char u8;
typedef signed int s32;

extern char D_L09_00189EA0[];
extern s32 func_325E78(char *a0, s32 a1);
extern void func_L09_00406BA0(s32 a0, u8 a1);

s32 func_L09_00406BF8(s32 a0, s32 a1) {
    s32 ret = 0;
    s32 kind = 0;

    if (a0 != -1) {
        if (func_325E78(D_L09_00189EA0, a0) != 0) {
            ret = 1;
        } else {
            kind = 2;
        }
    }
    func_L09_00406BA0(a1, kind);
    return ret;
}

/* Measured again (wave 24, worker 10).  The blocker is the live range of the
   "kind" value, not its spelling.  Retail keeps it in $a1 - the outgoing
   argument register of the final call - and never spills it, while $s0 holds
   the returned value and $s1 the second argument; that is only possible if the
   value is NOT live across the call to func_325E78, since $a1 is
   caller-clobbered.  The earlier attempt assigns kind = 0 before the call, so
   the value is live across it and this cc1 spills it ($s1) - one saved
   register too many, 112 bytes against retail's 108.  Assigning the kind only
   after the call (kind = 0 in the "call returned non-zero" arm, kind = 2 in
   the other, kind = 0 for a0 == -1) does put the kind in $a1 and gives
   retail's three saved registers ($s0, $s1, $ra), but the body is then 25
   instructions against retail's 27: retail materialises the "kind = 0" of the
   a0 == -1 path BEFORE the first branch (daddu $a1,$zero,$zero, so that path
   jumps straight to the final call) and keeps the "kind = 2" arm in a block
   of its own (addiu $a1,$zero,0x2) behind a `b`, while this cc1 puts the
   kind = 2 in the delay slot and the kind = 0 of the a0 == -1 path in its own
   block.  Twelve spellings measured (the kinds as s32 and u8, the argument as
   s32 and u8, the ret taken from the call and normalised, else-first and
   then-first, an explicit else arm, the goto form, a nested else): all give
   either 28 instructions with the kind spilled or 25 with the layout above. */
