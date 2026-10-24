/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 664 / 680 bytes; size equality is not a match.
 * us: 0/22 placements; 664/680 bytes.
 * us2: 0/22 placements; 664/680 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Qualified materialized copy pairs improve the 652-byte form to 664/680, but loop allocation and scheduling still differ.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 22 places match; exit 1.
 * us2: 0 of 22 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * Qualified materialized copy pairs improve the 652-byte form to 664/680, but loop allocation and scheduling still differ.
 * 2 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern unsigned char D_00189E20[];
extern int func_00282978(short *);
extern float func_00283B98(float, float);
extern float func_002A78D8(float, float);
extern float func_002A7878(float, float);
extern float func_002A7940(void);
extern float func_00283180(float);
extern float func_00283198(float);
extern int func_00283CF0(float);
extern int func_002A7820(int, int);
extern void func_002BE278(Vector *, Vector *, int, float);
extern void func_002AF000(float *, float, float, float);
extern unsigned char *func_002BAE50(Vector *, Vector *, unsigned int, unsigned int, int, int, int, int);

/* Update two timers that emit falling motes and a burst of colored particles. */
void func_L00_002AAE00(void) {
    Vector position, velocity;
    unsigned char *player = D_00189E20;
    int alpha, index, firstLife, secondLife;
    float angle, speed, fade, firstAngle, secondAngle;
    if (func_00282978((short *)(player + 0x51E))) {
        position.q = *(Quadword *)(player + 0x80);
        angle = func_00283B98(*(float *)(player + 0x98), 1.5707964897155762f);
        speed = func_002A78D8(0.0033333336468786f, 0.011666666716337204f);
        velocity.f[0] = func_00283180(angle) * speed;
        velocity.f[1] = func_00283198(angle) * speed;
        velocity.f[3] = -0.002222222276031971f;
        velocity.f[2] = 0.0f;
        func_002BE278(&position, &velocity, 0, -1.0f);
        *(short *)(player + 0x51E) = func_002A7820(2, 3);
    }
    if (func_00282978((short *)(player + 0x51C))) {
        fade = (float)(40 - *(int *)(player + 0x1B8)) * 0.025f;
        if (fade > 1.0f) fade = 1.0f;
        if (fade < 0.0f) fade = 0.0f;
        alpha = func_00283CF0(fade * 240.0f);
        if (alpha > 160) alpha = 160;
        if (alpha < 32) alpha = 32;
        for (index = 56; index >= 0; --index) {
            firstLife = func_00283CF0(func_002A7878(4200.0f, 7350.0f) * 0.001f);
            secondLife = func_00283CF0(func_002A7878(21000.0f, 31500.001953125f) * 0.001f);
            speed = func_002A7878(0.002500000176951289f, 0.00950000062584877f);
            position.q = *(Quadword *)(player + 0x80);
            firstAngle = func_002A7940();
            secondAngle = func_002A7940();
            func_002AF000(velocity.f, speed, firstAngle, secondAngle);
            func_002BAE50(&position, &velocity, ((unsigned int)alpha << 24) | 0xC0F0U, 0x70F0, 40, firstLife, secondLife, 1);
        }
        *(short *)(player + 0x51C) = func_002A7820(3, 7);
    }
}
