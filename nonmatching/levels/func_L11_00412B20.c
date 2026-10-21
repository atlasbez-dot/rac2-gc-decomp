/* from src/levels/11_joba/L11_003D6270-g8.c: C that compiles but does not match yet */
/* Arms the object's state record, then reports the two measured values the engine asks
   for and resets the record's two timers. Needs the -g8 profile (the level's counter is
   reached through $gp) and a -g8.c source unit when checked again.

   The byte and word flags are read through their absolute addresses because retail
   loads them into the address register itself (`lui $v0,0x1A; lbu $v0,0x7B00($v0)`),
   which only a literal address produces; the halfword flags stay named symbols, which
   keep the load in its own register. */
extern void func_L01_002EABA8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

extern s32 func_002ACBC8(void *a0, void *a1);

extern s32 func_00282948(void *a0);

extern void func_00288E18(s32 a0, s32 a1);

extern u16 D_0018CD60 NOT_SDA;

extern u16 D_00194158 NOT_SDA;

extern u16 D_0018D048 NOT_SDA;

extern s32 D_L11_001B30C8 __attribute__((sda));

extern u8 D_00189EA0[];

void func_L11_00412B20(u8 *arg0) {
    u8 *s0 = *(u8 **)(arg0 + 0x68);

    if (*(u8 *)(arg0 + 0x20) == 0) {
        *(u8 *)(arg0 + 0x20) = 1;
        *(u8 *)(arg0 + 0x30) = 0xFF;
        *(s32 *)(s0 + 0x8) = 0x1A4;
        *(s32 *)(s0 + 0x10) = 0x12C;
    }
    if (*(u8 *)(arg0 + 0x20) != 1) {
        return;
    }
    if (*(u8 *)0x1A7B00) {
        func_L01_002EABA8(0x9FF, 0x56, 3, *(s32 *)(s0 + 0x4), -1);
    }
    if (*(s32 *)0x1A9010 != 0 && D_L11_001B30C8 >= 3) {
        D_0018CD60 = 0xFFFF;
    }
    if (func_002ACBC8(D_00189EA0, *(s32 *)(s0 + 0x0)) != 0) {
        if (func_00282948(s0 + 0x8) != 0) {
            if (D_00194158 == 0) {
                func_00288E18(0xA00, 0x57);
                *(s32 *)(s0 + 0x8) = 0x1A4;
            }
        }
    }
    if (*(u8 *)0x1A7B2E) {
        func_L01_002EABA8(0xA03, 0x5A, 0, *(s32 *)(s0 + 0xC), -1);
    }
    if (*(u8 *)0x1A7B0B) {
        if (D_0018D048 == 0) {
            if (func_00282948(s0 + 0x10) != 0) {
                func_00288E18(0xA3D, 0x94);
            }
        }
    }
}
