/* Retained C reconstruction; not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections -g -frac2-zero-ti-por.
 * Compiled 864 bytes; retail 880 bytes.
 * us: 0/1 placements match (exit 1).
 * us2: 0/1 placements match (exit 1).
 * pal: canonical name absent; no match credit.
 * Remaining: The rotation output is now a real three-quadword array (48 bytes): func_002833F0
 * writes offsets 0,0x10,0x20 and func_00283738 reads the same three rows. This restores retail
 * frame 0x190; the old 16-byte output was undersized. Eight shared copies preserve both matrix
 * snapshots. Scalar D_L23_001B39D8 has one measured dual access: GP store at +0x49E8, absolute
 * float load at +0x39D8. Its NOT_SDA spelling uses an assembler alias to that same canonical
 * scalar, not separate storage. D_L23_001B1484 has just its canonical absolute declaration.
 * Initial FP scheduling, register allocation, zero forms and division padding still differ.
 * Reopen: A camera-matrix allocation and division-padding witness using the full 48-byte
 * rotation output and the measured single-scalar dual access.
 */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));

typedef struct {
    float v[4][4];          /* 0x00 */
    s32 c[4];               /* 0x40 */
    float uv[4][2];         /* 0x50 */
    u64 w[4];               /* 0x70 */
} Quad;

typedef struct { s16 a; s16 b; } Pair;

extern u8 *D_L23_001B1484 NOT_SDA;
extern s32 D_L23_001B1480;
extern float D_L23_001B1470;
extern s32 D_L23_001B1474;
extern float D_L23_001B1478;
extern s32 D_L23_001B147C;
extern float D_L23_001B39D8 __attribute__((sda));
extern float D_L23_001B39D8_2 __asm__("D_L23_001B39D8") NOT_SDA;
extern s32 D_L23_001B1C68 __attribute__((sda));
extern s32 D_L23_001B1C6C __attribute__((sda));
extern s32 D_L23_001B1C70 __attribute__((sda));
extern s32 D_L23_001B1C74 __attribute__((sda));
extern s32 D_L23_001B1C7C __attribute__((sda));
extern s32 D_L23_001B1C80 __attribute__((sda));
extern float D_L23_001B1C84 __attribute__((sda));
extern float D_L23_002A7F50[][4];
extern float D_L23_002A8460[][2];
extern float D_L23_002A8464[][2];
extern Pair D_L23_002A81E0[][4];

extern float func_00283B98(float, float);
extern float func_00283198(float);
extern u64 func_0027C878(s32);
extern void func_002FC560(u16, u64);
extern void func_L22_002F3B38(void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002833F0(void *, void *);
extern void func_00283738(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00280B90(void *, void *, s32);

void func_L23_0042ADB0(u8 *obj) {
    Quad q;
    TI128 m[3];
    TI128 v3;
    TI128 v5;
    TI128 v4;
    TI128 x[3];
    TI128 *pv3 = &v3;
    TI128 *pv5 = &v5;
    TI128 *pv4 = &v4;
    u8 *state = D_L23_001B1484;
    u8 *payload;
    s32 n;
    s32 a2;
    s32 i;
    s32 j;

    if (state != 0) {
        payload = *(u8 **)(obj + 0x68);
        D_L23_001B39D8 = D_L23_001B1470 * 1.1f;
        *(float *)payload = func_00283B98(*(float *)payload, (float)D_L23_001B1480 * 0.00029088825f);
        n = D_L23_001B1474;
        a2 = (s32)(func_00283198((float)(s32)(*(u16 *)(obj + 0x96) % n) * (1.0f / (float)n) * 3.1415927f) * D_L23_001B1478) + D_L23_001B147C;
        *(s32 *)(payload + 4) = a2;
        q.w[3] = (u64)D_L23_001B1C68 | ((u64)D_L23_001B1C6C << 2) | ((u64)D_L23_001B1C70 << 4)
                 | ((u64)D_L23_001B1C74 << 6) | ((u64)a2 << 32);
        q.w[1] = func_0027C878(D_L23_001B1C7C);
        q.w[2] = 0xFF9000000260ULL;
        q.w[0] = 0;
        func_002FC560(0x47, 0x53001);
        qcopy(&m[0],(obj + 0xC0));
        qcopy(&m[1],(obj + 0xD0));
        qcopy(&m[2],(obj + 0xE0));
        qcopy(&m[0],(D_L23_001B1484 + 0xC0));
        qcopy(&m[1],(D_L23_001B1484 + 0xD0));
        qcopy(&m[2],(D_L23_001B1484 + 0xE0));
        qcopy(pv3,D_L23_001B1484 + 0x10);
        *pv4 = 0;
        ((float *)pv4)[3] = 1.0f;
        ((float *)pv4)[2] = D_L23_001B1C84;
        qcopy(pv5,pv4);
        func_L22_002F3B38(pv5, pv5);
        func_00282CC0(pv3, D_L23_001B1484 + 0x10, pv5);
        qzero(pv4);
        ((float *)pv4)[2] = *(float *)payload;
        func_002833F0(x, pv4);
        func_00283738(m, m, x);
        ((float *)pv3)[3] = 1.0f;
        q.c[0] = D_L23_001B1C80;
        q.c[1] = D_L23_001B1C80;
        q.c[2] = D_L23_001B1C80;
        q.c[3] = D_L23_001B1C80;
        for (i = 0; i < 40; i++) {
            for (j = 0; j < 4; j++) {
                func_00282D30(&q.v[j], D_L23_002A7F50[D_L23_002A81E0[i][j].a], D_L23_001B39D8_2);
                q.uv[j][0] = D_L23_002A8460[D_L23_002A81E0[i][j].b][0];
                q.uv[j][1] = D_L23_002A8464[D_L23_002A81E0[i][j].b][0];
            }
            func_00280B90(&q, m, 0);
        }
    }
}
