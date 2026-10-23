/* Retained plain-C attempt: 228/228 bytes; first difference +0x50.
 * us: 0/27, pal: name absent, us2: 0/27.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -fno-gcse.
 * The loop counter/table registers, initial counter copy and null/type branch remain different. Real aligned C copies replace the obsolete MMI-impossibility screen. The callee func_L00_002D3778 requires destination/source pointers plus a float; the shared wrapper now forwards that measured interface.
 */
typedef int Quad __attribute__((mode(TI)));
extern char D_00189E20[];
extern char *D_L00_001C3280[];
extern int func_002E5CF8(int index, int mode, void *object);
extern void func_L00_002D3778(void *dst, void *src, float scale);
extern void func_L00_0038B888(void *position, int count);
static __inline__ int object_type(char *object)
{
    char *data;
    if (object == 0)
        return 0;
    data = *(char **)(object + 0x24);
    if (data == 0)
        return 0;
    return *(short *)(data + 0x46);
}
void func_L00_002BA138(void *object, int count)
{
    float position[4] __attribute__((aligned(16)));
    char **slot;
    int type;
    int remaining;
    char *data;
    char *base;
    if (count != 0) {
        base = D_00189E20;
        if (*(short *)(base + 0xbfe) == 0) {
            func_002E5CF8(1, 0, object);
            *(short *)(base + 0xbfe) = 1;
        }
        if (count > 0) {
            remaining = count;
            slot = D_L00_001C3280;
            do {
                type = object_type(*slot);
                if (type == 5 || type == 9) {
                    *(Quad *)position = *(Quad *)(*slot + 0x10);
                    func_L00_002D3778(position, position, 0.5f);
                    func_L00_0038B888(position, 4);
                }
                remaining--;
                slot++;
            } while (remaining != 0);
        }
    }
}
