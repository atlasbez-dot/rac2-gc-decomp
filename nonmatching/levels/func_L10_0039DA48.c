/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
   us: 10_hrugis_cloud: instruction at +0x0 differs; func_L10_0039DA48: 0 of 2 places match (src/levels/shared/L10_0039DA48-copy.c).
   us2: 10_hrugis_cloud: instruction at +0x0 differs; func_L10_0039DA48: 0 of 2 places match (src/levels/shared/L10_0039DA48-copy.c).
   pal: 10_hrugis_cloud: instruction at +0x0 differs; func_L10_0039DA48: 0 of 2 places match (src/levels/shared/L10_0039DA48-copy.c).
   Same 1492-byte extent; the current frame is 0x260 against retail 0x270, with different spills/allocation. Both core/glow passes use an explicit 0x90-byte packet layout; no fake padding was added. Texture handles and the final recorder value preserve their 64-bit width; color shifts are unsigned. Reopen with a verified spill/local lifetime structure.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_0039DA48 - 1492 bytes, 2 place(s), level 10_hrugis_cloud, retail
   at 0x0039da48. Screened with tools/w10_screen.py: 39 call(s)
   [func_0027C878@0039DAB8, func_0027C878@0039DB04, func_00282CF0@0039DBA0,
   func_00282CF0@0039DBB4, func_00282DD8@0039DBC8, func_00282DF0@0039DBD4,
   func_00282D30@0039DC04, func_00282CC0@0039DC14, func_00282CF0@0039DC24,
   func_00282CF0@0039DC54, func_00282CF0@0039DC64, func_00282DD8@0039DC74,
   func_00282DF0@0039DC7C, func_00282D30@0039DCA8, func_00282CC0@0039DCB8,
   func_00282CF0@0039DCC8, func_00280B90@0039DD1C, func_00282CF0@0039DDA0,
   func_00282CF0@0039DDB0, func_00282DF0@0039DDB8, func_00282DF0@0039DDC4,
   func_00282D30@0039DE08, func_00282D30@0039DE44, func_00282CC0@0039DE58,
   func_00282CC0@0039DE6C, func_00282CF0@0039DE7C, func_00282D30@0039DE8C,
   func_00282CF0@0039DE9C, func_00282CC0@0039DEAC, func_00282CF0@0039DEBC,
   func_00282DD8@0039DECC, func_00282DF0@0039DED4, func_00282D30@0039DF08,
   func_00282CC0@0039DF18, func_00282CF0@0039DF28, func_00282CC0@0039DF38,
   func_00282CF0@0039DF48, func_00280B90@0039DFA0, func_002FC560@0039DFD0];
   data addresses materialised [0x1c0000, 0x1c0000, 0x1c0000, 0x50000];
   float constants [0x3f800000, 0x3f800000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 7A420000@0x02dc, LQ/SQ 7FA20000@0x02e0, LQ/SQ 7A620000@0x02e8,
   LQ/SQ 7C620000@0x02ec, LQ/SQ 7A620000@0x03a4, LQ/SQ 7E220000@0x03a8,
   LQ/SQ 7A220000@0x03e0, LQ/SQ 7E620000@0x03e4]. Head: addiu $sp, $sp,
   -0x270 ; sd $fp, 0x230($sp) ; daddu $fp, $a0, $zero ; sd $s0, 0x1F0($sp)
   ; sd $s1, 0x1F8($sp) ; addiu $v0, $fp, 0x10. Not matched in this wave:
   the 128-bit copy needs an `lq`/`sq` pair; plain C reaches it only through
   a `mode(TI)` local, and this cc1 folds the destination offset into the
   `sq` where retail materialises the pointer first. What would unblock it:
   the exact source expression tree, so this cc1 picks the same registers in
   the same order. */

typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef int Quad __attribute__((mode(TI)));
typedef struct StripQuad {
    f32 vertex[4][4];
    u32 color[4];
    f32 uv[2][4];
    u64 blend;
    u64 texture;
    u64 primitive;
    u64 tag;
} StripQuad;
extern f32 D_L10_001B9680[4];
extern u64 func_0027C878(int);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern f32 func_00282DF0(void *);
extern void func_00282D30(void *, void *, f32);
extern void func_00280B90(void *, void *, int);
extern void func_002FC560(u32, u64);

/* Draws the core and camera-facing glow surfaces of a segmented energy strip. */
void func_L10_0039DA48(void *path, int coreAlpha, int glowAlpha, int count,
                      f32 coreWidth, f32 glowWidth, f32 bias, u32 coreColor, u32 glowColor) {
    StripQuad core;
    StripQuad glow;
    f32 normal[4], width[4], camera[4], tangent[4];
    f32 lineStart[4], lineEnd[4], sightStart[4], sightEnd[4], radial[4], shift[4];
    f32 (*points)[4] = path;
    f32 length, startLength, endLength;
    u32 coreTint, glowTint;
    int i, last = count - 1;
    core.texture = func_0027C878(14);
    coreTint = coreColor | ((u32)coreAlpha << 24);
    core.tag = 0x8000000048ULL;
    core.primitive = 0xFF9000000260ULL;
    core.blend = 0;
    core.color[0] = core.color[1] = core.color[2] = core.color[3] = coreTint;
    glow.texture = func_0027C878(16);
    glowTint = glowColor | ((u32)glowAlpha << 24);
    glow.tag = core.tag;
    glow.primitive = core.primitive;
    glow.blend = core.blend;
    glow.color[0] = glow.color[1] = glow.color[2] = glow.color[3] = glowTint;
    glow.uv[0][0] = 0.0f; glow.uv[0][1] = 0.0f; glow.uv[0][2] = 0.0f; glow.uv[0][3] = 1.0f;
    glow.uv[1][0] = 1.0f; glow.uv[1][1] = 0.0f; glow.uv[1][2] = 1.0f; glow.uv[1][3] = 1.0f;
    core.uv[0][0] = 0.0f; core.uv[0][1] = 0.0f; core.uv[0][2] = 0.0f; core.uv[0][3] = 1.0f;
    core.uv[1][0] = 1.0f; core.uv[1][1] = 0.0f; core.uv[1][2] = 1.0f; core.uv[1][3] = 1.0f;
    func_00282CF0(camera, points[0], D_L10_001B9680);
    func_00282CF0(tangent, points[1], points[0]);
    func_00282DD8(normal, tangent, camera);
    length = func_00282DF0(normal);
    if (length != 0.0f) length = 1.0f / length;
    func_00282D30(normal, normal, coreWidth * length);
    func_00282CC0(core.vertex[0], points[0], normal);
    func_00282CF0(core.vertex[1], points[0], normal);
    for (i = 1; i < last; i++) {
        func_00282CF0(camera, points[i], D_L10_001B9680);
        func_00282CF0(tangent, points[i + 1], points[i]);
        func_00282DD8(normal, tangent, camera);
        length = func_00282DF0(normal);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(normal, normal, coreWidth * length);
        func_00282CC0(core.vertex[2], points[i], normal);
        func_00282CF0(core.vertex[3], points[i], normal);
        if (i == 1) core.color[0] = core.color[1] = coreColor;
        else if (i == last) core.color[2] = core.color[3] = coreColor;
        else if (i == 2) core.color[0] = core.color[1] = coreTint;
        func_00280B90(&core, 0, 0);
        *(Quad *)core.vertex[0] = *(Quad *)core.vertex[2];
        *(Quad *)core.vertex[1] = *(Quad *)core.vertex[3];
    }
    for (i = 0; i < last; i++) {
        func_00282CF0(sightStart, points[i], D_L10_001B9680);
        func_00282CF0(sightEnd, points[i + 1], D_L10_001B9680);
        startLength = func_00282DF0(sightStart);
        endLength = func_00282DF0(sightEnd);
        if (endLength < startLength) {
            if (endLength == 0.0f) *(Quad *)sightEnd = *(Quad *)sightStart;
            else func_00282D30(sightEnd, sightEnd, startLength / endLength);
        } else {
            if (startLength == 0.0f) *(Quad *)sightStart = *(Quad *)sightEnd;
            else func_00282D30(sightStart, sightStart, endLength / startLength);
        }
        func_00282CC0(lineStart, D_L10_001B9680, sightStart);
        func_00282CC0(lineEnd, D_L10_001B9680, sightEnd);
        func_00282CF0(tangent, lineEnd, lineStart);
        func_00282D30(shift, tangent, bias);
        func_00282CF0(lineStart, lineStart, shift);
        func_00282CC0(lineEnd, lineEnd, shift);
        func_00282CF0(radial, D_L10_001B9680, lineStart);
        func_00282DD8(normal, radial, tangent);
        length = func_00282DF0(normal);
        if (length != 0.0f) length = 1.0f / length;
        func_00282D30(width, normal, glowWidth * length);
        func_00282CC0(glow.vertex[0], lineStart, width);
        func_00282CF0(glow.vertex[1], lineStart, width);
        func_00282CC0(glow.vertex[2], lineEnd, width);
        func_00282CF0(glow.vertex[3], lineEnd, width);
        if (i == 0) glow.color[0] = glow.color[1] = glowColor;
        else if (i == count - 2) glow.color[2] = glow.color[3] = glowColor;
        else if (i == 1) glow.color[0] = glow.color[1] = glowTint;
        func_00280B90(&glow, 0, 0);
    }
    func_002FC560(0x47, 0x5360BULL);
}
