typedef int TI128_002A7470 __attribute__((mode(TI)));

extern void func_002A7398(unsigned char *, int, int);
extern int func_0029FA88(void *);
extern void func_002A2450(void *, int);
extern void func_0029F390(void *);
extern float func_00283CE0(int);
extern unsigned char ref_L00_002A7470_00[];

void func_002A7470(unsigned char *object, int animation, int frame, int rate)
{
    int frame_count;
    int last_frame;
    int slot;
    float reciprocal;
    int copy_offset;
    unsigned char *table;
    TI128_002A7470 *copy_source;
    TI128_002A7470 *copy_destination;
    int use_frame;

    frame_count = *(unsigned char *)(*(unsigned char **)(*(unsigned char **)(object + 0x24) + animation * 4 + 0x48) + 0x10);
    use_frame = frame < frame_count;
    last_frame = frame_count - 1;
    if (use_frame)
        last_frame = frame;

    if (rate <= 0) {
        func_002A7398(object, animation, last_frame);
        return;
    }

    if (0.025f < *(float *)(object + 0x44) ||
        *(unsigned int *)(object + 0x50) != 0 ||
        *(unsigned int *)(object + 0x54) != 0) {
        slot = func_0029FA88(object);
        if (slot >= 0) {
            func_002A2450(object, slot | 0x300);
            copy_offset = slot * 16;
            copy_source = (TI128_002A7470 *)(object + 0x80);
            copy_destination = (TI128_002A7470 *)((unsigned char *)ref_L00_002A7470_00 + copy_offset);
            *copy_destination = *copy_source;
            if (object[0x42] != 0xFF)
                object[0xA9] = object[0x42];
            object[0x42] = 0xFF;
            object[0x40] = slot;
        }
    }

    object[0x41] = last_frame;
    object[0x43] = animation;
    func_0029F390(object);
    *(float *)(object + 0x48) = 1.0f;
    reciprocal = 1.0f / func_00283CE0(rate);
    *(unsigned int *)(object + 0x44) = 0;
    object[0x60] &= 0xFD;
    *(float *)(object + 0x4C) = reciprocal;
    table = *(unsigned char **)(object + 0x24);
    table += animation * 4;
    object[0x6C] = table[0x59];
}
