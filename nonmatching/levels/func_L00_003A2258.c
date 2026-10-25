/* Retained nonmatching C; measured 25 October 2026.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Final check.py coverage: us 0/27, us2 0/27, pal 0/27.
 * 420/420 bytes; first difference +0x3C is first-input/index s5/s6 allocation. Allocator records first-pointer refs7/live60 versus indexrefs9/live114. Earlier increment changes scheduling; non-clobbering local transfers did not close the allocation.
 * Reopen: Reopen only with a measured genuine pointer/index lifetime witness that changes their interference/ranking; three forms were bounded and no artificial reference was added.
 * Shared EE transfer helpers are approved; their use is not matching evidence.
 * Earlier complete drafts and all trial sources/logs are preserved privately.
 */

#include "common.h"
typedef int VectorBits __attribute__((mode(TI)));
extern float func_00283CE0(int);
extern void func_L00_003A1F68(VectorBits *, VectorBits *, VectorBits *, float);
extern void func_L00_003A2018(void *, void *, void *, void *, void *, float);
extern float func_002A7878(float, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_L00_003A2668(void *, int, void *, int);

/* Interpolate the beam's sample points and perturb them before drawing. */
void func_L00_003A2258(char *owner, void *first, void *second, char *settings)
{
    float points[11][4], left[4], right[4], noise[4];
    float (*cursor)[4] = points;
    int i = 0;
    char *leftTangent = settings + 0x50;
    char *rightTangent = settings + 0x60;
    do {
        float t = func_00283CE0(i);
        t /= func_00283CE0(9);
        func_L00_003A1F68((VectorBits *)cursor, (VectorBits *)first, (VectorBits *)second, t);
        qcopy(left, leftTangent);
        qcopy(right, rightTangent);
        func_00282CC0(left, left, first);
        func_00282CC0(right, right, second);
        func_L00_003A2018(cursor, first, second, left, right, t);
        noise[3] = 0.0f;
        noise[0] = func_002A7878(-1.0f, 1.0f);
        noise[1] = func_002A7878(-1.0f, 1.0f);
        noise[2] = func_002A7878(-1.0f, 1.0f);
        func_00282F20(noise, noise, 0.04f);
        func_00282CC0(cursor, cursor, noise);
        cursor++;
        i++;
    } while (i < 10);
    func_L00_003A2668(owner, 0x80, points, 11);
}
