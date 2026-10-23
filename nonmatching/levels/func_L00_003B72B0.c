/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G8 -ffunction-sections
   USA: 344/352 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: absent, us2: 0/27.
   Revisit the shared camera-state base and mixed small-data declarations.
*/
extern int func_002A7820(int,int);
extern int func_002A77E0(int);
extern void func_002A7A00(float *,float,float);
extern void func_00282CC0(float *,float *,float *);
extern void func_00283098(float *,float *,float *);
extern void func_002C3150(void *,void *,int,int,int,int,float);
extern int D_L00_001AFB58 __attribute__((sda));
extern int D_L00_001AFB5C;
extern float D_L00_001AFB40 __attribute__((sda));
extern float D_L00_001AFB30 __attribute__((sda));
extern float D_L00_001AFB34;
extern int D_L00_001AFB50;
extern int D_L00_001AFB54;
extern float D_L00_001AFB44;
extern int D_L00_001AFB48[2][2] __attribute__((sda));

extern int D_L00_001AFB68 __attribute__((sda));
extern float D_L00_001AFAE8 __attribute__((sda));
extern float D_L00_001AFAEC;
extern int D_L00_001AFB10;
extern int D_L00_001AFB14;
extern int D_L00_001AFB04;
extern float D_L00_001AFAFC;
extern int D_L00_001AFB70[2] __attribute__((sda));

extern float D_L00_001AFB20[4] __attribute__((sda));
extern float D_L00_001B8FF0[16];
extern float D_L00_001B8DC0[4];
extern int D_L00_001AFB08 __attribute__((sda));
extern int D_L00_001AFB0C;
extern float D_L00_001AFAF8 __attribute__((sda));
extern int D_L00_001AFB00 __attribute__((sda));
extern float D_L00_001A8F20[4];
extern int D_L00_001AFB18 __attribute__((sda));

void func_L00_003B72B0(void)
{
    float point[4],velocity[4],scatter[4];
    int i=0;
    unsigned char kind,random;
    func_00283098(point,D_L00_001AFB20,D_L00_001B8FF0);
    func_00282CC0(point,point,D_L00_001B8DC0);
    kind=func_002A7820(D_L00_001AFB08,D_L00_001AFB0C);
    random=func_002A77E0(255);
    func_002C3150(point,D_L00_001A8F20,D_L00_001AFB00,kind,random,0,D_L00_001AFAF8);
    func_002A7A00(velocity,D_L00_001AFAE8*(1.0f/60.0f),D_L00_001AFAEC*(1.0f/60.0f));
    while(i<D_L00_001AFB18) {
        i++;
        func_002A7A00(scatter,0.0f,0.25f);
        func_00282CC0(scatter,scatter,point);
        kind=func_002A7820(D_L00_001AFB10,D_L00_001AFB14);
        random=func_002A77E0(255);
        func_002C3150(scatter,velocity,D_L00_001AFB04,kind,random,0,D_L00_001AFAFC);
    }
}
