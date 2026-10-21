/* func_L22_003A3550 (336 bytes, 2 places: 22:003A3550, 23:003A7B88), -G8 profile.
   Wave 2 worker 7: 320 bytes, sixteen short, and the register assignment differs.

   The body reaches its global through $gp (`lw $v0,0x324($gp)`, the small-data
   word D_L22_001AF314), so it only reproduces in a -G8 unit: it belongs in
   src/levels/shared/L22_0039D708-g8.c, next to func_L22_003A48F8, which reads the
   same word. The draft below was measured in that unit.

   The structure is recovered. The function looks for a record of the orbit's table
   (the table at `D_L22_001AF314->0x68 + 0x2A0`) whose element lies within 45.0 of
   the hero (D_00189EA0, the second argument of func_002F3C40), and keeps looking
   while the record it picked is too close; the loop's exit condition is the flag in
   `a1` and func_L22_003A48F8. The element it settles on is copied into `a0` as one
   128-bit move and func_L22_003A2988 is called on it with the float argument.

   What is left, in the order the diff shows it:

   - the register assignment. Retail keeps the high half of D_00189EA0 in `$s5` and
     the table in `$s6`, so the two parameters land in `$s7` (`a1`) and `$fp` (`a0`);
     this cc1 gives `$s5` to `a0`, `$s6` to the hero address, `$s7` to the table and
     `$fp` to `a1`. The same four values, another four registers.
   - the 16-byte copy. Retail computes the element's address with a separate
     `addiu $v1,$v1,0x10` after the scaled index and loads it with `lq $v0,0($v1)`;
     this cc1 folds the `+ 0x10` into the `lq`'s offset (`lq $v1,0x10($v0)`) and so
     is one instruction short there. The MMI expander decides this, and the same
     choice is open in func_L22_003A2A28 and func_L22_003A2B90.
   - the arguments of func_002F3C40: retail passes the hero position first and the
     element second; the draft does the same, but the two end up in the opposite
     registers.

   Measured with tools/check.py func_L22_003A3550 in the -G8 unit: 320 bytes
   against retail's 336, "instruction at +0x0 differs" (the register assignment),
   then the differences above. */

typedef int u128 __attribute__((mode(TI)));

typedef struct Rec_003A2D58 {
    int count;
    unsigned char pad04[0x18];
    float angle;
} Rec_003A2D58;

extern int D_L22_001AF314 __attribute__((sda));
extern Rec_003A2D58 *D_L22_001FE940[];
extern float D_00189EA0[4];
extern int func_002A77E0(int);
extern float func_002F3C40(void *, void *);
extern int func_L22_003A48F8(int);
extern void func_L22_003A2988(void *, float);

void func_L22_003A3550(char *a0, int a1, float a2) {
    char *g = (char *)D_L22_001AF314;
    char *obj = *(char **)(g + 0x68);
    int *table = (int *)(obj + 0x2A0);
    Rec_003A2D58 *rec;
    char *p;
    char *elem;
    float d;
    int idx, j, found;

    for (;;) {
        found = 0;
        idx = func_002A77E0(0x20);
        rec = D_L22_001FE940[table[idx]];
        p = (char *)rec + 0x10;
        j = 0;
        for (;;) {
            j++;
            if (j >= rec->count) break;
            d = func_002F3C40(D_00189EA0, p);
            if (d < 45.0f) {
                found = 1;
                break;
            }
            p += 0x10;
        }
        if (found) continue;
        if (a1 == 0) continue;
        if (func_L22_003A48F8(idx) == 0) continue;
        elem = (char *)rec + func_002A77E0(rec->count - 1) * 16 + 0x10;
        *(u128 *)a0 = *(u128 *)elem;
        break;
    }
    func_L22_003A2988(a0, a2);
}
