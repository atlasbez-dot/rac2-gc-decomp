/* Near miss, rechecked 2026-10-21 in src/levels/02_maktar_nebula/L02_003F5430-g8.c
 * with the qualified compiler on master 8b23616 plus PR249,
 * -O2 -G8 -ffunction-sections: 284 bytes, retail 288; 0 of 1 places match.
 * The shared return lacks the alignment nop before jr $ra. The empty do/while
 * previously used only to force this alignment was removed: it is an artificial
 * source barrier, prohibited by AGENTS.md. No matching source form is known.
 */

#include "include_asm.h"

extern char *D_L02_001B359C_s __attribute__((sda));
extern unsigned short D_L02_001B1214 __attribute__((sda));
extern unsigned int D_L02_001FC060[];
extern char D_00189E20_c[];


void func_L02_003FB000(char *a0) {
    char *state = *(char **)(a0 + 0x68);
    unsigned int index = *(unsigned int *)(state + 0x40);
    unsigned int entry;
    short *p;
    char *tbl;
    char *rec;
    char *g;

    *(int *)(state + 0x60) = 0;
    *(float *)(state + 0x64) = 0;
    if (index == 0xFF)
        return;
    entry = D_L02_001FC060[index];
    if (entry == 0)
        return;
    p = (short *)entry;
    tbl = D_L02_001B359C_s;
    do {
        rec = tbl + ((*(unsigned short *)p & 0x7FFF) << 8);
        if (rec == 0)
            continue;
        if (*(unsigned char *)(rec + 0x20) == 0xFE)
            continue;
        if (*(unsigned char *)(rec + 0x20) == 0xFD)
            continue;
        if (*(unsigned char *)(rec + 0x20) == 1)
            continue;
        {
            short type = *(short *)(rec + 0xAA);
            if (type == 0x9CA || type == 0xB22 || type == 0xC3B || type == 0xC3E || type == 0x9F8 || type == 0xA44) {
                *(int *)(state + 0x60) += 1;
                *(float *)(state + 0x64) += *(float *)(*(char **)(rec + 0x68) + 0x20);
            }
        }
    } while (*p++ >= 0);
    g = D_00189E20_c;
    *(float *)(state + 0x68) = (float)*(int *)(g + 0x24CC);
    *(short *)(state + 0x11C) = 0;
    *(unsigned short *)(state + 0x11E) = D_L02_001B1214;

}
