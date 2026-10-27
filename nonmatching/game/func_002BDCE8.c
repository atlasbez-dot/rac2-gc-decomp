/* func_002BDCE8 (452 bytes, 28 places): spinning spark spawn, 002C3150 family.
   26 October 2026 (M32): 452/452 under the qcopy profile as its own unit; only the size
   store (swc1 $f22,0xC) is scheduled after the two zero byte stores where retail puts it
   before them; no statement order reproduces it. In the permuter. */

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
        int colour;
        int unk04;
        short spin;
        short pad0A;
        float speed;
        float axis[4];
    } motion;
} Particle_002BDCE8;

extern Particle_002BDCE8 *func_002B9030(int);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern float func_002A78D8(float, float);
extern int func_002A77E0(int);
extern float func_002A7878(float, float);
extern unsigned char *D_001F259C;

/* Spawns a spinning spark near position (jittered by up to jitter on each axis)
   turning about axis at a random speed between lo and hi, in either direction. */
Particle_002BDCE8 *func_002BDCE8(TI128 *position, int spin, TI128 *axis, int colour, int count,
                                 float jitter, float lo, float hi, float size)
{
    Particle_002BDCE8 *p = func_002B9030(0x17);
    typeof(p->motion) *m;

    if (p != 0) {
        *(TI128 *)p->position = *position;
        p->colour = colour | 0x20000000;
        m = &p->motion;
        p->unk09 = func_00283CF0(4.0f) + 0x70;
        p->unk03 = 0x48;
        p->size = size;
        p->unk08 = 0;
        p->unk01 = 0;
        p->unk02 = *D_001F259C;
        p->position[0] += func_002A78D8(0.0f, jitter);
        p->position[1] += func_002A78D8(0.0f, jitter);
        p->position[2] += func_002A78D8(0.0f, jitter);
        p->position[3] = func_00283CE0(count);
        p->life = 10;
        m->unk04 = 0;
        p->motion.colour = colour;
        m->spin = func_00283CF0(func_002A77E0(2) ? (float)spin : (float)-spin);
        m->speed = func_002A7878(lo, hi);
        *(TI128 *)m->axis = *axis;
        m->axis[3] = func_00283CE0(0x1E);
    }
    return p;
}
