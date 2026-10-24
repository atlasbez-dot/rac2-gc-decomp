/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 756 / 808 bytes; size equality is not a match.
 * us: 0/27 placements; 756/808 bytes.
 * us2: 0/27 placements; 756/808 bytes.
 * pal: 0/27 placements; 756/808 bytes.
 * Residual: Object-preview initialization and pose copies differ in register/address allocation and branch sharing. Both resource modes are reconstructed; pose rows keep all four 16-byte vectors of their 64-byte stride. Reopen on mode-specific initialization and copy lifetimes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 756 bytes; retail: 808 bytes. Stack frame 0x30.
 * Final coverage: US 0/27, US2 0/27, PAL 0/27. Absences are not matches.
 * 1 measured source/profile forms. Object-preview initialization and pose copies differ in
 * register/address allocation and branch sharing. Both resource modes are reconstructed; pose
 * rows keep all four 16-byte vectors of their 64-byte stride. Reopen on mode-specific
 * initialization and copy lifetimes.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
typedef struct { Vector rotation, position, alternate_rotation, alternate_position; } PreviewPose;
extern char D_L00_0022F7C0[];
extern unsigned char D_00139568[];
extern char D_L00_00262570[];
extern PreviewPose D_L00_0028D900[];
extern unsigned char D_001A7BB1;
extern int func_L00_00305600(int, int);
extern void func_0029F0C8(unsigned char *, int);
extern void func_002A0468(unsigned long long *, unsigned long long, unsigned long long, unsigned long long, unsigned long long);
extern void func_0029F390(unsigned char *);
extern void func_002A0F48(unsigned char *);

void func_L00_0037A2E8(void) {
    char *model = D_L00_0022F7C0;
    unsigned char *object;
    int selection;
    int alternate;
    if (*(int *)(model + 0x50) == 0) {
        if (!func_L00_00305600(*(int *)(model + 0x148 + *(int *)(model + 0x70) * 24), *(int *)(model + 0x1C))) return;
        object = *(unsigned char **)(model + 0x2C);
        *(int *)(model + 0x8C) = 0;
        *(int *)(model + 0x88) = 1;
        func_0029F0C8(object, *(int *)(model + 0x148 + *(int *)(model + 0x70) * 24));
        if (!*(void **)(object + 0x24)) {
            *(int *)(model + 0x88) = 0;
            *(int *)(model + 0x8C) = 0;
            return;
        }
        func_002A0468((unsigned long long *)object, 0x202020, 14, 14, 0);
        *(unsigned short *)(object + 0x34) = 0x2010;
        *(unsigned short *)(object + 0x32) = 64;
        object[0x31] = 1;
        object[0x30] = 0;
        object[0x23] = 0;
        object[0x20] = 0;
        if (*(unsigned char *)(*(char **)(object + 0x24) + 0xC) > 1) {
            object[0x43] = 1;
            object[0x42] = 1;
            func_0029F390(object);
        }
        selection = *(int *)(model + 0x140 + *(int *)(model + 0x70) * 24);
        alternate = D_L00_00262570[(unsigned int)D_00139568[selection] * 0xE0 + 4];
    } else {
        if (*(int *)(model + 0x50) != 1) return;
        if (!func_L00_00305600(*(int *)(model + 0x14C + *(int *)(model + 0x70) * 16), *(int *)(model + 0x1C))) return;
        object = *(unsigned char **)(model + 0x2C);
        *(int *)(model + 0x8C) = 0;
        *(int *)(model + 0x88) = 1;
        func_0029F0C8(object, *(int *)(model + 0x14C + *(int *)(model + 0x70) * 16));
        if (!*(void **)(object + 0x24)) {
            *(int *)(model + 0x88) = 0;
            *(int *)(model + 0x8C) = 0;
            return;
        }
        func_002A0468((unsigned long long *)object, 0x202020, 14, 14, 0);
        *(unsigned short *)(object + 0x34) = 0x2010;
        *(unsigned short *)(object + 0x32) = 64;
        object[0x31] = 1;
        object[0x30] = 0;
        object[0x23] = 0;
        object[0x20] = 0;
        if (*(unsigned char *)(*(char **)(object + 0x24) + 0xC) > 1) {
            object[0x43] = 1;
            object[0x42] = 1;
            func_0029F390(object);
        }
        selection = *(int *)(model + 0x144 + *(int *)(model + 0x70) * 16);
        alternate = D_L00_00262570[(unsigned int)D_00139568[selection] * 0xE0 + 4];
    }
    if (!alternate) {
        *(float *)(model + 0x98) = D_L00_0028D900[selection].position.f[3];
        *(Quad *)(model + 0xC0) = D_L00_0028D900[selection].position.q;
        *(Quad *)(object + 0xF0) = D_L00_0028D900[selection].rotation.q;
    } else {
        *(float *)(model + 0x98) = D_L00_0028D900[selection].alternate_position.f[3];
        *(Quad *)(model + 0xC0) = D_L00_0028D900[selection].alternate_position.q;
        *(Quad *)(object + 0xF0) = D_L00_0028D900[selection].alternate_rotation.q;
    }
    if (D_001A7BB1) *(float *)(model + 0xC8) -= 0.55f;
    *(int *)(model + 0x9C) = 1;
    func_002A0F48(object);
    if (*(int *)(model + 0x84) == 0 && *(int *)(model + 0x70) == *(int *)(model + 0x80))
        *(int *)(model + 0x90) = 0;
}
