/* Mid worker 19 near miss (func_L08_0040E9B8).
   Profile: -O2 -G8 -ffunction-sections -mno-split-addresses (the body below was last checked in a -G8 unit without it; the nosda attribute is only needed with it).
   Status: 3-state switch complete; with -O2 -G8 -ffunction-sections -mno-split-addresses and nosda scalars for the plain globals the prologue and the lui $at stores match; left: D_1BFD00 is built as lui $v0 / addiu $s1,$v0 (split) in retail but lui $s1 / addiu $s1 here, two $v0/$v1 picks, and the schedule of the entry-table load. */
extern void func_0029F338(void *);
extern void func_002A7750(void *, s32, s32);
extern float func_00283B98(float, float);
extern u8 D_001A7B0D[];
extern u8 D_L08_001BFD00[];
extern s32 D_L08_001A8F00 __attribute__((sda));
extern s32 D_L08_001B2728;
extern u8 *D_L08_001B2ACC;
extern s32 func_002ACBC8(void *, s32);
extern s32 func_00288AA0(void *, s32);
extern void func_00288BE8(void *);
extern void func_L01_003CEB00(u8 *);
extern s32 func_002F5D10(void);
extern void func_L00_002B9D60(u8 *, u8 *, s32, s32);
extern void func_00288308(s32);
extern void func_002B0A18(s32, s32);
extern void func_0029B3E0(s32, s32);

void func_L08_0040E9B8(u8 *self) {
    u8 *st = *(u8 **)(self + 0x68);
    u8 *ent;

    switch (self[0x20]) {
    case 0:
        if (D_001A7B0D[0] != 0) {
            func_0029F338(self);
            break;
        }
        *(float *)(self + 0x18) = *(float *)(self + 0x18) + 0.75f;
        *(float *)(self + 0x2C) = *(float *)(*(u8 **)(self + 0x24) + 0x24) * 1.5f;
        func_002A7750(self, 1, -1);
        break;
    case 1:
        *(float *)(self + 0xF8) = func_00283B98(*(float *)(self + 0xF8), 0.07853982597589493f);
        if (func_002ACBC8(D_00189EA0, *(s32 *)(st + 4)) != 0) {
            if (func_00288AA0(D_L08_001BFD00, 0x5B) != 0) {
                func_00288BE8(D_L08_001BFD00);
                self[0x20] = 2;
            }
        }
        if (self[0x31] != 0)
            func_L01_003CEB00(self);
        break;
    case 2:
        D_L08_001B2728 = 1;
        if (D_L08_001A8F00 == 2) {
            self[0x31] = 0;
            *(u16 *)(self + 0x34) |= 1;
        }
        if (func_002F5D10() != 0)
            break;
        D_L08_001B2728 = 0;
        self[0x31] = 1;
        *(u16 *)(self + 0x34) &= 0xFFFE;
        ent = D_L08_001B2ACC + *(s32 *)(st + 8) * 0x80;
        func_L00_002B9D60(ent + 0x30, ent + 0x70, 0, 1);
        func_00288308(0x15);
        func_002B0A18(0x122B, -1);
        func_0029B3E0(0, -1);
        func_0029F338(self);
        break;
    }
}
