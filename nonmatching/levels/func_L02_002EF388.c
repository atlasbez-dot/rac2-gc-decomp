/* 528/564, all three releases 0/17.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Readable fused-object construction with three optional links. Stack lifetimes, scalar flag stores, relative matrix scratch and copied input pointers differ. Reopen with original object and scratch layouts; no artificial overlap was introduced.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef int TI128 __attribute__((mode(TI)));
extern u8 *func_0029EFD0(int);
extern int func_L02_003272D8(char *);
extern void func_00283698(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00283098(void *, void *, void *);
extern int func_002AE730(float *, int *);
extern void func_00283738(void *, void *, void *);
extern void func_002AB6D8(float *, float *);
extern void func_002833F0(void *, void *);

int func_L02_002EF388(u8 *object, TI128 *position, TI128 *rotation, u8 **links, int count) {
    float inverse[16], relative[4], matrix[16], angles[4];
    u8 *fused = func_0029EFD0(0x9BB);
    u8 *data;
    int i;
    if (!fused)
        return 0;
    *(u8 **)(fused + 0xB8) = object;
    fused[0x30] = 0xFF;
    *(TI128 *)(fused + 0x10) = *position;
    data = *(u8 **)(fused + 0x68);
    *(u8 **)(data + 0x10) = object;
    *(unsigned int *)(data + 0x20) = *(u16 *)(object + 0x34);
    *(int *)(data + 0x30) = func_L02_003272D8((char *)object);
    func_00283698(inverse, object + 0xC0);
    for (i = 0; i < count && i < 3; i++) {
        if (links[i]) {
            *(u8 **)(data + 0x14 + i * 4) = links[i];
            *(unsigned int *)(data + 0x24 + i * 4) = *(u16 *)(links[i] + 0x34);
            *(int *)(data + 0x34 + i * 4) = func_L02_003272D8((char *)links[i]);
            func_00282CF0(relative, links[i] + 0x10, object + 0x10);
            func_00283098(relative, relative, inverse);
            func_002AE730(relative, (int *)(data + 0x40 + i * 4));
            func_00283738(matrix, inverse, links[i] + 0xC0);
            func_002AB6D8(matrix, angles);
            func_002AE730(angles, (int *)(data + 0x4C + i * 4));
            *(u16 *)(links[i] + 0x34) |= 0x102;
            *(u16 *)(links[i] + 0x34) |= 1;
            links[i][0x31] = 0;
            *(int *)(links[i] + 0x98) = 0;
        }
    }
    *(TI128 *)(object + 0x10) = *position;
    *(TI128 *)(object + 0xF0) = *rotation;
    func_002833F0(object + 0xC0, object + 0xF0);
    *(int *)(object + 0x98) = 0;
    object[0x31] = 0;
    *(u16 *)(object + 0x34) |= 0x103;
    return 1;
}
