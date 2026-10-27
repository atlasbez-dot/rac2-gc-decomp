/* Mid worker 7: near miss, boot func_00337C10 (532 B), own unit, flags -O2 -G0 -ffunction-sections -mno-split-addresses
   (the flag keeps the %hi of D_001A8CFC out of a saved register; without it a seventh callee-saved register appears).
   528 B vs 532: everything matches except one store. Retail keeps `sw $zero,0($v0)` ahead of the later
   `sw 0x60442D00,0($v0)` to the same word of the second allocation; this cc1 deletes the dead store. float/unsigned/long
   spellings of either store do not keep it. */
extern int *func_00336DA8(int, int);
extern int func_00336E40(void *);
extern int *func_00335E20(void *);
extern void func_00335E68(void *, int);
extern void func_003361E0(void *, void *, void *);
extern void func_00336390(void *, int, int);
extern void func_003363C0(void *, float);
extern void func_00115484(void *, int, int);
extern char D_001ADB40[];
extern char D_001ADB50[];
extern char *D_001A8CFC;

void func_00337C10(char *obj, void *arg)
{
    int *p;
    char *a;
    char *b;

    obj[0xA8] = 0;
    *(int *)(obj + 0x1AC) = 0;
    *(int *)(obj + 0x1A8) = 0;
    *(int *)(obj + 0x1C8) = 0;
    *(int *)(obj + 0x1CC) = 0;
    *(int *)(obj + 0x1D4) = 0x28;
    *(int *)(obj + 0x1C4) = 1;
    *(int *)(obj + 0x1B0) = 1;
    func_00115484(obj + 0x1D8, 0, 0x78);
    if (arg != 0) {
        p = func_00336DA8(0x10, func_00336E40(arg));
        *(float *)(p + 0) = 255.0f;
        *(float *)(p + 1) = 108.0f;
        p[2] = 0;
        p[3] = 0;
        *(int **)(obj + 0) = p;
        p = func_00336DA8(0x10, func_00336E40(arg));
        p[0] = 0;
        p[1] = 0;
        *(long *)p = 0x60442D00;
        p[2] = 0;
        p[3] = 0;
        *(int **)(obj + 8) = p;
        p = func_00336DA8(0x10, func_00336E40(arg));
        *(int **)(obj + 4) = p;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
        p = func_00336DA8(0x10, func_00336E40(arg));
        *(int **)(obj + 12) = p;
        p[0] = 0;
        p[1] = 0;
        p[2] = 0;
        p[3] = 0;
    }
    a = obj + 0x10;
    b = obj + 0x5C;
    func_003361E0(a, D_001ADB40, arg);
    func_00336390(a, (int)(D_001A8CFC + 0x8710), 0x57);
    func_003363C0(a, 0.02f);
    func_00335E68(a, 1);
    *func_00335E20(a) = 0x55F0C070;
    func_003361E0(b, D_001ADB50, arg);
    func_00336390(b, (int)(D_001A8CFC + 0x8710), 0x58);
    func_00335E68(b, 1);
    *func_00335E20(b) = 0x55F0C070;
    **(int **)(obj + 12) = 0x80F0F0F0;
    *(int *)(obj + 0x1B8) = 0;
    **(int **)(obj + 4) = 0;
}
