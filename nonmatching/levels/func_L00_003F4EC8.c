/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 724/724 bytes; us: 0/27 places; us2: 0/27 places; pal: absent from catalogue.
 * Unsigned object bytes, direct position fields and delayed cursor lifetime recover the
 * frame/size. First difference+0x54: compiler merges two identical closing calls that retail
 * keeps separate; loop increment scheduling also differs. Reopen with an independently
 * qualified block-order/tail-merge witness.
 * Historical screening note below predates this C attempt.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 724 bytes, 27 place(s), first word at L00:003f4ec8.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f4ec8  addiu       $sp, $sp, -0x70
 *   0x003f4ecc  sd          $s0, 0x20($sp)
 *   0x003f4ed0  sd          $s1, 0x28($sp)
 *   0x003f4ed4  daddu       $s0, $a0, $zero
 *   0x003f4ed8  sd          $s2, 0x30($sp)
 *   0x003f4edc  addiu       $a0, $zero, 0xC04
 * Kept as data for the maintainers. */

typedef int MovingEffectWord128 __attribute__((mode(TI)));
typedef union { MovingEffectWord128 word; float values[4]; } MovingEffectVector;
extern int func_002B4038(int, int);
extern void func_0029F338(void *);
extern void func_00300190(void *, void *);
extern void func_L00_003F5660(char *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283CE0(int);
extern void func_00282D08(void *, void *, void *, float);
extern void func_L00_003F5750(char *, void *);
extern void func_L00_003F6900(char *, void *);
extern int func_L00_003F5238(char *, void *);
extern int func_00282948(void *);

void func_L00_003F4EC8(unsigned char *object) {
    char *state = *(char **)(object + 0x68);
    MovingEffectVector previous, point;
    int i;
    float *position;
    if (!func_002B4038(0xC04, *(short *)(state + 0x1A))) {
        func_0029F338(object);
        return;
    }
    if ((unsigned char)object[0x20] == 2) {
        func_00300190(object + 0x10, object + 0x10);
        func_L00_003F5660(object);
        return;
    }
    if (*(int *)(state + 0x28) == 1)
        previous.word = *(MovingEffectWord128 *)(state + 0x40);
    else
        previous.word = *(MovingEffectWord128 *)(object + 0x10);
    position = (float *)(object + 0x10);
    func_00282CC0(position, position, state);
    if (*(int *)(state + 0x28) == 1)
        func_00282CC0(state + 0x40, state + 0x40, state + 0x30);
    if ((unsigned char)object[0x20] == 0)
        object[0x20] = 1;
    for (i = 0; i < 4; i++) {
        func_00282D08(&point, &previous, position, func_00283CE0(i) * 0.25f);
        func_L00_003F5750(object, &point);
    }
    func_L00_003F6900(object, position);
    func_00282D08(&point, &previous, position, 0.5f);
    func_L00_003F6900(object, &point);
    if (*(float *)(object + 0x10) < 2.0f || *(float *)(object + 0x10) > 1021.0f ||
        *(float *)(object + 0x14) < 2.0f || *(float *)(object + 0x14) > 1021.0f ||
        *(float *)(object + 0x18) < 2.0f || *(float *)(object + 0x18) > 1021.0f) {
        if (*(float *)(object + 0x10) < 5.0f) *(float *)(object + 0x10) = 5.0f;
        if (*(float *)(object + 0x14) < 5.0f) *(float *)(object + 0x14) = 5.0f;
        if (*(float *)(object + 0x18) < 5.0f) *(float *)(object + 0x18) = 5.0f;
        if (*(float *)(object + 0x10) > 1016.0f) *(float *)(object + 0x10) = 1016.0f;
        if (*(float *)(object + 0x14) > 1016.0f) *(float *)(object + 0x14) = 1016.0f;
        if (*(float *)(object + 0x18) > 1016.0f) *(float *)(object + 0x18) = 1016.0f;
    } else if (!func_L00_003F5238(object, &previous) && !func_00282948(state + 0x10)) {
        func_L00_003F5660(object);
        return;
    }
    object[0x20] = 2;
}
