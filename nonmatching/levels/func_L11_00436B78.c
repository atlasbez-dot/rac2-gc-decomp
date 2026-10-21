void func_L11_00436B78(char *obj, char *p)
{
    char *state;
    union { double d; float f[2]; } u;
    float f0, f1, f20, f21;
    TI128 v;

    state = *(char **)(obj + 0x68);
    if (*(short *)(state + 0x286) != 0) {
        f1 = *(float *)(obj + 0x14);
        f0 = *(float *)(obj + 0x10);
        u.f[0] = *(float *)(p + 0) * f0;
        u.f[1] = *(float *)(p + 4) * f1;
        f21 = 15.0f;
        func_00282C90(u.d);
        f0 = -0.78539824f;
        func_002A7878(-0.78539824f, 0.78539824f);
        f20 = f0;
        v = *(TI128 *)p;
        *(TI128 *)(state + 0x250) = v;
        f20 = func_00282BE0(f0);
        if (f0 < f21) {
            f1 = *(float *)(state + 0x250);
            f1 = func_00283198(f1);
            *(float *)(state + 0x250) = f1;
        }
        if (f0 < f21) {
            f1 = *(float *)(state + 0x254);
            func_002A7878(0.0f, 4.0f);
            *(float *)(state + 0x254) = f1;
        }
        f1 = 465.0f;
        *(float *)(state + 0x258) = f0;
    } else {
        f1 = *(float *)(obj + 0x14);
        f0 = *(float *)(obj + 0x10);
        u.f[0] = *(float *)(p + 0) * f0;
        u.f[1] = *(float *)(p + 4) * f1;
        func_00282C90(u.d);
        func_002A7878(-0.78539824f, 0.78539824f);
        func_002A7878(-2.0f, 2.0f);
        f20 = f21;
        f1 = 8.0f;
        v = *(TI128 *)p;
        *(TI128 *)(state + 0x250) = v;
        f21 = func_00282BE0(f0);
        f1 = *(float *)(state + 0x250);
        f21 = func_00283198(f1);
        *(float *)(state + 0x250) = f1;
        f20 = f0;
        f0 = *(float *)(state + 0x254);
        f20 = f0;
        *(float *)(state + 0x254) = f0;
    }
}
