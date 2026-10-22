/* from src/levels/11_joba/L11_003D6270-g8.c: C that compiles but does not match yet */
/* Sets the object's state up from its measured values and walks the two points it aims
   at. Needs the -g8 profile (the 16.0 and 0.4 factors are reached through $gp) and a
   -g8.c source unit when checked again.

   The candidate is retail's exact size and every instruction but the seven of the block
   that reads the object's pointer and stores the two measured values: retail hoists the
   pointer load and the value load to the top of the block (`lw $v1,0x24($s0)`,
   `lhu $v0,0x34($s0)`, `lw $a3,0x10($v1)`) and keeps the byte store of 0x31 between the
   `andi` and the halfword store, where this cc1 floats the byte store to the front of the
   block and sinks the pointer load. */
extern int func_002B3380(char *, char *, char *);

extern f32 func_00283180(f32 a0);

extern f32 func_00283198(f32 a0);

extern f32 func_00283B98(f32 a0, f32 a1);

extern void func_002833F0(void *a0, void *a1);

extern u8 *func_L11_004417E8(s32 a0);

extern f32 D_L11_001B0158 __attribute__((sda));

extern f32 D_L11_001B0140 __attribute__((sda));

void func_L11_003F2F38(u8 *arg0) {
    u8 *s0 = arg0;
    u8 *s1 = *(u8 **)(s0 + 0x68);
    u8 *v1;
    f32 f20;

    *(f32 *)(s1 + 0x20) = (f32)*(s16 *)(s1 + 0x24);
    v1 = *(u8 **)(s0 + 0x24);
    *(u16 *)(s0 + 0x34) &= 0xFFFE;
    *(u8 *)(s0 + 0x31) = 1;
    *(u32 *)(s0 + 0x98) = *(u32 *)(v1 + 0x10);
    *(u8 *)(s1 + 0x2E) = 1;
    *(u8 *)(s0 + 0x7F) = 0;
    *(u16 *)(s0 + 0x34) = (*(u16 *)(s0 + 0x34) & 0xFFB9) | 0x1000;
    *(s32 *)(s1 + 0x60) = 0;
    func_002B3380((char *)s0, (char *)(s1 + 0x50), (char *)(s1 + 0x20));
    if (*(s16 *)(s1 + 0x70) != 0) {
        *(s16 *)(s1 + 0x70) = 0;
        func_002A0488(s0, *(u32 *)(s1 + 0x280), *(u32 *)(s1 + 0x284),
                      *(u32 *)(s1 + 0x288));
        *(s16 *)(s1 + 0x72) = 1;
    }
    func_002A7750(s0, 2, 2);
    *(s32 *)(s1 + 0x250) = 0;
    f20 = func_00283180(*(f32 *)(s1 + 0x250));
    v1 = func_L11_004417E8(*(s32 *)(s0 + 0xB8));
    *(f32 *)(s0 + 0x10) = D_L11_001B0158 * f20 + *(f32 *)v1;
    f20 = func_00283198(*(f32 *)(s1 + 0x250));
    v1 = func_L11_004417E8(*(s32 *)(s0 + 0xB8));
    *(f32 *)(s0 + 0x18) = D_L11_001B0140;
    *(f32 *)(s0 + 0xF4) = -1.5707964f;
    *(s32 *)(s0 + 0xF0) = 0;
    *(f32 *)(s0 + 0x14) = D_L11_001B0158 * f20 + *(f32 *)(v1 + 4);
    *(f32 *)(s0 + 0xF8) = func_00283B98(3.1415927f, *(f32 *)(s1 + 0x250));
    func_002833F0(s0 + 0xC0, s0 + 0xF0);
}
