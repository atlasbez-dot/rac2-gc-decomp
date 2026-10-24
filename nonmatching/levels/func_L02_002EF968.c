/* Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 148/148 bytes, 0/8 US places: two source/destination cursor increments are reversed. Indexed, explicit postincrement and full cursor forms tried; reopen with loop source-lifetime evidence.
 * All carrying us/us2/pal placements checked; logs private.
 * Earlier LQ/SQ-only screening is superseded: TImode emits the copies.
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef int TI128 __attribute__((mode(TI)));
struct QuadPacket {
    TI128 vertices[4];
    int colors[4];
    f32 uv[4][2];
    long state70, state78, state80, state88;
};
extern void func_00281DE8(struct QuadPacket *, int, int, int);
extern u8 *func_0029EFD0(int);
extern void func_00282C88(TI128 *);
extern void func_002833F0(void *, void *);
extern f32 func_00282E48(void *, void *);
extern void func_0026FEB8(const char *, ...);
extern char ref_L02_003C0890_00[];
struct PositionRecord { TI128 first; TI128 position; };

void func_L02_002EF968(struct QuadPacket *packet, int texture, int color, f32 (*uv)[2], TI128 *vertices, int flags) {
    int i;
    func_00281DE8(packet, texture, flags, 128);
    for (i = 0; i < 4; i++) {
        packet->uv[i][0] = uv[i][0];
        packet->uv[i][1] = uv[i][1];
        packet->colors[i] = color;
        packet->vertices[i] = vertices[i];
    }
}
