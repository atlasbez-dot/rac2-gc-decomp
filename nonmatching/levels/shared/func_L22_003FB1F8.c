/* Retained C reconstruction, not linked or counted.
 * Profile: -O2 -G8 -ffunction-sections.
 * 276/276 bytes; 0/2 placements in each of us, us2 and pal.
 * The approved qcopy closes the copy addressing, counter rematerialization
 * and controller allocation walls. All code outside the initial object-flag
 * stores agrees.
 * Remaining: The 0x50/0xFF constant allocations and stores at +0x32/+0x30 are exchanged
 * around the +0x34 mask store, first difference +0x84. A named mask load and
 * an evidence-based partial object-field layout give the same schedule.
 * Reopen with: Independent object-field/lifetime or store-order evidence; three
 * meaningful forms now give identical bytes.
 */

#include "common.h"

typedef int TI128 __attribute__((mode(TI)));

extern int func_0029EFD0(int);
extern f32 func_002A7940(void);
extern void func_00283360(void *);
extern void func_L22_003FBBF0(void *);
extern int D_L22_001AF37C;

char *func_L22_003FB1F8(char *obj, TI128 *pos, int arg3, f32 f) {
    char *o = (char *)func_0029EFD0(0xE3A);
    if (o != 0) {
        u8 *ctl = *(u8 **)(o + 0x68);
        *(short *)(ctl + 0x2A) = arg3;
        if ((short)arg3 != 0) {
            int c = D_L22_001AF37C;
            D_L22_001AF37C = c + 1;
            *(u16 *)(o + 0x96) = (c + 2) % 31;
        }
        *(u16 *)(o + 0x32) = 0x50;
        *(u16 *)(o + 0x34) |= 0x108;
        *(u8 *)(o + 0x30) = 0xFF;
        *(u8 *)(o + 0x31) = 1;
        *(u8 *)(o + 0x20) = 0;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u32 *)(o + 0x24) + 0x24) * f;
        *(u32 *)(ctl + 0x20) = (u32)obj;
        *(f32 *)(ctl + 0x4C) = func_002A7940();
        qcopy(o + 0x10, pos);
        *(u16 *)(o + 0x34) |= 0x41;
        func_00283360(o + 0xC0);
        func_L22_003FBBF0(o);
    }
    return o;
}
