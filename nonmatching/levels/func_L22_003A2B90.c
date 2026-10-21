/* func_L22_003A2B90 (292 bytes, 2 places: 22:003A2B90, 23:003A71C8), default profile
   -O2 -G0. Wave 2 worker 7: 288 bytes, four short, and four instructions differ.

   The same walk as func_L22_003A2A28, but it copies the closest 16-byte element
   into the caller's buffer (`a1`) instead of announcing it: the function takes
   (object, buffer, matrix, flag), measures every element of every record of the
   table at `*(a0 + 0x68) + 0x2A0` with func_002F3C40 against the matrix in `a2`,
   and keeps the closest element, which is copied out as one 128-bit move.

   What is left, in the order the diff shows it:

   - the table lookup. Retail adds the base first (`addu $v0,$s7,$v0`); this cc1
     emits the commuted form (`addu $v0,$v0,$s7`). The D_L22_001FE940 lookup that
     follows matches (`addu $v1,$v1,$fp`).
   - the body of the inner loop. Retail keeps `mov.s $f20,$f0` (the new minimum)
     before the `lq`/`sq` pair and reloads the record's count in the `bc1fl`'s delay
     slot; this cc1 moves the `mov.s` between the `lq` and the `sq` and fills the
     delay slot with the loop counter instead. Retail's `bc1fl` against this cc1's
     plain `bc1f` is the same difference seen in func_L22_003A2A28.
   - the four bytes that are missing altogether are the count reload of the delay
     slot: retail has it twice (in the delay slot and after the body), this cc1 has
     it once.

   The 16-byte copy needs the 128-bit spelling: `*(u128 *)a1 = *(u128 *)p` is what
   reaches the MMI `lq`/`sq` pair (a plain struct assignment would come out as
   `ldl`/`ldr` pairs).

   Measured with tools/check.py func_L22_003A2B90: 288 bytes against retail's 292,
   "instruction at +0x0 differs" (the table lookup's operand order), then the
   differences above. */

typedef int u128 __attribute__((mode(TI)));

typedef struct Rec_003A2D58 {
    int count;
    unsigned char pad04[0x18];
    float angle;
} Rec_003A2D58;

extern float func_002F3C40(void *, void *);
extern int func_L22_003A48F8(int);
extern Rec_003A2D58 *D_L22_001FE940[];

void func_L22_003A2B90(void *a0, void *a1, void *a2, int a3) {
    char *obj = *(char **)((char *)a0 + 0x68);
    int *table = (int *)(obj + 0x2A0);
    Rec_003A2D58 *rec;
    char *p;
    float best = 30000.0f;
    float d;
    int i, j;

    for (i = 0; i < 32; i++) {
        if (a3 && func_L22_003A48F8(i) == 0)
            continue;
        rec = D_L22_001FE940[table[i]];
        p = (char *)rec + 0x10;
        for (j = 0; j < rec->count; j++) {
            d = func_002F3C40(p, a2);
            if (d < best) {
                best = d;
                *(u128 *)a1 = *(u128 *)p;
            }
            p += 0x10;
        }
    }
}
