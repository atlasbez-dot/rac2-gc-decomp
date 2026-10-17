/* 0 of 27 places match - last line: 00_aranos_tutorial: instruction at +0x4 differs
   Right size (56); the only difference is the register this cc1 gives the loaded flag
   and where it schedules the frame setup: retail lui $v0,0x1B / lw $v0,-0x7010($v0)
   (address and value in the same register, %lo folded into the load) then bnez $v0,
   here lw $v1,0x0($v0) and bnez $v1 with the $sp adjust moved before the lui.
   Both branches, both calls and all argument moves (a0 = a1, a2 = 1) are exact.
   int, void* and pointer-typed spellings of the flag all give the same code.
   Note the caller func_L00_00325300 takes one argument and this one reads a1: the
   declaration in src is aliased (extern void f(u8*) __asm__("func_L00_003252C8")). */

typedef void *V;

extern int D_001A8FF0;

extern void func_00282C98(V);

extern void func_002AFFD8(V,V,int);

void func_L00_003252C8(V p,V q) {
 if(D_001A8FF0==0) {
  func_00282C98(q);
  return;
 }
 func_002AFFD8(p,q,1);
}