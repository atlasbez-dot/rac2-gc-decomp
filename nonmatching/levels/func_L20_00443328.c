/* near-miss: func_L20_00443328 (20_yeedil, 136 bytes).
   Same size as retail, but this cc1 loads D_L20_001B2F9C through `lui $v1` + `lw $a1`
   and takes the state pointer in `$a0`, where retail keeps them in `$a0`/`$v1`; the
   `if (... == 0) return 0;` arm also lays out as a `beqz` fall-through where retail
   gives the empty arm its own `b` over the block (the func_00116300 wall). */
#include "common.h"

extern char *D_L20_001B2F9C;
extern s32 func_L03_003CA138(char *);
extern s32 func_L20_004499E8(char *, char *, char *);
extern void func_L20_0039BDF0(char *, char *, s32, s32);

char *func_L20_00443328(char *arg0, char *arg1)
{
    char *state = *(char **)(arg0 + 0x68);
    char *p = D_L20_001B2F9C + (*(s32 *)(state + 0x238) << 8);

    if (func_L03_003CA138(p) == 0)
        return 0;
    func_L20_004499E8(p, arg0, arg1);
    func_L20_0039BDF0(p, p + 0x10, 0x168, 0);
    return p;
}
