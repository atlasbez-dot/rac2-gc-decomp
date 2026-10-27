/* Nonmatching C: Create and update the resident effect object, transfer its joint data and blend its colors.
 * Tested profile: -O2 -G0 -ffunction-sections.
 * Measured US size: 812 bytes; retail: 852 bytes.
 * Placement checks: US and US2: 0/19 each; PAL: absent from the catalogue.
 * Remaining: Resident-base and vector-address lifetimes, dispatch scheduling and register allocation differ.
 * Reopen with independent resident-field and color lifetime evidence; preserve the complete joint vector, 64-byte matrix and pointer-returning allocator.
 */
#include "common.h"

typedef int Vector __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_001A7A43;
extern char *func_0029EFD0(int);
extern void func_002A0F48(char *);
extern void func_0029FCC0(char *, int, char *);
extern void func_L00_002A7A10(void);
extern void func_0029FC20(char *, int, char *);
extern void func_00283678(void *, void *);
extern float func_002AA2E8(float *, float, float);
extern float func_00283B98(float, float);
extern int func_00282978(short *);
extern int func_002E5CF8(int, int, char *);
extern float func_00283198(float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);

void func_L00_002A5CB0(void) {
    float joint[4] __attribute__((aligned(16)));
    float matrix[16] __attribute__((aligned(16)));
    unsigned char *hero = D_00189E20;
    char *object;
    float scale;
    unsigned int first;
    unsigned int second;
    unsigned int color;
    if (*(char **)(hero + 0x1864) == 0) {
        object = func_0029EFD0(0x4B4);
        *(char **)(hero + 0x1864) = object;
        if (object) {
            *(unsigned int *)(object + 0x78) = 0x801432D7;
            *(unsigned int *)(hero + 0x2524) = 0x301432D7;
            object = *(char **)(hero + 0x1864);
            qcopy(object + 0x10, hero + 0x80);
            qcopy(object + 0xF0, hero + 0x90);
            *(short *)(object + 0x32) = 0x40;
            (*(char **)(hero + 0x1864))[0x31] = 1;
            (*(char **)(hero + 0x1864))[0x30] = 0;
            *(short *)(*(char **)(hero + 0x1864) + 0x34) = 0;
            *(float *)(*(char **)(hero + 0x1864) + 0x2C) *= 1.7f;
            *(unsigned short *)(*(char **)(hero + 0x1864) + 0x34) |= 0x10;
            func_002A0F48(*(char **)(hero + 0x1864));
        }
    }
    if (!(*(unsigned short *)(*(char **)(hero + 0x2290) + 0x34) & 1)) {
        func_0029FCC0(*(char **)(hero + 0x2290), 7, (char *)joint);
        qcopy(hero + 0x2010, joint);
        func_L00_002A7A10();
        if (*(char **)(hero + 0x1864)) {
            func_0029FC20(*(char **)(hero + 0x2290), 7, (char *)matrix);
            object = *(char **)(hero + 0x1864);
            qcopy(object + 0x10, matrix + 12);
            func_00283678(object + 0xC0, matrix);
            func_002A0F48(*(char **)(hero + 0x1864));
            scale = D_001A7A43 ? 3.1f : 1.7f;
            if (*(short *)(hero + 0x2520)) scale *= 1.4f;
            object = *(char **)(hero + 0x1864);
            func_002AA2E8((float *)(object + 0x2C), *(float *)(*(char **)(object + 0x24) + 0x24) * scale, 0.02f);
        }
    }
    *(float *)(hero + 0x1868) = func_00283B98(*(float *)(hero + 0x1868), 0.049451005f);
    first = 0x281414C8;
    second = 0x1E00004B;
    if (!func_00282978((short *)(hero + 0x2520))) {
        *(float *)(hero + 0x1868) = func_00283B98(*(float *)(hero + 0x1868), 0.20362177f);
        switch (*(short *)(hero + 0x2522)) {
        case 1: first = 0x2814C814; second = 0x1E004B00; break;
        case 2: first = 0x2814C8C8; second = 0x1E004B4B; break;
        case 3: first = 0x323232FA; second = 0x1E000078; break;
        case 4: first = 0x28F01414; second = 0x1E4B0000; break;
        }
        if (*(short *)(hero + 0x2520) >= 50 && (*(unsigned short *)(hero + 0x2520) & 1))
            func_002E5CF8(*(short *)(hero + 0x2522) + 16, 0, *(char **)(hero + 0x2290));
    }
    color = func_00283D38(first, second, func_00283198(*(float *)(hero + 0x1868)) * 0.5f + 0.5f);
    object = *(char **)(hero + 0x1864);
    if (object)
        *(unsigned int *)(object + 0x78) = func_00283D38(*(unsigned int *)(object + 0x78), color, 0.1f);
    *(unsigned int *)(hero + 0x2524) = func_00283D38(*(unsigned int *)(hero + 0x2524), color, 0.1f);
}
