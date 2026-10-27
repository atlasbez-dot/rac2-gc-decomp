/*
 * Near miss (M23, 2026-10-26): 576/576 bytes, 16 differing instructions. us: 0/28.
 * Profile: -O2 -G32 -Wa,-G32 -ffunction-sections (as its siblings 002D0930-g32.c, 002CFBE8-g32.c).
 * Both cursor loops and the item switch match. Residual: the buy test. Retail tests cost == 0x5A
 * first and re-tests cost != 0x5A after `limit < cost` (no jump threading), with the table copy
 * in $s0 made in the delay slot; this C tests `cost <= limit` first, which keeps the re-test but
 * moves the branch order and registers. The `(unsigned char)item` compare gives retail's andi.
 * M39 (2026-10-26): written `(cost != 0x5A && cost <= limit) || ...` the .jump dump has retail's
 * shape (beq to the re-test, B's fall-through into it), but cse1 skips the B block
 * (-fcse-skip-blocks), threads the first jump and then folds the fall-through re-test away: 34
 * off. Retail's re-test survived, so its cse1 could not skip that block; the first jump was
 * threaded later (jump2). Ternary, unsigned char cost, re-read costs and a separate table
 * address are all worse (34-67 off).
 */
#include "common.h"

typedef struct { char prefix[0x14]; char *source; int value; char gap[0x118]; int fallback; } SelectionCallback;
typedef struct { char reserved[0x1C4]; int flags; } CallbackMenuState;
typedef struct { unsigned char f0; unsigned char f1; unsigned char item; unsigned char cost; } ShopEntry;

extern SelectionCallback D_001F2840;
extern CallbackMenuState D_00138180;
extern int D_001AB9EC __attribute__((sda));
extern ShopEntry D_001ABCD0[] MACRO_ADDR;
extern unsigned char D_001A7A60[] MACRO_ADDR;
extern unsigned char D_001A7A40[] MACRO_ADDR;
extern short D_001A7A10[4];
extern int func_002B0E90(void);
extern int func_002E5E58(int, unsigned int, void *);
extern void func_002923C0(int);

int func_002CF5B0(void)
{
    int result = 0;
    int limit = func_002B0E90();
    int flags = D_00138180.flags;

    if (flags & 0x10) {
        int value;
        int status;
        D_001AB9EC = 0;
        value = *(int *)(D_001F2840.source + 0xE0);
        if (value != 0)
            D_001F2840.value = value;
        else if (D_001F2840.fallback == 0) {
            status = -1;
            goto finish;
        }
        status = 0;
finish:
        return status;
    }
    if (flags & 0x900) {
        D_001AB9EC = 0;
        result = 1;
    } else {
        if (flags & 0x1000) {
            func_002E5E58(3, 0, 0);
            do {
                ShopEntry *table;
                if (--D_001AB9EC < 0)
                    D_001AB9EC = 11;
                table = D_001ABCD0;
                if (table[D_001AB9EC].cost != 100)
                    break;
            } while (1);
        } else if (flags & 0x4000) {
            int cur;
            ShopEntry *table;
            func_002E5E58(3, 0, 0);
            cur = D_001AB9EC;
            table = D_001ABCD0;
            do {
                if (++cur >= 12)
                    cur = 0;
            } while (table[cur].cost == 100);
            D_001AB9EC = cur;
        }
        if (D_00138180.flags & 0x40) {
            ShopEntry *table = D_001ABCD0;
            int cost = table[D_001AB9EC].cost;
            if ((cost <= limit && cost != 0x5A) || (cost == 0x5A && D_001A7A60[0] != 0)) {
                unsigned char *slot;
                func_002E5E58(4, 0, 0);
                slot = &D_001A7A40[table[D_001AB9EC].item];
                if (*slot)
                    *slot = 0;
                else
                    *slot = 1;
                {
                    int item = table[D_001AB9EC].item;
                    if (item == 9 || item == 10 || (unsigned char)item == 2 || (unsigned char)item == 11)
                        func_002923C0(D_001A7A10[4]);
                }
            } else
                func_002E5E58(5, 0, 0);
        }
    }
    return result;
}
