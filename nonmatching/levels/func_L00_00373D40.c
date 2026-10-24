/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 444 / 512 bytes; size equality is not a match.
 * us: 0/27 placements; 444/512 bytes.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Dialog branches, model bases, helper-call scheduling and register allocation differ. Two nested condition forms tied at 432 bytes; direct state/event field references reached 444. Reopen on model field expressions and the original dialog branch layout.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections
 * Measured text: 444 bytes; retail: 512 bytes. Stack frame 0x20.
 * Final coverage: US 0/27, US2 absent, PAL absent. Absences are not matches.
 * 3 measured source/profile forms. Dialog branches, model bases, helper-call scheduling and
 * register allocation differ. Two nested condition forms tied at 432 bytes; direct
 * state/event field references reached 444. Reopen on model field expressions and the
 * original dialog branch layout.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

extern char D_L00_0022F7C0[];
extern char D_00138180[];
extern int D_001A79F8;
extern unsigned int D_L00_001B25A4 __attribute__((sda));
extern int D_L00_001AD500 __attribute__((sda));
extern int D_L00_001AD4F8 __attribute__((sda));
extern int D_L00_001AD4FC __attribute__((sda));
extern int func_002E5CF8(int, int, char *);
extern int func_00288FB8(int);
extern void func_002F88D8(void *);
extern void func_002F9198(void);
extern void func_002FB1A0(void);

void func_L00_00373D40(int *answer) {
    char *model = D_L00_0022F7C0;
    int index = *(int *)(model + 0x80);
    int price = *(int *)(model + 0x144 + index * 12);
    int state = *(int *)(D_L00_0022F7C0 + 0x84);
    if (state == 1) {
        *answer = 0;
        if (D_001A79F8 < price) func_002E5CF8(2, 17, *(char **)(D_L00_0022F7C0 + 0x28));
        *(int *)(D_L00_0022F7C0 + 0x84) = 2;
    } else if (state == 2) {
        if ((*(unsigned int *)(D_00138180 + 0x1C4) & 0x10) && !(D_L00_001B25A4 & 0x10)) {
            *answer = 0;
            *(int *)(D_L00_0022F7C0 + 0x84) = 3;
        } else if ((*(unsigned int *)(D_00138180 + 0x1C4) & 0x40) && !(D_L00_001B25A4 & 0x40)) {
            *answer = 1;
            *(int *)(D_L00_0022F7C0 + 0x84) = 3;
        }
    } else if (state == 3) {
        if (*answer) {
            if (D_001A79F8 >= price) {
                if (D_L00_001AD500 != 4) {
                    D_L00_001AD4F8 = 1;
                    D_L00_001AD4FC = *(int *)(model + 0x148 + index * 12);
                    func_002E5CF8(7, 17, *(char **)(D_L00_0022F7C0 + 0x28));
                    D_001A79F8 -= price;
                    func_002F88D8((void *)func_00288FB8(0x2DCB));
                    func_002E5CF8(7, 17, *(char **)(D_L00_0022F7C0 + 0x28));
                    func_002F9198();
                } else {
                    func_002F88D8((void *)func_00288FB8(0x2DCC));
                    func_002E5CF8(0, 17, *(char **)(D_L00_0022F7C0 + 0x28));
                }
            } else {
                func_002F88D8((void *)func_00288FB8(0x2DCC));
                func_002E5CF8(0, 17, *(char **)(D_L00_0022F7C0 + 0x28));
            }
        } else func_002E5CF8(0, 17, *(char **)(D_L00_0022F7C0 + 0x28));
        *(int *)(D_L00_0022F7C0 + 0x84) = 0;
        func_002FB1A0();
    }
}
