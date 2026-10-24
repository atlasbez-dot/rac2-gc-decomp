/* Manual reconstruction, 2026-10-23; retained, not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses.
 * us: 16_snivelak: 2028 bytes, expected 1988; func_L16_00435CE8: 0 of 1 places match (src/levels/16_snivelak/L16_00435CE8-g8-qcopy.c)
 * us2: 16_snivelak: 2028 bytes, expected 1988; func_L16_00435CE8: 0 of 1 places match (src/levels/16_snivelak/L16_00435CE8-g8-qcopy.c)
 * pal: func_L16_00435CE8 is in neither catalogue of pal; func_L16_00435CE8 is in neither catalogue of pal
 * 2028/1988 bytes in both USA releases. Camera configuration branch merging, clamped interpolation and mixed global accesses differ. All camera helper FP/GPR inputs follow current definitions and retail calls; reopen with original configuration-record and control-flow evidence.
 */
#include "common.h"
typedef int Vector128 __attribute__((mode(TI)));
extern char *D_L16_001B24C4 __attribute__((nosda));
extern char *D_L16_001B9B50 __attribute__((nosda));
extern char D_L16_001B9B00[];
extern int D_L16_001A8FF0 __attribute__((nosda));
extern int D_001A79F0 __attribute__((nosda)),D_0018C0B4 __attribute__((nosda)),D_0018C0BC __attribute__((nosda));
extern char *D_0018C0B0 __attribute__((nosda));
extern unsigned char D_0018C0D4 __attribute__((nosda)),D_0018A2BE __attribute__((nosda));
extern short D_0018B274 __attribute__((nosda));
extern float D_00138280 __attribute__((nosda)),D_00138284 __attribute__((nosda)),D_00189F90 __attribute__((nosda)),D_0018A340 __attribute__((nosda));
extern Vector128 D_00189EA0,D_00189ED0;
extern float D_L16_001B227C __attribute__((sda)),D_L16_001B2284 __attribute__((sda));
extern float D_L16_001B2288 __attribute__((sda)),D_L16_001B228C __attribute__((sda));
extern float D_L16_001B2290 __attribute__((sda)),D_L16_001B2294 __attribute__((sda));
extern float D_L16_001B2298 __attribute__((sda)),D_L16_001B229C __attribute__((sda));
extern float D_L16_001B22A0 __attribute__((sda)),D_L16_001B22A4 __attribute__((sda));
extern float D_L16_001B22A8 __attribute__((sda)),D_L16_001B22AC __attribute__((sda));
extern float D_L16_001B22B0 __attribute__((sda)),D_L16_001B20FC __attribute__((sda));
extern int D_L16_001B26CC __attribute__((sda));
extern float func_00282E48(void *,void *);
extern float func_002B0360(char *);
extern int func_L00_00424940(int);
extern int func_L00_00424978(char *);
extern int func_002ACBC8(void *,int);
extern float func_00282C48(float);
extern void func_L00_00424C00(void),func_L00_00424C28(void);
extern void func_L00_00424B48(int);
extern void func_L00_00424B70(float,float);
extern int func_00282948(int *);
extern void func_L00_00424F00(char *,float,float);
extern float func_L01_002C81D0(float,float,float);
extern int func_00283CF0(float);
extern void func_L16_0042FB58(float,float);
extern void func_L00_00424BB8(float,float);
extern void func_L00_00424A08(int,float,float);
extern void func_L00_00424A50(float,float);
extern void func_L00_00424A88(int,float,float);
extern void func_L00_00424B20(float);
void func_L16_00435CE8(char *object)
{
    Vector128 point[1];
    char *record=D_L16_001B24C4+*(short *)(object+0x84)*0x20;
    char *settings=*(char **)(record+0x1c);
    float distance,clamped,ratio,first,second;
    int i,rotation;
    if(*(int *)(settings+0x20)==0) {
        if(D_L16_001A8FF0==0 && (D_001A79F0!=16 || D_0018C0B4!=0x81)) return;
        ((float *)point)[0]=*(float *)record;
        ((float *)point)[1]=*(float *)(record+4);
        ((float *)point)[2]=*(float *)(record+8);
        ((float *)point)[3]=0.0f;
        *(float *)(settings+0x24)=func_00282E48(point,&D_00189ED0);
        *(int *)(settings+0x20)=1;
        return;
    }
    if(*(short *)(D_L16_001B9B50+0x86)!=0 || !(D_L16_001A8FF0!=0 || (D_001A79F0==16 && D_0018C0B4==0x81))) {
        if(func_002B0360(D_L16_001B9B00)>D_L16_001B22B0) D_L16_001B26CC=3;
        else D_L16_001B26CC=0;
        func_L00_00424940((int)object);
        return;
    }
    if(func_L00_00424978(object)<=0) return;
    for(i=0;i<6;i++) {
        if(*(int *)(settings+0x28+i*4)<0) break;
        if(func_002ACBC8(&D_00189EA0,*(int *)(settings+0x28+i*4))!=0) {
            func_L16_0042FB58(0.04f,0.2f);
            func_L00_00424A08(0,*(float *)(settings+0x40),0.003f);
            func_L00_00424A50(*(float *)(settings+0x44),0.003f);
            return;
        }
    }
    if(D_0018C0D4!=2 || D_0018B274!=0 || D_0018C0B4==0x5b || func_00282C48(D_00138280)>=0.3f || func_00282C48(D_00138284)>=0.3f) {
        func_L00_00424C00();
        func_L00_00424B48(0);
    }
    func_L00_00424C28();
    func_L00_00424B70(D_L16_001B2284,0.2f);
    if(func_00282948((int *)(settings+0x50))!=0 && D_00189F90<=0.005f) func_L00_00424F00(D_0018C0B0+0xc0,0.005235988647f,0.0f);
    if(func_00282C48(D_00138280)>=0.3f || func_00282C48(D_00138284)>=0.3f) *(int *)(settings+0x50)=300;
    if(D_0018C0D4==2) {
        *(int *)(*(char **)(D_L16_001B9B50+0x70)+0x250)=2;
        rotation=0;
        if(D_0018A2BE!=0) rotation=func_00283CF0(func_L01_002C81D0(90.0f,D_0018A340,-1.0f));
        if(D_0018C0B4==0x5b && (D_0018A2BE==0 || rotation>19)) {
            func_L00_00424B70(0.5f,1.0f);
            func_L16_0042FB58(0.05f,0.2f);
            func_L00_00424BB8(0.04f,0.0f);
            func_L00_00424A88(0,D_L16_001B22A4,0.005f);
            func_L00_00424A08(1,D_L16_001B2298,0.01f);
            func_L00_00424A50(D_L16_001B229C,0.01f);
            D_L16_001B20FC=D_L16_001B22AC*0.017453294f;
            func_L00_00424B20(D_L16_001B22A8*0.017453294f);
        } else {
            func_L00_00424A88(0,D_L16_001B22A0,0.03f);
            if(D_0018C0BC==2) func_L16_0042FB58(0.04f,0.2f);
            else func_L16_0042FB58(0.015f,0.2f);
            distance=func_00282E48(&D_00189EA0,&D_00189ED0)-*(float *)(settings+0x24);
            clamped=D_L16_001B227C;
            if(distance<=D_L16_001B227C) { clamped=distance; if(distance<0.0f) clamped=0.0f; }
            ratio=clamped/D_L16_001B227C;
            second=(D_L16_001B2294-D_L16_001B228C)*ratio+D_L16_001B228C;
            first=(D_L16_001B2290-D_L16_001B2288)*ratio+D_L16_001B2288;
            func_L00_00424A08(1,first,0.005f);
            func_L00_00424A50(second,0.005f);
        }
        if(func_002B0360(D_L16_001B9B00)>D_L16_001B22B0) D_L16_001B26CC=3;
        else D_L16_001B26CC=0;
        return;
    }
    if(D_0018C0B4==0x81) {
        func_L16_0042FB58(0.05f,0.2f);
        func_L00_00424BB8(0.04f,0.0f);
        if(D_001A79F0==16) {
            func_L00_00424A88(0,0.5f,0.04f);
            func_L00_00424A08(0,4.0f,0.002f);
            func_L00_00424A50(2.0f,0.04f);
        } else {
            func_L00_00424A88(0,1.0f,0.04f);
            func_L00_00424A08(0,2.0f,0.002f);
            func_L00_00424A50(7.0f,0.04f);
        }
        return;
    }
    if(D_0018C0BC==2) func_L16_0042FB58(0.04f,0.2f);
    else func_L16_0042FB58(0.015f,0.2f);
    if(D_0018C0BC==5) {
        func_L00_00424A08(0,4.0f,0.003f);
        func_L00_00424A50(6.0f,0.003f);
        return;
    }
    distance=func_00282E48(&D_00189EA0,&D_00189ED0)-*(float *)(settings+0x24);
    clamped=D_L16_001B227C;
    if(distance<=D_L16_001B227C) { clamped=distance; if(distance<0.0f) clamped=0.0f; }
    ratio=clamped/D_L16_001B227C;
    second=(*(float *)(settings+0x4c)-*(float *)(settings+0x44))*ratio+*(float *)(settings+0x44);
    first=(*(float *)(settings+0x48)-*(float *)(settings+0x40))*ratio+*(float *)(settings+0x40);
    func_L00_00424A08(0,first,0.003f);
    func_L00_00424A50(second,0.003f);
}
