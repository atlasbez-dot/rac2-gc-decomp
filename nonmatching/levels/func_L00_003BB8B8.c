/* Near miss (mid-15): instruction-for-instruction equal except the six callee-saved float constants:
   retail holds pi/-pi/.001/.005/3.25/4.75 in f20/f21/f23.. order pi,-pi,.005,.001,4.75,3.25 (f20..f25); this C gets
   -pi,pi,.005,.001,3.25,4.75. Unit flags: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. */
#include "include_asm.h"

/* The grouped quadword copy: the R5900 lq/sq pair with both addresses in registers. */
typedef int Rac2TI128 __attribute__((mode(TI)));

/* Measured partial layout of one 0xA0-byte record of the table at D_L00_0023DDA0. */
typedef struct Rec_003BB8B8 {
    unsigned char prefix_00[0x40];
    float f_40;
    float f_44;
    float f_48;
    float f_4C;
    float f_50;
    float f_54;
    float f_58;
    float f_5C;
    float f_60;
    float f_64;
    float f_68;
    float f_6C;
    float f_70;
    float f_74;
    float f_78;
    float f_7C;
    float f_80;
    float f_84;
    int w_88;
    void *w_8C;
    void *w_90;
    void *w_94;
    void *w_98;
    int w_9C;
} Rec_003BB8B8;

extern Rec_003BB8B8 D_L00_0023DDA0[];

extern float func_002A7878(float low, float high);
extern float func_002A78D8(float low, float high);
extern void func_00282C88(void *p);
extern float *func_002AB1F0(char *object);
extern void func_L00_003252A8(char *object, float *out, int flag);
extern void func_00282D30(char *dst, char *src, float scale);
extern void func_00282CC0(void *out, void *in1, void *in2);

/* Claims the first free record of the thirty 0xA0-byte records at D_L00_0023DDA0, keeps the
   owner's pointer in it, copies a quadword in and fills the drawn values, then derives the
   record's vector at 0x30 from the object's own vector (scaled by its helper's float when it has
   one). */
void func_L00_003BB8B8(char *owner, char *obj, void *arg)
{
    Rac2TI128 *src1 = (Rac2TI128 *)(owner + 0x10);
    Rec_003BB8B8 *base = D_L00_0023DDA0;
    Rac2TI128 *src2 = (Rac2TI128 *)(obj + 0x10);
    Rec_003BB8B8 *slot;
    float *rec;
    float local[4];
    char *ctx;
    int i;

    ctx = *(char **)(owner + 0x68);
    for (i = 0; i < 30; i++) {
        slot = base + i;
        if (slot->w_8C != 0)
            continue;
        slot->w_8C = owner;
        (*(int *)(ctx + 0x54))++;
        *(Rac2TI128 *)((char *)slot + 0x20) = *src1;
        slot->f_40 = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_44 = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_48 = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_64 = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_68 = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_6C = func_002A7878(-3.14159274f, 3.14159274f);
        slot->f_4C = func_002A78D8(0.001f, 0.005f);
        slot->f_50 = func_002A78D8(0.001f, 0.005f);
        slot->f_54 = func_002A78D8(0.001f, 0.005f);
        slot->f_70 = func_002A78D8(0.001f, 0.005f);
        slot->f_74 = func_002A78D8(0.001f, 0.005f);
        slot->f_78 = func_002A78D8(0.001f, 0.005f);
        slot->f_58 = func_002A7878(3.25f, 4.75f);
        slot->f_5C = func_002A7878(3.25f, 4.75f);
        slot->f_60 = func_002A7878(3.25f, 4.75f);
        slot->f_7C = func_002A7878(3.25f, 4.75f);
        slot->f_80 = func_002A7878(3.25f, 4.75f);
        slot->f_84 = func_002A7878(3.25f, 4.75f);
        func_00282C88(slot);
        func_00282C88((char *)slot + 0x10);
        slot->w_98 = arg;
        slot->w_94 = arg;
        slot->w_88 = 20;
        slot->w_90 = obj;
        slot->w_9C = 0;
        rec = func_002AB1F0(obj);
        if (rec != 0) {
            func_L00_003252A8(obj, local, 1);
            func_00282D30((char *)local, (char *)local, rec[4]);
            func_00282CC0((char *)slot + 0x30, local, obj + 0x10);
        } else {
            *(Rac2TI128 *)((char *)slot + 0x30) = *src2;
        }
        break;
    }
}
