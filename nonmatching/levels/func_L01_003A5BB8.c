/* Measured with -O2 -G8 -ffunction-sections. US: 01_oozla: 1124 bytes, expected 1136; 0/1 placements.
   US2: canonical function absent. PAL: canonical function absent. Four source trials, plus an
   unsupported -fno-crossjumping trial (removed). State machine and mixed integer/float call signatures
   reconstructed. Remaining control-flow merging and scheduling differences. Cached story-state value
   is preserved across calls. Reopen with a matching state-machine branch-layout witness.
 */

#include "common.h"
#define F(p,o) (*(float *)((u8 *)(p)+(o)))
#define I(p,o) (*(int *)((u8 *)(p)+(o)))
extern void *D_L01_001FE180[];
extern float D_L01_001AF85C __attribute__((sda));
extern float D_L01_001AF860 __attribute__((sda));
extern int D_L01_001AF864 __attribute__((sda));
extern int D_001A79F0;
extern u8 D_001A7A6D;
extern int D_L01_001A907C;
extern void func_0029F338(void *);
extern float func_00282E48(void *,void *);
extern float func_00282C48(float);
extern void func_002C9828(void *,int,void *,void *,int,float);
extern void func_002A7470(void *,int,int,int);
extern int func_002A9640(void *,int,int);
extern void func_00283098(void *,void *,void *);
extern void func_002E5E58(int,int,int);
extern void func_002B0A18(int,int);
extern int func_002B3868(void *);
extern void func_002AC728(void *,void *,int,float,float);
extern void func_002E5CF8(int,int,void *);
extern void func_00282CC0(void *,void *,void *);
extern float func_00283B98(float,float);
extern float func_002A89A8(void *,int,float);
extern void func_002A7750(void *,int,int);
extern void func_L01_003A6028(void *);
extern void func_L00_00326110(void *,int,float);
extern int func_00282948(void *);
void func_L01_003A5BB8(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    u8 *path = D_L01_001FE180[I(state,0x50)];
    float first, last, oldHeight;
    int mode;
    switch (object[0x20]) {
    case 0:
        if (I(state,0x50) == -1) { func_0029F338(object); return; }
        D_L01_001AF864 = 0;
        first = func_00282E48(path + 0x10,path + 0x20);
        last = func_00282E48(path + 0x10,path + I(path,0)*16);
        F(state,0x74) = (D_L01_001AF85C * 0.016666668f) / first;
        I(state,0x70) = func_00282C48(first-last) < 0.1f;
        F(state,0x5C) = F(state,0x58) * I(path,0);
        object[0x20] = 1;
        object[0x30] = 255;
        F(object,0x2C) *= D_L01_001AF860;
    case 1:
        oldHeight = F(object,0x18);
        func_002C9828(path,I(state,0x70),object+0x10,object+0xF0,0,F(state,0x5C));
        F(object,0xF4) *= 0.5f;
        F(object,0x18) += F(state,0x54);
        F(state,0x5C) += F(state,0x74);
        if (F(state,0x5C) > I(path,0)) F(state,0x5C) -= I(path,0);
        if (object[0x60] & 2) {
            if (oldHeight < F(object,0x18)) {
                if (object[0x43] != 0) func_002A7470(object,0,0,10);
            } else if (object[0x43] != 1) func_002A7470(object,1,0,10);
        }
        if (!func_002A9640(object,0x10000,0)) return;
        F(state,0x60) = D_L01_001AF85C * 0.008333334f;
        func_00283098(state+0x60,state+0x60,object+0xC0);
        D_L01_001AF864++;
        F(state,0x68) = -0.0500000045f;
        mode = D_001A79F0;
        if (D_L01_001AF864 > 3 && mode == 1 && !D_001A7A6D) {
            D_001A7A6D = 1;
            func_002E5E58(1,0,0);
            func_002B0A18(0x1233,-1);
            D_L01_001A907C = mode;
        }
        mode = 2;
        break;
    case 2:
        if (func_002B3868(object)) {
            func_002AC728(object,object+0x10,-1,0.5f,13.0f);
            func_002E5CF8(0,0,object);
        }
        F(object,0x48) = 0.5f;
        func_00282CC0(object+0x10,object+0x10,state+0x60);
        F(state,0x68) -= 0.003f;
        F(state,0x60) *= 0.98f;
        F(state,0x64) *= 0.98f;
        F(object,0xF0) = func_00283B98(-3.1415927f,(F(object,0xF0)+3.1415927f)*0.95f);
        if (func_00282C48(func_002A89A8(object+0x10,0,0.5f)-F(object,0x18)) >= 0.5f) return;
        I(state,0x78) = 30;
        mode = 3;
        break;
    case 3:
        if (func_002B3868(object)) {
            func_L01_003A6028(object);
            func_002E5CF8(1,0,object);
            func_L00_00326110(object,1,0.0f);
        }
        F(object,0x18) += F(state,0x68);
        if (func_00282948(state+0x78)) func_0029F338(object);
        return;
    default:
        return;
    }
    func_002A7750(object,mode,-1);
}
