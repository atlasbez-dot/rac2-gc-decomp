/* Manual reconstruction, 2026-10-23; retained, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 16_snivelak: 788 bytes, expected 800; func_L16_004192A8: 0 of 1 places match (src/levels/16_snivelak/L16_004192A8-g8-qcopy.c)
 * us2: 16_snivelak: 788 bytes, expected 800; func_L16_004192A8: 0 of 1 places match (src/levels/16_snivelak/L16_004192A8-g8-qcopy.c)
 * pal: func_L16_004192A8 is in neither catalogue of pal; func_L16_004192A8 is in neither catalogue of pal
 * 788/800 bytes in both USA releases; state-chain merging, initialization-loop shape and field/FP scheduling remain different. One manual C trial. Reopen with original state-chain/source-lifetime evidence.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef struct { Quad16 vector; int owner,flags; unsigned char enabled,kind; unsigned short id; float distance; int active; } CollisionRequest;
typedef struct { Vector128 position,offset; CollisionRequest request; Vector128 direction; } MarkerWorkspace;
extern float func_002A7940(void);
extern void func_002A7750(unsigned char *,unsigned char,int);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_00277258(void *,int,void *,float);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern void func_L00_002B30E8(void);
extern void func_00282D60(void *,void *,float);
extern float func_00283B98(float,float);
extern float func_002A78D8(float,float);
extern void func_L00_002E6CF0(void (*)(void *),void *);
extern void func_L13_0041FBE0(void *);
extern float func_002AA2E8(float *,float,float);
extern int D_001A79F0;
extern Vector128 D_00189EA0;
extern char *D_0018C0B0;
extern char *D_0018A15C;
extern int D_0018A160;
extern char *D_L16_001BFF58 __attribute__((nosda));
extern Quad16 D_L16_001A8F20;
extern float D_L16_001B1CA0 __attribute__((sda));
extern float D_L16_001B1CA4 __attribute__((sda));
extern float D_L16_001B1CA8 __attribute__((sda));
void func_L16_004192A8(char *object)
{
    MarkerWorkspace local;
    float *state=*(float **)(object+0x68);
    float value;
    int i;
    if (*(unsigned char *)(object+0x20)==0) {
        state[0]=1.0f;
        state[8]=func_002A7940();
        state[2]=0.5f;
        state[1]=0.0f;
        state[0]=1.0f;
        for(i=7;i>=4;i--) state[i]=1.0f;
        *(unsigned char *)(object+0x30)=0xff;
        func_002A7750((unsigned char *)object,1,-1);
        object[0x31]=0;
        *(unsigned short *)(object+0x34)|=1;
    } else if (*(unsigned char *)(object+0x20)==1 && D_001A79F0==16) {
        *(Vector128 *)&local.position=D_00189EA0;
        func_00282F20(&local.offset,D_0018C0B0+0xe0,0.75f);
        func_00282CC0(&local.position,&local.position,&local.offset);
        if (func_00277258(&local.position,0,D_0018C0B0,0.5f)!=0 && D_L16_001BFF58!=0 && D_L16_001BFF58==object) {
            func_002A8C00((char *)&local.request,(int)object,1,100.0f,&D_L16_001A8F20);
            local.request.id=*(unsigned short *)(object+0xaa);
            func_L00_002B30E8();
        }
        if (D_0018A15C!=0 && D_0018A15C==object && D_0018A160!=0) {
            ((float *)&local.direction)[0]=0.0f;
            ((float *)&local.direction)[1]=1.0f;
            ((float *)&local.direction)[2]=0.0f;
            ((float *)&local.direction)[3]=1.0f;
            func_00282F20(&local.direction,&local.direction,10.0f);
            func_002A8C00((char *)&local.request,(int)object,1,10.0f,(Quad16 *)&local.direction);
            local.request.id=*(unsigned short *)(object+0xaa);
            func_L00_002B30E8();
        }
    }
    if (state[0]!=0.0f) {
        func_00282D60(&local.position,object,0.0009765625f);
        state[8]=func_00283B98(state[8],D_L16_001B1CA0*0.0002908882452f);
        state[3]+=(D_L16_001B1CA4+func_002A78D8(0.25f,0.5f))*0.016666668f;
        if (state[3]>1.0f) state[3]-=1.0f;
        for(i=1;i<=2;i++) {
            value=state[i]+D_L16_001B1CA8*0.016666668f;
            state[i]=value;
            if(value>1.0f) state[i]=value-1.0f;
        }
        func_L00_002E6CF0(func_L13_0041FBE0,object);
        func_002AA2E8(state,1.0f,0.008333333768f);
    }
}
