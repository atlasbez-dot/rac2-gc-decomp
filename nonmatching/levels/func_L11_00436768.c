void func_L11_00436768(char *obj)
{
    float tmp[3];
    TI128 tmp2[2];
    char *state;
    float f0, f1;

    tmp2[1] = 0;
    state = *(char **)(obj + 0x68);
    f1 = *(float *)(state + 0x100);
    f0 = *(float *)(state + 0x104);
    *(float *)((char *)&tmp2[1] + 8) = f0 + f1;
    tmp2[0] = tmp2[1];
    func_00283098((float *)&tmp2[0], (float *)&tmp2[0], (float *)((char *)obj + 0xC0));
    func_00282CC0((char *)tmp, (char *)obj + 0x10, (char *)&tmp2[0]);
    if (*(unsigned short *)(obj + 0x96) <= 0xFFFE)
        *(unsigned short *)(obj + 0x96) = *(unsigned short *)(obj + 0x96) + 1;
    func_338398(obj, state + 0x290, 2.5f, 1, 1);
    func_32E480(obj, obj + 0x10, 0x4000000, 1.0f, 1.0f, 1.0f, 0, 1, 0);
}
