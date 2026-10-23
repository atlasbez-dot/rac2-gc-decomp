/* Retained C reconstruction, 2026-10-23. Not linked or counted.
   Profile: -O2 -G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier
   USA: 384/384 bytes, 0/27 placements; first difference 0x40.
   us: 0/27, pal: absent, us2: 0/27.
   Revisit small-data table bases and the paired-state pointer allocation.
*/
typedef int Quad __attribute__((mode(TI)));
typedef struct { char *objects[2]; char pad08[8]; Quad positions[2]; Quad velocity[2]; char pad50[0x18]; int seed; } PairState;
extern Quad D_L00_001AFA70[2] __attribute__((sda));
extern Quad D_L00_001AFA50[2] __attribute__((sda));
extern float D_L00_001AFAA0[2] __attribute__((sda));
extern float D_L00_001AFA90[2] __attribute__((sda));
extern int D_L00_001AFA98[2] __attribute__((sda));
extern int func_002A77E0(int);
extern char *func_0029EFD0(int);
extern void func_002B37E8(char *,int);
extern void func_002AEC18(char *,int);

int func_L00_003B6858(char *object)
{
    int i=0;
    Quad *source=D_L00_001AFA70,*position=D_L00_001AFA50;
    float *rate=D_L00_001AFAA0,*scale=D_L00_001AFA90;
    int *material=D_L00_001AFA98;
    PairState *state=*(PairState **)(object+0x68);
    char **slot=state->objects;
    Quad *out=state->positions,*velocity=state->velocity;
    state->seed=func_002A77E0(255);
    do {
        *slot=func_0029EFD0(i?0xe7d:0xeb0);
        func_002B37E8(*slot,0);
        *(unsigned short *)(*slot+0x34)|=0x4100;
        (*slot)[0xbc]=i;
        *(Quad *)(*slot+0xf0)=*source;
        *out=*position;
        *velocity=0;
        ((float *)velocity)[1]=*rate*(1.0f/60.0f);
        *(float *)(*slot+0x2c)=*(float *)(*(char **)(*slot+0x24)+0x24)* *scale;
        func_002AEC18(*slot,*material);
        slot++;out++;velocity++;source++;position++;rate++;scale++;material++;i++;
    }while(i<2);
    if(!state->objects[0]) return 0;
    if(!state->objects[1]) return 0;
    return 1;
}
