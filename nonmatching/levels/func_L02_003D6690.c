/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-hazard-labels.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   864/864 bytes; first difference +0x264. The last accumulated float addition moves into the count-limit branch delay slot, changing count registers and nearby scheduling. Explicit next-count computation recovered the retail size; -g was neutral. Hazard-label placement fixes the earlier +0x110 branch target. Reopen with a measured scheduling remedy for the final sum and copy.
   No linked build was run for this draft.
*/

typedef int Vector __attribute__((mode(TI)));
extern int D_L02_001B0344 __attribute__((sda));
extern float D_L02_001B0338 __attribute__((sda));
extern float D_L02_001B033C __attribute__((sda));
extern float D_L02_001B0340 __attribute__((sda));
extern float D_L02_001B0350 __attribute__((sda));
extern float D_L02_001B0354;
extern float D_L02_001B0358;
extern float D_L02_001B0360 __attribute__((sda));
extern float D_L02_001B0364;
extern float D_L02_001B0368;
extern Vector D_L02_00241290[];
extern Vector D_L02_002415B0[];
extern void *func_0029FCC0(char *, int, void *);
extern void func_0029FC20(char *, int, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282E48(void *, void *);
extern float func_002AA548(void *, void *, float, float, float, float);
extern float func_00282C48(float);

void func_L02_003D6690(char *self, int joint) {
    float origin[4];
    float endpoint[4];
    float matrix[16];
    float direction[4];
    float previous_end[4];
    float previous_origin[4];
    float error;
    if (D_L02_001B0344 >= 50)
        return;
    func_0029FCC0(self, joint, origin);
    func_0029FC20(self, joint, matrix);
    *(Vector *)direction = *(Vector *)matrix;
    error = 100.0f;
    func_00282F20(direction, direction, 5.3f);
    func_00282CC0(endpoint, origin, direction);
    if (D_L02_001B0344 > 0) {
        *(Vector *)previous_end = D_L02_00241290[D_L02_001B0344];
        *(Vector *)previous_origin = D_L02_002415B0[D_L02_001B0344];
        error = func_00282E48(previous_end, endpoint);
        error += func_00282E48(previous_origin, origin);
        if (error > 0.01f) {
            do {
                int next;
                error = func_00282C48(func_002AA548(previous_end, &D_L02_001B0350, endpoint[0],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                error += func_00282C48(func_002AA548(previous_end + 1, &D_L02_001B0354, endpoint[1],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                error += func_00282C48(func_002AA548(previous_end + 2, &D_L02_001B0358, endpoint[2],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                (D_L02_00241290 + 1)[D_L02_001B0344] = *(Vector *)previous_end;
                error += func_00282C48(func_002AA548(previous_origin, &D_L02_001B0360, origin[0],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                error += func_00282C48(func_002AA548(previous_origin + 1, &D_L02_001B0364, origin[1],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                error += func_00282C48(func_002AA548(previous_origin + 2, &D_L02_001B0368, origin[2],
                    D_L02_001B0338 * 0.00027777778f, D_L02_001B033C * 0.00027777778f, D_L02_001B0340 * 0.016666668f));
                (D_L02_002415B0 + 1)[D_L02_001B0344] = *(Vector *)previous_origin;
                next = D_L02_001B0344 + 1;
                if (D_L02_001B0344 >= 50)
                    return;
                D_L02_001B0344 = next;
            } while (error > 0.01f);
        }
    }
    if (error > 0.01f) {
        (D_L02_00241290 + 1)[D_L02_001B0344] = *(Vector *)endpoint;
        (D_L02_002415B0 + 1)[D_L02_001B0344] = *(Vector *)origin;
        D_L02_001B0344++;
    }
}
