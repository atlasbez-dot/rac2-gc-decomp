/* func_L13_0041BAE0 - 708 bytes, 2 place(s), level 13_boldan, retail at
   0x0041bae0. Screened with tools/w10_screen.py: 5 call(s)
   [func_00283658@0041BB24, func_0027C878@0041BB40, func_00283180@0041BCEC,
   func_00283198@0041BD00, func_00280B90@0041BD58]; data addresses
   materialised [0x1b0000, 0x3f930000, 0x3dcc0000, 0x3f260000, 0x3dcc0000,
   0x190000, 0x190000, 0x3e490000, 0x40490000]; float constants [0x3f800000,
   0x3f800000]; $gp-relative small data: no   saves: -; callee-saved
   registers saved [-]; words plain C cannot emit [LQ/SQ 7A020000@0x0054,
   LQ/SQ 7C620000@0x0058, COP1 4680A520@0x0200]. Head: addiu $sp, $sp,
   -0x140 ; sd $s0, 0xD0($sp) ; sd $s1, 0xD8($sp) ; daddu $s0, $a0, $zero ;
   sd $s2, 0xE0($sp) ; addiu $s1, $sp, 0x90. Not matched in this wave: the
   128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through a
   `mode(TI)` local, and this cc1 folds the destination offset into the `sq`
   where retail materialises the pointer first. What would unblock it: the
   exact source expression tree, so this cc1 picks the same registers in the
   same order. */

/* Manual C reconstruction, retained after bounded retail comparison.
 * This body supersedes the historical screening conclusions above.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 756 bytes; retail: 708 bytes. US/US2/PAL: 0/2 placements in each carrying
 * release.
 * 2 distinct measured forms. Retail 708 bytes; stack frame 0x160 versus 0x140. Independent
 * UV pointer iterators still produced 756 bytes. Real 144-byte packet, 64-byte matrix, and
 * 32-byte UV array are preserved. Reopen on packet/local lifetimes and UV addressing; do
 * not shrink the UV array or add an interior alias.
 * All carrying checks ended as nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef struct { float vertex[4][4]; unsigned int color[4]; float uv[4][2]; unsigned long long state[4]; } RingPacket;
extern int D_L13_001B16E8[4] __attribute__((sda));
extern int D_L13_001B16F8 __attribute__((sda));
extern unsigned int D_L13_001B16FC __attribute__((sda));
extern float D_L13_001B1700[4][2] __attribute__((sda));
extern float D_L13_001B1720 __attribute__((sda));
extern unsigned char D_00189E20[];
extern void func_00283658(void *, void *);
extern unsigned long long func_0027C878(int);
extern float func_00283180(float);
extern float func_00283198(float);
extern void func_00280B90(void *, void *, int);

void func_L13_0041BAE0(void *opaque) {
    char *object = opaque;
    RingPacket packet;
    float matrix[16];
    char *private = *(char **)(object + 0x68);
    float thickness;
    float radius;
    float fade;
    float angle;
    int i;
    int j;
    func_00283658(matrix, object + 0xC0);
    *(Quad *)(matrix + 12) = *(Quad *)(object + 0x10);
    packet.state[1] = func_0027C878(D_L13_001B16F8);
    packet.state[3] = (long long)D_L13_001B16E8[0] |
        ((long long)D_L13_001B16E8[1] << 2) | ((long long)D_L13_001B16E8[2] << 4) |
        ((long long)D_L13_001B16E8[3] << 6) | 0x8000000000ULL;
    packet.state[2] = 0xFF9000000260ULL;
    packet.state[0] = 0;
    {
        float *u = &D_L13_001B1700[0][0];
        float *v = &D_L13_001B1700[0][1];
        float *out_u = &packet.uv[0][0];
        float *out_v = &packet.uv[0][1];
        unsigned int *color = packet.color;
        unsigned int shade = D_L13_001B16FC;
        for (i = 3; i >= 0; i--) {
            *out_u = *u;
            *out_v = *v;
            *color++ = shade;
            u += 2;
            v += 2;
            out_u += 2;
            out_v += 2;
        }
    }
    radius = *(float *)(private + 0x34);
    thickness = 0.1f;
    if (radius < 1.15f) {
        fade = 1.15f - radius;
        fade += fade;
        if (fade > 1.0f) fade = 1.0f;
        else if (fade < 0.0f) fade = 0.0f;
        thickness = fade + 0.1f;
        D_00189E20[0x22B5] = radius < 0.65f ? 1 : 0;
    }
    for (i = 0; i < 32; i++) {
        for (j = 0; j < 4; j++) {
            angle = (float)(i + j / 2) * 0.19637252f - 3.14159f;
            packet.vertex[j][0] = func_00283180(angle) * *(float *)(private + 0x34);
            packet.vertex[j][1] = func_00283198(angle) * *(float *)(private + 0x34);
            packet.vertex[j][2] = 0.0f;
            packet.vertex[j][2] = (j & 1) ? D_L13_001B1720 + thickness : D_L13_001B1720 - thickness;
            packet.vertex[j][3] = 1.0f;
        }
        func_00280B90(&packet, matrix, 0);
    }
}
