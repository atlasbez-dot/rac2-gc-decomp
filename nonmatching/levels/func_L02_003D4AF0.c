/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G0 -ffunction-sections.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   520/524 bytes; float/int division scheduling, global-load registers and the pre-division nop remain different. Four meaningful source arrangements were tried. Reopen with a measured division scheduling or padding remedy.
   No linked build was run for this draft.
*/

extern void func_002A7470(char *, int, int, int);
extern void func_002A7750(char *, int, int);
extern int func_002A77E0(int);
extern int D_0018C2EC;
extern int D_001A7A00;
extern float func_002A7878(float, float);

void func_L02_003D4AF0(char *self, int previous) {
    int mode = *(unsigned char *)(self + 0x95);
    char *state = *(char **)(self + 0x68);
    float elapsed;
    float fraction;
    float choice;
    if (mode == 1) {
        fraction = ((float)*(short *)(state + 0x24) - *(float *)(state + 0x20)) / (float)*(short *)(state + 0x24);
        elapsed = (float)((D_001A7A00 - D_0018C2EC) / D_001A7A00);
        choice = elapsed - fraction + func_002A7878(-0.2f, 0.2f);
        {
            if (previous != mode && (choice < 0.0f || previous == -1)) {
                if (func_002A77E0(2)) {
                    if (*(unsigned char *)(self + 0x43) != 5)
                        func_002A7470(self, 5, 0, 10);
                } else {
                    if (*(unsigned char *)(self + 0x43) != 6)
                        func_002A7470(self, 6, 0, 10);
                }
            } else {
                if (func_002A77E0(2)) {
                    if (*(unsigned char *)(self + 0x43) != 7)
                        func_002A7470(self, 7, 0, 10);
                } else {
                    if (*(unsigned char *)(self + 0x43) != 8)
                        func_002A7470(self, 8, 0, 10);
                }
            }
        }
    }
    if (*(unsigned char *)(self + 0x95) == 2) {
        if (func_002A77E0(2)) {
            if (*(unsigned char *)(self + 0x43) != 20)
                func_002A7470(self, 20, 0, 10);
        } else {
            if (*(unsigned char *)(self + 0x43) != 19)
                func_002A7470(self, 19, 0, 10);
        }
    }
    *(short *)(state + 0x324) = *(unsigned char *)(self + 0x20);
    *(short *)(state + 0x326) = *(unsigned char *)(self + 0x95);
    func_002A7750(self, 10, *(unsigned char *)(self + 0x95));
}
