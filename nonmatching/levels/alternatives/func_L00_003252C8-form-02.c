/* Alternative source form for func_L00_003252C8.
   Retained from 3252C8_c.c, entry func_L00_003252C8; declarations preserved.
   Naming/extraction only: this form has not been recompiled or validated
   by the cleanup. See the primary near-miss file for the recorded blocker;
   do not apply another form's verdict to this one. Recheck its file-level
   flags with tools/check.py, then tools/build.py before promotion. */
typedef void *V;
extern V D_001A8FF0;
extern void func_00282C98(V);
extern void func_002AFFD8(V,V,int);

void func_L00_003252C8(V p,V q) {
 if(D_001A8FF0==0) {
  func_00282C98(q);
  return;
 }
 func_002AFFD8(p,q,1);
}
