/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G64 -ffunction-sections -Wa,-G64 -frac2-qcopy -frac2-qcopy-barrier -g.
 * Reported final C / retail: 964 / 964 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: absent from catalogue (not a match).
 * Residual: 964-byte equal-size near miss, not a match. All four GP-relative corner vectors are declared as a full 64-byte object and use both G64 compiler and assembler limits. A full 64-byte transform and 144-byte draw packet are retained.
 * Reopening condition: A demonstrated branch/FP temporary and GS-state scheduling remedy.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G64 -ffunction-sections -Wa,-G64 -frac2-qcopy -frac2-qcopy-barrier -g.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 964-byte equal-size near miss, not a match. All four GP-relative corner vectors are
 * declared as a full 64-byte object and use both G64 compiler and assembler limits. A full
 * 64-byte transform and 144-byte draw packet are retained.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated branch/FP
 * temporary and GS-state scheduling remedy.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int u32;
typedef unsigned long long u64;
typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union {TI128 q;float v[4];} Vector;
typedef struct {Vector corners[4];u32 colors[4];Vector uv[2];u64 state[4];} SurfacePacket;
typedef struct {int reserved00;unsigned short age,reserved06;short active,reserved0A;} Ring;
extern Ring D_L00_0023D960[10];
extern Vector D_L00_001B8DC0,D_0018A0E0;
extern float D_L00_001B28AC[];
extern int D_L00_001AF8E0 __attribute__((sda));
extern int D_L00_001AF938 __attribute__((sda));
extern u32 D_L00_001AF93C __attribute__((sda));
extern Vector D_L00_001AF940[4] __attribute__((sda));
extern float D_L00_001AF980 __attribute__((sda)),D_L00_001AF984 __attribute__((sda));
extern float D_L00_001AF988 __attribute__((sda));
extern u32 D_L00_001AF98C __attribute__((sda)),D_L00_001AF990 __attribute__((sda));
extern float D_L00_001AF994 __attribute__((sda));
extern float func_00283CE0(int),func_002A78D8(float,float);
extern int func_00283CF0(float);
extern u64 func_0027C878(int);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern void func_00282F20(void *,void *,float),func_00282D30(void *,void *,float),func_00282DD8(void *,void *,void *);
extern void func_002830C0(void *,void *,void *),func_00280B90(void *,void *,int);
extern void func_L00_003B4560(unsigned char *,float),func_L00_003B5210(void);
void func_L00_003B4198(unsigned char *object)
{
    SurfacePacket packet;
    Vector transform[4],scaled;
    float life,t,low,high,size;
    u32 color;
    int i,j,alpha;
    short age;
    if(object[0x20]!=2) {
        age=*(short *)(*(char **)(object+0x68)+8);
        if(age>=D_L00_001AF8E0-30) {t=func_00283CE0(D_L00_001AF8E0-age);high=func_00283CE0(30);life=t/high;}
        else life=1.0f;
        packet.state[1]=func_0027C878(8);packet.state[2]=0xFF9000000260ULL;
        packet.state[3]=0x8000000048ULL;packet.state[0]=0;
        packet.uv[0].v[0]=0.0f;packet.uv[0].v[1]=0.0f;packet.uv[0].v[2]=0.0f;packet.uv[0].v[3]=1.0f;
        packet.uv[1].v[0]=1.0f;packet.uv[1].v[1]=0.0f;packet.uv[1].v[2]=1.0f;packet.uv[1].v[3]=1.0f;
        func_00282CF0(&transform[0],&D_L00_001B8DC0,object+0x10);
        func_00282F20(&transform[0],&transform[0],1.0f);
        transform[3].q=*(TI128 *)(object+0x10);
        func_00282D30(&transform[2],&D_0018A0E0,-1.0f);
        func_00282DD8(&transform[1],&transform[0],&transform[2]);
        func_00282F20(&transform[1],&transform[1],1.0f);
        func_00282DD8(&transform[2],&transform[1],&transform[0]);
        for(i=0;i<10;++i)if(D_L00_0023D960[i].active) {
            t=func_00283CE0(D_L00_0023D960[i].age)*D_L00_001B28AC[0];if(t>1.0f)t=1.0f;
            size=D_L00_001AF980+(D_L00_001AF984-D_L00_001AF980)*t;
            low=func_00283CE0(D_L00_001AF938);high=func_00283CE0(D_L00_001AF938);
            alpha=func_00283CF0(life*(low-high*t));
            color=(D_L00_001AF93C&0xFFFFFF)|((u32)alpha<<24);
            packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=color;
            for(j=0;j<4;++j) {
                func_00282D30(&scaled,&D_L00_001AF940[j],size);
                func_002830C0(&packet.corners[j],&scaled,transform);
            }
            func_00280B90(&packet,0,0);
        }
        packet.state[1]=func_0027C878(11);packet.state[3]=0x8000000044ULL;
        color=(D_L00_001AF990&0xFFFFFF)|D_L00_001AF98C;
        packet.colors[0]=packet.colors[1]=packet.colors[2]=packet.colors[3]=color;
        func_00282F20(&transform[3],&transform[0],D_L00_001AF994);
        func_00282CC0(&transform[3],&transform[3],object+0x10);
        size=D_L00_001AF988+func_002A78D8(0.0f,0.1f);
        for(j=0;j<4;++j) {
            func_00282D30(&scaled,&D_L00_001AF940[j],size);
            func_002830C0(&packet.corners[j],&scaled,transform);
        }
        func_00280B90(&packet,0,0);
        func_L00_003B4560(object,life);
    }
    func_L00_003B5210();
}
