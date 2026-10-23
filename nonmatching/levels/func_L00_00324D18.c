/* Retained C, not matched.
   Profile: -O2 -G0 -ffunction-sections -frac2-keep-block-order -frac2-gcse-unsplit-edges.
   304/304 bytes; 0/27, first mismatch +0x54. Plain C with three pointers, five float parameters, health guard and unaligned 12-byte record copy; exact prologue under both CFG switches. Guard branch polarity/likely slot, call setup and return transport still differ. Six bounded trials. */

typedef unsigned char u8;
typedef struct { float x, y, z; } V3;
extern u8 D_00189E20[];
extern V3 D_L00_001AA300 __attribute__((aligned(1)));
extern float *func_002AB1F0(u8 *);
extern u8 *func_002AF580(void *, void *, void *, int, int, int, void *, void *, float, float, float, float, float);
u8 *func_L00_00324D18(void *a, void *b, void *c, float d, float e, float f, float g, float h)
{
    V3 point;
    float scratch[4];
    u8 *resident = D_00189E20;
    u8 *object = *(u8 **)(resident + 0x1450);
    float *health;
    if (object == 0 || object[0x20] == 0xfe || object[0x20] == 0xfd ||
        (health = func_002AB1F0(object)) == 0 || !(*health > 0.0f)) {
        point = D_L00_001AA300;
        return func_002AF580(a, b, scratch, 0, 0, 0, c, &point, d, e, f, g, h);
    }
    return *(u8 **)(resident + 0x1450);
}
