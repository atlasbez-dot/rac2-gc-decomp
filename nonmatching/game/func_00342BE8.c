/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections. 900/900 bytes, frame 0xB0 as retail; us 0/28.
 * 26 October 2026 (M10): -G8 with D_001A7340/D_001A7344 and the clip rectangle as plain
 * declarations (retail:  in delay slots, lui/lw elsewhere) gives the right size and frame
 * (the &alternate pseudo spills to 0x30). 90 differing lines remain: retail keeps object+0x28 as
 * a loop-invariant base in  (ours folds 0x28 into the load), the colour word read order,
 * and the clip copy addressing ( la, unshared lui/lw field reads). Pointer locals, struct
 * views and do/while forms did not hoist the base.
 */
#include "common.h"
typedef struct { float x, y; } VEC_F6bf9ce42;
typedef struct { unsigned int values[4]; } MenuColourQuad;
typedef struct { int x0, x1, y0, y1; } MenuClipRectangle;
extern void func_00343068(VEC_F6bf9ce42 **);
extern int func_003427C0(char *, int, float, float, float, float);
extern unsigned char D_00139568[], D_00239BA0[];
extern MenuColourQuad D_001AE1D8, D_001AE1E8;
extern float D_001AE1D0 __attribute__((sda));
extern int D_001AE1D4 __attribute__((sda));
extern int D_001B23C0 __attribute__((sda));
extern MenuClipRectangle D_001B23B0;
extern int D_001A7340, D_001A7344;
extern void func_002FC620(int, int, int, int);
extern int func_0028E588(int, int);
extern void func_0028EA58(int, int, int, int, int, unsigned int *);


void func_00342BE8(char *object)
{
    float high, low, current;
    int index, first, second, texture;
    MenuColourQuad normal, alternate, *colours;
    MenuClipRectangle clip;
    unsigned char *entry;
    func_00343068((VEC_F6bf9ce42 **)object);
    low = (*(VEC_F6bf9ce42 **)object)->y + *(float *)(object + 0xC) * -4.0f;
    high = (*(VEC_F6bf9ce42 **)object)->y + *(float *)(object + 4) * 0.5f;
    for (index = *(int *)(object + 0x20);
            index <= *(int *)(object + 0x24) && *(int *)(object + 0x10); index++) {
        normal = D_001AE1D8;
        alternate = D_001AE1E8;
        entry = D_00239BA0 + D_00139568[((int *)(object + 0x28))[*(int *)(object + 0x14) + index]] * 224;
        colours = &normal;
        if (*(int *)entry && entry[4]) colours = &alternate;
        current = (float)index;
        first = func_003427C0(object, D_001AE1D4, low,
                (*(VEC_F6bf9ce42 **)object)->y + *(float *)(object + 0xC) * current + (float)*(int *)(object + 0x90),
                high, D_001AE1D0);
        second = func_003427C0(object, D_001AE1D4, low,
                (*(VEC_F6bf9ce42 **)object)->y + *(float *)(object + 0xC) * current + *(float *)(object + 4) + (float)*(int *)(object + 0x90),
                high, D_001AE1D0);
        colours->values[0] = (colours->values[0] & 0xFFFFFF) | (first << 24);
        colours->values[1] = (colours->values[1] & 0xFFFFFF) | (first << 24);
        colours->values[2] = (colours->values[2] & 0xFFFFFF) | (second << 24);
        colours->values[3] = (colours->values[3] & 0xFFFFFF) | (second << 24);
        if (D_001B23C0 == 0) {
            clip.x0 = 0;
            clip.x1 = D_001A7340 - 1;
            clip.y0 = 63;
            clip.y1 = 340;
            D_001B23C0 = 1;
            D_001B23B0 = clip;
        }
        func_002FC620(D_001B23B0.x0, D_001B23B0.x1, D_001B23B0.y0, D_001B23B0.y1);
        entry = D_00239BA0 + D_00139568[((int *)(object + 0x28))[*(int *)(object + 0x14) + index]] * 224;
        texture = func_0028E588(*(unsigned short *)(entry + 0x3C), 0);
        func_0028EA58(texture, (int)(*(VEC_F6bf9ce42 **)object)->x,
                (int)((*(VEC_F6bf9ce42 **)object)->y + *(float *)(object + 0xC) * current + (float)*(int *)(object + 0x90)),
                (int)*(float *)(object + 4), (int)*(float *)(object + 4), colours->values);
        func_002FC620(0, D_001A7340 - 1, 0, D_001A7344 - 1);
    }
}
