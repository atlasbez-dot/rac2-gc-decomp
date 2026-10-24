/* 420/452, USA v1.01/v2.00 0/9; PAL absent.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-barrier.
 * The frame/spilled input and pointer lifetimes are shorter than retail. Retail reaches the same counter through both GP-relative and absolute forms; this draft keeps one truthful symbol. Reopen with containing state layout and matrix scratch extent evidence.
 */
typedef unsigned char u8;
typedef int TI128 __attribute__((mode(TI)));
extern unsigned int func_L00_0032C638(unsigned int);
extern void func_L02_00332900(void);
extern void func_00283698(void *, void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_L00_00325600(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern void func_L00_0032C5E8(char *, char *);
extern void func_L02_00333300(char *, char *);
extern void func_L02_00332A80(char *, char *, void *, void *, void *, void *, void *);
extern void func_L02_00332D28(char *, char *, void *, void *, void *);
extern void func_L02_00332EF0(char *, char *, void *, void *, void *);
extern int D_L02_001B30C8 __attribute__((sda));

int func_L02_00333480(char *object, void *target, void *input) {
    float inverse[16], direction[4], rotated[12];
    TI128 previous, output0, output1;
    char *data = (char *)func_L00_0032C638((unsigned int)object);
    if (!data)
        return 8;
    if (D_L02_001B30C8 == *(int *)(data + 0xBC))
        return *(int *)(data + 0x94);
    func_L02_00332900();
    func_00283698(inverse, object + 0xC0);
    func_002AFFD8(object + 0x10, (char *)direction, 0);
    func_L00_00325600(object + 0xC0, direction, rotated);
    func_00283098(data + 0xA0, data + 0xA0, rotated);
    *(int *)(data + 0x98) = *(int *)(data + 0x94);
    *(int *)(data + 0x94) = 0;
    func_L00_0032C5E8(object, data);
    previous = *(TI128 *)(object + 0x10);
    if (D_L02_001B30C8 - *(int *)(data + 0xBC) >= 2 || *(int *)(data + 0xBC) == 0) {
        func_L02_00333300(object, data);
        *(int *)(data + 0x80) = 0;
        data[0xEA] = 0xFF;
        *(unsigned int *)(data + 0x9C) &= ~2;
        *(int *)(data + 0xB4) = 0;
        *(TI128 *)(data + 0xA0) = 0;
    }
    *(int *)(data + 0xBC) = D_L02_001B30C8;
    func_L02_00332A80(object, data, target, input, &output0, &output1, inverse);
    func_L02_00332D28(object, data, &previous, &output1, inverse);
    func_L02_00332EF0(object, data, target, &previous, inverse);
    return *(int *)(data + 0x94);
}
