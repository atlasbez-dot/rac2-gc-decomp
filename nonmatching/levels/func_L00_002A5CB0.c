/* Current reconstruction, checked 2026-10-23.
   Game profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   USA v1.01 and USA v2.00: 0/19 carrying placements each; absent from PAL.
   812/852 bytes, frame 0x70 versus retail 0x80. Resident-base lifetime, vector-copy address roles, switch/register scheduling differ. Moving initial color setup to its measured phase removed unrelated long-lived registers; disabling the first scheduling pass was neutral. Reopen with the original resident-object layout and color/copy lifetimes.
   The historical screening comment below is superseded by these C measurements.
   No linked build was run for this draft.
*/

/* func_L00_002A5CB0 - 852 bytes, 19 places, level 00_aranos_tutorial at 0x002A5CB0.
   Wave 13 s4: not attempted, screened.  This is the twin of func_L00_002A6008:
   it builds the object the resident block points at (the pointer is at
   0x1864 here), stores the two resident records into it and sets its flags.
   The 128-bit copies are retail's materialised shape again -
     addiu $a2,$s0,0x80 ; lq $v0,0($a2) ; sq $v0,0($v1)
     addiu $a1,$a0,0xF0 ; addiu $v1,$s0,0x90 ; lq $v0,0($v1) ; sq $v0,0($a1)
     addiu $v1,$s1,0x2010 ; lq $v0,0($sp) ; sq $v0,0($v1)
     addiu $a1,$sp,0x40 ; addiu $v1,$a0,0x10 ; lq $v0,0($a1) ; sq $v0,0($v1)
   (words 0x78C20000, 0x7C620000, 0x78620000, 0x7CA20000, 0x7BA20000,
   0x78A20000) - the same wall as func_L00_002A6008: this cc1 folds the
   constant offset into the lq/sq instead of keeping the address in a
   register.  The body also carries the float constant 0x3FD9999A and a
   `lw`/`sw` pair of the 0x801432D7 / 0x301432D7 tags.  Unblocker: the
   quad-copy wall of func_L00_002A6008 has to fall first. */

typedef int Vector __attribute__((mode(TI)));
extern unsigned char D_00189E20[];
extern unsigned char D_001A7A43;
extern char *func_0029EFD0(int);
extern void func_002A0F48(char *);
extern void func_0029FCC0(char *, int, char *);
extern void func_L00_002A7A10(void);
extern void func_0029FC20(char *, int, char *);
extern void func_00283678(void *, void *);
extern float func_002AA2E8(float *, float, float);
extern float func_00283B98(float, float);
extern int func_00282978(short *);
extern int func_002E5CF8(int, int, char *);
extern float func_00283198(float);
extern unsigned int func_00283D38(unsigned int, unsigned int, float);

void func_L00_002A5CB0(void) {
    float joint[4];
    float matrix[16];
    unsigned char *hero = D_00189E20;
    char *object;
    float scale;
    unsigned int first;
    unsigned int second;
    unsigned int color;
    if (*(char **)(hero + 0x1864) == 0) {
        object = func_0029EFD0(0x4B4);
        *(char **)(hero + 0x1864) = object;
        if (object) {
            *(unsigned int *)(object + 0x78) = 0x801432D7;
            *(unsigned int *)(hero + 0x2524) = 0x301432D7;
            object = *(char **)(hero + 0x1864);
            *(Vector *)(object + 0x10) = *(Vector *)(hero + 0x80);
            *(Vector *)(object + 0xF0) = *(Vector *)(hero + 0x90);
            *(short *)(object + 0x32) = 0x40;
            (*(char **)(hero + 0x1864))[0x31] = 1;
            (*(char **)(hero + 0x1864))[0x30] = 0;
            *(short *)(*(char **)(hero + 0x1864) + 0x34) = 0;
            *(float *)(*(char **)(hero + 0x1864) + 0x2C) *= 1.7f;
            *(unsigned short *)(*(char **)(hero + 0x1864) + 0x34) |= 0x10;
            func_002A0F48(*(char **)(hero + 0x1864));
        }
    }
    if (!(*(unsigned short *)(*(char **)(hero + 0x2290) + 0x34) & 1)) {
        func_0029FCC0(*(char **)(hero + 0x2290), 7, (char *)joint);
        *(Vector *)(hero + 0x2010) = *(Vector *)joint;
        func_L00_002A7A10();
        if (*(char **)(hero + 0x1864)) {
            func_0029FC20(*(char **)(hero + 0x2290), 7, (char *)matrix);
            object = *(char **)(hero + 0x1864);
            *(Vector *)(object + 0x10) = *(Vector *)(matrix + 12);
            func_00283678(object + 0xC0, matrix);
            func_002A0F48(*(char **)(hero + 0x1864));
            scale = D_001A7A43 ? 3.1f : 1.7f;
            if (*(short *)(hero + 0x2520)) scale *= 1.4f;
            object = *(char **)(hero + 0x1864);
            func_002AA2E8((float *)(object + 0x2C), *(float *)(*(char **)(object + 0x24) + 0x24) * scale, 0.02f);
        }
    }
    *(float *)(hero + 0x1868) = func_00283B98(*(float *)(hero + 0x1868), 0.049451005f);
    first = 0x281414C8;
    second = 0x1E00004B;
    if (!func_00282978((short *)(hero + 0x2520))) {
        *(float *)(hero + 0x1868) = func_00283B98(*(float *)(hero + 0x1868), 0.20362177f);
        switch (*(short *)(hero + 0x2522)) {
        case 1: first = 0x2814C814; second = 0x1E004B00; break;
        case 2: first = 0x2814C8C8; second = 0x1E004B4B; break;
        case 3: first = 0x323232FA; second = 0x1E000078; break;
        case 4: first = 0x28F01414; second = 0x1E4B0000; break;
        }
        if (*(short *)(hero + 0x2520) >= 50 && (*(unsigned short *)(hero + 0x2520) & 1))
            func_002E5CF8(*(short *)(hero + 0x2522) + 16, 0, *(char **)(hero + 0x2290));
    }
    color = func_00283D38(first, second, func_00283198(*(float *)(hero + 0x1868)) * 0.5f + 0.5f);
    object = *(char **)(hero + 0x1864);
    if (object)
        *(unsigned int *)(object + 0x78) = func_00283D38(*(unsigned int *)(object + 0x78), color, 0.1f);
    *(unsigned int *)(hero + 0x2524) = func_00283D38(*(unsigned int *)(hero + 0x2524), color, 0.1f);
}
