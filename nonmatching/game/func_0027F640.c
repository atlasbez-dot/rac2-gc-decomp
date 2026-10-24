/* Complete manual reconstruction; NOT MATCHING and never linked.
   Tested profile: -O2 -G0 -ffunction-sections
   Actual final-source coverage: us: 0/28 placements, 804 compiled bytes; us2: absent from both catalogues; pal: absent from both catalogues.
   804/808 bytes. Palette addressing and repeated control-character loads differ; the palette full extent remains unknown. No shortened SDA object was introduced. Mixed f12-f14/GPR inputs and 64-bit texture/color are retained.
   Reopen only with: Establish the complete palette object and its legitimate storage profile, then recover the genuine control-character alias/lifetime model.
*/

typedef unsigned char u8;
typedef unsigned long u64;
/* Font metrics are four bytes per glyph: atlas u/v, vertical offset, advance. */
extern int D_001B166C __attribute__((sda));
extern int D_001B1668 __attribute__((sda));
extern int D_001A89B0[] __attribute__((sda));
extern float func_00283CE0(int);
extern void func_0027E1A0(int u, int v, int width, int height,
                         unsigned int *colors, u64 texture,
                         float x, float y, float draw_width, float draw_height);

void func_0027F640(u64 color, u8 *text, int length, u64 texture, u8 *metrics,
                   float x, float y, float scale)
{
    unsigned int colors[4];
    float height, offset;
    int i;
    u8 *p;
    if (D_001B166C == 0)
        D_001A89B0[0] = (int)color;
    i = 0;
    height = scale * 16.0f;
    if (length != 0 && text[0] != 0) {
        p = text;
        do {
            if ((unsigned int)(p[0] - 8) < 8) {
                if (D_001B1668 != 0) {
                    color &= 0xFF000000UL;
                    color |= D_001A89B0[p[0] - 8] & 0xFFFFFF;
                }
                goto next_character;
            }
            if (((signed char *)metrics)[p[0] * 4 + 3] != 0) {
                offset = func_00283CE0(((signed char *)metrics)[p[0] * 4 + 2]) * scale;
                if ((u8)(p[0] + 128) < 40) {
                    u8 *accent = &metrics[(p[0] + 64) * 4];
                    float dx = func_00283CE0(((signed char *)accent)[3]) * scale;
                    float dy = func_00283CE0(((signed char *)accent)[2]) * scale;
                    colors[2] = colors[1] = colors[0] = colors[3] = (int)color;
                    func_0027E1A0(accent[0], accent[1], 16, 16, colors, texture,
                                  x + dx, y + dy, height, height);
                }
                if (p[0] < 32) {
                    u64 sum = (color & 255) + ((color >> 8) & 255) + ((color >> 16) & 255);
                    int gray = (int)sum / 3;
                    int shade = (int)(color & 0xFF000000UL) + (gray << 16) + (gray << 8) + gray;
                    colors[2] = colors[1] = colors[0] = colors[3] = shade;
                    func_0027E1A0(metrics[p[0] * 4], metrics[p[0] * 4 + 1],
                                  24, 16, colors, texture,
                                  x, y + offset, scale * 24.0f, scale * 16.0f);
                } else if (p[0] > 32) {
                    colors[2] = colors[1] = colors[0] = colors[3] = (int)color;
                    func_0027E1A0(metrics[p[0] * 4], metrics[p[0] * 4 + 1],
                                  16, 16, colors, texture,
                                  x, y + offset, height, height);
                }
                x += func_00283CE0(((signed char *)metrics)[p[0] * 4 + 3]) * scale;
            }
next_character:
            i++;
            p++;
            if (i == length)
                break;
        } while (p[0] != 0);
    }
}
