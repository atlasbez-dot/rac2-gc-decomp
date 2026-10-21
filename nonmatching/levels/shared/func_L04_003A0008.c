/* from src/levels/shared/L04_0039FEF0-g8.c: C that compiles but does not link at its places yet */
/* The level's frame clock: when the clock has not reached a full turn the ripple patches
   are updated, otherwise the three row indexes are used to place the marked patches.  The
   clock advances by the step in either case.  The retail materialises the step's address
   twice, once before the frame's tests and once in the closing block, so its address never
   lives in a saved register; this draft keeps the address in a register, which makes the
   frame one slot larger (0x30 instead of 0x20). */
typedef int s32;

typedef unsigned int u32;

typedef unsigned char u8;

typedef unsigned short u16;

typedef float f32;

extern f32 ref_L04_003A0008_00 __attribute__((sda));
extern s32 ref_L04_003A0008_01 __attribute__((sda));
extern s32 ref_L04_003A0008_02 __attribute__((sda));
extern s32 ref_L04_003A0008_03 __attribute__((sda));
extern f32 D_L04_001AD860;
extern void func_L04_0039FEF0(void *a0, s32 a1);
extern void func_L04_0032F340(void *a0, void *a1, void *a2, f32 f3);

void func_L04_003A0008(void *a0, s32 a1) {
    if (1.0f - D_L04_001AD860 <= ref_L04_003A0008_00) {
        ref_L04_003A0008_00 = D_L04_001AD860;
        func_L04_0039FEF0(a0, a1);
        ref_L04_003A0008_02 = ref_L04_003A0008_01;
    } else {
        ref_L04_003A0008_02 = 2;
        if (a1 > 0) {
            s32 i = a1;
            u8 *p = (u8 *)a0;

            while (i != 0) {
                if (*(u16 *)(p + 0x1E) != 0) {
                    func_L04_0032F340(p + ref_L04_003A0008_02 * 0x5C0 + 0x50,
                                      p + ref_L04_003A0008_01 * 0x5C0 + 0x50,
                                      p + ref_L04_003A0008_03 * 0x5C0 + 0x50,
                                      ref_L04_003A0008_00);
                }
                i--;
                p += 0x1190;
            }
        }
    }
    ref_L04_003A0008_00 = ref_L04_003A0008_00 + D_L04_001AD860;
}
