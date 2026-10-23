/* Nonmatching: 388 bytes versus 376; USA 0/27 placements.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * +0x0: one extra saved register gives a 0xB0 frame instead of 0xA0. Advancing the object pointer before the loop tied. Reopen on the array/base live ranges. */

typedef int Quad __attribute__((mode(TI)));
extern Quad D_L00_00254960[],D_L00_001B2C00;
extern float D_L00_001B0CB0 __attribute__((sda)),D_L00_001B0CAC __attribute__((sda));
extern void func_00282D30(void *,void *,float);
extern void func_00282F20(void *,void *,float);
extern void func_00282CC0(void *,void *,void *);
void func_L00_00401168(char *object)
{
    Quad vectors[4], delta, center;
    Quad *out=D_L00_00254960;
    int i;
    vectors[0]=*(Quad *)(object+0xC0);
    vectors[3]=*(Quad *)(object+0xD0);
    func_00282D30(vectors+1,vectors,-1.0f);
    func_00282D30(vectors+2,vectors+3,-1.0f);
    out[4]=vectors[0]; out[5]=vectors[1]; out[6]=vectors[2]; out[7]=vectors[3];
    object += 0x10;
    for(i=0;i<8;i++,out++) {
        if(i<4) func_00282CC0(out,vectors+(i>>1),vectors+2+(i&1));
        func_00282F20(out,out,D_L00_001B0CB0);
        func_00282CC0(out,out,object);
        func_00282F20(&delta,&D_L00_001B2C00,-D_L00_001B0CAC);
        func_00282CC0(out,out,&delta);
        func_00282CC0(&center,&delta,object);
    }
}
