/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   USA: 356/356 bytes, 0/27 placements; first difference 0x4.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit the local position pointer lifetime and collision-loop frame.
*/
typedef int Quad __attribute__((mode(TI)));
extern int func_00283CF0(float);
extern void func_0026FEB8(const char *,...);
extern void func_00282CF0(float *,float *,float *);
extern float func_00282E20(float *);
extern int func_L00_002DB4B8(float *,float *,float);
extern char D_L00_001A8988[];
extern char *D_L00_001B1880;

float *func_L00_002DB350(float radius,Quad *position)
{
    union { Quad q; float f[4]; } origin;
    float delta[4];
    int x,y;
    float *point=origin.f;
    origin.q=*position;
    x=func_00283CF0(point[0]*0.0625f);
    y=func_00283CF0(point[1]*0.0625f);
    if(x<0 || y<0 || x>64 || y>64) {
        func_0026FEB8(D_L00_001A8988);
    } else {
        int offset=((int *)D_L00_001B1880)[y*64+x];
        int *cell=(int *)(D_L00_001B1880+offset);
        if(!offset) return 0;
        {
            int i=0;
            float *primitive=(float *)(cell+4);
            for(;i<*cell;i++,primitive+=12) {
                float limit;
                func_00282CF0(delta,primitive,point);
                limit=primitive[3];
                delta[3]=1.0f;
                if(func_00282E20(delta)<limit+radius && func_L00_002DB4B8(point,primitive,radius)) return primitive;
            }
        }
    }
    return 0;
}
