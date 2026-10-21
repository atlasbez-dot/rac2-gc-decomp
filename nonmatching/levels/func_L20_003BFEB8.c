/* Near miss from src/levels/20_yeedil/L20_0039C448-g8.c (the -G8 unit).

   The attempt below is 96 instructions against the retail's 99 and the
   shape of the body is right: the walk over the record list (the
   `beql $a0,$s4` sentinel test with the counter in the delay slot, the
   call to f_003305C0, the pointer advanced by 4 in the delay slot of the
   exit branch, the counter and the reload in the delay slot of the loop
   branch), the test of the int at +0x2294 of D_00189E20, the two reads
   of the int at +0x24 of the state, the byte at +0xBC, the two table
   lookups with the 0x80 mask and the stores through D_L20_0021E340 and
   D_L20_0021EFB0.

   What differs, and what was measured:

   - The retail's loop is a `goto` loop whose check block ends in an
     unconditional jump to the body; that is what makes this cc1 emit
     the branch-LIKELY form the retail uses (`beql $a0,$s4` with
     `addiu $s2,$s2,0x1` in the delay slot, `bnel $v0,$zero` with
     `lw $a0,0x0($s0)` in the delay slot).  The attempt's loop block
     ends in the fall-through to the exit and the branches come out
     plain (`beq`, `bnel`).  See the note on func_L20_0039D680: the
     check block has to end in an unconditional jump to the body.

   - The retail keeps the list pointer in one register ($s0) for the
     whole loop; the attempt needs two ($s0 for the first read and $s1
     for the loop), which costs the extra `daddu $s1,$s0,$zero` and one
     more callee-saved register (the frame is 0x40 against the retail's
     0x30).  Every spelling tried (the value read from the state
     instead of from the pointer, a char pointer advanced by 4, the
     value read in the loop only) keeps the copy.

   - The retail's -1 is two different values in two registers: $s4 for
     the list's sentinel (set in the prologue) and $s0 for the "not
     found" marker (set in the delay slot of the D_00189E20 test).  The
     attempt merges them into one, and its `p = (s32 *)-1` comes out as
     the 64-bit -1 (`lui` + `ori`) where the retail has the 32-bit
     `addiu $s0,$zero,-0x1`.

   - The retail's `lw $a3,0x24($s0)`-style loads of the state fields
     are re-read after the call to f_00335728 (the attempt keeps the
     value in a register instead).

   The attempt below is the closest one.
   With the attempt in src/ (the unit's default flags):
     20_yeedil: 380 bytes, expected 396
     func_L20_003BFEB8: 0 of 1 places match
*/
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003305C0(s32, s32);
extern s32 func_00335728(s32);
extern void func_003253A8(char *);
extern void func_003306A0(s32, s32);

/* The retail body reaches D_00189E20 through $at/$lo. */
extern char D_00189E20[] __attribute__((nosda));

/* The retail body reaches D_0019B2E8 through $at/$lo. */
extern char D_0019B2E8[] __attribute__((nosda));

/* The retail body reaches D_L20_001B2DE0 through $at/$lo. */
extern u8 D_L20_001B2DE0[] __attribute__((nosda));

/* The retail body reaches D_L20_0021E340 through $at/$lo. */
extern u8 D_L20_0021E340[] __attribute__((nosda));

/* The retail body reaches D_L20_0021EFB0 through $at/$lo. */
extern u8 D_L20_0021EFB0[] __attribute__((nosda));

/* 0x1AEFF0 - 0x7600 : the retail body reaches this one through $gp. */
extern s32 D_001A79F0 __attribute__((sda));

void func_L20_003BFEB8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    s32 *p = (s32 *)state;
    s32 value = *p;
    s32 count = 0;
    s32 sentinel = -1;
    s32 n;
    s32 a;
    s32 b;
    u32 c;

body:
    if (value == sentinel) {
        goto check;
    }
    if (func_003305C0(value, -1) != 0) {
        goto out;
    }
    count++;
    p++;
    value = *p;
check:
    if (count < 8) {
        goto body;
    }
    if (*(s32 *)(D_00189E20 + 0x2294) == 0x31) {
        goto out;
    }
    n = -1;
    a = *(s32 *)(state + 0x28);
    b = *(s32 *)(state + 0x24);
    if (a == n) {
        goto have_b;
    }
    if (func_00335728(b + 0x80) == 0) {
        goto out;
    }
    b = *(s32 *)(state + 0x24);
have_b:
    if (b == n) {
        goto have_c;
    }
    *(u8 *)(arg0 + 0xBC) = *(u8 *)(state + 0x24);
    c = *(u32 *)(state + 0x20);
have_c:
    if (c != 0xFF) {
        goto other;
    }
    {
        u8 d = *(u8 *)(arg0 + 0xB0);
        s32 e = d & 0xFF;

        *(u8 *)(D_L20_0021E340 + *(s16 *)(arg0 + 0xB2)) = d + 2;
        if (e == (s32)c) {
            goto store;
        }
        if (*(u8 *)(D_L20_001B2DE0 + e) & 0x80) {
            goto done;
        }
        if (*(u8 *)(D_0019B2E8 + (D_001A79F0 << 4) + e) & 0x80) {
            goto done;
        }
    store:
        *(u8 *)(D_L20_0021EFB0 + *(s16 *)(arg0 + 0xB2)) = d + 2;
    }
done:
    func_003253A8(arg0);
    goto out;
other:
    if (c == (s32)n) {
        goto out;
    }
    *(u8 *)(arg0 + 0x20) = *(u8 *)(state + 0x20);
    a = *(s32 *)(state + 0x2C);
    if (a == n) {
        goto out;
    }
    func_003306A0(a, 1);
out:
    return;
}

/* ------------------------------------------------------------------
   Wave 21, worker 08.  A new attempt, with the retail's loop shape.

   The attempt below is 380 bytes against the retail's 396 and the
   loop's SHAPE is now the retail's: the check comes first, the
   sentinel test is a branch-likely with the count increment in its
   delay slot, the list pointer is one register, and the back edge is
   a branch-likely with the reload of the element in its delay slot:

     retail:  beql $a0,$s4,.+0x18 / addiu $s2,$s2,0x1 / jal / addiu $a1,-1 /
              bnez $v0,EXIT / addiu $s0,$s0,0x4 / addiu $s2,$s2,0x1 /
              slti $v0,$s2,0x8 / bnel $v0,$zero,CHECK / lw $a0,0($s0)
     here:    beql $a0,$s5,.+0x1C / addiu $s2,$s2,0x1 / jal / addiu $a1,-1 /
              bnel $v0,$zero,EXIT / ld $s0,0($sp) / addiu $s1,$s1,0x4 /
              addiu $s2,$s2,0x1 / slti $v0,$s2,0x8 / bnel $v0,$zero,CHECK /
              lw $a0,0($s1)

   What is still different, and what was measured:

   - the register allocation: the retail gives $s0 to the list
     pointer, $s1 to the state, $s2 to the count, $s3 to arg0 and $s4
     to the sentinel (-1), and it reuses $s0 for the "not found" marker
     after the loop (`addiu $s0,$zero,-0x1` at 0x3BFF2C).  The attempt
     gives $s0 to the state and $s1 to the pointer, and it needs one
     callee-saved register more than the retail (its frame is 0x40
     against the retail's 0x30).  The order of the two declarations
     (`char *state` then `s32 *p`, or `s32 *p` then `char *state`) does
     not change it: the load lands in the lower register either way.
   - the exit branch of the call: the retail has a plain `bnez $v0` with
     the pointer increment in its delay slot, the attempt a branch-
     likely `bnel $v0,$zero` with the epilogue's restore of $s0 in the
     delay slot.  Writing the test as `if (... == 0) { p++; count++; }
     else { goto out; }` does not change it either.
   - the retail re-reads the fields of the state after the call to
     f_00335728 (`lw $v0,0x24($s1)` at 0x3BFF4C), so the source uses
     the expression `*(s32 *)(state + 0x24)` twice and keeps no
     variable for it; the attempt's `b` variable costs a register.
   - the retail's "not found" marker is a second -1 (it is materialised
     into $s0 after the loop), while the sentinel of the loop test is
     the one of the prologue ($s4).  The attempt has both, but the
     marker lands in $s1 (the pointer's register) instead of $s0.

   The attempt below is the closest one of this wave: the loop and its
   branches are right, the registers are not.
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003305C0(s32, s32);
extern s32 func_00335728(s32);
extern void func_003253A8(char *);
extern void func_003306A0(s32, s32);

extern char D_00189E20[] __attribute__((nosda));
extern char D_0019B2E8[] __attribute__((nosda));
extern u8 D_L20_001B2DE0[] __attribute__((nosda));
extern u8 D_L20_0021E340[] __attribute__((nosda));
extern u8 D_L20_0021EFB0[] __attribute__((nosda));
extern s32 D_001A79F0 __attribute__((sda));

void func_L20_003BFEB8(char *arg0) {
    s32 *p = (s32 *) *(char **)(arg0 + 0x68);
    char *state = (char *)p;
    s32 sentinel = -1;
    s32 count = 0;
    s32 n;
    u32 c;

check:
    if (*p == sentinel) {
        count++;
        goto test;
    }
    if (func_003305C0(*p, -1) != 0) {
        goto out;
    }
    p++;
    count++;
test:
    if (count < 8) {
        goto check;
    }
    if (*(s32 *)(D_00189E20 + 0x2294) == 0x31) {
        goto out;
    }
    n = -1;
    if (*(s32 *)(state + 0x28) == n) {
        goto have_b;
    }
    if (func_00335728(*(s32 *)(state + 0x24) + 0x80) == 0) {
        goto out;
    }
have_b:
    if (*(s32 *)(state + 0x24) == n) {
        goto have_c;
    }
    *(u8 *)(arg0 + 0xBC) = *(u8 *)(state + 0x24);
    c = *(u32 *)(state + 0x20);
have_c:
    if (c != 0xFF) {
        goto other;
    }
    {
        u8 d = *(u8 *)(arg0 + 0xB0);
        s32 e = d & 0xFF;

        *(u8 *)(D_L20_0021E340 + *(s16 *)(arg0 + 0xB2)) = d + 2;
        if (e == (s32)c) {
            goto store;
        }
        if (*(u8 *)(D_L20_001B2DE0 + e) & 0x80) {
            goto done;
        }
        if (*(u8 *)(D_0019B2E8 + (D_001A79F0 << 4) + e) & 0x80) {
            goto done;
        }
    store:
        *(u8 *)(D_L20_0021EFB0 + *(s16 *)(arg0 + 0xB2)) = d + 2;
    }
done:
    func_003253A8(arg0);
    goto out;
other:
    *(u8 *)(arg0 + 0x20) = *(u8 *)(state + 0x20);
    if (*(s32 *)(state + 0x2C) == n) {
        goto out;
    }
    func_003306A0(*(s32 *)(state + 0x2C), 1);
out:
    return;
}

/* ------------------------------------------------------------------
   Wave 22, worker 09.  The attempt below is the closest one yet: 388
   bytes against the retail's 396, and with `-fno-schedule-insns2` the
   LOOP matches the retail instruction for instruction.

   What this wave measured:

   - The exit branch of the loop needs the pointer increment in its
     DELAY SLOT (`bnez $v0,EXIT` + `addiu $s0,$s0,0x4`), which means
     the increment has to be in the RTL BEFORE the branch.  Written
     that way, the SECOND scheduling pass (-fschedule-insns2, on by
     default) moves the increment in front of the call, and the branch
     then takes its delay slot from the exit block and becomes a
     branch-LIKELY (`bnel $v0,$zero` + `ld $s0,0($sp)`).  With
     `-fno-schedule-insns2` the increment stays where it is and the
     branch comes out as the retail's plain `bnez` with the increment
     in the delay slot.  (The RTL dumps show it: x.i.jump has the
     increment after the call, x.i.sched2 has it before.)
     `-fno-schedule-insns` alone does NOT do it; only
     `-fno-schedule-insns2` does.

   - The `count++` of the "the element is the sentinel" path and the
     `count++` of the "the call returned 0" path must NOT be merged:
     the retail has the first one in the delay slot of the branch-
     likely (`beql $a0,$s4` + `addiu $s2,$s2,0x1`) and the second one
     after the call.  Written as two `count++` in two blocks, gcc
     merges them into one at the join and the branch comes out plain.
     The attempt keeps them apart by putting the call's result in a
     variable and testing it after the increment.

   - The two array stores are at +0x464 in D_L20_0021E340 and
     D_L20_0021EFB0 (the earlier attempt had them at +0).  The
     offset has to stay the STORE's displacement, so the address is
     built through a pointer variable
     (`u8 *q = D_L20_0021E340 + idx; *(q + 0x464) = ...;`): spelled
     as one expression, `D + idx + 0x464` is folded to
     `(D + 0x464) + idx` and the compiler adds 0x464 to the address
     register instead.

   - The byte at +0xB0 is read TWICE: once for the stored value and
     once for the table index, and the second read is masked with
     `andi $v0,$a2,0xFF`.  The mask survives only when the value is
     read as a SIGNED char (`*(s8 *)(arg0 + 0xB0) & 0xFF`): read as
     an unsigned char the mask is folded away.  With the signed read
     gcc narrows the load to `lbu` and keeps the `andi`.

   What still differs (the attempt is 388 bytes, the retail 396):

   - the REGISTER ALLOCATION of the state and of the list pointer:
     the retail gives $s0 to the pointer (the copy `daddu $s0,$s1`) and
     $s1 to the state (the load `lw $s1,0x68($s3)`); the attempt
     gives $s0 to the state and $s1 to the pointer.  Every spelling
     tried (the pointer first, the state first, the state as void *,
     as u32 *, the pointer as char *) gives the load the LOWER
     callee-saved register and the copy the higher one; the retail
     has it the other way round.  The quantity allocator gives a hard
     register to the pseudo with the highest priority
     (floor_log2(n_refs) * n_refs / life), and the pointer's live
     range is much the shorter of the two, so the pointer should win
     - it does not, and the reason is not understood yet.
   - the value of `*(state + 0x20)` is in $a1 in the retail and in
     $a0/$a2 in the attempt (a consequence of the allocation above).
   - the load delay slots: the retail has a `nop` after the load of
     the list element (`lw $a0,0($s0)` + `nop` + `beql $a0,$s4`),
     the attempt has none.
   - the two `lw $a1,0x20($s1)` (the value of state+0x20) and the
     `lw $a0,0x2C($s1)` are in the same registers.

   The attempt needs `-fno-schedule-insns2`, so it belongs in a unit
   of its own:
     src/levels/20_yeedil/L20_003BFEB8-g8.c  -O2 -G8 -ffunction-sections -fno-schedule-insns2

   With the attempt in src/ (the unit's default flags):
     20_yeedil: 392 bytes, expected 396
     func_L20_003BFEB8: 0 of 1 places match
   With the attempt in a unit of its own built with -fno-schedule-insns2:
     20_yeedil: 388 bytes, expected 396
     func_L20_003BFEB8: 0 of 1 places match
*/
#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003305C0(s32, s32);
extern s32 func_00335728(s32);
extern void func_003253A8(char *);
extern void func_003306A0(s32, s32);

extern char D_00189E20[] __attribute__((nosda));
extern char D_0019B2E8[] __attribute__((nosda));
extern u8 D_L20_001B2DE0[] __attribute__((nosda));
extern u8 D_L20_0021E340[] __attribute__((nosda));
extern u8 D_L20_0021EFB0[] __attribute__((nosda));
extern s32 D_001A79F0 __attribute__((sda));

void func_L20_003BFEB8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    s32 *p = (s32 *)state;
    s32 sentinel = -1;
    s32 count = 0;
    s32 n;
    s32 c;

check:
    if (*p == sentinel) {
        count++;
        goto test;
    }
    {
        s32 r = func_003305C0(*p, -1);

        p++;
        if (r == 0) {
            count++;
        } else {
            goto out;
        }
    }
test:
    if (count < 8) {
        goto check;
    }
    if (*(s32 *)(D_00189E20 + 0x2294) == 0x31) {
        goto out;
    }
    n = -1;
    if (*(s32 *)(state + 0x28) == n) {
        goto have_b;
    }
    if (func_00335728(*(s32 *)(state + 0x24) + 0x80) == 0) {
        goto out;
    }
have_b:
    if (*(s32 *)(state + 0x24) == n) {
        goto have_c;
    }
    *(u8 *)(arg0 + 0xBC) = *(u8 *)(state + 0x24);
have_c:
    c = *(s32 *)(state + 0x20);
    if (c != 0xFF) {
        goto other;
    }
    {
        u8 *q = D_L20_0021E340 + *(s16 *)(arg0 + 0xB2);
        s32 e;

        *(q + 0x464) = *(u8 *)(arg0 + 0xB0) + 2;
        e = *(s8 *)(arg0 + 0xB0) & 0xFF;
        if (e != (s32)c) {
            if (*(u8 *)(D_L20_001B2DE0 + e) & 0x80) {
                goto done;
            }
            if (*(u8 *)(D_0019B2E8 + (D_001A79F0 << 4) + e) & 0x80) {
                goto done;
            }
        }
    store:
        {
            u8 *q2 = D_L20_0021EFB0 + *(s16 *)(arg0 + 0xB2);

            *(q2 + 0x464) = *(u8 *)(arg0 + 0xB0) + 2;
        }
    }
done:
    func_003253A8(arg0);
    goto out;
other:
    if (c != n) {
        *(u8 *)(arg0 + 0x20) = *(u8 *)(state + 0x20);
    }
    if (*(s32 *)(state + 0x2C) != n) {
        func_003306A0(*(s32 *)(state + 0x2C), 1);
    }
out:
    return;
}

/* ------------------------------------------------------------------
   Wave 5, worker 08.  The attempt below is the wave-22 attempt; it
   needs a unit of its own with -fno-schedule-insns2 (the loop only
   matches with that flag), so it would live in

     src/levels/20_yeedil/L20_003BFEB8-g8.c
     -O2 -G8 -ffunction-sections -fno-schedule-insns2

   and the config/cflags.txt line

     src/levels/20_yeedil/L20_003BFEB8-g8.c	-O2 -G8 -ffunction-sections -fno-schedule-insns2

   What this wave measured on the two walls that are left:

   - THE ADDRESS OF D_00189E20 IS MATERIALISED IN THE RETAIL AND
     FOLDED HERE.  The retail reads it as

        lui   $v0,%hi(D_189E20)
        addiu $v0,$v0,%lo(D_189E20)
        lw    $v1,0x2294($v0)

     and this attempt as

        lui   $v0,%hi(D_00189E20)
        lw    $v0,0x2294(%lo(D_00189E20)($v0))

     The load's address in the retail is a REGISTER that holds the
     symbol's address and the 0x2294 is the displacement; here the
     offset is folded into the symbol reference.  The escape is known
     for the 128-bit copies (a symbol base survives the CSE), and it
     does not work here: the front end rewrites the pseudo that holds
     the address back into the symbol reference (reg_equiv), so
     `char *dbg = (char *)D_00189E20; *(s32 *)(dbg + 0x2294)' comes
     out the same as the one-expression form, and so do a second
     assignment of the same symbol (`dbg = (char *)D_00189E20;' after
     it) and the declarations with and without `nosda', with a
     different element type and as a pointer.

   - THE LIST POINTER AND THE STATE SWAP PLACES IN THE REGISTERS.  The
     retail gives $s0 to the pointer (the copy `daddu $s0,$s1,$zero')
     and $s1 to the state (the load `lw $s1,0x68($s3)'); this attempt
     gives $s0 to the state and $s1 to the pointer.  The quantity
     allocator gives a hard register to the pseudo with the highest
     priority (floor_log2(n_refs) * n_refs / live_length, and first of
     all to the pseudo that the LRS extension made a copy of), and
     the state's priority (9 references over 37 instructions) is
     higher than the pointer's (4 over 13), so the state is allocated
     first and gets $s0.  For the retail to come out the other way
     round the state's live range has to be about three times the
     pointer's, which the source does not change.

   - The retail has one instruction more before the loop's first
     branch: `lw $a0,0x0($s0)' + `nop' + `beql $a0,$s4'.  This
     attempt has no nop.

   So the attempt is 388 bytes against the retail's 396, with the
   loop itself (the branch-likely sentinel test, the call, the
   pointer increment in the exit branch's delay slot and the reload in
   the loop branch's delay slot) matching instruction for instruction.

   The attempt belongs in the -G8 unit (it reads -0x7600($gp)).
*/

#include "include_asm.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef signed char s8;
typedef signed short s16;
typedef unsigned int u32;
typedef signed int s32;
typedef float f32;

extern s32 func_003305C0(s32, s32);
extern s32 func_00335728(s32);
extern void func_003253A8(char *);
extern void func_003306A0(s32, s32);

extern char D_00189E20[] __attribute__((nosda));
extern char D_0019B2E8[] __attribute__((nosda));
extern u8 D_L20_001B2DE0[] __attribute__((nosda));
extern u8 D_L20_0021E340[] __attribute__((nosda));
extern u8 D_L20_0021EFB0[] __attribute__((nosda));
extern s32 D_001A79F0 __attribute__((sda));

void func_L20_003BFEB8(char *arg0) {
    char *state = *(char **)(arg0 + 0x68);
    s32 *p = (s32 *)state;
    s32 sentinel = -1;
    s32 count = 0;
    s32 n;
    s32 c;

check:
    if (*p == sentinel) {
        count++;
        goto test;
    }
    {
        s32 r = func_003305C0(*p, -1);

        p++;
        if (r == 0) {
            count++;
        } else {
            goto out;
        }
    }
test:
    if (count < 8) {
        goto check;
    }
    if (*(s32 *)(D_00189E20 + 0x2294) == 0x31) {
        goto out;
    }
    n = -1;
    if (*(s32 *)(state + 0x28) == n) {
        goto have_b;
    }
    if (func_00335728(*(s32 *)(state + 0x24) + 0x80) == 0) {
        goto out;
    }
have_b:
    if (*(s32 *)(state + 0x24) == n) {
        goto have_c;
    }
    *(u8 *)(arg0 + 0xBC) = *(u8 *)(state + 0x24);
have_c:
    c = *(s32 *)(state + 0x20);
    if (c != 0xFF) {
        goto other;
    }
    {
        u8 *q = D_L20_0021E340 + *(s16 *)(arg0 + 0xB2);
        s32 e;

        *(q + 0x464) = *(u8 *)(arg0 + 0xB0) + 2;
        e = *(s8 *)(arg0 + 0xB0) & 0xFF;
        if (e != (s32)c) {
            if (*(u8 *)(D_L20_001B2DE0 + e) & 0x80) {
                goto done;
            }
            if (*(u8 *)(D_0019B2E8 + (D_001A79F0 << 4) + e) & 0x80) {
                goto done;
            }
        }
    store:
        {
            u8 *q2 = D_L20_0021EFB0 + *(s16 *)(arg0 + 0xB2);

            *(q2 + 0x464) = *(u8 *)(arg0 + 0xB0) + 2;
        }
    }
done:
    func_003253A8(arg0);
    goto out;
other:
    if (c != n) {
        *(u8 *)(arg0 + 0x20) = *(u8 *)(state + 0x20);
    }
    if (*(s32 *)(state + 0x2C) != n) {
        func_003306A0(*(s32 *)(state + 0x2C), 1);
    }
out:
    return;
}
