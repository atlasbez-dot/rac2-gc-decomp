#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002A7A00(void *, float, float);
extern void *func_002C3150(void *, void *, unsigned int, int, int, int, float);
extern int D_L00_001AEE38 __attribute__((sda));
extern int D_L00_001AEE3C[] __attribute__((sda));
extern int D_L00_001AEE40[] __attribute__((sda));
extern int D_L00_001AEE44[] __attribute__((sda));
extern float D_L00_001AEE10 __attribute__((sda));
extern float D_L00_001AEE14[] __attribute__((sda));
extern float D_L00_001AEE20 __attribute__((sda));
extern float D_L00_001AEE24[] __attribute__((sda));
extern unsigned int D_L00_001AEE28[4] __attribute__((sda));


void func_L00_00384E08(unsigned char *object, void *position)
{
    char buffer[16];
    unsigned int *table=D_L00_001AEE28;
    void *data=*(void **)(object+0x68);
    int state=(unsigned char)func_002A7820(D_L00_001AEE38,D_L00_001AEE3C[0]);
    unsigned int *entry=table+object[0xBC]*2;
    int random=(unsigned char)func_002A77E0(255);
    func_002C3150(position,data,entry[0],state,random,0,D_L00_001AEE20);
    func_002A7A00(buffer,D_L00_001AEE10*0.01666666753590107f,D_L00_001AEE14[0]*0.01666666753590107f);
    state=(unsigned char)func_002A7820(D_L00_001AEE40[0],D_L00_001AEE44[0]);
    entry=(unsigned int *)((char *)table+((object[0xBC]<<3)|4));
    random=(unsigned char)func_002A77E0(255);
    func_002C3150(position,buffer,entry[0],state,random,0,D_L00_001AEE24[0]);
}
