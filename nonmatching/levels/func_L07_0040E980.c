/* Near miss: func_L07_0040E980 (src/levels/07_siberius/L07_003F4578.c), 600 bytes against
   retail's 644; 84 of retail's 161 words line up (relocations ignored). It has to be built in the
   -G8 sibling (L07_003F4578-g8.c): it reads D_L07_001B1700 and ..1704 through $gp outside a
   delay slot and takes the address of D_L07_001B1770 with `addiu $v0,$gp`. Compile it as a -g8
   file.

   What is right: the outer `for (i = 1; i < 5; i++)` inside `if (a0[0x21] != 0xFF)` and the
   id-list walk of the object's group byte (+0x21) with the second `p != 0` (the unrotated form,
   so `b` into the test); the entity base through a second name of 12 bytes
   (D_L07_001B22DC_base, `__asm__("D_L07_001B22DC")`, so its load is lui/lw) and the count
   D_L07_001B22F8 read in the delay slot ($gp); the class test `*(s16 *)(e + 0xAA) == i + 0x11D9`;
   the two stores of the flags at e + 0x34 (`|= 1` then `|= 0x22`), which stay two stores only
   with the load through `*(e + 0x24)` between them (otherwise cse merges them into one `ori
   0x23`); `arr = state + 0xE0` as a pointer set inside the guard, `arr[i] = arr[i - 1] +
   D_L07_001B1770[i]`; the three calls at the end of the body with the `sw` of the entity pointer in
   the first one's delay slot. The 1 / distance, the two scale constants and the four `mul.s` of
   the first block are retail's.

   What differs (600 bytes against 644: 16 for the two nops of each division, 16 for the four
   address additions of the copies, 12 for the index arithmetic of the loop):
   0. Retail has two `nop`s in front of each of its two `div.s` (`nop ; nop ; div.s $f1,$f1,$f0`
      before the stores of the first block and the same before `div.s $f20,$f1,$f0`): the
      division padding of docs/COMPILER-NOTES.md (the two load-delay nops before a `div.s`),
      which no source shape moves in this -G8 unit and which only a unit built with `-g`
      (func_L14_003E4EA0's recipe) gives. This alone keeps it from matching.
   1. The two 128-bit copies, the copy wall of docs/COMPILER-NOTES.md. Retail materialises every
      address, both at the start (`addiu a0,s4,0x40` and `addiu v1,s2,0xF0`, issued in the shadow
      of the division, then `lq v0,0(v1) ; sq v0,0(a0)`) and in the walk (`addiu a2,s0,0xF0`,
      `addiu a1,v1,0x40`, then `lq v0,0(a2) ; sq v0,0(a1)`); this compiler folds the offsets
      into the instructions (`lq v0,0xF0(s2) ; sq v0,0x40(s3)`), so it is four words short. The
      schedule of the first block follows: with the two additions missing there is no work to
      put in the division's two-slot wait, so the loads of D_L07_001B1700/1704 and the 1/60 and
      1/3600 constants end up in other places and registers.
   2. The register assignment of the walk: retail keeps i in $s3, the state in $s4, `state +
      0xE0` in $s5, `i + 1` in $s6 and the table base in $s7; this build gives the state $s3,
      i $s4, `i + 1` $s5, the table base $s6 and arr $s7. The per-iteration address arithmetic
      for arr and the pointer array at +0xF4 follows the registers (retail: `addiu v1,s3,-1 ;
      sll a1,s3,2 ; sll v1,v1,2 ; addu v1,s5,v1 ; addu a2,s5,a1 ; addu a1,s4,a1`; this build
      folds more of it into the offsets).
   Scratch variants with the copies written through volatile pointers (not allowed in src/) spill
   the pointers and say nothing about the rest.

   Would unblock it: the compiler-side tie-break of find_best_addr (gcc/cse.c) for TImode, as
   for the other copy-wall rows; the rest would then follow or leave a register-order question. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));

extern f32 func_00282E48(void *a, void *b);
extern void func_L07_00410588(u8 *a);
extern void func_L07_0040F598(u8 *a);
extern void func_L07_0040F6B8(u8 *a);
extern u8 *D_L07_001FDEC0[];
extern u16 *D_L07_001FAD60[];
extern f32 D_L07_001B1700 __attribute__((sda));
extern f32 D_L07_001B1704 __attribute__((sda));
extern f32 D_L07_001B1770[2] __attribute__((sda));
extern s32 D_L07_001B22F8;
extern u8 *D_L07_001B22DC_base[3] __asm__("D_L07_001B22DC") __attribute__((sda));

void func_L07_0040E980(u8 *a0)
{
    u8 *state = *(u8 **)(a0 + 0x68);
    u8 *base;
    f32 inv;
    f32 f20;
    f32 *arr;
    s32 i;
    u16 *p;
    u8 *e;
    u8 *es;

    base = D_L07_001FDEC0[*(s32 *)(state + 0x90)];
    inv = 1.0f / func_00282E48(base + 0x10, base + 0x20);
    *(s32 *)(state + 0x11C) = 0;
    *(u8 **)(state + 0xF4) = a0;
    *(s32 *)(state + 0x5C) |= 2;
    *(s32 *)(state + 0xE0) = 0;
    *(f32 *)(state + 0x1A4) = inv * 0.00027777778f * D_L07_001B1704;
    *(f32 *)(state + 0x1A0) = inv * 0.016666668f * D_L07_001B1700;
    *(TI128 *)(state + 0x40) = *(TI128 *)(a0 + 0xF0);
    func_L07_00410588(a0);
    *(u16 *)(a0 + 0x34) |= 1;
    a0[0x31] = 0;
    f20 = *(f32 *)(a0 + 0x2C) / *(f32 *)(*(u8 **)(a0 + 0x24) + 0x24);
    if (a0[0x21] != 0xFF) {
        arr = (f32 *)(state + 0xE0);
        for (i = 1; i < 5; i++) {
            for (p = D_L07_001FAD60[a0[0x21]];
                 a0[0x21] != 0xFF && a0[0x21] <= D_L07_001B22F8 && p != 0 &&
                 ((p != 0 && (s16)p[-1] >= 0) || p == D_L07_001FAD60[a0[0x21]]);
                 p++) {
                e = D_L07_001B22DC_base[0] + ((*p & 0x7FFF) << 8);
                if (e == 0)
                    break;
                if (*(s16 *)(e + 0xAA) == i + 0x11D9) {
                    *(u16 *)(e + 0x34) |= 1;
                    e[0x31] = 0;
                    *(f32 *)(e + 0x2C) = *(f32 *)(*(u8 **)(e + 0x24) + 0x24) * f20;
                    es = *(u8 **)(e + 0x68);
                    *(u16 *)(e + 0x34) |= 0x22;
                    *(u8 **)(es + 8) = es + 0x20;
                    *(s32 *)(es + 0x5C) = 2;
                    *(TI128 *)(es + 0x40) = *(TI128 *)(e + 0xF0);
                    arr[i] = arr[i - 1] + D_L07_001B1770[i];
                    *(u8 **)(state + 0xF4 + i * 4) = e;
                    func_L07_0040F598(e);
                    func_L07_0040F6B8(e);
                    func_L07_00410588(e);
                }
            }
        }
    }
}
