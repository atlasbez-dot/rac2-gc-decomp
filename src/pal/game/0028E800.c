#include "include_asm.h"

INCLUDE_ASM("asm/pal/game", func_PAL_0028E800);

extern char D_00255330[];
extern int D_001B1874 __attribute__((sda));
extern void func_0028B4D8(char *);
extern void func_0028E2A8(void);

/* Walks the records, caps their timers, moves their positions on, and lets a
   record run its own handler. */
int func_PAL_0028E9B8(int arg)
{
    char *rec;
    char *end;
    int count = 0;

    func_0028E2A8();
    rec = (char *)D_00255330;
    end = (char *)D_00255330 + 0x750;
    do {
        int v;

        if ((*(int *)(rec + 4) & 0x10) || D_001B1874) {
            v = *(int *)(rec + 0x7C);
            if (v < 8) {
                *(int *)(rec + 0x7C) = 8;
            }
            v = *(int *)(rec + 0x7C);
        } else {
            v = *(int *)(rec + 0x7C);
        }

        if (v > 0) {
            v = v - 1;
            *(int *)(rec + 0x7C) = v;
            if (v > 0) {
                count++;
                if (*(int *)(rec + 0x6C) < 30) {
                    *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) + 1;
                }
            } else if (*(int *)(rec + 0x6C) >= -5) {
                *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) - 1;
            }
        } else if (*(int *)(rec + 0x6C) >= -5) {
            *(int *)(rec + 0x6C) = *(int *)(rec + 0x6C) - 1;
        }

        if (*(int *)(rec + 0x68) != 0) {
            if (*(int *)(rec + 0x6C) == -6) {
                func_0028B4D8(rec);
            }
        }

        if (arg != 0) {
            void (*handler)(char *) = *(void (**)(char *))(rec + 0x14);
            if (handler) {
                handler(rec);
            }
        }
        rec += 0x90;
    } while ((int)rec < (int)end);
    return count;
}

