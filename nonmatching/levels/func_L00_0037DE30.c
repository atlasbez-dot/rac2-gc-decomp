/* Retained C, not matched.
   Profile: -O2 -G0 -ffunction-sections.
   196 bytes; 0/27 on USA/PAL/US2, first mismatch +0x14. Corrected pointer advance and positive-filter bypass; loop and branch-likely slots match, but best/found occupy swapped s3/s4. Seven bounded source/profile trials; next useful hypothesis is real variable lifetime/allocation. */

typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s32 func_L00_0037DDE8(u32 key, u32 owner);

u8 *func_L00_0037DE30(int a0, u8 **a1, int a2, int a3)
{
    u8 *found = 0;
    int best = 0x270F;

    if (a2 > 0) {
        u8 **p = a1;
        int remaining = a2;
        do {
            s32 v;
            if (a3 <= 0 || *(s16 *)(*(u8 **)(*p + 0x24) + 0x46) == a3) {
                v = func_L00_0037DDE8((u32)a0, (u32)*p);
                if (v < best && v != -1) {
                    found = *p;
                    best = v;
                }
            }
            --remaining;
            ++p;
        } while (remaining != 0);
    }
    return found;
}
