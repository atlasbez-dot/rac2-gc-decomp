/* Alternative source form for func_L00_002A53B8.
   Retained from 53b8_v4.c, entry func_L00_002A53B8; declarations preserved.
   Naming/extraction only: this form has not been recompiled or validated
   by the cleanup. See the primary near-miss file for the recorded blocker;
   do not apply another form's verdict to this one. Recheck its file-level
   flags with tools/check.py, then tools/build.py before promotion. */
typedef unsigned char u8;
typedef int s32;
typedef struct {
 u8 p0[0x40];
 u8 a[0x20];
 u8 b[0x30];
 u8 c[0x1C];
 float f;
} Ent;
extern u8 D_L24_0025B710[];
extern void *func_L00_002A4FE8(short);
extern void func_0029F9F0(void *, void *);
extern void func_00282C88(void *);

void func_L00_002A53B8(void) {
 Ent *e=(Ent *)D_L24_0025B710;
 Ent *end=e+40;
 do {
  u8 *ep=(u8 *)e;
  if(ep[1]!=0) {
   void *x=func_L00_002A4FE8(*(short *)(ep+0xA2));
   if(x!=0) func_0029F9F0(x,ep);
  }
  func_00282C88(e->a);
  func_00282C88(e->b);
  func_00282C88(e->c);
  e->f=1.0f;
  e++;
 } while(e<end);
}
