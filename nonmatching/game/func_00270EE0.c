/* func_00270EE0 (588 bytes, 28 places): the rac1 twin start_camera_blend ported.
   26 October 2026 (M32): 588/588 and exact at all 28 places under the unit's profile
   plus -fno-gcse (-O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse).
   Without -fno-gcse, gcse keeps the entry's %hi(D_001B5490) in $s6 for the final phase
   store, where retail rebuilds it (lui $v1; sh). 596/588. Not landed: an optimisation-off
   switch for one function is not accepted. Needs the declarations of src/game/0026EA00-qcopy.c
   (TI128, D_001B5490, func_00270E30, func_00270EA8). */
extern char D_00189E20[];
extern void func_00282F20(float *, float *, float);
extern void func_00270B58(float *, float *, float *, float *, float *, float *);
extern void func_002AB600(void *, void *);
extern void func_00270D50(void);
extern float func_00283CE0(int);

/* Starts the camera blend from the previous camera: captures the blend source
   by the sub-mode (byte 3) when the phase is 1, else saves or restores the
   resident vectors; then sets phase 3, copies the sub-mode into the kind
   (byte 2) and either resets the lerp or advances the orbit frame count. */
void func_00270EE0(char *from)
{
    unsigned char *r = (unsigned char *)D_001B5490;
    float a[4] __attribute__((aligned(16)));
    float b[4] __attribute__((aligned(16)));
    float c[4] __attribute__((aligned(16)));
    unsigned char sub;

    if (*(short *)r == 1) {
        sub = r[3];
        if (sub == 0) {
            *(TI128 *)(r + 0x50) = *(TI128 *)(from + 0x30);
            func_002AB600(r + 0x60, from);
        } else if (sub == 2) {
            *(TI128 *)(r + 0xC0) = *(TI128 *)(from + 0x30);
            func_002AB600(r + 0xD0, from);
            func_00270D50();
        } else {
            char *g = D_00189E20;

            func_00282F20(a, (float *)(*(char **)(g + 0x2290) + 0xC0), 1.0f);
            func_00282F20(b, (float *)(*(char **)(g + 0x2290) + 0xD0), 1.0f);
            func_00282F20(c, (float *)(*(char **)(g + 0x2290) + 0xE0), 1.0f);
            func_00270B58((float *)(r + 0x70), (float *)(from + 0x30),
                          (float *)(*(char **)(r - 0x100) + 0x30), a, b, c);
            func_002AB600(r + 0xB0, from);
            *(TI128 *)(r + 0xD0) = *(TI128 *)(r + 0xB0);
        }
    } else {
        sub = r[3];
        if (sub == 2) {
            func_00270E30();
            func_00270D50();
        } else if (sub == 1) {
            func_00270E30();
            *(TI128 *)(r + 0xB0) = *(TI128 *)(r + 0xD0);
        } else if (sub == 0) {
            func_00270EA8();
        }
    }
    *(short *)D_001B5490 = 3;
    r[2] = r[3];
    if (r[2] == 0) {
        unsigned char *l = r + 0x10;

        *(float *)(l + 0x10) = *(float *)(l + 0x14);
        *(int *)(l + 0xC) = 0;
        *(TI128 *)(r + 0x40) = *(TI128 *)(r + 0x50);
        *(int *)(r + 0x10) = 0;
        *(float *)(l + 0x4) = *(float *)(l + 0x8);
        *(TI128 *)(r + 0x30) = *(TI128 *)(r + 0x60);
    } else {
        unsigned char *o = r + 0x70;
        int n = ++*(int *)(o + 0x14);

        *(int *)(o + 0xC) = n;
        *(float *)(o + 0x10) = 1.0f / func_00283CE0(n);
    }
}
