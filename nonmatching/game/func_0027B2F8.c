/* func_0027B2F8, 328 bytes, 27 placements.  Needs its own -O2 -G0 -ffunction-sections
   -mno-split-addresses unit: the eight screen words are NOT_SDA macro stores
   (`lui $at; sw`), which keeps them out of the call slots.  M30: same size as
   retail; only the registers differ (retail keeps the width copy in $a3 and the
   half sizes in $t0/$t1, here $t1 and $a3/$t0), which also moves the schedule.
   Queued for the permuter. */
#include "include_asm.h"
#include "common.h"

typedef struct {
    char pad0[0xA0];
    float near;
    float far;
    char padA8[8];
    float fov;
    char padB4[0x200 - 0xB4];
    float halfWidth;
    float halfHeight;
    float width4;
    float height4;
    char pad210[8];
    float y;
    float z;
    char pad220[8];
    float w;
    float x;
} View_0027B2F8;

extern View_0027B2F8 D_001B9040;
extern int D_001A7340 NOT_SDA;
extern int D_001A7344 NOT_SDA;
extern int D_001A7348 NOT_SDA;
extern int D_001A734C NOT_SDA;
extern int D_001A7350 NOT_SDA;
extern int D_001A7354 NOT_SDA;
extern int D_001A7358 NOT_SDA;
extern int D_001A735C NOT_SDA;
extern void func_0027AB40(void);
extern float func_00283CE0(int);

/* Sets the screen size: the scissor box around the 2048 GS centre, the half sizes, the
   projection parameters, then rebuilds the view. */
void func_0027B2F8(int width, int height, float fov, float y, float z, float w, float x)
{
    View_0027B2F8 *view = &D_001B9040;
    int halfHeight = height >> 1;
    int halfWidth = width >> 1;

    view->fov = fov;
    D_001A7350 = (0x800 - halfWidth) << 4;
    D_001A7354 = (0x800 - halfHeight) << 4;
    D_001A7358 = (halfWidth + 0x800) << 4;
    D_001A735C = (halfHeight + 0x800) << 4;
    view->near = 32.0f;
    view->far = 1048576.0f;
    D_001A7340 = width;
    D_001A7348 = halfWidth;
    D_001A734C = halfHeight;
    D_001A7344 = height;
    view->halfWidth = func_00283CE0(width) * 0.5f;
    view->halfHeight = func_00283CE0(height) * 0.5f;
    view->width4 = view->halfWidth * 4.0f;
    view->height4 = view->halfHeight * 4.0f;
    view->y = y;
    view->z = z;
    view->w = w;
    view->x = x;
    func_0027AB40();
}
