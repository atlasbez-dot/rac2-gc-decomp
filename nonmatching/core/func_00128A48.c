/* from src/core/00128898.c: the catalogue row is 220 bytes but the function is 212.
   Its first two words are the linker remnant rac1-decomp names func_00124D10 and keeps
   with LINKER_REMNANT (`addiu $sp, $sp, 0x20`, then `nop`), and the USA v2.00 symbol
   table still gives func_00128A48 a size of 0x8 and lists func_00128A50 as its own
   entry. The C below is rac1-decomp's func_00124D18 and reproduces the 212 bytes at
   0x00128A50 exactly: tools/check.py prints "212 bytes, expected 220" and --diff lines
   the candidate up instruction for instruction two words behind retail. Unblocked by
   splitting the row in tools/levels.py, not by more C. */
#include "common.h"

/* 0x330-stride entry table of the DBC library, and the slot table that follows it. */
typedef struct {
    char unk_00[4];
    int  unk_04;
    int  unk_08;
    char *unk_0C;
    char unk_10[0x320];
} Ent330;

extern Ent330 r1_D_0015B640[];

extern char r1_D_0015B650[];

extern int func_00128D58(int);

extern void *func_00128DB0(int);

extern int func_00128E98(unsigned char *, int *);

extern void *func_001153D4(void *, const void *, unsigned int);

/* Read entry id's current record into dst: open the entry if it is not
   (func_00128D58), fetch the record (func_00128DB0), copy its p[2]-byte
   payload from +0x1C and hand the bytes after it to func_00128E98 with
   the entry's slot array. Returns the length, or -1. */
int func_00128A48(int id, void *dst) {
    unsigned char *p;

    if (*(int *)((char *)r1_D_0015B640 + id * 0x330) == 0) {
        return -1;
    }
    if (r1_D_0015B640[id].unk_04 == 0) {
        if (func_00128D58(id) < 0) {
            return -1;
        }
    }
    p = (unsigned char *)func_00128DB0(id);
    if (p[2] != 0) {
        unsigned char *src = p + 0x1C;

        if (src != 0) {
            func_001153D4(dst, src, p[2]);
            func_00128E98(p + 0x1C + p[2], (int *)(r1_D_0015B650 + id * 0x330));
        }
    }
    if (*(int *)(p + 4) == 0) {
        return -1;
    }
    return p[2];
}
