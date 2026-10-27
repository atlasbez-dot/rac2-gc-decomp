/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 5636/5868 bytes. us: 0/1 places; us2: 0/1 places; pal: absent.
 * Remaining: Grelbin retail initializes noise Z before publishing its full vector; this
 * order is preserved. The three range guards reject ordered greater-than
 * values rather than also rejecting NaNs. Actual aligned 64-bit state masks
 * are preserved, and all sixteen-byte transfers use clobbering qcopy. Own
 * projection/query measurements justify the sequential 64-byte phase union;
 * twenty-point arrays, four five-point strips and 128 disabled pointers remain
 * complete. The frame is 0x430 versus retail 0x440; seven-FPR lifetimes,
 * geometry/query scheduling and branch allocation remain different. The
 * 32-bit count returned by 277F48 is intentionally ignored, never declared void.
 * Reopen with: Independent Grelbin geometry/query and FP-spill lifetime evidence. Never
 * restore copy-before-Z-zero, reject NaNs differently, shrink workspaces or
 * add padding to manufacture the frame. Full runtime semantics remain unverified.
 */

#include "common.h"

typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct { Vec direction; int owner,flags; unsigned char type,active; unsigned short class_id; float material; int enabled; } HitPacket;
extern unsigned char D_00139568[];
extern char *D_0018C0B0 NOT_SDA;
extern char *D_L19_001FB960[];
extern char *D_L19_001BFE98 NOT_SDA;
typedef struct { unsigned char prefix[4]; unsigned char upgraded; unsigned char gap[0x6b]; float power; unsigned char tail[0x6c]; } WeaponRecord;
extern WeaponRecord D_L19_00265870[];
extern Vec D_00189EA0,D_0018A0E0,D_0018A560,D_0018A570,D_L19_001A8F20,D_L19_001BFEA0,D_L19_001B9A40;
extern float D_L19_001B9A58,D_00189EB8;
extern int D_L19_001A8FF0,D_L19_001B32C0;
extern short D_L19_001B32C8[],D_L19_001B32D0[],D_L19_001B32D8[],D_L19_001B32E0[];
extern Vec D_L19_0023A5D0[20],D_L19_0023A710[20],D_L19_0023A8A0[20],D_L19_0023AA30[20];
extern float D_L19_0023A850[20],D_L19_0023A9E0[20];
extern float D_L19_001AF014 __attribute__((sda)),D_L19_001AF018 __attribute__((sda)),D_L19_001AF01C __attribute__((sda)),D_L19_001AF020 __attribute__((sda)),D_L19_001AF024 __attribute__((sda)),D_L19_001AF028 __attribute__((sda)),D_L19_001AF02C __attribute__((sda)),D_L19_001AF030 __attribute__((sda)),D_L19_001AF034 __attribute__((sda)),D_L19_001AF038 __attribute__((sda)),D_L19_001AF03C __attribute__((sda)),D_L19_001AF040 __attribute__((sda)),D_L19_001AF044 __attribute__((sda)),D_L19_001AF048 __attribute__((sda)),D_L19_001AF04C __attribute__((sda)),D_L19_001AF050 __attribute__((sda)),D_L19_001AF064 __attribute__((sda)),D_L19_001AF068 __attribute__((sda)),D_L19_001AF0A8 __attribute__((sda)),D_L19_001AF0AC __attribute__((sda));
extern unsigned int D_L19_001AF078 __attribute__((sda));
extern float func_00283B98(float,float),func_00283BE0(float,float),func_00283C80(float,float),func_00283248(float,float),func_002831B0(float),func_00283180(float),func_00283198(float),func_002ABB18(float),func_00283CE0(int),func_002A78D8(float,float),func_002A7878(float,float);
extern int func_00283CF0(float),func_00282948(int *),func_00282978(s16 *),func_002A77E0(int),func_002A7820(int,int),func_002761F8(void *,void *,int,void *,void *);
extern float func_00282E20(void *),func_00282DF0(void *),func_00282DB0(void *,void *),func_00282E48(void *,void *);
extern int func_002AB1F0(unsigned char *);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *),func_00282D30(void *,void *,float),func_00282F20(void *,void *,float),func_00282D08(void *,void *,void *,float),func_00282DD8(void *,void *,void *),func_00282C88(void *),func_00300190(void *,void *),func_002ACEC0(void *,void *,void *,float);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern int func_00277F48(void *,int,void *,void *,float);
extern void func_002A8E20(void *,void *);
extern void *func_002C2210(void *,int,int,int,int,void *,int,float,float,float);
#define I(p,o) (*(int *)((p)+(o)))
#define F(p,o) (*(float *)((p)+(o)))
#define H(p,o) (*(short *)((p)+(o)))
#define P(p,o) (*(char **)((p)+(o)))
void func_L19_00390F78(char *obj) {
    struct { Vec first,second,temp; HitPacket collision; Vec direction,delta,blend,step,offset;
        char *disabled[128]; Vec toward;
        /* Grelbin retail places projection at 0x2C0, first query at 0x2D0
         * and the later second query at 0x2C0. Projection is consumed before
         * query construction; both queries are dead before the spark phase. */
        union {
            struct { Vec scratch; HitPacket hit1; } primary;
            HitPacket secondary;
        } queries;
        Vec segments[4]; } frame;
    char *ctx=P(obj,0x68),*candidate,*definition,*best=0,*runner=0,*hit,**list;
    Vec *point,*other,*branch;
    int upgraded,blocked=0,disabled=0,i,j,k,rotation,firsthalf;
    float bestscore=0,secondscore=0,reach=D_L19_001AF014,distance,score,heading,playerangle,dot,length,scale=0,amplitude,phase,wave,noise,blend,angle,sideangle,size;
    upgraded=D_L19_00265870[D_00139568[0x12]].upgraded!=0;
    D_L19_001AF02C=func_00283B98(D_L19_001AF02C,D_L19_001AF030);
    D_L19_001AF034=func_00283BE0(D_L19_001AF034,D_L19_001AF038);
    D_L19_001AF048=func_00283B98(D_L19_001AF048,D_L19_001AF04C);
    if(!P(ctx,0x20) || (upgraded && !P(ctx,0x38))) {
        if(!P(ctx,0x38)) {
            for(list=D_L19_001FB960;(candidate=*list)!=0;++list) {
                if(candidate==P(ctx,0x20) || candidate==P(ctx,0x38) || !candidate || !P(candidate,0x24) || H(P(candidate,0x24),0x46)!=5) continue;
                if(((u8 *)candidate)[0x20]==254 || ((u8 *)candidate)[0x20]==253) continue;
                definition=(char *)func_002AB1F0((unsigned char *)candidate); if(!definition) continue;
                func_00282CF0(&frame.first,candidate+0x10,ctx);
                if(!D_L19_001A8FF0) distance=func_00282E20(&frame.first);
                else {
                    dot=func_00282DB0(&frame.first,D_0018C0B0+0xE0);
                    func_00282D30(&frame.second,D_0018C0B0+0xE0,dot); func_00282CF0(&frame.temp,&frame.first,&frame.second); distance=func_00282DF0(&frame.temp);
                }
                if(distance>D_L19_001AF014) continue;
                heading=func_00283C80(D_L19_001B9A58,func_00283248(F(candidate,0x10)-D_L19_001B9A40.f[0],F(candidate,0x14)-D_L19_001B9A40.f[1]));
                if(heading>D_L19_001AF01C) continue;
                playerangle=0;
                if(!D_L19_001A8FF0) playerangle=func_00283C80(func_00283248(F(candidate,0x10)-D_00189EA0.f[0],F(candidate,0x14)-D_00189EA0.f[1]),D_00189EB8);
                else {
                    func_00282CF0(&frame.second,candidate+0x10,&D_00189EA0);
                    dot=func_00282DB0(&frame.second,D_0018C0B0+0xE0); func_00282D30(&frame.temp,D_0018C0B0+0xE0,dot); func_00282CF0(&frame.second,&frame.second,&frame.temp);
                    dot=func_00282DB0(&frame.second,D_0018C0B0+0xC0); length=func_00282DF0(&frame.second); if(length==0) continue;
                    playerangle=1.5707964f-func_002831B0(dot/length);
                }
                if(playerangle>D_L19_001AF018) continue;
                score=((D_L19_001AF01C-heading)/D_L19_001AF01C)*D_L19_001AF0AC+(D_L19_001AF014-distance)/D_L19_001AF014;
                if(bestscore<score) { runner=best; secondscore=bestscore; bestscore=score; best=candidate; }
                else if(secondscore<score) { secondscore=score; runner=candidate; }
            }
        } else { P(ctx,0x20)=P(ctx,0x38); H(ctx,0x40)=H(ctx,0x42); P(ctx,0x38)=0; H(ctx,0x42)=0; }
    }
    if(best) {
        if(!P(ctx,0x20)) { H(ctx,0x40)=0; P(ctx,0x20)=best; if(func_00282948(&D_L19_001B32C0)) D_L19_001B32C0=10; }
        else runner=best;
    }
    if(runner && upgraded) {
        distance=func_00282E48(ctx,best+0x10);
        if(distance<D_L19_001AF014 && distance+func_00282E48(best+0x10,runner+0x10)<D_L19_001AF014) { H(ctx,0x42)=0; P(ctx,0x38)=runner; }
    }
    distance=0;
    if(P(ctx,0x20)) {
        definition=(char *)func_002AB1F0((unsigned char *)P(ctx,0x20)); candidate=P(ctx,0x20); qcopy(&frame.first, (candidate+0x10));
        func_00282D30(&frame.second,candidate+0xE0,F(definition,0x10)); func_00282CC0(&frame.first,&frame.first,&frame.second);
        reach=distance=func_00282E48(ctx,&frame.first);
    }
    if(P(ctx,0x38)) {
        definition=(char *)func_002AB1F0((unsigned char *)P(ctx,0x38)); candidate=P(ctx,0x38); qcopy(&frame.second, (candidate+0x10));
        func_00282D30(&frame.temp,candidate+0xE0,F(definition,0x10)); func_00282CC0(&frame.second,&frame.second,&frame.temp);
        reach=func_00282E48(&frame.first,&frame.second)+distance;
    }
    reach*=0.05f;
    if(upgraded) D_L19_001AF078=0x207F20; else D_L19_001AF078=0x7F2020;
    func_00282C88(&frame.temp);
    func_002A8C00((char *)&frame.collision,(int)obj,0x210000,D_L19_00265870[D_00139568[0x12]].power,(Quad16 *)&frame.temp);
    frame.collision.class_id=*(unsigned short *)(obj+0xAA); frame.collision.active=1; frame.collision.type=5; H(ctx,0x3E)=20;
    func_00277F48(ctx,0x10,D_0018C0B0,&frame.collision,0.3f);
    func_00282CF0(&frame.direction,ctx+0x10,ctx); func_00282F20(&frame.direction,&frame.direction,1.0f);
    if(P(ctx,0x20) || P(ctx,0x38)) { func_00282DD8(&frame.delta,&frame.direction,&D_0018A0E0); func_002ACEC0(&frame.direction,&frame.direction,&frame.delta,0.17453295f); }
    func_00282D30(&frame.step,&frame.direction,reach);
    qcopy(&D_L19_0023A5D0[0], ctx); qcopy(&D_L19_0023A710[0], ctx);
    for(i=1;i<=19;++i) {
        point=&D_L19_0023A5D0[i]; other=&D_L19_0023A710[i];
        amplitude=D_L19_001AF024+(D_L19_001AF028-D_L19_001AF024)*func_00283CE0(i)*0.05f;
        phase=func_002ABB18(D_L19_001AF02C+(float)i*D_L19_001AF020);
        wave=func_00283198(phase); noise=func_002A78D8(D_L19_001AF064,D_L19_001AF068); noise=amplitude*wave+noise;
        point->f[2]-=D_L19_0023A850[i]; D_L19_0023A850[i]=noise;
        func_00300190(point,point);
        func_00282CF0(&frame.delta,point,&D_L19_0023A5D0[i-1]); func_00282D08(&frame.blend,&frame.delta,&frame.step,0.85f);
        length=func_00282DF0(&frame.blend);
        if(length==0) qcopy(point, &D_L19_0023A5D0[i-1]);
        else { func_00282D30(&frame.blend,&frame.blend,reach/length); func_00282CC0(point,&D_L19_0023A5D0[i-1],&frame.blend); qcopy(&frame.step, &frame.blend); }
        point->f[2]+=noise; func_00282CF0(&frame.delta,point,&D_L19_0023A5D0[i-1]);
        if(P(ctx,0x20)) {
            if(!upgraded || !P(ctx,0x38)) {
                func_00282CF0(&frame.toward,&frame.first,point); length=func_00282DF0(&frame.toward);
                if(length!=0) {
                    if(i==19) { blend=0.5f; reach=length; } else if(i<16) blend=0.1f; else { blend=0.5f; reach=length/func_00283CE0(19-i); }
                    func_00282D30(&frame.toward,&frame.toward,reach/length); func_00282D08(&frame.step,&frame.step,&frame.toward,blend);
                }
            } else {
                if(i<10) func_00282CF0(&frame.toward,&frame.first,point); else func_00282CF0(&frame.toward,&frame.second,point);
                length=func_00282DF0(&frame.toward);
                if(length!=0) {
                    if(i==9 || i==19) { blend=0.7f; reach=length; }
                    else if((unsigned int)i-5<5 || i>14) { blend=0.7f; reach=length/func_00283CE0(i<10?9-i:19-i); } else blend=0.2f;
                    func_00282D30(&frame.toward,&frame.toward,reach/length); func_00282D08(&frame.step,&frame.step,&frame.toward,blend);
                }
            }
        }
        if(i<10) {
            phase=func_002ABB18(D_L19_001AF034+(float)i*D_L19_001AF03C);
            angle=func_002ABB18(D_L19_001AF048+(float)i*D_L19_001AF050);
            amplitude=D_L19_001AF040*func_00283198(angle); qcopy(other, point);
            wave=func_00283198(phase); noise=func_002A78D8(0.0f,0.1f); noise=amplitude*wave+noise;
            D_L19_0023A9E0[i]=noise; other->f[2]+=noise;
            angle=func_00283B98(func_00283248(frame.delta.f[0],frame.delta.f[1]),1.5707965f);
            amplitude=D_L19_001AF044*func_00283180(phase);
            frame.offset.f[0]=func_00283180(angle)*amplitude; frame.offset.f[1]=func_00283198(angle)*amplitude;
            frame.offset.f[2]=0; qcopy(&D_L19_0023A8A0[i], &frame.offset); func_00282CC0(other,other,&frame.offset);
        } else { qcopy(other, point); other->f[2]+=D_L19_0023A9E0[21-i]; func_00282CC0(other,other,&D_L19_0023A8A0[21-i]); qcopy(&frame.offset, &D_L19_0023A8A0[i]); }
        if(i>1 && (i==19 || !(i&1))) {
            func_00282CF0(&frame.temp,point,&D_L19_001B9A40);
            if(!D_L19_001A8FF0) frame.temp.f[2]=0; else { dot=func_00282DB0(&frame.temp,D_0018C0B0+0xE0); func_00282D30(&frame.toward,D_0018C0B0+0xE0,dot); func_00282CF0(&frame.temp,&frame.temp,&frame.toward); }
            length=func_00282DF0(&frame.temp); if(length==0) frame.temp.f[2]=1.0f; else func_00282D30(&frame.temp,&frame.temp,1.0f/length);
            frame.temp.f[3]=5627.925f; qcopy(&frame.collision.direction, &frame.temp);
            blocked=func_002761F8(&D_L19_0023A5D0[i-2],point,0x10,obj,0);
            if(blocked) {
                hit=D_L19_001BFE98;
                if(hit) { definition=(char *)func_002AB1F0((unsigned char *)hit); if(!definition || !P(hit,0x24) || H(P(hit,0x24),0x46)!=5) func_002A8E20(hit,&frame.collision); else { blocked=0; frame.disabled[disabled++]=hit; I(hit,0x98)=0; } }
                if(blocked) { qcopy(point, &D_L19_001BFEA0); H(ctx,0x3E)=i; qcopy((ctx+0x10), &D_L19_001BFEA0); if(!D_L19_001BFE98) { P(ctx,0x20)=0; H(ctx,0x40)=0; } break; }
            }
        }
    }
    for(i=0;i<disabled;++i) { hit=frame.disabled[i]; I(hit,0x98)=I(P(hit,0x24),0x10); }
    if(!blocked) qcopy((ctx+0x10), &D_L19_0023A5D0[19]);
    if(P(ctx,0x20) && !(*(u64 *)(ctx+0x40) & 0xFFFF0000FFFFULL)) {
        func_00282CF0(&frame.toward,P(ctx,0x20)+0x10,&D_L19_001B9A40);
        if(!D_L19_001A8FF0) frame.toward.f[2]=0; else { dot=func_00282DB0(&frame.toward,D_0018C0B0+0xE0); func_00282D30(&frame.queries.primary.scratch,D_0018C0B0+0xE0,dot); func_00282CF0(&frame.toward,&frame.toward,&frame.queries.primary.scratch); }
        func_00282F20(&frame.toward,&frame.toward,1.0f); frame.toward.f[3]=5627.925f;
        func_002A8C00((char *)&frame.queries.primary.hit1,(int)obj,0x210000,D_L19_00265870[D_00139568[0x12]].power,(Quad16 *)&frame.toward);
        frame.queries.primary.hit1.class_id=*(unsigned short *)(obj+0xAA); frame.queries.primary.hit1.active=3; frame.queries.primary.hit1.type=5;
        func_002A8E20(P(ctx,0x20),&frame.queries.primary.hit1); definition=(char *)func_002AB1F0((unsigned char *)P(ctx,0x20)); H(ctx,0x44)=definition && H(definition,4)==1?1:5;
    }
    if(P(ctx,0x38) && !(*(u64 *)(ctx+0x40) & 0xFFFF0000FFFF0000ULL)) {
        func_00282CF0(&frame.toward,P(ctx,0x38)+0x10,&D_L19_001B9A40);
        if(!D_L19_001A8FF0) frame.toward.f[2]=0; else { dot=func_00282DB0(&frame.toward,D_0018C0B0+0xE0); func_00282D30(&frame.queries.primary.scratch,D_0018C0B0+0xE0,dot); func_00282CF0(&frame.toward,&frame.toward,&frame.queries.primary.scratch); }
        func_00282F20(&frame.toward,&frame.toward,1.0f); frame.toward.f[3]=5627.925f;
        func_002A8C00((char *)&frame.queries.secondary,(int)obj,0x210000,D_L19_00265870[D_00139568[0x12]].power,(Quad16 *)&frame.toward);
        frame.queries.secondary.class_id=*(unsigned short *)(obj+0xAA); frame.queries.secondary.active=3; frame.queries.secondary.type=5;
        func_002A8E20(P(ctx,0x38),&frame.queries.secondary); definition=(char *)func_002AB1F0((unsigned char *)P(ctx,0x38)); H(ctx,0x46)=definition && H(definition,4)==1?1:5;
    }
    for(i=0;i<4;++i) {
        if(i<2) { qcopy(&frame.queries.primary.scratch, ctx); scale=0.4f; } else { qcopy(&frame.queries.primary.scratch, (ctx+0x10)); scale=0.5f; }
        branch=&D_L19_0023AA30[i*5];
        if(!func_00282978(&D_L19_001B32C8[i])) {
            for(j=0;j<4;++j) {
                func_00282CF0(&frame.segments[j],&branch[j+1],&branch[j]);
                frame.segments[j].f[0]+=func_002A78D8(0.0f,0.1f); frame.segments[j].f[1]+=func_002A78D8(0.0f,0.1f); frame.segments[j].f[2]+=func_002A78D8(0.0f,0.1f);
            }
            qcopy(&branch[0], &frame.queries.primary.scratch);
            for(j=0;j<4;++j) func_00282CC0(&branch[j+1],&branch[j],&frame.segments[j]);
            k=D_L19_001B32C8[i]-D_L19_001B32E0[i]; if(k<0) k=-k;
            length=func_00283CE0(k); amplitude=func_00283CE0(15); D_L19_001B32D0[i]=func_00283CF0((1.0f-length/amplitude)*32.0f);
        } else {
            D_L19_001B32C8[i]=D_L19_001B32D8[i]; D_L19_001B32D0[i]=0;
            angle=func_002A78D8(0.52359885f,1.0471977f); sideangle=func_002A7878(-1.0471977f,0.17453295f);
            func_00282D30(&frame.toward,&frame.direction,scale); func_002ACEC0(&frame.toward,&frame.toward,&D_0018A560,sideangle); func_002ACEC0(&frame.toward,&frame.toward,&D_0018A570,angle);
            qcopy(&branch[0], &frame.queries.primary.scratch); func_00282CC0(&branch[1],&frame.queries.primary.scratch,&frame.toward); scale=1;
            for(j=1;j<4;++j) { func_00282CF0(&frame.queries.primary.hit1,&branch[j],&D_L19_001B9A40); angle=func_002A7878(0.17453295f,0.9599312f)*scale; scale=-scale; func_002ACEC0(&frame.toward,&frame.toward,&frame.queries.primary.hit1,angle); func_00282CC0(&branch[j+1],&branch[j],&frame.toward); }
        }
    }
    angle=func_002A78D8(0.52359885f,1.0471977f); sideangle=func_002A7878(-0.52359885f,1.0471977f);
    func_00282D30(&frame.toward,&frame.direction,D_L19_001AF0A8); func_002ACEC0(&frame.toward,&frame.toward,&D_0018A560,sideangle); func_002ACEC0(&frame.toward,&frame.toward,&D_0018A570,angle);
    rotation=func_002A7820(1,8); if(func_002A77E0(2)) rotation=-rotation; size=func_002A7878(0.2f,0.6f);
    func_002C2210(ctx,15,D_L19_001AF078|0x7F000000,0,rotation,&frame.toward,1,size*0.3f,size,0);
    func_002C2210(ctx,15,0x307F7F7F,0,-rotation,&frame.toward,1,size*0.15f,size*0.5f,0);
    rotation=func_002A7820(1,8); if(func_002A77E0(2)) rotation=-rotation; size=func_002A7878(0.15f,3.0f);
    func_002C2210(ctx+0x10,12,D_L19_001AF078|0x7F000000,0,rotation,&D_L19_001A8F20,1,size*0.1f,size,0);
}
