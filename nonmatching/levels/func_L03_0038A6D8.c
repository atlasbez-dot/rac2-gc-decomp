/* GNU game -O2 -G0 -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por -g,
 * 760/760 bytes, us/us2 each 0/2 places; absent from PAL. Five original trials
 * plus one ABI/name repair check. First difference +0x1c8 remains the outgoing
 * argument-store order; sound-table pointer allocation also differs. The varying
 * callback uses a measured ref symbol; its canonical identities and level-03
 * boundary uncertainty are documented below. The resident store at 0x0018cde4
 * was verified in both levels in both USA releases. Reopen with an allocation
 * witness and independent review of that callback boundary.
 */
typedef int EffectQuad __attribute__((mode(TI)));
extern void func_L03_00419A60(int, void *, int);
extern void func_L03_0038B4E8(void *);
extern void func_L03_0038B408(void *);
extern void func_002A7750(void *, int, int);
extern int func_002B3868(void *);
extern int func_00282948(void *);
extern void func_L03_0038B238(void);
extern void func_L03_0038B5D8(void *);
typedef void (*EffectDrawCallback)(void *);
extern void func_L00_002E6EF8(EffectDrawCallback, void *);
/* The callback is not one canonical entry in both carrying levels. Retail
 * US level 03: func_L03_0038AA20 + 0x18 (0x0038AA38); level 14:
 * func_L14_00390FE8 + 0 (0x00390FE8). US2: the same canonical identities
 * at 0x0038BF08 and 0x00392440. The level-03 catalogue extent includes
 * three positive stack adjustments before the callback's negative-frame
 * prologue. That boundary still needs independent catalogue review.
 */
extern void ref_L03_0038A6D8_00(void *);
extern int func_002B38B8(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_0032C700(float, float, void *, int, int, int, int, int, int, int, int, int, int, int);
extern unsigned short D_0018CDE4;
extern unsigned char D_00188660[];
extern void func_002E59F8(int);
extern int func_002E5CF8(int, int, void *);
extern void func_0029F338(void *);

void func_L03_0038A6D8(unsigned char *object) {
    unsigned char *state = *(unsigned char **)(object + 0x68);
    unsigned char *entry;
    union { EffectQuad quad; float values[4]; } position;
    int handle;
    switch (object[0x20]) {
    case 0:
        *(EffectQuad *)state = *(EffectQuad *)(object + 0x10);
        if (*(int *)(state + 0x10) != -1 && *(int *)(state + 0x14))
            func_L03_00419A60(*(int *)(state + 0x10), object + 0x10, 0);
        func_L03_0038B4E8(object);
        if ((*(unsigned long long *)(state + 0x38) & 0x1100000000ULL) == 0x1100000000ULL)
            func_L03_0038B408(object);
        func_002A7750(object, 1, -1);
        break;
    case 1:
        if (func_002B3868(object))
            *(EffectQuad *)(object + 0x10) = *(EffectQuad *)state;
        if (func_00282948(state + 0x24)) {
            *(int *)(state + 0x24) = *(int *)(state + 0x18);
            func_002A7750(object, 2, -1);
        }
        break;
    case 2:
        if (func_00282948(state + 0x24)) {
            *(int *)(state + 0x24) = *(int *)(state + 0x1C);
            func_002A7750(object, 3, -1);
        }
        break;
    case 3:
        if (func_00282948(state + 0x24)) {
            *(int *)(state + 0x24) = *(int *)(state + 0x20);
            func_002A7750(object, 1, -1);
        }
        break;
    }
    if (!(*(int *)(state + 0x3C) & 0x20)) {
        if (!(*(int *)(state + 0x3C) & 0x40))
            func_L03_0038B238();
        func_L03_0038B5D8(object);
        func_L00_002E6EF8(ref_L03_0038A6D8_00, object);
    }
    if (func_002B38B8(object)) {
        position.quad = 0;
        position.values[2] = 1.0f;
        func_00282CC0(&position, &position, object + 0x10);
        func_0032C700(1.0f, 20.0f, &position, 0, 0, 0, 0, 0x14, 0x2D, 1, 1, 0, 0, 0);
        if (*(int *)(state + 0x10) != -1 && *(int *)(state + 0x14))
            func_L03_00419A60(*(int *)(state + 0x10), object + 0x10, 1);
        D_0018CDE4 = 0xFFFF;
        handle = *(int *)(state + 0xD8);
        if (handle != -1) {
            entry = (unsigned char *)(handle * 0x70 + (int)D_00188660);
            if (*(unsigned char **)(entry + 0x88) == object && entry[0x74])
                func_002E59F8(handle);
        }
        *(int *)(state + 0xD8) = -1;
        func_002E5CF8(1, 0, object);
        func_0029F338(object);
    } else {
        entry = (unsigned char *)(*(int *)(state + 0xD8) * 0x70 + (int)D_00188660);
        if (*(unsigned char **)(entry + 0x88) != object || !entry[0x74])
            *(int *)(state + 0xD8) = func_002E5CF8(0, 4, object);
    }
}
