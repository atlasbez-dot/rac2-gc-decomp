/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 980 / 984 bytes; size equality is not a match.
 * us: 0/3 placements; 980/984 bytes.
 * us2: 0/3 placements; 980/984 bytes.
 * pal: 0/3 placements; 980/984 bytes.
 * Residual: 00_aranos_tutorial: 980 bytes, expected 984
 * Reopening condition: A faithful field/lifetime model explaining remaining stack, register or scheduling differences; no arbitrary padding/barriers.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Historical manual summary: The earlier automatic screen is superseded by the current manual reconstruction. Allocation and address formation remain experimental; extracted screen tables stay private. The original map is retained privately; no extracted instruction, opcode, address or generated table is reproduced here. */

/*
 * Nonmatching manual reconstruction; retail size 984 bytes.
 * Final US check: 00_aranos_tutorial: 980 bytes, expected 984.
 * Reproduce at src/levels/shared/L00_00382F28.c with:
 * -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Full body retained after bounded source/API/layout trials; no matching bytes
 * are claimed. Reopen when a truthful field or lifetime model explains the
 * remaining stack, register and scheduling differences.
 * US/US2/PAL coverage and catalogue absence are recorded in the private result.
 */
#include "common.h"
typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword bits; float f[4]; } Vector4;
#define FIELD(type,p,off) (*(type *)((char *)(p)+(off)))
extern void func_00282CF0(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_00282D30(void *,void *,float);
extern float func_00282DB0(void *,void *);
extern float func_00282DF0(void *);
extern float func_00282C48(float);
extern float func_00283C80(float,float);
extern float func_00283C28(float);
extern float func_00283180(float);
extern float func_002A7878(float,float);
extern float func_002A78D8(float,float);
extern float func_002A7940(void);
extern int func_002A77E0(int);
extern void func_002AF000(float *,float,float,float);
extern char *func_002C2210(void *,int,unsigned int,int,int,void *,int,float,float,float);
extern char *func_0029EFD0(int);
extern void func_002B37E8(void *,void *);
extern void func_002A7398(signed char *,int,int);
extern void func_002AEC18(void *,int);
extern void func_002833F0(void *,void *);
extern void func_002FE8D8(void *,void *);
extern void func_00282F20(void *,void *,float);
extern void func_00282DD8(void *,void *,void *);
extern float func_00283198(float);
extern void func_00283958(void *,void *);
extern void func_00283738(void *,void *,void *);
extern void func_00282C88(void *);
extern int func_002FEC78(unsigned char *,unsigned int);
extern int func_002FED90(void *,void *,float,float,float);
extern void func_0029F338(void *);
extern void func_002A0F48(void *);
extern void func_00283098(void *,void *,void *);
extern void func_002830C0(void *,void *,void *);
extern int func_002A7820(int,int);
extern unsigned long func_0027C878(int);
extern void func_00280B90(void *,void *,int);
extern void func_L00_003883B8(char *);
extern void func_L00_0038AA40(char *);
extern void func_L00_00388490(void *,Vector4 *);
extern void func_L00_0038AAD0(void *,Vector4 *);
extern void func_0029FCC0(char *,int,char *);
extern int func_001163B0(void);
extern int func_00282948(int *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern float func_00282E48(void *,void *);
extern unsigned char D_001B90C0[];
extern Vector4 D_001B8DC0;
extern int D_001A7348,D_001A734C,D_001A7350,D_001A7354;
extern int D_001B273C;
extern int D_L00_001AECF0;
extern void func_00279BD8(void *,void *);
extern void func_002FC560(unsigned int,unsigned long long);
extern void func_0027E018(int,int,int,int,int,int,int,int,unsigned long,unsigned long);
void func_L00_00382F28(char *object)
{
    char *work=FIELD(char *,object,0x68);
    Vector4 screen;
    float width,height,dx,dy,x,y,distance,fade,horizontal,vertical,alpha;
    unsigned long texture;
    int color;
    int i,size,left,top;
    if(FIELD(int,D_001B90C0,4)!=1 || !(FIELD(unsigned char,FIELD(char *,D_001B90C0,0),0x20)&0x80)) {FIELD(int,D_001B90C0,4)=0;return;}
    if(FIELD(float,D_001B90C0,8)<=0)return;
    distance=func_00282E48(&D_001B8DC0,work);
    width=func_00283CE0(D_001A7348);height=func_00283CE0(D_001A734C);
    func_00279BD8(&screen,work);
    screen.f[0]=(screen.f[0]-func_00283CE0(D_001A7350))*0.0625f;
    screen.f[1]=(screen.f[1]-func_00283CE0(D_001A7354))*0.0625f;
    dx=width-screen.f[0];dy=height-screen.f[1];
    for(i=0;i<14;++i) {
        texture=func_0027C878(D_001B273C+FIELD(short,D_001B90C0,0x30+i*2));
        x=width+dx*FIELD(float,D_001B90C0,0x90+i*4);y=height+dy*FIELD(float,D_001B90C0,0x90+i*4);
        fade=distance-5;if(fade>1)fade=1;else if(fade<0)fade=0;
        horizontal=(func_00282C48(dx)/width)*-5+5.5f;
        if(horizontal>1)horizontal=1;else if(horizontal<0)horizontal=0;
        vertical=(func_00282C48(dy)/height)*-5+5.5f;
        if(vertical>1)vertical=1;else if(vertical<0)vertical=0;
        alpha=fade*((horizontal*vertical)*FIELD(float,D_001B90C0,8));
        color=(int)(((unsigned int)func_00283CF0(alpha*(float)FIELD(short,D_001B90C0,0x10+i*2))<<24)|(FIELD(unsigned int,D_001B90C0,0x50+i*4)&0xFFFFFF));
        size=func_00283CF0((float)D_L00_001AECF0*FIELD(float,D_001B90C0,0xD0+i*4));
        func_002FC560(66,0x8000000048ULL);
        left=func_00283CF0(x-(float)(size>>1));top=func_00283CF0(y-(float)(size>>1));
        func_0027E018(left,top,size,size,0,0,64,64,color,texture);
    }
    FIELD(int,D_001B90C0,8)=0;
}
