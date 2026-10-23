/* Retained C, not matched.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   380/380 bytes; 0/19 USA and US2, first mismatch +0x4c; canonical name absent from PAL catalogue. Qualified qcopy/barrier materializes all copies, but second destination, constant and later object-pointer allocation still differ. Three fresh formulations; no new compiler mechanism. */

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
