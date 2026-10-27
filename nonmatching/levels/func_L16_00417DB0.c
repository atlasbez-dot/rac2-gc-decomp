/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses.
 * Compiled 1076 bytes; retail 1076 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: Shared qcopy and the actual audio-bank field view reach retail size, up from 1072.
 * The 0xC0 frame agrees; the first difference is +0xB4 in argument/address setup, with later
 * branch and vector lifetime differences. The three-float direction helper and unsigned state
 * sentinels remain explicit.
 * Reopen: A spark-update caller/source lifetime witness for the resident vector and complete
 * direction helper arguments.
 */

#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 player,velocity,previous,point; } SparkWorkspace;
extern char *D_L16_001B2B1C;
extern float D_00189EA0[4];
extern char *D_0018C0B0;
extern char *D_L16_001BFF58;
extern Vector128 D_L16_001BFF60;
extern char D_00188660[];
extern int func_002ACBC8(void *,int);
extern float func_002A7878(float,float);
extern void func_L00_002E6EF8(void (*)(void *),void *);
extern void func_L14_003F0E68(void *);
extern int func_002A8508(int,int);
extern int func_00277258(void *,int,void *,float);
extern int func_002E5CF8(int,int,char *);
extern int func_002A77E0(int);
extern float func_002A7940(void);
extern void func_002AF000(float *,float,float,float);
extern float func_002A78D8(float,float);
extern void func_002C2210(void *,int,unsigned int,int,int,void *,int,float,float,float);
extern void func_002E59F8(int);
void func_L16_00417DB0(char *object)
{
    SparkWorkspace local;
    char *state=*(char **)(object+0x68);
    char *target;
    char *sound;
    float speed,firstAngle,secondAngle,magnitude;
    int i,index,handle;
    if(*(unsigned char *)(object+0x20)==0) {
        object[0x20]=1;
        *(int *)(object+0x98)=0;
        *(unsigned short *)(object+0x34)|=0x41;
    }
    if(*(unsigned char *)(object+0x20)==1) {
        target=D_L16_001B2B1C+*(int *)state*0x100;
        if(target==0 || *(unsigned char *)(target+0x20)==0xfe || *(unsigned char *)(target+0x20)==0xfd) {
            if(func_002ACBC8(D_00189EA0,*(int *)(state+8))!=0) {
                object[0x20]=2;
                *(int *)(object+0x98)=*(int *)(*(char **)(object+0x24)+0x10);
            }
        }
    }
    if(*(unsigned char *)(object+0x20)!=2) return;
    *(float *)(state+0x10)+=*(float *)(state+0x14);
    *(float *)(state+0x18)+=*(float *)(state+0x1c);
    if(*(float *)(state+0x10)>=8.0f) *(float *)(state+0x10)-=8.0f;
    if(*(float *)(state+0x18)>=8.0f) *(float *)(state+0x18)-=8.0f;
    *(float *)(state+0x14)=func_002A7878(0.003f,0.005f);
    *(float *)(state+0x1c)=func_002A7878(0.001f,0.0025f);
    func_L00_002E6EF8(func_L14_003F0E68,object);
    if(func_002A8508(*(int *)(state+4),-1)==0) {
        *(int *)(object+0x98)=0;
        object[0x20]=3;
    }
    qcopy(&local.player,D_00189EA0);
    ((float *)&local.player)[2]=D_00189EA0[2]+0.75f;
    if(func_00277258(&local.player,0,D_0018C0B0,0.5f)!=0 && D_L16_001BFF58!=0 && *(short *)(D_L16_001BFF58+0xaa)==0x10fb) {
        qcopy(&local.point,&D_L16_001BFF60);
        for(i=2;i>=0;i--) {
            handle=*(int *)(state+12);
            sound=D_00188660+0x70*handle;
            if((*(char **)(sound+0x88))!=object || (*(unsigned char *)(sound+0x74))==0) *(int *)(state+12)=func_002E5CF8(1,4,object);
            speed=func_002A7878(1.0f,2.0f);
            index=func_002A77E0(2);
            if(index==0) index--;
            firstAngle=func_002A7940();
            secondAngle=func_002A7878(0.3490658998f,1.535889864f);
            magnitude=func_002A7878(0.05f,0.1f);
            func_002AF000((float *)&local.velocity,magnitude,firstAngle,secondAngle);
            qcopy(&local.previous,&local.point);
            ((float *)&local.point)[0]+=func_002A78D8(0.0f,0.15f);
            ((float *)&local.point)[1]+=func_002A78D8(0.0f,0.15f);
            ((float *)&local.point)[2]+=func_002A78D8(0.0f,0.15f);
            func_002C2210(&local.point,15,0xff803040u,0,index,&local.velocity,0,speed*0.1f,speed,0.006f);
        }
        return;
    }
    handle=*(int *)(state+12);
    if(handle!=-1) {
        sound=D_00188660+0x70*handle;
        if((*(char **)(sound+0x88))==object && (*(unsigned char *)(sound+0x74))!=0) func_002E59F8(handle);
    }
    *(int *)(state+12)=-1;
}
