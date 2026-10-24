/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 768 / 792 bytes; size equality is not a match.
 * us: 0/27 placements; 768/792 bytes.
 * us2: 0/27 placements; 768/792 bytes.
 * pal: 0/27 placements; 768/792 bytes.
 * Residual: 768 bytes versus 792. Four complete five-vector trails use signed halfword timers and full 16-byte point records. R5900 mult/madd are ordinary indexed pointer arithmetic, not an incoming HI dependency.
 * Reopening condition: A demonstrated loop-register/address materialisation source-shape remedy.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1, pal: 0/27 exit 1.
 * 768 bytes versus 792. Four complete five-vector trails use signed halfword timers and full
 * 16-byte point records. R5900 mult/madd are ordinary indexed pointer arithmetic, not an
 * incoming HI dependency.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated loop-
 * register/address materialisation source-shape remedy.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union { TI128 q; float v[4]; } Vector;
extern short D_L00_001B28B0[4];
extern unsigned short D_L00_001B28B8[4];
extern Vector D_L00_0023D9E0[4][5],D_L00_001B8DC0;
extern float D_L00_001AFA14 __attribute__((sda));
extern void func_002A7988(int,float,float);
extern void func_00282CF0(void *,void *,void *),func_00282CC0(void *,void *,void *);
extern float func_002A7878(float,float),func_002A78D8(float,float);
extern void func_002ACEC0(void *,void *,void *,float);
void func_L00_003B4EF8(unsigned char *object)
{
    Vector position,direction,axis,displacements[4];
    int i,j;
    float sign,angle;
    position.q=*(TI128 *)(object+0x10);
    for(i=0;i<4;++i) {
        if(!D_L00_001B28B0[i])continue;
        --D_L00_001B28B0[i];
        if(D_L00_001B28B0[i]<0)D_L00_001B28B0[i]=0;
        if(!D_L00_001B28B0[i]) {
            D_L00_001B28B0[i]=4;D_L00_001B28B8[i]=64;
            func_002A7988((int)&direction,D_L00_001AFA14,D_L00_001AFA14);
            D_L00_0023D9E0[i][0].q=position.q;
            sign=1.0f;
            for(j=0;j<4;++j) {
                func_00282CF0(&axis,&D_L00_0023D9E0[i][j],&D_L00_001B8DC0);
                angle=func_002A7878(0.17453295f,0.78539824f)*sign;
                sign=-sign;
                func_002ACEC0(&direction,&direction,&axis,angle);
                func_00282CC0(&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j],&direction);
            }
        } else {
            for(j=0;j<4;++j) {
                func_00282CF0(&displacements[j],&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j]);
                displacements[j].v[0]+=func_002A78D8(0.0f,0.1f);
                displacements[j].v[1]+=func_002A78D8(0.0f,0.1f);
                displacements[j].v[2]+=func_002A78D8(0.0f,0.1f);
            }
            D_L00_0023D9E0[i][0].q=position.q;
            for(j=0;j<4;++j)func_00282CC0(&D_L00_0023D9E0[i][j+1],&D_L00_0023D9E0[i][j],&displacements[j]);
            if(D_L00_001B28B0[i]<1)D_L00_001B28B8[i]=0;
            else D_L00_001B28B8[i]=32;
        }
    }
}
