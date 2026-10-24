/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G8 -ffunction-sections.
 * US: 524 versus 540; state dispatch layout and GP store/address forms differ.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

extern int D_001A79F0;
extern char *D_L02_001B35A8;
extern int D_L02_001AEC78;
extern int D_L02_001B30C8;
extern unsigned char D_001A7A6E, D_001A7A75;
extern int D_L02_001A903C;
extern void func_002A7750(void *, int, int);
extern void func_002E5E58(int, int, int);
extern void func_002B0A18(int, int);

void func_L02_0038A008(unsigned char *object) {
    int state = (unsigned char)object[0x20];
    char *entry;
    int kind;
    if (state == 1) {
        if (D_001A79F0 == 2) {
            if (D_L02_001B30C8 == 2) D_L02_001AEC78 = 0x71;
            if (D_L02_001AEC78 >= 11 || D_001A7A6E) return;
            D_001A7A6E = state;
        } else if (D_001A79F0 == 3) {
            if (D_L02_001B30C8 == 2) D_L02_001AEC78 = 0x70;
            if (D_L02_001AEC78 >= 12 || D_001A7A75) return;
            D_001A7A75 = state;
        } else return;
        func_002E5E58(1, 0, 0);
        func_002B0A18(0x1233, -1);
        D_L02_001A903C = state;
    } else if (state < 2) {
        if (state == 0) {
        object[0x30] = 0xFF;
        if (D_001A79F0 == 2) {
            for (entry = D_L02_001B35A8; entry; entry = *(char **)(entry + 0x28)) {
                kind = *(short *)(entry + 0xAA);
                if ((kind == 0xA9C || kind == 0xD0D || kind == 0xAA4 || kind == 0xE93 || kind == 0x1259) && *(float *)(entry + 0x18) < 400.0f)
                    ++D_L02_001AEC78;
            }
        } else if (D_001A79F0 == 3) {
            for (entry = D_L02_001B35A8; entry; entry = *(char **)(entry + 0x28)) {
                kind = *(unsigned short *)(entry + 0xAA);
                if ((unsigned)(kind - 0xF37) < 2 || (short)kind == 0xF3E)
                    ++D_L02_001AEC78;
            }
        }
        func_002A7750(object, 1, -1);
        }
    }
}
