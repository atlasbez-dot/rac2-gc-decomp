/* Near miss from src/levels/03_endako/L03_00399230-g8.c (G8: needs a -g8.c
   source unit when checked again): this body compiles to 292 bytes, the retail
   body is 304. Kept as a starting point; not linked, not counted.

   What is recovered: the frame (0x1E0) and every stack offset of the retail
   body - the level's own object at +0x00, its second half at +0x90, the two
   vectors at +0x120 and +0x150, the copy of the actor's aim at +0x180 and
   the 128-bit word at +0x190 - the six calls (func_00283658, func_002833F0,
   func_L01_0031BC68, func_00283D38, func_L02_002EF968 twice and
   func_L01_002E1510), the small-data arguments at 0x1B0410 and 0x1B0430, the
   absolute word at 0x1B0434 and the level's table at 0x29B9F0. The constant
   the retail stores at +0x198 is 0.19634954f (pi over sixteen), not 0.2f.

   What differs: the scheduling of the two func_L02_002EF968 calls and of the
   final func_L01_002E1510 call - the retail sets the fourth argument (the
   small-data address) of both calls and the fifth argument (the table) in
   front of the call, this cc1 sets the table and the arguments after it, so
   the two bodies differ by twelve bytes. The register assignment differs as
   well. The $gp-relative forms themselves match: `addiu $a3,$gp,0x1420` and
   `lw $a0,0x1440($gp)` come out with the same relocations as the retail's.
   Tried: the small-data argument as a pointer, as an object and by address;
   the vector at +0x120 as a double array and as a byte buffer. The frame and
   the offsets do not move. */

/* Standalone declarations recovered from src/levels/03_endako/L03_00399230-g8.c. */
typedef unsigned char      u8;
typedef unsigned int       u32;
typedef signed int         s32;
typedef float              f32;

typedef int TI128 __attribute__((mode(TI)));

extern void func_00283658(void *a0, void *a1);
extern void func_002833F0(void *a0, void *a1);
extern s32  func_L01_0031BC68(u32 a0, u32 a1, f32 a2);
extern s32  func_00283D38(s32 a0, s32 a1);
extern void func_L02_002EF968(void *a0, s32 a1, s32 a2, void *a3, void *a4, s32 a5);
extern void func_L01_002E1510(void *a0, s32 a1, void *a2, s32 a3, void *a4);

extern u32  D_L03_001B0430 __attribute__((sda));
extern u32  D_L03_001B0434;
extern u8   D_L03_001B0410 __attribute__((sda));
extern f32  D_L03_0029B9F0[];

/* Builds the actor's effect object: the track the level keeps, the two vectors
   the aim is folded into, and the level's own tables. */
void func_L03_003CBC40(char *a0)
{
    u8 work[0x1A0];
    s32 moby;
    s32 res;
    f32 f;

    func_00283658(work + 0x150, a0 + 0xC0);
    moby = *(s32 *)(a0 + 0x68);
    *(TI128 *)(work + 0x180) = *(TI128 *)(a0 + 0x10);
    *(TI128 *)(work + 0x190) = 0;
    *(f32 *)(work + 0x18C) = 1.0f;
    func_002833F0(work + 0x120, work + 0x190);
    *(f32 *)(work + 0x198) = 0.19634954f;
    res = func_L01_0031BC68(D_L03_001B0430, D_L03_001B0434, *(f32 *)(moby + 0x30));
    f = *(f32 *)(moby + 0x18);
    if (f < 1.0f)
        res = func_00283D38(res & 0xFFFFFF, res);
    func_L02_002EF968(work, 5, res, &D_L03_001B0410, &D_L03_0029B9F0[0], 1);
    func_L02_002EF968(work + 0x90, 5, res, &D_L03_001B0410, &D_L03_0029B9F0[0x10], 1);
    func_L01_002E1510(work, 2, work + 0x120, 0x20, work + 0x150);
}
