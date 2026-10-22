/* from src/levels/shared/L04_002CC748.c: C that compiles but does not link at its places yet */
/* Builds the level's spawn record of kind 0x1B: the same record as func_L04_00363CA0 with a
   second sixteen-byte block, three more words and the record's own seventh byte copied back
   as a word.  The retail keeps the record pointer in $s1 and the second block's pointer in
   $s0; this draft gives $s0 to the record and $s1 to the second block, and the two words
   the retail stores in the order 0x14 then 0x10 come out the other way round. */
typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

typedef float f32;

typedef int L04Quad __attribute__((mode(TI)));

typedef struct {
    L04Quad field00;
    u32 field10;
    u32 field14;
    u32 field18;
} L04Spawned2Sub;

typedef struct {
    u8 pad00;
    u8 field01;
    u8 field02;
    u8 field03;
    u32 field04;
    u8 field08;
    u8 field09;
    u8 pad0A[2];
    f32 field0C;
    L04Quad field10;
    L04Spawned2Sub field20;
} L04Spawned2;

extern void *func_002B9030(s32 kind);

extern s32 func_001163B0(void);

extern s32 func_00283CF0(f32 value);

/* the level's pointer to the byte the record carries in its second flag byte */
extern u32 ref_L04_00358AE8_00;

u32 func_L04_00358AE8(void *a0, void *a1, u32 a2, u32 a3, f32 f0) {
    L04Spawned2 *p = (L04Spawned2 *)(u32)func_002B9030(0x1B);
    L04Spawned2Sub *sub = (L04Spawned2Sub *)((u8 *)p + 0x20);

    if ((u32)p != 0) {
        p->field10 = *(L04Quad *)a0;
        p->field08 = (u8)func_001163B0();
        p->field04 = a2;
        p->field09 = (u8)(func_00283CF0(4.0f) + 0x40);
        p->field03 = 0x48;
        p->field0C = f0;
        p->field01 = 0;
        p->field02 = *(u8 *)ref_L04_00358AE8_00;
        sub->field18 = *(signed char *)((u8 *)p + 7);
        sub->field00 = *(L04Quad *)a1;
        sub->field14 = a3;
        sub->field10 = a3;
    }
    return (u32)p;
}
