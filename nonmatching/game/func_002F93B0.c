/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/28 placements; exit 1.
 * us2: catalogue absent (no credit).
 * pal: catalogue absent (no credit).
 * USA assigned unit compiled 872 bytes; retail 964 bytes.
 * Standalone retained source compiles to 876 bytes; unit context also matters.
 * Entry save allocation, repeated state-base materialization and guard layout differ. Reopen with independently supported state-pointer lifetimes and guard source structure.
 */

extern int D_001B2240, D_001B223C;
extern int D_001B2244 __attribute__((sda));
extern int D_001A79F8;
extern int D_00139688[];
extern int func_002E5CF8(int, int, char *);
extern void func_0028B6C8(int, unsigned int);
extern int func_002F6510(void);
extern void func_002F9198(void);

extern char D_00138180[], D_0021F240[], D_00239BA0[];
extern unsigned char D_00139568[];

void func_002F93B0(void)
{
    char *state = D_0021F240;
    int moved, cost;
    int *item;
    char *record;
    if (*(int *)(state + 0x84)) return;
    if ((*(int *)(D_00138180 + 0x1C4) & 0x2000) ||
            (D_001B2240 >= 16 && D_001B2240 % 10 == 1)) {
        if (*(int *)(state + 0x6C) < 57) {
            moved = 0;
            if (*(int *)(state + 0x80) < *(int *)(state + 0x740) - 1) {
                ++*(int *)(state + 0x80);
                moved = 1;
            }
            if (moved) {
                if (*(int *)(state + 0x88))
                    *(int *)(state + 0x90) = *(int *)(state + 0x50) == 2 ? 3 : 1;
                *(int *)(state + 0x6C) += 56;
                func_002E5CF8(1, 17, *(char **)(state + 0x28));
                if (*(int *)(state + 0x78) != -1) {
                    if (*(int *)(state + 0x50) == 0)
                        func_0028B6C8(*(int *)(state + 0x78), 0);
                    *(int *)(D_0021F240 + 0x78) = -1;
                }
            }
        }
    }
    if ((*(int *)(D_00138180 + 0x1C4) & 0x8000) ||
            (D_001B223C >= 16 && D_001B223C % 10 == 1)) {
        state = D_0021F240;
        if (*(int *)(state + 0x6C) >= -56) {
            moved = 0;
            if (*(int *)(state + 0x80) > 0) {
                --*(int *)(state + 0x80);
                moved = 1;
            }
            if (moved) {
                if (*(int *)(state + 0x88))
                    *(int *)(state + 0x90) = *(int *)(state + 0x50) == 2 ? 3 : 1;
                *(int *)(state + 0x6C) -= 56;
                func_002E5CF8(1, 17, *(char **)(state + 0x28));
                if (*(int *)(state + 0x78) != -1) {
                    if (*(int *)(state + 0x50) == 0)
                        func_0028B6C8(*(int *)(state + 0x78), 0);
                    *(int *)(D_0021F240 + 0x78) = -1;
                }
            }
        }
    }
    if ((*(int *)(D_00138180 + 0x1C4) & 0x40) && !(D_001B2244 & 0x40)) {
        state = D_0021F240;
        if (*(int *)(state + 0x50) == 3) {
            if (D_001B2244 & 0x40) goto finish;
            if (*(int *)(state + 0x50) != 3) goto finish;
            if (*(int *)(state + 0x144 + *(int *)(state + 0x80) * 12) == 0) goto finish;
        }
        if (*(int *)(state + 0x50) == 0) {
            item = (int *)(state + 0x144 + *(int *)(state + 0x80) * 24);
            if (*item == 0) {
                cost = func_002F6510();
                if (D_001A79F8 >= cost) goto activate;
            }
            item = (int *)(state + 0x144 + *(int *)(state + 0x80) * 24);
            if (*item != 1) goto rejected;
            record = D_00239BA0 + D_00139568[item[-1]] * 224;
            if (D_00139688[item[-1]] >= *(unsigned short *)(record + 0x8E)) goto rejected;
            if (D_001A79F8 < *(unsigned short *)(record + 0x88)) goto rejected;
        }
activate:
        state = D_0021F240;
        if (*(int *)(state + 0x88)) *(int *)(state + 0x90) = 1;
        *(int *)(state + 0x84) = 1;
        func_002E5CF8(0, 17, *(char **)(state + 0x28));
        goto finish;
rejected:
        func_002E5CF8(2, 17, *(char **)(D_0021F240 + 0x28));
    }
finish:
    if (*(int *)(D_00138180 + 0x1C4) & 0x10) func_002F9198();
}
