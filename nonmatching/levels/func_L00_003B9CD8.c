/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 2412 / 2444 bytes; size equality is not a match.
 * us: 0/1 placements; 2412/2444 bytes.
 * us2: 0/1 placements; 2412/2444 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: See the retained source comment for the measured residual.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* The prior manual layout is retained separately in alternatives/func_L00_003B9CD8-prior-layout.c. Neither variant matches; this selection does not establish semantic superiority. */

/* Unmatched manual reconstruction, G0: 2412 bytes versus 2444 in both USA releases.
 * The first difference is the GPR save at +0x4, with one fewer saved register;
 * case-4/8 position pointer lifetime and shared state transitions remain different.
 * Four bounded source-shape trials also produced 2380 and 2368 bytes.
 * This audit preserves 64-bit dispatch flags, the canonical A8D70 parameter order,
 * pointer returns, unsigned object bytes, and all four C700 stack arguments.
 * C700's float inputs and pointer/int inputs use independent ABI banks.
 * The float return of A89A8 was checked in retail; an old external declaration
 * elsewhere says void. No caller or compiler-output workaround is included here.
 * PAL has no catalogue entry for this canonical target. Behavior and linked-image
 * equality are unverified. Reopen after a demonstrated register-lifetime remedy.
 */
typedef unsigned int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vec;
extern char D_001886D4[],*D_0018C2BC,*D_L00_001FDA80[];
extern unsigned long func_002B1C20(void *,void *);
extern int func_00317D78(void),func_002B3890(void *),func_00282948(void *),func_002A7820(int,int);
extern void *func_002B60B0(unsigned char *,float,float,float,float);
extern int func_002E5CF8(int,int,char *);
extern void func_0029F338(void *),func_002A7750(void *,int,int),func_002A7470(void *,int,int,int),func_002E59F8(int),func_002A6C58(void *,int,int);
extern void *func_0032C700(float,float,void *,int,int,int,int,int,int,int,int,int,int,void *);
extern float func_00283B98(float,float),func_00283198(float),func_00282E80(void *,void *),func_002A89A8(void *,int,float);
extern int func_002B4FF0(char *,float *,float);
extern void func_00282CF0(void *,void *,void *),func_00282F20(void *,void *,float),func_00282CC0(void *,void *,void *),func_002A677C(void *),func_00318200(void *);
extern int func_002A8D70(float,float,float,void *,void *,int,int,int,int);
#define I(p,o) (*(int *)((p)+(o)))
#define F(p,o) (*(float *)((p)+(o)))
#define H(p,o) (*(short *)((p)+(o)))
#define U(p,o) (*(unsigned short *)((p)+(o)))
#define P(p,o) (*(char **)((p)+(o)))
#define UPDATE_SHAPE() if(func_002B3890(obj)) func_002B60B0(obj,0.006666667f,0.06666667f,0.8377582f,0.8377582f)
#define BEGIN_ATTACK() if(I(ctx,0x294)==-1) { func_002A7750(obj,6,2); F(obj,0x18)=F(ctx,0x28C); if(obj[0x43]!=2) func_002A7470(obj,2,0,5); } else func_002A7750(obj,4,2)
void func_L00_003B9CD8(unsigned char *obj) {
    struct { Vec point,delta; } frame;
    char *ctx=P(obj,0x68),*path;
    unsigned long result;
    int handle,i;
    float height,wave;
    if(func_00317D78()) { func_0029F338(obj); return; }
    switch((unsigned char)obj[0x95]) {
    case 0:
        UPDATE_SHAPE();
        if(I(ctx,0x258)==1 && func_00282948(ctx+0x2A4) && I(ctx,0x2AC)) { BEGIN_ATTACK(); }
        else if(H(ctx,0x276)) { func_002A7750(obj,3,1); H(ctx,0x276)=0; if(H(ctx,0x270)<300) H(ctx,0x270)=func_002A7820(480,600); }
        F(obj,0xF8)=func_00283B98(F(obj,0xF8),0.03490659f); break;
    case 1:
        UPDATE_SHAPE();
        if((I(ctx,0x258)==1 || I(ctx,0x25C)==1) && I(ctx,0x2AC)) { BEGIN_ATTACK(); }
        F(obj,0xF8)=func_00283B98(F(obj,0xF8),0.03490659f); break;
    case 2:
        UPDATE_SHAPE();
        if(I(ctx,0x258)!=1 && I(ctx,0x25C)!=1 && obj[0x20]!=4) { func_002A7750(obj,1,1); if(obj[0x43]) func_002A7470(obj,0,0,20); H(ctx,0x270)=func_002A7820(580,600); }
        break;
    case 3:
        result=func_002B1C20(obj,ctx+0x60);
        if(result&1) {
            handle=I(ctx,0x2A8); if(handle!=-1 && P(D_001886D4+handle*0x70,0x14)==obj && D_001886D4[handle*0x70]) func_002E59F8(handle);
            I(ctx,0x2A8)=-1; func_0032C700(0.3f,20.0f,obj+0x10,0,0,0,0,20,45,1,1,0,0,0); func_002E5CF8(0,0,obj); func_002A6C58(obj,0,3); func_0029F338(obj); return;
        }
        if(result&2) {
            if(I(ctx,0x258)!=1 && I(ctx,0x25C)!=1) { func_002A7750(obj,3,1); H(ctx,0x270)=func_002A7820(580,600); }
            else { func_002A7750(obj,5,2); if(obj[0x43]) func_002A7470(obj,0,0,5); if(I(ctx,0x294)!=-1) func_002A7750(obj,4,2); }
        }
        break;
    }
    switch((unsigned char)obj[0x20]) {
    case 1:
        if(U(obj,0x96)<26) {
            wave=func_00283198((float)U(obj,0x96)*0.12566361f); height=F(obj,0x18);
            if(F(ctx,0x28C)<height) F(obj,0x18)=height-wave*0.02f; else F(obj,0x18)=height+wave*0.02f;
        } else { if(obj[0x43]) func_002A7470(obj,0,0,5); func_002A7750(obj,2,-1); F(obj,0x18)=F(ctx,0x28C); }
        break;
    case 4:
        path=D_L00_001FDA80[I(ctx,0x294)]; i=I(ctx,0x298);
        if(i<I(path,0)) {
            frame.point.q=*(Quad *)(path+i*16+16);
            func_00282CF0(&frame.delta,&frame.point,obj+0x10); func_00282F20(&frame.delta,&frame.delta,F(ctx,0x1C0)); func_00282CC0(obj+0x10,obj+0x10,&frame.delta);
            if(func_00282E80(obj+0x10,&frame.point)<0.5f) ++I(ctx,0x298);
            if(I(path,0)-6<=I(ctx,0x298) && F(ctx,0x1C0)>=0.10000001f) F(ctx,0x1C0)-=0.0022222223f;
            height=func_002A89A8(obj+0x10,0,0.5f); if(F(obj,0x18)<height+0.5f) F(obj,0x18)=height+0.5f;
            F(ctx,0x28C)=F(obj,0x18); func_002A677C(obj);
        } else { I(ctx,0x294)=-1; F(ctx,0x28C)=func_002A89A8(obj+0x10,0,0.5f)+0.5f; func_002A7750(obj,5,-1); }
        F(obj,0xF8)=func_00283B98(F(obj,0xF8),0.03490659f); break;
    case 5:
        height=F(obj,0x18); func_002B4FF0(obj,ctx+0x230,F(ctx,0x290)); F(obj,0x18)=height;
        if(func_00282E80(obj+0x10,P(ctx,0x240)+0x10)<1.3f) func_002A7750(obj,7,-1);
        F(obj,0xF8)=func_00283B98(F(obj,0xF8),0.03490659f); break;
    case 6:
        if(obj[0x60]&2) { if(obj[0x43]!=3) func_002A7470(obj,3,0,5); func_002A7750(obj,8,-1); } break;
    case 7:
        if(U(obj,0x96)>=30) { func_002A7750(obj,6,-1); if(obj[0x43]!=1) func_002A7470(obj,1,0,2); F(obj,0x48)=1.0f; } break;
    case 8:
        F(obj,0x48)=1.75f;
        for(i=0;i<4;++i) func_002A8D70(0.17f,F(ctx,0x2B0),1.0f,obj,(void *)i,1,0,1,0);
        if(D_0018C2BC==obj) func_002A7750(obj,9,-1);
        if(func_00282E80(obj+0x10,P(ctx,0x240)+0x10)>1.3f && (float)U(obj,0x96)>120.0f) { if(obj[0x43]) func_002A7470(obj,0,0,15); func_002A7750(obj,5,-1); F(obj,0x48)=1.0f; } break;
    case 9:
        if((float)U(obj,0x96)>20.0f) { func_002A7750(obj,10,-1); if(obj[0x43]!=4) func_002A7470(obj,4,0,5); F(obj,0x48)=1.0f; } break;
    case 10:
        if(obj[0x60]&2) { if(obj[0x43]) func_002A7470(obj,0,0,15); func_002A7750(obj,5,-1); } break;
    }
    if(obj[0x20]!=4 && obj[0x95]==2 && F(obj,0x18)<F(ctx,0x28C)) F(obj,0x18)=F(ctx,0x28C);
    func_00318200(obj);
}
