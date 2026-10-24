/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/1 placements; exit 1.
 * us2: 0/1 placements; exit 1.
 * pal: catalogue absent (no credit).
 * USA compiled 960 bytes; retail 960 bytes.
 * Equal length still differs at +0x8: object/state register allocation, GP versus absolute matrix/rate accesses and copy scheduling. A truthful 64-byte matrix G64/qcopy profile produced 928 bytes. Reopen only with a measured mixed-address storage model or independently supported allocator lifetimes.
 */

typedef unsigned int TodanoQuadword __attribute__((mode(TI)));
typedef struct { float rows[4][4]; } TodanoMatrix;
extern TodanoMatrix D_L12_001AEE40 __attribute__((sda));
extern unsigned char D_00189EA0[];
extern int D_L12_001B363C, D_L12_001B29C8;
extern float D_L12_001B3640[4] __attribute__((aligned(16)));
extern float D_L12_001AEF4C __attribute__((sda)), D_L12_001AEF50 __attribute__((sda));
extern void func_L12_00389988(void *);
extern void func_L00_002E6CF0(void (*)(void *), void *);
extern void func_L00_002E6EF8(void (*)(void *), void *);
extern float func_00283198(float);
extern float func_002A7878(float, float);
extern float func_00282E80(void *, void *);


void func_L12_00389BC0(unsigned char *object)
{
    float *state = *(float **)(object + 0x68);
    float a, b, c, d;
    int row, mode = object[0x20];
    float *vector;
    switch (mode) {
    case 0:
        state[1] = 0.25f;
        state[11] = 1.75f;
        state[2] = 0.5f;
        state[3] = 0.75f;
        state[8] = 1.0f;
        state[9] = 1.25f;
        state[10] = 1.5f;
        state[0] = 0.0f;
        object[0x30] = 255;
        object[0x20] = 1;
        if (D_L12_001AEE40.rows[0][0] > 1000.0f) {
            vector = D_L12_001AEE40.rows[0];
            row = 3;
            do {
                float x = vector[0] * 0.01f;
                float y = vector[1] * 0.01f;
                float z = vector[2] * 0.01f;
                vector[0] = x;
                vector[1] = y;
                vector[2] = z;
                vector += 4;
            } while (--row >= 0);
        }
        break;
    case 1:
        func_L00_002E6CF0(func_L12_00389988, object);
        D_L12_001B363C = mode;
        *(TodanoQuadword *)D_L12_001B3640 = *(TodanoQuadword *)D_00189EA0;
        *(short *)(D_00189EA0 + 0x17E) = 5;
        D_L12_001B3640[3] = 48.0f;
        D_L12_001B3640[2] = func_00283198((float)(D_L12_001B29C8 % 360) * 0.01744444482028484344482421875f - 3.14f) * 0.25f + 59.5f;
        state[4] += state[5];
        if (state[4] >= 8.0f) state[4] -= 8.0f;
        a = func_00283198(state[0] * 3.141590118408203125f) * 0.01f;
        b = func_00283198(state[1] * 3.141590118408203125f) * 0.025f;
        c = func_00283198(state[2] * 3.141590118408203125f) * 0.01f;
        d = func_00283198(state[3] * 3.141590118408203125f) * 0.025f;
        D_L12_001AEE40.rows[0][2] += a;
        D_L12_001AEE40.rows[1][2] += b;
        D_L12_001AEE40.rows[2][2] += c;
        D_L12_001AEE40.rows[3][2] += d;
        state[0] += 0.01f;
        state[1] += 0.01f;
        state[2] += 0.01f;
        state[3] += 0.01f;
        if (state[0] > 2.0f) state[0] = 0.0f;
        if (state[1] > 2.0f) state[1] = 0.0f;
        if (state[2] > 2.0f) state[2] = 0.0f;
        if (state[3] > 2.0f) state[3] = 0.0f;
        state[5] = func_002A7878(D_L12_001AEF4C, D_L12_001AEF50);
        break;
    case 2:
        if (func_00282E80(object + 0x10, D_00189EA0) < 64.0f)
            func_L00_002E6EF8(func_L12_00389988, object);
        break;
    }
}
