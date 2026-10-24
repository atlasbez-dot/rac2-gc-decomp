/* Manual reconstruction, 2026-10-23; retained, not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * us: 16_snivelak: instruction at +0xac differs; func_L16_004185C0: 0 of 1 places match (src/levels/16_snivelak/L16_004185C0-qcopy.c)
 * us2: 16_snivelak: instruction at +0xac differs; func_L16_004185C0: 0 of 1 places match (src/levels/16_snivelak/L16_004185C0-qcopy.c)
 * pal: func_L16_004185C0 is in neither catalogue of pal; func_L16_004185C0 is in neither catalogue of pal
 * 988/988 bytes; first remaining difference +0xac in both USA releases, in table-pointer materialization/allocation. Corrected unsigned state bytes and flag operation order; direct and no-split-address forms were measured. Reopen with independently justified source layout/lifetime evidence.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
typedef struct { Vector128 position,angles,delta,step; } RotatingMoverWorkspace;
typedef struct { unsigned char active; char reserved[19]; char *owner; char tail[88]; } SoundRecord;
extern char *D_L16_001B2B1C;
extern SoundRecord D_001886D4[];
extern float func_00283BE0(float,float);
extern float func_00283B98(float,float);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
extern int func_002E5CF8(int,int,char *);
extern void func_00282CF0(void *,void *,void *);
extern void func_002AD6F0(void *,void *,void *,void *);
void func_L16_004185C0(char *object)
{
    RotatingMoverWorkspace local;
    char *state=*(char **)(object+0x68);
    char *target;
    SoundRecord *sound;
    *(Vector128 *)&local.position=*(Vector128 *)(object+0x10);
    *(Vector128 *)&local.angles=*(Vector128 *)(object+0xf0);
    if(*(unsigned char *)(object+0x20)==0) {
        *(unsigned char *)(object+0x30)=0xff;
        object[0x20]=1;
        *(int *)(state+0x70)=-1;
        if(*(short *)(object+0xaa)==0x10fc) {
            *(int *)(object+0x98)=0;
            *(unsigned short *)(object+0x34)=(*(unsigned short *)(object+0x34)|0x41)&0xefff;
        }
    }
    if(*(unsigned char *)(object+0x20)==1 && *(unsigned char *)(D_L16_001B2B1C+*(int *)(state+0x6c)*0x100+0x20)==2) object[0x20]=2;
    if(*(unsigned char *)(object+0x20)==2) {
        if(*(int *)(state+0x68)==0) {
            if(*(short *)(object+0xaa)==0x10fe) {
                *(float *)(object+0xf8)=func_00283BE0(*(float *)(object+0xf8),0.0045378562063f);
                func_00282F20(&local.step,object+0xc0,0.05333333835f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
            }
            if(*(short *)(object+0xaa)==0x10fd) {
                *(float *)(object+0xf8)=func_00283BE0(*(float *)(object+0xf8),0.00450294977f);
                func_00282F20(&local.step,object+0xc0,0.03333333507f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
            }
            if(*(short *)(object+0xaa)==0x10fc) {
                *(float *)(object+0xf8)=func_00283BE0(*(float *)(object+0xf8),0.0045378562063f);
                func_00282F20(&local.step,object+0xc0,0.04333333299f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
                target=D_L16_001B2B1C+*(int *)(state+0x6c)*0x100+0x10;
                func_00282CC0(target,&local.step,target);
                sound=D_001886D4+*(int *)(state+0x70);
                if(sound->owner!=object || sound->active==0) *(int *)(state+0x70)=func_002E5CF8(0,4,object);
            }
        } else {
            if(*(short *)(object+0xaa)==0x10fe) {
                *(float *)(object+0xf8)=func_00283B98(*(float *)(object+0xf8),0.0045378562063f);
                func_00282F20(&local.step,object+0xc0,-1.0f);
                func_00282F20(&local.step,&local.step,0.05333333835f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
            }
            if(*(short *)(object+0xaa)==0x10fd) {
                *(float *)(object+0xf8)=func_00283B98(*(float *)(object+0xf8),0.0045378562063f);
                func_00282F20(&local.step,object+0xc0,-1.0f);
                func_00282F20(&local.step,&local.step,0.03333333507f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
            }
            if(*(short *)(object+0xaa)==0x10fc) {
                *(float *)(object+0xf8)=func_00283B98(*(float *)(object+0xf8),0.0045378562063f);
                func_00282F20(&local.step,object+0xc0,-1.0f);
                func_00282F20(&local.step,&local.step,0.04333333299f);
                func_00282CC0(object+0x10,&local.step,object+0x10);
                target=D_L16_001B2B1C+*(int *)(state+0x6c)*0x100+0x10;
                func_00282CC0(target,&local.step,target);
            }
        }
    }
    func_00282CF0(&local.delta,object+0x10,&local.position);
    func_002AD6F0(state+0x20,&local.delta,&local.angles,object+0xf0);
}
