/* Nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 16_snivelak: 404 bytes, expected 412.
   us2: 16_snivelak: 404 bytes, expected 412.
   pal: 16_snivelak: 404 bytes, expected 412.
   The trigger loops and retail repeated st[4] lookup are reconstructed. The switch dispatch and mixed absolute/GP object base still differ. Reopen with matching switch dispatch and natural mixed object-base accesses. */
typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern char *D_L16_001B2B1C __attribute__((sda));
extern char D_00189EA0[];
extern s32 func_002ACBC8(char *, s32);
extern s32 func_002A8508(s32, s32);
extern void func_002A7750(char *, s32, s32);

/* Releases the linked objects after either trigger condition has completed. */
void func_L16_0041C990(char *self) {
    s32 *st = *(s32 **)(self + 0x68);
    s32 *ids;
    s32 i;
    char *object;
    u8 state;
    switch (*(u8 *)(self + 0x20)) {
    case 0:
        if (st[1] == -1) {
            if (st[2] == -1) func_002A7750(self, 4, -1);
            else func_002A7750(self, 2, -1);
        } else func_002A7750(self, 1, -1);
        break;
    case 1:
        object = D_L16_001B2B1C + st[0] * 256;
        if (object) {
            state = *(u8 *)(object + 0x20);
            if (state != 254 && state != 253) break;
        }
        if (!func_002ACBC8(D_00189EA0, st[1])) break;
        for (ids = st + 4, i = 7; i >= 0; i--, ids++) {
            if (*ids != -1) {
                object = D_L16_001B2B1C + *ids * 256;
                if (*(s16 *)(object + 0xAA) == 0xEA3)
                    *(s32 *)(*(char **)(object + 0x68) + 0x24C) = 1;
                else *(u8 *)(object + 0xBC) = 1;
            }
        }
        func_002A7750(self, 4, -1);
        break;
    case 2:
        if (func_002A8508(st[2], -1)) break;
        for (ids = st + 4, i = 7; i >= 0; i--, ids++) {
            if (*ids != -1) {
                object = D_L16_001B2B1C + st[4] * 256;
                if (*(s16 *)(object + 0xAA) == 0xEA3)
                    *(s32 *)(*(char **)(object + 0x68) + 0x24C) = 1;
                else *(u8 *)(object + 0xBC) = 1;
            }
        }
        func_002A7750(self, 4, -1);
        break;
    case 3:
    case 4:
    default:
        break;
    }
}
