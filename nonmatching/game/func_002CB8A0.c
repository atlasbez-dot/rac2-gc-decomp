#include "include_asm.h"

/* func_002CB8A0 - 176 bytes, 28 places (the boot and every level), retail at
   0x002CB8A0.

   Near miss (wave 2, worker 2).  The body is recovered: the function takes the
   mode in $a0, keeps a 64-bit result (0) and an int out-parameter on the stack,
   dispatches through the program's own jump table (0x26CCC0 in the boot, the
   level's own address in each level) with the range check `sltiu $v0,$a0,7` and
   `beqz` to the default, and the seven case blocks hand one of the small-data
   menu entries (D_001AA6B8 .. D_001AA748, 24 bytes apart) to func_002D5E70,
   which returns the result.  Case 0 first copies D_00189E20's field at +0x1248
   into its field at +0x22C8.

   The C below produces the retail's instruction sequence except for eight
   words:

   1. the 64-bit zero of the result is in $v1 here and in $a1 in the retail
      (`daddu $a1,$zero,$zero` in the prologue, `daddu $a1,$v0,$zero` after the
      call): the retail keeps the value in one 64-bit register and truncates it
      with a plain `daddu $v0,$a1,$zero`, this cc1 keeps it in a register pair
      and re-extracts it with `dsll32`/`dsra32`;
   2. the delay slot of each of the six case branches holds `daddu $a1,$sp,$zero`
      in the retail (the out-parameter's address sunk into the branch delay
      slots), a nop here.

   What was tried: the dispatch through the program's table with a computed goto
   (`goto *((void **)D_0026CCC0)[a0]`, the case labels kept alive by a static
   array of label addresses), the case blocks inside the `if` so that the default
   path is the branch target and the fall-through is the dispatch, the two
   declaration orders, and `(int)result` / `(int)(result >> 32)` as the return.

   What would unblock it: the 64-bit value's register choice and the delay-slot
   sinking - both are the scheduler's and the register allocator's decisions, not
   the source's shape.  The same table is used by func_002CB950 (0x26CCE0),
   which has the same shape and the same two walls.
*/

/*
 * The game's global state: the mode 0 case copies one of its fields into another.
 */
typedef struct {
    char reserved_000[0x1248];
    int value_1248;
    char reserved_124C[0x107C];
    int value_22C8;
} GameState_189E20;

extern GameState_189E20 D_00189E20;

/* The menu entries the seven cases hand to func_002D5E70, in the small data area. */
extern int D_001AA6B8 __attribute__((sda));
extern int D_001AA6D0 __attribute__((sda));
extern int D_001AA6E8 __attribute__((sda));
extern int D_001AA700 __attribute__((sda));
extern int D_001AA718 __attribute__((sda));
extern int D_001AA730 __attribute__((sda));
extern int D_001AA748 __attribute__((sda));

extern int func_002D5E70(char *object, int *result);

/*
 * The dispatch table of the seven cases: the program's data holds the address of
 * each case block (0x26CCC0 in the boot, the level's own address in a level), so
 * the C reads the table instead of generating one.
 */
extern int D_0026CCC0[];

int func_002CB8A0(int a0)
{
    /* The labels' addresses, so that the case blocks are kept: the dispatch itself
       goes through the program's own table. */
    static void *cases[7] = {&&c0, &&c1, &&c2, &&c3, &&c4, &&c5, &&c6};
    long long result = 0;
    int local = 0;
    int *menu;

    if ((unsigned)a0 < 7) {
        goto *((void **)D_0026CCC0)[a0];
c0:     {
            GameState_189E20 *st = &D_00189E20;
            st->value_22C8 = st->value_1248;
        }
        menu = &D_001AA6B8;
        goto cont;
c1:     menu = &D_001AA6D0;
        goto cont;
c2:     menu = &D_001AA6E8;
        goto cont;
c3:     menu = &D_001AA700;
        goto cont;
c4:     menu = &D_001AA718;
        goto cont;
c5:     menu = &D_001AA730;
        goto cont;
c6:     menu = &D_001AA748;
cont:
        result = func_002D5E70((char *)menu, &local);
    }
    return (int)result;
}
