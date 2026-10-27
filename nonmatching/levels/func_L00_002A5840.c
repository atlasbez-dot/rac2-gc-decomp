/* Nonmatching C: Update the object color and initialize or retire four resident effect records.
 * Tested profile: -O2 -G64 -Wa,-G64 -ffunction-sections.
 * Measured US size: 1096 bytes; retail: 1136 bytes.
 * Placement checks: US and US2: 0/27 each; PAL: absent from the catalogue.
 * Remaining: Resident-base and scalar lifetimes, floating-point scheduling and vector-loop spills differ.
 * Reopen with independent resident-field grouping and loop-spill evidence; retain all four entries of each vector and index table.
 */
#include "common.h"

typedef int Vector __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_001A7A43;
extern float D_L00_001A7CF8 __attribute__((sda));
extern int D_L00_001B19C8;
extern Vector D_L00_001A7E60[4] __attribute__((sda));
extern Vector D_L00_001A7EA0[4] __attribute__((sda));
extern Vector D_L00_001A7EE0[4] __attribute__((sda));
extern int D_L00_001A7F20[4] __attribute__((sda));
extern float D_L00_0025DEE0[22];
extern float func_002AA2E8(float *, float, float);
extern float func_00283CE0(int);
extern float func_00283198(float);
extern int func_00283CF0(float);
extern int func_00282978(short *);
extern int func_002A7820(int, int);
extern void func_0029F9F0(char *, char *);
extern void func_0029F978(unsigned char *, unsigned int, unsigned char *);
extern void func_00282D30(void *, void *, float);

void func_L00_002A5840(void) {
    unsigned char *hero;
    char *object;
    unsigned char *record;
    Vector *a;
    Vector *b;
    Vector *c;
    Vector *out_a;
    Vector *out_b;
    Vector *out_c;
    unsigned char *scan;
    int *indices;
    int period;
    int red;
    int green;
    int blue;
    int r_wave;
    int g_wave;
    int b_wave;
    int age;
    int count;
    int i;
    float normalized;
    float wave;
    float amplitude;
    float blend;
    if (D_001A7A43)
        func_002AA2E8(&D_L00_001A7CF8, 1.8f, 0.05f);
    else
        func_002AA2E8(&D_L00_001A7CF8, 1.0f, 0.05f);
    hero = D_00189E20;
    if ((unsigned int)(hero[0x22B4] - 1) < 2)
        object = *(char **)(hero + 0x2290);
    else {
        if (*(short *)(hero + 0x24FC)) return;
        object = *(char **)(hero + 0x1314);
    }
    if (object == 0) return;
    *(unsigned short *)(object + 0x34) |= 0x10;
    blue = *(int *)(hero + 0x24CC) == 1 ? 136 : 56;
    period = 110;
    normalized = func_00283CE0(period);
    normalized = (float)(D_L00_001B19C8 % period) / normalized;
    wave = func_00283198(normalized * 2.0f * 3.1415927f + -3.1415927f);
    amplitude = wave * 24.0f;
    b_wave = func_00283CF0(amplitude) + 12;
    blue += b_wave;
    green = func_00283CF0(wave * 48.0f);
    g_wave = green + 24;
    green += 160;
    r_wave = func_00283CF0(amplitude) + 12;
    red = r_wave + 64;
    age = *(short *)(hero + 0x20E);
    if (age != 0) {
        blend = 1.0f;
        if (age > 40)
            blend = func_00283CE0(45 - age) / func_00283CE0(5);
        age = *(short *)(hero + 0x20E);
        if (age < 20)
            blend = func_00283CE0(age) / func_00283CE0(20);
        blue -= func_00283CF0((float)b_wave * blend);
        green -= func_00283CF0((float)g_wave * blend);
        red -= func_00283CF0((float)r_wave * blend);
        blue += func_00283CF0(blend * 112.0f);
        green -= func_00283CF0(blend * 72.0f);
    }
    *(unsigned int *)(object + 0x78) = 0x80000000 | (red << 16) | (green << 8) | blue;
    if (hero[0x22B4] != 0 || *(int *)(hero + 0x2294) == 124) return;
    if (func_00282978((short *)(hero + 0x118C)) && (unsigned char)object[0x43] == 1) {
        *(short *)(hero + 0x118C) = func_002A7820(50, 200);
        *(short *)(hero + 0x118E) = 1;
    }
    if (*(short *)(hero + 0x118E) == 0) return;
    count = (short)(*(unsigned short *)(hero + 0x118E) + 1);
    *(short *)(hero + 0x118E) = count;
    if (count >= 22) *(short *)(hero + 0x118E) = 0;
    if (*(short *)(hero + 0x118E) == 0) {
        record = hero + 0x1080;
        for (i = 3; i >= 0; i--, record += 0x40)
            if (record[1]) func_0029F9F0(object, (char *)record);
        return;
    }
    record = hero + 0x1080;
    scan = hero;
    out_a = (Vector *)(hero + 0x1090);
    out_b = (Vector *)(hero + 0x10A0);
    out_c = (Vector *)(hero + 0x10B0);
    a = D_L00_001A7E60;
    b = D_L00_001A7EA0;
    c = D_L00_001A7EE0;
    indices = D_L00_001A7F20;
    for (i = 0; i < 4; i++, record += 0x40, scan += 0x40, out_a += 4, out_b += 4, out_c += 4, a++, b++, c++, indices++) {
        if (!scan[0x1081]) {
            func_0029F978((unsigned char *)object, *indices, record);
            scan[0x1083] = 1;
            qcopy(out_a, a);
            qcopy(out_b, b);
            qcopy(out_c, c);
            func_00282D30(out_c, out_c, *(float *)(object + 0x2C));
        }
    }
    record = D_00189E20 + 0x108C;
    for (i = 3; i >= 0; i--, record += 0x40)
        *(float *)record = D_L00_0025DEE0[*(short *)(D_00189E20 + 0x118E)];
}
