/* from src/game/00344848.c: 240 bytes, retail's size (tools/check.py: 0 of 28 places).
   The first difference is in the prologue at +0x10, as in func_00344F98: the callee-saved registers
   are assigned to the frame's values in another order, and the gp values and object pointers sit in
   other registers from there on (36 of 60 listing lines differ).
   Tried on func_00344F98: the stores in retail's order with the pointers inline (the form in these drafts), the same
   with the pointers hoisted into locals (37 lines differ), and ascending index order (248 bytes).
   Needs a -G8 unit (the file name gives -G8): the gp-relative symbols carry __attribute__((sda)). */

extern char D_001AA830[];
extern int D_L04_001AE338 __attribute__((sda));
extern int D_L04_001AE33C __attribute__((sda));
extern int D_L04_001AE340 __attribute__((sda));
extern int D_L04_001AE348 __attribute__((sda));
extern int D_L04_001AE350 __attribute__((sda));
extern int D_L04_001AE358 __attribute__((sda));
extern int D_L04_001AE360 __attribute__((sda));

void func_00345088(char *o)
{
    int f[23];

    f[19] = *(int *)(o + 0x444);
    f[1] = D_L04_001AE338;
    f[18] = *(int *)(o + 0x430);
    f[5] = (int)&D_L04_001AE340;
    f[22] = 1;
    f[21] = *(int *)(o + 0x448) == 1;
    f[3] = *(int *)(o + 0x43C);
    f[4] = *(int *)(o + 0x440);
    f[9] = (int)&D_L04_001AE360;
    f[2] = D_L04_001AE33C;
    f[0] = (int)D_001AA830;
    f[17] = (int)(o + 0x210);
    f[10] = (int)(o + 0x130);
    f[12] = (int)(o + 0x17C);
    f[15] = (int)(o + 0x258);
    f[8] = (int)&D_L04_001AE358;
    f[7] = (int)&D_L04_001AE350;
    f[6] = (int)&D_L04_001AE348;
    f[16] = 0;
    f[14] = 0;
    f[11] = 0;
    f[13] = 0;
    f[20] = 0;
    func_00337210(f);
}
