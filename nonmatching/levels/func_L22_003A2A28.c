/* func_L22_003A2A28 (360 bytes, 2 places: 22:003A2A28, 23:003A7060), default profile
   -O2 -G0. Wave 2 worker 7: 356 bytes, four short, and six instructions differ.

   The structure is recovered. The function walks the object's table of records at
   `*(a0 + 0x68) + 0x2A0`, looks each record up in D_L22_001FE940, measures every
   16-byte element of it with func_002F3C40 and keeps the closest one; the closest
   element is announced with func_L22_003A2E10 and the index of it is stored at
   `*(a0 + 0x68) + 0x356`.

   What is left, in the order the diff shows it:

   - the prologue. Retail's holds nothing but the saves and the parameter copies
     (`$s5 = a0`, `$fp = a1`, `a1 = a0 + 0x10`); this cc1 hoists the D_00189EA0
     materialisation, `&b1`, `&b0`, `i = 0` and the 30000.0f materialisation into it.
   - the 16-byte copy. Retail emits `lq $v0,0($a1)` with the address in a register
     (the value of `a0 + 0x10`, shared with the call); this cc1 emits the offset
     form `lq $v0,0x10($s5)`. The same difference is in func_L22_003A2B90 and
     func_L22_003A3550 below, and in the MMI expander it is what decides whether the
     `+ 0x10` of a copied element stays a separate `addiu` or is folded into the
     `lq`'s offset.
   - the table lookup. Retail adds the base first (`addu $v0,$s7,$v0`); this cc1
     emits the commuted form (`addu $v0,$v0,$s7`). The same for the D_L22_001FE940
     lookup, which matches.
   - the body of the inner loop. Retail keeps `mov.s $f20,$f0` (the new minimum)
     before the `lq`/`sq` pair and reloads the record's count in the `bc1fl`'s delay
     slot; this cc1 moves the `mov.s` between the `lq` and the `sq` and fills the
     delay slot with the loop counter instead. The `bc1fl` of retail against the
     plain `bc1f` here is the same difference seen in func_L22_003A2B90.
   - the record's index. Retail's table index is one more than the one handed to
     func_L22_003A48F8 (the branch likely's delay slot increments it before the
     body); this cc1 does the same, so the two agree.

   The call to func_L22_003A2E10 needs a name of its own: the unit's own definition
   spells the parameter `unsigned short`, so a call with an `int` index would carry
   an `andi` that retail does not have. Widening that parameter to `int` leaves the
   callee's own 60 bytes unchanged (measured), and then the plain catalogue name
   works; until then the call goes through `ref_L22_003A2A28_00`, whose value the
   build reads from the retail bytes.

   Measured with tools/check.py func_L22_003A2A28: 356 bytes against retail's 360,
   "instruction at +0x0 differs" (the frame size), then the differences above. */

typedef int u128 __attribute__((mode(TI)));

typedef struct Rec_003A2D58 {
    int count;
    unsigned char pad04[0x18];
    float angle;
} Rec_003A2D58;

extern void func_002F3AB0(void *, void *, void *);
extern void func_002F3D60(void *, void *, float);
extern void func_002F3A80(void *, void *, void *);
extern float func_002F3C40(void *, void *);
extern int func_L22_003A48F8(int);
extern void ref_L22_003A2A28_00(char *, int);
extern float D_00189EA0[4];
extern Rec_003A2D58 *D_L22_001FE940[];

void func_L22_003A2A28(char *a0, int a1) {
    char b0[16];
    char b1[16];
    char *obj = *(char **)(a0 + 0x68);
    int *table;
    Rec_003A2D58 *rec;
    char *p;
    float best;
    float d;
    int i, j;

    *(u128 *)b0 = *(u128 *)(a0 + 0x10);
    func_002F3AB0(b1, a0 + 0x10, D_00189EA0);
    best = 30000.0f;
    func_002F3D60(b1, b1, 4.0f);
    func_002F3A80(b0, b0, b1);
    table = (int *)(obj + 0x2A0);
    for (i = 0; i < 32; i++) {
        if (a1 && func_L22_003A48F8(i) == 0)
            continue;
        rec = D_L22_001FE940[table[i]];
        p = (char *)rec + 0x10;
        for (j = 0; j < rec->count; j++) {
            d = func_002F3C40(p, (char *)&b0);
            if (d < best) {
                best = d;
                ref_L22_003A2A28_00(a0, i);
                *(unsigned short *)(obj + 0x356) = j;
            }
            p += 0x10;
        }
    }
}
