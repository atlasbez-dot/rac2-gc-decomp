/* func_00325DA0 (284 bytes, 7 places) - near miss: 280/284 B in a -G8 unit (00325DA0-g8.c).
 *
 * M27: the goto loop (jump to the test, no loop.c hoisting) gives retail's shape: the byte
 * offset computed before the loop with the sra/sll inside it, the moby base and the
 * D_001EE5A0 row re-read each pass, the $gp read of D_001B1B78.
 * M37: a group local g, set before the jump to the test and at the end of each pass, gives
 * retail's entry copy of the slot argument to $a2 (D_001B1688 in $a1): 276 -> 280 B.
 * Still missing: retail tests g through `andi $v1,$a3,0xFF` and reloads m->group for the
 * <= D_001B1B78 bound and the row index (here both reuse g); retail also copies the first
 * group load into $a3 at the top. Any s8/s16/s32/u16/u32 g, a (u8) cast, or setting g at
 * the top instead is no closer (268-288 B).
 */
#include "common.h"

typedef struct Moby_325DA0 {
    u8 pad00[0x21];
    u8 group;
    u8 pad22[0x68 - 0x22];
    s32 *pvar;
    u8 pad6C[0xAA - 0x6C];
    s16 team;
    u8 padAC[0x100 - 0xAC];
} Moby_325DA0;

extern s32 D_001B1688[] __attribute__((sda));
extern Moby_325DA0 *D_001B1B5C[] __attribute__((sda));
extern s32 D_001B1B78;
extern u16 *D_001EE5A0[];
extern void func_0027CFD0(void (*)(Moby_325DA0 *), Moby_325DA0 *);
extern void func_00325EC0(Moby_325DA0 *);

/* Clear one pvar slot in every moby of the same group and team, then queue the follow-up. */
void func_00325DA0(Moby_325DA0 *m, s32 *slot)
{
    u16 *list;
    Moby_325DA0 *o;
    s32 off;
    u8 g;

    if (*slot == D_001B1688[0]) return;
    if (m->group == 0xFF) {
        *slot = D_001B1688[0];
    } else {
        off = (char *)slot - (char *)m->pvar;
        list = D_001EE5A0[m->group];
        g = m->group;
        goto test;
    body:
        o = &D_001B1B5C[0][*list & 0x7FFF];
        if (o == 0) goto done;
        if (o->team == m->team) o->pvar[off >> 2] = D_001B1688[0];
        g = m->group;
        list++;
    test:
        if (g != 0xFF && m->group <= D_001B1B78 && list != 0
            && ((s16)list[-1] >= 0 || list == D_001EE5A0[m->group])) goto body;
    }
done:
    func_0027CFD0(func_00325EC0, m);
}
