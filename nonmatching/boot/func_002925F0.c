/*
 * Near miss for func_002925F0. The measured US and US2 trial was 188 bytes
 * versus 196, with 0/28 placements matching in each release; PAL has no
 * catalogue entry for this function. The closest measured US trial was 192
 * bytes and also matched 0/28. The descriptor constant below was corrected
 * from the retail instruction sequence after those checks and remains
 * unverified. Remaining differences include register allocation and call
 * scheduling around the table loads.
 */

typedef struct {
    unsigned char pad_00[0x18];
    int value_18;
    unsigned char pad_1C[0x1C];
    unsigned long long value_38;
} RAC2State_002925F0;

typedef struct {
    unsigned long long value_00;
    unsigned long long value_08;
    unsigned long long value_10;
} RAC2Descriptor_002925F0;

extern RAC2State_002925F0 D_00152C00;
typedef struct {
    int value_00;
    int value_04;
} RAC2Slot_002925F0;

typedef struct {
    unsigned char pad_00[0x3E24];
    int value_3E24;
    unsigned char pad_3E28[0x0AB0];
    RAC2Slot_002925F0 slots[1];
} RAC2Table_002925F0;

extern RAC2Table_002925F0 D_0014B540;
extern char *D_L00_001BF1B0;
extern RAC2Descriptor_002925F0 D_L00_001C91C0;
extern int ref_L00_001A91E0_00 __attribute__((sda));

extern void func_002FC3C0(unsigned long);
extern int func_002B7C80(char *, int, int);
extern void func_002934F8(char *, int, int, int);

void func_002925F0(int param)
{
    RAC2State_002925F0 *state;
    RAC2Table_002925F0 *entry;
    char *resource;

    state = &D_00152C00;
    func_002FC3C0(1);
    state->value_18 = param;

    entry = (RAC2Table_002925F0 *)((char *)&D_0014B540 + (param << 3));
    resource = D_L00_001BF1B0;
    func_002B7C80(
        resource,
        entry->slots[0].value_00 + D_0014B540.value_3E24,
        entry->slots[0].value_04);

    D_L00_001C91C0.value_00 = state->value_38;
    D_L00_001C91C0.value_08 = 0x0000FFA0000000E0ULL;
    D_L00_001C91C0.value_10 = 0x40000400004000ULL;

    func_002934F8(resource, 0, (int)&ref_L00_001A91E0_00, -1);
}
