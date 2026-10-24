/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1020 / 1044 bytes; size equality is not a match.
 * us: 0/27 placements; 1020/1044 bytes.
 * us2: 0/27 placements; 1020/1044 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 1020 bytes versus 1044 after restoring the observed third FP argument to B7260 with root authorisation. That coefficient expression is the actual measured GP+A50 value scaled by the time unit, not a dummy input. Both-player state and full vector extents are retained.
 * Reopening condition: A demonstrated state/input layout, loop-register and source scheduling remedy after the qualified interface restoration.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G16 -ffunction-sections -Wa,-G16 -frac2-qcopy -frac2-qcopy-barrier.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 1020 bytes versus 1044 after restoring the observed third FP argument to B7260 with root
 * authorisation. That coefficient expression is the actual measured GP+A50 value scaled by
 * the time unit, not a dummy input. Both-player state and full vector extents are retained.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated state/input
 * layout, loop-register and source scheduling remedy after the qualified interface
 * restoration.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int u32;
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union {TI128 q;float v[4];} Vector;
typedef struct {unsigned char *actors[2];float steering[2];Vector positions[2],velocities[2];int timers[2],scores[2],phase;} PairContext;
typedef struct {
    unsigned char reserved000[0x108];float axis0;
    unsigned char reserved10C[0x1A0-0x10C];u32 held0,pressed0;
    unsigned char reserved1A8[0x488-0x1A8];float axis1;
    unsigned char reserved48C[0x520-0x48C];u32 held1,pressed1;
} PartialInput;
extern PartialInput D_00138180;
extern float D_L00_001B8FF0[12];
extern float D_L00_001AFAA8 __attribute__((sda)),D_L00_001AFAAC __attribute__((sda));
extern float D_L00_001AFAB0 __attribute__((sda)),D_L00_001AFAB4 __attribute__((sda)),D_L00_001AFAB8 __attribute__((sda));
extern Vector D_L00_001AFAC0 __attribute__((sda));
extern float D_L00_001AFA40 __attribute__((sda));
extern int D_L00_001AFA48 __attribute__((sda));
extern void func_00283698(void *,void *),func_00283098(void *,void *,void *),func_00282F20(void *,void *,float),func_00282CC0(void *,void *,void *);
extern float func_002AA2E8(float *,float,float),func_00283B98(float,float);
extern int func_00282948(void *);
extern void func_L00_003B74A8(unsigned char *,void *);
extern void *func_L00_003B7410(char *,void *,void *,void *);
extern void func_L00_003B7260(float,float,float,float *,float *),func_002AC9F8(float *,float);
void func_L00_003B6B70(unsigned char *object)
{
    float axes[2];u32 held[2],pressed[2];
    float inverse[16];
    Vector acceleration,inherited,spawn;
    PairContext *context=*(PairContext **)(object+0x68);
    unsigned char *actor;
    int i;
    axes[0]=-D_00138180.axis0;
    if(D_00138180.held0&0x8000)axes[0]=1.0f;else if(D_00138180.held0&0x2000)axes[0]=-1.0f;
    axes[1]=-D_00138180.axis1;
    if(D_00138180.held1&0x8000)axes[1]=1.0f;else if(D_00138180.held1&0x2000)axes[1]=-1.0f;
    held[0]=D_00138180.held0;held[1]=D_00138180.held1;
    pressed[0]=D_00138180.pressed0;pressed[1]=D_00138180.pressed1;
    func_00283698(inverse,D_L00_001B8FF0);
    for(i=0;i<2;++i) {
        actor=context->actors[i];
        if(*(unsigned short *)(actor+0x34)&1)continue;
        func_002AA2E8(&context->steering[i],D_L00_001AFAA8*axes[i]*0.00029088825f,D_L00_001AFAAC*0.0000048481375f);
        *(float *)(actor+0xF8)=func_00283B98(*(float *)(actor+0xF8),context->steering[i]);
        if(held[i]&0x40) {
            func_00283098(&acceleration,actor+0xC0,inverse);
            func_00282F20(&acceleration,&acceleration,D_L00_001AFAB0*0.00027777778f);
            acceleration.v[0]=0.0f;
            func_00282CC0(&context->velocities[i],&context->velocities[i],&acceleration);
            inherited.q=0;inherited.v[0]=-0.4f;
            func_00283098(&inherited,&inherited,actor+0xC0);
            func_00282CC0(&inherited,&inherited,actor+0x10);
            func_L00_003B74A8(actor,&inherited);
        }
        if(!context->phase && func_00282948(&context->timers[i]) && (pressed[i]&0xA0)) {
            spawn.q=0;spawn.v[1]=context->velocities[i].v[1];spawn.v[2]=context->velocities[i].v[2];
            inherited.q=spawn.q;
            func_00283098(&spawn,&D_L00_001AFAC0,actor+0xC0);
            func_00282CC0(&spawn,&spawn,actor+0x10);
            func_00282F20(&acceleration,actor+0xC0,D_L00_001AFAB8*0.016666668f);
            func_00283098(&inherited,&inherited,D_L00_001B8FF0);
            func_00282CC0(&acceleration,&acceleration,&inherited);
            func_L00_003B7410((char *)actor,&spawn,&acceleration,(void *)i);
            context->timers[i]=D_L00_001AFA48;
        }
        func_L00_003B7260(context->positions[i].v[1],context->positions[i].v[2],D_L00_001AFA40*0.00027777778f,&context->velocities[i].v[1],&context->velocities[i].v[2]);
        func_002AC9F8(context->velocities[i].v,D_L00_001AFAB4*0.016666668f);
        func_00282CC0(&context->positions[i],&context->positions[i],&context->velocities[i]);
    }
}
