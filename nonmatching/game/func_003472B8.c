/* func_003472B8: Opus closer M1 near miss, 26 October 2026.
   Profile: -O2 -G0 -ffunction-sections, own unit.
   428/428 bytes, 20 differing instructions (was 46). Separate x/y locals per call give retail f20/f21; the `bits` temporary per call gives the sltu form. Left: the table base and the flag base take a1/v1 the other way round, and the pad copy is scheduled earlier. */
#include "common.h"
#define FLD(base, T, off) (((struct { u8 pad[off]; T v; } *)(base))->v)
typedef struct { int x; int y; } Pair;
typedef struct { u8 pad[6]; s16 index; u8 pad8[2]; } MenuEntry;
extern MenuEntry D_00282998[];
extern u8 D_001A7AF8[];
extern u8 D_001A7A80[];
extern Pair ref_003472B8_00;
extern void func_00335E68(char *, int);
extern float *func_00335E10(char *);
extern void func_00335E38(char *, float, float, float, float);
void func_003472B8(char *obj) {
    Pair pad;
    char *a; char *b; float x, y, x2, y2; u8 *flags; int bits;
    {
    MenuEntry *entry = &D_00282998[FLD(obj, int, 0x4FC) + (FLD(obj, int, 0x500) << 2)];
    int index = entry->index;
    if (D_001A7AF8[index] == 0) return;
    a = obj + 0x2E8;
    pad = ref_003472B8_00;
    flags = &D_001A7A80[index];
    b = obj + 0x330;
    bits = flags[0] & 4;
    func_00335E68(a, (flags[0] & 1) | (bits != 0));
    { int b2 = flags[0] & 0x10; func_00335E68(b, b2 != 0); }
    x = FLD(obj, float *, 0x498)[0] + func_00335E10(a)[0] + (float)pad.x;
    y = FLD(obj, float *, 0x498)[1] + func_00335E10(a)[1] + (float)pad.y;
    func_00335E38(a, x, y, 0.0f, 0.0f);
    x2 = FLD(obj, float *, 0x498)[0] + func_00335E10(b)[0] + (float)pad.x;
    y2 = FLD(obj, float *, 0x498)[1] + func_00335E10(b)[1] + (float)pad.y;
    func_00335E38(b, x2, y2, 0.0f, 0.0f);
    }
}
