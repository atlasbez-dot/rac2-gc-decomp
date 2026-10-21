char *func_L11_004349F8(char *obj, TI128 *p1, TI128 *p2, float f)
{
    TI128 t[2];
    char *n;
    char *st;

    t[0] = *p1;
    t[1] = *p2;
    n = func_3224B0(0xD1B);
    if (n != 0) {
        *(unsigned char *)(n + 0x31) = 1;
        *(unsigned char *)(n + 0x30) = 0xFF;
        *(unsigned short *)(n + 0x32) = 0xFF;
        *(unsigned char *)(n + 0x20) = 0;
        st = *(char **)(n + 0x68);
        *(unsigned long long *)(n + 0x38) = *(unsigned long long *)(obj + 0x38);
        *(TI128 *)(n + 0x10) = *(TI128 *)st;
        *(TI128 *)st = t[0];
        *(TI128 *)(st + 0x20) = t[1];
        *(float *)(st + 0x3C) = f;
        *(int *)(st + 0x34) = 0;
        *(int *)(st + 0x38) = 0;
    }
    return n;
}
