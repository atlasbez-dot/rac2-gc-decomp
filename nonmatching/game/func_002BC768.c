/* func_002BC768 (380 bytes, 28 places): spark spawn, func_002BDCE8's sibling.
   26 October 2026 (M32): 380/380 under the qcopy profile as its own unit; as in
   func_002BDCE8 only the size store (swc1 $f22,0xC) lands after the zero byte stores
   (retail before them); statement order, chained zeros, casts and the profile without
   the barrier do not move it. In the permuter. */

typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    unsigned char unk00;
    unsigned char unk01;
    unsigned char unk02;
    unsigned char unk03;
    int colour;
    unsigned char unk08;
    unsigned char unk09;
    short life;
    float size;
    float position[4];
    struct {
        int unk00;
        int unk04;
        int spin;
        float speed;
        float unk10;
        int colour;
    } motion;
} Particle_002BC768;

extern Particle_002BC768 *func_002B9030(int);
extern int func_00283CF0(float);
extern float func_002A78D8(float, float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern unsigned char *D_001F2574;

/* Spawns a spark near position (jittered on each axis) spinning either way. */
Particle_002BC768 *func_002BC768(TI128 *position, int spin, int colour, float jitter, float lo,
                                 float hi, float arg6, float size)
{
    Particle_002BC768 *p = func_002B9030(0xD);
    typeof(p->motion) *m;

    if (p != 0) {
        *(TI128 *)p->position = *position;
        p->colour = colour;
        m = &p->motion;
        p->unk09 = func_00283CF0(4.0f) + 0x40;
        p->unk03 = 0x48;
        p->unk01 = p->unk08 = 0;
        p->size = size;
        p->unk02 = *D_001F2574;
        p->position[0] += func_002A78D8(0.0f, jitter);
        p->position[1] += func_002A78D8(0.0f, jitter);
        p->position[2] += func_002A78D8(0.0f, jitter);
        p->life = 10;
        m->unk04 = 0;
        if (func_002A77E0(2))
            m->spin = spin;
        else
            m->spin = -spin;
        m->colour = colour & 0xFFFFFF;
        m->speed = func_002A7878(lo, hi);
        m->unk10 = arg6;
    }
    return p;
}
