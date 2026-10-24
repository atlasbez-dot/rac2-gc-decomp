/* Plain-C reconstruction, 23 October 2026. Profile: -O2 -G8
 * -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-barrier -g. USA and USA v2: 0/7 placements,
 * 1296/1336 bytes; canonical name absent from the PAL catalogue.
 * Six bounded trials: a do/while with signed pointer comparison fixes the
 * initial loop shape. The vertex reset uses the current strip, but each
 * switch arm updates its independently named strip; using packet[i] there
 * compiles to 1356 bytes and hides that distinct alias structure. Separate
 * named-strip container and -g trials did not improve the match.
 * Reopen on inner-loop pointer induction and lifetimes (retail keeps several
 * independent strip/UV pointers and spills the vertex counter with sq).
 * The por zero and quadword operations all compile from ordinary C.
 */

/* Superseded historical screen, retained for provenance. */
/* MMI (SPECIAL2) instruction: no C spelling. 1336 bytes, level
   02_maktar_nebula. Retail at 0x00410F68 carries the SPECIAL2 word
   0x70001CA9 (+0x04CC) - opcode 0x1C, which rabbitizer prints as `INVALID`;
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
extern int ref_L02_00410F68_0 __attribute__((sda));
extern int ref_L02_00410F68_1 __attribute__((sda));
extern int ref_L02_00410F68_2 __attribute__((sda));
extern int ref_L02_00410F68_3 __attribute__((sda));
extern int ref_L02_00410F68_4 __attribute__((sda));
extern float ref_L02_00410F68_5 __attribute__((sda));
extern unsigned int ref_L02_00410F68_6[2] __attribute__((sda));
extern float ref_L02_00410F68_7[8] __attribute__((sda));
extern float ref_L02_00410F68_8 __attribute__((sda));
extern float ref_L02_00410F68_9 __attribute__((sda));
extern u8 D_00189E20[];
extern float D_L02_001B1A8C[];
extern void func_00283658(void *,void *);
extern u64 func_0027C878(int);
extern void func_00282CF0(void *,void *,void *);
extern void func_002AC9F8(void *,float);
extern unsigned int func_00283D38(unsigned int,unsigned int,float);
extern void func_00282C90(void *);
extern void func_002833F0(void *,void *);
extern void func_L01_002E1510(void *,int,void *,int,void *);

/* Assemble four animated strips in the object's coordinate frame. */
void func_L02_00410F68(u8 *object)
{
    EffectPacket packet[4];
    Vector frame[4];
    Vector rotation[3];
    Vector angle;
    u8 *effect=*(u8 **)(object+0x68);
    EffectPacket *p;
    u8 *resident;
    float alpha,spread,shrink,time;
    int i,j;
    func_00283658(frame,object+0xC0);
    frame[3].q=*(Quad *)(object+0x10);
    p=packet;
    do {
        p->texture=func_0027C878(ref_L02_00410F68_0);
        p->setup=0xFF9000000260ULL;
        p->reserved=0;
        p->state=(long long)ref_L02_00410F68_1 | ((long long)ref_L02_00410F68_2<<2) | ((long long)ref_L02_00410F68_3<<4) | ((long long)ref_L02_00410F68_4<<6) | 0x8000000000ULL;
        p++;
    } while ((int)p<(int)(packet+4));
    time=*(float *)(effect+0x34);
    alpha=(1.95f-time)*2.0f;
    if(alpha>1.0f) alpha=1.0f;
    else if(alpha<0.0f) alpha=0.0f;
    spread=0.1f;
    if(time<1.15f) {
        resident=D_00189E20+0x100;
        func_00282CF0(resident,object+0x10,resident-0x80);
        resident-=0x100;
        *(float *)(resident+0x108)=0;
        func_002AC9F8(resident+0x100,0.016666668f);
        time=*(float *)(effect+0x34);
        shrink=1.15f-time;
        if(shrink<0) shrink=0;
        spread=(0.2f-time)*5.0f;
        if(spread<0) spread=0;
        if(*(int *)(effect+0x38)<0) ref_L02_00410F68_5=spread;
        spread=shrink+0.1f;
        if(time<0.65f) {
            float scale=time*1.538461566f;
            *(short *)(resident+0x2500)=1;
            *(float *)(resident+0x2024)=scale;
            *(float *)(resident+0x2020)=scale;
            *(float *)(resident+0x2028)=2.0f-scale;
        } else *(short *)(resident+0x2500)=0;
    }
    for(i=0;i<4;i++) {
        j=0;
        do {
            unsigned int color;
            packet[i].uv[j*2]=ref_L02_00410F68_7[j*2];
            packet[i].uv[j*2+1]=D_L02_001B1A8C[j*2];
            color=ref_L02_00410F68_6[i!=0];
            packet[i].color[j]=color;
            packet[i].color[j]=func_00283D38(color&0xFFFFFF,color,alpha);
            func_00282C90(&packet[i].point[j]);
            time=*(float *)(effect+0x34);
            if(i!=0) time+=0.01f;
            packet[i].point[j].f[0]=time;
            if(j&1) {
                switch(i) {
                case 0: packet[0].point[j].f[2]+=ref_L02_00410F68_8+spread; break;
                case 1: packet[1].point[j].f[2]+=ref_L02_00410F68_8+ref_L02_00410F68_9; break;
                case 2: packet[2].point[j].f[2]+=(ref_L02_00410F68_8-spread*0.8f)+ref_L02_00410F68_9; break;
                case 3: packet[3].point[j].f[2]+=(ref_L02_00410F68_8+spread*0.8f)+ref_L02_00410F68_9; break;
                }
            } else {
                switch(i) {
                case 0: packet[0].point[j].f[2]+=ref_L02_00410F68_8-spread; break;
                case 1: packet[1].point[j].f[2]+=ref_L02_00410F68_8-ref_L02_00410F68_9; break;
                case 2: packet[2].point[j].f[2]+=(ref_L02_00410F68_8-spread*0.8f)-ref_L02_00410F68_9; break;
                case 3: packet[3].point[j].f[2]+=(ref_L02_00410F68_8+spread*0.8f)-ref_L02_00410F68_9; break;
                }
            }
            j++;
        } while (j<4);
    }
    angle.q=0; angle.f[2]=0.19634955f;
    func_002833F0(rotation,&angle);
    func_L01_002E1510(packet,4,rotation,32,frame);
}
