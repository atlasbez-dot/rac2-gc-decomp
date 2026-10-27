/* M13, 26 October 2026: 608/600 B under -O2 -G8 -ffunction-sections (opcode score 49 -> 35).
 * The GS flags word is built as a linear or-chain over separate statements (retail's
 * order). Left: the face loop: retail keeps the face counter in s6 and spills the u/v
 * cursors (0xD4/0xD8), with the table bases hoisted into s7/fp; this draft spills the
 * counter instead. Reopen: the loop's counter/cursor form.
 */
typedef int RenderWord128 __attribute__((mode(TI)));
typedef union { RenderWord128 word; struct { float x,y,z,w; } f; } RenderVector;
typedef struct { RenderVector vertices[4]; unsigned int colors[4]; float uv[8]; long long zero, texture, state, flags; } RenderPacket;
extern int D_L00_001B0870 __attribute__((sda));
extern int D_L00_001B0874 __attribute__((sda));
extern int D_L00_001B0878 __attribute__((sda));
extern int D_L00_001B087C __attribute__((sda));
extern int D_L00_001B0880 __attribute__((sda));
extern int D_L00_001B0884 __attribute__((sda));
extern int D_L00_001B0888 __attribute__((sda));
extern float D_L00_001B088C __attribute__((sda));
extern RenderVector D_L00_0029AF40[] __attribute__((nosda));
extern short D_L00_0029B440[][8] __attribute__((nosda));
extern float D_L00_0029B840[][2] __attribute__((nosda));
extern long long func_0027C878(int);
extern void func_00282C88(RenderWord128 *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, void *, float);
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00280B90(void *, void *, int);

void func_L00_003EFD00(char *object) {
    RenderPacket packet;
    RenderVector matrix[3], offset;
    char *orientation = object + 0xC0;
    char *data = *(char **)(object + 0x68);
    char *u, *v;
    RenderVector *vertex;
    short *indices;
    int face = 0, tableOffset = 0, remaining, index;
    unsigned int color;
    long long flags;
    packet.texture = func_0027C878(D_L00_001B0884);
    flags = (long long)D_L00_001B0870 | (long long)D_L00_001B0874 << 2;
    flags |= (long long)D_L00_001B0878 << 4;
    flags |= (long long)D_L00_001B087C << 6;
    flags |= (long long)D_L00_001B0880 << 32;
    packet.flags = flags;
    packet.state = 0xFF9000000260LL;
    packet.zero = 0;
    object += 0x10;
    func_00282C88(&matrix[0].word);
    func_00282C88(&matrix[1].word);
    func_00282C88(&matrix[2].word);
    matrix[0].f.x = *(float *)(data + 0x10);
    matrix[1].f.y = *(float *)(data + 0x10);
    matrix[2].f.z = *(float *)(data + 0x10) * 0.125f;
    color = D_L00_001B0888 + (*(unsigned int *)(data + 0x24) << 24);
    packet.colors[0] = color;
    packet.colors[1] = color;
    packet.colors[2] = color;
    packet.colors[3] = color;
    func_002AFFD8(object, (char *)&offset, 1);
    func_00282D30(&offset, &offset, 0.25f);
    for (;;) {
        face++;
        indices = (short *)((char *)D_L00_0029B440 + tableOffset);
        u = (char *)&packet + 0x50;
        v = (char *)&packet + 0x54;
        vertex = packet.vertices;
        remaining = 3;
        for (;;) {
            remaining--;
            index = indices[1];
            func_00282D30(vertex, &D_L00_0029AF40[indices[0]], D_L00_001B088C);
            indices += 2;
            *(float *)u = D_L00_0029B840[index][0];
            *(float *)v = D_L00_0029B840[index][1];
            func_00283098(vertex, vertex, matrix);
            u += 8;
            v += 8;
            func_00283098(vertex, vertex, orientation);
            func_00282CC0(vertex, vertex, object);
            func_00282CC0(vertex, vertex, &offset);
            if (remaining < 0)
                break;
            vertex++;
        }
        func_00280B90(&packet, 0, 0);
        if (face >= 64)
            break;
        tableOffset = face * 16;
    }
}
