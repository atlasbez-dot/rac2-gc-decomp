/*
 * Retained complete manual C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections
 * 1224/1232 bytes.
 * us: 0/2 placements; us2: 0/2 placements; pal: absent from catalogue.
 * Residual: The four actual inner/outer and attracted/outward branches retain random draw
 * order, distinct factory submissions, pointer/null returns and byte9 updates. The0xD0 frame
 * agrees. Splitting these real branches improves856 to1216 bytes; separating loop/sign
 * lifetimes reaches1224. Saved-GPR priorities, base/axis pointers and call scheduling still
 * differ.
 * Reopen: Independent base/axis and remaining-count lifetime evidence; retain all four branch
 * variants and the exact physical seven-GPR/three-FP particle factory inputs.
 * Trial-only source markers and profiles are restored after checking.
 */

#include "common.h"

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { u8 reserved[0x140]; float position[4]; } FlareTargetView;
extern FlareTargetView D_L02_001BA3C0 __attribute__((nosda));
extern float D_L02_001B1FA8 __attribute__((sda)),D_L02_001B1FAC __attribute__((sda));
extern float D_L02_001B1FB0 __attribute__((sda)),D_L02_001B1FB4 __attribute__((sda));
extern float D_L02_001B1FB8 __attribute__((sda));
extern float D_L02_001B1FBC __attribute__((sda)),D_L02_001B1FC0 __attribute__((sda));
extern u32 D_L02_001B1FC8 __attribute__((sda)),D_L02_001B1FCC __attribute__((sda));
extern void func_00282CF0(void *,void *,void *);
extern float func_002A7878(float,float);
extern int func_002A77E0(int);
extern void func_002ACEC0(void *,void *,void *,float);
extern void func_00282F20(void *,void *,float);
extern float func_002A78D8(float,float);
extern int func_001163B0(void);
extern void func_00282D30(void *,void *,float);
extern u8 *func_002C2210(void *,int,u32,int,int,void *,int,float,float,float);
extern int func_00283CF0(float);
extern void func_00282CC0(void *,void *,void *);

/* Emit paired particles, choosing an outward or target-directed trajectory. */
void func_L02_00421DA0(void *origin,int count,int inner)
{
    Vector velocity,position,base,axis,toward;
    func_00282CF0(&base,D_L02_001BA3C0.position,origin);
    base.f[2]=0;
    axis.f[0]=0;axis.f[1]=0;axis.f[2]=1;axis.f[3]=1;
    if(count<=0) return;
    {
    int left=count;
    do {
        float size,speed;
        int sign;
        u8 *particle;
        size=func_002A7878(D_L02_001B1FBC,D_L02_001B1FC0);
        sign=func_002A77E0(2);
        sign=sign?sign:sign-1;
        func_002ACEC0(&velocity,&base,&axis,func_002A7878(-1.0471977f,1.0471977f));
        speed=func_002A7878(D_L02_001B1FA8,D_L02_001B1FAC)*0.016666668f;
        func_00282F20(&velocity,&velocity,speed);
        velocity.f[2]=func_002A7878(D_L02_001B1FB0,D_L02_001B1FB4)*0.016666668f;
        qcopy(&position,origin);
        position.f[0]+=func_002A78D8(0,0.15f);
        position.f[1]+=func_002A78D8(0,0.15f);
        position.f[2]+=func_002A78D8(0,0.15f);
        /* Retail keeps distinct inner/outer and outward/attracted submissions. */
        if(!inner) {
            if(!(func_001163B0()&1)) {
                func_00282D30(&velocity,&velocity,1.5f);
                particle=func_002C2210(&position,60,D_L02_001B1FC8,0,sign,&velocity,0,size*0.35f,size,D_L02_001B1FB8);
                if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
                particle=func_002C2210(&position,60,D_L02_001B1FCC,1,-sign,&velocity,0,size*0.245f,size*0.7f,D_L02_001B1FB8);
            } else {
                func_00282CF0(&toward,D_L02_001BA3C0.position,&position);
                func_00282F20(&toward,&toward,speed);
                func_00282CC0(&velocity,&velocity,&toward);
                particle=func_002C2210(&position,40,D_L02_001B1FC8,0,sign,&velocity,0,size*2.05f,size,D_L02_001B1FB8);
                if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
                particle=func_002C2210(&position,40,D_L02_001B1FCC,1,-sign,&velocity,0,size*1.4350001f,size*0.7f,D_L02_001B1FB8);
            }
        } else {
            if(!(func_001163B0()&1)) {
                func_00282D30(&velocity,&velocity,1.5f);
                particle=func_002C2210(&position,60,D_L02_001B1FC8,0,sign,&velocity,0,size*0.3f,size,D_L02_001B1FB8);
                if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
                particle=func_002C2210(&position,60,D_L02_001B1FCC,1,-sign,&velocity,0,size*0.21000001f,size*0.7f,D_L02_001B1FB8);
            } else {
                func_00282CF0(&toward,D_L02_001BA3C0.position,&position);
                func_00282F20(&toward,&toward,speed);
                func_00282CC0(&velocity,&velocity,&toward);
                particle=func_002C2210(&position,40,D_L02_001B1FC8,0,sign,&velocity,0,size*0.25f,size,D_L02_001B1FB8);
                if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
                particle=func_002C2210(&position,40,D_L02_001B1FCC,1,-sign,&velocity,0,size*0.175f,size*0.7f,D_L02_001B1FB8);
            }
        }
        if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
    } while(--left);
    }
}
