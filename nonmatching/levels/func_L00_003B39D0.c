/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   USA: 296/292 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit the original object pointer lifetime around the collision call.
*/
typedef int Quad __attribute__((mode(TI)));
typedef struct { char pad00[0xb0]; float origin[4]; char padc0[0x21d0]; int mask; } CollisionState;
extern CollisionState D_00189E20;
extern Quad D_L00_001BF230[2];
extern int D_L00_001A8FF0;
extern int func_00277258(void *,int,float,void *);
extern void func_00282CF0(float *,void *,void *);
extern void func_00282F20(float *,float *,float);
extern float func_00282DB0(float *,float *);
extern void func_00282D30(float *,float *,float);
extern void func_00283028(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);

void func_L00_003B39D0(char *object)
{
    float normal[4],projection[4],remaining[4];
    void *position=object+0x10;
    char *data=*(char **)(object+0x68);
    if(func_00277258(position,0,0.25f,(void *)D_00189E20.mask)) {
        *(Quad *)position=D_L00_001BF230[0];
        if(D_L00_001A8FF0) {
            float dot;
            data+=0x30;
            func_00282CF0(normal,D_00189E20.origin,position);
            func_00282F20(normal,normal,1.0f);
            dot=func_00282DB0(normal,(float *)data);
            func_00282D30(projection,normal,dot);
            func_00282CF0(remaining,data,projection);
            func_00283028(data,remaining,&D_L00_001BF230[1]);
            func_00282CC0(data,data,projection);
        } else {
            float vertical=*(float *)(data+0x38);
            *(float *)(data+0x38)=0;
            func_00283028(data+0x30,data+0x30,&D_L00_001BF230[1]);
            *(float *)(data+0x38)=vertical;
        }
    }
}
