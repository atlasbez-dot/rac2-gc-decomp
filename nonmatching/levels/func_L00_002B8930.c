/* Retained manual C reconstruction; not linked and not credited as matching.
 * Checked source: src/levels/shared/L00_002B7B80.c
 * Profile: -O2 -G0 -ffunction-sections -mno-split-addresses
 * Retail US extent: 904 bytes.
 * us: 0/19 (exit 1, 916 compiled bytes); us2: 0/19 (exit 1, 916 compiled bytes); pal: catalogue absent (exit 1).
 * Residual: 916/904 bytes in the final source with an incomplete external storage declaration (the earlier complete-prefix extern compiled to 908 bytes). The frame is 0x20. Resident base construction, scalar allocation and FP scheduling differ; lexical float scopes and a partial struct view did not resolve them.
 * Reopen only with: A measured object-base/storage model preserving unknown whole-object extents, or a qualified profile change shown to affect this exact base-construction pattern.
 * No complete linked build was run for this candidate.
 */
#include "include_asm.h"



typedef struct { char reserved000[0x174]; float weight; char reserved178[0x2c]; float x, y; char reserved1ac[0x20e8]; int mode; int reserved2298; int submode; } CameraPlayerPrefix;
extern unsigned char D_00189E20[];
#define PLAYER (*(CameraPlayerPrefix *)D_00189E20)
extern unsigned char D_L00_0025BE10[];
extern float func_00282C48(float);
#define CAMERA_FLOAT(offset) (*(float *)(D_L00_0025BE10 + (offset)))
#define PLAYER_FLOAT(offset) (*(float *)(D_00189E20 + (offset)))
#define PLAYER_INT(offset) (*(int *)(D_00189E20 + (offset)))
void func_L00_002B8930(void)
{
    float scaled, negative, weight;
    if (PLAYER.mode == 64) {
        float turn;
        turn = PLAYER.x * 9.0f;
        if (turn > 0.7f) turn = 0.7f;
        else if (turn < -0.7f) turn = -0.7f;
        turn = turn * func_00282C48(turn) * 1.25f;
        weight = PLAYER.weight * 19.999998f;
        negative = -turn;
        scaled = negative * 0.2f;
        CAMERA_FLOAT(0x1240) = scaled;
        if (weight > 1.0f) weight = 1.0f;
        if (weight < 0.0f) weight = 0.0f;
        CAMERA_FLOAT(0x10e8) = turn;
        CAMERA_FLOAT(0x1240) = scaled * weight;
        CAMERA_FLOAT(0x10e0) = negative * 0.35f;
        CAMERA_FLOAT(0x1198) = turn * 1.35f;
        CAMERA_FLOAT(0x1194) = func_00282C48(turn) * 0.25f;
    } else if (PLAYER.mode == 75) {
        float turn;
        turn = PLAYER.y * 1.6f;
        if (turn > 1.25f) turn = 1.25f;
        else if (turn < -1.25f) turn = -1.25f;
        scaled = -turn * 0.52f;
        CAMERA_FLOAT(0x1240) = scaled;
        if (scaled > 0.28f) CAMERA_FLOAT(0x1240) = 0.28f;
        else if (scaled < -0.28f) CAMERA_FLOAT(0x1240) = -0.28f;
        scaled = turn * 1.7f;
        CAMERA_FLOAT(0x1198) = scaled;
        CAMERA_FLOAT(0x10e8) = turn * 0.58f;
        if (scaled > 0.7f) CAMERA_FLOAT(0x1198) = 0.7f;
        else if (scaled < -0.7f) CAMERA_FLOAT(0x1198) = -0.7f;
        scaled = func_00282C48(turn) * 0.2f;
        CAMERA_FLOAT(0x1194) = scaled;
        if (scaled <= 0.2f && scaled < -0.2f) CAMERA_FLOAT(0x1194) = -0.2f;
        CAMERA_FLOAT(0x1190) = func_00282C48(turn) * 0.16f;
    } else if (PLAYER.submode == 2 || PLAYER.submode == 4) {
        float turn;
        turn = PLAYER.y;
        if (turn > 1.4f) turn = 1.4f;
        else if (turn < -1.4f) turn = -1.4f;
        CAMERA_FLOAT(0x10e8) = turn * 0.29f;
        CAMERA_FLOAT(0x1198) = turn * 0.87f;
    }
}
