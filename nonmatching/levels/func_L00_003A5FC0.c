/* Complete nonmatching reconstruction: 1360/1396 bytes.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Placement checks: US: 0/27; US2: 0/27; PAL absent from catalogue.
 * The two phases retain every particle/streak call and RNG call in retail order. All nine vectors are complete and16-byte aligned. Retail explicitly clears drift at+0xc4 before its conditional scale; the older draft omitted that clear. jitter W is not initialized by the inspected caller and is not invented here. func_002BCB00 returns pointer/null, consumes eight GPR inputs plus the ninth int32 zero on the stack, and takes f12; its result is ignored here. Particle-tail capture follows the measured+0x20 access.1360/1396 bytes and the retail0x140 frame remain different in scalar/vector lifetimes, constant placement and loop/call scheduling.
 * Reopen with qualified particle/streak workspace and scalar-lifetime evidence from actual allocator dumps. Preserve the observed drift clear, the ninth stack word, RNG order and the genuine caller pre-initialization constraint on jitter W.
 */
#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef float Vector[4] __attribute__((aligned(16)));
extern float D_0018A550[4], D_0018A560[4], D_00189F30[4];
extern int D_0018A160;
extern void func_002ACEC0(void *, void *, void *, float);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_002A7878(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7940(void);
extern float func_00283B98(float, float);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern char *func_002BDCE8(void *, int, void *, unsigned int, int, float, float, float, float);
extern void func_00282CF0(void *, void *, void *);
extern char *func_002C16C0(void *, void *, unsigned int, int, int, int, float, float, float, float, float);
extern float func_00282C48(float);
extern void func_002AB668(void *, int, float);
extern void func_002ACDE8(void *, void *, void *);
extern void func_002AF000(float *, float, float, float);
extern int func_002AAFA0(unsigned int, int);
extern int func_002A7820(int, int);
extern char *func_002BCB00(void *, void *, int, int, int, int, int, int, int, float);

/* Emit the smoke and streak layers of a beam contact burst. */
void func_L00_003A5FC0(void *owner, void *position)
{
    Vector rotation, direction, base, origin, velocity, jitter, drift, offset, scatter;
    float angle = 0.0f;
    int count;
    *(VectorBits *)base = 0;
    base[0] = 0.3f;
    base[1] = -1.0f;
    base[3] = 1.0f;
    qcopy(origin, position);
    func_002ACEC0(base, D_0018A550, D_0018A560, 0.3490659595f);
    qcopy(direction, base);
    qzero(drift);
    if (D_0018A160)
        func_00282D30(drift, D_00189F30, 1.7f);
    func_00282D30(offset, D_0018A550, 0.4f);
    func_00282CC0(origin, origin, offset);
    for (count = 19; count >= 0; count--) {
        char *particle;
        float size;
        int spin;
        angle = func_00283B98(angle, func_002A7878(0.0f, 0.6283186078f));
        func_00282D30(velocity, direction, func_002A7878(0.2000000179f, 0.2666666806f));
        func_00282CC0(velocity, velocity, drift);
        jitter[0] = origin[0] + func_002A78D8(0.0f, 0.3f);
        jitter[1] = origin[1] + func_002A78D8(0.0f, 0.3f);
        jitter[2] = origin[2] + func_002A78D8(0.0f, 0.3f);
        spin = func_00283CF0(func_002A78D8(1.0f, 2.0f));
        size = func_002A7878(0.2f, 0.75f) * 210000.0f;
        particle = func_002BDCE8(jitter, spin, D_00189F30, 0x7F202020, 0,
                                 0.0f, 1.0f, 1.00999999f, size);
        if (particle) {
            char *tail = particle + 0x20;
            *(short *)(particle + 10) = 60;
            *(unsigned char *)(particle + 3) = 0x44;
            *(unsigned char *)(particle + 9) = func_00283CF0(4.0f) + 0x40;
            *(float *)(tail + 0x1C) = func_00283CE0(5);
            *(int *)(tail + 4) = 3;
            *(unsigned char *)(tail + 0xA) = 0x30;
            *(unsigned char *)(tail + 0xB) = *(unsigned char *)(particle + 10);
        }
        jitter[0] = origin[0] + func_002A78D8(0.0f, 0.6f);
        jitter[1] = origin[1] + func_002A78D8(0.0f, 0.6f);
        jitter[2] = origin[2] + func_002A78D8(0.0f, 0.6f);
        size = func_002A7878(0.2f, 1.75f) * 210000.0f;
        func_00282CF0(jitter, jitter, velocity);
        func_002C16C0(jitter, velocity, 6, 0x7F, 0x404040, spin,
                      size, 500.0f, 0.95f, 0.0f, 0.0f);
        if (func_00282C48(angle) > 0.00001f) {
            func_002AB668(rotation, (int)D_0018A550, angle);
            func_002ACDE8(direction, base, rotation);
        }
    }
    func_00282D30(base, D_0018A550, func_002A7878(8.0f, 12.0f) * (1.0f / 60.0f));
    for (count = 1; count >= 0; count--) {
        float cone = func_002A7878(0.2617994249f, 1.39626348f);
        float heading = func_002A7940();
        float length = func_002A7878(7.0f, 10.5f);
        int firstColor, secondColor, life;
        func_002AF000(scatter, (1.0f / 60.0f) * 0.5f * length, heading, cone);
        func_00282CC0(scatter, scatter, base);
        scatter[2] += 0.05000000447f;
        firstColor = func_002AAFA0(0x4F007FFF, 0);
        secondColor = func_002AAFA0(0x1F00007F, 0);
        life = func_002A7820(60, 120);
        func_002BCB00(position, scatter, firstColor, secondColor, life, 1, -1, -1, 0, 20000.0f);
    }
}
