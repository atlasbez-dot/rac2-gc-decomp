/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier.
 * us: 856/1232 bytes, 0/2 carrying placements.
 * us2: 856/1232 bytes, 0/2 carrying placements.
 * pal: canonical name absent.
 * One complete readable reconstruction. Shared primary/secondary submission sites factor the
 * four branch variants, preserving their random draws, trajectory modifications, colours,
 * factors and per-object byte 9 update. Retail keeps separate submission branches; the smaller
 * body is not a match. Reopen with an unmerged branch/float-lifetime reconstruction.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* func_L02_00421DA0 - 1232 bytes, 2 place(s), level 02_maktar_nebula,
   retail at 0x00421da0. Screened with tools/w10_screen.py: 31 call(s)
   [func_00282CF0@00421E04, func_002A7878@00421E68, func_002A77E0@00421E74,
   func_002A7878@00421EA0, func_002ACEC0@00421EB4, func_002A7878@00421EC0,
   func_00282F20@00421ED4, func_002A7878@00421EE0, func_002A78D8@00421EFC,
   func_002A78D8@00421F14, func_002A78D8@00421F2C, 0x1163b0@00421F44,
   func_00282D30@00421F64, func_002C2210@00421F9C, func_00283CF0@00421FB8,
   func_00282CF0@00421FF8, func_00282F20@00422008, func_00282CC0@00422018,
   func_002C2210@00422050, func_00283CF0@0042206C, 0x1163b0@00422090,
   func_00282D30@004220B0, func_002C2210@004220E8, func_00283CF0@00422104,
   func_00282CF0@00422144, func_00282F20@00422154, func_00282CC0@00422164,
   func_002C2210@00422198, func_00283CF0@004221B4, func_002C2210@004221F4,
   func_00283CF0@00422210]; data addresses materialised [0x1c0000,
   0x3c880000, 0x3e190000, 0x3f330000, 0x3f860000, 0xbf860000, 0x3eb30000,
   0x3e7a0000, 0x40030000, 0x3fb70000, 0x3e990000, 0x3e570000, 0x3e330000];
   float constants [0x3f800000, 0x3fc00000, 0x40800000, 0x40800000,
   0x3fc00000, 0x40800000, 0x3e800000, 0x40800000, 0x40800000]; $gp-relative
   small data: no   saves: -; callee-saved registers saved [-]; words plain
   C cannot emit [LQ/SQ 7AA20000@0x0150, LQ/SQ 7E420000@0x0154]. Head: addiu
   $sp, $sp, -0xD0 ; sd $s0, 0x50($sp) ; sd $s5, 0x78($sp) ; daddu $s0, $a1,
   $zero ; sd $s6, 0x80($sp) ; daddu $s5, $a0, $zero. Not matched in this
   wave: the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it only
   through a `mode(TI)` local, and this cc1 folds the destination offset
   into the `sq` where retail materialises the pointer first. What would
   unblock it: the exact source expression tree, so this cc1 picks the same
   registers in the same order. */

typedef unsigned char u8;
typedef unsigned int u32;
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
    while(count>0) {
        float size,speed,primaryFactor,secondaryFactor;
        int sign,attract,duration;
        u8 *particle;
        size=func_002A7878(D_L02_001B1FBC,D_L02_001B1FC0);
        sign=func_002A77E0(2);
        if(sign==0) sign=-1;
        func_002ACEC0(&velocity,&base,&axis,func_002A7878(-1.0471977f,1.0471977f));
        speed=func_002A7878(D_L02_001B1FA8,D_L02_001B1FAC)*0.016666668f;
        func_00282F20(&velocity,&velocity,speed);
        velocity.f[2]=func_002A7878(D_L02_001B1FB0,D_L02_001B1FB4)*0.016666668f;
        position.q=*(Quad *)origin;
        position.f[0]+=func_002A78D8(0,0.15f);
        position.f[1]+=func_002A78D8(0,0.15f);
        position.f[2]+=func_002A78D8(0,0.15f);
        attract=func_001163B0()&1;
        if(attract) {
            func_00282CF0(&toward,D_L02_001BA3C0.position,&position);
            func_00282F20(&toward,&toward,speed);
            func_00282CC0(&velocity,&velocity,&toward);
            duration=40;
            if(inner) {primaryFactor=0.25f;secondaryFactor=0.175f;}
            else {primaryFactor=2.05f;secondaryFactor=1.4350001f;}
        } else {
            func_00282D30(&velocity,&velocity,1.5f);
            duration=60;
            if(inner) {primaryFactor=0.3f;secondaryFactor=0.21000001f;}
            else {primaryFactor=0.35f;secondaryFactor=0.245f;}
        }
        particle=func_002C2210(&position,duration,D_L02_001B1FC8,0,sign,&velocity,0,size*primaryFactor,size,D_L02_001B1FB8);
        if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
        particle=func_002C2210(&position,duration,D_L02_001B1FCC,1,-sign,&velocity,0,size*secondaryFactor,size*0.7f,D_L02_001B1FB8);
        if(particle) particle[9]=(u8)(func_00283CF0(4.0f)+0x70);
        count--;
    }
}
