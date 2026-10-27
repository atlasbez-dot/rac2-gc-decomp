/* func_L00_004143D0 (368 bytes) - NEAR MISS (M22, 2026-10-26).
 * Twin of func_L16_0041F950 (only the draw callee differs).  Default profile
 * "-O2 -G0 -ffunction-sections": 368/368 with the addressing right; about 13
 * words of scheduling left (func_0027DE50's argument setup, the 0.1f constant
 * vs the end load in both interpolations).  Tried swapped multiply operands, the
 * factor as a local and the end read inline.  On the permuter.
 */
#include "include_asm.h"
#include "common.h"
extern void func_002FC560(unsigned int,unsigned long long);
extern void func_0027DE50(int,int,int,int,unsigned int);
extern void func_L00_00415210(void *,int,int,float,float,float,float,float);
typedef struct { char prefix[0x150]; short width,height; } Screen;
extern Screen D_001A6480;
void func_L00_004143D0(char *object)
{
    char *state=*(char **)(object+0x68);
    int difference;
    float start,end;
    if (*(short *)(state+2)-*(short *)state<2 && *(short *)(state+4)!=0 && *(int *)(state+0x1c)!=0) {
        func_002FC560(0x42,0x48ULL);
        func_0027DE50(0,D_001A6480.height,0,D_001A6480.width,0x80808080u);
    }
    if (*(int *)(state+0x18)==0) return;
    difference=*(short *)(state+2)-*(short *)state;
    if (difference<10) {
        start=*(float *)(state+8); end=*(float *)(state+12);
        func_L00_00415210(object+0x10,0x3c,0,start+(end-start)*((float)difference*0.1f),0.5f,0.0f,0.0f,0.0f);
    } else if ((unsigned short)(*(unsigned short *)state-46)<4) {
        start=*(float *)(state+8); end=*(float *)(state+12);
        func_L00_00415210(object+0x10,0x3c,0,start+(end-start)*((float)(*(short *)state-45)*0.1f),0.5f,0.0f,0.0f,0.0f);
    }
}
