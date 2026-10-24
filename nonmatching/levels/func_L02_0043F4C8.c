/* Plain-C reconstruction, 23 October 2026. Profile: -O2 -G8
 * -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * -frac2-zero-ti-barrier -g. USA and USA v2: 0/2 placements,
 * 1476/1484 bytes; canonical name absent from the PAL catalogue.
 * The single counter is D_L02_001AEC78 with SDA access. Retail uses an
 * absolute store in case 0 and SDA accesses elsewhere; this source keeps
 * one truthful datum and therefore does not reproduce that mixed sequence.
 * A rejected diagnostic used two external identities for the counter and
 * reached 1480 bytes; that is not an allowed active C representation.
 * Absolute upper-bound float reads require nosda; lower bounds use SDA.
 * Both por clears and all quadword copies compile. Four initial shape
 * trials left allocation/scheduling differences; the last three tied.
 * This fifth trial removes the fabricated identity and rechecks both USA
 * releases. Reopen on natural mixed-access generation and state-1 local
 * lifetimes or aggregate layout, rather than equivalent source spelling.
 */

/* Superseded historical screen, retained for provenance. */
/* MMI (SPECIAL2) instruction: no C spelling. 1484 bytes, level
   02_maktar_nebula. Retail at 0x0043F4C8 carries the SPECIAL2 words
   0x700014A9, 0x700014A9 (+0x0188, +0x03CC) - opcode 0x1C, which rabbitizer
   prints as `INVALID`; it is the MMI family (pcpyld and its relatives) the
   sixth wave recorded and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy. ASM_FUNC candidate, as for the rest of
   the family. */

typedef unsigned char u8;
typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern int D_L02_001AEC78 __attribute__((sda));
extern float ref_L02_0043F4C8_1 __attribute__((sda));
extern float ref_L02_0043F4C8_2 __attribute__((sda));
extern float D_L02_001B2A54 __attribute__((nosda));
extern float D_L02_001B2A5C __attribute__((nosda));
extern float ref_L02_0043F4C8_3 __attribute__((sda));
extern float ref_L02_0043F4C8_4 __attribute__((sda));
extern float ref_L02_0043F4C8_5 __attribute__((sda));
extern u8 D_00189E20[];
extern u8 D_L02_001A8F20[];
extern float func_002A7940(void);
extern float func_002A78D8(float,float);
extern int func_002A77E0(int);
extern void func_002A7470(void *,int,int,int);
extern void func_002A7750(void *,int,int);
extern float func_00283B98(float,float);
extern float func_00283198(float);
extern void func_002833F0(void *,void *);
extern void func_00282D30(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_L00_003206B8(void *,void *);
extern u8 *func_002A9640(void *,int,int);
extern int func_002A7820(int,int);
extern void func_00282F20(void *,void *,float);
extern void func_00282CF0(void *,void *,void *);
extern void func_00283698(void *,void *);
extern void func_002830C0(void *,void *,void *);
extern float func_00282C68(float,float,float);
extern int func_002761F8(void *,void *,int,int,int);
extern int func_002B3868(void *);
extern void func_002E5CF8(int,int,void *);
extern void func_L01_002E1680(void *,void *,int,int,int,float,float,float);
extern int func_00282978(void *);
extern void func_00282C88(void *);
extern void func_002ABBB8(void *,void *,void *,float,float,int,int,int,float,float,float,float,int,float,int,int,int,int,int);
extern void func_002B0A68(void *,int,void *,int,float,float,float,float);
extern void func_L00_00326110(void *,int,float);
extern void func_0029F338(void *);
extern void func_L02_0043FA98(void *);

/* Advance the hovering object's idle, launch and impact states. */
void func_L02_0043F4C8(u8 *object)
{
    Vector delta,angles;
    Vector matrix[3];
    Vector destination;
    u8 *effect=*(u8 **)(object+0x68);
    u8 *hit;
    u8 *position;
    int mode;
    switch(object[0x20]) {
    case 0:
        if(*(int *)(effect+0x40)) D_L02_001AEC78=D_L02_001AEC78-1;
        *(Quad *)effect=*(Quad *)(object+0x10);
        *(float *)(effect+0x10)=func_002A7940();
        *(float *)(effect+0x14)=func_002A7940();
        *(float *)(effect+0x18)=func_002A78D8(ref_L02_0043F4C8_1,D_L02_001B2A54)*0.00029088825f;
        *(float *)(effect+0x1C)=func_002A78D8(ref_L02_0043F4C8_2,D_L02_001B2A5C)*0.00029088825f;
        *(int *)(effect+0x40)=0;
        *(float *)(effect+0x4C)=0.104719773f;
        object[0x40]=func_002A77E0((*(u8 **)(*(u8 **)(object+0x24)+0x48))[0x10]);
        *(short *)(effect+0x48)=180;
        mode=func_002A77E0(2)+1;
        if(object[0x43]!=mode) func_002A7470(object,mode,0,5);
        func_002A7750(object,1,-1);
        break;
    case 1: {
        position=object+0x10;
        if(object[0x31]) {
            *(float *)(effect+0x10)=func_00283B98(*(float *)(effect+0x10),*(float *)(effect+0x18));
            *(float *)(effect+0x14)=func_00283B98(*(float *)(effect+0x14),*(float *)(effect+0x1C));
            *(float *)(object+0xF0)=ref_L02_0043F4C8_3*func_00283198(*(float *)(effect+0x10));
            *(float *)(object+0xF4)=ref_L02_0043F4C8_4*func_00283198(*(float *)(effect+0x14));
            angles.q=0;
            angles.f[0]=*(float *)(effect+0x10);
            angles.f[2]=*(float *)(effect+0x14);
            delta.q=angles.q;
            func_002833F0(matrix,&delta);
            func_00282D30(position,&matrix[1],ref_L02_0043F4C8_5);
            func_00282CC0(position,position,effect);
        }
        if(*(short *)(effect+0x3E)) {
            if(*(u8 **)(D_00189E20+0x33C)==object && *(int *)(D_00189E20+0x340)) *(short *)(effect+0x3E)=2;
            if(*(short *)(effect+0x3E)==2) {
                *(float *)(effect+8)-=0.06666667f;
                if(*(void **)(effect+0x50) && func_L00_003206B8(position,*(void **)(effect+0x50))) func_002A7750(object,3,-1);
            }
        }
        if(*(int *)(effect+0x40)) break;
        hit=func_002A9640(object,0x4210000,0);
        if(!hit) break;
        D_L02_001AEC78--;
        *(short *)(effect+0x4A)=func_002A7820(30,60);
        *(Quad *)(effect+0x20)=*(Quad *)(hit+0x10);
        func_00282F20(effect+0x20,effect+0x20,0.25f);
        func_00282CF0(&delta,hit,position);
        func_00283698(matrix,object+0xC0);
        func_002830C0(&delta,&delta,matrix);
        *(float *)(effect+0x30)=-(func_00282C68(delta.f[2],-1.0f,1.0f)*0.069813184f);
        *(float *)(effect+0x34)=func_00282C68(delta.f[1],-1.0f,1.0f)*0.052359886f;
        func_00282D30(&destination,effect+0x20,(float)*(short *)(effect+0x4A));
        func_00282CC0(&destination,position,&destination);
        if(func_002761F8(position,&destination,2,0,0)) *(short *)(effect+0x3C)=1;
        if(*(short *)(effect+0x3C)) func_002A7750(object,3,-1);
        else func_002A7750(object,2,-1);
        break;
    }
    case 2:
        if(func_002B3868(object)) func_002E5CF8(0,0,object);
        delta.q=0; angles.q=0;
        delta.f[2]=0.06666667f;
        angles.f[2]=-0.5f;
        func_00282CC0(&angles,&angles,object+0x10);
        if(!func_002A77E0(2)) func_L01_002E1680(&angles,&delta,1,0x40F0F0F0,1,0.006666667f,0.9f,1.04f);
        *(float *)(object+0xF4)=func_00283B98(*(float *)(object+0xF4),*(float *)(effect+0x30));
        *(float *)(object+0xF8)=func_00283B98(*(float *)(object+0xF8),*(float *)(effect+0x34));
        func_00282CC0(object+0x10,object+0x10,effect+0x20);
        if(func_00282978(effect+0x4A)) func_002A7750(object,3,-1);
        break;
    case 3:
        if(*(short *)(effect+0x3C)) func_00282C88(effect+0x20);
        func_002ABBB8(object,D_L02_001A8F20,object+0x10,0.0f,0.0f,10,5,15,0.0f,0.0f,9.0f,*(float *)(object+0x2C)*10.0f,-1,0.0f,0,0,-1,0,0x810001);
        func_002B0A68(object,0x3FFF,effect+0x20,255,3.0f,6.0f,3.0f,6.0f);
        func_L00_00326110(object,3,0.0f);
        func_002E5CF8(1,0,object);
        func_0029F338(object);
        return;
    }
    if(object[0x20]) func_L02_0043FA98(object);
}
