/* from src/levels/shared/L02_002B5F50.c: not matched. Retail 388 bytes, 9 place(s), first word
 * at L02:002B5F50.
 *
 * The body is the level's start-up: it clears the pending state of the resident structure at
 * 0x199E20, asks the level's own setup and the spawner for their part, and then hands the
 * actor's path entry to the two routines that place it.
 *
 * The C below compiles to 400 bytes against retail's 388. Its first half matches retail
 * instruction for instruction, the second half does not, for three measured reasons:
 *
 *   - the resident structure stays in $s1 here and in $s0 in retail, and retail keeps the
 *     $19xxxx half in $s1 to rebuild the structure's address after the first call, so the two
 *     builds materialise the address differently;
 *   - the 16-byte copy folds its offsets into the lq/sq here (lq $v0,0x80($s1) and
 *     sq $v0,0x10($v1)), while retail computes both addresses into registers first
 *     (addiu $a1,$s0,0x80 and addiu $v1,$a0,0x10) and uses a zero offset; a source form
 *     that keeps the two addresses in registers was not found;
 *   - the actor's pointer is re-read from the structure here (lw $a0,0xC14($s1) and
 *     lw $a0,0xC18($s1)) where retail keeps it in a register and re-derives it once.
 *
 * What would unblock it: the source shape that keeps the structure's address, the actor's
 * pointer and the copy's two addresses in registers, as retail has them. */
typedef int TI128 __attribute__((mode(TI)));

extern void func_0029F338(void *a0);
extern void func_L00_002A53B8(void);
extern void func_0028B3D0(int a0, int a1, void *a2, void *a3, void *a4, int a5, int a6);
extern void func_L00_002F6B90(int a0);
extern void func_L00_002A6708(void *a0);
extern void func_L00_002D24B8(void *a0, float f12);
extern void func_L00_002A4DB0(int a0, int a1, void *a2);
extern void func_L00_002C42E0(int a0, int a1);
extern char D_L02_001B5B40[];
extern char D_L02_001B6140[];
extern int D_L02_001A8F00;
extern char D_L02_030B7D0[];
extern char D_L02_030B820[];
extern char D_L02_030C0F0[];

/* The resident state of the game, at 0x199E20. */
typedef struct {
    char pad00[0x0C14];
    void *f_0C14;
    void *f_0C18;
    char pad0C1C[0x0C24 - 0x0C1C];
    float f_0C24;
    char pad0C28[0x1860 - 0x0C28];
    void *f_1860;
    void *f_1864;
    char pad1868[0x2290 - 0x1868];
    void *f_2290;
    int f_2294;
    char pad2298[0x22B4 - 0x2298];
    unsigned char f_22B4;
    char pad22B5[0x24CC - 0x22B5];
    int f_24CC;
    int f_24D0;
    short f_24D4;
} Global_199E20;

extern Global_199E20 D_00199E20;

void func_L02_002B5F50(void) {
    Global_199E20 *g = &D_00199E20;
    unsigned char *p;
    unsigned char v;
    int mode;

    if (g->f_22B4 == 1) {
        g->f_24D0 = g->f_24CC;
        g->f_24CC = g->f_24D4;
        if (g->f_1860 != 0) {
            func_0029F338(g->f_1860);
            g->f_1860 = 0;
        }
        if (g->f_1864 != 0) {
            func_0029F338(g->f_1864);
            g->f_1864 = 0;
        }
    }
    func_L00_002A53B8();
    func_0028B3D0(0x23, 0, D_L02_030B7D0, D_L02_030B820, D_L02_030C0F0, 0, 0);
    g->f_22B4 = 0;
    func_L00_002F6B90(3);
    if (g->f_0C14 != 0)
        *(unsigned short *)((char *)g->f_0C14 + 0x34) &= 0xFFF9;
    func_L00_002A6708(g->f_0C14);
    g->f_0C14 = 0;
    g->f_2290 = g->f_0C18;
    *(TI128 *)((char *)g->f_0C18 + 0x10) = *(TI128 *)((char *)g + 0x80);
    *(int *)((char *)g->f_0C18 + 0x9C) = 0;
    g->f_0C24 = 1.0f;
    func_L00_002D24B8(g->f_0C18, 1.0f);
    p = (unsigned char *)g->f_2290;
    v = p[0x42];
    if (v != 0xFF) {
        func_L00_002A4DB0(v, p[0x40], D_L02_001B5B40);
        *(int *)((char *)g->f_2290 + 0x58) = v;
    }
    p = (unsigned char *)g->f_2290;
    v = p[0x43];
    func_L00_002A4DB0(v, p[0x41], D_L02_001B6140);
    *(int *)((char *)g->f_2290 + 0x5C) = v;
    mode = (g->f_2294 == 0x61) ? 0x61 : 0;
    if (D_L02_001A8F00 != 2 && D_L02_001A8F00 != 6)
        func_L00_002C42E0(mode, 1);
}
