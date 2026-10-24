/* 0 of 28 placements match in USA v1.01, PAL, and USA v2.00.
   Ten checker invocations covered four source forms. The best plain-C draft
   is 356 bytes, but the first mismatch is at +0x8 in every release; the
   prologue/base live ranges and initial register allocation remain different.
   Explicit SDA declarations recover the two GP-relative accesses. */
typedef struct {
    int value[5];
} Func002F71B8Table;

extern int D_001AD1C0 __attribute__((sda));
extern int D_001AD1B8 __attribute__((sda));
extern Func002F71B8Table D_001AD268;
extern unsigned char D_001395B8[];
extern char D_0021F240[];
extern int func_00288D58(void);

void func_002F71B8(void)
{
    Func002F71B8Table values = D_001AD268;
    char *base = D_0021F240;
    int *count = (int *)(base + 0x740);
    int *field0 = (int *)(base + 0x140);
    int *field1 = (int *)(base + 0x144);
    int *field2 = (int *)(base + 0x148);
    int i = D_001AD1C0 != 0 ? D_001AD1C0 + 1 : 1;

    *count = 0;
    D_001AD1B8 = 0;
    for (; i < 5; i++) {
        if ((unsigned int)i >= 8 ||
            ((D_001395B8[0x8D] >> i) & 1) == 0) {
            if (func_00288D58() == 0)
                continue;
        }
        field2[(*count) * 3] = i;
        field1[(*count) * 3] = values.value[i];
        field0[(*count) * 3] = i + 0xEA92;
        *count = *count + 1;
    }
}
