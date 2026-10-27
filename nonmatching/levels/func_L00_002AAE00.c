/* M7, 26 October 2026 (-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier):
 * nine opcode hunks left (was twelve). Direct D_00189E20 + offset addressing gives retail's
 * timer-relative base (s1 = D+0x51E, the rest as offsets from it) and a hoisted colour local
 * gives retail's loop-invariant `ori s4`. Left: retail derives the player base as s1-0x51E
 * in the first block, keeps the loop's biv decrement after the position qcopy (ours fills the
 * first jal slot with it), a pre-loop nop and the re-materialised base for the final 0x51C store.
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
    unsigned int color;
    int alpha, index, firstLife, secondLife;
    float angle, speed, fade, firstAngle, secondAngle;
    if (func_00282978((short *)(D_00189E20 + 0x51E))) {
        position.q = *(Quadword *)(D_00189E20 + 0x80);
        angle = func_00283B98(*(float *)(D_00189E20 + 0x98), 1.5707964897155762f);
        speed = func_002A78D8(0.0033333336468786f, 0.011666666716337204f);
        velocity.f[0] = func_00283180(angle) * speed;
        velocity.f[1] = func_00283198(angle) * speed;
        velocity.f[3] = -0.002222222276031971f;
        velocity.f[2] = 0.0f;
        func_002BE278(&position, &velocity, 0, -1.0f);
        *(short *)(D_00189E20 + 0x51E) = func_002A7820(2, 3);
    }
    if (func_00282978((short *)(D_00189E20 + 0x51C))) {
        fade = (float)(40 - *(int *)(D_00189E20 + 0x1B8)) * 0.025f;
        if (fade > 1.0f) fade = 1.0f;
        if (fade < 0.0f) fade = 0.0f;
        alpha = func_00283CF0(fade * 240.0f);
        if (alpha > 160) alpha = 160;
        if (alpha < 32) alpha = 32;
        color = ((unsigned int)alpha << 24) | 0xC0F0U;
        for (index = 56; index >= 0; --index) {
            firstLife = func_00283CF0(func_002A7878(4200.0f, 7350.0f) * 0.001f);
            secondLife = func_00283CF0(func_002A7878(21000.0f, 31500.001953125f) * 0.001f);
            speed = func_002A7878(0.002500000176951289f, 0.00950000062584877f);
            position.q = *(Quadword *)(D_00189E20 + 0x80);
            firstAngle = func_002A7940();
            secondAngle = func_002A7940();
            func_002AF000(velocity.f, speed, firstAngle, secondAngle);
            func_002BAE50(&position, &velocity, color, 0x70F0, 40, firstLife, secondLife, 1);
        }
        *(short *)(D_00189E20 + 0x51C) = func_002A7820(3, 7);
    }
}
