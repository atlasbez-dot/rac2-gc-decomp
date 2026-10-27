/* Bounded complete manual reconstruction, 2026-10-25; not linked or counted.
 * Profile: -O2 -G16 -Wa,-G16 -ffunction-sections.
 * 1028/1044 bytes; us: 0/27 placements; us2: 0/27 placements; pal: absent from catalogue.
 * Both player streams, complete vectors and the 64-byte inverse output remain. The inverse helper
 * reads three rows and writes four. The actual spawn-to-inherited copy uses qcopy. Current paired
 * reset code independently names input roots D_00138180 and D_00138500; separate measured prefixes
 * improve 1020 to 1028 bytes. The original third B7260 FP coefficient is preserved. Frame 0x120
 * agrees; input-base setup, loop register roles and source schedules differ. A per-actor field-
 * scope control regressed to 1004 bytes and is private.
 * Reopen with: Independent input-base/per-actor lifetime evidence beyond the measured two-root
 * form; preserve both actors, all physical input banks and the full inverse buffer.
 * Original drafts, useful variants and diagnostics remain private.
 * No linked-image equality or complete native behavior is established.
 */
#include "common.h"
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union {TI128 q;float v[4];} Vector;
typedef struct {unsigned char *actors[2];float steering[2];Vector positions[2],velocities[2];int timers[2],scores[2],phase;} PairContext;
/* Measured prefixes of the two input records; no complete record size is inferred. */
typedef struct {
    unsigned char reserved000[0x108]; float axis;
    unsigned char reserved10C[0x1A0-0x10C]; u32 held, pressed;
} InputPadPrefix;
/* Both input roots are independently named by the existing paired reset. */
extern InputPadPrefix D_00138180, D_00138500;
#define INPUT0 (&D_00138180)
#define INPUT1 (&D_00138500)
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
    float inverse[16] __attribute__((aligned(16)));
    Vector acceleration,inherited,spawn;
    PairContext *context=*(PairContext **)(object+0x68);
    unsigned char *actor;
    int i;
    axes[0]=-INPUT0->axis;
    if(INPUT0->held&0x8000)axes[0]=1.0f;else if(INPUT0->held&0x2000)axes[0]=-1.0f;
    axes[1]=-INPUT1->axis;
    if(INPUT1->held&0x8000)axes[1]=1.0f;else if(INPUT1->held&0x2000)axes[1]=-1.0f;
    held[0]=INPUT0->held;held[1]=INPUT1->held;
    pressed[0]=INPUT0->pressed;pressed[1]=INPUT1->pressed;
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
            qcopy(&inherited,&spawn);
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
