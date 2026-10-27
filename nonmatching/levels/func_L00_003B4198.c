/* Near miss (M5): 964/964 B, 24 lines off at the 27 places, all in the first block's
   scheduling: retail loads the state pointer before the $gp limit, puts the %hi of
   D_L00_001B8DC0 between the packet-state stores (so 0xFF9000000260 lands in $a2), and
   places the D_0018A0E0 %hi and the D_L00_001AF940 base differently around two calls.
   Solved here: Ring.age is signed (lh), D_L00_001B28AC an incomplete sda array read [0]
   (retail's `lui $at; lwc1` macro form), `low + -high * t`, life as one expression, the
   packet's state[3] store before state[2], and separate locals for the second colour,
   radius and corner counter (retail allocates them apart). The -g and qcopy-barrier
   flags both matter. Profile `-O2 -G64 -ffunction-sections -Wa,-G64 -frac2-qcopy
   -frac2-qcopy-barrier -g`. */
#include "include_asm.h"
typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union {TI128 q;float v[4];} Vector;
typedef struct {Vector corners[4];u32 colors[4];Vector uv[2];u64 state[4];} SurfacePacket;
typedef struct {int reserved00;short age;unsigned short reserved06;short active,reserved0A;} Ring;
extern Ring D_L00_0023D960[10];
extern Vector D_L00_001B8DC0,D_0018A0E0;
extern float D_L00_001B28AC[] __attribute__((sda));
extern int D_L00_001AF8E0 __attribute__((sda));
extern int D_L00_001AF938 __attribute__((sda));
extern u32 D_L00_001AF93C __attribute__((sda));
extern Vector D_L00_001AF940[4] __attribute__((sda));
extern float D_L00_001AF980 __attribute__((sda)),D_L00_001AF984 __attribute__((sda));
extern float D_L00_001AF988 __attribute__((sda));
extern u32 D_L00_001AF98C __attribute__((sda)),D_L00_001AF990 __attribute__((sda));
extern float D_L00_001AF994 __attribute__((sda));
extern float func_00283CE0(int),func_002A78D8(float,float);
extern int func_00283CF0(float);
extern u64 func_0027C878(int);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern void func_00282F20(void *,void *,float),func_00282D30(void *,void *,float),func_00282DD8(void *,void *,void *);
extern void func_002830C0(void *,void *,void *),func_00280B90(void *,void *,int);
extern void func_L00_003B4560(unsigned char *,float),func_L00_003B5210(void);
void func_L00_003B4198(unsigned char *object)
{
    SurfacePacket packet;
    Vector transform[4],scaled;
    float life,t,low,high,size,radius;
    u32 color;
    int i,j,k,alpha;
    short age;
    if(object[0x20]!=2) {
        age=*(short *)(*(char **)(object+0x68)+8);
        if(age>=D_L00_001AF8E0-30) life=func_00283CE0(D_L00_001AF8E0-age)/func_00283CE0(30);
        else life=1.0f;
        packet.state[1]=func_0027C878(8);packet.state[3]=0x8000000048ULL;
        packet.state[2]=0xFF9000000260ULL;packet.state[0]=0;
        packet.uv[0].v[0]=0.0f;packet.uv[0].v[1]=0.0f;packet.uv[0].v[2]=0.0f;packet.uv[0].v[3]=1.0f;
        packet.uv[1].v[0]=1.0f;packet.uv[1].v[1]=0.0f;packet.uv[1].v[2]=1.0f;packet.uv[1].v[3]=1.0f;
        func_00282CF0(&transform[0],&D_L00_001B8DC0,object+0x10);
        func_00282F20(&transform[0],&transform[0],1.0f);
        transform[3].q=*(TI128 *)(object+0x10);
        func_00282D30(&transform[2],&D_0018A0E0,-1.0f);
        func_00282DD8(&transform[1],&transform[0],&transform[2]);
        func_00282F20(&transform[1],&transform[1],1.0f);
        func_00282DD8(&transform[2],&transform[1],&transform[0]);
        for(i=0;i<10;++i)if(D_L00_0023D960[i].active) {
            t=func_00283CE0(D_L00_0023D960[i].age)*D_L00_001B28AC[0];if(t>1.0f)t=1.0f;
            size=D_L00_001AF980+(D_L00_001AF984-D_L00_001AF980)*t;
            low=func_00283CE0(D_L00_001AF938);high=func_00283CE0(D_L00_001AF938);
            alpha=func_00283CF0(life*(low+-high*t));
            packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=(D_L00_001AF93C&0xFFFFFF)|((u32)alpha<<24);
            for(j=0;j<4;++j) {
                func_00282D30(&scaled,&D_L00_001AF940[j],size);
                func_002830C0(&packet.corners[j],&scaled,transform);
            }
            func_00280B90(&packet,0,0);
        }
        packet.state[1]=func_0027C878(11);packet.state[3]=0x8000000044ULL;
        packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=(D_L00_001AF990&0xFFFFFF)|D_L00_001AF98C;
        func_00282F20(&transform[3],&transform[0],D_L00_001AF994);
        func_00282CC0(&transform[3],&transform[3],object+0x10);
        radius=D_L00_001AF988+func_002A78D8(0.0f,0.1f);
        for(k=0;k<4;++k) {
            func_00282D30(&scaled,&D_L00_001AF940[k],radius);
            func_002830C0(&packet.corners[k],&scaled,transform);
        }
        func_00280B90(&packet,0,0);
        func_L00_003B4560(object,life);
    }
    func_L00_003B5210();
}
