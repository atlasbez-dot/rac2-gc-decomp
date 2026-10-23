/* Retained plain-C attempt: 248/260 bytes; first difference +0x4.
 * us: 0/27, pal: 0/27, us2: 0/27.
 * Profile: -O2 -G0 -ffunction-sections -g.
 * The -g source reproduces the polling-loop padding, but resident high-half reuse and entry/address copies differ. Both calls reach actual resident entry 00132828, currently inside the incorrectly prefixed catalogue row func_00132818. Resolve that boundary independently before linking this draft.
 */
extern char D_00188660[];
extern char D_0014B540[];
extern void func_00132858(int handle);
extern void func_00133230(void);
extern int func_00132028(void);
extern void func_00132828(void);
extern int func_00132318(int address, int mode);
void func_L00_0032D208(int index)
{
    char *base = D_00188660;
    int *handle = (int *)(base + 0x17a4);
    int i = 2;
    int address;
    do {
        i--;
        if (*handle != 0) {
            func_00132858(*handle);
            *handle = 0;
        }
        handle++;
    } while (i >= 0);
    func_00133230();
    while (func_00132028() != 0) { }
    func_00132828();
    while (func_00132028() != 0) { }
    address = *(int *)(D_0014B540 + 0x52e0 + index * 8);
    if (address != 0) {
        address += *(int *)(D_0014B540 + 0x529c);
        handle = (int *)(base + 0x17a0) + index + 1;
        *handle = -1;
        *handle = func_00132318(address, 0);
    }
    func_00132828();
}
