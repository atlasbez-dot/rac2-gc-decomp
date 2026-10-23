/* func_L00_003AC8E8 (376 bytes, 27 places) -- NEAR MISS, not integrated.
   state: 388 bytes against retail's 376; the body is recovered, three extra copies
   and the loop's shape are left.

   The unit needs a file of its own, because it calls func_2EE178 with four
   arguments while the sibling func_L00_003AB618 calls it with three:
     src/levels/shared/L00_003AC8E8.c   (-O2 -G0 -ffunction-sections, the default)
   and the marker in src/levels/shared/L00_003A8E28.c becomes a comment.

   check.py (00_aranos_tutorial) with the source below:
     func_L00_003AC8E8: 0 of 27 places match (src/levels/shared/L00_003AC8E8.c)
     00_aranos_tutorial: 388 bytes, expected 376

   What is measured and right:
   - the frame is 0x90 and the saved registers land where retail puts them, which
     needs the caller's word to be kept in the record at +0x20 (the store is in
     func_2EE178's delay slot and the reload into $t0 is before func_31CC80).
   - the body is decoded. func_2EE178 fills the first 16 bytes of the record, the
     object's direction (a0+0x10) is copied over the next 16, the level's 224-byte
     record at D_L00_00262570 (indexed by D_00139568[0x1B]) gives the flag byte at
     +4 and the scale at +0x74, the scale is 3.0f when the flag is set and 4.0f
     otherwise, and func_2E10E8 returns the number of sparks.
   - the sparks are the words at D_L00_001C3280, and the kind is 0x45 when the
     record's flag is set and 0x1B otherwise; the count is the countdown retail
     shows (`blez count,end ; s0=count ; ... ; s0-- ; bne s0,zero,loop`).
   - func_31CC80 takes the object, the direction, the spark table, the count, the
     caller's word, 0x81000000, 3, 1 and the two floats (the scale and 1.0f).

   What is left:
   - three copies this cc1 emits and retail does not: `daddu $v0,$a2,$zero` (the
     caller's word is copied into $v0 before the store, retail stores $a2 itself),
     `daddu $a0,$a1,$zero` (the first argument of func_2E10E8, `(int)a0 + 0x10`, is
     computed into $a1 and copied, retail computes it straight into $a0) and
     `daddu $fp,$v0,$zero` (the %hi of D_L00_001C3280 is copied into $fp, retail
     materialises it into $fp once).
   - the loop is not rotated the way retail's is: retail's body starts at the mult
     and the index byte is loaded in the back edge's delay slot, this cc1 keeps the
     load at the top of the body.

   Tried and not enough: the increment of the spark pointer after the call in each
   branch (retail has it once, in the first branch's `b` delay slot and as a plain
   instruction in the second, so one shared increment after the if/else is what
   matches); the caller's word in a local instead of in the record (the frame then
   shrinks to 0x80, retail's is 0x90); the record's flag test as a ternary on the
   scale (retail branches on the flag and keeps the scale's load in the delay slot,
   so a branch is needed). */

extern void func_2EE178(void *, void *, int, float);

extern int func_2E10E8(int, int, int, int, float);

extern void func_3F8AD0(int, int, int);

extern void func_31CC80(void *, void *, void *, int, int, int, int, int, float, float);

extern unsigned char D_00139568[];

extern unsigned char D_L00_00262570[];

extern unsigned int D_L00_001C3280[];

typedef int TI128 __attribute__((mode(TI)));

#ifndef RAC2_T_ENTRY262570B
#define RAC2_T_ENTRY262570B
typedef struct {
    unsigned char pad0[4];
    unsigned char flag;
    unsigned char pad1[111];
    float scale;
    unsigned char pad2[104];
} Entry262570b;
#endif

#ifndef RAC2_T_TRAIL_3AC8E8
#define RAC2_T_TRAIL_3AC8E8
typedef struct {
    float head[4];
    float vec[4];
    int arg;
} Trail_3AC8E8;
#endif

void func_L00_003AC8E8(char *a0, char *a1, int a2)
{
    Trail_3AC8E8 s;
    Entry262570b *e;
    int count;
    int i;
    unsigned int *p;
    float scale;

    s.arg = a2;
    func_2EE178(&s, a1, a2, -3.0f);
    e = (Entry262570b *)(D_L00_00262570 + D_00139568[0x1B] * 224);
    scale = e->scale;
    count = func_2E10E8((int)a0 + 0x10, 0x10, (int)a0, 0,
                        e->flag != 0 ? 3.0f : 4.0f);
    p = D_L00_001C3280;
    for (i = 0; i < count; i++) {
        e = (Entry262570b *)(D_L00_00262570 + D_00139568[0x1B] * 224);
        if (e->flag != 0)
            func_3F8AD0(*p, 0x45, *(int *)(a0 + 0xB8));
        else
            func_3F8AD0(*p, 0x1B, *(int *)(a0 + 0xB8));
        p++;
    }
    *(TI128 *)s.vec = *(TI128 *)(a0 + 0x10);
    func_31CC80(a0, &s.vec, D_L00_001C3280, count, s.arg, 0x81000000, 3, 1, scale, 1.0f);
}
