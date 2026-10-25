/* Retained nonmatching C; measured 25 October 2026.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Final check.py coverage: us 0/27, us2 0/27, pal catalogue absent.
 * 580/580 bytes, first difference +0x34. Shared-helper transfers retain true vectors, but validity/allocation exits, table-base scheduling and branch layout differ. Nested common-return trial was576bytes with worse early allocation.
 * Reopen: Establish a distinct real owner/allocator-result lifetime and common-failure control-flow witness before another compile; equal size is not a match.
 * Shared EE transfer helpers are approved; their use is not matching evidence.
 * Earlier complete drafts and all trial sources/logs are preserved privately.
 */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { char pad[0x50]; float speed; char tail[0x8C]; } WeaponEntry;
extern WeaponEntry D_L00_00262570[];
extern unsigned char D_0013957F;
extern unsigned int D_L00_001AF6D4 __attribute__((sda));
extern float D_L00_001B8DC0[4], D_L00_001B8FF0[4];
extern int func_002B4038(int, int);
extern char *func_0029EFD0(int);
extern void func_003001E0(void *, void *, void *);
extern int func_00283CF0(float);
extern float func_00283CE0(int);
extern char *func_L00_0032A088(int, int);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_L00_003A8060(char *, char *);
extern void func_L00_003A8E28(void *);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_L00_003A80F8(char *, void *);

/* Spawn and configure one moving beam effect. */
char *func_L00_003A7C30(void *position, void *velocity, int handle, int mode)
{
    float normal[4], previous[4];
    char *moby, *state;
    if (handle == -1 || !func_002B4038(0x5CB, handle))
        return 0;
    moby = func_0029EFD0(0x5D6);
    if (!moby)
        return 0;
    *(unsigned char *)(moby + 0x30) = 0xFF;
    *(unsigned short *)(moby + 0x32) = 0xFF;
    *(unsigned char *)(moby + 0x31) = 1;
    state = *(char **)(moby + 0x68);
    qcopy(moby + 0x10, position);
    *(unsigned char *)(moby + 0x20) = 0;
    *(short *)(state + 0x12) = mode;
    func_003001E0(state, velocity, position);
    *(short *)(state + 0x10) = func_00283CF0(128.0f / (D_L00_00262570[D_0013957F].speed * (1.0f / 60.0f)));
    *(float *)(state + 0x14) = 1.0f / func_00283CE0(*(short *)(state + 0x10));
    *(short *)(state + 0x1A) = handle;
    *(char **)(state + 0x1C) = func_L00_0032A088(0x5CB, handle);
    func_002AFFD8(moby + 0x10, (char *)normal, 1);
    func_00282D30(normal, normal, -1.0f);
    func_L00_003A8060(moby, (char *)normal);
    if (D_L00_001AF6D4 >= 4)
        D_L00_001AF6D4 = 0;
    *(short *)(state + 0x18) = D_L00_001AF6D4;
    D_L00_001AF6D4 = (int)(D_L00_001AF6D4 + 1) % 3;
    func_L00_003A8E28(moby);
    if (mode == 1) {
        qcopy(state + 0x30, D_L00_001B8DC0);
        func_00282F20(state + 0x20, D_L00_001B8FF0, func_00282DF0(velocity));
    }
    if (mode == 2) {
        qcopy(previous, position);
        func_00282CC0(moby + 0x10, position, velocity);
        if (func_L00_003A80F8(moby, previous))
            *(unsigned char *)(moby + 0x20) = 2;
    }
    return moby;
}
