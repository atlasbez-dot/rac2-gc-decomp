/* func_0028DDD8 (boot, 284 B, 28 places): M29 2026-10-26, 284/284 B under -O2 -G0,
   4 lines off, register-only: retail loads object->y into $v1 and object->x into $v0
   (here swapped). Permuter queued. */
typedef unsigned char u8;

/* Draws a 256x64 meter widget: lays out its position, draws the fill (frame 1, width
   0x1B + 221 * value / max), the frame (frame 0) and a 32x32 cap (frame 2), the cap
   lit only while the hero flag at 0x18B69A is set; returns the widget's width. */
extern short D_0018B69A;
extern void func_0028B740(void *, int *, int *);
extern void func_0028B7A8(void *, int *, int *, int, int);
extern int func_0028E588(int, int);
extern void func_0028ECD8(int, int, int, int, int, int);
extern void func_0028E868(int, int, int, int, int, int);

typedef struct {
    u8 pad0[8];
    int max;
    u8 padC[0x44];
    int x;
    int y;
    int width;
    int height;
    u8 pad60[0xC];
    int style;
    u8 pad70[4];
    int value;
} Meter28DDD8;

int func_0028DDD8(Meter28DDD8 *object)
{
    int x;
    int y;
    int width;

    y = object->y;
    x = object->x;
    object->width = 0x100;
    object->height = 0x40;
    func_0028B740(object, &x, &y);
    func_0028B7A8(object, &x, &y, object->style, 0);
    width = object->value * 0xDD / object->max + 0x1B;
    func_0028ECD8(func_0028E588(0x7558, 1), x, y, width, 0x40, 0x80);
    func_0028E868(func_0028E588(0x7558, 0), x, y, 0x100, 0x40, 0x80);
    func_0028E868(func_0028E588(0x7558, 2), x, y, 0x20, 0x20, D_0018B69A != 0 ? 0x80 : 0);
    return object->width;
}
