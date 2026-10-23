/* Retained C reconstruction: 248/252 bytes.
   Profile: -O2 -G0 -ffunction-sections -g.
   0/27 in us, pal and us2. Debug compilation narrows the former 240-byte draft to 248 bytes; resident address lifetime and floating-branch/division scheduling remain different. The actual helper returns float.
   Reopen only with new source/type/lifetime evidence; bounded scheduling/profile variants did not close it. */

#include "include_asm.h"

extern char D_00189E20_2[];
extern float func_002AA2E8(float *dst, float value, float scale);

void func_L00_002A9E30(float arg0, float arg1, float arg2, float arg3)
{
    char *base = D_00189E20_2;
    float step;
    float threshold = *(float *)(base + 0xC38);

    if (threshold < arg0) {
        step = arg0 - threshold;
    } else {
        float rate = 2.0f;

        if (*(int *)(base + 0xC2C) == 0)
            rate = 0.5f / *(float *)(base + 0xC24);
        {
            unsigned char *owner = *(unsigned char **)(base + 0x2290);
            int index = owner[0x43];
            char *entry = *(char **)(*(char **)(owner + 0x24) + index * 4 + 0x48);
            unsigned char count = *(unsigned char *)(entry + 0x10);

            step = arg0 + (rate * (float)count - threshold);
        }
    }

    if (0.0f < arg1) {
        float scale = *(float *)(base + 0xC24);

        if (*(int *)(base + 0xC2C) != 0)
            scale = *(float *)*(char **)(*(char **)(base + 0x2290) + 0x5C);
        {
            float value = (arg2 * step) / (arg1 * scale);

            if (arg3 == -1.0f)
                *(float *)(base + 0xC20) = value;
            else
                func_002AA2E8((float *)(base + 0xC20), value, arg3);
        }
    }
}
