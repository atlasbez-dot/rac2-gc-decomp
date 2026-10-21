/* Near miss: func_L07_00410700 (src/levels/07_siberius/L07_003F4578.c), 544 bytes against
   retail's 560. Compile it as a -g8 file (it takes the addresses of the $gp objects D_L07_001B17E0,
   ..17F0, ..1800 and ..1810 and loads a float from D_L07_001B1810 through $gp, none of it in a
   delay slot; the other floats of the vector, D_L07_001B1814 and ..1818, are bare loads).

   The body is right. From the load of the state pointer to the call of func_002AAC80 (the four
   float arguments, the 400.0f - x, the stores into D_001A63A8) the code is retail's word for
   word, and so are the id-list walk at the end (the unrotated form with `p != 0` first and the
   entity test in the loop condition, 32-byte records, bit 2 set at +0x1E), the epilogue and the
   final store; the float chain around func_2E49C8 / func_2E4508 and the zero store of the
   argument vector (`sq $zero,0(sp)`, the form retail has too) are the same instructions.

   What cannot be reproduced is the three 128-bit copies, the 128-bit copy wall of
   docs/COMPILER-NOTES.md: retail materialises every address,

     addiu a0,s1,0x10 ; addiu v1,gp,0x27F0 ; lq v0,0(v1) ; sq v0,0(a0)
     addiu a1,s1,0xF0 ; addiu s3,gp,0x2800 ; lq v0,0(s3) ; sq v0,0(a1)
     addiu a0,sp,0x10 ; (lui/addiu D_00189EA0 into v1) ; lq v0,0(v1) ; sq v0,0(a0)

   and this compiler folds each destination into the sq (`sq v0,16(s1)`, `sq v0,240(s1)`,
   `sq v0,16(sp)`), so it is three words short. The sources of the copies (`&gp object`) are
   materialised correctly. The fourth missing word is the `addiu s0,gp,0x2820` that retail keeps
   the address of D_L07_001B1810 in (the register of `state`, dead by then; copied to a0/a1 at
   the two calls) where this build rematerialises it with `addiu a0/a1,gp` at both uses, hence 544
   against 560. A local pointer for it takes a fifth callee-saved register instead, because the
   scheduler hoists its `la` to the top.

   The scheduler also places the four state stores before the func_L00_002B9D60 call as 0xD0,
   0x16B8, 0x16BC, 0x16B0 where retail has 0x16BC, 0x16B0, 0xD0, 0x16B8 (all 24 source orders of
   the four statements give the same code). Scratch copies with the copies written as a volatile
   asm (not allowed in src/) reach 560 bytes but disturb the schedule after them, so they do not
   say whether these two differences would follow once the copies are right.

   Would unblock it: the same compiler-side tie-break in find_best_addr (gcc/cse.c) for TImode
   as the other copy-wall rows. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;
typedef float f32;

extern void func_002A7750(u8 *a, u8 b, s32 c);

typedef int TI128 __attribute__((mode(TI)));

extern f32 D_L07_001B17E0 __attribute__((sda));

extern f32 D_L07_001B17F0 __attribute__((sda));

extern f32 D_L07_001B1800 __attribute__((sda));

extern f32 D_L07_001B1810 __attribute__((sda));

extern f32 D_L07_001B1814;

extern f32 D_L07_001B1818;

extern f32 D_L07_001B1744 __attribute__((sda));

extern f32 D_L07_001B1748 __attribute__((sda));

extern u16 **D_L07_001A9014;

extern u8 *D_L07_001B2954;

extern s32 D_L07_001B1E90;

extern s32 D_001A63A8[];

extern char D_00189EA0[];

extern f32 D_L07_00189E20[];

extern void func_002A0F48(u8 *a);

extern void func_002AAC80(void *a, f32 b, f32 c, f32 d, f32 e);

extern void func_L00_002B9D60(void *obj, void *pos, s32 a2, s32 a3);

extern f32 func_2E49C8(f32 a, f32 b);

extern f32 func_2E4508(void *a, void *b);

extern void func_00335438(void *a, void *b, s32 c, s32 d, s32 e);

extern void func_L07_004106B8(u8 *a);

/* Starts the second phase of the object: its two position vectors, the shared timer record, the
   effect call and the camera-facing vector, then raises bit 2 of every record of the group. */
void func_L07_00410700(u8 *a0, s32 group)
{
    f32 w[4];
    f32 t[4];
    u8 *state;
    u16 *p;
    u8 *e;
    f32 r;

    func_002A7750(a0, 5, -1);
    *(TI128 *)(a0 + 0x10) = *(TI128 *)&D_L07_001B17E0;
    *(TI128 *)(a0 + 0xF0) = *(TI128 *)&D_L07_001B17F0;
    *(u16 *)(a0 + 0x34) &= 0xFFFD;
    func_002A0F48(a0);
    state = *(u8 **)(a0 + 0x68);
    D_001A63A8[9] = (*(s32 *)(state + 0xD4) & 0x3FFF) + 3000;
    D_001A63A8[10] = 0;
    func_002AAC80(state + 0x11C, 400.0f - D_L07_001B17E0, 5.0f,
                  D_L07_001B1748 * 0.00027777778f, D_L07_001B1744 * 0.016666668f);
    *(s32 *)(state + 0x16BC) = 0;
    *(s32 *)(state + 0x16B0) = 0;
    *(s32 *)(state + 0xD0) = group;
    *(f32 *)(state + 0x16B8) = 1.0f;
    func_L00_002B9D60(&D_L07_001B1800, &D_L07_001B17F0, 0x6F, 1);
    *(TI128 *)t = *(TI128 *)D_00189EA0;
    t[2] = t[2] + 1.0f;
    *(TI128 *)w = 0;
    w[2] = func_2E49C8(D_L07_00189E20[0x20] - D_L07_001B1810, D_L07_00189E20[0x21] - D_L07_001B1814);
    r = func_2E4508(t, &D_L07_001B1810);
    w[1] = func_2E49C8(r, D_L07_001B1818 - t[2]);
    func_00335438(&D_L07_001B1810, w, 1, 0, 0);
    func_L07_004106B8(a0);
    for (p = D_L07_001A9014[group];
         p != 0 && ((s16)p[-1] >= 0 || p == D_L07_001A9014[group]) &&
         (e = D_L07_001B2954 + ((*p & 0x7FFF) << 5)) != 0;
         p++) {
        e[0x1E] |= 4;
    }
    D_L07_001B1E90 = 0;
}
