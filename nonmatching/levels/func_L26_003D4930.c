/* Near miss: func_L26_003D4930 (src/levels/26_jamming_array/L26_002EC840.c), 428 bytes against
   retail's 436. Compile it as a -g8 file (the group count is read through $gp, in a delay slot).

   Everything before the last statement matches word for word at its place: the prologue, the
   stamp test that opens the group walk (the entity base D_L26_001B1C1C is the bare `lui`/`lw` of
   the second name below, the group count the delay-slot $gp load), the walk and its callback
   registration (func_L26_003D4AE8, matched), the signed `% 8` phase (`movn` form), the ring
   advance, and both calls. Only the 16-byte copy of the object's +0x10 vector into the ring slot
   differs, and that is the 128-bit copy wall of docs/COMPILER-NOTES.md ("The 128-bit copy wall
   is a cost tie in the CSE"):

     retail:  lw v1,0x194(s2) ; addiu a0,s1,0x10 ; sll v1,v1,4 ; addu v1,v1,s2 ;
              addiu v1,v1,0x80 ; lq v0,0(a0) ; sq v0,0(v1)
     this:    lw v0,0x194(s2) ; lq v1,0x10(s1) ; sll v0,v0,4 ; ... ; addu v0,v0,s2 ;
              sq v1,0x80(v0)

   The source address (obj + 0x10) and the destination (state + idx * 16 + 0x80) are both kept in
   a register with a zero displacement in retail, and both fold their constant into the lq/sq here.

   Tried, all 428 bytes with the folded offsets: the one-line cast copy below; pointer locals for
   source and destination; `(TI128 *)(state + 0x80) + idx` and `((TI128 *)(state + 0x80))[idx]`;
   the base kept in a `u8 *` local first; the ring as `TI128 ring[8]` in a struct view of the
   state (`((Ring *)state)->ring[idx]`); a one-member struct around the TI128; a TI128 temporary
   between the load and the store. None of the escapes listed in the notes (symbol base, loop
   pointer, pointer with two values at a join, volatile pointer, offset past 32752) is a plain
   spelling here, and this body has no join between the pointer computation and the copy.

   Would unblock it: a compiler-side tie-break in find_best_addr (gcc/cse.c) for TImode. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));

extern int D_L26_001B1C38 __attribute__((sda));

extern u8 *D_L26_001B1C1C_1[3] __attribute__((sda));

extern u16 *D_L26_001FA6E0[];

extern int D_L26_001B1748;

extern void func_002AB6D8(u8 *, u8 *);

extern void func_002A91F0(u8 *, u8 *);

extern void func_L00_002E6CF0(void *, u8 *);

extern void func_L26_003D4AE8(u8 *a0);

/* Every 8th tick of the frame word D_L26_001B1748 the object's ring of eight samples advances; the
   object's rotation angles are refreshed from its matrix, the matrix of the current slot is
   rebuilt from them and the object's position vector is copied into the slot's 16-byte record.
   When the state's stamp (+0x19C) differs from the frame word, every entity of the object's group
   is stamped and the object is registered with func_L26_003D4AE8 first. */
void func_L26_003D4930(u8 *a0) {
    u8 *state = *(u8 **)(a0 + 0x68);
    u16 *p;
    u8 *e;
    float phase;

    if (*(int *)(state + 0x19C) != D_L26_001B1748) {
        for (p = D_L26_001FA6E0[a0[0x21]];
             a0[0x21] != 0xFF && a0[0x21] <= D_L26_001B1C38 && p != 0 &&
             ((p != 0 && (short)p[-1] >= 0) || p == D_L26_001FA6E0[a0[0x21]]);
             p++) {
            e = D_L26_001B1C1C_1[0] + ((*p & 0x7FFF) << 8);
            if (e == 0)
                break;
            *(int *)(*(u8 **)(e + 0x68) + 0x19C) = D_L26_001B1748;
        }
        func_L00_002E6CF0((void *)func_L26_003D4AE8, a0);
    }
    phase = (float)(D_L26_001B1748 % 8) * 0.125f;
    *(float *)(state + 0x198) = phase;
    if (phase == 0.0f) {
        *(int *)(state + 0x194) = (*(int *)(state + 0x194) + 1) % 8;
        if (*(int *)(state + 0x190) < 8)
            *(int *)(state + 0x190) = *(int *)(state + 0x190) + 1;
    }
    func_002AB6D8(a0 + 0xC0, a0 + 0xF0);
    func_002A91F0(state + 0x100 + *(int *)(state + 0x194) * 16, a0 + 0xF0);
    *(TI128 *)(state + 0x80 + *(int *)(state + 0x194) * 16) = *(TI128 *)(a0 + 0x10);
}
