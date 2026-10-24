/* 448/456 bytes, 0/11 places in each of us, us2 and pal.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy
 * -frac2-qcopy-barrier -frac2-zero-ti-barrier.
 * Remeasured with canonical func_002AFF08(char *, char *, char *) returning
 * float and direct pointer arguments: the 448-byte result is unchanged.
 * Saved position lifetime, displaced clear and initial loop padding differ.
 * An explicit position pointer did not improve the result. Reopen with field
 * layout and clear-source evidence.
 */
typedef unsigned char u8;
typedef int TI128 __attribute__((mode(TI)));
extern void func_00282CC0(void *, void *, void *);
extern int func_L02_00333218(void *, void *);
extern void func_00282CF0(void *, void *, void *);
/* Canonical pointer inputs and float return are explicit. */
extern float func_002AFF08(char *, char *, char *);
extern void func_002AFE58(char *, char *, char *, char *, float);
extern float func_002B0360(char *);
extern void func_002AFD88(float, float, float, char *, char *);
extern void func_002AFEB8(char *, char *, char *, char *, float);
extern int func_00282948(void *);

void func_L02_00332D28(char *object, char *data, void *originalPosition, void *scratch, char *transform) {
    TI128 before;
    int changed = 0, hit, i;
    float speed, height;
    func_00282CC0(object + 0x10, object + 0x10, data + 0xA0);
    before = *(TI128 *)(object + 0x10);
    *(int *)(data + 0x84) = 0;
    *(TI128 *)(data + 0x60) = 0;
    for (i = 0; i < 8; i++) {
        hit = func_L02_00333218(object, data);
        changed |= hit;
        if (!hit)
            break;
    }
    if (changed) {
        func_00282CF0(data + 0xA0, object + 0x10, originalPosition);
        speed = func_002AFF08(object, data + 0xA0, transform);
        if (*(float *)(data + 0xB0) < speed)
            func_002AFE58(object, data + 0xA0, data + 0xA0, transform, *(float *)(data + 0xB0));
        else
            *(float *)(data + 0xB0) = speed;
        height = func_002B0360(object + 0x10);
        if (height <= *(float *)(data + 0x90)) {
            func_002AFD88(0.0f, 0.0f, *(float *)(data + 0x90) - height, object, object + 0x10);
            func_002AFEB8(object, data + 0xA0, data + 0xA0, transform, 0.0f);
        }
        if (*(float *)(data + 0xB0) < *(float *)(data + 0x28) * 0.5f)
            *(int *)(data + 0x80) += 1;
        else
            func_00282948(data + 0x80);
    } else {
        func_00282948(data + 0x80);
    }
    func_00282CF0(data + 0x70, object + 0x10, &before);
}
