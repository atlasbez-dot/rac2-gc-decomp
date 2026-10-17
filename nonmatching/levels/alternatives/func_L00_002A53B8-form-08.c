/* Alternative source form for func_L00_002A53B8.
   Retained from 53b8_g3.c, entry func_L00_002A53B8; declarations preserved.
   Naming/extraction only: this form has not been recompiled or validated
   by the cleanup. See the primary near-miss file for the recorded blocker;
   do not apply another form's verdict to this one. Recheck its file-level
   flags with tools/check.py, then tools/build.py before promotion. */
typedef unsigned char u8;
typedef int s32;
extern u8 D_L24_0025B710[];
extern void *func_L00_002A4FE8(short);
extern void func_0029F9F0(void *, void *);
extern void func_00282C88(void *);

void func_L00_002A53B8(void) {
 u8 *base=D_L24_0025B710;
 u8 *q=base+0x40;
 u8 *s=base+0x90;
 u8 *r=base+0x60;
 u8 *p=base;
 u8 *limit=p+0x1bc0;
 do {
  if(p[1]!=0) {
   void *e=func_L00_002A4FE8(*(short *)(p+0xA2));
   if(e!=0) {
    u8 *pp=p;
    func_0029F9F0(e,pp);
   }
  }
  func_00282C88(q);q+=0xb0;
  func_00282C88(r);r+=0xb0;
  func_00282C88(s);s+=0xb0;
  *(float *)(p+0xAC)=1.0f;
  p+=0xb0;
 } while((s32)q<(s32)limit);
}
