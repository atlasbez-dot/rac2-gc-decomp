/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -g.
 * Reported final C / retail: 3188 / 3328 bytes; size equality is not a match.
 * us: 0/1 placements; 3188/3328 bytes.
 * us2: 0/1 placements; 3188/3328 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: 140 bytes short; frame 0x170 is correct, but field allocation, branches and state dispatch differ.
 * Reopening condition: Evidence for original local lifetimes and state-dispatch shape.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction of the Maktar turret update.
 * Retail US/US2: 3328 bytes; final trial: 3188 bytes, 0/1 each, exit 1.
 * PAL does not carry this canonical function in its catalogue.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 *          -frac2-zero-ti-por -g.
 * Three bounded trials: 3200, 3180 and 3188 bytes. Frame 0x170 is correct.
 * Remaining differences include field/register allocation, branches and the
 * final state dispatch. Reopen with a concrete original local/control-flow
 * hypothesis rather than another equivalent clamp or colour-branch spelling.
 * The 32-byte joint union represents two observed quads; vectors are 16 bytes
 * and matrices 64 bytes. The colour wrapper forwards two colours and f12 to
 * func_00283D38 and returns the packed colour in v0.
 */
typedef int Quadword __attribute__((mode(TI)));
typedef union {
    struct { float origin[4]; float difference[4]; } aim;
    struct { float angles[4]; float original[4]; } rotation;
} JointScratch;
extern unsigned char *D_L02_001B359C __attribute__((sda));
extern int D_L02_001B30C8 __attribute__((sda));
extern float D_L02_001A8F20[4] __attribute__((sda));
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern void func_0029FC20(char *, int, char *);
extern void func_002A05A8(char *);
extern void func_002A0F48(char *);
extern void func_002A10E8(char *);
extern unsigned int func_L00_0031C998(unsigned int, unsigned int, float);
extern float func_00283198(float);
extern float func_002AAA00(float *, float *, int, float, float, float, float);
extern void func_002833F0(void *, void *);
extern void func_002AB6D8(float *, float *);
extern void func_0029FCC0(char *, int, char *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00283BE0(float, float);
extern float func_00283C28(float);
extern void func_002A91F0(void *, float *);
extern float func_L02_00321C30(void *, void *, float);
extern int func_00282978(short *);
extern void func_002A7470(char *, int, int, int);
extern int func_00283CF0(float);
extern float func_0029F530(char *);
extern void func_00282F20(void *, void *, float);
extern unsigned char *func_L02_004216F0(unsigned char *, int, unsigned char *, float);

#define PROXY (D_L02_001B359C + (*(int *)(*(char **)(self+0x68)+0x244) << 8))

/* Update the attached turret's colour, aim joints and muzzle emissions. */
void func_L02_003D9E68(char *self)
{
    float target[4];
    float ownerMatrix[16];
    JointScratch work;
    float angles[4];
    float orientation[4];
    float firstMuzzle[16];
    float secondMuzzle[16];
    char *state = *(char **)(self+0x68);
    char *object;
    float distance, yaw, difference, fraction, limit, phase;
    unsigned int colour;
    int mode;

    *(Quadword *)target=0;
    object=*(char **)(state+0x240);
    if (object) *(Quadword *)target=*(Quadword *)(object+0x10);
    distance=func_00282E80(self+0x10,target);
    yaw=func_00283248(target[0]-*(float *)(self+0x10),target[1]-*(float *)(self+0x14));
    difference=func_00283C80(*(float *)(PROXY+0xF8),yaw);
    func_0029FC20(self,0,(char *)ownerMatrix);
    object=(char *)PROXY;
    *(Quadword *)(object+0x10)=*(Quadword *)(ownerMatrix+12);
    func_002A05A8(object);
    func_002A0F48((char *)PROXY);
    func_002A10E8((char *)PROXY);
    if ((*(unsigned int *)(state+0x250)&0xFFFFFF)!=(*(unsigned int *)(state+0x258)&0xFFFFFF)) {
        *(unsigned int *)(state+0x250)=func_L00_0031C998(*(unsigned int *)(state+0x254),
                *(unsigned int *)(state+0x258),*(float *)(state+0x25C));
        *(float *)(state+0x25C)+=0.1f;
        if (*(float *)(state+0x25C)>1.0f) *(float *)(state+0x25C)=1.0f;
    } else {
        *(unsigned int *)(state+0x254)=*(unsigned int *)(state+0x258);
        *(int *)(state+0x25C)=0;
    }
    phase=func_00283198((float)(D_L02_001B30C8%120)*0.052359883f-3.1415927f);
    colour=(*(unsigned int *)(state+0x250)&0xFFFFFF)
            | ((int)(phase*phase*(float)*(unsigned char *)(state+0x25B)) << 24);
    *(unsigned int *)(state+0x250)=colour;
    *(unsigned int *)(PROXY+0x78)=colour;
    mode=*(unsigned char *)(self+0x20);
    if ((unsigned)(mode-9)>=3 && mode!=7) {
        fraction=*(float *)(state+0x20)/(float)*(short *)(state+0x24);
        limit=(fraction*-330.0f+360.0f)*0.0000048481375f;
        func_002AAA00((float *)(state+0x248),(float *)(state+0x24C),0,
                yaw,limit,limit,(fraction*-225.0f+240.0f)*0.00029088825f);
        *(Quadword *)work.rotation.original=0;
        work.rotation.original[2]=*(float *)(state+0x248);
        *(Quadword *)work.rotation.angles=*(Quadword *)work.rotation.original;
        func_002833F0(PROXY+0xC0,&work);
        object=(char *)PROXY;
        func_002AB6D8((float *)(object+0xC0),(float *)(object+0xF0));
    }
    mode=*(unsigned char *)(self+0x20);
    if (mode==5 || (mode==6 && *(float *)(state+0x20)<(float)*(short *)(state+0x24)*0.2f)) {
        func_0029FCC0((char *)PROXY,2,(char *)work.aim.origin);
        func_00282CF0(work.aim.difference,*(char **)(state+0x240)+0x10,work.aim.origin);
        limit=func_00282E80(*(char **)(state+0x240)+0x10,work.aim.origin);
        *(Quadword *)angles=0;
        angles[1]=func_00283248(work.aim.difference[2],limit)-1.5707964f;
        if (angles[1]>1.5707965f) angles[1]=1.5707965f;
        else if (angles[1]<-1.5707965f) angles[1]=-1.5707965f;
        if (difference<0.17453295f) {
            angles[2]=func_00283248(work.aim.difference[0],work.aim.difference[1]);
            angles[2]=func_00283BE0(angles[2],*(float *)(PROXY+0xF8));
            angles[2]=func_00283C28(angles[2]);
        }
        if (angles[2]<=0.9599312f) {
            if (angles[2]<-0.13962635f) angles[2]=-0.13962635f;
        } else angles[2]=0.9599312f;
        func_002A91F0(orientation,angles);
        func_L02_00321C30(state+0x180,orientation,0.01f);
        func_0029FCC0((char *)PROXY,3,(char *)work.aim.origin);
        func_00282CF0(work.aim.difference,*(char **)(state+0x240)+0x10,work.aim.origin);
        limit=func_00282E80(*(char **)(state+0x240)+0x10,work.aim.origin);
        angles[1]=func_00283248(work.aim.difference[2],limit)-1.5707964f;
        if (angles[1]>1.5707965f) angles[1]=1.5707965f;
        else if (angles[1]<-1.5707965f) angles[1]=-1.5707965f;
        if (difference<0.17453295f) {
            angles[2]=func_00283248(work.aim.difference[0],work.aim.difference[1]);
            angles[2]=func_00283BE0(angles[2],*(float *)(PROXY+0xF8));
            angles[2]=func_00283C28(angles[2]);
        }
        if (angles[2]<=0.13962635f) {
            if (angles[2]<-0.9599312f) angles[2]=-0.9599312f;
        } else angles[2]=0.13962635f;
        func_002A91F0(orientation,angles);
        func_L02_00321C30(state+0x1C0,orientation,0.01f);
        if (func_00282978((short *)(state+0x286)) && distance<45.0f
                && distance>0.0f && difference<3.141593f) {
            object=(char *)PROXY;
            if (object[0x43]!=5) func_002A7470(object,5,0,3);
            PROXY[0xBC]=0;
            if (self[0x20]==5)
                *(short *)(state+0x286)=func_00283CF0((*(float *)(state+0x20)/(float)*(short *)(state+0x24))*40.0f+20.0f);
            else *(short *)(state+0x286)=60;
        }
    } else {
        func_L02_00321C30(state+0x180,D_L02_001A8F20,0.01f);
        func_L02_00321C30(state+0x1C0,D_L02_001A8F20,0.01f);
    }
    switch (PROXY[0x42]) {
    case 0:
        *(unsigned int *)(state+0x258)=0x40FF00EA;
        if (self[0x20]!=5 || distance<=45.0f || distance>=0.0f || difference<=3.141593f) return;
        object=(char *)PROXY;
        if (object[0x43]!=1) func_002A7470(object,1,0,10);
        return;
    case 1: case 2: case 3: case 4:
        if (distance>=45.0f || distance<=0.0f || difference>=3.141593f) return;
        object=(char *)PROXY;
        if (object[0x43]) func_002A7470(object,0,0,10);
        return;
    case 5:
        *(unsigned int *)(state+0x258)=0x80FF00EA;
        phase=func_0029F530((char *)PROXY);
        object=(char *)PROXY;
        if (!object[0xBC] && phase>3.0f && phase<6.0f) {
            func_0029FCC0(object,0,(char *)work.aim.origin);
            func_0029FC20((char *)PROXY,0,(char *)firstMuzzle);
            func_00282CF0(angles,*(char **)(state+0x240)+0x10,work.aim.origin);
            func_00282F20(angles,angles,1.0f);
            firstMuzzle[2]=angles[2];
            func_00282F20(firstMuzzle,firstMuzzle,1.0f);
            func_L02_004216F0((unsigned char *)work.aim.origin,(int)self,(unsigned char *)firstMuzzle,
                    (float)*(unsigned char *)(state+0x34));
            func_0029FCC0((char *)PROXY,1,(char *)work.aim.difference);
            func_0029FC20((char *)PROXY,1,(char *)secondMuzzle);
            func_00282CF0(angles,*(char **)(state+0x240)+0x10,work.aim.difference);
            func_00282F20(angles,angles,1.0f);
            secondMuzzle[2]=angles[2];
            func_00282F20(secondMuzzle,secondMuzzle,1.0f);
            func_L02_004216F0((unsigned char *)work.aim.difference,(int)self,(unsigned char *)secondMuzzle,
                    (float)*(unsigned char *)(state+0x34));
            PROXY[0xBC]=1;
        }
        object=(char *)PROXY;
        if ((object[0x60]&2) && object[0x43]) func_002A7470(object,0,0,3);
        return;
    case 10:
        *(unsigned int *)(state+0x258)=0x30FF00EA; return;
    case 12: case 13:
        *(unsigned int *)(state+0x258)=0xFF000000;
        if (self[0x20]==11) return;
        *(unsigned int *)(state+0x258)=0x8000FFFF;
        goto turn;
    case 7:
        if (self[0x20]!=7) return;
        *(unsigned int *)(state+0x258)=0x80806060;
turn:
        *(float *)(state+0x248)+=*(float *)(state+0x24C);
        *(float *)(state+0x24C)*=0.97f;
        *(float *)(state+0x248)=func_00283C28(*(float *)(state+0x248));
        *(Quadword *)work.rotation.original=0;
        work.rotation.original[2]=*(float *)(state+0x248);
        *(Quadword *)work.rotation.angles=*(Quadword *)work.rotation.original;
        func_002833F0(PROXY+0xC0,&work);
        object=(char *)PROXY;
        func_002AB6D8((float *)(object+0xC0),(float *)(object+0xF0));
        return;
    }
}
