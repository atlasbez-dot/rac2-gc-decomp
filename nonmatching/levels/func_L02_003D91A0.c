/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   1100/1124 bytes; initialization ordering and the damage/animation-selector control flow differ. Direct branch spelling replaced an indexed selector expression; the displayed damage scale constants retain the measured float values. Reopen with the original state-field grouping or branch layout.
   No linked build was run for this draft.
*/

typedef int Vector __attribute__((mode(TI)));
extern int D_L02_001B359C;
extern int D_L02_001FF798[];
extern int func_00283CF0(float);
extern void func_002A04B8(char *, void *, void *, void *);
extern void func_00282A60(void *, int, int);
extern void func_L02_003DB6D8(char *);
extern void *func_002A9640(char *, int, int);
extern float func_002A96A0(char *, void *);
extern void func_002AB800(char *, void *);
extern void func_002A7750(char *, int, int);
extern void func_002AF1D0(char *, char *, int, int);
extern int func_002B3BA8(char *, int, int, int, float, float);
extern void func_L02_003D4990(char *);
extern void func_L02_003FC020(void *, void *);
extern void func_L02_003D9728(char *);
extern void func_L02_003D9E68(char *);

void func_L02_003D91A0(char *self) {
    char *state = *(char **)(self + 0x68);
    char *part;
    char *damage;
    char *source;
    float amount;
    if (*(unsigned char *)(self + 0x20) == 0) {
        *(unsigned char *)(state + 0x48) = func_00283CF0(15.0f);
        *(unsigned char *)(state + 0x4A) = func_00283CF0(24.0f);
        *(float *)(state + 0x124) = 0.5f;
        *(float *)(state + 0x5C) = 1.0f;
        *(int *)(state + 0x88) = 2;
        *(float *)(state + 0x60) = 1.1344641f;
        *(float *)(state + 0x80) = 0.52359885f;
        *(float *)(state + 0x84) = 0.01f;
        *(float *)(state + 0x7C) = 0.013888889f;
        *(float *)(state + 0x30) = 11.0f;
        *(float *)(state + 0x54) = 1.0f;
        *(float *)(state + 0x58) = 1.0f;
        *(unsigned char *)(state + 0x139) = 1;
        *(unsigned char *)(state + 0x28) = 3;
        *(unsigned char *)(state + 0x29) = 0;
        *(int *)(state + 0x50) = 0;
        part = (char *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8));
        *(unsigned short *)(part + 0x34) |= 6;
        *(short *)(state + 0x286) = 60;
        func_002A04B8(self, state + 0x270, state + 0x274, state + 0x278);
        func_00282A60(state + 0x170, 0, 0x40);
        func_00282A60(state + 0x1B0, 0, 0x40);
        func_L02_003DB6D8(self);
        *(char **)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8) + 0xB8) = self;
        *(int *)(state + 0x254) = 0x40FF00EA;
        *(short *)(state + 0x282) = 0;
        *(int *)(state + 0x250) = 0x40FF00EA;
        *(int *)(state + 0x258) = 0x40FF00EA;
        *(int *)(state + 0x264) = 0;
        *(short *)(state + 0x280) = 0;
        return;
    }
    damage = func_002A9640(self, 0x10000, 0);
    amount = func_002A96A0(self, damage);
    if (damage && *(char **)(damage + 0x20)) {
        source = *(char **)(damage + 0x20);
        if (*(short *)(source + 0xAA) == 0xC89 || *(short *)(source + 0xAA) == 0xBFE)
            amount *= 0.35f;
    }
    if (amount > 0.0f) {
        if (*(unsigned char *)(self + 0x20) >= 5 && *(unsigned char *)(self + 0x20) != 10 &&
            *(unsigned char *)(self + 0x20) != 11) {
            *(float *)(state + 0x20) -= amount;
            D_L02_001FF798[*(unsigned char *)(state + 0x37)] += (int)(amount * 32.0f);
            if (*(short *)(state + 0x140) == 0)
                func_002AB800(self, state + 0x140);
            if (amount > 3.0f && *(unsigned char *)(self + 0x20) == 6 && *(unsigned char *)(self + 0x42) == 7) {
                *(short *)(state + 0x28A) = *(unsigned char *)(self + 0x20);
                part = (char *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8));
                if (*(unsigned char *)(part + 0x43) == 255)
                    *(short *)(state + 0x28C) = *(unsigned char *)(part + 0x42);
                else
                    *(short *)(state + 0x28C) = *(unsigned char *)(part + 0x43);
                *(short *)(state + 0x28E) = *(unsigned char *)(self + 0xBC);
                func_002A7750(self, 9, -1);
                *(float *)(state + 0x24C) = 0.1939255f;
            }
            if (*(float *)(state + 0x20) <= 0.0f) {
                *(float *)(state + 0x24C) = 0.387851f;
                func_002A7750(self, 10, -1);
            }
        }
    }
    *(unsigned char *)(self + 0xA8) = 255;
    *(unsigned char *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8) + 0xA8) = 255;
    part = (char *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8));
    source = *(char **)(*(char **)(self + 0x68) + 0x260);
    if (part && source) func_002AF1D0(part, source, 4, 0);
    *(short *)(state + 0x284) = func_002B3BA8(self, *(int *)(state + 0x268), 0, 0, 100.0f, 100.0f);
    part = *(char **)(state + 0x160);
    *(char **)(state + 0x240) = part;
    if (*(unsigned char *)(self + 0x20) != 3)
        *(Vector *)(state + 0x230) = *(Vector *)(part + 0x10);
    if (*(unsigned char *)(state + 0x2E) == 2) {
        source = *(char **)(state + 0x264);
        if (source && *(unsigned char *)(source + 0x20) != 254 && *(unsigned char *)(source + 0x20) != 253 &&
            *(unsigned char *)(source + 0x20) >= 3) {
            func_L02_003D4990(self);
            func_L02_003FC020(*(void **)(self + 0xB8), *(void **)(state + 0x264));
        }
        func_L02_003DB6D8(self);
    }
    func_L02_003D9728(self);
    func_L02_003D9E68(self);
}
