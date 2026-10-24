/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 644 / 636 bytes; size equality is not a match.
 * us: 0/27 placements; 644/636 bytes.
 * us2: 0/27 placements; 644/636 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 644 bytes versus 636 after two readable control/global-layout forms. All five selector FP arguments and the six observed queue-call GPR slots are preserved; AB1F0 is interpreted as a nullable 32-bit pointer word where retail dereferences it.
 * Reopening condition: A demonstrated branch/base-materialisation and argument-lifetime source-shape remedy.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 644 bytes versus 636 after two readable control/global-layout forms. All five selector FP
 * arguments and the six observed queue-call GPR slots are preserved; AB1F0 is interpreted as
 * a nullable 32-bit pointer word where retail dereferences it.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated branch/base-
 * materialisation and argument-lifetime source-shape remedy.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
typedef struct {
    unsigned char reserved0000[0x80]; Vector position;
    unsigned char reserved0090[0x774-0x90]; float pitch,yaw;
    unsigned char reserved077C[0x1500-0x77C]; int blocked;
    unsigned char reserved1504[0x2290-0x1504]; unsigned char *player;
    unsigned char reserved2294[0x24EC-0x2294]; short paused;
} PartialRoot;
extern PartialRoot D_00189E20;
extern int D_001A79F0[];
extern Vector D_L00_001B8DC0;
extern int func_00282978(void *),func_002AB1F0(unsigned char *);
extern void func_00282D30(void *,void *,float),func_00282CC0(void *,void *,void *);
extern void func_002AF000(float *,float,float,float);
extern unsigned char *func_L00_00324D18(void *,void *,int,float,float,float,float,float);
extern float func_00282E48(void *,void *),func_00282C48(float);
extern void func_00273318(void *,unsigned int,void *,int,int,int,float,float,float);
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define H(p,o) (*(short *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define P(p,o) (*(unsigned char **)((char *)(p)+(o)))
void func_L00_003B6158(unsigned char *object)
{
    Vector point,projection,facing;
    char *context=*(char **)(object+0x68);
    unsigned char *target,*descriptor;
    float aperture,distance;
    func_00282978(context+0x1E);
    if(object[0x20]==1) {
      if(D_00189E20.blocked) P(context,0x14)=0;
      else if(!D_00189E20.paused && !H(context,0x1E)) {
        func_00282D30(&projection,D_00189E20.player+0xE0,0.75f);
        func_00282CC0(&projection,&D_00189E20.position,&projection);
        func_002AF000(facing.v,1.0f,D_00189E20.yaw,D_00189E20.pitch);
        aperture=0.17453295f;
        target=P(context,0x14);
        if(D_001A79F0[0]==1 && target && (unsigned)(U(target,0xAA)-0xA8D)<2)
            aperture=0.30543268f;
        target=func_L00_00324D18(&projection,&facing,0,aperture,0.3490659f,30.0f,0.78539824f,0.6108653f);
        if(!target) {P(context,0x14)=0;H(context,0x1C)=4;}
        else if(target!=P(context,0x18)) H(context,0x1C)=4;
        else if(func_00282978(context+0x1C)) {P(context,0x14)=target;H(context,0x1E)=2;}
        P(context,0x18)=target;
      }
    } else if(D_00189E20.blocked) P(context,0x14)=0;
    target=P(context,0x14);
    if(target) {
        descriptor=(unsigned char *)func_002AB1F0(target);
        if(!descriptor) point.q=*(TI128 *)(P(context,0x14)+0x10);
        else {
            func_00282D30(&projection,P(context,0x14)+0xE0,F(descriptor,0x10));
            func_00282CC0(&point,P(context,0x14)+0x10,&projection);
        }
        distance=func_00282E48(&D_L00_001B8DC0,&point);
        aperture=func_00282C48(0.9f-distance*0.006666667f*0.65f);
        func_00273318(object,0xFF0FFF0F,&point,0x26,-1,4,aperture,0.0f,90.0f);
    }
}
