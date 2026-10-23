/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier
   USA: 384/384 bytes, 0/27 placements; first difference 0x24.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit saved integer/float allocation and the payload store order.
*/
typedef int Quad __attribute__((mode(TI)));
typedef struct { unsigned char b0,b1,b2,b3; int color; unsigned char seed,alpha; unsigned short size; float life; union { Quad q; float f[4]; } position; float payload[8]; } Particle;
extern Particle *func_002B9030(int);
extern int func_00283CF0(float);
extern int func_001163B0(void);
extern float func_00283CE0(int);
extern float func_00282E80(void *,void *);
extern float func_002A7878(float,float);
extern int func_002A77E0(int);
extern char *func_002AB1F0(int);
extern void func_00282CF0(float *,void *,void *);
extern void func_00283698(void *,void *);
extern void func_002830C0(float *,float *,void *);
extern unsigned char *D_L00_001FEA68,*D_L00_001FEAAC,*D_L00_001FEA40,*D_L00_001FEA78;
extern char D_00189EA0[];

Particle *func_L00_0033AA40(float life,float a,float b,Quad *position,Quad *velocity,unsigned int size,int color,int value,int flag)
{
    Particle *p=func_002B9030(0x40);
    if(p) {
        float *out=p->payload;
        p->position.q=*position;
        if(func_00282E80(D_00189EA0,position)<80.0f) p->alpha=func_00283CF0(1.0f)+48;
        else p->alpha=func_00283CF0(1.0f)+32;
        p->b3=flag?0x48:0x44;
        p->b1=0;
        p->b2=D_L00_001FEA40[1];
        p->color=color;
        p->life=life*210000.0f;
        { float random=func_002A7878(0.0f,255.0f);
          p->size=size; p->seed=(int)random; }
        *(Quad *)out=*velocity;
        out[4]=a;out[5]=b;
        *(int *)(out+6)=value;
    }
    return p;
}
