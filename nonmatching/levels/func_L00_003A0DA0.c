/* Nonmatching: 384 bytes versus 396; USA 0/27 placements.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * +0x0: the rotation temporary remains live in a callee-saved TImode register instead of a second stack vector. A struct assignment regressed to 420 bytes; qcopy barrier toggling did not improve it. Reopen with a memory-lifetime explanation. */

typedef int Quad __attribute__((mode(TI)));
extern char *func_0029EFD0(int);
extern float func_002A7878(float,float);
extern void func_002A0488(void *,unsigned char,unsigned char,unsigned char);
extern void func_002A0F48(void *);
char *func_L00_003A0DA0(int value,Quad *position,Quad *velocity,int timer,
 unsigned char red,unsigned char green,unsigned char blue,unsigned char flags,float scale)
{
    char *object=func_0029EFD0(1192);
    char *state;
    Quad angles;
    union { Quad quad; float f[4]; } random;
    if(object) {
        state=*(char **)(object+0x68);
        random.quad=0;
        random.f[0]=func_002A7878(-3.1415927410125732f,3.1415927410125732f);
        random.f[1]=func_002A7878(-3.1415927410125732f,3.1415927410125732f);
        random.f[2]=func_002A7878(-3.1415927410125732f,3.1415927410125732f);
        angles=random.quad;
        object[0x20]=0; object[0x23]=flags; object[0x31]=1; *(unsigned char *)(object+0x30)=255;
        *(unsigned short *)(object+0x32)=255;
        func_002A0488(object,red,green,blue);
        *(float *)(state+0x18)=*(float *)(object+0x2C)*scale;
        *(float *)(object+0x2C)=0.0f;
        *(int *)(state+0x10)=value;
        *(Quad *)(object+0x10)=*position;
        *(Quad *)state=*velocity;
        *(Quad *)(object+0xF0)=angles;
        *(short *)(state+0x1E)=flags;
        *(int *)(state+0x14)=timer;
        *(short *)(state+0x1C)=*(unsigned short *)(state+0x14);
        func_002A0F48(object);
    }
    return object;
}
