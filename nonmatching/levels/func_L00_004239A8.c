/* Near miss (M5): 516/516 B, 16 lines off at the 27 places, three spots:
   - head: retail loads the sda constant into $f4 and 1.0 into $f3 (here swapped) and the
     hero pointer `*(char **)D_L00_001B8E10` into $a0 (here $v1, with 2 in $v1 for the sh);
   - loop tail: retail emits `i++` after the 16-byte copy, here sched lifts it above the lui;
   - func_00277258's call: retail `mov.s $f12` before the jal and `daddu $a1` in the slot.
   Found: D_L00_001B8E10 and D_L00_001B8E20 are one object (retail keeps &D+0x10 in $s3 and
   reads the hero pointer as -0x10($s3)); the loop is `while (i < 3)` with i++ at the end and
   `else if (!B) break; else gotB = 1;`, which leaves the gotB store out of the rotated exit
   test (stmt.c expand_end_loop moves up to the last jump to the end label). Statement order
   of the head, the f20 expression form, a for loop and the float position in func_00277258's
   prototype all tie. Profile `-O2 -G8 -ffunction-sections`. */
typedef int TI128 __attribute__((mode(TI)));

extern char D_L00_001B8E10[];
extern char D_L00_001BF220_1[];
extern char D_L00_001BF230[];
extern float D_L00_001B14D0 __attribute__((sda));
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern float func_00282DB0(void *, void *);
extern int func_L00_00420388(void *, float);
extern int func_00277258(void *, void *, void *, float);
extern void *func_L00_004237C8(char *, void *, int, int);

/* Picks the best of three blends of the owner's block. */
void *func_L00_004239A8(char *a0)
{
    char *base = *(char **)(a0 + 0x70);
    char *st = base + 0x1F0;
    void *mid = base + 0x60;
    char *end = base + 0x160;
    TI128 v, w;
    void *q;
    void *tgt;
    void *ret;
    float f20;
    float d;
    int i = 0;
    int gotA = 0;
    int gotB = 0;
    char *cam = D_L00_001B8E10 + 0x10;

    func_00282CC0(&v, base + 0xB0, end);
    *(short *)(st + 0x38) = 2;
    q = *(void **)(*(char **)D_L00_001B8E10 + 0x70);
    tgt = *(void **)(st + 0x48);
    f20 = D_L00_001B14D0 +
          *(float *)((char *)q + 0x234) * *(float *)((char *)q + 0x22C) *
              (*(float *)((char *)q + 0x230) - 1.0f);
    while (i < 3) {
        if (func_L00_00420388(&v, f20))
            gotA = 1;
        else if (!func_00277258(&v, tgt, *(void **)(cam + 0xC4), f20))
            break;
        else
            gotB = 1;
        if (*(short *)(st + 0x38) != 0) {
            func_00282CF0(&w, D_L00_001BF220_1, &v);
            func_00282F20(&w, &w, 1.0f);
            d = func_00282DB0(cam + 0x30, &w);
            if (d > 0.75f)
                *(short *)(st + 0x38) = 1;
            else if (d < -0.75f)
                *(short *)(st + 0x38) = -1;
            else
                *(short *)(st + 0x38) = 0;
        }
        v = *(TI128 *)D_L00_001BF230;
        i++;
    }
    ret = func_L00_004237C8(a0, &v, gotA, gotB);
    func_00282CC0(st + 0x20, (char *)mid + 0x50, end);
    if (*(short *)(st + 0x38) == 2)
        *(short *)(st + 0x38) = 0;
    return ret;
}
