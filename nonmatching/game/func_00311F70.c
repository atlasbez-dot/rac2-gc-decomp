/* func_00311F70 (340 bytes, boot; unit src/game/0030F7B0.c, -O2 -G0).
   26 October 2026 (M32): 348/340. Body, calls and the shared stack word (the type whose
   address func_002A68A8 takes) agree. Left: retail's switch tree tests ==4 first, then <5
   (this cc1 picks 8 as the pivot of 4/8/9); the difficulty split (retail slti 21 then
   slti 11 with movz); the piece loop's entry test is on the call result (blez ) before
   the copy to . */
extern int D_001AF0FC[] __attribute__((sda));
extern int func_002A77E0(int);
extern void func_002A6C58(void *, int, int);
extern int func_002A68A8(void *, int *);
extern void func_003202E8(void *, int, int, int);

/* Destroys the object: an intact one (vars +0xC6 clear, not class 0x1F5 or 0x200)
   just plays one of the hit sounds picked by the difficulty word; otherwise the
   explosion type follows the vars' kind byte and func_002A68A8 says how many
   pieces to spawn. */
void func_00311F70(char *object)
{
    char *vars = *(char **)(object + 0x68);
    int type;
    int n;
    int k;
    int lvl;

    type = *(short *)(vars + 0xC6) == 0;
    if (*(short *)(object + 0xAA) == 0x1F5 || *(short *)(object + 0xAA) == 0x200)
        type = 0;
    if (type != 0) {
        lvl = D_001AF0FC[0];
        if (lvl >= 21)
            k = 0;
        else if (lvl < 11)
            k = 2;
        else
            k = 1;
        func_002A6C58(object, 0x100, func_002A77E0(2) + k);
        return;
    }
    if (*(short *)(object + 0xAA) != 0x1F5 && *(short *)(object + 0xAA) != 0x200) {
        switch (*(unsigned char *)(vars + 0xCB)) {
        case 4:
            type = 0xF;
            break;
        case 8:
            type = 0xE;
            break;
        case 9:
            type = 0x11;
            break;
        default:
            type = -1;
            break;
        }
        n = func_002A68A8(object, &type);
        if (n > 0) {
            do {
                func_003202E8(object + 0x10, type, -1, 0);
            } while (--n != 0);
        }
    }
    if (*(short *)(object + 0xB4) != 0)
        *(short *)(object + 0xB4) = 0;
    func_002A6C58(object, 0x100, 0);
}
