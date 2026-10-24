/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_002FF6A8.c
 * Game compiler profile: -O2 -G0 -ffunction-sections
 * Compiled/US retail bytes: 984/1040.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: 0/27 (exit 1).
 * Residual: 0x80 frame agrees; global setup, 64-bit packing allocation/order and fallback-table arithmetic differ. All 80 packet bytes are retained by layout.
 * Reopen only for: A measured source/storage model for GS bitfield packing and indexed fallback triples.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Relocates a three-stream image and builds each complete 80-byte GS packet. */
typedef unsigned long U64FF6A8;
typedef unsigned int QuadFF6A8 __attribute__((mode(TI)));
typedef struct PacketFF6A8 {
    U64FF6A8 tex0, tag0;
    U64FF6A8 mip0, tag1;
    U64FF6A8 tex1, tag2;
    U64FF6A8 flags, tag3;
    U64FF6A8 tail[2];
} PacketFF6A8;
extern int D_L00_001B2510;
extern unsigned char *D_L00_00226700[];
extern short D_L00_00226900[];
extern unsigned char D_L00_00226A00[];
extern int D_L00_0022DA00[];
extern QuadFF6A8 D_L00_0022DE00[];
extern U64FF6A8 D_L00_001C91C0[][3];
extern int D_001A72F4;
extern int func_00283CF0(float);
extern int func_00282A18(int);
void func_L00_002FF6A8(unsigned char *image, short *textures, QuadFF6A8 *remap, int key)
{
    int i, j, index, w, h, logW, logH, offset;
    int lod, address, flags, override;
    unsigned char *stream;
    short *texture;
    unsigned char *permutation;
    PacketFF6A8 *packet;
    U64FF6A8 tex0, tex1, mip;
    D_L00_00226700[D_L00_001B2510] = image;
    D_L00_00226900[D_L00_001B2510] = key;
    D_L00_00226A00[key] = *(unsigned char *)&D_L00_001B2510;
    *(unsigned short *)(image + 0x46) = *(unsigned short *)&D_L00_001B2510;
    D_L00_0022DA00[D_L00_001B2510++] = func_00283CF0(*(float *)(image + 0x48) * 1024.0f);
    *(int *)(image + 0x20) = 0;
    *(short *)(image + 0x3e) = 0;
    for (i = 0; i < 3; i++) {
        if (*(int *)(image + i * 4)) {
            *(unsigned char **)(image + i * 4) = image + *(int *)(image + i * 4);
            for (j = 0; j < image[0xc + i]; j++) {
                stream = *(unsigned char **)(image + i * 4);
                *(unsigned char **)(stream + j * 16) = stream + *(int *)(stream + j * 16);
            }
        }
    }
    if (image[0xd] == 0) *(float *)(image + 0x14) = 8190.0f;
    if (image[0xe] == 0) *(float *)(image + 0x18) = 8192.0f;
    *(unsigned char **)(image + 0x34) = image + *(int *)(image + 0x34);
    *(unsigned char **)(image + 0x1c) = image + *(int *)(image + 0x1c);
    *(int *)(image + 0x30) = 0;
    permutation = (unsigned char *)&D_L00_0022DE00[D_L00_00226A00[key]];
    *(QuadFF6A8 *)permutation = *remap;
    packet = *(PacketFF6A8 **)(image + 0x1c);
    for (i = 0; i < image[0xf]; i++, packet++) {
        index = permutation[i];
        lod = *(int *)((unsigned char *)packet + 0x10);
        address = *(int *)((unsigned char *)packet + 0x14);
        flags = *(int *)((unsigned char *)packet + 0x30);
        override = *(int *)((unsigned char *)packet + 0x34);
        if (textures) {
            texture = textures + index * 8;
            w = texture[2] >> 6;
            h = texture[2] >> 7;
            if (w <= 0) w = 1;
            if (h <= 0) h = 1;
            logW = func_00282A18(texture[2]);
            logH = func_00282A18(texture[3]);
            offset = D_001A72F4 >> 8;
            tex0 = ((U64FF6A8)logW << 26) | 0x01300000;
            tex0 = ((U64FF6A8)w << 14) | tex0 | ((U64FF6A8)logH << 30);
            tex0 |= ((U64FF6A8)(texture[5] + offset) << 37) | ((U64FF6A8)1 << 34);
            tex0 |= (U64FF6A8)1 << 63;
            tex1 = ((U64FF6A8)h << 14) | ((U64FF6A8)(texture[6] + offset) << 20);
            tex1 |= ((U64FF6A8)(texture[7] + offset) << 40) | ((U64FF6A8)1 << 34);
            tex1 |= (U64FF6A8)1 << 39;
            mip = ((U64FF6A8)address << 6) | 0x20 | ((U64FF6A8)(texture[4] - 1) << 2);
            mip |= (U64FF6A8)lod << 32;
            packet->tex0 = tex0;
            packet->mip0 = mip;
            packet->tex1 = tex1;
            packet->flags = (U64FF6A8)flags | ((U64FF6A8)override << 2) | ((U64FF6A8)index << 24);
        } else {
            packet->tex0 = D_L00_001C91C0[index][0];
            packet->mip0 = (D_L00_001C91C0[index][1] & 0x1c) | ((U64FF6A8)address << 6) | 0x20 | ((U64FF6A8)lod << 32);
            packet->tex1 = D_L00_001C91C0[index][2];
            packet->flags = (U64FF6A8)flags | ((U64FF6A8)override << 2) | ((U64FF6A8)index << 24);
        }
    }
}
