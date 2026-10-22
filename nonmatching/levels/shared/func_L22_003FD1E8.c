/* from src/levels/shared/L22_003A5018.c: C that compiles but does not link at its places yet */
/* Spawns the object of kind 0xE3D, arms it with the slot number and the scale factor, and
 * copies the position into it.  The slot number is a 16 bit quantity: the counter of the
 * spawned objects only advances for a slot that is not zero.
 *
 * The retail body of this function is the body of func_L22_003FC780 with the object kind
 * 0xE3D instead of 0xE3B.  The candidate is 232 bytes against the retail's 240, and it
 * differs in the same two places: the controller pointer is in $a3 where the retail has it in
 * $a2, and the counter's address is materialised once, in $a2, where the retail
 * rematerialises it (the load takes its base from the destination register and the store's
 * address is a fresh `lui $at`).
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
extern void func_00283360(void *);
extern int D_L22_001AF37C;

char *func_L22_003FD1E8(char *obj, TI128 *pos, int arg3, f32 f) {
    char *o = (char *)func_0029EFD0(0xE3D);
    if (o != 0) {
        u8 *ctl = *(u8 **)(o + 0x68);
        *(short *)(ctl + 0x2A) = arg3;
        if ((short)arg3 != 0) {
            int c = D_L22_001AF37C;
            D_L22_001AF37C = c + 1;
            *(u16 *)(o + 0x96) = (c + 2) % 31;
        }
        *(u16 *)(o + 0x34) |= 0x108;
        *(u8 *)(o + 0x30) = 0xFF;
        *(u16 *)(o + 0x32) = 0x50;
        *(u8 *)(o + 0x31) = 1;
        *(u8 *)(o + 0x20) = 0;
        *(f32 *)(o + 0x2C) = *(f32 *)(*(u32 *)(o + 0x24) + 0x24) * f;
        *(u32 *)(ctl + 0x20) = (u32)obj;
        *(TI128 *)(o + 0x10) = *pos;
        func_00283360(o + 0xC0);
    }
    return o;
}
