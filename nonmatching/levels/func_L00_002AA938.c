/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 680 / 676 bytes; size equality is not a match.
 * us: 0/24 placements; 680/676 bytes.
 * us2: 0/24 placements; 680/676 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: The retained 680/676-byte form reproduces the 0x90 frame and a held inherited-velocity view, but argument/local allocation and scheduling differ.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 24 places match; exit 1.
 * us2: 0 of 24 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * The retained 680/676-byte form reproduces the 0x90 frame and a held inherited-velocity view, but argument/local allocation and scheduling differ.
 * 5 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern unsigned char D_00189E20[];
extern float func_002A7878(float, float);
extern void func_0029FCC0(char *, int, char *);
extern void func_00282D30(void *, void *, float);
extern void func_L00_00335558(Vector *, void *, float);
extern unsigned char *func_002BF728(Vector *, Vector *, float, float);

/* Emit particles either around the player or alternately from selected joints. */
void func_L00_002AA938(int count, int sourceMode, int sparks) {
    Vector position;
    Vector velocity;
    unsigned char *player = D_00189E20;
    Vector *inheritedVelocity = (Vector *)(player + 0x110);
    int index;
    float size;
    for (index = 0; index < count; ++index) {
        if (sourceMode == 0) {
            position.f[0] = *(float *)(player + 0x80) + func_002A7878(-0.1f, 0.1f);
            position.f[1] = *(float *)(player + 0x84) + func_002A7878(-0.1f, 0.1f);
            position.f[2] = *(float *)(player + 0x88) + func_002A7878(-0.5f, 0.1f);
        } else if (sourceMode == 1) {
            func_0029FCC0(*(char **)(player + 0x2290), (index & 1) ? 14 : 0, (char *)&position);
        } else if (sourceMode == 2) {
            func_0029FCC0(*(char **)(player + 0x2290), (index & 1) ? 22 : 23, (char *)&position);
        }
        velocity = *inheritedVelocity;
        if (*(int *)(player + 0x2294) == 0x33) func_00282D30(&velocity, &velocity, 1.15f);
        else func_00282D30(&velocity, &velocity, 0.7f);
        velocity.f[0] += func_002A7878(-0.0066666672937572f, 0.0066666672937572f);
        velocity.f[1] += func_002A7878(-0.0066666672937572f, 0.0066666672937572f);
        velocity.f[2] += func_002A7878(-0.01666666753590107f, 0.0f);
        if (!sparks) {
            size = func_002A7878(4200.0f, 7350.0f);
            func_002BF728(&position, &velocity, size, -1.0f);
        } else {
            unsigned char *matrix = *(unsigned char **)(player + 0x2290) + 0xC0;
            size = func_002A7878(0.7f, 1.1f);
            func_L00_00335558(&position, matrix, *(float *)(player + 0x170) * size);
        }
    }
}
