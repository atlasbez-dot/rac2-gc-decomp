/* Manual C near miss retained on 2026-10-24; no exact-C credit.
 * Measured unit: src/levels/shared/L00_002FFAB8.c
 * Game compiler profile: -O2 -G0 -ffunction-sections
 * Compiled/US retail bytes: 1428/1492.
 * Actual release checks: US: 0/27 (exit 1); US2: 0/27 (exit 1); PAL: 0/27 (exit 1).
 * Residual: 0xc0 frame agrees; material packing, nested stream temporary spills and 64-bit expression ordering differ. The full 64-byte records and leading material block are modeled.
 * Reopen only for: A measured packing/live-range hypothesis covering both optional material and nested stream paths.
 * The ASM marker and trial-only flags were restored after measurement.
 */

/* Relocates the model streams, then patches the material and 64-byte GS records. */
typedef unsigned long U64FFAB8;
typedef unsigned int QuadFFAB8 __attribute__((mode(TI)));
typedef struct PacketFFAB8 {
    U64FFAB8 mip, tag0;
    U64FFAB8 flags, tag1;
    U64FFAB8 tex1, tag2;
    U64FFAB8 tex0, tag3;
} PacketFFAB8;
extern int D_L00_001B23F0;
extern unsigned char *D_L00_0021EA20[];
extern short D_L00_0021EB20[];
extern unsigned char D_L00_0021EBA0[];
extern int D_L00_002203A0[];
extern QuadFFAB8 D_L00_002209A0[];
extern U64FFAB8 D_L00_001C91C0[][3];
extern int D_001A72F4;
extern int func_00283CF0(float);
extern int func_00282A18(int);
void func_L00_002FFAB8(unsigned char *image, short *textures, QuadFFAB8 *remap,
    short *material, int key)
{
    int i, j, n, index, dims[4], w, h, logW, logH, offset;
    int lod, address, flags, override;
    unsigned char *header, *permutation, *patch;
    PacketFFAB8 *packet;
    short *texture;
    U64FFAB8 tex0, tex1, mip;
    D_L00_0021EBA0[key] = *(unsigned char *)&D_L00_001B23F0;
    D_L00_0021EB20[D_L00_001B23F0] = key;
    D_L00_0021EA20[D_L00_001B23F0] = image;
    *(unsigned short *)(image + 0x26) = *(unsigned short *)&D_L00_001B23F0;
    n = func_00283CF0(*(float *)(image + 0x10) * 1024.0f);
    D_L00_002203A0[D_L00_001B23F0] = n;
    D_L00_001B23F0++;
    *(int *)(image + 0x18) = 0;
    *(short *)(image + 0x16) = 0;
    if (*(int *)(image + 0x2c))
        *(unsigned char **)(image + 0x2c) = image + *(int *)(image + 0x2c);
    for (i = 0; i < *(short *)(image + 0x28); i++)
        *(unsigned char **)(image + 0x40 + i * 8) = image + *(int *)(image + 0x40 + i * 8);
    if (*(int *)(image + 0x1c)) {
        patch = image + *(int *)(image + 0x1c);
        *(unsigned char **)(image + 0x1c) = patch;
        lod = *(int *)(patch + 0x10);
        address = *(int *)(patch + 0x14);
        if (material) {
            for (i = 0; i < 4; i++) {
                dims[i] = material[0] >> (i + 6);
                if (dims[i] <= 0) dims[i] = 1;
            }
            logW = func_00282A18(material[0]);
            logH = func_00282A18(material[1]);
            mip = ((U64FFAB8)address << 6) | 0x20 | ((U64FFAB8)(material[2] - 1) << 2) | ((U64FFAB8)lod << 32);
            *(U64FFAB8 *)(patch + 0x10) = mip;
            offset = D_001A72F4 >> 8;
            tex0 = (U64FFAB8)(material[4] + offset) | ((U64FFAB8)dims[0] << 14);
            tex0 |= ((U64FFAB8)logW << 26) | 0x01300000 | ((U64FFAB8)logH << 30);
            tex0 |= ((U64FFAB8)(material[3] + offset) << 37) | ((U64FFAB8)1 << 34) | ((U64FFAB8)1 << 63);
            *(U64FFAB8 *)(patch + 0x20) = tex0;
            tex1 = (U64FFAB8)(material[5] + offset) | ((U64FFAB8)dims[1] << 14);
            tex1 |= ((U64FFAB8)(material[6] + offset) << 20) | ((U64FFAB8)dims[2] << 34);
            tex1 |= ((U64FFAB8)(material[7] + offset) << 40) | ((U64FFAB8)dims[3] << 54);
            *(U64FFAB8 *)(patch + 0x30) = tex1;
        } else {
            index = 0;
            while (D_L00_001C91C0[index + 1][0]) index++;
            *(U64FFAB8 *)(patch + 0x20) = D_L00_001C91C0[index][0];
            *(U64FFAB8 *)(patch + 0x30) = D_L00_001C91C0[index][2];
            *(U64FFAB8 *)(patch + 0x10) = (D_L00_001C91C0[index][1] & 0x1c) |
                ((U64FFAB8)address << 6) | 0x20 | ((U64FFAB8)lod << 32);
        }
    }
    permutation = (unsigned char *)&D_L00_002209A0[D_L00_0021EBA0[key]];
    *(QuadFFAB8 *)permutation = *remap;
    for (i = 0; i < *(short *)(image + 0x28); i++) {
        header = *(unsigned char **)(image + 0x40 + i * 8) + 0x10;
        packet = (PacketFFAB8 *)(header + (*(int *)(header + 4) * 16) + 0x10);
        for (j = 0; j < *(int *)header; j++, packet++) {
            index = permutation[*(int *)((unsigned char *)packet + 0x20)];
            lod = *(int *)packet;
            address = *(int *)((unsigned char *)packet + 4);
            flags = *(int *)((unsigned char *)packet + 0x10);
            override = *(int *)((unsigned char *)packet + 0x14);
            if (textures) {
                texture = textures + index * 8;
                w = texture[2] >> 6;
                h = texture[2] >> 7;
                if (w <= 0) w = 1;
                if (h <= 0) h = 1;
                logW = func_00282A18(texture[2]);
                logH = func_00282A18(texture[3]);
                offset = D_001A72F4 >> 8;
                tex0 = ((U64FFAB8)logW << 26) | 0x01300000;
                tex0 = ((U64FFAB8)w << 14) | tex0 | ((U64FFAB8)logH << 30);
                tex0 |= ((U64FFAB8)(texture[5] + offset) << 37) | ((U64FFAB8)1 << 34) | ((U64FFAB8)1 << 63);
                tex1 = ((U64FFAB8)h << 14) | ((U64FFAB8)(texture[6] + offset) << 20);
                tex1 |= ((U64FFAB8)(texture[7] + offset) << 40) | ((U64FFAB8)1 << 34) | ((U64FFAB8)1 << 39);
                mip = ((U64FFAB8)address << 6) | 0x20 | ((U64FFAB8)(texture[4] - 1) << 2) | ((U64FFAB8)lod << 32);
                packet->mip = mip;
                packet->flags = (U64FFAB8)flags | ((U64FFAB8)override << 2) | ((U64FFAB8)index << 24);
                packet->tex1 = tex1;
                packet->tex0 = tex0;
            } else {
                packet->mip = (D_L00_001C91C0[index][1] & 0x1c) | ((U64FFAB8)address << 6) | 0x20 | ((U64FFAB8)lod << 32);
                packet->flags = (U64FFAB8)flags | ((U64FFAB8)override << 2) | ((U64FFAB8)index << 24);
                packet->tex1 = D_L00_001C91C0[index][2];
                packet->tex0 = D_L00_001C91C0[index][0];
            }
        }
    }
}
