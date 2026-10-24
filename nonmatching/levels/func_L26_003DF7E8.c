/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 784 bytes; retail: 784 bytes. Stack frame 0x100; retail 0x100.
 * Final coverage: US 0/1, US2 0/1, PAL 0/1. Absences are not matches.
 * 1 measured source/profile forms. Equal text size; first mismatch +0x4, especially fp versus
 * s7 ownership and pointer allocation. The packet is 144 bytes and its UV table is a complete
 * 32-byte array. Retail mixes GP and absolute UV accesses; no interior alias was introduced.
 * Reopen with a new truthful pointer-walk/address-expression hypothesis.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { Vector vertex[4]; unsigned int color[4]; float uv[4][2]; unsigned long long state[4]; } DrawPacket;
extern int D_L26_001B0664[5] __attribute__((sda));
extern int D_L26_001B0678 __attribute__((sda));
extern unsigned int D_L26_001B0680[2] __attribute__((sda));
extern float D_L26_001B0688[4][2] __attribute__((sda));
extern int D_L26_001B06A8 __attribute__((sda));
extern int D_L26_001B06AC[5];
extern Vector D_L26_0029ABD0[];
extern short D_L26_0029B3D0[][12];
extern unsigned long long func_0027C878(int);
extern int func_00283CF0(float);
extern float func_00283198(float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);
extern void func_00280B90(void *, void *, int);

void func_L26_003DF7E8(char *object) {
    DrawPacket packet;
    float *private = *(float **)(object + 0x68);
    unsigned int color;
    int face;
    int j;
    int index;
    packet.state[1] = func_0027C878(D_L26_001B0678);
    packet.state[3] = (unsigned long long)(long long)D_L26_001B0664[0] |
        ((unsigned long long)(long long)D_L26_001B0664[1] << 2) |
        ((unsigned long long)(long long)D_L26_001B0664[2] << 4) |
        ((unsigned long long)(long long)D_L26_001B0664[3] << 6) |
        ((unsigned long long)(long long)D_L26_001B0664[4] << 32);
    packet.state[2] = 0xFF9000000260ULL;
    packet.state[0] = (unsigned long long)(long long)D_L26_001B06A8 |
        ((unsigned long long)(long long)D_L26_001B06AC[0] << 2) |
        ((unsigned long long)(long long)D_L26_001B06AC[1] << 4) |
        ((unsigned long long)(long long)D_L26_001B06AC[2] << 14) |
        ((unsigned long long)(long long)D_L26_001B06AC[3] << 24) |
        ((unsigned long long)(long long)D_L26_001B06AC[4] << 34);
    for (face = 0; face < 64; face++) {
        for (j = 0; j < 4; j++) {
            packet.vertex[j].q = D_L26_0029ABD0[D_L26_0029B3D0[face][j * 3]].q;
            packet.uv[j][1] = D_L26_001B0688[j][1];
        }
        for (j = 0; j < 4; j++) {
            index = func_00283CF0(packet.uv[j][1] + 0.2f);
            packet.uv[j][0] = D_L26_001B0688[j][0] + private[2];
            color = D_L26_001B0680[index];
            packet.color[j] = func_00283D38(color & 0xFFFFFF, color, func_00283198(private[0] * 3.1415927f));
        }
        func_00280B90(&packet, 0, 0);
        for (j = 0; j < 4; j++) {
            index = func_00283CF0(packet.uv[j][1] + 0.2f);
            packet.uv[j][0] = D_L26_001B0688[j][0] + private[3];
            color = D_L26_001B0680[index];
            packet.color[j] = func_00283D38(color & 0xFFFFFF, color, func_00283198(private[1] * 3.1415927f));
        }
        func_00280B90(&packet, 0, 0);
    }
}
