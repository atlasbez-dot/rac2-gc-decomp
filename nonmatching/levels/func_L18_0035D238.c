/* Retained manual C reconstruction, 25 October 2026; not matching.
 * Profile: -O2 -G0 -ffunction-sections -g.
 * 884/880 bytes under -O2 -G0 -ffunction-sections -g. A single normalized radius ratio and
 * shared result path reduce the old 924-byte body; the existing debug-label profile restores the
 * two pre-division nops. Candidate-pointer allocation and final return/restore scheduling still
 * differ. A non-clobbering-copy probe tied and was discarded. Reopen with independent pointer-
 * lifetime or return-layout evidence.
 * Checks: us: func_L18_0035D238: 0 of 3 places match; us2: func_L18_0035D238: 0 of 3 places
 * match; pal: func_L18_0035D238: 0 of 3 places match.
 * No linked build or runtime validation. This header was added after candidate checks; the
 * copied standalone file was not recompiled after retention.
 */

#include "common.h"
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
    struct {
        float offset[4], segment[4], closest[4], first[4], second[4];
    } vectors;
    float along, distance, length, reach, firstT, secondT;
    float firstError, secondError, threshold;
    func_00282CF0(vectors.offset, start, point);
    func_00282CF0(vectors.segment, end, start);
    length = func_00282DB0(vectors.segment, vectors.segment);
    along = -func_00282DB0(vectors.offset, vectors.segment) / length;
    func_00282D30(vectors.closest, vectors.segment, along);
    func_00282CC0(vectors.closest, vectors.closest, start);
    distance = func_00282E48(vectors.closest, point);
    if (distance < radius) {
        reach = func_00282C10(radius * radius - distance * distance);
        length = func_00282DF0(vectors.segment);
        reach /= length;
        firstT = along - reach;
        if (firstT < 0.0f) firstT = 0.0f;
        else if (firstT > 1.0f) firstT = 1.0f;
        secondT = along + reach;
        if (secondT < 0.0f) secondT = 0.0f;
        else if (secondT > 1.0f) secondT = 1.0f;
        func_00282D30(vectors.first, vectors.segment, firstT);
        func_00282CC0(vectors.first, vectors.first, start);
        firstError = func_00282C48(func_00282E48(vectors.first, point) - radius);
        threshold = radius * 0.01f;
        if (firstError < threshold) firstError = 0.0f;
        func_00282D30(vectors.second, vectors.segment, secondT);
        func_00282CC0(vectors.second, vectors.second, start);
        secondError = func_00282C48(func_00282E48(vectors.second, point) - radius);
        if (secondError < threshold) secondError = 0.0f;
        if (firstError < secondError || (firstError == secondError && func_00282E48(vectors.first, reference) < func_00282E48(vectors.second, reference))) {
            qcopy(out, vectors.first);
            distance = firstError;
        } else {
            qcopy(out, vectors.second);
            distance = secondError;
        }
    } else if (along < 0.0f) {
        qcopy(out, start);
        distance = func_00282C48(func_00282E48(out, point) - radius);
    } else if (along > 1.0f) {
        qcopy(out, end);
        distance = func_00282C48(func_00282E48(out, point) - radius);
    } else {
        qcopy(out, vectors.closest);
    }
    if (distance < radius * 0.01f) distance = 0.0f;
    return distance;
}
