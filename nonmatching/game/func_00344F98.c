/* from src/game/00344848.c: 240 bytes, retail's size (tools/check.py: 0 of 28 places).
   The first difference is in the prologue at +0x10: this cc1 saves $s2 there and retail saves $s1,
   so the callee-saved registers are assigned to the frame's values in another order, and the gp values
   and object pointers sit in other registers from there on (36 of 60 listing lines differ).
   Tried on func_00344F98: the stores in retail's order with the pointers inline (the form in these drafts), the same
   with the pointers hoisted into locals (37 lines differ), and ascending index order (248 bytes).
   The three siblings in the same unit have the same shape and differ from this one in the table address,
   the mode test and the gp offsets (func_00345268 also in the roles of two saved registers).
   Needs a -G8 unit (the file name gives -G8): the gp-relative symbols carry __attribute__((sda)). */

extern char D_L00_0025E328[];
extern int D_L04_001AE304 __attribute__((sda));
extern int D_L04_001AE308 __attribute__((sda));
extern int D_L04_001AE310 __attribute__((sda));
extern int D_L04_001AE318 __attribute__((sda));
extern int D_L04_001AE320 __attribute__((sda));
extern int D_L04_001AE328 __attribute__((sda));
extern int D_L04_001AE330 __attribute__((sda));

void func_00344F98(char *o)
{
    int f[23];

    f[19] = *(int *)(o + 0x444);
    f[1] = D_L04_001AE304;
    f[18] = *(int *)(o + 0x430);
    f[5] = (int)&D_L04_001AE310;
    f[22] = 1;
    f[21] = *(int *)(o + 0x448) == 2;
    f[3] = *(int *)(o + 0x43C);
    f[4] = *(int *)(o + 0x440);
    f[9] = (int)&D_L04_001AE330;
    f[2] = D_L04_001AE308;
    f[0] = (int)D_L00_0025E328;
    f[17] = (int)(o + 0x210);
    f[10] = (int)(o + 0x130);
    f[12] = (int)(o + 0x17C);
    f[15] = (int)(o + 0x258);
    f[8] = (int)&D_L04_001AE328;
    f[7] = (int)&D_L04_001AE320;
    f[6] = (int)&D_L04_001AE318;
    f[16] = 0;
    f[14] = 0;
    f[11] = 0;
    f[13] = 0;
    f[20] = 0;
    func_00337210(f);
}
