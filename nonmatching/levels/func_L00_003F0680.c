typedef struct { float x, y, z, w; } Vector;
typedef struct {
    Vector position, direction;
    float unused20, scale, spinStart, spin, spinEnd, phase;
    float offsetStart, offset, offsetEnd, sizeStart, size, sizeEnd;
    int unused50, remaining, duration, initialCount, count;
    int colorStart, color, colorEnd, unused70, state, kind;
    char *owner;
} Effect;
extern Effect *D_L00_001B2BB8 __attribute__((sda));
extern void func_00282C88(void *);
extern float func_00283CE0(int);
extern int func_00283CF0(float);
extern int func_00283D38(int, int, float);
extern float func_002A7790(float);
extern float func_002A7798(float);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern float func_00283B98(float, float);
extern int func_002A7820(int, int);
extern int func_00282948(void *);

void func_L00_003F0680(char *owner)
{
    Vector displacement, velocity;
    Effect *record;
    char *object, *data;
    float numerator, denominator, fraction, first, second, curve;
    int i;

    i = 0;
    func_00282C88(&displacement);
    for (; i < 320; i++) {
        record = &D_L00_001B2BB8[i];
        if (record->owner == owner) {
            numerator = func_00283CE0(record->remaining);
            denominator = func_00283CE0(record->duration);
            fraction = 1.0f - numerator / denominator;
            if (record->state == 0)
                goto interpolate;
            if (record->state == 1) {
                first = func_00283CE0(record->initialCount);
                second = func_00283CE0(record->initialCount);
                curve = func_002A7790(fraction);
                record->count = func_00283CF0(first - second * curve);
                if (record->kind != 2) {
interpolate:
                    record->color = func_00283D38(record->colorStart, record->colorEnd, fraction);
                    record->spin = record->spinStart + (record->spinEnd - record->spinStart) * fraction;
                    record->offset = record->offsetStart + (record->offsetEnd - record->offsetStart) * fraction;
                    record->size = record->sizeStart + (record->sizeEnd - record->sizeStart) * fraction;
                    curve = func_002A7798(fraction);
                    func_00282F20(&displacement, &record->direction, record->scale * curve);
                } else {
                    func_00282F20(&displacement, &record->direction, record->scale);
                }
            }
            func_00282F20(&velocity, record->owner, record->offset);
            func_00282CC0(record, record, &velocity);
            if (record->kind != 1)
                func_00282CC0(record, &displacement, record);
            object = *(char **)(record->owner + 0x30);
            data = *(char **)(object + 0x68);
            record->phase = func_00283B98(record->phase, record->spin);
            if (*(unsigned char *)(object + 0x20) == 2 && *(int *)(data + 0x14) < 38 && record->kind != 2) {
                record->state = 1;
                record->duration = func_002A7820(30, 45);
                record->sizeStart = record->size;
                record->colorStart = record->color;
                record->offsetStart = record->offset;
                record->initialCount = record->count;
                record->spinStart = record->spin;
                record->remaining = record->duration;
            }
            if (func_00282948(&record->remaining) != 0) {
                if (record->state == 0) {
                    record->state = 1;
                    record->remaining = record->kind == 1 ? 30 : 55;
                    record->duration = record->remaining;
                } else if (record->count < 1) {
                    (*(int *)(record->owner + 0x38))--;
                    if (record->kind == 0)
                        (*(int *)(record->owner + 0x40))--;
                    else {
                        if (record->kind != 1) {
                            record->owner = 0;
                            goto next;
                        }
                        (*(int *)(record->owner + 0x44))--;
                    }
                    record->owner = 0;
                } else {
                    record->state = 2;
                    record->count--;
                }
            }
        }
next:;
    }
}
