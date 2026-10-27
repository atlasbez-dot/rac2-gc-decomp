/* func_L00_003B69D8: M3 2026-10-26: 180/180 bytes, 7 register-only lines. f68 read into a local before the two calls, then p = t and q = t + 0x10; only the loop counter ($s3) and the D_L00_001B8FF0 base ($s2) are swapped. In the permuter queue.
 */
typedef struct NODE {
    char pad0[0x68];
    void *f68;
} NODE;

extern void func_L00_003B6B70();

extern void func_L00_003B6F88();

extern void func_00283098(void *, void *, void *);

extern void func_00282CC0(void *, void *, void *);

extern void func_002833F0(void *, void *);

extern void func_002A0F48(void *);

extern char D_L00_001B8FF0[];

void func_L00_003B69D8(NODE *a0)
{
    void **p;
    char *q;
    void **t;
    int i;
    t = a0->f68;
    func_L00_003B6B70();
    func_L00_003B6F88(a0);
    q = (char *)t + 0x10;
    p = t;
    for (i = 1; i >= 0; i--) {
        func_00283098((char *)*p + 0x10, q, D_L00_001B8FF0);
        q += 0x10;
        func_00282CC0((char *)*p + 0x10, (char *)*p + 0x10, D_L00_001B8FF0 - 0x230);
        func_002833F0((char *)*p + 0xC0, (char *)*p + 0xF0);
        func_002A0F48(*p);
        p++;
    }
}
