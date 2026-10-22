/* from src/levels/shared/L04_002CC748.c: C that compiles but does not link at its places yet */
/* Builds the level's spawn record of kind 0x1A and, when the caller's third argument is not
   -1, runs the record through the four helpers with a sixteen-byte stack buffer; otherwise
   it copies the caller's sixteen bytes into the record.  The record's own block at 0x20
   holds the two halfwords, the byte and the word the caller passes. */
typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

typedef float f32;

typedef int L04Quad __attribute__((mode(TI)));

typedef struct {
    u8 pad00[0x20];
    u16 field20;
    u16 field24;
    u8 pad26[2];
    u32 field28;
    u8 pad2C[4];
    u32 field30;
    u32 field34;
} L04Spawned3;

extern void *func_002B9030(s32 kind);

extern s32 func_001163B0(void);

extern s32 func_00283CF0(f32 value);

extern void func_0029FCC0(void *a0, s16 a1, void *a2);

extern void func_00282CF0(void *a0, u32 a1, void *a2);

extern void func_00282F20(void *a0, void *a1, void *a2, f32 f3);

extern void func_00282CC0(void *a0, void *a1);

/* the level's pointer to the byte the record carries in its second flag byte */
extern u32 ref_L04_00358868_00;

u32 func_L04_00358868(void *a0, void *a1, u32 a2, u32 a3, f32 f0) {
    L04Spawned3 *p = (L04Spawned3 *)(u32)func_002B9030(0x1A);
    u8 *sub = (u8 *)p + 0x20;
    s16 index = (s16)(a3 >> 16);

    if ((u32)p != 0) {
        p->field20 = (u16)a2;
        p->field30 = a1 >> 24;
        p->field24 = (u16)a3;
        p->field28 = a2;
        if (index == -1) {
            *(L04Quad *)((u8 *)p + 0x10) = *(L04Quad *)((u8 *)a0 + 0x10);
        } else {
            f32 buf[4];

            func_0029FCC0(p->pad00, index, buf);
            func_00282CF0(buf, 0x1B9680, buf);
            func_00282F20(buf, buf, buf, 0.4f);
            func_00282CC0((u8 *)p + 0x10, buf);
        }
        p->field04 = a1;
        p->field08 = (u8)func_001163B0();
        p->field09 = (u8)(func_00283CF0(4.0f) + 0x70);
        p->field03 = 0x48;
        p->field0C = f0;
        p->field01 = 0;
        p->field02 = *(u8 *)ref_L04_00358868_00;
    }
    (void)sub;
    return (u32)p;
}
