/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G32 -ffunction-sections -Wa,-G32 -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 908 / 948 bytes; size equality is not a match.
 * us: 0/28 placements; 908/948 bytes.
 * us2: 0/28 placements; 908/948 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Allocation differences; truthful seven-float 28-byte settings object and complete pointer-return allocator API.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 00306680: 908 bytes versus retail 948; frame 0xE0.
 * Profile: -O2 -G32 -ffunction-sections -Wa,-G32 -frac2-qcopy -frac2-qcopy-barrier.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * The seven-float settings record is 28 bytes under a genuine G32 model. Particle scalar lifetimes and emission joins still differ.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned int u32;
typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
typedef struct {
    float horizontalLow, horizontalHigh, verticalLow, verticalHigh;
    float rotation, sizeLow, sizeHigh;
} ParticleBurstSettings;
extern ParticleVector ref_00306680_00 __attribute__((nosda));
extern ParticleBurstSettings ref_00306680_01 __attribute__((sda));
extern void func_00282CF0(void *, void *, void *);
extern void func_002FE8D8(void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_002A7878(float, float);
extern int func_002A77E0(int);
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern float func_002A78D8(float, float);
extern int func_001163B0(void);
extern void func_00282CC0(void *, void *, void *);
extern void *func_002C2210(void *, int, u32, int, int, void *, int, float, float, float);
extern int func_00283CF0(float);

/* Scatter paired impact particles in the plane around the supplied point. */
void func_00306680(void *origin, int count)
{
    ParticleVector side, axis, projection, velocity, position, pull;
    char *particle;
    float size, speed, shrink, angle, projectionLength;
    int random, spin, duration;
    func_00282CF0(&side,&ref_00306680_00,origin);
    func_002FE8D8(origin,&axis);
    projectionLength=func_00282DB0(&axis,&side);
    func_00282D30(&projection,&axis,projectionLength);
    func_00282CF0(&side,&side,&projection);
    if (count>0) do {
        size=func_002A7878(ref_00306680_01.sizeLow,ref_00306680_01.sizeHigh);
        random=func_002A77E0(2);
        spin=random-1;
        if (random) spin=random;
        angle=func_002A7878(-1.0471977f,1.0471977f);
        func_002ACEC0(&velocity,&side,&axis,angle);
        speed=func_002A7878(ref_00306680_01.horizontalLow,ref_00306680_01.horizontalHigh)*0.016666668f;
        func_00282F20(&velocity,&velocity,speed);
        velocity.f[2]=func_002A7878(ref_00306680_01.verticalLow,ref_00306680_01.verticalHigh)*0.016666668f;
        position.word=*(ParticleWord *)origin;
        position.f[0]+=func_002A78D8(0.0f,0.15f);
        position.f[1]+=func_002A78D8(0.0f,0.15f);
        position.f[2]+=func_002A78D8(0.0f,0.15f);
        if (!(func_001163B0()&1)) {
            func_00282D30(&velocity,&velocity,1.5f);
            particle=func_002C2210(&position,60,0x7f000080,0,spin,&velocity,1,
                                 size*0.35f,size,ref_00306680_01.rotation);
            if (particle) particle[9]=(char)func_00283CF0(4.0f)+0x70;
            shrink=0.245f; duration=60;
        } else {
            func_00282CF0(&pull,&ref_00306680_00,&position);
            func_00282F20(&pull,&pull,speed);
            func_00282CC0(&velocity,&velocity,&pull);
            particle=func_002C2210(&position,40,0x7f000080,0,spin,&velocity,1,
                                 size*2.05f,size,ref_00306680_01.rotation);
            if (particle) particle[9]=(char)func_00283CF0(4.0f)+0x70;
            shrink=1.4350001f; duration=40;
        }
        particle=func_002C2210(&position,duration,0x7f7f7f7f,1,-spin,&velocity,1,
                             size*shrink,size*0.7f,ref_00306680_01.rotation);
        --count;
        if (particle) particle[9]=(char)func_00283CF0(4.0f)+0x70;
    } while (count);
}
