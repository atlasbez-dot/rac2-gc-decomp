/* Near miss for func_L08_0041EA88 (src/levels/shared/L08_003D3928.c, levels 08 and 19).
 *
 * 368 bytes against retail's 364. The body, the call sequence, the two TI copies and the
 * four float constants are reproduced; what is left is the delay slot of the branch that
 * tests the +0x74 word and the register the second TI copy's address is built in.
 *
 * Retail:  beqz $a0, +0x10 with `lui $v1, 0x1C` in the delay slot and a second `lui` after
 *          the call, then sb/sw/sh and the lq/sq; the +0x1BFF60 address is built in $s0.
 * Draft:   beql with the `sh $zero, 0x88($s0)` copied into the delay slot (three copies of
 *          that store), and the +0x1BFF60 address is built in $v0.
 * Putting the TI copy before the three stores selects the retail's delay slot (`lui`) and
 * its `beqz`, but then the copy lands before the stores instead of after them.
 */

typedef int TI128 __attribute__((mode(TI)));

typedef union L08Scratch {
    TI128 ti;
    struct {
        u8 pad[8];
        f32 scale;
        u8 pad2[4];
    } s;
} L08Scratch;

extern u8 D_00189E20[];
extern u8 D_00189EA0[];
extern TI128 D_L08_001B9D30;
extern TI128 D_L08_001BFF60;

extern void func_L01_00323310(void *, void *);
extern void func_L08_00318F90(void *, void *, int);
extern void ref_L08_0041EA88_00(void *, int);
extern void func_0029F338(void *);
extern void func_00282F20(char *, char *, float);
extern void func_00282CC0(char *, char *, char *);
extern int func_002761F8(void *, void *, int, void *, int);
extern int func_00277258(void *, int, void *, float);

void func_L08_0041EA88(u8 *a0)
{
    u8 *s0;
    u8 *r;
    L08Scratch sc;

    s0 = *(u8 **)(a0 + 0x68);
    func_L01_00323310(*(void **)(s0 + 0x198), *(void **)(s0 + 0x1A0));
    func_L08_00318F90(0, 0, 1);
    r = D_00189E20;
    ref_L08_0041EA88_00(0, 1);
    *(u8 *)(r + 0x22B5) = 0;
    *(f32 *)(r + 0x108) = 0.16666667f;
    *(s16 *)(r + 0x1834) = -1;
    *(s32 *)(r + 0x1830) = 0;
    if (*(u32 *)(s0 + 0x74) != 0)
        func_0029F338((void *)*(u32 *)(s0 + 0x74));
    *(u8 *)(s0 + 0x8A) = 0;
    *(u32 *)(s0 + 0x74) = 0;
    *(s16 *)(s0 + 0x88) = 0;
    *(volatile TI128 *)&sc = *(TI128 *)&D_L08_001B9D30;
    sc.s.scale = 0.0f;
    func_00282F20((char *)&sc, (char *)&sc, 2.5f);
    sc.s.scale = 0.7f;
    func_00282CC0((char *)&sc, (char *)(a0 + 0x10), (char *)&sc);
    *(u32 *)(a0 + 0x98) = 0;
    if (func_002761F8(r + 0x80, (char *)&sc, 2, (void *)*(u32 *)(r + 0x2290), 0) != 0) {
        *(volatile TI128 *)&sc = *(TI128 *)&D_L08_001BFF60;
    }
    if (func_00277258((char *)&sc, 2, (void *)*(u32 *)(r + 0x2290), 0.4f) != 0) {
        *(volatile TI128 *)&sc = *(TI128 *)&D_L08_001BFF60;
    }
    *(volatile TI128 *)D_00189EA0 = sc.ti;
    *(u32 *)(a0 + 0x98) = *(u32 *)((u8 *)*(u32 **)(a0 + 0x24) + 0x10);
    *(u32 *)((u8 *)*(u32 **)(D_00189EA0 + 0x2210) + 0x9C) = 0;
}
