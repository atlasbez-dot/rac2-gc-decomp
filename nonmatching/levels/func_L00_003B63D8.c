/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1104 / 1152 bytes; size equality is not a match.
 * us: 0/27 placements; 1104/1152 bytes.
 * us2: 0/27 placements; 1104/1152 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 1104 bytes versus 1152. Complete controller and fragment states retain all callbacks, all three particle calls, the observed B7260 third FP argument and the observed ignored B75C8 object argument. Both API restorations were separately qualified; no new helper credit is claimed.
 * Reopening condition: A demonstrated state-branch/data-layout source-shape remedy with the qualified real interfaces.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Complete unmatched manual reconstruction, 2026-10-23.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final checks: us: 0/27 exit 1, us2: 0/27 exit 1.
 * No canonical catalogue entry: pal; absence is not a match.
 * 1104 bytes versus 1152. Complete controller and fragment states retain all callbacks, all
 * three particle calls, the observed B7260 third FP argument and the observed ignored B75C8
 * object argument. Both API restorations were separately qualified; no new helper credit is
 * claimed.
 * Behavior and linked-image equality remain unverified. Reopen: A demonstrated state-
 * branch/data-layout source-shape remedy with the qualified real interfaces.
 * The following historical screening comment is superseded by this manual attempt. In
 * particular, por/mult/madd alone are not evidence of handwritten assembly. No ASM_FUNC
 * classification or C credit is claimed.
 */

/* Historical screen/map retained privately. The current manual reconstruction and measured residual above supersede that screen; its extracted instruction, opcode and address lists establish neither matching nor handwritten-assembly status. */

typedef unsigned int TI128 __attribute__((mode(TI)));
typedef union {TI128 q;float v[4];} Vector;
typedef struct NODE NODE;
typedef void (*DrawCallback_r002E6CF0)(void *);
extern unsigned int D_00138324[];
extern int D_L00_001A8F00 __attribute__((sda));
extern int D_L00_001B1BE8;
extern float D_L00_001B18E0;
extern float D_L00_001B8FF0[12];
extern Vector D_L00_001B8DC0;
extern float D_L00_001AFA44 __attribute__((sda));
extern int D_L00_001AFA4C __attribute__((sda));
extern void func_002A7750(unsigned char *,unsigned char,int),func_0029F338(void *);
extern int func_002B49E0(int,int,int,int,unsigned char *),func_002B4B70(int,int);
extern int func_L00_003B6858(void *);
extern void func_L00_003B69D8(void *),func_L00_003B75C8(void *),func_L00_003B72B0(void *),func_L00_003B77A8(void *);
extern void func_L00_003B7908(void *),func_L00_002E6CF0(DrawCallback_r002E6CF0,void *),func_L00_003B6A90(NODE *);
extern float func_002AA2E8(float *,float,float);
extern void func_002833F0(float *,float *),func_00283698(void *,void *),func_00282CF0(void *,void *,void *),func_00283098(void *,void *,void *);
extern void func_L00_003B7190(float *,float *),func_L00_003B7260(float,float,float,float *,float *),func_00282CC0(void *,void *,void *),func_00282F20(void *,void *,float);
extern void func_L00_003B74A8(unsigned char *,void *);
extern int func_002A8C28(void *,float,float *,int,float,float,int,int,int);
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
void func_L00_003B63D8(unsigned char *object)
{
    Vector point;
    float inverse[16];
    Vector velocity,spawn,offset;
    char *context=*(char **)(object+0x68);
    unsigned short age;
    int mode,old_age;
    if(object[0x20]==1) {
        D_L00_001B1BE8=1;
        func_L00_003B69D8(object);
        func_L00_003B75C8(object);
        func_L00_003B72B0(object);
        func_L00_003B77A8(object);
        func_L00_002E6CF0(func_L00_003B7908,object);
        if(!I(context,0x60) || I(context,0x64)++<91) {
            func_002AA2E8(&D_L00_001B18E0,0.0f,0.06666667f);
            mode=D_L00_001A8F00;
        } else {
            func_002AA2E8(&D_L00_001B18E0,1.0f,0.06666667f);
            mode=D_L00_001A8F00;
            if(D_L00_001B18E0>=1.0f) {
                func_L00_003B6A90((NODE *)object);
                func_L00_003B6858(object);
                I(context,0x60)=0;I(context,0x64)=0;
                mode=D_L00_001A8F00;
            }
        }
        if(mode==7) {
            if(!(D_00138324[0]&0x10))return;
            func_002B4B70(1,0);return;
        }
        func_L00_003B6A90((NODE *)object);
    } else if(object[0x20]<2) {
        if(object[0x20]!=0)return;
        if(!D_L00_001A8F00) {func_002B49E0(7,1,(int)object,2,0);return;}
        if(D_L00_001A8F00==7 && func_L00_003B6858(object)) {
            point.q=0;point.v[1]=1.5707964f;
            func_002833F0(D_L00_001B8FF0,point.v);
            func_002A7750(object,1,-1);return;
        }
        age=U(object,0x96);U(object,0x96)=age+1;if(age<6)return;
    } else {
        if(object[0x20]!=2)return;
        func_00283698(inverse,D_L00_001B8FF0);
        func_00282CF0(&point,object+0x10,&D_L00_001B8DC0);
        func_00283098(&point,&point,inverse);
        func_00283098(&velocity,context,inverse);
        func_L00_003B7190(point.v+1,point.v+2);
        func_L00_003B7260(point.v[1],point.v[2],D_L00_001AFA44*0.00027777778f,velocity.v+1,velocity.v+2);
        velocity.v[0]=0.0f;
        func_00282CC0(&point,&point,&velocity);
        func_00283098(object+0x10,&point,D_L00_001B8FF0);
        func_00282CC0(object+0x10,object+0x10,&D_L00_001B8DC0);
        func_00283098(context,&velocity,D_L00_001B8FF0);
        if(point.v[1]*point.v[1]+point.v[2]*point.v[2]>=0.09f) {
            func_L00_003B74A8(object,object+0x10);
            func_00282F20(&offset,D_L00_001B8FF0,-0.1f);
            func_00282CC0(&spawn,object+0x10,&offset);
            func_002A8C28(*(void **)(object+0xB8),0.1f,spawn.v,0x10000,1.0f,1.0f,0,1,0);
            func_00282CF0(&spawn,object+0x10,&offset);
            func_002A8C28(*(void **)(object+0xB8),0.1f,spawn.v,0x10000,1.0f,1.0f,0,1,0);
            func_00282CF0(&spawn,object+0x10,&offset);
            func_002A8C28(*(void **)(object+0xB8),0.1f,spawn.v,0x10000,1.0f,1.0f,0,1,0);
            if(D_L00_001A8F00==7) {age=U(object,0x96);U(object,0x96)=age+1;if((int)age<=D_L00_001AFA4C)return;}
        }
    }
    func_0029F338(object);
}
