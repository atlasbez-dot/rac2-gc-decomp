/* func_0028B3D0 (264 bytes, 28 places; unit src/game/00288D88.c, -O2 -G0).
   26 October 2026 (M32): 268/264. Seven-argument slot request; the compare chain, stores
   and the sda frame counter D_001B1870 ($gp in the branch slots, lui $at for the store)
   agree, but this cc1 copies the first parameter to $t5 and puts the constant 1 in $a1
   and the counter in $a0, where retail keeps it in $v0 (one extra move). The unit's
   later `extern void func_0028B3D0(...)` must become int when this lands (its caller
   func_0028B540 still matches with that). In the permuter. */
typedef struct {
    int unk00;
    int flags;
    char pad08[0x18];
    int a;
    int key;
    int f;
    int e;
    int b;
    int c;
    int d;
    char pad3C[0x28];
    int stamp;
    int active;
    char pad6C[4];
    int unk70;
    char pad74[8];
    int unk7C;
    char pad80[0x10];
} SlotRecord;

typedef struct { unsigned char pad00[0x64]; int key; unsigned char pad68[0x28]; } SearchRow_28B5D0;
extern SearchRow_28B5D0 D_00255330[];
extern int D_001A8BB0[] __attribute__((sda));
extern int D_001B1870[] __attribute__((sda));
extern void func_0028B4D8(char *);

/* Starts (or keeps) the request id in its slot (the id's low four bits): a
   changed parameter set restamps the slot from the frame counter and resets it.
   Returns the slot's stamp, or 0 when state 5 locks every slot but 0 and 2. */
int func_0028B3D0(int id, int a, int b, int c, int d, int e, int f)
{
    int slot = id & 0xF;
    int key = id & 0xFFF0;
    SlotRecord *r = (SlotRecord *)&D_00255330[slot];

    if (D_001A8BB0[0] == 5 && slot != 2 && slot != 0)
        return 0;
    if (r->e != e || r->f != f || r->a != a || r->key != key || r->b != b || r->c != c
        || r->d != d) {
        r->stamp = D_001B1870[0];
        r->e = e;
        r->f = f;
        r->a = a;
        r->b = b;
        r->c = c;
        r->d = d;
        D_001B1870[0]++;
        r->active = 1;
        r->key = key;
        r->unk7C = 0;
        r->unk70 = 0;
        if (key & r->flags & 0x20)
            func_0028B4D8((char *)r);
    }
    return r->stamp;
}
