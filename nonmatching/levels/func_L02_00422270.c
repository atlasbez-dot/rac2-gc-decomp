/* Readable C reconstruction, 23 October 2026. Profile: -O2 -G8 -ffunction-sections -frac2-zero-
 * ti-barrier.
 * us: 572/600 bytes, 0/2 carrying placements.
 * us2: 572/600 bytes, 0/2 carrying placements.
 * pal: canonical name absent.
 * One complete C reconstruction. Both indexed colour windows and fixed colour bytes use one
 * canonical incomplete array; no duplicate identities describe the mixed accesses. Constant
 * scale/predicate folding, palette address forms and the 0x80 rather than 0x90 frame remain.
 * Reopen with qualified original type/control-flow evidence.
 * The historical screening below predates this C and is superseded; por/quadword instructions
 * alone are not evidence of handwritten assembly. No linked qualification was run.
 */

/* Superseded historical screen, retained for provenance. */
/* MMI (SPECIAL2) instruction: no C spelling. 600 bytes, level
   02_maktar_nebula. Retail at 0x00422270 carries the SPECIAL2 word
   0x700014A9 (+0x0010) - opcode 0x1C, which rabbitizer prints as `INVALID`;
   it is the MMI family (pcpyld and its relatives) the sixth wave recorded
   and that no C spelling reaches. This cc1 emits `lq`/`sq` for a `mode(TI)`
   local and `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the
   packed copy. ASM_FUNC candidate, as for the rest of the family. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern float func_002A7878(float,float);
extern int func_002A77E0(int);
extern int func_002A7820(int,int);
extern u8 *func_002BBCB0(void *,void *,u32,u32,int,int,int,int,float,float);
extern u8 *func_00308408(void *,void *,void *,int,int,int,int,int,float);
/* The two indexed colour windows and fixed colours share this observed storage. */
extern u32 D_L02_001B1FE8[] __attribute__((sda));

/* Emit the capture burst and its three coloured flash objects. */
void func_L02_00422270(u8 *owner, void *position)
{
    Vector velocity;
    int left=5;
    float scale=1.0f;
    velocity.q=0;
    velocity.f[2]=0.13333334f;
    do {
        float size=400000.0f*scale;
        float rate=func_002A7878(8.0f,10.0f)*0.016666668f;
        int index=func_002A77E0(6);
        u32 first=D_L02_001B1FE8[index+4];
        u32 second=D_L02_001B1FE8[index];
        int begin=func_002A7820(15,20);
        int end=func_002A7820(30,45);
        u8 *particle=func_002BBCB0(position,&velocity,second,first,begin,end,0,0,size,rate*scale);
        if(particle) particle[3]=0x44;
    } while (--left>=0);
    {
        u8 *color=(u8 *)(D_L02_001B1FE8+8);
        func_00308408(owner,position,&velocity,16,color[0],color[1],color[2],color[3],4.0f);
        color=(u8 *)(D_L02_001B1FE8+10);
        func_00308408(owner,position,&velocity,22,color[0],color[1],color[2],color[3],4.0f);
        color=(u8 *)(D_L02_001B1FE8+12);
        func_00308408(owner,position,&velocity,30,color[0],color[1],color[2],color[3],4.0f);
    }
    if(owner) {
        float radius=2.0f;
        if(radius>0.0f) func_00308408(owner,position,&velocity,27,80,50,50,20,radius);
    }
}
