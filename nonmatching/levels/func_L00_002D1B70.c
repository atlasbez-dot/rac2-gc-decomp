/* Game -O2 -G8 with gcse-unsplit-edges/keep-block-order: 192/208 bytes in us/pal/us2, 0/27 each. This is an actual table-selector and byte-key search reconstruction, replacing a comment-only screen. Canonical selector and known-size sda tables are used. Crossjumped selector/success blocks differ; straightforward nested returns measured 200 bytes, while hoisting a table before a call added a saved register.
 * Profile: -O2 -G8 -ffunction-sections -frac2-gcse-unsplit-edges -frac2-keep-block-order
 * us: 192 bytes, expected 208
 * pal: 192 bytes, expected 208
 * us2: 192 bytes, expected 208
 */
#include "include_asm.h"
typedef struct { short key; unsigned char a, b; } TableEntry;
extern TableEntry D_L00_001A7D60 __attribute__((sda));
extern TableEntry D_L00_001A7D48 __attribute__((sda));
extern TableEntry D_L00_001A7D78 __attribute__((sda));
extern int func_L00_002ADEA0(int);
int func_L00_002D1B70(int id, int *out)
{
    TableEntry *table, *p;
    if (func_L00_002ADEA0(3) == 2) table = &D_L00_001A7D60;
    else if (func_L00_002ADEA0(3) == 3) table = &D_L00_001A7D48;
    else if ((func_L00_002ADEA0(3) ^ 4) != 0) table = 0;
    else table = &D_L00_001A7D78;
    if (table) {
        if (table->key != -1) {
        p = table;
        do {
            if (id == p->a) goto found;
            p++;
            table++;
        } while (p->key != -1);
        }
    }
    *out = 0;
    return 0;
found:
    *out = table->key;
    return 1;
}
