#include "include_asm.h"

typedef unsigned char u8;

/* The request block the entry's completion callback reads. */
typedef struct {
    u8 pad0[0x8C];
    unsigned int busy;
    short a90;
    short a92;
    short a94;
    short a96;
    u8 pad1[4];
    short a9C;
    u8 pad2[2];
    int aA0;
    int aA4;
} Request_002B7088;

extern Request_002B7088 D_001A63A8;
extern char D_0014B540[];

extern void func_002B7F08(void);
extern void func_00133350(long, int, int, int, int, int, int, int, int, int, void (*)(void), unsigned long);

/* Starts the entry's request when none is pending.  Returns 1 when it was
   started, 0 when one is pending or the entry has no data. */
int func_002B7088(int a0, int index, int a2, int a3)
{
    char *b;
    int h;

    if (D_001A63A8.busy != 0)
        return 0;
    b = D_0014B540;
    h = *(int *)(b + index * 8 + 0x5300);
    if (h == 0)
        return 0;
    D_001A63A8.a94 = a2;
    D_001A63A8.aA0 = 10;
    D_001A63A8.aA4 = 48000;
    D_001A63A8.busy = 0xFFFFFFFFu;
    D_001A63A8.a90 = a0;
    D_001A63A8.a9C = 1;
    D_001A63A8.a96 = 1;
    D_001A63A8.a92 = a3;
    func_00133350(h + *(int *)(b + 0x52FC), 0, 0, 0, (short)a3, 0, 1, 0, 0, 32,
                  func_002B7F08, (unsigned long)(unsigned int)&D_001A63A8.busy);
    return 1;
}
