/* Near miss: the layout of the three-place blend search matches (prologue, loop, sign test,
   tail) but the body is 532 bytes against retail's 516, four instructions out:
   - retail reloads nothing at 0x1B8E20: the whole function shares one base register
     (`lw $a0,-0x10($s3)` for the +0xE10 pointer and `lw $a2,0xC4($s3)`), this cc1
     rematerialises `lui` for the second use;
   - retail hoists both 0.75 and -0.75 into f22/f21 in the prologue, this cc1 materialises
     -0.75 inside the else branch;
   - the dot product is compared twice in f0 in retail, here it is copied to f1 first;
   - retail's `b` takes `add.s` as its delay slot, here a `nop` is left.
   The body needs the -G8 profile for the `lwc1 0x24E0($gp)` constant. */

/* Needs the L00_004224D0 unit's types: */
typedef int TI128 __attribute__((mode(TI)));

extern char *D_L00_001B8E10;
extern char D_L00_001BF220_1[];
extern char D_L00_001B8E20[];
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

    func_00282CC0(&v, base + 0xB0, end);
    *(short *)(st + 0x38) = 2;
    q = *(void **)(D_L00_001B8E10 + 0x70);
    tgt = *(void **)(st + 0x48);
    f20 = D_L00_001B14D0 +
          *(float *)((char *)q + 0x234) * *(float *)((char *)q + 0x22C) *
              (*(float *)((char *)q + 0x230) - 1.0f);
    while (i < 3) {
        if (func_L00_00420388(&v, f20)) {
            gotA = 1;
        } else if (func_00277258(&v, tgt, *(void **)(D_L00_001B8E20 + 0xC4),
                                 f20)) {
            gotB = 1;
        } else {
            break;
        }
        if (*(short *)(st + 0x38) != 0) {
            func_00282CF0(&w, D_L00_001BF220_1, &v);
            func_00282F20(&w, &w, 1.0f);
            d = func_00282DB0(D_L00_001B8E20 + 0x30, &w);
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

int func_L00_00423BB0(void)
{
    char buf[80];

    return 0;
}

