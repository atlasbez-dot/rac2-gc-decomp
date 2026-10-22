/* from src/levels/shared/L22_003A5018.c: C that compiles but does not link at its places yet */
/* Spawns the object of kind 0xE3A, arms it with the slot number and the scale factor, and
 * copies the position into it.  The slot number is a 16 bit quantity: the counter of the
 * spawned objects only advances for a slot that is not zero.
 *
 * The candidate is 268 bytes against the retail's 276, and it differs in two places:
 *   - the counter's address is materialised once, in $a2, and used by both the load and the
 *     store, where the retail rematerialises it: the load takes its base from the
 *     destination register ($v0) and the store's address is a fresh `lui $at`, and
 *   - the store of the 0x34 mask and the store of the 0x32 halfword are in another order
 *     than the retail's (retail: 0x32, 0x34, 0x30, 0x31, 0x20; this cc1: 0x32, 0x34, 0x30,
 *     0x31, 0x20 with the 0x34 store after the 0x32 one).
 * The statement orders tried here (counter first, remainder first, remainder in a local, the
 * counter through a pointer, the counter volatile) do not change the address.
 *
 * The 16 bit slot test is `(short)arg3` and the copy is a TImode assignment, so the unit
 * needs the -frac2-qcopy profile of src/levels/shared/L22_003A5018-g8.c.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
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
        *(TI128 *)(o + 0x10) = *pos;
        *(u16 *)(o + 0x34) |= 0x41;
        func_00283360(o + 0xC0);
        func_L22_003FBBF0(o);
    }
    return o;
}
