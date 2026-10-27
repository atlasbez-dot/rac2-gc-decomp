/* Manual reconstruction, wave8 (2026-10-25). Nonmatching; no linked or runtime credit.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Final checks: US 0/3; US2 0/3; PAL absent from catalogue.
 * The initializer captures the complete aligned position with qcopy and snapshots the owner class before writes.
 * Defaults remain seven floats (28 bytes); the movement call retains its four floating inputs.
 * Initializer constant allocation, scalar-store scheduling and address construction differ; text 1196/1212 bytes.
 * Reopen with measured field/owner lifetimes or original initializer ordering; no wider default record is inferred.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));

typedef struct { float f0,f4,f8,fC,f10,f14,f18; } MotionDefaults;
extern MotionDefaults D_L18_001B1218 __attribute__((sda));
extern int D_001A79F0 __attribute__((sda));
extern unsigned char D_0019B2E8[];
extern unsigned char D_L18_0021EC14[];
extern float func_002A7878(float,float);
extern void *func_002B60B0(unsigned char *,float,float,float,float);
extern int func_002A7820(int,int);
extern float func_L09_0033E7A0(int);
extern int func_L18_00427130(unsigned char *,int,int);
extern void func_L18_00426F78(unsigned char *);
extern void func_L18_00427010(unsigned char *);
extern int func_001163B0(void);
extern void func_L18_00426F28(unsigned char *,int,int,float);
extern void func_002A7750(unsigned char *,int,int);
int func_L18_00427688(unsigned char *object)
{
    char *state;
    float randomAngle;
    unsigned int ownerClass;
    if(object[0xb0]!=0xff && (D_0019B2E8[D_001A79F0*16+object[0xb0]]&0x80)!=0 && D_L18_0021EC14[*(short *)(object+0xb2)]!=0) return 1;
    state=*(char **)(object+0x68);
    ownerClass=object[0x30];
    state[0x60]=10;
    *(float *)(state+0x6c)=0.1833333373f;
    *(float *)(state+0x70)=0.08333333582f;
    *(float *)(state+0x78)=0.008333333768f;
    *(float *)(state+0x8c)=0.4f;
    state[0xbd]=6;
    *(float *)(state+0x80)=0.4f;
    *(float *)(state+0x84)=0.4f;
    *(unsigned int *)(state+0x3e0)=ownerClass;
    state[0x66]=8; state[0x65]=9;
    *(float *)(state+0x7c)=0.004166666884f;
    state[0xbc]=3; state[0xc2]=5; state[0xc3]=11;
    state[0x28]=1;
    *(float *)(state+0x30)=0.75f;
    *(unsigned char *)(state+0x2f)=0xff;
    state[0x2a]=4; state[0x4a]=7;
    *(float *)(state+0x100)=0.7f;
    *(int *)(state+0x98)=9;
    state[0x61]=7; state[0x62]=8;
    *(unsigned char *)(state+0x67)=0xff;
    *(float *)(state+0x74)=0.004166666884f;
    state[0xbe]=5; state[0xbf]=11; state[0x2e]=1; state[0x4d]=0;
    *(float *)(state+0x104)=0.5f;
    *(float *)(state+0x108)=0.5f;
    *(float *)(state+0x10c)=0.5f;
    *(float *)(state+0x110)=1.22173059f;
    randomAngle=func_002A7878(20.0f,25.0f);
    *(float *)(state+0x134)=0.5f;
    state[0x1e8]=0; state[0x1e9]=0;
    *(float *)(state+0x130)=randomAngle*0.017453294f;
    *(float *)(state+0x12c)=D_L18_001B1218.f18*0.0002777777845f;
    if(*(short *)(object+0xaa)==0xed4) *(float *)(state+0x100)=1.0f;
    if(*(short *)(object+0xaa)==0xee1) *(float *)(state+0x100)=1.1f;
    if(*(float *)(state+0x3c4)==0.0f && *(float *)(state+0x3c0)==0.0f && *(float *)(state+0x3cc)==0.0f && *(float *)(state+0x3c8)==0.0f) {
        *(float *)(state+0x3c4)=D_L18_001B1218.f0;
        *(float *)(state+0x3c0)=D_L18_001B1218.f4;
        *(float *)(state+0x3cc)=D_L18_001B1218.f8;
        *(float *)(state+0x3c8)=D_L18_001B1218.fC;
        *(float *)(state+0x3dc)=D_L18_001B1218.f10;
        *(float *)(state+0x3d8)=D_L18_001B1218.f14;
        *(float *)(state+0x3d4)=D_L18_001B1218.f10;
        *(float *)(state+0x3d0)=D_L18_001B1218.f14;
    }
    func_002B60B0(object,*(float *)(state+0x3c4)*0.0002777777845f,*(float *)(state+0x3c0)*0.016666668f,*(float *)(state+0x3d4)*0.000004848137451f,*(float *)(state+0x3d0)*0.0002908882452f);
    randomAngle=func_002A7878(20.0f,40.0f);
    *(short *)(state+0x1e2)=180; *(short *)(state+0x1e4)=120;
    *(float *)(state+0x1dc)=randomAngle*0.017453294f;
    {
        void *position=object+0x10;
        void *initialPosition=state+0x1f0;
        qcopy(initialPosition,position);
    }
    *(float *)(state+0x200)=*(float *)(state+0x100);
    *(float *)(state+0x210)=5.0f;
    *(float *)(state+0x20c)=5.0f;
    *(int *)(state+0x37c)=*(int *)(state+0x360);
    *(short *)(state+0x392)=func_002A7820(0,45);
    func_L09_0033E7A0(*(int *)(state+0x368));
    func_L09_0033E7A0(*(int *)(state+0x13c));
    func_L09_0033E7A0(*(int *)(state+0xcc));
    func_L09_0033E7A0(*(int *)(state+0x380));
    func_L09_0033E7A0(*(int *)(state+0x384));
    *(int *)(state+0x13c)=*(int *)(state+0x380);
    func_L18_00427130(object,*(int *)(state+0x36c),-1);
    if(state[0x399]!=0) state[0x399]=1;
    func_L18_00426F78(object);
    func_L18_00427010(object);
    if(*(short *)(object+0xaa)==0xed4 || *(short *)(object+0xaa)==0xee1) state[0x39b]=2;
    else if(*(short *)(object+0xaa)==0xec0) { state[0x39b]=0; *(int *)(state+0x1c)=0; }
    func_L18_00426F28(object,func_001163B0()&1,0,1.0f);
    if(state[0x3e8]==0) {
        if(state[0x39c]!=0) {
            object[0x31]=0;
            *(unsigned short *)(object+0x34)|=1;
            func_002A7750(object,0,2);
            return 0;
        }
        func_002A7750(object,2,2);
    } else {
        func_002A7750(object,0,1);
        *(int *)(object+0x48)=0;
    }
    return 0;
}
