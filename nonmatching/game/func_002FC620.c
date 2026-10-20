/* func_002FC620: 276 bytes compiled (-O2 -G0 in its own file), retail 284.
   Still differs in scheduling and register choice: retail loads D_001A7340 and D_001A7344 before
   the first store and keeps the clamped fields in $t0..$t3; this cc1 places the loads and the
   clamps around the stores differently. Needs a -G0 file for the same reason as func_002FC468. */
#include "include_asm.h"

extern char *D_001B22A8 __attribute__((sda));
extern int D_001A7340;
extern int D_001A7344;

void func_002FC620(int a0, int a1, int a2, int a3)
{
    *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 0) = 0x10000002u;
    {
        long long lim1 = D_001A7340 - 1;
        long long lim3 = D_001A7344 - 1;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 4) = 0;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 8) = 0;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 12) = 0x50000002u;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 16) = 0x8001u;
        *(long long *)(*(char * volatile *)&D_001B22A8 + 32) =
            (long long)(a0 > -1 ? a0 : 0) | ((long long)(lim1 < a1 ? lim1 : a1) << 16)
            | ((long long)(a2 > -1 ? a2 : 0) << 32) | ((long long)(lim3 < a3 ? lim3 : a3) << 48);
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 20) = 0x10000000u;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 24) = 0x0eu;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 28) = 0;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 40) = 0x40u;
        *(unsigned int *)(*(char * volatile *)&D_001B22A8 + 44) = 0;
        D_001B22A8 = *(char * volatile *)&D_001B22A8 + 0x30;
    }
}
