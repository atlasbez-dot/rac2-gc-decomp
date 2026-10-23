#include "include_asm.h"
typedef unsigned int Quad __attribute__((mode(TI)));
extern int D_001A79F0[] __attribute__((sda));
extern int D_L00_001B90C4[] __attribute__((sda));
extern float D_L00_001B90C8[] __attribute__((sda));
extern int D_L00_001B273C[] __attribute__((sda));
extern Quad D_L00_001AECC0[4] __attribute__((sda));
extern float func_L00_00382BF0(void *);
extern void func_L00_00382CE8(void *);
extern void func_L00_00382F28(void *);
extern void func_L00_002E6CF0(void (*)(void *), void *);


void func_L00_00382AE8(unsigned char *object)
{
    Quad *data=*(Quad **)(object+0x68);
    switch (object[0x20]) {
    case 0: {
        int level;
        int index=0;
        object[0x30]=255;
        object[0x20]=1;
        D_L00_001B90C4[0]=0;
        level=D_001A79F0[0];
        if (level==0) D_L00_001B273C[0]=0x49;
        else if (level==3) D_L00_001B273C[0]=0x40;
        else if (level==7) { D_L00_001B273C[0]=0x3F; index=1; }
        else if (level==12) { D_L00_001B273C[0]=0x41; index=2; }
        else if (level==14) { D_L00_001B273C[0]=0x4D; index=3; }
        *data=D_L00_001AECC0[index];
        func_L00_00382CE8(object);
        break;
    }
    case 1: {
        D_L00_001B90C8[0]=func_L00_00382BF0(object);
        func_L00_002E6CF0(func_L00_00382F28,object);
        break;
    }
    }
}
