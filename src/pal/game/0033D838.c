#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_0033D838);

extern void Ffb202470_FUN_0033AB50(char *p);

char *func_PAL_0033DC60(char *object)
{
    Ffb202470_FUN_0033AB50(object + 8);
    return object;
}

INCLUDE_ASM("asm/pal/game", func_PAL_0033DC98);

INCLUDE_ASM("asm/pal/game", func_PAL_0033DDC0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033DF90);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E000);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E038);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E160);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E248);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E300);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E338);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E460);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E608);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E888);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E8C0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033E9E8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033EAF0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033EC50);

INCLUDE_ASM("asm/pal/game", func_PAL_0033EC98);

INCLUDE_ASM("asm/pal/game", func_PAL_0033EEF8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F190);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F310);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F348);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F470);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F508);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F5D8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F610);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F738);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F840);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F9A0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033F9D8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FB00);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FBE0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FC98);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FCD0);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FDF8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FED8);

INCLUDE_ASM("asm/pal/game", func_PAL_0033FF10);

INCLUDE_ASM("asm/pal/game", func_PAL_00340038);

INCLUDE_ASM("asm/pal/game", func_PAL_00340118);

INCLUDE_ASM("asm/pal/game", func_PAL_00340158);

INCLUDE_ASM("asm/pal/game", func_PAL_003402B8);

INCLUDE_ASM("asm/pal/game", func_PAL_003402F0);

INCLUDE_ASM("asm/pal/game", func_PAL_00340310);

INCLUDE_ASM("asm/pal/game", func_PAL_00340348);

INCLUDE_ASM("asm/pal/game", func_PAL_00340418);

INCLUDE_ASM("asm/pal/game", func_PAL_00340470);

INCLUDE_ASM("asm/pal/game", func_PAL_003404B0);

INCLUDE_ASM("asm/pal/game", func_PAL_003405B0);

void func_0033AF48(int);

void func_PAL_00340610(int param_1) {
  func_0033AF48(param_1 + 8);
}

extern void func_0033AB50_1(void *);
extern void func_L00_0042BFF8(void *);
extern void func_L00_0042C290(void *);
extern void func_L00_0042BAD0(void *);

/* Calls twelve sub-object handlers in sequence, each with the object base plus a fixed byte offset (8, 684, 744, 816, 888, 960, 1040, 1112, 1184, 1256, 1328, 1400), then returns the object pointer. */
char *func_PAL_00340630(char *object)
{
    func_0033AB50_1(object + 8);
    func_L00_0042BFF8(object + 732);
    func_L00_0042C290(object + 792);
    func_L00_0042C290(object + 880);
    func_L00_0042C290(object + 968);
    func_L00_0042BAD0(object + 1056);
    func_L00_0042C290(object + 1136);
    func_L00_0042C290(object + 1224);
    func_L00_0042C290(object + 1312);
    func_L00_0042C290(object + 1400);
    func_L00_0042C290(object + 1488);
    func_L00_0042C290(object + 1576);
    return object;
}

INCLUDE_ASM("asm/pal/game", func_PAL_003406C0);

INCLUDE_ASM("asm/pal/game", func_PAL_00340A50);

INCLUDE_ASM("asm/pal/game", func_PAL_00340C88);

INCLUDE_ASM("asm/pal/game", func_PAL_00340D78);

INCLUDE_ASM("asm/pal/game", func_PAL_00341020);

INCLUDE_ASM("asm/pal/game", func_PAL_00341090);

INCLUDE_ASM("asm/pal/game", func_PAL_00341208);
