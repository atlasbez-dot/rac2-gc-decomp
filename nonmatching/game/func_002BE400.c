/* Retained manual reconstruction, 2026-10-24.
 * Profile: -O2 -G0 -ffunction-sections.
 * Final measurements: us: 0/28 placements, exit1, 1036 compiled bytes; us2:
 * 0/28 placements, exit1, 1036 compiled bytes; pal: catalogue absent
 * (exit1).
 * Remaining: Complete collision, motion, signed colour decay, deletion and
 * timer updates are retained. The 0x70 frame agrees; saved-register
 * assignment, branch arrangement and copy scheduling differ. Default,
 * qcopy/barrier, initialization-lifetime and no-gcse trials remained 1036
 * bytes. PAL catalogue absence is not a successful check.
 * Reopen with: Concrete particle/velocity field and live-range evidence
 * that resolves the object/position saved-register allocation; stop tied
 * source/profile permutations.
 * No byte-match or linked-build credit is claimed.
 */
/* Update a moving particle, preserving its signed colour-decay convention. */
typedef struct { float x, y, z, w; } Vec4_BE400;
extern void func_00300190(void *, void *);
extern void func_00282CC0(Vec4_BE400 *, Vec4_BE400 *, Vec4_BE400 *);
extern int func_002761F8(Vec4_BE400 *, Vec4_BE400 *, int, int, int);
extern void func_00282C88(Vec4_BE400 *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(Vec4_BE400 *, Vec4_BE400 *, float);
extern int func_00282978(short *);
extern void func_002B9180(void *);
extern int func_002AAE98(float, float, float, float);
extern int D_0018C0B0;
extern Vec4_BE400 D_001BAFA0;
extern int D_001A8CA0;

void func_002BE400(unsigned char *particle)
{
    Vec4_BE400 next, correction;
    Vec4_BE400 *velocity, *position;
    float r, g, b;
    int negative;
    if (!particle) return;
    velocity = (Vec4_BE400 *)(particle + 0x20);
    r = *(float *)(particle + 0x30);
    g = *(float *)(particle + 0x34);
    b = *(float *)(particle + 0x38);
    negative = 0;
    if (r < 0.0f || g < 0.0f || b < 0.0f) {
        r = -r;
        g = -g;
        b = -b;
        negative = 1;
    }
    position = (Vec4_BE400 *)(particle + 0x10);
    func_00300190(position, position);
    *(float *)(particle + 0xC) += -100.0f;
    func_00282CC0(&next, position, velocity);
    if (velocity->x != 0.0f || velocity->y != 0.0f || velocity->z != 0.0f) {
        if (func_002761F8(position, &next, 2, D_0018C0B0, 0)) {
            *position = D_001BAFA0;
            func_00282C88(velocity);
            *(float *)(particle + 0xC) += *(float *)(particle + 0xC);
        } else {
            *position = next;
            if (D_001A8CA0) {
                float scale;
                func_002AFFD8((char *)position, (char *)&correction, 0);
                scale = velocity->w;
                if (scale != 0.0f) scale = -scale;
                else scale = 0.0063f;
                func_00282D30(&correction, &correction, scale);
                func_00282CC0(velocity, velocity, &correction);
            } else {
                velocity->z += velocity->w != 0.0f ? velocity->w : -0.0063f;
            }
        }
    }
    if (*(float *)(particle + 0x3C) <= 0.0f ||
        func_00282978((short *)(particle + 0xA)) ||
        *(float *)(particle + 0xC) < 0.0f ||
        next.x < 0.01f || next.y < 0.01f || next.z < 0.01f) {
        func_002B9180(particle);
        return;
    }
    if (!negative) {
        r += -0.01f;
        if (r < 0.0f) r = 0.0f;
        g += -0.03001f;
        if (g < 0.0f) g = 0.0f;
    } else {
        g += -0.01f;
        if (g < 0.0f) g = 0.0f;
        r += -0.03001f;
        if (r < 0.0f) r = 0.0f;
    }
    b += -0.05f;
    if (b < 0.0f) b = 0.0f;
    if (*(float *)(particle + 0x3C) < 0.0f) *(float *)(particle + 0x3C) = 0.0f;
    *(int *)(particle + 4) = func_002AAE98(r, g, b, *(float *)(particle + 0x3C));
    if (negative > 0) {
        *(float *)(particle + 0x30) = -r;
        *(float *)(particle + 0x34) = -g;
        *(float *)(particle + 0x38) = -b;
    } else {
        *(float *)(particle + 0x38) = b;
        *(float *)(particle + 0x30) = r;
        *(float *)(particle + 0x34) = g;
    }
    --particle[8];
}
