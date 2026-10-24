/* Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 188/180 bytes, 0/8 US places: TImode copied through added address registers instead of direct +0x10 loads/stores. Local heading/value loads fix initial schedule. Reopen with object layout/copy evidence.
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

void func_L02_003C0890(u8 *object) {
    u8 *data = *(u8 **)(object + 0x68);
    u8 *child;
    if (object[0x20] == 0) {
        *(int *)(data + 4) = 0;
        object[0x20] = 1;
        object[0x30] = 0x80;
        {
            f32 heading = *(f32 *)(object + 0xF8);
            int value = *(int *)(data + 0x14);
            *(int *)(data + 8) = 0;
            *(f32 *)(data + 0x10) = heading;
            *(int *)(data + 0x18) = value;
        }
        child = func_0029EFD0(0xAFC);
        *(u8 **)(data + 0x1C) = child;
        if (child) {
            child[0x30] = object[0x30];
            child = *(u8 **)(data + 0x1C);
            *(u16 *)(child + 0x32) = *(u16 *)(object + 0x32);
            child = *(u8 **)(data + 0x1C);
            ((struct PositionRecord *)child)->position = ((struct PositionRecord *)object)->position;
            child = *(u8 **)(data + 0x1C);
            *(u16 *)(child + 0x34) |= 0x41;
        } else {
            func_0026FEB8(ref_L02_003C0890_00, *(short *)(object + 0xB2));
        }
    }
}
