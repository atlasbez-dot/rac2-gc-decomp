/* func_L00_003E64F8 - 300 bytes, 27 places, level 00_aranos_tutorial, retail at
   0x003E64F8.  NEAR MISS, not integrated.

   The candidate below is retail's size exactly (300 bytes) and reads the
   same: it walks the table of 0x50-byte records at D_L00_001B2B50, takes the
   first free one, fills it in (the owner, the two 16-byte vectors, the
   scalar at +0x28 and the two words at +0x38 and +0x3C), runs the engine's
   vector helpers over a 16-byte local, and then runs the 48-round loop that
   calls func_L00_003E6778 and funnels the value through func_00283B98 with
   0.1336848 (0x3E08E4AB).

   What is left: the loop is rotated.  Retail tests the record at the top of
   the loop (0x003E6538) and keeps the busy path out of line (0x003E65F4, a
   branch-likely `bnel` whose delay slot advances the third pointer), while
   this build puts the free path first and the test at the end (0x003E64EC),
   with the counter test (`bgtz` against retail's `blez`) at the top.  The
   argument registers differ too: retail holds the second argument in $t0 and
   the third in $a1, this build holds the first in $t0.

   Tried: the loop with the free path in an `if` and the busy path after it
   (this build then rotates the other way and the counter test moves into
   the head), the free path as the `if` body, the busy path with the counter
   test before and after the pointer bumps.  The branch-likely shape of
   retail's `bnel` is the piece no source shape reached. */

typedef int TI128 __attribute__((mode(TI)));

extern int D_L00_001B2B50_1 __attribute__((sda));

extern void func_00282F20(char *a, char *b, float c);

extern void func_00282F38(char *a, char *b, char *c);

extern void func_00282DD8(char *a, char *b, char *c);

extern float func_002A7940(void);

extern void func_L00_003E6778(char *rec, int a, float b, float c, int d);

extern float func_00283B98(float a, float b);

void func_L00_003E64F8(char *owner, int a1, void *a2, void *a3, float f12)
{
    char *base = (char *)D_L00_001B2B50_1;
    char *rec = base;
    char *p1 = base + 0x10;
    char *p2 = base + 0x20;
    TI128 local;
    float v;
    int i = 0;
    int j;

    for (;;) {
        if (*(int *)(rec + 0x30) != 0) {
            p2 += 0x50;
            if (++i <= 0) {
                rec += 0x50;
                p1 += 0x50;
                continue;
            }
            rec += 0x50;
            break;
        }
        *(int *)(rec + 0x34) = a1;
        *(float *)(rec + 0x3C) = f12;
        *(int *)(rec + 0x30) = (int)owner;
        *(int *)(rec + 0x38) = 0;
        *(TI128 *)rec = *(TI128 *)a3;
        *(TI128 *)p2 = *(TI128 *)a2;
        *(float *)(rec + 0x28) = *(float *)((char *)owner + 0x18);
        func_00282F20((char *)&local, (char *)&local, 2.0f);
        func_00282F38((char *)&local, (char *)&local, p2);
        func_00282DD8(p1, p2, (char *)&local);
        v = func_002A7940();
        for (j = 47; j >= 0; j--) {
            func_L00_003E6778(rec, 2, 0, v, 0.0f);
            v = func_00283B98(v, 0.1336848f);
        }
        *(int *)(rec + 0x44) = 0;
        *(int *)(rec + 0x40) = 0;
        break;
    }
}
