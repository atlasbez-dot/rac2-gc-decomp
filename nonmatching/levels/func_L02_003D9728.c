/* Signature/interface follow-up, 23 October 2026.
 * Profile: -O2 -G8 -ffunction-sections.
 * USA v1.01: 1844/1852 bytes, 0/1 carrying placements.
 * USA v2.00: 1844/1852 bytes, 0/1 carrying placements.
 * PAL: canonical name absent from the catalogue.
 * Ignored func_L02_00321C30 and func_002AA2E8 results are declared float; scalar-field
 * addresses use float pointers.
 * This follows the current linked C contract; it does not independently prove the original
 * source declaration.
 * The retained C remains nonmatching. Earlier sizes and residual offsets below are
 * historical and superseded by this measurement; their reopening hypotheses remain
 * unqualified. No linked build was run for this follow-up.
 */

/* Historical measurements, superseded where inconsistent with the follow-up above. */
/* Nonmatching reconstruction, checked 2026-10-23.
   Profile: game -O2 -G8 -ffunction-sections.
   USA v1.01 and USA v2.00: 0/1 carrying placements each.
   PAL: this canonical function is absent from both catalogues.
   1844/1852 bytes; early actor-table registers, branch ordering and later schedules differ. The ten-entry retail dispatch table was decoded and is referenced under its canonical identity; retained local label references follow the existing computed-goto convention. Reopen with the original branch layout and state-pointer lifetimes.
   No linked build was run for this draft.
*/

extern int D_L02_001B359C;
extern int D_L02_001B03F0 __attribute__((sda));
extern void *D_L02_002A5200[10];
extern float D_L02_001BA520;
extern int D_L02_001BA528;
extern int D_L02_001BA52C;
extern float func_00282E80(void *, void *);
extern float func_00283248(float, float);
extern float func_0029F530(char *);
extern void func_002B60B0(char *, float, float, float, float);
extern void func_002B5278(char *, float);
extern float func_L02_00321C30(void *, void *, float);
extern void *func_L02_003FC0B8(void *);
extern float *func_L02_003FC098(void *);
extern int func_L00_003206B8(void *, void *);
extern void func_L01_00321178(char *, void *);
extern void *func_0029FCC0(char *, int, void *);
extern void func_002833F0(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_L01_00322288(char *, float);
extern float func_00283C28(float);
extern void func_L02_003DAB68(char *);
extern float func_002AA2E8(float *, float, float);

void func_L02_003D9728(char *self) {
    static void *states[10] = {&&idle, &&pursue, &&step, &&turn_delay, &&turn, &&impact, &&pulse_a, &&beam, &&pulse_b, &&finish};
    float before[4];
    float after[4];
    float delta[4];
    char *state = *(char **)(self + 0x68);
    float *target = (float *)(state + 0x230);
    float distance = func_00282E80(self + 0x10, target);
    float heading = func_00283248(target[0] - *(float *)(self + 0x10), target[1] - *(float *)(self + 0x14));
    float frame = func_0029F530(self);
    char *part = (char *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8));
    int saved = *(int *)(part + 0x98);
    unsigned int mode;
    float speed;
    *(int *)(part + 0x98) = 0;
    func_002B60B0(self, 0.0016666667f, 0.05166667f, 0.003490659f, 0.10471977f);
    mode = *(unsigned char *)(self + 0x42);
    if (mode < 10) goto *D_L02_002A5200[mode];
    goto finish;
idle:
    if (*(unsigned char *)(self + 0x20) == 4)
        func_L02_00321C30(self + 0x10, &D_L02_001B03F0, 0.16666667f);
    else
        func_002B5278(self, *(float *)(self + 0xF8));
    goto finish;
pursue:
    if (func_L00_003206B8(self + 0x10, func_L02_003FC0B8(*(void **)(self + 0xB8))))
        func_L01_00321178(self, target);
    else
        func_L01_00321178(self, func_L02_003FC098(*(void **)(self + 0xB8)));
    if ((frame > 0.0f && frame < 2.0f) || (frame > 15.0f && frame < 17.0f) ||
        (frame > 30.0f && frame < 32.0f) || (frame > 45.0f && frame < 47.0f)) {
        D_L02_001BA520 = 0.05f;
        D_L02_001BA528 = 15;
        D_L02_001BA52C = 0;
    }
    goto finish;
step:
    if (frame > 12.0f && frame < 25.0f) {
        func_0029FCC0(self, 4, before);
        func_002B5278(self, heading);
        func_002833F0(self + 0xC0, self + 0xF0);
        func_0029FCC0(self, 4, after);
        func_00282CF0(delta, before, after);
        func_00282CC0(self + 0x10, self + 0x10, delta);
    } else if (frame > 42.0f && frame < 55.0f) {
        func_0029FCC0(self, 8, before);
        func_002B5278(self, heading);
        func_002833F0(self + 0xC0, self + 0xF0);
        func_0029FCC0(self, 8, after);
        func_00282CF0(delta, before, after);
        func_00282CC0(self + 0x10, self + 0x10, delta);
    }
    if ((frame > 0.0f && frame < 2.0f) || (frame > 29.0f && frame < 31.0f)) {
        D_L02_001BA520 = 0.1f;
        D_L02_001BA528 = 15;
        D_L02_001BA52C = 0;
    }
    goto finish;
turn_delay:
    if (frame < 23.0f) goto finish;
turn:
    func_L01_00322288(self, func_00283248(*(float *)(state + 0xF0), *(float *)(state + 0xF4)));
    *(float *)(state + 0xF8) -= *(float *)(state + 0x7C);
    func_00282CC0(self + 0x10, self + 0x10, state + 0xF0);
    goto finish;
impact:
    if (frame > 3.0f && frame < 5.0f) {
        D_L02_001BA520 = 0.4f;
        D_L02_001BA528 = 25;
        D_L02_001BA52C = 0;
    }
    goto finish;
pulse_a:
    if (frame > 20.0f && frame < 22.0f) {
        D_L02_001BA520 = 0.2f;
        D_L02_001BA528 = 25;
        D_L02_001BA52C = 0;
    }
    goto finish;
beam:
    if ((unsigned int)(*(unsigned char *)(self + 0x20) - 10) >= 2) {
        *(float *)(self + 0xF8) += ((*(float *)(state + 0x20) / (float)*(short *)(state + 0x24)) * -90.0f + 160.0f) * 0.00029088825f;
        *(float *)(self + 0xF8) = func_00283C28(*(float *)(self + 0xF8));
        func_002833F0(self + 0xC0, self + 0xF0);
        func_L02_003DAB68(self);
        if (distance > 12.0f && *(unsigned char *)(self + 0x20) != 10) {
            if (func_L00_003206B8(self + 0x10, func_L02_003FC0B8(*(void **)(self + 0xB8)))) {
                speed = ((*(float *)(state + 0x20) / (float)*(short *)(state + 0x24)) * -2.2f + 3.0f) * 0.016666668f;
                func_002AA2E8((float *)(self + 0x10), target[0], speed);
                func_002AA2E8((float *)(self + 0x14), target[1], speed);
            } else {
                func_002AA2E8((float *)(self + 0x10), func_L02_003FC098(*(void **)(self + 0xB8))[0], 0.33333334f);
                func_002AA2E8((float *)(self + 0x14), func_L02_003FC098(*(void **)(self + 0xB8))[1], 0.33333334f);
            }
        }
    }
    goto finish;
pulse_b:
    if (frame > 30.0f && frame < 32.0f) {
        D_L02_001BA520 = 0.2f;
        D_L02_001BA528 = 25;
        D_L02_001BA52C = 0;
    }
finish:
    if (*(float *)(self + 0x18) < func_L02_003FC098(*(void **)(self + 0xB8))[2])
        *(float *)(self + 0x18) = func_L02_003FC098(*(void **)(self + 0xB8))[2];
    *(int *)(D_L02_001B359C + (*(int *)(*(char **)(self + 0x68) + 0x244) << 8) + 0x98) = saved;
}
