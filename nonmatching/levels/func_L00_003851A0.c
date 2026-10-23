#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern int func_002A7820(int, int);
extern int func_002A77E0(int);
extern void func_002A7A00(void *, float, float);
extern void func_00282CC0(void *, void *, void *);
extern void *func_002C3150(void *, void *, unsigned int, int, int, int, float);
extern int D_L00_001AEE68 __attribute__((sda));
extern float D_L00_001AEE70 __attribute__((sda));
extern unsigned int D_L00_001AEE6C __attribute__((sda));
extern float D_L00_001AEE74[] __attribute__((sda));
extern float D_L00_001AEE84[] __attribute__((sda));
extern int D_L00_001AEE90[] __attribute__((nosda));
extern int D_L00_001AEE94[] __attribute__((sda));


void func_L00_003851A0(void *unused, void *source)
{
    char buffer[0x20];
    int i=0;
    char *second=buffer+0x10;
    if (D_L00_001AEE68 > 0) {
        float scale = 0.01666666753590107f;
        do {
            int state, random;
            func_002A7A00(buffer, 0.0f, 0.0333000011742115f);
            i++;
            func_00282CC0(buffer, buffer, source);
            func_002A7A00(second, D_L00_001AEE70*scale, D_L00_001AEE74[0]*scale);
            state = (unsigned char)func_002A7820(D_L00_001AEE90[0], D_L00_001AEE94[0]);
            random = (unsigned char)func_002A77E0(255);
            func_002C3150(buffer,second,D_L00_001AEE6C,state,random,0,D_L00_001AEE84[0]);
        } while (i < D_L00_001AEE68);
    }
}
