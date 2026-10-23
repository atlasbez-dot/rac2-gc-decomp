/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
   USA: 372/352 bytes, 0/27 placements; size differs from retail.
   us: 0/27, pal: 0/27, us2: 0/27.
   Revisit quadword temporary layout and random-result lifetimes; por is compiler-reachable.
*/
typedef int Quad __attribute__((mode(TI)));
extern int func_001163B0(void);
extern void func_001163A0(int);
extern float func_002A78D8(float,float);
extern float func_002A7878(float,float);
extern int func_00283D38(int,int,float);
extern int func_002A77E0(int);
extern void func_00283098(void *,void *,void *);
extern void func_00282CC0(void *,void *,void *);
extern void func_002C3150(void *,void *,int,int,int,int,float);
extern int D_L00_001AFB78 __attribute__((sda));
extern float D_L00_001AFB88 __attribute__((sda));
extern float D_L00_001AFB8C;
extern float D_L00_001AFB90 __attribute__((sda));
extern float D_L00_001AFB94;
extern int D_L00_001AFB80 __attribute__((sda));
extern int D_L00_001AFB84;
extern char D_L00_001B8FF0[],D_L00_001B8DC0[],D_L00_001A8F20[];

void func_L00_003B77A8(char *object)
{
    union { Quad q; float f[4]; } vectors[2];
    char *state=*(char **)(object+0x68);
    int saved=func_001163B0();
    int i=0;
    func_001163A0(*(int *)(state+0x68));
    while(i<D_L00_001AFB78) {
        float speed,blend;
        int color;
        unsigned char random;
        vectors[1].q=0;
        vectors[1].f[0]=20.0f;
        i++;
        vectors[1].f[1]=func_002A78D8(0.0f,D_L00_001AFB88);
        vectors[1].f[2]=func_002A78D8(0.0f,D_L00_001AFB8C);
        vectors[0].q=vectors[1].q;
        func_00283098(&vectors[0],&vectors[0],D_L00_001B8FF0);
        func_00282CC0(&vectors[0],&vectors[0],D_L00_001B8DC0);
        speed=func_002A7878(D_L00_001AFB90,D_L00_001AFB94);
        blend=func_002A7878(0.0f,1.0f);
        color=func_00283D38(D_L00_001AFB80,D_L00_001AFB84,blend);
        random=func_002A77E0(255);
        func_002C3150(&vectors[0],D_L00_001A8F20,color,2,random,0,speed);
    }
    func_001163A0(saved);
}
