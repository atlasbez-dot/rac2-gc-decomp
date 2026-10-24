/* Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 180/180 bytes, 0/3 US places: initial stack query pointer and save schedule differ. Reassigning position to its local copy restores s4 lifetime; explicit query variant differs. Reopen with initialization-order evidence.
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

int func_L02_00348420(TI128 *position, struct PointList *list) {
    TI128 point;
    int i, nearest = -1;
    f32 distance, minimum = 9999999.0f;
    point = *position;
    position = &point;
    if (list) {
        for (i = 0; i < list->count; i++) {
            distance = func_00282E48(position, &list->points[i]);
            if (distance < minimum) {
                minimum = distance;
                nearest = i;
            }
        }
    }
    return nearest;
}
