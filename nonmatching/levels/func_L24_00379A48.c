/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections.
 * Reported final C / retail: 524 / 524 bytes; size equality is not a match.
 * us: 0/1 placements.
 * us2: absent from catalogue (not a match).
 * pal: absent from catalogue (not a match).
 * Residual: Two movn/movz polarity instructions at+bc/+c0 differ; three integer flag widths tie.
 * Reopening condition: New measured source-shape/scheduler or ABI remedy addressing the residual; do not repeat tied forms.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Near miss: 524 bytes, 0/1 USA placements under -O2 -G8.
 * Only two non-relocation instructions differ: +0xbc initializes permitted
 * from the saved one register then movn selects zero; retail initializes zero
 * then movz selects one. Int, unsigned int and unsigned char flags tie.
 * Long flags and a boolean XOR form emit 520 bytes; -fno-gcse emits 516.
 * Retail's live object+0x68 pointer is loaded before switch dispatch.
 * Scalar small-data globals require truthful sized sda declarations.
 * Remaining unknown helper func_002B0C28 is provisionally typed from three
 * integer inputs and a v0 predicate; qualify its full return width before use.
 * Reopen with a measured conditional-move polarity remedy; no linked build.
 */
#include "include_asm.h"
typedef struct { float x,y,z,w; } Point;
typedef struct {
    unsigned char pad0[0x80];
    Point position;
    unsigned char pad90[8];
    float heading;
    unsigned char pad9c[0x2294-0x9c];
    int mode;
    unsigned char pad2298[4];
    int activity;
} PlayerView;
extern unsigned char D_00189E20[];
#define PLAYER ((PlayerView *)D_00189E20)
extern int D_L24_001AEBB8 __attribute__((sda));
extern int D_L24_001AEBBC __attribute__((sda));
extern int D_L24_001A8F00;
extern unsigned int D_00138324 __attribute__((nosda));
extern void func_002A7750(unsigned char *, unsigned char, int);
extern void func_L00_00326048(char *, float *, int, int, float);
extern float func_00282E80(void *, void *);
extern float func_00282C48(float);
extern float func_00283248(float, float);
extern float func_00283C80(float, float);
extern int func_002B0C28(int, int, int);
extern int func_002B49E0(int, int, int, int, unsigned char *);
void func_L24_00379A48(unsigned char *object)
{
    unsigned int permitted;
    int selected;
    float *animation = *(float **)(object + 0x68);
    switch (object[0x20]) {
    case 0:
        func_002A7750(object, 1, -1);
        break;
    case 1:
        permitted = 1;
        selected = 0;
        func_L00_00326048((char *)object, animation,
                          D_L24_001AEBB8, D_L24_001AEBBC, 0.043633237f);
        if (PLAYER->activity && PLAYER->mode != 3) {
            permitted = 0;
            if (PLAYER->activity == 1) permitted = 1;
        }
        if (func_00282E80(object + 0x10, &PLAYER->position) > 3.0f ||
            func_00282C48(PLAYER->position.z - *(float *)(object + 0x18)) > 0.7f)
            permitted = 0;
        if (func_00283C80(PLAYER->heading,
              func_00283248(*(float *)(object + 0x10) - PLAYER->position.x,
                            *(float *)(object + 0x14) - PLAYER->position.y)) > 1.5707965f)
            permitted = 0;
        if (PLAYER->mode == 0x1c || PLAYER->mode == 0x31) permitted = 0;
        if (permitted) selected = func_002B0C28(1, 0x2799, 1) != 0;
        if ((D_00138324 & 0x10) && selected) {
            func_002B49E0(5, 1, (int)object, 0, 0);
            object[0x20] = 2;
        }
        break;
    case 2:
        if (!D_L24_001A8F00) object[0x20] = 1;
        break;
    }
}
