/* Near miss from src/levels/03_endako/L03_00399230-g8.c (G8: needs a -g8.c
   source unit when checked again): this body compiles to 364 bytes, the retail
   body is 360. Kept as a starting point; not linked, not counted.

   What is recovered: the frame (0x110) and every stack offset of the retail
   body - the four 128-bit corners at +0x00, the four words at +0x40, the four
   float pairs at +0x50, the four packed words at +0x70, the vector at +0x90,
   the copy of the actor's aim at +0xC0 and the two 128-bit words at +0xD0 -
   the five calls (func_00282C88, func_00283248, func_00283410, func_0027C878
   and func_00280B90), the level's tables at 0x1B035C, 0x1B0360, 0x1B0364,
   0x1B0368, 0x1B036C, 0x1B0390, 0x1B03D0 and 0x1B9840, and the four-step
   loop that copies them.

   What differs: the three small-data table addresses. The retail reaches
   0x1B0390, 0x1B0368 and 0x1B03D0 through $gp in one instruction each
   (`addiu $t3,$gp,0x13A0`), which the assembler only emits inside a
   `.set noreorder` region; this cc1 leaves them in a reorder region, so each
   comes out as the deferred lui/addiu pair instead - four bytes more per
   address. The retail keeps the whole setup (the `lq`/`sq` pair, the 1.0f
   store and the addresses) in one noreorder region, this cc1 starts the
   region only at the store. The register assignment around the loop differs
   as well (the retail walks the tables in $t0-$t3 and the destinations in
   $v1, $a0-$a2, this cc1 in $v1 and $a0-$a3). Tried: the tables as one
   array of pairs and as two overlapping ones, the float pair source as the
   second half of the pair array and as its own array, the 1.0f store before
   and after the copy. The frame and the offsets do not move. */

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
extern u32 D_L03_001B0360 __attribute__((sda));
extern u32 D_L03_001B0364 __attribute__((sda));
extern L03_Pair D_L03_001B0368[] __attribute__((sda));
extern L03_Pair D_L03_001B036C[];
extern TI128 D_L03_001B0390[] __attribute__((sda));
extern s32 D_L03_001B03D0[] __attribute__((sda));
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
    s32 moby;
    f32 mobyf;
    f32 first_angle;
    u64 mode_bits;
    s32 *pi;
    s32 *si;
    L03_Pair *ps;
    L03_Pair *pw;
    L03_Pair *pd;
    L03_Pair *px;
    TI128 *pq;
    TI128 *sq;
    int i;

    func_00282C88((TI128 *)(work + 0xD0));
    moby = *(s32 *)(a0 + 0x68);
    mobyf = *(f32 *)moby;
    first_angle = func_00283248(D_L03_001B9840[0x140 / 4] - *(f32 *)(a0 + 0x10),
                                D_L03_001B9840[0x144 / 4] - *(f32 *)(a0 + 0x14));
    *(f32 *)(work + 0xD8) = first_angle;
    func_00283410(work + 0x90, work + 0xD0);
    *(TI128 *)(work + 0xC0) = *(TI128 *)(a0 + 0x10);
    *(f32 *)(work + 0xCC) = 1.0f;

    si = D_L03_001B03D0;
    ps = D_L03_001B0368;
    pw = D_L03_001B036C;
    sq = D_L03_001B0390;
    pi = (s32 *)(work + 0x40);
    pd = (L03_Pair *)(work + 0x50);
    px = (L03_Pair *)(work + 0x54);
    pq = (TI128 *)work;
    for (i = 0; i < 4; i++) {
        *pi++ = *si++;
        pd->v = ps->v + mobyf;
        px->v = pw->v;
        pd++;
        px++;
        ps++;
        pw++;
        *pq++ = *sq++;
    }

    *(u64 *)(work + 0x78) = func_0027C878(D_L03_001B035C);
    mode_bits = ((u64)D_L03_001B0360 << 2) | ((u64)D_L03_001B0364 << 6)
               | ((u64)0x8000 << 24);
    *(u64 *)(work + 0x88) = mode_bits;
    *(u64 *)(work + 0x80) = 0xFF90000000000260ULL;
    *(u64 *)(work + 0x70) = 0;
    func_00280B90(work, work + 0x90, 1);
}
