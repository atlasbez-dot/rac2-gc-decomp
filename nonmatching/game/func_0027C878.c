/* Plain-C texture descriptor and upload-queue reconstruction; not matched.
 * Profile: -O2 -G8 -ffunction-sections. 1356/1356 bytes (16 lines off), us 0/28.
 * 26 October 2026 (M10): the descriptor word as a linear or-chain over separate statements in a
 * fresh temp, and the upload stores in climbed order, take it from 45 to 18 differing lines. Left:
 * pure scheduling in the descriptor block (the height load and palette-bits pair come early) and
 * the palette constant register pair (a0/v1). Expression forms of palette_bits, the height local
 * and the sign constant compile identically. In the permuter farm.
 * 26 October 2026 (M14): upload stores in retail order (palette at +6 right after +0, texture at
 * +14 last) fix the store block: 16 lines left, all in the descriptor block. A statement-order
 * climb over the descriptor block finds nothing better.
 */
#include "include_asm.h"

typedef unsigned long TextureBits;
typedef struct {
    TextureBits bits;
    unsigned short first_offset;
    unsigned short second_offset;
    unsigned short width_shift;
    unsigned short height_shift;
} TextureEntry;


extern int D_001A72D0;
extern int D_001A72DC;
extern int D_001A72E0;
extern int D_001A72D8 __attribute__((sda));
extern TextureBits ref_0027C878_00 __attribute__((sda));
extern TextureBits ref_0027C878_01 __attribute__((sda));
extern int ref_0027C878_02 __attribute__((sda));
extern char *ref_0027C878_03;
extern char D_00138AD0[];
extern char D_00138DC0[];
extern TextureEntry ref_0027C878_04[];
extern int ref_0027C878_05;
extern char *ref_0027C878_06;
extern char ref_0027C878_07[];

/* Resolve a cached texture descriptor, allocating VRAM and queuing its upload
 * when necessary. Negative identifiers select the render-target descriptors. */
TextureBits func_0027C878(int id)
{
    if (id < 0) {
        if (id == -5)
            return (D_001A72E0 >> 8) | 0x27020000UL | (0xC800UL << 19);
        if (id == -8) {
            TextureBits frame = (D_001A72DC >> 8) | 0x25B20000UL;
            TextureBits palette = ((TextureBits)ref_0027C878_02 << 37) | (0xC800UL << 19);
            return frame | palette | (0x8000UL << 46);
        }
        if (id == -7)
            return (D_001A72D8 >> 8) | 0x24020000UL | (0xC800UL << 19);
        if (id == -6)
            return (D_001A72DC >> 8) | 0x24020000UL | (0xC800UL << 19);
        if ((unsigned int)(id + 2) < 2) {
            int base;
            TextureBits result;
            TextureBits frame;
            if (ref_0027C878_00 != 0)
                return ref_0027C878_00;
            base = (D_001A72D0 + 0x1FFF) & -0x2000;
            D_001A72D0 = base + 0x20000;
            frame = (base >> 13) | 0x02040000;
            result = (base >> 8) | 0x20210000UL | (0xC000UL << 19);
            *(int *)(ref_0027C878_03 + 0) = 0x10000003;
            *(int *)(ref_0027C878_03 + 4) = 0;
            *(int *)(ref_0027C878_03 + 8) = 0;
            *(int *)(ref_0027C878_03 + 12) = 0x50000003;
            *(int *)(ref_0027C878_03 + 16) = 0x8001;
            *(int *)(ref_0027C878_03 + 20) = 0x20000000;
            *(int *)(ref_0027C878_03 + 24) = 0xEE;
            *(int *)(ref_0027C878_03 + 28) = 0;
            *(TextureBits *)(ref_0027C878_03 + 32) = frame;
            *(int *)(ref_0027C878_03 + 40) = 0x4D;
            *(int *)(ref_0027C878_03 + 44) = 0;
            *(TextureBits *)(ref_0027C878_03 + 48) =
                (D_001A72DC >> 8) | 0x24020000UL | (0xC800UL << 19);
            *(int *)(ref_0027C878_03 + 56) = 7;
            *(int *)(ref_0027C878_03 + 60) = 0;
            *(int *)(ref_0027C878_03 + 64) = 0x3000002F;
            *(char **)(ref_0027C878_03 + 68) = D_00138AD0;
            *(int *)(ref_0027C878_03 + 72) = 0;
            *(int *)(ref_0027C878_03 + 76) = 0x5000002F;
            ref_0027C878_00 = result;
            ref_0027C878_03 += 80;
            return result;
        }
        if ((unsigned int)(id + 4) < 2) {
            int base;
            TextureBits result;
            TextureBits frame;
            if (ref_0027C878_01 != 0)
                return ref_0027C878_01;
            base = (D_001A72D0 + 0x1FFF) & -0x2000;
            D_001A72D0 = base + 0x2000;
            frame = (base >> 13) | 0x02010000;
            result = (base >> 8) | 0x18204000UL | (0xB000UL << 19);
            *(int *)(ref_0027C878_03 + 0) = 0x10000003;
            *(int *)(ref_0027C878_03 + 4) = 0;
            *(int *)(ref_0027C878_03 + 8) = 0;
            *(int *)(ref_0027C878_03 + 12) = 0x50000003;
            *(int *)(ref_0027C878_03 + 16) = 0x8002;
            *(int *)(ref_0027C878_03 + 20) = 0x10000000;
            *(int *)(ref_0027C878_03 + 24) = 0xEE;
            *(int *)(ref_0027C878_03 + 28) = 0;
            *(TextureBits *)(ref_0027C878_03 + 32) = frame;
            *(int *)(ref_0027C878_03 + 40) = 0x4D;
            *(int *)(ref_0027C878_03 + 44) = 0;
            *(TextureBits *)(ref_0027C878_03 + 48) =
                (D_001A72DC >> 8) | 0x24020000UL | (0xC800UL << 19);
            *(int *)(ref_0027C878_03 + 56) = 7;
            *(int *)(ref_0027C878_03 + 60) = 0;
            *(int *)(ref_0027C878_03 + 64) = 0x3000002F;
            *(char **)(ref_0027C878_03 + 68) = D_00138DC0;
            *(int *)(ref_0027C878_03 + 72) = 0;
            *(int *)(ref_0027C878_03 + 76) = 0x5000002F;
            ref_0027C878_01 = result;
            ref_0027C878_03 += 80;
            return result;
        }
    } else {
        TextureEntry *entry = &ref_0027C878_04[id];
        if (entry->bits == 0) {
            int base = D_001A72D0;
            int width = (short)entry->width_shift;
            int shift = width - 6;
            int palette, texture, count, height;
            long bits, column_bits, width_bits, height_bits, palette_bits;
            if (shift < 0)
                shift = 0;
            palette = base >> 8;
            base += 0x400;
            texture = base >> 8;
            column_bits = (long)texture | ((long)(1 << shift) << 14);
            width_bits = ((long)((TextureBits)entry->width_shift << 48) >> 22) | 0x01300000L;
            height = (short)entry->height_shift;
            height_bits = (long)((TextureBits)entry->height_shift << 48) >> 18;
            palette_bits = ((long)palette << 37) | (0x8000L << 19);
            D_001A72D0 = base + (1 << (width + height));
            bits = column_bits;
            bits |= width_bits;
            bits |= height_bits;
            bits |= palette_bits;
            bits |= (-9223372036854775807L - 1);
            entry->bits = bits;
            count = ref_0027C878_05;
            if (count < 64) {
                char *upload = ref_0027C878_07 + (count << 4);
                *(unsigned int *)(upload + 0) = (unsigned int)(ref_0027C878_06 + (entry->second_offset << 4));
                *(short *)(upload + 6) = palette;
                *(short *)(upload + 4) = 0;
                *(unsigned int *)(ref_0027C878_07 + (count << 4) + 8) = (unsigned int)(ref_0027C878_06 + (entry->first_offset << 4));
                *(unsigned char *)(upload + 12) = entry->width_shift;
                *(unsigned char *)(upload + 13) = entry->height_shift;
                *(short *)(upload + 14) = texture;
                ref_0027C878_05 = count + 1;
            }
        }
    }
    return ref_0027C878_04[id].bits;
}
