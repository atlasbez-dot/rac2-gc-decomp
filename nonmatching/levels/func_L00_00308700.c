/* func_L00_00308700: M3 2026-10-26: written from retail (LRU lookup over 8 entries, swap with entry 0): 272/288. Retail keeps %hi of D_L00_001C93A0 in $s4 and best<<4 across the call, builds D+0x30 fresh for the swap and walks the ages from &e[0].age.
 */
typedef int Q128 __attribute__((mode(TI)));

typedef union {
    struct {
        int key;
        int age;
        unsigned char *data;
        int pad;
    } s;
    Q128 q;
} Ent_308700;

typedef struct {
    unsigned char *base;
    short *info;
    char pad8[0x28 - 8];
    int active;
    int pad2C;
    Ent_308700 e[8];
} Cache_308700;

extern Cache_308700 D_L00_001C93A0;
extern int D_001B18D8;
extern void func_00297550(unsigned char *, int, unsigned char *, short *);

int func_L00_00308700(int key)
{
    int found;
    int best;
    int i;

    if (D_L00_001C93A0.active == 0)
        return 0;
    found = 0;
    best = 0;
    for (i = 0; i < 8; i++) {
        if (D_L00_001C93A0.e[i].s.key == key)
            break;
        if (D_L00_001C93A0.e[i].s.age < D_L00_001C93A0.e[best].s.age)
            best = i;
    }
    if (i == 8) {
        func_00297550(D_L00_001C93A0.e[best].s.data, key, D_L00_001C93A0.base, D_L00_001C93A0.info);
        D_L00_001C93A0.e[best].s.key = key;
        i = best;
        found = 1;
    }
    if (i != 0) {
        Q128 tmp = D_L00_001C93A0.e[0].q;
        D_L00_001C93A0.e[0].q = D_L00_001C93A0.e[i].q;
        D_L00_001C93A0.e[i].q = tmp;
    }
    D_L00_001C93A0.e[0].s.age = D_001B18D8;
    return found;
}
