/* Plain-C reconstruction, 23 October 2026. Profile: -O2 -G8
 * -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-barrier -g. USA, USA v2 and PAL: 0/2 placements,
 * 1176/1176 bytes; first real mismatch +0x118 (three packet-tag stores).
 * Nine bounded trials: TI members fix the quadword copies, separate stores
 * establish the retail colour order. Remaining differences are tag ordering,
 * the middle-packet pointer's allocation, and one load/address schedule swap.
 * A named middle pointer, texture temporary, -g, and zero placement did not
 * fix these; removing qcopy-barrier grows the body to 1184 bytes.
 * Reopen with a source-layout/alias-lifetime hypothesis. por plus sq is
 * compiler-reachable: the historical no-C screen below is superseded.
 */

/* Superseded historical screen, retained for provenance. */
/* MMI (SPECIAL2) instruction: no C spelling. 1176 bytes, level
   02_maktar_nebula. Retail at 0x00422720 carries the SPECIAL2 word
   0x700024A9 (+0x00F4) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

typedef unsigned char u8;
typedef unsigned long long u64;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct {
    Vector point[4];
    unsigned int color[4];
    float uv[8];
    u64 reserved, texture, setup, state;
} EffectPacket;
extern unsigned int ref_L02_00422720_0 __attribute__((sda));
extern unsigned int ref_L02_00422720_1 __attribute__((sda));
extern unsigned int ref_L02_00422720_2 __attribute__((sda));
extern Vector D_L02_001BA500;
extern u64 func_0027C878(int);
extern int func_001163B0(void);
extern float func_002A7878(float,float);
extern void func_L00_003DA2B0(void *);
extern void func_00282CF0(void *,void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282DD8(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_002830C0(void *,void *,void *);
extern void func_00280B90(void *,int,int);

/* Build the three textured strips around the effect's two endpoints. */
void func_L02_00422720(u8 *object)
{
    EffectPacket a,b,c;
    u64 texture;
    Vector frame[4];
    Vector small,wide,tall;
    u8 *effect=*(u8 **)(object+0x68);
    u64 setup=0xFF9000000260ULL;
    u64 state=0x8000000048ULL;
    a.texture=func_0027C878(16);
    a.setup=setup;
    a.reserved=0;
    a.state=0x8000000040ULL | ((u64)(func_001163B0()%2+1)<<2);
    a.color[1]=ref_L02_00422720_0; a.color[0]=ref_L02_00422720_0; a.color[3]=ref_L02_00422720_0; a.color[2]=ref_L02_00422720_0;
    b.texture=func_0027C878(16);
    b.setup=setup; b.state=state; b.reserved=0;
    b.color[1]=ref_L02_00422720_1; b.color[0]=ref_L02_00422720_1; b.color[3]=ref_L02_00422720_1; b.color[2]=ref_L02_00422720_1;
    texture=func_0027C878(16);
    c.setup=setup; c.texture=texture; c.state=state;
    c.color[1]=ref_L02_00422720_2; c.color[0]=ref_L02_00422720_2; c.color[3]=ref_L02_00422720_2; c.color[2]=ref_L02_00422720_2; c.reserved=0;
    small.q=0; wide.q=0; tall.q=0;
    small.f[3]=1.0f; wide.f[3]=1.0f; tall.f[3]=1.0f;
    tall.f[2]=func_002A7878(0.2f,0.25f);
    small.f[2]=func_002A7878(0.3f,0.4f);
    wide.f[2]=small.f[2]+small.f[2];
    tall.f[2]*=*(float *)(effect+0x60);
    wide.f[2]*=*(float *)(effect+0x60);
    small.f[2]*=*(float *)(effect+0x60);
    func_L00_003DA2B0(&a); func_L00_003DA2B0(&b); func_L00_003DA2B0(&c);
    a.uv[0]=0; a.uv[1]=0; a.uv[2]=0; a.uv[3]=1; a.uv[4]=1; a.uv[5]=0; a.uv[6]=1; a.uv[7]=1;
    b.uv[0]=0; b.uv[1]=0; b.uv[2]=0; b.uv[3]=1; b.uv[4]=1; b.uv[5]=0; b.uv[6]=1; b.uv[7]=1;
    c.uv[0]=0; c.uv[1]=0; c.uv[2]=0; c.uv[3]=1; c.uv[4]=1; c.uv[5]=0; c.uv[6]=1; c.uv[7]=1;
    func_00282CF0(&frame[0],effect+0x20,effect+0x10);
    func_00282F20(&frame[0],&frame[0],1.0f);
    func_00282CF0(&frame[1],&D_L02_001BA500,effect+0x10);
    func_00282DD8(&frame[2],&frame[1],&frame[0]);
    func_00282F20(&frame[2],&frame[2],1.0f);
    func_00282DD8(&frame[1],&frame[0],&frame[2]);
    frame[3].q=*(Quad *)(effect+0x10);
    a.point[0].q=small.q; b.point[0].q=wide.q; c.point[0].q=tall.q;
    func_00282D30(&a.point[1],&a.point[0],-1.0f);
    func_00282D30(&b.point[1],&b.point[0],-1.0f);
    func_00282D30(&c.point[1],&c.point[0],-1.0f);
    func_002830C0(&a.point[0],&a.point[0],frame);
    func_002830C0(&a.point[1],&a.point[1],frame);
    func_002830C0(&b.point[0],&b.point[0],frame);
    func_002830C0(&b.point[1],&b.point[1],frame);
    func_002830C0(&c.point[0],&c.point[0],frame);
    func_002830C0(&c.point[1],&c.point[1],frame);
    frame[3].q=*(Quad *)(effect+0x20);
    a.point[2].q=small.q; b.point[2].q=wide.q; c.point[2].q=tall.q;
    func_00282D30(&a.point[3],&a.point[2],-1.0f);
    func_00282D30(&b.point[3],&b.point[2],-1.0f);
    func_00282D30(&c.point[3],&c.point[2],-1.0f);
    func_002830C0(&a.point[2],&a.point[2],frame);
    func_002830C0(&a.point[3],&a.point[3],frame);
    func_002830C0(&b.point[2],&b.point[2],frame);
    func_002830C0(&b.point[3],&b.point[3],frame);
    func_002830C0(&c.point[2],&c.point[2],frame);
    func_002830C0(&c.point[3],&c.point[3],frame);
    func_00280B90(&a,0,0); func_00280B90(&b,0,0); func_00280B90(&c,0,0);
}
