/* Retained C, not matched.
   Profile: -O2 -G0 -ffunction-sections -fno-strength-reduce.
   180/192 bytes; 0/27 on USA/PAL/US2. Signed ascending counter retained with -fno-strength-reduce; pointer alias/store allocation and three branch words still differ. Unsigned ascending and nested-guard forms were also measured. */

typedef unsigned char u8;
typedef unsigned int u32;
typedef signed int s32;

typedef struct {
    u32 field00, field04;
    s32 field08;
    u8 gap0c[4];
} OrbitalPairTableView16;

extern u8 D_L00_00231340[];
extern int func_00282948(void *p);

void func_L00_0037E000(u32 a0)
{
    OrbitalPairTableView16 *entry = (OrbitalPairTableView16 *)D_L00_00231340;
    int i;

    for (i = 0; i < 32; i++, entry++) {
        if (entry->field04 == a0) {
            u8 *p = (u8 *)entry->field00;

            if ((*(unsigned short *)(p + 0x34) & 0x1000) == 0 || p == 0
                || *(u8 *)(p + 0x20) == 0xFE || *(u8 *)(p + 0x20) == 0xFD
                || func_00282948((char *)entry + 8) != 0) {
                entry->field04 = 0;
            }
        }
    }
}
