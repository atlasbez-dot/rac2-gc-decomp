/* func_L01_004171C8 (284 bytes, 1 place, level 01, profile -O2 -G8, needs a -g8.c unit)
   -- measured 0 of 1: SIZE IS 292, retail is 284; first difference at +0x18.

   Arms a measured primitive for the hero and the object it follows:

     m = func_305EE8(0x1250);                [ the new object ]
     if (m == 0) return (s32)m;
     st = *(u8 **)(m + 0x68);
     *(u64 *)(m + 0x38) = *(u64 *)((u8 *)g_pHeroMoby[0] + 0x38);
     *(TI128 *)(m + 0x10) = *(TI128 *)arg0;
     *(u16 *)(m + 0x32) = 0x5A;  *(u8 *)(m + 0x30) = 0x40;  *(u8 *)(m + 0x31) = 1;
     *(u32 *)st = (u32)arg1;
     *(TI128 *)(st + 0x10) = *(TI128 *)(m + 0x10);
     t = *(f32 *)(m + 0xF8);   *(f32 *)(st + 0x1C) = t;
     t = func_310648();        *(f32 *)(m + 0xF0) = t;
     t = func_310648();        *(f32 *)(m + 0xF4) = t;
     t = func_310648();        *(f32 *)(m + 0xF8) = t;
     t = func_310648();        *(f32 *)(m + 0xFC) = t;
     *(u32 *)(st + 8) = (u32)arg3;
     *(u32 *)(st + 4) = (u32)arg2;
     *(f32 *)(st + 0x60) = D_L01_001B1A70 * 0.0002908882452175021f;
     *(f32 *)(st + 0x68) = D_L01_001B1A68 * 0.0002908882452175021f;
     *(f32 *)(st + 0x64) = D_L01_001B1A6C * 0.0002908882452175021f;
     *(u8 *)(m + 0x20) = 1;
     func_L01_00416B30(m);
     return (s32)m;

   Measured: the three constants at D_L01_001B1A68/6C/70 are $gp-relative and
   their values are multiplied, so this needs -G8; under -G0 the loads come out
   as lui+lw.  The allocation, the four calls to func_310648 (they take no
   argument and return a float) and the two 16-byte copies match.  Three things
   are left:

   1. the registers: retail saves $s0-$s5 and reuses $s3 (the first argument's
      register, dead after the copy) for the constant 1; this cc1 saves $s0-$s6
      and keeps the constant in $s1, which costs one register and four bytes.

   2. the hero's field: retail loads the hero's pointer into $a0 and reads
      0x38($a0); this cc1 loads it into $v1 and reads 0x38($v1) - the same
      shape, but the register differs.

   3. the float constants: retail loads all three before the multiplications
      ($f4, $f3, $f2) and multiplies in the order of the stores; this cc1 loads
      each constant right before its multiplication and keeps the multiplier in
      $f2 instead of $f1.  */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int s32;
typedef float f32;

extern s32 func_305EE8(s32 size);
extern f32 func_310648(void);
extern u32 g_pHeroMoby[];
extern f32 D_L01_001B1A68 __attribute__((sda));
extern f32 D_L01_001B1A6C __attribute__((sda));
extern f32 D_L01_001B1A70 __attribute__((sda));
extern void func_L01_00416B30(void *a0);

/* 128-bit copies reach lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

s32 func_L01_004171C8(void *a0, void *a1, void *a2, void *a3)
{
    u8 *m;
    u8 *st;
    f32 t;

    m = (u8 *)func_305EE8(0x1250);
    if (m == 0)
        return (s32)m;
    st = *(u8 **)(m + 0x68);
    *(u64 *)(m + 0x38) = *(u64 *)((u8 *)g_pHeroMoby[0] + 0x38);
    *(TI128 *)(m + 0x10) = *(TI128 *)a0;
    *(u16 *)(m + 0x32) = 0x5A;
    *(u8 *)(m + 0x30) = 0x40;
    *(u8 *)(m + 0x31) = 1;
    *(u32 *)st = (u32)a1;
    *(TI128 *)(st + 0x10) = *(TI128 *)(m + 0x10);
    t = *(f32 *)(m + 0xF8);
    *(f32 *)(st + 0x1C) = t;
    t = func_310648();
    *(f32 *)(m + 0xF0) = t;
    t = func_310648();
    *(f32 *)(m + 0xF4) = t;
    t = func_310648();
    *(f32 *)(m + 0xF8) = t;
    t = func_310648();
    *(f32 *)(m + 0xFC) = t;
    *(u32 *)(st + 8) = (u32)a3;
    *(u32 *)(st + 4) = (u32)a2;
    *(f32 *)(st + 0x60) = D_L01_001B1A70 * 0.0002908882452175021f;
    *(f32 *)(st + 0x68) = D_L01_001B1A68 * 0.0002908882452175021f;
    *(f32 *)(st + 0x64) = D_L01_001B1A6C * 0.0002908882452175021f;
    *(u8 *)(m + 0x20) = 1;
    func_L01_00416B30(m);
    return (s32)m;
}
