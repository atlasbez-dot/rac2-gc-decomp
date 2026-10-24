/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 912 / 944 bytes; size equality is not a match.
 * us: 0/27 placements; 912/944 bytes.
 * us2: 0/27 placements; 912/944 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: The 0x50 frame versus retail 0x40, allocation and common tails differ. One resident level-id identity has both absolute and GP accesses in retail; no artificial alternate name was introduced.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: absent from both catalogues (exit 1).
 * The 0x50 frame versus retail 0x40, allocation and common tails differ. One resident level-id identity has both absolute and GP accesses in retail; no artificial alternate name was introduced.
 * 1 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
extern unsigned char D_00189E20[];
extern int D_L00_001B19C8;
extern int D_001A79F0;
extern unsigned char D_L00_001BCAC0[];
extern unsigned char D_L00_001B1710[];
extern unsigned char D_L00_001B1750[];
extern unsigned char D_001A7A43;
extern float D_L00_001A7CF8 __attribute__((sda));
extern float func_00283CE0(int);
extern float func_00283198(float);
extern int func_00283CF0(float);
extern void func_0029FCC0(char *, int, char *);
extern float func_00282C48(float);
extern void func_L00_002A7DE8(Vector *, unsigned int, float, float);
extern float func_00283B98(float, float);
extern void func_0029F978(unsigned char *, unsigned int, unsigned char *);

/* Animate the object's glow and bind the appropriate auxiliary joint record. */
void func_L00_002A70F8(unsigned char *object) {
    Vector position;
    unsigned char *player = D_00189E20;
    unsigned char *record;
    unsigned int red, green, blue, alpha;
    int kind, emit;
    float wave, denominator, pulse;
    *(unsigned short *)(object + 0x34) |= 0x10;
    denominator = func_00283CE0(100);
    wave = (float)(D_L00_001B19C8 % 100) / denominator;
    wave = func_00283198((wave + wave) * 3.1415927410125732f - 3.1415927410125732f);
    red = (unsigned int)func_00283CF0(wave * 24.0f) + 0x44U;
    green = (unsigned int)func_00283CF0(wave * 52.0f) + 0xA2U;
    blue = (unsigned int)func_00283CF0(wave * 24.0f) + 0x4CU;
    *(unsigned int *)(object + 0x78) = (blue << 16) | 0x80000000U | (green << 8) | red;
    kind = *(short *)(object + 0xAA);
    if (kind == 0x1159) {
        func_0029FCC0((char *)object, 6, (char *)&position);
        if (func_00282C48(*(float *)(object + 0x18) - position.f[2]) > 2.0f)
            func_L00_002A7DE8(&position, 0x200000C0U, 0.25f, 0.15f);
    } else if (kind == 0x57) {
        emit = 1;
        if (D_001A79F0 == 3 &&
            ((*(int *)(D_L00_001BCAC0 + 0x30) == 7 && *(int *)(D_L00_001BCAC0 + 0x34) > 0x470) ||
             *(int *)(D_L00_001BCAC0 + 0x30) == 0)) emit = 0;
        if (emit) {
            func_0029FCC0((char *)object, 7, (char *)&position);
            *(float *)(player + 0x1868) = func_00283B98(*(float *)(player + 0x1868), 0.06690429896116257f);
            pulse = func_00283198(*(float *)(player + 0x1868));
            alpha = (unsigned int)func_00283CF0((pulse * 0.5f + 0.5f) * 13.0f) + 23U;
            func_L00_002A7DE8(&position, (alpha << 24) | 0xC0U, 0.04f, 0.07f);
        } else *(unsigned int *)(object + 0x78) = 0x80505050U;
    } else if (!(D_001A79F0 == 3 && *(int *)(D_L00_001BCAC0 + 0x30) == 7 && *(int *)(D_L00_001BCAC0 + 0x34) > 0x470)) {
        func_0029FCC0((char *)object, 1, (char *)&position);
        *(float *)(player + 0x1868) = func_00283B98(*(float *)(player + 0x1868), 0.06690429896116257f);
        pulse = func_00283198(*(float *)(player + 0x1868));
        alpha = (unsigned int)func_00283CF0((pulse * 0.5f + 0.5f) * 13.0f) + 23U;
        func_L00_002A7DE8(&position, (alpha << 24) | 0xC0U, 0.04f, 0.07f);
    }
    kind = *(short *)(object + 0xAA);
    record = kind == 0x27D ? D_L00_001B1750 : D_L00_001B1710;
    if (D_001A7A43 && !record[1]) {
        func_0029F978(object, kind == 0x27D ? 1 : kind == 0x57 ? 5 : 2, record);
        *(float *)(record + 0x28) = D_L00_001A7CF8;
        *(float *)(record + 0x20) = D_L00_001A7CF8;
        *(float *)(record + 0x24) = D_L00_001A7CF8;
    }
}
