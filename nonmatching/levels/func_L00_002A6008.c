/* func_L00_002A6008 - 380 bytes, 19 places, level 00_aranos_tutorial at 0x002A6008.
   Wave 13 s4: 0 of 19 places match; the candidate is 356 bytes and every
   instruction of the body except six is exact.  The frame (0xB0), the four
   saved registers ($s0/$s1/$s2/$ra at 0x90/0x98/0xA0/0xA8), the resident
   layout (the object pointer at 0x1860, the second record at 0x90 with the
   float at 0x98 inside it, the pointer at 0x2290 and the mode word at 0x2294),
   the scratch (0x90 bytes, the record at 0x30, the two matrices at 0x40 and
   0x50), the branch shape (bnel, the two beqz guards, the bne on the mode
   word, the beq/beqz on the flag byte and the two calls to func_002A7470)
   and every call site are retail's own words.
   The six missing words are the materialisation of the four 128-bit copy
   addresses and of the two hoisted constants:
     retail: addiu $a0,$a2,0x10 ; addiu $v1,$s2,0x80 ; lq $v0,0($v1) ;
             sq $v0,0($a0) ; addiu $a0,$a2,0xF0 ; addiu $v1,$s2,0x90 ;
             lq $v0,0($v1) ; sq $v0,0($a0)
     here:   lq $v1,0x80($s2) ; sq $v1,0x10($a2) ; lq $v0,0x90($s2) ;
             sq $v0,0xF0($a2)
   and the third copy, retail `addiu $a1,$sp,0x30 ; addiu $v1,$a0,0x10 ;
   lq $v0,0($a1) ; sq $v0,0($v1)` against here `lq $v0,0x30($sp) ;
   sq $v0,0x10($v1)`.  Retail keeps every 128-bit address in a register and
   uses a zero offset; this cc1 folds the constant offset into the lq/sq.
   Measured with tools/s4_probe.py (private): a mode(TI) copy through a
   pointer variable, a one-member struct copy, a 16-byte struct assignment,
   an aligned(16) struct, a mode(TI) type based on int/long/float/char/short,
   memcpy and memmove of 16 bytes, a volatile destination, the address used
   twice, a variable offset, a 64-bit (s8) pointer cast, an inlined helper
   (static and __inline__) and the SDK compiler all give the folded form or
   a call; only a plain pointer with no offset (retail's own shape in the
   matched func_002A8C00) or a symbol address comes out materialised.  The
   same wall is recorded for func_L00_002A5CB0 and func_L00_002A5840, and
   in the repository for func_L00_00326620, func_L00_0032A1A8 and
   func_L18_003FC9B8.  What would unblock it: the original source
   expression tree, so this cc1 keeps the two addresses in registers. */

typedef unsigned char u8;

typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

typedef unsigned long long u64;

typedef float f32;

typedef int TI128 __attribute__((mode(TI)));

/* The second 16-byte record of the resident block: the float at 0x98 sits
   inside it. */
typedef union {
    TI128 q;
    struct {
        u8 pad[8];
        f32 f;
    } s;
} ResidentRec90;

/* The resident block: two 16-byte records, the object pointer and the fields
   the game walks. */
typedef struct {
    u8 pad000[0x80];
    TI128 q080;
    ResidentRec90 q090;
    u8 pad0a0[0x1860 - 0xa0];
    u8 *p1860;
    u8 pad1864[0x2290 - 0x1864];
    u8 *p2290;
    s32 f2294;
} ResidentState;

extern ResidentState D_00189E20;

extern void *func_0029EFD0(int);

extern void func_0029FC20(u8 *, s32, void *);

extern void func_002A0F48(u8 *);

extern void func_00283678(u8 *, void *);

extern void func_002A7470(u8 *, s32, s32, s32);

extern void func_00283410(void *, void *);

extern void func_00283788(void *, void *, void *);

extern void func_00282C88(void *);

/* The scratch the function works in. */
typedef struct {
    u8 pad000[0x30];
    TI128 v30;
    TI128 v40;
    TI128 v50;
    u8 pad060[0x30];
} Scratch;

/* A 16-byte record, the unit the game copies. */
typedef struct {
    TI128 v;
} ResidentQuad;

/* Creates the object the resident block points at, copies two resident records
   into it, sets its flags, then walks the resident record again. */
void func_L00_002A6008(void) {
  u8 *obj;
  Scratch s;
  ResidentQuad *dst1;
  ResidentQuad *src1;
  ResidentQuad *dst2;
  ResidentQuad *src2;

  if (D_00189E20.p1860 == 0) {
    obj = (u8 *)func_0029EFD0(0x47A);
    D_00189E20.p1860 = obj;
    if (obj == 0)
      goto end;
    dst1 = (ResidentQuad *)(obj + 0x10);
    src1 = (ResidentQuad *)&D_00189E20.q080;
    *dst1 = *src1;
    dst2 = (ResidentQuad *)(obj + 0xF0);
    src2 = (ResidentQuad *)&D_00189E20.q090.q;
    *dst2 = *src2;
    *(u16 *)(obj + 0x32) = 0x40;
    *(u8 *)(D_00189E20.p1860 + 0x31) = 1;
    *(u8 *)(D_00189E20.p1860 + 0x30) = 0;
    *(u16 *)(D_00189E20.p1860 + 0x34) = 0;
    func_002A0F48(D_00189E20.p1860);
    if (D_00189E20.p1860 == 0)
      goto end;
  }
  func_0029FC20(D_00189E20.p2290, 5, &s);
  *(TI128 *)(D_00189E20.p1860 + 0x10) = s.v30;
  func_002A0F48(D_00189E20.p1860);
  func_00282C88(&s.v40);
  *(f32 *)((u8 *)&s.v40 + 8) = -D_00189E20.q090.s.f;
  func_00283410(&s.v50, &s.v40);
  func_00283788(&s, &s, &s.v50);
  func_00283678(D_00189E20.p1860 + 0xC0, &s);
  *(u64 *)(D_00189E20.p1860 + 0x38) = *(u64 *)(D_00189E20.p2290 + 0x38);
  if (D_00189E20.f2294 == 0x4B) {
    if (*(u8 *)(D_00189E20.p1860 + 0x43) == 1)
      goto end;
    func_002A7470(D_00189E20.p1860, 1, 0, 0xA);
    goto end;
  }
  if (*(u8 *)(D_00189E20.p1860 + 0x43) == 0)
    goto end;
  func_002A7470(D_00189E20.p1860, 0, 0, 0x11);
end:
  return;
}
