/* Near miss from src/levels/03_endako/L03_00399230.c: this body compiles to 288
   bytes, the retail body is 300. Kept as a starting point;
   not linked, not counted.

   What is recovered: the frame (0xE0) and every stack offset of the retail
   body - the state at +0x00, the first corner at +0x30, the second at +0x40,
   the effect track at +0x50, the copy of the actor's aim at +0x80 and the
   float at +0x8C - the four calls (func_002A8BD0, func_002A8C28,
   func_00283658, func_002830C0 and func_002761F8), the level's table of
   four-float vectors at 0x29A8D0 and the four-iteration loop that walks it.

   What differs: the register assignment and the scheduling. The retail keeps
   the actor pointer in $s3 and the loop counter in $s1 (it reuses the register
   the aim pointer had); this cc1 keeps them in $s2 and $s3. The retail also
   materialises the table's base once in $v0 and derives both the first entry
   (a1) and the walking pointer (s2) from it, and it sets the eighth and
   ninth arguments of func_002A8C28 in the other order (the ninth, $t1, first
   and the eighth, $t0, in the call's delay slot). Tried: the aim as a local
   pointer, as a `TI128 *`, and inline; the loop as `for`, as `while` and as
   `do ... while`; the table's entries as two variables and as one. The
   frame, the offsets and the call sequence do not move. */

/* Standalone declarations recovered from src/levels/03_endako/L03_00399230.c. */
typedef unsigned char      u8;
typedef unsigned int       u32;
typedef signed int         s32;
typedef float              f32;

typedef int TI128 __attribute__((mode(TI)));

/* The state the actor's effect keeps: a 128-bit word, the actor, two words and
   a float. */
typedef struct {
    TI128 q;
    void *p;
    u32 flags;
    u32 pad;
    f32 f;
    u32 z;
} L03_003C8698_State;

/* Four floats: the level's table of them at 0x29A8D0. */
typedef struct {
    f32 x, y, z, w;
} L03_V4;

/* The frame of func_L03_003C8698: the state, the two corners it computes, the
   effect track and the copy of the actor's aim. */
typedef struct {
    L03_003C8698_State st;
    TI128 q30;
    TI128 q40;
    TI128 v[3];
    TI128 q80;
} L03_003C8698_Body;

extern void func_002A8BD0(void *a0, void *a1, u32 a2, f32 a3);
extern void func_002A8C28(void *a0, void *a1, s32 a2, f32 a3, f32 a4, f32 a5,
                          s32 a6, s32 a7, s32 a8);
extern void func_00283658(void *a0, void *a1);
extern void func_002830C0(void *a0, void *a1, void *a2);
extern void func_002761F8(void *a0, void *a1, void *a2, void *a3);
extern L03_V4 D_L03_0029A8D0[];

/* Seeds the actor's effect: the state, the aim, the effect track and then the
   four corners of the level's table. */
void func_L03_003C8698(char *a0)
{
    L03_003C8698_Body b;
    f32 one = 1.0f;
    TI128 *aim = (TI128 *)(a0 + 0x10);
    L03_V4 *p = &D_L03_0029A8D0[1];
    int i;

    func_002A8BD0(&b.st, a0, 0x10000, 2.0f);
    func_002A8C28(a0, aim, 0x10000, 1.25f, 100.0f, one, 0, 1, 0);
    func_00283658(&b.v[0], a0 + 0xC0);
    b.q80 = *aim;
    *(f32 *)((u8 *)&b.q80 + 12) = one;
    func_002830C0(&b.q30, &D_L03_0029A8D0[0], &b.v[0]);
    for (i = 3; i >= 0; i--) {
        func_002830C0(&b.q40, p, &b.v[0]);
        func_002761F8(&b.q30, &b.q40, 0, a0);
        b.q30 = b.q40;
        p++;
    }
}
