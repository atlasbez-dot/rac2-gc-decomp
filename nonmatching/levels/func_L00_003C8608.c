/* func_L00_003C8608: M3 2026-10-26: 540/540 bytes in a -G8 unit (32 differing lines). Fixed: one func_0027C878 call (the draft called it twice), named D_002403C0 / D_L00_001B8DC0 / D_0018A0E0 instead of literal addresses, the 0x88 store before 0x80. Left: loop registers (table copy in $s4/$s6, the work+0xD0 copy in loop 2), the -1 store order and loop 2 preheader nop. In the permuter queue.
 */

extern unsigned long func_0027C878(int);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_002830C0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);

extern int D_L00_1B00A0[2] __attribute__((sda));
extern float D_L00_1B00E0 __attribute__((sda));
extern float D_L00_1B00E4 __attribute__((sda));
extern float D_L00_1B00E8 __attribute__((sda));
extern int D_L00_1B00EC __attribute__((sda));



/* Draws the object twice: builds one render packet from its frame at +0xD0, then feeds the four
   16-byte vectors of the level's small-data table through the packet, once in the level's colour
   and once in the inverted one. */
extern char D_002403C0[];
extern char D_L00_001B8DC0[];
extern char D_0018A0E0[];

void func_L00_003C8608(char *self)
{
    unsigned char work[0xE0];
    float vector[4];
    int *source;
    float *target;
    int i;
    unsigned long t;

    t = func_0027C878(0xB);
    *(long long *)(work + 0x88) = 0x0000008000000048LL;
    *(long long *)(work + 0x80) = 0x0000FF9000000260LL;
    *(int *)(work + 0x4C) = D_L00_1B00EC;
    *(int *)(work + 0x48) = D_L00_1B00EC;
    *(int *)(work + 0x44) = D_L00_1B00EC;
    *(int *)(work + 0x40) = D_L00_1B00EC;
    *(long long *)(work + 0x78) = t;
    *(long long *)(work + 0x70) = 0;
    *(int *)(work + 0x50) = 0;
    *(int *)(work + 0x54) = 0;
    *(int *)(work + 0x58) = 0;
    *(float *)(work + 0x5C) = 1.0f;
    *(float *)(work + 0x60) = 1.0f;
    *(int *)(work + 0x64) = 0;
    *(float *)(work + 0x68) = 1.0f;
    *(float *)(work + 0x6C) = 1.0f;

    func_00282F20((char *)vector, self + 0xD0, D_L00_1B00E8);
    func_00282CC0((char *)work + 0xC0, D_002403C0, (char *)vector);
    func_00282CF0((char *)vector, D_L00_001B8DC0, (char *)work + 0xC0);
    func_00282F20((char *)work + 0x90, (char *)vector, 1.0f);
    func_00282DD8((char *)work + 0xA0, (char *)work + 0x90, D_0018A0E0);
    func_00282F20((char *)work + 0xA0, (char *)work + 0xA0, -1.0f);
    func_00282DD8((char *)work + 0xB0, (char *)work + 0xA0, (char *)work + 0x90);

    target = (float *)work;
    for (i = 3, source = D_L00_1B00A0; i >= 0; i--) {
        func_00282D30((char *)work + 0xD0, (char *)source, D_L00_1B00E0);
        func_002830C0((char *)target, (char *)work + 0xD0, (char *)work + 0x90);
        source += 4;
        target += 4;
    }
    func_00280B90((char *)work, (char *)0, (char *)0);

    *(int *)(work + 0x4C) = -1;
    *(int *)(work + 0x48) = -1;
    *(int *)(work + 0x44) = -1;
    *(int *)(work + 0x40) = -1;

    target = (float *)work;
    for (i = 3, source = D_L00_1B00A0; i >= 0; i--) {
        func_00282D30((char *)work + 0xD0, (char *)source, D_L00_1B00E4);
        func_002830C0((char *)target, (char *)work + 0xD0, (char *)work + 0x90);
        source += 4;
        target += 4;
    }
    func_00280B90((char *)work, (char *)0, (char *)0);
}
