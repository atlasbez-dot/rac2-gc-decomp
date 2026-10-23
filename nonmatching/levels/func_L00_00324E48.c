/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x1c differs
   Right size (196): the 0x60 frame, the 0x10-byte stack buffer, the three calls and the
   five-float repack are all places. This cc1 swaps the two int parameters ($s1/$s2),
   hoists the second call's a1 into the first call's delay slot and moves the
   $a0 = $sp setup one instruction later. The float copies (f24,f22,f21,f20,f23) are in
   retail's order.

   Wave 8 (agent w8-08) corrected the body: retail does NOT call the VU0 routines
   func_00282D30 / func_00282CC0 but their C wrappers, func_2EE178 and func_2EE108:

     lui $s0,0x19 ; addiu $s0,$s0,-0x61E0     ; the global's address
     lw $v0,0x2290($s0)                       ; the matrix
     jal func_2EE178 ; addiu $a1,$v0,0xE0     ; scale the matrix's vector by 0.75
     jal func_2EE108 ; addiu $a1,$s0,0x80     ; add the global's vector
     jal func_L00_00324D18                    ; the five floats and the two pointers

   The global's address has to stay in a register (`u8 *b = D_00189E20;`): written
   inline, this cc1 folds the offsets into the symbol (one `lui`/`addiu` of
   D_00189E20+0x2290) where retail materialises the global once and uses the
   displacements 0x2290 and 0x80.

   What is left (measured on this source): the two pointer parameters land in $s2/$s1
   where retail puts them in $s1/$s2, the first call's $a0 = $sp is set up one
   instruction later than retail (whose first jal delay slot holds the $a1 = $v0+0xE0
   instead), and the second call's $a1 = $b+0x80 lands in the first call's delay slot.
   The float copies and every call are otherwise retail's. */

typedef int s32;
typedef float f32;
typedef unsigned char u8;

extern u8 D_00189E20[];

extern void func_2EE178(void *,void *,f32);

extern void func_2EE108(void *,void *,void *);

extern void func_L00_00324D18(void *,void *,void *,f32,f32,f32,f32,f32);

void func_L00_00324E48(void *a0,void *a1,f32 f1,f32 f2,f32 f3,f32 f4,f32 f5) {
 u8 *b=D_00189E20;
 u8 buf[0x10];
 func_2EE178(buf,(void *)(*(int *)(b+0x2290)+0xE0),0.75f);
 func_2EE108(buf,b+0x80,buf);
 func_L00_00324D18(buf,a0,a1,f1,f2,f3,f4,f5);
}
