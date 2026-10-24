/* Measured profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -mno-split-addresses
   -fno-gcse. us: 18_damosel: 524 bytes, expected 528; us2: 18_damosel: 524 bytes, expected 528; pal:
   18_damosel: 524 bytes, expected 528. Default qcopy profile produced 528 bytes; disabling GCSE
   produced 524, with early template-address hoisting and argument scheduling still different. The
   historical por classification below is obsolete: por is the ordinary compiler-supported quadword-
   zero idiom, not handwritten evidence. Full vectors, 64-byte basis and 144-byte quad packet are
   retained. Reopen with a matching template-address scheduling witness. No linked build or functional
   execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* MMI (SPECIAL2) instruction: no C spelling. 528 bytes, level 18_damosel.
   Retail at 0x003FCA38 carries the SPECIAL2 word 0x700014A9 (+0x0004) -
   opcode 0x1C, which rabbitizer prints as `INVALID`; it is the MMI family
   (pcpyld and its relatives) the sixth wave recorded and that no C spelling
   reaches. This cc1 emits `lq`/`sq` for a `mode(TI)` local and
   `ldl`/`ldr`/`sdl`/`sdr` for a struct assignment, never the packed copy.
   ASM_FUNC candidate, as for the rest of the family. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
typedef struct { float vertex[4][4]; u32 color[4]; float uv[8]; u64 primitive, texture, mode, flags; } GlowQuad;
extern float D_L18_001B97C0[4];
extern float D_L18_001AA250[4][4];
extern float D_L18_001B06C8 __attribute__((sda));
extern float D_L18_001B0690 __attribute__((sda));
extern float D_L18_001B06CC NOT_SDA;
extern float D_L18_001B06D0 NOT_SDA;
extern void func_00282CF0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_002830C0(void *, void *, void *);
extern u64 func_0027C878(s32);
extern void func_00280B90(void *, void *, s32);
void func_L18_003FCA38(u8 *object)
{
    float basis[4][4], up[4], offset[4];
    GlowQuad packet;
    u8 *state = *(u8 **)(object + 0x68);
    float *source;
    float *vertex;
    s32 i;
    *(VectorBits *)up = 0;
    up[2] = 1.0f;
    up[3] = 1.0f;
    *(VectorBits *)basis[3] = *(VectorBits *)(state + 0x90);
    func_00282CF0(basis[0], D_L18_001B97C0, basis[3]);
    func_00282F20(basis[0], basis[0], 1.0f);
    func_00282DD8(basis[1], basis[0], up);
    func_00282F20(basis[1], basis[1], 1.0f);
    func_00282DD8(basis[2], basis[1], basis[0]);
    func_00282F20(basis[0], basis[0], D_L18_001B06C8);
    func_00282F20(basis[1], basis[1], D_L18_001B06CC);
    func_00282F20(basis[2], basis[2], D_L18_001B06D0);
    func_00282D30(offset, basis[0], D_L18_001B0690);
    func_00282CC0(basis[3], basis[3], offset);
    packet.flags = 0x8000000048ULL;
    packet.mode = 0xFF9000000260ULL;
    packet.primitive = 5;
    packet.uv[7] = 1.0f;
    packet.uv[0] = 0; packet.uv[1] = 0; packet.uv[2] = 0; packet.uv[3] = 1;
    packet.uv[4] = 1; packet.uv[5] = 0; packet.uv[6] = 1;
    packet.color[0] = *(u32 *)(state + 0xC4);
    packet.color[1] = packet.color[0]; packet.color[2] = packet.color[0]; packet.color[3] = packet.color[0];
    source = D_L18_001AA250[0];
    vertex = packet.vertex[0];
    for (i = 3; i >= 0; i--) {
        func_00282D30(vertex, source, *(float *)(state + 0xC0));
        source += 4;
        func_002830C0(vertex, vertex, basis);
        vertex += 4;
    }
    packet.texture = func_0027C878(11);
    func_00280B90(&packet, 0, 0);
    packet.texture = func_0027C878(6);
    func_00280B90(&packet, 0, 0);
}
