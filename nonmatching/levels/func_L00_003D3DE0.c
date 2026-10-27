/* func_L00_003D3DE0: first full reconstruction (M9, 2026-10-26).
 * Profile -O2 -G16 -Wa,-G16 -ffunction-sections (the four-slot table at gp+0x12C0 is a
 * 16-byte sda object). 456/456 bytes, 0/27, 39 instructions off. The slot search, calls
 * and tail match; open: retail keeps the 3-quadword copy loop counting up (slti 3) where
 * this reverses it, the moby/state registers sit one temp later (t1/t2), and the
 * 0xFF/0x7F/1 constants and the weapon-table address operands come in another order.
 */
#include "common.h"
typedef int Quad __attribute__((mode(TI)));
typedef struct { char pad[0x58]; int value; char tail[0x84]; } ClassEntry;
extern char *D_L00_001B02B0[4] __attribute__((sda));
extern char *D_0018C0B0;
extern unsigned char D_00139568[];
extern ClassEntry D_L00_00262570[];
extern int func_L00_002D3F30(int, int);
extern int func_002E5DA0(int, int, char *, int);
extern char *func_0029EFD0(int);

/* Spawn the owner's companion moby into the first free one of four slots. */
char *func_L00_003D3DE0(char *owner, Quad *position)
{
    char *moby;
    char *state;
    char *src, *dst;
    int slot = -1;
    int i, j;
    i = 0;
    do {
        char *m = D_L00_001B02B0[i];
        if (m == 0 || *(short *)(m + 0xAA) != 0xB02 || (unsigned char)m[0x20] == 0xFE || (unsigned char)m[0x20] == 0xFD) {
            slot = i;
            break;
        }
        i++;
    } while (i < 4);
    if (slot < 0)
        return 0;
    if (func_L00_002D3F30(0x1F, 1) == 0) {
        func_002E5DA0(6, 0, owner, 0xB02);
        return 0;
    }
    moby = func_0029EFD0(0xB02);
    if (moby != 0) {
        state = *(char **)(moby + 0x68);
        *(char **)(state + 0x34) = owner;
        moby[0x30] = 0xFF;
        *(short *)(moby + 0x32) = 0x7F;
        moby[0x31] = 1;
        *(long long *)(moby + 0x38) = *(long long *)(owner + 0x38);
        src = D_0018C0B0 + 0xC0;
        dst = moby + 0xC0;
        for (j = 0; j < 3; j++) {
            qcopy(dst, src);
            src += 16;
            dst += 16;
        }
        qzero(moby + 0xF0);
        *(unsigned short *)(moby + 0x34) |= 0x100;
        qcopy(moby + 0x10, position);
        *(float *)(moby + 0x2C) *= 0.1f;
        *(int *)(state + 0x38) = -1;
        *(int *)(state + 0x3C) = 0;
        *(int *)(state + 0x40) = D_L00_00262570[D_00139568[0x1F]].value;
        *(short *)(state + 0x44) = 1;
        D_L00_001B02B0[slot] = moby;
        *(int *)(state + 0x38) = slot;
        moby[0x20] = 0;
    }
    return moby;
}
