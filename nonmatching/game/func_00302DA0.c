/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections (reported default game profile).
 * Reported final C / retail: 728 / 716 bytes; size equality is not a match.
 * us: 0/28 placements; 728/716 bytes.
 * us2: 0/27 placements; 728/716 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Branch/allocation differences; full scoped boot/level helper bindings and 19-argument BBBB8 call retained.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 00302DA0: 728 bytes versus retail 716; frame 0x50.
 * Profile: default -O2 -G0 -ffunction-sections.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * Program-specific references preserve real boot-stub versus level transition bindings. BBBB8 retains eight GPR inputs, seven FP inputs and all four stack tail words. Control-flow allocation remains different.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
typedef struct { float x,y,z,w; } V4_F213135aa;
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);

extern char D_00189E20[];
extern float ref_00302DA0_00[4];
extern float ref_00302DA0_01[4];
extern V4_F213135aa ref_00302DA0_02[];
extern float ref_00302DA0_03;
extern void ref_00302DA0_04(int, int, float);
extern int ref_00302DA0_05(int, int);
extern void ref_00302DA0_06(void);
extern int ref_00302DA0_07(void);
extern int func_00303E20(char *, void *, int *, int *);
extern void func_002A7750(u8 *, u8, s32);
extern float func_002AA140(float, float, float);
extern void func_002ABBB8(void *, void *, int, int, int, int, int, int,
    float, float, float, float, float, float, float, int, int, int, u32);
#define SURFACE_PLAYER_INT(offset) (*(int *)(D_00189E20+(offset)))
#define SURFACE_PLAYER_FLOAT(offset) (*(float *)(D_00189E20+(offset)))
#define SURFACE_PLAYER_POINTER(offset) (*(char **)(D_00189E20+(offset)))

/* Resolve the player onto the surface grid and blend their height into it. */
void func_00302DA0(char *object)
{
    char *state=*(char **)(object+0x68);
    float center, ceiling, blend;
    int index;
    if (*(int *)(state+0x98)==-1) {
        if (func_00303E20(object,D_00189E20+0x80,(int *)(state+0x90),(int *)(state+0x94))) {
            *(int *)(state+0x98)=0;
            func_002A7750((u8 *)object,5,-1);
        }
    }
    if (*(int *)(state+0x98)>=0) {
        center=*(float *)(state+0x70)+*(float *)(state+4);
        ceiling=center+*(float *)(state+0x34)+1.0f;
        if (ref_00302DA0_01[2]<=ceiling && center-*(float *)(state+0x34)-1.0f<=ref_00302DA0_01[2])
            ref_00302DA0_03=ceiling-ref_00302DA0_01[2];
        if (SURFACE_PLAYER_INT(0x2294)!=0x38 && SURFACE_PLAYER_INT(0x2294)!=0x79 &&
            (SURFACE_PLAYER_INT(0x2294)!=0x39 || *(int *)(*(char **)(SURFACE_PLAYER_POINTER(0x2290)+0x24)+0x1f0)) &&
            SURFACE_PLAYER_INT(0x2294)!=0x7a) {
            if (SURFACE_PLAYER_INT(0x2294)==0x31) {
                func_002ABBB8(SURFACE_PLAYER_POINTER(0x1830),ref_00302DA0_00,0,10,3,16,-1,1,
                    0.0f,0.0f,4.0f,2.0f,9.0f,1.0f,15.0f,1,-1,0,0x00810001);
                ref_00302DA0_04(0x88,0,0.0f);
                SURFACE_PLAYER_POINTER(0x1830)=0;
                ref_00302DA0_05(0,1);
                ref_00302DA0_06();
                SURFACE_PLAYER_FLOAT(0x318)=SURFACE_PLAYER_FLOAT(0x88);
            }
            if (!D_00189E20[0x22b4] && !*(int *)(*(char **)(SURFACE_PLAYER_POINTER(0x2290)+0x24)+0x1f0))
                ref_00302DA0_05(0x39,1);
            else ref_00302DA0_05(D_00189E20[0x22b4] ? 0x7a : 0x79,1);
        }
        if (SURFACE_PLAYER_INT(0x2294)==0x31 && *(int *)(state+0x98)>5)
            ref_00302DA0_07();
        blend=(float)*(int *)(state+0x98)*0.05f;
        if (blend>1.0f) blend=1.0f;
        index=*(int *)(state+0x40)*64+*(int *)(state+0x94)*8+*(int *)(state+0x90);
        SURFACE_PLAYER_FLOAT(0x88)=func_002AA140(SURFACE_PLAYER_FLOAT(0x88),
            ref_00302DA0_02[index].z-(float)*(int *)(state+0x98)*0.016666668f,blend);
        ++*(int *)(state+0x98);
    }
}
#undef SURFACE_PLAYER_INT
#undef SURFACE_PLAYER_FLOAT
#undef SURFACE_PLAYER_POINTER
