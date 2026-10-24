/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 772 / 856 bytes; size equality is not a match.
 * us: 0/28 placements; 772/856 bytes.
 * us2: not run after us mismatch; no exact candidate.
 * pal: not run after us mismatch; no exact candidate.
 * Residual: The initial store to mode+0x50 is real and precedes a 20-case dispatch; the old compiler retains switch bodies in plain C. This is not sufficient boundary evidence. Input/timer scheduling and the case layout differ.
 * Reopening condition: Qualify the complete neighborhood and indirect table at boot0x0026CDF0 before any boundary change; otherwise recover the original mode/timer source shape.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Not matched. boot: 772 bytes, expected 856.
 * Profile: -O2 -G8 -ffunction-sections
 * The initial store to mode+0x50 is real and precedes a 20-case dispatch; the old compiler retains switch bodies in plain C. This is not sufficient boundary evidence. Input/timer scheduling and the case layout differ.
 * Reopen: Qualify the complete neighborhood and indirect table at boot0x0026CDF0 before any boundary change; otherwise recover the original mode/timer source shape.
 * US placement check: 0/28. No linked-build or runtime claim.
 */
#include "common.h"
extern u8 D_00138180[],D_001F2840[],D_00261A08[],D_00261AB8[],D_00261B78[];
extern u8 D_001ABBA0[] __attribute__((sda));
extern u8 D_001ABBB8[] __attribute__((sda));
extern int D_0025ED8C;
int func_002DC3C8(u8 *menu)
{
    int fast,previous,value;
    u8 *owner;
    *(int *)(menu+0x50)=0;
    fast=(*(u64 *)(D_00138180+0x1c0)&15)==15;
    if (!*(int *)(D_001F2840+0xec) || (fast && (*(u32 *)(D_00138180+0x1c0)&16))) {
        if ((*(u32 *)(D_00138180+0x1c4)&0x900) && !*(int *)(D_001F2840+0x134)) return 1;
        if (*(u32 *)(D_00138180+0x1c4)&16) {
            owner=*(u8 **)(D_001F2840+0x14);value=*(int *)(owner+0xe0);
            if (value || *(int *)(D_001F2840+0x134)) {if (!value) value=*(int *)(D_001F2840+0x18);*(int *)(D_001F2840+0x18)=value;return 0;}
            return -1;
        }
    }
    previous=*(int *)(menu+0x40);
    *(int *)(menu+0x40)=previous-1;if (fast) *(int *)(menu+0x40)=previous-2;
    if (*(int *)(menu+0x40)<0) *(int *)(menu+0x40)=0;
    switch (*(int *)(menu+0x50)) {
    case 0:
        ++*(int *)(menu+0x50);*(int *)(menu+0x40)=180;*(int *)(menu+0x3c)=0;
        D_0025ED8C=0x33c0;*(u8 **)(menu+0x34)=D_00261A08;break;
    case 1:case 5:case 8:case 12:case 16:
        if (*(int *)(menu+0x40)) return 0;
        *(int *)(menu+0x54)=0;++*(int *)(menu+0x50);break;
    case 2:case 6:case 9:case 13:case 17:
        previous=*(int *)(menu+0x3c);*(int *)(menu+0x3c)=previous+10;
        if (fast) *(int *)(menu+0x3c)=previous+20;
        if (*(int *)(menu+0x54)) {*(int *)(menu+0x40)=180;++*(int *)(menu+0x50);}break;
    case 3:
        if (*(int *)(menu+0x40)) return 0;
        D_0025ED8C=0x340e;*(int *)(menu+0x34)=0x340f;*(int *)(menu+0x40)=240;
        *(int *)(menu+0x3c)=0;++*(int *)(menu+0x50);break;
    case 4:
        if (*(int *)(menu+0x40)) return 0;
        *(int *)(menu+0x50)=5;*(int *)(menu+0x40)=180;*(int *)(menu+0x3c)=0;
        D_0025ED8C=0x3410;*(u8 **)(menu+0x34)=D_00261AB8;break;
    case 7:
        if (*(int *)(menu+0x40)) return 0;
        D_0025ED8C=0x3458;*(u8 **)(menu+0x34)=D_00261B78;*(int *)(menu+0x40)=240;
        ++*(int *)(menu+0x50);*(int *)(menu+0x3c)=0;break;
    case 10:
        if (*(int *)(menu+0x40)) return 0;
        D_0025ED8C=0x3488;*(int *)(menu+0x34)=0x3489;*(int *)(menu+0x40)=240;
        *(int *)(menu+0x3c)=0;++*(int *)(menu+0x50);break;
    case 11:
        if (*(int *)(menu+0x40)) return 0;
        *(int *)(menu+0x3c)=0;*(int *)(menu+0x40)=180;D_0025ED8C=0x348a;
        *(int *)(menu+0x50)=12;*(u8 **)(menu+0x34)=D_001ABBA0;break;
    case 14:
        if (*(int *)(menu+0x40)) return 0;
        D_0025ED8C=0;*(int *)(menu+0x34)=0x349b;*(int *)(menu+0x40)=240;
        *(int *)(menu+0x3c)=0;++*(int *)(menu+0x50);break;
    case 15:
        if (*(int *)(menu+0x40)) return 0;
        *(int *)(menu+0x3c)=0;*(int *)(menu+0x40)=180;D_0025ED8C=0x349d;
        *(int *)(menu+0x50)=16;*(u8 **)(menu+0x34)=D_001ABBB8;break;
    case 18:
        if (*(int *)(menu+0x40)) return 0;
        D_0025ED8C=0;*(int *)(menu+0x40)=300;*(int *)(menu+0x34)=0;++*(int *)(menu+0x50);break;
    case 19:
        if (*(int *)(menu+0x40)) return 0;
        if (*(int *)(D_001F2840+0xec)) return 1;
    }
    return 0;
}
