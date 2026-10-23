#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern int func_002A77E0(int);
extern void func_00282CC0(void *, void *, void *);
extern void *func_002C3150(void *, void *, unsigned int, int, int, int, float);
extern int func_001163B0(void);
extern void func_001163A0(int);
extern float func_002A78D8(float,float);
extern float func_002A7878(float,float);
extern int func_00283D38(int,int,float);
extern void func_00283098(void *,void *,void *);
extern int D_L00_001AEE48 __attribute__((sda));
extern float D_L00_001AEE58 __attribute__((sda));
extern float D_L00_001AEE5C[] __attribute__((sda));
extern int D_L00_001AEE50 __attribute__((sda));
extern int D_L00_001AEE54[] __attribute__((sda));
extern float D_L00_001AEE60 __attribute__((sda));
extern float D_L00_001AEE64[] __attribute__((sda));
extern char D_L00_001B8FF0[] __attribute__((sda));
extern char D_L00_001B8DC0[] __attribute__((sda));
extern char D_L00_001A8F20[] __attribute__((sda));


void func_L00_00385040(char *object)
{
    union { Quad bits; float f[4]; } local[2];
    char *data=*(char **)(object+0x68);
    int saved=func_001163B0();
    int i=0;
    func_001163A0(*(int *)(data+0x68));
    if (D_L00_001AEE48>0) {
        do {
            float size, amount;
            int colour, random;
            local[1].bits=0;
            local[1].f[0]=20.0f;
            local[1].f[1]=func_002A78D8(0.0f,D_L00_001AEE58);
            i++;
            local[1].f[2]=func_002A78D8(0.0f,D_L00_001AEE5C[0]);
            local[0].bits=local[1].bits;
            func_00283098(&local[0],&local[0],D_L00_001B8FF0);
            func_00282CC0(&local[0],&local[0],D_L00_001B8DC0);
            size=func_002A7878(D_L00_001AEE60,D_L00_001AEE64[0]);
            amount=func_002A7878(0.0f,1.0f);
            colour=func_00283D38(D_L00_001AEE50,D_L00_001AEE54[0],amount);
            random=(unsigned char)func_002A77E0(255);
            func_002C3150(&local[0],D_L00_001A8F20,colour,2,random,0,size);
        } while (i<D_L00_001AEE48);
    }
    func_001163A0(saved);
}
