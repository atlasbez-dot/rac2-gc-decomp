/* Measured profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier. us: 18_damosel: 924
   bytes, expected 880; us2: 18_damosel: 924 bytes, expected 880; pal: 18_damosel: 924 bytes, expected
   880. Two source forms measured 916 and 924 bytes versus 880. The retained 924-byte form follows the
   retail distance-less-than-radius predicate, including its unordered-comparison direction. Full
   segment and candidate vectors retained; output selection, shared return paths and register lifetimes
   differ. Reopen with a matching geometric branch/return idiom. No linked build or functional
   execution run. */

/* Historical screening below; superseded by the measured C reconstruction. */
/* func_L18_0035D238 - 880 bytes, 3 place(s), level 18_damosel, retail at
   0x0035d238. Screened with tools/w10_screen.py: 21 call(s)
   [func_00282CF0@0035D290, func_00282CF0@0035D2A4, func_00282DB0@0035D2B4,
   func_00282DB0@0035D2C4, func_00282D30@0035D2E8, func_00282CC0@0035D2F8,
   func_00282E48@0035D304, func_00282C10@0035D328, func_00282DF0@0035D334,
   func_00282D30@0035D3C0, func_00282CC0@0035D3D0, func_00282E48@0035D3DC,
   func_00282C48@0035D3E4, func_00282D30@0035D41C, func_00282CC0@0035D42C,
   func_00282E48@0035D438, func_00282C48@0035D440, func_00282E48@0035D484,
   func_00282E48@0035D494, func_00282E48@0035D51C, func_00282C48@0035D524];
   data addresses materialised [0x3c230000, 0x3c230000]; float constants
   [0x3f800000, 0x3f800000, 0x3f800000]; $gp-relative small data: no
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [LQ/SQ 7A220000@0x0274, LQ/SQ 7E420000@0x0278, LQ/SQ 7A020000@0x0284,
   LQ/SQ 7E420000@0x0288, LQ/SQ 7A620000@0x02ac, LQ/SQ 7E420000@0x02b0,
   LQ/SQ 7AA20000@0x02d8, LQ/SQ 7E420000@0x02dc, LQ/SQ 7A220000@0x02fc,
   LQ/SQ 7E420000@0x0300]. Head: addiu $sp, $sp, -0xD0 ; sd $s2, 0x60($sp) ;
   sd $s3, 0x68($sp) ; daddu $s2, $a0, $zero ; sd $s4, 0x70($sp) ; daddu
   $s3, $a3, $zero. Not matched in this wave: the 128-bit copy needs an
   `lq`/`sq` pair; plain C reaches it only through a `mode(TI)` local, and
   this cc1 folds the destination offset into the `sq` where retail
   materialises the pointer first. What would unblock it: the exact source
   expression tree, so this cc1 picks the same registers in the same order. */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282E48(void *, void *);
extern float func_00282C10(float);
extern float func_00282DF0(void *);
extern float func_00282C48(float);
float func_L18_0035D238(float radius, float *out, float *reference, float *point, float *start, float *end)
{
    float offset[4], segment[4], closest[4], first[4], second[4];
    float along, distance, length, reach, firstT, secondT;
    float firstError, secondError, threshold;
    func_00282CF0(offset, start, point);
    func_00282CF0(segment, end, start);
    length = func_00282DB0(segment, segment);
    along = -func_00282DB0(offset, segment) / length;
    func_00282D30(closest, segment, along);
    func_00282CC0(closest, closest, start);
    distance = func_00282E48(closest, point);
    if (distance < radius) {
        reach = func_00282C10(radius * radius - distance * distance);
        length = func_00282DF0(segment);
        firstT = along - reach / length;
        if (firstT < 0.0f) firstT = 0.0f;
        else if (firstT > 1.0f) firstT = 1.0f;
        secondT = along + reach / length;
        if (secondT < 0.0f) secondT = 0.0f;
        else if (secondT > 1.0f) secondT = 1.0f;
        func_00282D30(first, segment, firstT);
        func_00282CC0(first, first, start);
        firstError = func_00282C48(func_00282E48(first, point) - radius);
        threshold = radius * 0.01f;
        if (firstError < threshold) firstError = 0.0f;
        func_00282D30(second, segment, secondT);
        func_00282CC0(second, second, start);
        secondError = func_00282C48(func_00282E48(second, point) - radius);
        if (secondError < threshold) secondError = 0.0f;
        if (firstError < secondError || (firstError == secondError && func_00282E48(first, reference) < func_00282E48(second, reference))) {
            *(VectorBits *)out = *(VectorBits *)first;
            return firstError;
        }
        *(VectorBits *)out = *(VectorBits *)second;
        return secondError;
    }
    if (along < 0.0f) {
        *(VectorBits *)out = *(VectorBits *)start;
    } else if (along > 1.0f) {
        *(VectorBits *)out = *(VectorBits *)end;
    } else {
        *(VectorBits *)out = *(VectorBits *)closest;
        if (distance < radius * 0.01f) distance = 0.0f;
        return distance;
    }
    distance = func_00282C48(func_00282E48(out, point) - radius);
    if (distance < radius * 0.01f) distance = 0.0f;
    return distance;
}
