/* Game -O2 -G8: 312/312 bytes in us/pal/us2, 0/27 each, first mismatch +0x9C. The identity really consumes a0 and the random range helper takes (0, count - 1); the old draft omitted those live arguments. Only two preheader words exchange the table-pointer copy and -1 terminator, plus one addu operand order differs in the chosen-record address. Scheduling profile alternatives did not fix it.
 * Profile: -O2 -G8 -ffunction-sections
 * us: instruction at +0x9c differs
 * pal: instruction at +0x9c differs
 * us2: instruction at +0x9c differs
 */
#include "include_asm.h"

typedef struct {
    short key;
    unsigned char a;
    unsigned char b;
} Elem;

extern Elem D_L00_001A7D60 __attribute__((sda));
extern Elem D_L00_001A7D48 __attribute__((sda));
extern Elem D_L00_001A7D78 __attribute__((sda));

extern int func_L00_002A4EF0(int);
extern int func_L00_002ADEA0(int);
extern int func_002A7820(int, int);

int func_L00_002D1DA0(int a0, int *a1, int *a2)
{
    int buf[20];
    Elem *table;
    Elem *p;
    int count = 0;
    int idx;
    int key;

    key = func_L00_002A4EF0(a0);
    if (func_L00_002ADEA0(3) == 2) {
        table = &D_L00_001A7D60;
    } else if (func_L00_002ADEA0(3) == 3) {
        table = &D_L00_001A7D48;
    } else if ((func_L00_002ADEA0(3) ^ 4) != 0) {
        table = 0;
    } else {
        table = &D_L00_001A7D78;
    }
    if (table != 0) {
        idx = 0;
        if (table->key != -1) {
            p = table;
            do {
                if (key == p->key) {
                    buf[count] = idx;
                    count++;
                }
                p++;
                idx++;
            } while (p->key != -1);
        }
    }
    idx = count - 1;
    if (count != 0) {
        int n = func_002A7820(0, idx);
        Elem *e = &table[buf[n]];
        *a1 = e->a;
        *a2 = e->b;
        return 1;
    }
    *a1 = 1;
    return 0;
}
