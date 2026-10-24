/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -mno-split-addresses.
 * Prior worker coverage: US 0/3; US2 0/3; PAL 0/3.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/* Historical analysis (summary).
 * Historical screening catalogued calls, vector operations and data addressing without a
 * complete manual reconstruction. Its generated call/address lists and decoded instruction
 * header remain private. The dated manual reconstruction and recorded worker profile below
 * supersede that screening; no unsupported impossibility or handwritten classification is
 * carried forward.
 */

/* Wave4 manual reconstruction, 2026-10-23. Nonmatching; historical screening above
   is summarized; generated listings and unsupported classifications remain private.
   Trial source: src/levels/shared/L18_003FA180-g8.c
   Profile: -O2 -G8 -ffunction-sections -mno-split-addresses
   Recovered eight-case switch verified by lead: cases0-4 and default aliases5/6/7. Split-address shape trial grew1888B; restored best1660B.
   us: func_L18_003FA180: 0 of 3 places match (src/levels/shared/L18_003FA180-g8.c), exit 1; us2: func_L18_003FA180: 0 of 3 places match (src/levels/shared/L18_003FA180-g8.c), exit 1; pal: func_L18_003FA180: 0 of 3 places match (src/levels/shared/L18_003FA180-g8.c), exit 1
*/
#include "common.h"
extern unsigned short *D_L18_001FB320[];
extern char *D_L18_001B281C __attribute__((nosda));
extern int D_L18_001B2838 __attribute__((sda));

/* Each group is a terminated stream of 15-bit actor indices. */
#define DISABLE_GROUP(field) do { \
    group=*(unsigned int *)(state+(field)); \
    entry=D_L18_001FB320[group]; \
    while((group&0xff)!=0xff && (int)group<=D_L18_001B2838 && entry!=0 && \
          ((short)entry[-1]>=0 || entry==D_L18_001FB320[group])) { \
        member=D_L18_001B281C+(*entry&0x7fff)*0x100; \
        if(member==0) break; \
        flags=*(unsigned short *)(member+0x34)&0xffbc; \
        *(unsigned short *)(member+0x34)=flags|0x1000; \
        *(int *)(member+0x98)=*(int *)(*(char **)(member+0x24)+0x10); \
        if(*(short *)(owner+0xaa)!=0xb69) { \
            member[0x31]=0; \
            *(unsigned short *)(member+0x34)=flags|0x1001; \
        } \
        entry++; \
        group=*(unsigned int *)(state+(field)); \
    } \
} while(0)

void func_L18_003FA180(char *owner,unsigned int mode)
{
    char *state=*(char **)(owner+0x68);
    char *member;
    unsigned int group;
    unsigned short *entry;
    unsigned short flags;
    if(mode>=8) return;
    switch(mode) {
    case 0:
        DISABLE_GROUP(0x60);
        DISABLE_GROUP(0x64);
        break;
    case 1:
        DISABLE_GROUP(0x68);
        break;
    case 2:
        DISABLE_GROUP(0x6c);
        DISABLE_GROUP(0x74);
        DISABLE_GROUP(0x78);
        break;
    case 3:
        DISABLE_GROUP(0x70);
        break;
    case 4:
        DISABLE_GROUP(0x7c);
        break;
    case 5: case 6: case 7:
        return;
    }
}
#undef DISABLE_GROUP
