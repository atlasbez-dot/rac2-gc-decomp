/* func_L03_003CAD78 - 360 bytes, 1 place (03_endako). M35: 360/360 in a unit
   L03_003CAD78-g64.c with -O2 -G64 -Wa,-G64 -ffunction-sections -frac2-qcopy
   -frac2-qcopy-barrier. The sda tables at 0x1B0368, 0x1B0390 and 0x1B03D0 are
   sized arrays, so -G64 gives retail's one-instruction $gp addresses; the moby
   pointer is read before the first call and its float re-read in the loop; the
   loop is an indexed for loop (the qcopy barrier keeps the pointer steps after
   the copy); the two mode words are signed; the constant is 0x0000FF9000000260.
   Left: the loop's 0x1B0390 and 0x1B036C pointers come out in $t2/$t3 swapped
   against retail ($t3/$t2), with their preheader setup order. 7 lines, register
   allocation only; queued for the permuter. */

/* Standalone declarations recovered from src/levels/03_endako/L03_00399230-g8.c. */
typedef unsigned char      u8;
typedef unsigned int       u32;
typedef signed int         s32;
typedef unsigned long long u64;
typedef float              f32;

typedef int TI128 __attribute__((mode(TI)));

/* A pair of floats: the level's tables of them at 0x1B0368 (the first halves,
   in the small data area) and at 0x1B036C (the second halves, absolute). */
typedef struct {
    f32 v;
    f32 w;
} L03_Pair;

extern u32 D_L03_001B035C __attribute__((sda));
extern s32 D_L03_001B0360 __attribute__((sda));
extern s32 D_L03_001B0364 __attribute__((sda));
extern L03_Pair D_L03_001B0368[4] __attribute__((sda));
extern L03_Pair D_L03_001B036C[];
extern TI128 D_L03_001B0390[4] __attribute__((sda));
extern s32 D_L03_001B03D0[4] __attribute__((sda));
extern f32 D_L03_001B9840[];

extern void func_00282C88(TI128 *a0);
extern f32  func_00283248(f32 a0, f32 a1);
extern void func_00283410(void *a0, void *a1);
extern s32  func_0027C878(s32 a0);
extern void func_00280B90(void *a0, void *a1, s32 a2);

/* Builds the actor's effect track: the aim, the four corners of the level's
   tables, and the two packed words the level keeps. */
void func_L03_003CAD78(char *a0)
{
    u8 work[0xE0];
    f32 *moby;
    u64 mode_bits;
    s32 *pi;
    L03_Pair *pd;
    L03_Pair *px;
    TI128 *pq;
    int i;

    moby = *(f32 **)(a0 + 0x68);
    func_00282C88((TI128 *)(work + 0xD0));
    *(f32 *)(work + 0xD8) = func_00283248(D_L03_001B9840[0x140 / 4] - *(f32 *)(a0 + 0x10),
                                          D_L03_001B9840[0x144 / 4] - *(f32 *)(a0 + 0x14));
    func_00283410(work + 0x90, work + 0xD0);
    *(TI128 *)(work + 0xC0) = *(TI128 *)(a0 + 0x10);
    *(f32 *)(work + 0xCC) = 1.0f;

    pi = (s32 *)(work + 0x40);
    pd = (L03_Pair *)(work + 0x50);
    px = (L03_Pair *)(work + 0x54);
    pq = (TI128 *)work;
    for (i = 0; i < 4; i++) {
        pi[i] = D_L03_001B03D0[i];
        pd[i].v = D_L03_001B0368[i].v + *moby;
        px[i].v = D_L03_001B036C[i].v;
        pq[i] = D_L03_001B0390[i];
    }

    *(u64 *)(work + 0x78) = func_0027C878(D_L03_001B035C);
    mode_bits = ((u64)D_L03_001B0360 << 2) | ((u64)D_L03_001B0364 << 6)
               | ((u64)0x8000 << 24);
    *(u64 *)(work + 0x88) = mode_bits;
    *(u64 *)(work + 0x80) = 0x0000FF9000000260ULL;
    *(u64 *)(work + 0x70) = 0;
    func_00280B90(work, work + 0x90, 1);
}
