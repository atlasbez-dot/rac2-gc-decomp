/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier.
 * us: 1324/1340 bytes, 0/2 carrying placements.
 * us2: 1324/1340 bytes, 0/2 carrying placements.
 * pal: canonical name absent.
 * Two interface-qualified source trials. BeamQuery and ImpactInfo describe the observed fields
 * and extents; the optimizer eliminates the initial unused position copy, yielding a0xF0
 * instead of0x100 frame. Timer conversion uses state + 0x58, not the misleading Ghidra global
 * argument; clipping preserves the retail ordered comparisons for NaNs. Reopen with a
 * qualified query/temporary lifetime model.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* func_L02_00421860 - 1340 bytes, 2 place(s), level 02_maktar_nebula,
   retail at 0x00421860. Screened with tools/w10_screen.py: 33 call(s)
   [func_002AFFD8@004218B4, func_00282CC0@004218DC, func_00282F20@00421914,
   func_002761F8@0042194C, func_002E5CF8@00421974,
   func_L02_00421DA0@00421990, func_L02_00421DA0@004219AC,
   func_L02_00422270@004219C0, func_002A8BD0@004219DC,
   func_00277F48@00421A18, func_00282948@00421A28, func_002A7878@00421A48,
   func_002A77E0@00421A5C, func_002A7878@00421AA4, func_002A7878@00421AB8,
   func_002A7878@00421AC8, func_00282F20@00421AE4, func_002A7878@00421AFC,
   func_002C2210@00421B2C, func_002C2210@00421B58, func_00283CE0@00421B80,
   func_00283CE0@00421B8C, 0x1163b0@00421B98, func_002A77E0@00421BC4,
   func_002A7878@00421BEC, func_002A7878@00421BFC, func_002A7878@00421C0C,
   func_002A7878@00421C1C, func_00282F20@00421C3C, func_002C2210@00421C74,
   func_002C2210@00421CB8, func_0029F338@00421D48,
   func_L02_00422538@00421D58]; data addresses materialised [0x10000,
   0x45af0000, 0x1c0000, 0x1c0000, 0x1c0000, 0x810000, 0x3f4c0000,
   0x3eb30000, 0x3e7a0000, 0x3f330000, 0x3ccc0000, 0x3dcc0000, 0x3ccc0000,
   0x3d4c0000, 0x3b650000, 0x3d0f0000, 0x447f0000]; float constants
   [0x3f800000, 0xbf800000, 0x3f800000, 0xbf800000, 0x3f800000, 0x40000000];
   $gp-relative small data: no   saves: -; callee-saved registers saved [-];
   words plain C cannot emit [LQ/SQ 7A420000@0x0044, LQ/SQ 7FA20000@0x0048,
   LQ/SQ 7A420000@0x0060, LQ/SQ 7EA20000@0x0064, LQ/SQ 7A220000@0x00a4,
   LQ/SQ 7C820000@0x00a8]. Head: addiu $sp, $sp, -0x100 ; sd $s2, 0xA0($sp)
   ; sd $s3, 0xA8($sp) ; sd $s0, 0x90($sp) ; daddu $s3, $a0, $zero ; sd $s1,
   0x98($sp). Not matched in this wave: the 128-bit copy needs an `lq`/`sq`
   pair; plain C reaches it only through a `mode(TI)` local, and this cc1
   folds the destination offset into the `sq` where retail materialises the
   pointer first. What would unblock it: the exact source expression tree,
   so this cc1 picks the same registers in the same order. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { Vector direction; u8 *source; u32 mask; u8 kind,enabled; u16 type; float strength; } ImpactInfo;
typedef struct { Vector previous,normal,start; ImpactInfo impact; int enabled; } BeamQuery;
typedef struct { u8 reserved[0x18]; u8 *other; u32 reserved1c; Vector position; } HitView;
extern HitView D_L02_001C0940 __attribute__((nosda));
extern float D_L02_001B1FBC __attribute__((sda)),D_L02_001B1FC0 __attribute__((sda));
extern float D_L02_001B1FB8 __attribute__((sda));
extern u32 D_L02_001B1FC8 __attribute__((sda)),D_L02_001B1FCC __attribute__((sda));
extern void func_002AFFD8(void *,void *,int);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern int func_002761F8(void *,void *,int,void *,int);
extern int func_002E5CF8(int,int,void *);
extern void func_L02_00421DA0(void *,int,int);
extern void func_L02_00422270(u8 *,void *);
extern void func_002A8BD0(char *,int,int,float);
extern int func_00277F48(void *,int,void *,void *,float);
extern int func_00282948(void *);
extern float func_002A7878(float,float);
extern int func_002A77E0(int);
extern float func_00283CE0(int);
extern int func_001163B0(void);
extern u8 *func_002C2210(void *,int,u32,int,int,void *,int,float,float,float);
extern void func_0029F338(void *);
extern void func_L02_00422538(u8 *);

/* Move and test the beam endpoint, then emit its fading or impact particles. */
void func_L02_00421860(u8 *object)
{
    BeamQuery query;
    ImpactInfo impact;
    u8 *state=*(u8 **)(object+0x68);
    float size;
    int sign,left;
    query.previous.q=*(Quad *)(object+0x10);
    func_002AFFD8(object+0x10,&query.normal,1);
    query.start.q=*(Quad *)(object+0x10);
    if(object[0x20]==0) {
        func_00282CC0(object+0x10,object+0x10,state+0x40);
        query.impact.source=object;
        query.impact.mask=0x10000;
        query.impact.strength=*(float *)(state+0x64);
        query.enabled=1;
        query.impact.direction.q=*(Quad *)(state+0x40);
        func_00282F20(&query.impact.direction,&query.impact.direction,1.0f);
        query.impact.type=*(u16 *)(object+0xAA);
        query.impact.enabled=1;
        query.impact.kind=1;
        query.impact.direction.f[3]=5627.9248046875f;
        if(func_002761F8(&query.start,object+0x10,0,object,0) && D_L02_001C0940.other!=*(u8 **)(state+0x50)) {
            func_002E5CF8(0,0,object);
            if(!D_L02_001C0940.other) func_L02_00421DA0(&D_L02_001C0940.position,5,0);
            else if(*(int *)(D_L02_001C0940.other+0x98)) func_L02_00421DA0(&D_L02_001C0940.position,10,1);
            func_L02_00422270(object,&D_L02_001C0940.position);
            func_002A8BD0((char *)&impact,(int)object,0x810001,*(float *)(state+0x64));
            impact.kind=2;impact.enabled=1;
            impact.type=*(u16 *)(*(u8 **)(state+0x50)+0xAA);
            func_00277F48(&D_L02_001C0940.position,16,object,&impact,0.8f);
            func_0029F338(object);
            return;
        }
    }
    if(func_00282948(state+0x58)) {
        size=func_002A7878(D_L02_001B1FBC,D_L02_001B1FC0);
        sign=func_002A77E0(2);if(sign==0)sign=-1;
        left=4;
        do {
            query.impact.direction.f[2]=func_002A7878(-1.0f,1.0f);
            query.impact.direction.f[1]=func_002A7878(-1.0f,1.0f);
            query.impact.direction.f[0]=func_002A7878(-1.0f,1.0f);
            func_00282F20(&query.impact.direction,&query.impact.direction,0.025f);
            query.impact.direction.f[2]=func_002A7878(0,0.1f);
            func_002C2210(object+0x10,60,D_L02_001B1FC8,0,sign,&query.impact.direction,0,size*0.35f,size,D_L02_001B1FB8);
            func_002C2210(object+0x10,60,D_L02_001B1FCC,1,sign,&query.impact.direction,0,size*0.245f,size*0.7f,D_L02_001B1FB8);
            sign=-sign;
        } while(--left>=0);
        func_0029F338(object);
        return;
    }
    if(*(int *)(state+0x58)<16) {
        *(float *)(state+0x60)=func_00283CE0(*(int *)(state+0x58))/func_00283CE0(15);
        if(func_001163B0()%3==0) {
            sign=func_002A77E0(2);if(sign==0)sign=-1;
            size=func_002A7878(D_L02_001B1FBC,D_L02_001B1FC0);
            query.impact.direction.f[2]=func_002A7878(-1.0f,1.0f);
            query.impact.direction.f[1]=func_002A7878(-1.0f,1.0f);
            query.impact.direction.f[0]=func_002A7878(-1.0f,1.0f);
            func_00282F20(&query.impact.direction,&query.impact.direction,0.025f);
            func_002C2210(object+0x10,60,D_L02_001B1FC8,0,sign,&query.impact.direction,0,size*0.05f,size,D_L02_001B1FB8);
            func_002C2210(object+0x10,60,D_L02_001B1FCC,1,sign,&query.impact.direction,0,size*0.0035f,size*0.035f,D_L02_001B1FB8);
        }
    }
    if(*(float *)(object+0x10)<2.0f || *(float *)(object+0x10)>1021.0f ||
       *(float *)(object+0x14)<2.0f || *(float *)(object+0x14)>1021.0f ||
       *(float *)(object+0x18)<2.0f || *(float *)(object+0x18)>1021.0f) func_0029F338(object);
    else func_L02_00422538(object);
}
