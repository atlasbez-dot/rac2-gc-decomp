/* func_L16_002D2D10, 88 bytes, 1 placement (level 16).  Closest candidate: 76 bytes
   (the retail's four extra `nop`s).

   The store order in the source is the lever: the earlier attempt assigned
   f278 before f274, and this cc1 then computed 1/f12 first (`div.s $f1,$f0,$f12`)
   and stored it at +0x274.  With f274 assigned first, the divisions and the
   stores come out in retail's order:

     retail: div.s $f1,$f0,$f13 ; swc1 $f0,0x27C ; div.s $f0,$f0,$f12 ;
             swc1 $f1,0x278 ; swc1 $f0,0x274
     this:   div.s $f1,$f0,$f13 ; s.s   $f0,636 ; div.s $f0,$f0,$f12 ;
             s.s   $f1,632 ; s.s   $f0,628

   What is still missing is the pair of standalone `nop`s retail has before each
   `div.s` (four in all, 16 bytes).  They are not delay-slot nops - the div.s
   stands alone - and this cc1 and its assembler never emit one there; the
   game's as only fills a delay slot (tools/compiler/patches/0051 touches the
   FPR hazard nops, and it is the delay-slot search that uses them).  The same
   pair appears in other retail bodies of this level (for instance at
   0x002AACF0 before `div.s $f12,$f12,$f4`), while other div.s in the same
   listing have none, so it is not a blanket rule on the division.  The body: */

typedef unsigned char u8;
typedef signed int s32;
typedef float f32;

typedef struct {
    u8 pad[0x274];
    f32 f274;
    f32 f278;
    f32 f27C;
    s32 i280;
} T_001B99C0;

extern T_001B99C0 D_L16_001B99C0;

void func_L16_002D2D10(s32 a0, f32 f12, f32 f13) {
    if (D_L16_001B99C0.f27C == 0.0f) {
        D_L16_001B99C0.i280 = a0;
        D_L16_001B99C0.f27C = 1.0f;
        D_L16_001B99C0.f274 = 1.0f / f12;
        D_L16_001B99C0.f278 = 1.0f / f13;
    }
}
