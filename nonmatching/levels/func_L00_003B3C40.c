/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g.
 * Reported final C / retail: 560 / 568 bytes; size equality is not a match.
 * us: 0/27 placements; 560/568 bytes.
 * us2: 0/27 placements; 560/568 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 560 bytes versus 568. The truthful zero vector is reached through the qualified zero-ti-por profile; -g did not resolve the pre-DIV padding and remaining argument scheduling differences.
 * Reopening condition: A qualified division/interlock and call-expression source-shape remedy.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 560 bytes versus 568. The truthful zero vector is reached through the qualified zero-ti-por
 * profile; -g did not resolve the pre-DIV padding and remaining argument scheduling
 * differences.
 * Behavior and linked-image equality remain unverified. Reopen: A qualified
 * division/interlock and call-expression source-shape remedy.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
extern Vector D_L00_001B8DC0,D_L00_001A8F20;
extern float D_L00_001AF908 __attribute__((sda));
extern float D_L00_001AF8FC __attribute__((sda));
extern unsigned int D_L00_001AF900 __attribute__((sda));
extern int D_L00_001AF904 __attribute__((sda));
extern float D_L00_001AF90C __attribute__((sda));
extern unsigned int D_L00_001AF910 __attribute__((sda));
extern int D_L00_001AF914 __attribute__((sda));
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern float func_00283CE0(int),func_002A7940(void);
extern void func_002ACEC0(void *,void *,void *,float),func_00282F20(void *,void *,float);
extern int func_002A77E0(int);
extern unsigned char *func_002BDCE8(void *,int,void *,unsigned int,int,float,float,float,float);
void func_L00_003B3C40(unsigned char *object)
{
    Vector axis,direction,rotated,position,velocity;
    unsigned char *particle,*state;
    int spin,life;
    axis.q=0;axis.v[2]=D_L00_001AF908;
    func_00282CF0(&direction,&D_L00_001B8DC0,object+0x10);
    func_002ACEC0(&rotated,&axis,&direction,func_002A7940());
    func_00282CC0(&position,object+0x10,&rotated);
    spin=func_002A77E0(16);
    if(func_002A77E0(2))spin=-spin;
    life=D_L00_001AF904;
    func_00282F20(&velocity,&rotated,-(D_L00_001AF908/func_00283CE0(life)));
    particle=func_002BDCE8(&position,spin,&velocity,D_L00_001AF900,0,
        0.5f,1.0f,0.99f,D_L00_001AF8FC*210000.0f);
    if(particle) {
        state=particle+0x20;
        *(unsigned short *)(particle+0x0A)=life;
        *(int *)(state+4)=3;state[0x0A]=0x7F;state[0x0B]=particle[0x0A];
    }
    if(func_002A77E0(3)==0) {
        func_00282F20(&direction,&direction,-0.5f);
        func_00282CC0(&position,object+0x10,&direction);
        particle=func_002BDCE8(&position,spin,&D_L00_001A8F20,
            (D_L00_001AF910&0xFFFFFF)|((unsigned int)D_L00_001AF914<<24),0,
            0.1f,1.0f,0.8f,D_L00_001AF90C*210000.0f);
        if(particle) {
            state=particle+0x20;
            *(unsigned short *)(particle+0x0A)=60;
            particle[3]=0x44;*(int *)(state+4)=3;
            state[0x0A]=(unsigned char)D_L00_001AF914;state[0x0B]=particle[0x0A];
        }
    }
}
