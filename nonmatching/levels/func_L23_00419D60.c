/* func_L23_00419D60 (724 bytes, 1 place: 23:00419D60) -- NEAR MISS, not integrated.
   This C compiles to 688 bytes (696 with -frac2-zero-ti-barrier) against retail's 724, in a -g8 unit.
   95 words differ (98 with the barrier profile). The $gp words are D_L23_001B1438/1440/1448/1460/1464;
   D_L23_001B3724 is a plain extern: retail reads it absolute (`lui`/`lw 0x3724`) and writes it
   through $gp only where the store sits in a delay slot, which the assembler does by itself; the stores
   to D_L23_001B372C/3730 are plain externs through `$at`. The control flow and the data are decoded:
   for the kinds 8..10 the three states of D_L23_001B1438 (0, 1, 2) and a separate path for the other
   kinds, the stack vector {0, 0, 1, 1} for func_00282D30, the fields at +0x470..+0x4C0 and +0x578
   (1.4726216f is 0x3FBC7EDD). Branch shapes, call order and constants are retail's: the
   `D_L23_001B1438 != 2` arm order and the `scale = 0.0f` initialisation inside the first branch (retail
   has `mtc1 $zero,$f20` after the first load) were needed. What differs, all of it known compiler-side
   walls:
   - Three `por $v,$zero,$zero ; sq $v,0x0($sp)` clears of the stack vector (states 1 and 2 and the
     other-kind path): this cc1 folds them into `sq $zero,0x0($sp)`, since the zero-TI fold applies to a
     register address with no displacement. The same wall as func_L23_00422798 (its record says what
     it would take: a change to rac2_fold_zero_ti_store). Retail has four `por` words: the three
     clears and reorg's copy of the first into the delay slot of the `bnez` in front of the
     func_0029F978 call.
   - Two `addiu $v0,$s0,0x480 ; sq $zero,0x0($v0)` clears (the tail of both paths): this cc1 folds the
     offset and keeps the zero, `por ; sq $v,0x480($s0)` (the 128-bit constant-offset wall); retail
     also issues the loads that follow the clear (`lwc1 ... 0x2450($gp)`, `cvt.s.w`) ahead of the float
     stores, this C behind them. -frac2-zero-ti-barrier keeps the offset form and moves the stack clears
     into branch-likely delay slots (696 bytes), no closer.
   - The 1.0f constant is carried across the func_00282D30 call in a callee-saved FPR here (`mtc1
     $at,$f20` in the other-kind path, with the scale in $f21 and a second save/restore pair), where
     retail rematerialises it after the call and keeps only the scale in $f20. A named local for it,
     or taking vec.f[3] from vec.f[2], gives the same bytes. Retail has two `nop`s in front of the first
     `div.s` and one in front of the second; this C has none (its stores are ordered differently). */

typedef int TI128 __attribute__((mode(TI)));

extern int D_L23_001B1438 __attribute__((sda));

extern int D_L23_001B1440 __attribute__((sda));

extern float D_L23_001B1448 __attribute__((sda));

extern int D_L23_001B3724;

extern int D_L23_001B1460 __attribute__((sda));

extern int D_L23_001B1464 __attribute__((sda));

extern int D_L23_001B372C;

extern int D_L23_001B3730;

extern void func_0029F978(char *, int, char *);

extern void func_00282D30(char *, char *, float);

extern void func_00283898(void *, int, float);

void func_L23_00419D60(char *obj) {
    char *state = *(char **)(obj + 0x68);
    float scale;
    union {
        TI128 q;
        float f[4];
    } vec;
    float r;

    if ((unsigned char)(*(unsigned char *)(obj + 0x20) - 8) < 3) {
        scale = 0.0f;
        if (D_L23_001B1438 == 0) {
            D_L23_001B1438 = 1;
            D_L23_001B3724 = D_L23_001B1440;
        } else if (D_L23_001B1438 != 2) {
            if (*(unsigned char *)(state + 0x471) == 0)
                func_0029F978(obj, 0x26, state + 0x470);
            vec.q = 0;
            vec.f[2] = 1.0f;
            vec.f[3] = 1.0f;
            scale = (float)(D_L23_001B1440 - D_L23_001B3724) * D_L23_001B1448;
            func_00282D30(state + 0x4A0, (char *)&vec, scale);
            D_L23_001B3724 = D_L23_001B3724 - 1;
            if (D_L23_001B3724 == -1)
                D_L23_001B1438 = 2;
        } else {
            D_L23_001B3724 = D_L23_001B1440;
            if (*(unsigned char *)(state + 0x471) == 0)
                func_0029F978(obj, 0x26, state + 0x470);
            vec.q = 0;
            vec.f[2] = 1.0f;
            vec.f[3] = 1.0f;
            scale = (float)D_L23_001B1440 * D_L23_001B1448;
            func_00282D30(state + 0x4A0, (char *)&vec, scale);
            if (*(unsigned char *)(state + 0x4B1) == 0)
                func_0029F978(obj, 0x27, state + 0x4B0);
            *(float *)(state + 0x578) = 1.4726216f;
            func_00283898(state + 0x4C0, 1, 1.4726216f);
        }
        *(TI128 *)(state + 0x480) = 0;
        *(unsigned char *)(state + 0x473) = 1;
        *(float *)(state + 0x47C) = 1.0f;
        *(float *)(state + 0x48C) = 1.0f;
        *(float *)(state + 0x49C) = 1.0f;
        r = 1.0f - scale / (D_L23_001B1448 * (float)D_L23_001B1440 * 4.0f);
        *(float *)(state + 0x490) = r;
        *(float *)(state + 0x498) = r;
        *(float *)(state + 0x494) = r;
    } else if (D_L23_001B1438 != 0) {
        if (*(unsigned char *)(state + 0x471) == 0)
            func_0029F978(obj, 0x26, state + 0x470);
        vec.q = 0;
        vec.f[2] = 1.0f;
        vec.f[3] = 1.0f;
        scale = (float)D_L23_001B3724 * D_L23_001B1448;
        func_00282D30(state + 0x4A0, (char *)&vec, scale);
        D_L23_001B3724 = D_L23_001B3724 - 1;
        if (D_L23_001B3724 == -1) {
            D_L23_001B372C = D_L23_001B1460;
            D_L23_001B3730 = D_L23_001B1464;
            D_L23_001B1438 = 0;
        }
        *(TI128 *)(state + 0x480) = 0;
        *(unsigned char *)(state + 0x473) = 1;
        *(float *)(state + 0x47C) = 1.0f;
        *(float *)(state + 0x48C) = 1.0f;
        *(float *)(state + 0x49C) = 1.0f;
        r = 1.0f - scale / (D_L23_001B1448 * (float)D_L23_001B1440 * 2.0f);
        *(float *)(state + 0x490) = r;
        *(float *)(state + 0x498) = r;
        *(float *)(state + 0x494) = r;
    }
}
