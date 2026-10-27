/* Reads `count` records of four words (two scaled positions and two ids) into the shared
   table of 16-byte entries, resetting the table cursor first. */
typedef struct {
    long long clear;
} Pad8;

typedef struct {
    Pad8 head;
    short b;
    short a;
    short c;
    short d;
} Entry_001B9740;

extern int D_001B1600 __attribute__((sda));
extern Entry_001B9740 D_001B9740[];
extern short func_00282A18(int);

void func_00291DE0(int *p, int count) {
    for (D_001B1600 = 0; D_001B1600 < count; D_001B1600++) {
        int w0 = *p++;
        int w1 = *p++;
        int w2 = *p++;
        int w3 = *p++;
        D_001B9740[D_001B1600].a = w0 >> 4;
        D_001B9740[D_001B1600].b = w1 >> 4;
        D_001B9740[D_001B1600].c = func_00282A18(w2);
        D_001B9740[D_001B1600].d = func_00282A18(w3);
        D_001B9740[D_001B1600].head.clear = 0;
    }
}
