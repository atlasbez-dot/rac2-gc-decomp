/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g.
 * Reported final C / retail: 416 / 416 bytes; size equality is not a match.
 * us: 0/27 placements.
 * us2: 0/27 placements.
 * pal: absent from catalogue (not a match).
 * Residual: Five source/profile trials; -g plus zero-ti-por reaches 416 bytes, but scheduling of the particle-call argument preparation differs at +0x104. The post-call subrecord view reproduces the retail stores.
 * Reopening condition: A demonstrated source-expression scheduling remedy for the real particle API; no prototype or output alteration.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-zero-ti-por -g.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * Five source/profile trials; -g plus zero-ti-por reaches 416 bytes, but scheduling of the
 * particle-call argument preparation differs at +0x104. The post-call subrecord view
 * reproduces the retail stores.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated source-
 * expression scheduling remedy for the real particle API; no prototype or output alteration.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
extern Vector D_L00_001B8DC0;
extern float D_L00_001AF908 __attribute__((sda));
extern int D_L00_001AF918 __attribute__((sda));
extern unsigned short D_L00_001AF91C __attribute__((sda));
extern float D_L00_001AF920 __attribute__((sda));
extern float D_L00_001AF924 __attribute__((sda));
extern unsigned int D_L00_001AF928 __attribute__((sda));
extern unsigned char D_L00_001AF92C __attribute__((sda));
extern float D_L00_001AF930 __attribute__((sda));
extern void func_00282CF0(void *,void *,void *);
extern float func_00283CE0(int);
extern void func_002ACEC0(void *,void *,void *,float);
extern void func_00282F20(void *,void *,float);
extern int func_002A77E0(int);
extern unsigned char *func_002BDCE8(void *,int,void *,unsigned int,int,float,float,float,float);
void func_L00_003B3E78(unsigned char *object)
{
    Vector axis, direction, rotated, velocity;
    float spacing;
    unsigned char *particle;
    int i, spin;
    axis.q=0;
    axis.v[2]=D_L00_001AF908;
    func_00282CF0(&direction,&D_L00_001B8DC0,object+0x10);
    spacing=6.2831855f/func_00283CE0(D_L00_001AF918);
    for(i=0;i<D_L00_001AF918;++i) {
        func_002ACEC0(&rotated,&axis,&direction,(float)i*spacing);
        func_00282F20(&velocity,&rotated,D_L00_001AF920*0.016666668f);
        spin=func_002A77E0(16);
        if(func_002A77E0(2)) spin=-spin;
        particle=func_002BDCE8(object+0x10,spin,&velocity,D_L00_001AF928,0,
            0.5f,1.0f,D_L00_001AF930,D_L00_001AF924*210000.0f);
        if(particle) {
            unsigned char *state=particle+0x20;
            *(unsigned short *)(particle+0x0A)=D_L00_001AF91C;
            *(int *)(state+4)=2;
            state[0x0A]=D_L00_001AF92C;
            state[0x0B]=particle[0x0A];
        }
    }
}
