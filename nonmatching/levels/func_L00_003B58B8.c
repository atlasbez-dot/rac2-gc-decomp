/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 824 / 828 bytes; size equality is not a match.
 * us: 0/27 placements; 824/828 bytes.
 * us2: 0/27 placements; 824/828 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 824 bytes versus 828 after two typed-layout forms. Both camera rotations use full 48-byte matrices, copied pose fields use full vectors, and all owner/callback inputs are preserved.
 * Reopening condition: A demonstrated temporary/register scheduling remedy; no fabricated padding or narrower matrix.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 824 bytes versus 828 after two typed-layout forms. Both camera rotations use full 48-byte
 * matrices, copied pose fields use full vectors, and all owner/callback inputs are preserved.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated
 * temporary/register scheduling remedy; no fabricated padding or narrower matrix.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
typedef struct {Vector position,angles;} PartialCameraPose;
extern PartialCameraPose D_L00_001B8DC0;
typedef struct {unsigned char reserved[0x1A0];unsigned int held,pressed;} PartialInput;
extern PartialInput D_00138180;
typedef struct {unsigned char reserved[0x1FB0];float pitch,yaw;unsigned char middle[0x24B8-0x1FB8];float delta;} PartialRoot;
extern PartialRoot D_00189E20;
extern int D_L00_001B1BE8,D_L00_001A8FF0;
extern Vector D_L00_001B1B10;
extern float D_L00_001AFA30 __attribute__((sda));
extern void func_002A7750(unsigned char *,unsigned char,int),func_003355A8(int);
extern void func_L00_002C42E0(int,int),func_L00_002F46C8(void),func_002B0CE0(int,int,int);
extern void func_002833F0(float *,float *),func_00282F20(void *,void *,float),func_00282CC0(void *,void *,void *);
extern float func_002AA2E8(float *,float,float),func_00282E48(void *,void *),func_00282DB0(void *,void *),func_00282C48(float),func_00283248(float,float);
extern void func_002AFFD8(void *,void *,int),func_00282DD8(void *,void *,void *),func_002ACE78(void *,void *,float);
extern void func_00283958(void *,void *),func_00283738(void *,void *,void *);
extern void func_00335370(void *),func_002AB6D8(float *,float *),func_003353C8(void *);
#define F(p,o) (*(float *)((char *)(p)+(o)))
void func_L00_003B58B8(unsigned char *object)
{
    Vector position,angles;
    float matrix[12];
    Vector movement,turn,cross,forward;
    float rotation[12];
    float *state=*(float **)(object+0x68);
    float step,pitch,distance,projection;
    switch(object[0x20]) {
    case 0:
        func_002A7750(object,1,-1);
        break;
    case 1:
        break;
    case 2:
        if(D_00138180.pressed&0x200) {func_003355A8(0);func_L00_002C42E0(0,1);func_002A7750(object,1,-1);}
        func_L00_002F46C8();
        object[0x31]=0;*(unsigned short *)(object+0x34)|=1;
        D_L00_001B1BE8=1;
        func_002B0CE0(6,0,1);
        position.q=D_L00_001B8DC0.position.q;
        angles.q=D_L00_001B8DC0.angles.q;
        func_002833F0(matrix,angles.v);
        if(D_00138180.held&0x10)func_002AA2E8(state,-0.6666667f,0.0019444445f);
        else if(D_00138180.held&0x40)func_002AA2E8(state,0.6666667f,0.0019444445f);
        func_00282F20(&movement,matrix,state[0]);
        func_00282CC0(&position,&position,&movement);
        step=D_L00_001AFA30*0.0000048481375f;
        if(D_00189E20.delta>0.1f)step*=D_00189E20.delta;
        func_002AA2E8(state+1,-D_00189E20.pitch*0.052359886f,step);
        func_002AA2E8(state+2,-D_00189E20.yaw*0.052359886f,step);
        func_002AFFD8(&position,&forward,1);
        func_00282DD8(&cross,matrix,&forward);
        pitch=state[2];
        if(D_L00_001A8FF0) {
            distance=func_00282E48(&position,&D_L00_001B1B10);
            projection=func_00282C48(func_00282DB0(&forward,&movement));
            pitch=state[2]+func_00283248(distance,state[0]-projection);
        }
        func_002ACE78(&turn,&forward,state[1]*0.5f);
        func_002ACE78(&cross,&cross,pitch*0.5f);
        func_00283958(&turn,rotation);
        func_00283738(matrix,rotation,matrix);
        func_00283958(&cross,rotation);
        func_00283738(matrix,rotation,matrix);
        func_00335370(&position);
        func_002AB6D8(matrix,angles.v);
        func_003353C8(&angles);
        break;
    }
}
