/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_00414020.c
 * Game compiler profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * Compiled/US retail bytes: 800/816.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: catalogue absent (exit 1).
 * Residual: 0xd0 frame agrees; saved GPR assignment, pointer reuse and vector-copy scheduling differ. Twelve GPR slots including four stack-tail slots are preserved.
 * Reopen only for: A concrete saved-argument/pointer allocation model; G0 and mno-split profiles have already been measured.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Creates and initializes the radial effect, including its twelve GPR argument slots. */
typedef unsigned int Quad414020 __attribute__((mode(TI)));
extern char D_L00_001B8DC0[];
extern char *func_0029EFD0(int);
extern void func_00282CF0(char *, char *, char *);
extern void func_00282F20(char *, char *, float);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282DD8(char *, char *, char *);
extern int func_002AD330(char *, char *, char *, char *);
extern int func_00283DB8(float, char *);
extern float func_00282E48(char *, char *);
extern float func_00282DB0(char *, char *);
extern float func_002831B0(float);
extern void func_L00_00414540(char *, char *, char *);
char *func_L00_00414020(float radius, char *position, int flash, int a, int b,
    int c, int d, int e, int directional, int g, int h, int j, char *parent)
{
    char direction[16] __attribute__((aligned(16)));
    char tangent[16] __attribute__((aligned(16)));
    Quad414020 zero;
    char sphere[16] __attribute__((aligned(16)));
    char toCamera[16] __attribute__((aligned(16)));
    char *effect, *state;
    effect = func_0029EFD0(0x139c);
    if (effect != 0) {
        ((unsigned char *)effect)[0x30] = 0xff;
        effect[0x20] = 0;
        *(short *)(effect + 0x32) = 0xff;
        state = *(char **)(effect + 0x68);
        *(Quad414020 *)(effect + 0x10) = *(Quad414020 *)position;
        *(float *)(effect + 0x1c) = 1.0f;
        func_00282CF0(direction, D_L00_001B8DC0, effect + 0x10);
        func_00282F20(direction, direction, 1.0f);
        func_002AFFD8(effect + 0x10, tangent, 1);
        *(Quad414020 *)(effect + 0xc0) = *(Quad414020 *)direction;
        func_00282DD8(effect + 0xd0, effect + 0xc0, tangent);
        func_00282F20(effect + 0xd0, effect + 0xd0, 1.0f);
        func_00282DD8(effect + 0xe0, effect + 0xd0, effect + 0xc0);
        *(float *)(effect + 0xcc) = 0.0f;
        *(float *)(effect + 0xec) = 0.0f;
        *(float *)(effect + 0xdc) = 0.0f;
        *(int *)(state + 0x20) = a;
        *(int *)(state + 0x24) = b;
        *(int *)(state + 0x28) = c;
        *(int *)(state + 0x2c) = d;
        *(int *)(state + 0x30) = e;
        *(int *)(state + 0x34) = g;
        *(int *)(state + 0x38) = j;
        *(short *)(state + 2) = 60;
        *(float *)(state + 8) = radius + radius;
        *(float *)(state + 0xc) = radius * 4.0f;
        *(int *)(state + 0x1c) = h;
        *(float *)(state + 0x14) = radius;
        *(int *)(state + 0x18) = directional;
        *(short *)state = 60;
        *(char **)(state + 0x3c) = parent;
        zero = 0;
        if (parent)
            func_002AD330(effect, parent, effect + 0x10, (char *)&zero);
        *(Quad414020 *)sphere = *(Quad414020 *)(effect + 0x10);
        *(float *)(sphere + 0xc) = radius * 3.0f;
        if (func_00283DB8(128.0f, sphere) == 1) {
            *(short *)(state + 4) = 10;
            *(float *)(state + 0x10) = 0.1f;
            if (func_00282E48(position, D_L00_001B8DC0) < 48.0f && flash) {
                *(int *)(D_L00_001B8DC0 + 0x2c) = 0;
                *(float *)(D_L00_001B8DC0 + 0x20) = 0.075f;
                *(int *)(D_L00_001B8DC0 + 0x28) = 20;
            }
            if (*(int *)(state + 0x18)) {
                func_00282CF0(toCamera, effect + 0x10, D_L00_001B8DC0);
                func_00282F20(toCamera, toCamera, 1.0f);
                if (1.5707964f - func_002831B0(func_00282DB0(toCamera, D_L00_001B8DC0 + 0x230)) < 0.45378566f)
                    *(int *)(state + 0x18) = 1;
                else
                    *(int *)(state + 0x18) = 0;
            }
        } else {
            *(int *)(state + 0x18) = 0;
            *(short *)(state + 4) = 0;
        }
        func_L00_00414540(effect, tangent, (char *)&zero);
    }
    return effect;
}
