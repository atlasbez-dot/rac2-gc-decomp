/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 956 / 984 bytes; size equality is not a match.
 * us: 0/27 placements; 956/984 bytes.
 * us2: 0/27 placements; 956/984 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: The 0x50 frame versus retail 0x60 and held base/joint-buffer allocation differ; canonical helper parameters and both random interval endpoints are retained.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * The 0x50 frame versus retail 0x60 and held base/joint-buffer allocation differ; canonical helper parameters and both random interval endpoints are retained.
 * 1 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_L00_0025BE10[];
extern int func_L00_002ADF80(void);
extern float func_00282C48(float);
extern float func_00283248(float, float);
extern float func_00283BE0(float, float);
extern void func_L00_002D3248(short, unsigned char, unsigned char, unsigned char, float, float);
extern void func_0029FCC0(char *, int, char *);
extern float func_002A7878(float, float);
extern void func_L00_00335558(void *, void *, float);
#define REAL(o) (*(float *)(player + (o)))
#define WORD(o) (*(int *)(player + (o)))
#define SHORT(o) (*(short *)(player + (o)))
#define HALF(o) (*(unsigned short *)(player + (o)))
#define ROW(o) (*(float *)(D_L00_0025BE10 + (o)))

/* Drive articulated offsets and emit the active pair of joint effects. */
void func_L00_002AC1A0(void) {
    Quadword position;
    unsigned char *player = D_00189E20;
    unsigned char *matrix;
    float left, right, draw;
    int index;
    if (WORD(0x1270)) { ROW(0x41C) = 0.01f; ROW(0x36C) = 0.01f; }
    if (func_L00_002ADF80()) return;
    if ((func_00282C48(REAL(0x300)) > 0.015f || func_00282C48(REAL(0x304)) > 0.015f ||
         func_00282C48(REAL(0x308)) > 0.01745329424738884f || func_00282C48(REAL(0x30C)) > 0.01745329424738884f ||
         func_00282C48(REAL(0x310)) > 0.01745329424738884f || func_00282C48(REAL(0x314)) > 0.01745329424738884f) && SHORT(0x348) != 1) {
        ROW(0x324) = -REAL(0x308);
        ROW(0x3D4) = -REAL(0x30C);
        left = func_00283248(0.2f, REAL(0x300)) * 1.2f;
        right = -func_00283248(0.2f, REAL(0x304)) * 1.2f;
        if (left > 0.785398244857788f) left = 0.785398244857788f;
        if (left < -0.174532949924469f) left = -0.174532949924469f;
        if (right > 0.174532949924469f) right = 0.174532949924469f;
        if (right < -0.785398244857788f) right = -0.785398244857788f;
        ROW(0x480) = left;
        ROW(0x530) = right;
        ROW(0x320) = -func_00283BE0(REAL(0x310), -left);
        ROW(0x3D0) = -func_00283BE0(REAL(0x314), -right);
    }
    if (HALF(0x143E) & 0x80) { WORD(0x1438) = 0; return; }
    if (WORD(0x2294) == 3) func_L00_002D3248(1, 2, 1, 0, 0.021f, 0.002f);
    if (WORD(0x229C) == 4 && player[0x49C] && player[0x49C] < 12)
        func_L00_002D3248(1, 2, 0, 1, 0.016f, 0.002f);
    if (WORD(0x1438) > 0 && SHORT(0x143C)) {
        matrix = 0;
        if (HALF(0x143E) & 1) matrix = *(unsigned char **)(player + 0x2290) + 0xC0;
        --WORD(0x1438);
        func_0029FCC0(*(char **)(player + 0x2290), 22, (char *)&position);
        for (index = 0; index < SHORT(0x143C); ++index) {
            draw = func_002A7878(-REAL(0x1434), REAL(0x1434));
            func_L00_00335558(&position, matrix, REAL(0x1430) + draw);
        }
        func_0029FCC0(*(char **)(player + 0x2290), 23, (char *)&position);
        for (index = 0; index < SHORT(0x143C); ++index) {
            draw = func_002A7878(-REAL(0x1434), REAL(0x1434));
            func_L00_00335558(&position, matrix, REAL(0x1430) + draw);
        }
    }
}
