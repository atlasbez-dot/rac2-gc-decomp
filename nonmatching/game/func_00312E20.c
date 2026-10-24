/* Best of ten plain-C trials: 136 bytes, 0/28 in each release. The initial branch and the final copy still differ. */
typedef struct __attribute__((aligned(16))) {
    float x;
    float y;
    float z;
    float w;
} Pos16_00312E20;

extern char *func_0029EFD0(int);

void *func_00312E20(char *arg0, int arg1)
{
    char *object;
    char *data;
    Pos16_00312E20 *srcPos;
    Pos16_00312E20 *dstPos;

    if (*(signed char *)(arg0 + 0x20) >= 0) {
        object = func_0029EFD0(0x326);
        if (object != 0) {
            data = *(char **)(object + 0x68);
            *(unsigned char *)(object + 0x30) = 0x40;
            srcPos = (Pos16_00312E20 *)(arg0 + 0x10);
            *(unsigned char *)(object + 0x20) = 0;
            dstPos = (Pos16_00312E20 *)(object + 0x10);
            *(char **)(object + 0xB8) = arg0;
            *(unsigned char *)(data + 0x57) = (unsigned char)arg1;
            *(unsigned int *)(object + 0x98) = 0;
            *(unsigned short *)(object + 0x34) |= 0x41;
            *dstPos = *srcPos;
        }
        return object;
    }
    return 0;
}
