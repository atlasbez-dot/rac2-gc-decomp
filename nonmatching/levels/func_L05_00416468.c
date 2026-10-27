/* Near-miss twins: 408 bytes, expected 424, 0 of 1 place (level 05 feltzin).
 *
 * Profile: -O2 -G8 -ffunction-sections.
 * Last verdict: `python scratch/wslcmp.py src/levels/05_feltzin_system/L05_00314E28-g8.c func_L05_00416468`
 *   func_L05_00416468: 0 of 1 places match   [05_feltzin_system: 408 bytes, expected 424]
 *
 * Remaining difference: the two fade constants.  Retail hoists 0.35f and
 * 0.08f into the saved FP registers $f21/$f20 once; this cc1 treats them as
 * rematerialisable constants and rebuilds them with lui/ori/mtc1 at every use
 * (two extra pairs and no FP saves, hence 16 bytes short).  Naming both as
 * float locals did not stop the rematerialisation.  The record walk, the six
 * blend calls and the loop counter match.
 */
/* The two ring records a boss prop keeps (0x80 slots of 0x50 bytes): for every
   slot that belongs to the prop, blend two source blocks and lay down four
   blended quads.  The two bodies differ only in the record table, the packet
   source and the blend routine. */
void func_L05_00416468(char *obj)
{
    char *base = D_L05_002659E0;
    char *low = base + 0x10;
    char *high = base + 0x30;
    float close = 0.08f;
    float far = 0.35f;
    int i = 0;

    do {
        float v;

        i++;
        if (*(char **)(high + 0x10) != obj)
            break;
        func_L05_00416698(base, low, 0x807F7F7F, (void *)D_L05_001B0F48, 0.025f);
        func_L05_00416698(base, low, 0x60008000, (void *)D_L05_001B0F48, 0.05f);
        v = func_002A7940();
        func_00281EB8(high, 0x31, 0x60008000, 1, 1.35f, far, v);
        v = func_002A7940();
        func_00281EB8(high, 0x31, 0x807F7F7F, 1, 1.0f, far, v);
        v = func_002A7940();
        func_00281EB8(low, 0x31, 0x60008000, 1, 0.125f, close, v);
        v = func_002A7940();
        func_00281EB8(low, 0x31, 0x807F7F7F, 1, close, close, v);
        base += 0x50;
        low += 0x50;
        high += 0x50;
    } while (i < 0x80);
}

void func_L05_0041CFE8(char *obj)
{
    char *base = D_L05_002681E0;
    char *low = base + 0x10;
    char *high = base + 0x30;
    float close = 0.08f;
    float far = 0.35f;
    int i = 0;

    do {
        float v;

        i++;
        if (*(char **)(high + 0x10) != obj)
            break;
        func_L05_0041D218(base, low, 0x807F7F7F, (void *)D_L05_001B1340, 0.025f);
        func_L05_0041D218(base, low, 0x60008000, (void *)D_L05_001B1340, 0.05f);
        v = func_002A7940();
        func_00281EB8(high, 0x31, 0x60008000, 1, 1.35f, far, v);
        v = func_002A7940();
        func_00281EB8(high, 0x31, 0x807F7F7F, 1, 1.0f, far, v);
        v = func_002A7940();
        func_00281EB8(low, 0x31, 0x60008000, 1, 0.125f, close, v);
        v = func_002A7940();
        func_00281EB8(low, 0x31, 0x807F7F7F, 1, close, close, v);
        base += 0x50;
        low += 0x50;
        high += 0x50;
    } while (i < 0x80);
}

