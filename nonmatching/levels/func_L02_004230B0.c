/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G8 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier -frac2-zero-ti-barrier.
 * us: 1076/1132 bytes, 0/2 carrying placements.
 * us2: 1076/1132 bytes, 0/2 carrying placements.
 * pal: 1076/1132 bytes, 0/2 carrying placements.
 * One complete two-packet reconstruction, with the retail 0x1F0 frame. Random endpoint, both
 * texture headers, flipped UVs, tapered cross-sections and both submissions are present.
 * Packet/UV copy lowering and register lifetimes remain. Reopen with a natural aggregate/UV-
 * lifetime witness.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 * Initializer identity varies by carrying level; ref_L02_004230B0_00 preserves it.
 */

/* Superseded historical screen, retained for provenance. */
/* MMI (SPECIAL2) instruction: no C spelling. 1132 bytes, level
   02_maktar_nebula. Retail at 0x004230B0 carries the SPECIAL2 word
   0x70002CA9 (+0x012C) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { Vector point[4]; u32 color[4]; float uv[8]; u64 reserved,texture,setup,state; } QuadPacket;
typedef struct { u8 reserved[0x140]; float position[4]; } FlareTargetView;
extern FlareTargetView D_L02_001BA3C0 __attribute__((nosda));
extern u32 D_L02_001B1FE0 __attribute__((sda));
extern u32 D_L02_001B1FE4 __attribute__((sda));
extern float func_002A7878(float,float);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern u64 func_0027C878(int);
extern int func_001163B0(void);
extern void ref_L02_004230B0_00(char *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_002830C0(void *,void *,void *);
extern void func_00280B90(void *,void *,int);

/* Build two tapered strips from a beam point toward a random nearby endpoint. */
void func_L02_004230B0(u8 *object,void *position)
{
    QuadPacket outer,inner;
    Vector frame[4],endpoint,small,wide;
    u8 *state=*(u8 **)(object+0x68);
    u32 color;
    float size;
    endpoint.f[0]=func_002A7878(-1.0f,1.0f);
    endpoint.f[1]=func_002A7878(-1.0f,1.0f);
    endpoint.f[2]=func_002A7878(-1.0f,1.0f);
    func_00282F20(&endpoint,&endpoint,func_002A7878(0.25f,0.65f));
    func_00282CC0(&endpoint,position,&endpoint);
    outer.texture=func_0027C878(23);
    outer.setup=0xFF9000000260ULL;
    outer.reserved=0;
    outer.state=0x8000000040ULL|((u64)(func_001163B0()%2+1)<<2);
    outer.color[1]=D_L02_001B1FE0;outer.color[0]=D_L02_001B1FE0;outer.color[3]=D_L02_001B1FE0;outer.color[2]=D_L02_001B1FE0;
    inner.texture=func_0027C878(23);
    small.q=0;wide.q=0;
    color=D_L02_001B1FE4;
    inner.color[0]=color;inner.color[1]=color;
    inner.color[3]=color&0xFFFFFF;inner.color[2]=color&0xFFFFFF;
    inner.setup=0xFF9000000260ULL;inner.state=0x8000000048ULL;inner.reserved=0;
    small.f[3]=1;wide.f[3]=1;
    size=func_002A7878(0.1f,0.2f);
    small.f[2]=size**(float *)(state+0x60);
    wide.f[2]=(size+size)**(float *)(state+0x60);
    ref_L02_004230B0_00((char *)&outer);ref_L02_004230B0_00((char *)&inner);
    if (func_001163B0()&1) { inner.uv[5]=0;inner.uv[7]=1; }
    else { inner.uv[7]=0;inner.uv[5]=1; }
    outer.uv[0]=0;outer.uv[1]=inner.uv[5];outer.uv[2]=0;outer.uv[3]=inner.uv[7];outer.uv[4]=1;outer.uv[5]=inner.uv[5];outer.uv[6]=1;outer.uv[7]=inner.uv[7];
    inner.uv[0]=0;inner.uv[1]=inner.uv[5];inner.uv[2]=0;inner.uv[3]=inner.uv[7];inner.uv[4]=1;inner.uv[6]=1;
    func_00282CF0(&frame[0],&endpoint,position);
    func_00282F20(&frame[0],&frame[0],1.0f);
    func_00282CF0(&frame[1],D_L02_001BA3C0.position,position);
    func_00282DD8(&frame[2],&frame[1],&frame[0]);
    func_00282F20(&frame[2],&frame[2],1.0f);
    func_00282DD8(&frame[1],&frame[0],&frame[2]);
    frame[3].q=*(Quad *)position;
    outer.point[0].q=small.q;inner.point[0].q=wide.q;
    func_00282D30(&outer.point[1],&outer.point[0],-1.0f);
    func_00282D30(&inner.point[1],&inner.point[0],-1.0f);
    func_002830C0(&outer.point[0],&outer.point[0],frame);
    func_002830C0(&outer.point[1],&outer.point[1],frame);
    func_002830C0(&inner.point[0],&inner.point[0],frame);
    func_002830C0(&inner.point[1],&inner.point[1],frame);
    frame[3].q=endpoint.q;
    small.f[2]*=0.15f;wide.f[2]=small.f[2]+small.f[2];
    outer.point[2].q=small.q;inner.point[2].q=wide.q;
    func_00282D30(&outer.point[3],&outer.point[2],-1.0f);
    func_00282D30(&inner.point[3],&inner.point[2],-1.0f);
    func_002830C0(&outer.point[2],&outer.point[2],frame);
    func_002830C0(&outer.point[3],&outer.point[3],frame);
    func_002830C0(&inner.point[2],&inner.point[2],frame);
    func_002830C0(&inner.point[3],&inner.point[3],frame);
    func_00280B90(&outer,0,0);func_00280B90(&inner,0,0);
}
