/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 1288 / 1292 bytes; size equality is not a match.
 * us: 0/1 placements; 1288/1292 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: 4 bytes short; guard sharing, table addressing, register allocation and copy scheduling differ. G0 reached equal size without equality.
 * Reopening condition: Concrete original guard/control-flow and table lifetime hypothesis.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction of the Dobbo Orbit damage response.
 * Retail US: 1292 bytes; final trial: 1288 bytes, 0/1 placements, exit 1.
 * US2 and PAL do not carry this canonical function in their catalogues.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Seven bounded trials covered default/G8 addressing, shared reject control
 * flow, scoped resident pointers and mask/index expressions. G0 also reached
 * 1292 bytes but did not match; equal size is not byte equality. Remaining
 * differences include guard sharing, table addressing, allocation and copies.
 * Reopen with evidence for the original control-flow shape and table lifetimes.
 * The 64-byte DamageRecord stride and all resident offsets are measured views;
 * neither the array extent nor the full resident object extent is inferred.
 */
typedef int Quadword __attribute__((mode(TI)));
typedef struct {
    unsigned char prefix00[0x10];
    float direction[4];
    unsigned char *target;
    unsigned int flags;
    unsigned char kind;
    unsigned char reserved29[3];
    float amount;
    unsigned int directionFlags;
    unsigned int reserved34;
    unsigned char *owner;
    unsigned int reserved3C;
} DamageRecord;
extern unsigned char D_00189E20[];
extern DamageRecord D_L22_001C4340[];
extern int D_L22_001A8F00;
extern unsigned char D_001A7A32;
extern unsigned char D_001A7A33;
extern float func_L00_0037E668(void);
extern float func_L00_0037E5F0(float);
extern int func_00283CF0(float);
extern void func_L00_002A6708(void);
extern void func_00282CF0(void *, void *, void *);
extern void func_L00_002D36E0(float *, int, float, float, float);
extern int func_L22_002C9898(long, int);
extern void *func_002A9640(void *, unsigned int, int);
extern void func_L00_002A4EF8(unsigned long);
extern int func_L00_002B9B88(int, int);
extern void func_L00_002B2C58(int, int, float, float);
extern void func_L00_002D3C68(char *, char *, float);
extern void func_L22_003B9358(unsigned int);
extern void func_00282D30(void *, void *, float);
extern void func_00282C88(Quadword *);
extern void func_00282CC0(void *, void *, void *);

/* Validate a pending hit, choose the player response and add its impulse. */
int func_L22_002B7550(long apply)
{
    unsigned char *p = D_00189E20;
    DamageRecord *hit;
    unsigned char *object;
    void *effect;
    float impulse[4];
    int inLocalFrame;
    int health;
    unsigned char index;
    unsigned int flags;
    float gate;

    if (*(int *)(p+0x229C)==20 || *(int *)(p+0x229C)==7 || *(int *)(p+0x2294)==49) {
reject:
        return 0;
    }
    if (*(short *)(p+0x1DC)) return 0;
    if (D_L22_001A8F00) return 0;
    *(int *)(p+0x249C)=0;
    object=*(unsigned char **)(p+0x2290);
    index=object[0xA8];
    if (index==255) goto reject;
    hit=&D_L22_001C4340[index];
    if (hit->owner!=object) return 0;
    flags=hit->flags;
    if (p[0x22B4]==2) flags &= 2;
    else flags &= 9;
    if (!flags) return 0;
    if (hit->amount!=0.0f) { D_001A7A33=0; D_001A7A32=1; }
    gate=func_L00_0037E668();
    if (gate!=0.0f) {
        unsigned char *q=D_00189E20;
        if (q[0x22B4]==0) {
            hit->amount=func_L00_0037E5F0(hit->amount);
            if (hit->amount==0.0f) return 0;
        }
    }
    { unsigned char *state=D_00189E20;
    *(unsigned char **)(state+0x249C)=hit->target;
    if (*(int *)(state+0x229C)==15) {
        *(DamageRecord **)(state+0x6C4)=hit;
        *(short *)(state+0x68E)=1;
        return 0;
    }
    if (state[0x22B4]==2) {
        health=*(int *)(state+0x1874)-func_00283CF0(hit->amount);
        *(int *)(state+0x1874)=health;
        if (health<0) *(int *)(state+0x1874)=0;
    }
    if (!apply) return 1;
    inLocalFrame=0;
    func_L00_002A6708();
    if (hit->directionFlags & 1) {
        *(Quadword *)impulse=*(Quadword *)hit->direction;
        if (hit->direction[3]==5627.9248046875f) inLocalFrame=1;
    } else if (!hit->target) {
        func_L00_002D36E0(impulse,0,-1.0f,0.0f,0.0f);
    } else {
        func_00282CF0(impulse,D_00189E20+0x80,hit->target+0x10);
    }
    if (D_00189E20[0x22B4]==1) goto characterOne;
    if (D_00189E20[0x22B4]>1) {
        if (D_00189E20[0x22B4]==2) goto characterTwo;
        goto applyImpulse;
    }
    if (D_00189E20[0x22B4]!=0) goto applyImpulse;
        object=*(unsigned char **)(D_00189E20+0x249C);
        if (object && (*(short *)(object+0xAA)==0x4EB || *(short *)(object+0xAA)==0x558)) {
            func_L22_002C9898(0x7D,1);
            return 1;
        }
        if (*(int *)(D_00189E20+0x2294)==1 || *(int *)(D_00189E20+0x2294)==29 || *(int *)(D_00189E20+0x1500)) {
            if (!(hit->flags & 8)) {
                effect=func_002A9640(*(void **)(D_00189E20+0x2290),1,0);
                if (effect) func_L00_002A4EF8(func_00283CF0(*(float *)((char *)effect+0x2C)));
                if (*(int *)(D_00189E20+0x24CC)==0) func_L22_002C9898(22,1);
                *(short *)(D_00189E20+0x1DC)=77;
                if (*(short *)(D_00189E20+0x21C)==0) *(short *)(D_00189E20+0x21C)=18;
                func_L00_002B9B88(20,0);
                return 0;
            }
        }
        if (*(int *)(D_00189E20+0x229C)==18) func_L22_002C9898(0x72,1);
        else if (*(int *)(D_00189E20+0x229C)==17) func_L22_002C9898(0x73,1);
        else if (hit->flags & 8) func_L22_002C9898(0x8C,1);
        else func_L22_002C9898(22,1);
        if (*(int *)(D_00189E20+0x2294)==0x8C) {
            *(Quadword *)impulse=0;
        } else {
            func_L00_002B2C58((int)impulse,inLocalFrame,D_00189E20[0x1497] ? 0.0f : 0.055000003427267075f,0.028333336f);
            if (inLocalFrame && hit->kind==4)
                func_L00_002D3C68((char *)impulse,(char *)impulse,2.0f);
        }
        goto applyImpulse;
characterOne:
        func_L22_002C9898(0x42,1);
        func_L00_002B2C58((int)impulse,inLocalFrame,0.083333336f,0.050000004f);
        goto applyImpulse;
characterTwo:
        if (!(hit->flags & 4) && *(int *)(D_00189E20+0x1874)>0) {
            func_00282C88((Quadword *)impulse);
            goto applyImpulse;
        }
        if (hit->target && *(short *)(hit->target+0xAA)==0x11DF)
            func_L22_002C9898(0x5A,1);
        else
            func_L22_002C9898(0x59,1);
        func_L22_003B9358((unsigned int)*(void **)(D_00189E20+0x2290));
        func_00282D30(impulse,impulse,0.095f);
        goto applyImpulse;
applyImpulse:
    func_00282CC0(D_00189E20+0xF0,D_00189E20+0xF0,impulse);
    func_00282CC0(D_00189E20+0x110,D_00189E20+0x110,impulse);
    return 1;
    }
}
