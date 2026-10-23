/* Near miss for func_L08_00435990 (src/levels/shared/L08_003D3928.c, levels 08 and 19).
 *
 * 264 bytes against retail's 232. The whole body is reproduced - the three early exits, the
 * loop, the two branch-likely tests, the call and the three float stores - but the loop
 * optimizer hoists the five address computations (`lui`/`addiu` for the group, the pool and
 * the three floats) out of the loop, so they become live across the call and need five
 * callee-saved registers: the frame is 0x60 instead of 0x40 and the body is 32 bytes longer.
 *
 * Retail keeps the three `lui $at, 0x1B` and the `lui $a2, 0x1B` inside the loop, after the
 * call, and reuses $at for all of them. The loop's RTL has 34 instructions and the loop
 * optimizer's threshold (1 + n_non_fixed_regs, times savings times lifetime) is at least 38,
 * so every movable is moved out; the source forms tried (volatile globals, a local pointer
 * walk, a local count, a while loop, the group accessed through the global) all move them
 * out as well, and none of them changes the number of instructions in the loop.
 */

typedef int TI128 __attribute__((mode(TI)));

/* One entity of the group: the kind word is at 0xAA. */
typedef struct L08Thing {
    u8 pad[0xAA];
    s16 kind;
} L08Thing;

/* The group: the count is at 0x44, the list of entities at 0x18C. */
typedef struct L08Group {
    u8 pad0[0x44];
    s16 count;
    u8 pad1[0x18C - 0x46];
    L08Thing *items[1];
} L08Group;

extern L08Group D_L08_001BD800;
extern s32 D_L08_001A8F00;
extern u8 D_001A7A40;
extern u8 D_L08_001B22E0[];
extern u8 D_L08_001B22E1;
extern f32 D_L08_001B2300;
extern f32 D_L08_001B2304;
extern f32 D_L08_001B2308;

extern void func_0029F978(unsigned char *, unsigned int, unsigned char *);

void func_L08_00435990(L08Thing *a0)
{
    L08Group *g;
    L08Thing *e;
    s32 i;

    if (D_L08_001A8F00 != 2)
        return;
    if (D_001A7A40 == 0)
        return;
    g = &D_L08_001BD800;
    for (i = 0; i < g->count; i++) {
        e = g->items[i];
        if (e->kind != a0->kind)
            continue;
        if (D_L08_001B22E1 != 0)
            continue;
        func_0029F978((unsigned char *)e, 0, D_L08_001B22E0);
        D_L08_001B2300 = 2.3f;
        D_L08_001B2304 = 2.3f;
        D_L08_001B2308 = 2.3f;
    }
}
