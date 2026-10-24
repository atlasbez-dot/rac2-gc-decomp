/* Complete manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections.
 * us: 0/28 placements; exit 1.
 * us2: 0/28 placements; exit 1.
 * pal: 0/28 placements; exit 1.
 * USA compiled 940 bytes; retail 912 bytes.
 * The 56-key, three-channel scans differ in saved registers, repeated base materialization and switch layout. Reopen with a measured declaration/lifetime hypothesis for the mapped-class base, preserving all three switches.
 */

extern unsigned char D_00139568[], D_001A7AB8[], D_001A7AF8[], D_001A7A80[];
extern char D_00239BA0[], D_0021F240[];
extern int func_002F7320(int owner, int key, int channel);
extern int func_00288D58(void);

extern int D_001A79F0;

void func_002F73A8(void)
{
    int key, channel, available;
    char *entry;
    *(int *)(D_0021F240 + 0x740) = 0;
    for (key = 0; key < 56; key++) {
        if (*(int *)(D_00239BA0 + D_00139568[key] * 224) != 0) {
            for (channel = 0; channel < 3; channel++) {
                if (func_002F7320(D_001A79F0, key, channel) == 0) {
                    switch (channel) {
                    case 0: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x98); break;
                    case 1: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x9C); break;
                    case 2: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0xA0); break;
                    default: available = 0; break;
                    }
                    if (available && func_00288D58())
                        D_001A7AB8[key] |= 1 << channel;
                }
            }
        }
    }
    for (key = 0; key < 56; key++) {
        if (key == 0) continue;
        if (*(int *)(D_00239BA0 + D_00139568[key] * 224) == 0) continue;
        if (D_001A7AF8[key] == 0) continue;
        for (channel = 0; channel < 3; channel++) {
            if (!(D_001A7AB8[key] & (1 << channel))) continue;
            switch (channel) {
            case 0: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x98); break;
            case 1: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x9C); break;
            case 2: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0xA0); break;
            default: available = 0; break;
            }
            if (!available) continue;
            if (D_001A7A80[key] & (unsigned char)(1 << (channel * 2))) continue;
            *(int *)(D_0021F240 + 0x140 + *(int *)(D_0021F240 + 0x740) * 16) = channel;
            switch (channel) {
            case 0: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x98); break;
            case 1: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0x9C); break;
            case 2: available = *(int *)(D_00239BA0 + D_00139568[key] * 224 + 0xA0); break;
            default: available = 0; break;
            }
            *(int *)(D_0021F240 + 0x148 + *(int *)(D_0021F240 + 0x740) * 16) = available;
            entry = D_00239BA0 + D_00139568[key] * 224;
            *(int *)(D_0021F240 + 0x144 + *(int *)(D_0021F240 + 0x740) * 16) = key;
            *(int *)(D_0021F240 + 0x14C + *(int *)(D_0021F240 + 0x740) * 16) = *(int *)(entry + 0x14);
            ++*(int *)(D_0021F240 + 0x740);
        }
    }
}
