/* Bounded manual reconstruction, 2026-10-23; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: func_L16_0041F950: 0 of 2 places match (src/levels/shared/L16_0041F950-draw.c); us2: func_L16_0041F950: 0 of 2 places match (src/levels/shared/L16_0041F950-draw.c); pal: func_L16_0041F950: 0 of 2 places match (src/levels/shared/L16_0041F950-draw.c)
 * 368/368 bytes, first difference +0x54; screen-field addressing and float interpolation scheduling differ. Verified the 32-bit/64-bit func_002FC560 interface; tried byte offsets and a measured screen layout. Reopen with evidence for the original screen declaration and expression order.
 * Historical screening note below predates this C reconstruction.
 */
/* func_L16_0041F950 - 368 bytes, 2 place(s), level 16_snivelak, retail at
   0x0041f950. Screened with tools/w10_screen.py: 4 call(s)
   [func_002FC560@0041F998, func_0027DE50@0041F9BC,
   func_L04_00459408@0041FA34, func_L04_00459408@0041FAA4]; data addresses
   materialised [0x1a0000, 0x80800000, 0x3dcc0000, 0x3dcc0000]; float
   constants [0x3f000000, 0x3f000000]; $gp-relative small data: no   saves:
   -; callee-saved registers saved [-]; words plain C cannot emit [COP1
   46800020@0x00a0, COP1 46800020@0x0114]. Head: addiu $sp, $sp, -0x20 ; sd
   $s1, 0x8($sp) ; sd $ra, 0x10($sp) ; daddu $s1, $a0, $zero ; sd $s0,
   0x0($sp) ; lw $s0, 0x68($s1). Not matched in this wave: the float code
   has to come out of the same expression tree to keep the FPU registers.
   What would unblock it: the exact source expression tree, so this cc1
   picks the same registers in the same order. */

#include "common.h"
extern void func_002FC560(unsigned int,unsigned long long);
extern void func_0027DE50(int,int,int,int,unsigned int);
extern void func_L04_00459408(void *,int,int,float,float,float,float,float);
typedef struct { char prefix[0x150]; short width,height; } Screen;
extern Screen D_001A6480;
void func_L16_0041F950(char *object)
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
        func_L04_00459408(object+0x10,0x3c,0,start+(end-start)*((float)difference*0.1f),0.5f,0.0f,0.0f,0.0f);
    } else if ((unsigned short)(*(unsigned short *)state-46)<4) {
        start=*(float *)(state+8); end=*(float *)(state+12);
        func_L04_00459408(object+0x10,0x3c,0,start+(end-start)*((float)(*(short *)state-45)*0.1f),0.5f,0.0f,0.0f,0.0f);
    }
}
