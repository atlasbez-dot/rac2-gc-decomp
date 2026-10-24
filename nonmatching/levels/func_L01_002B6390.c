/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Prior worker coverage: US 0/1; US2 0/1; PAL absent from catalogue.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Retained manual reconstruction, 23 October 2026; NOT MATCHING.
 *
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g
 *
 * Meaningful bounded trials: 10.
 *
 * USA v1.01 and USA v2.00: 1336/1336 bytes, 0/1 placements each; PAL does not carry this
 * canonical name. First structural mismatch is +0x238, where the planar pointer and local
 * horizontal-vector pointer use s3/s2 instead of s2/s3. Other scheduling differences remain.
 * Typed TI transfers and an accessed resident prefix recovered the frame and initial instruction
 * sequence. Projection locals preserve f0 across clamps. The forward-distance clamp follows the
 * retail less-than test, including unordered float behavior; a prior equal-size draft with
 * different NaN behavior was corrected. Named pointer and unsplit-edge trials did not resolve
 * allocation.
 *
 * Reopen with measured source lifetime evidence that exchanges the planar/global and local
 * projection pointer allocation without artificial operations.
 *
 * No strict linked build or runtime validation is claimed.
 */
#include "common.h"

typedef struct MotionVector { float x, y, z, w; } MotionVector;
typedef int VectorBits __attribute__((mode(TI)));
typedef struct PlayerMotionView {
    unsigned char pad0[0x80]; MotionVector position, orientation;
    unsigned char padA0[0xF0 - 0xA0]; MotionVector velocity, additional, displacement;
    MotionVector actual, planar, normal, additionalDisplacement;
    unsigned char pad160[0x170 - 0x160]; float distance, planarDistance, forwardDistance, slope, height, additionalDistance;
    unsigned char pad188[0x1F0 - 0x188]; short frozen;
    unsigned char pad1F2[0x264 - 0x1F2]; float maxDistance;
    unsigned char pad268[4]; int contact;
    unsigned char pad270[0x287 - 0x270]; unsigned char contactFlags;
    unsigned char pad288[0x31C - 0x288]; float fallLimit;
    unsigned char pad320[0x588 - 0x320]; void *collisionObject;
    unsigned char pad58C[0xA60 - 0x58C]; MotionVector pending;
    unsigned char padA70[0x2294 - 0xA70]; int state;
} PlayerMotionView;
extern PlayerMotionView D_00189E20;
extern void func_L00_002D4140(void *, void *, void *);
extern float func_L00_002D3A58(char *);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3B58(VectorBits *, VectorBits *, float);
extern void func_L00_002D3BD8(char *, int, float);
extern void func_L00_002D3960(char *, char *);
extern float func_L00_002B5590(MotionVector *);
extern void func_L00_002B5A88(void);
extern void func_L00_002B5250(void);
extern void func_L01_002B5218(void);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);
extern void func_00282C88(VectorBits *);
extern float func_00282DF0(void *);
extern float func_00282DB0(void *, void *);
extern void func_00282F20(void *, void *, float);

/* Apply pending movement, resolve contacts, then retain the resulting displacement. */
void func_L01_002B6390(void)
{
    MotionVector start, horizontal, vertical;
    float amount, zero;

    *(VectorBits *)&start = *(VectorBits *)(&D_00189E20.position);
    func_L00_002D4140(D_00189E20.collisionObject, (&D_00189E20.additional), &D_00189E20.orientation);
    if (D_00189E20.state == 20 || D_00189E20.state == 91 ||
        D_00189E20.state == 88 || D_00189E20.state == 129) {
        if (D_00189E20.frozen == 0) {
            amount = func_L00_002D3A58((char *)(&D_00189E20.velocity));
            if (D_00189E20.maxDistance - 0.02f < amount)
                func_L00_002D3BD8((char *)(&D_00189E20.velocity), (int)(&D_00189E20.velocity), D_00189E20.maxDistance - 0.02f);
        }
        amount = func_L00_002D3B00((char *)(&D_00189E20.velocity));
        if (amount < -D_00189E20.fallLimit) {
            amount = -D_00189E20.fallLimit - 0.02f;
            if (0.0f < amount) amount = 0.0f;
            func_L00_002D3B58((VectorBits *)&D_00189E20.velocity, (VectorBits *)&D_00189E20.velocity, amount);
        }
    } else if (D_00189E20.frozen == 0) {
        amount = func_00282DF0((&D_00189E20.velocity));
        if (D_00189E20.maxDistance - 0.02f < amount)
            func_00282F20((&D_00189E20.velocity), (&D_00189E20.velocity), D_00189E20.maxDistance - 0.02f);
    }
    func_00282CC0((&D_00189E20.position), (&D_00189E20.position), (&D_00189E20.velocity));
    func_00282CC0((&D_00189E20.position), (&D_00189E20.position), &D_00189E20.pending);
    func_00282C88((VectorBits *)(&D_00189E20.pending));
    D_00189E20.contactFlags = 0;
    D_00189E20.contact = 0;
    if (func_00282DF0((&D_00189E20.additional)) <= 0.0001f) {
        func_L00_002B5A88();
        func_L01_002B5218();
        func_00282CF0(&D_00189E20.displacement, (&D_00189E20.position), &start);
        func_L00_002B5250();
    } else {
        func_L01_002B5218();
    }
    func_00282CF0((&D_00189E20.actual), (&D_00189E20.position), &start);
    *(VectorBits *)(&D_00189E20.normal) = *(VectorBits *)(&D_00189E20.actual);
    *(VectorBits *)(&D_00189E20.planar) = *(VectorBits *)(&D_00189E20.actual);
    zero = 0.0f;
    func_00282F20((&D_00189E20.actual), (&D_00189E20.actual), 1.0f);
    {
        float projection = func_00282DB0((&D_00189E20.actual), (&D_00189E20.velocity));
        if (projection < zero) projection = zero;
        func_00282F20((&D_00189E20.actual), (&D_00189E20.velocity), projection);
    }
    *(VectorBits *)&horizontal = *(VectorBits *)(&D_00189E20.velocity);
    func_L00_002D3960((char *)&horizontal, (char *)&horizontal);
    func_L00_002D3960((char *)(&D_00189E20.normal), (char *)(&D_00189E20.normal));
    func_00282F20((&D_00189E20.normal), (&D_00189E20.normal), 1.0f);
    {
        float projection = func_00282DB0((&D_00189E20.normal), &horizontal);
        if (projection < zero) projection = zero;
        func_00282F20((&D_00189E20.normal), &horizontal, projection);
    }
    *(VectorBits *)&vertical = *(VectorBits *)(&D_00189E20.velocity);
    func_L00_002D3BD8((char *)&vertical, (int)&vertical, zero);
    func_L00_002D3BD8((char *)(&D_00189E20.planar), (int)(&D_00189E20.planar), zero);
    func_00282F20((&D_00189E20.planar), (&D_00189E20.planar), 1.0f);
    {
        float projection = func_00282DB0((&D_00189E20.planar), &vertical);
        if (projection < zero) projection = zero;
        func_00282F20((&D_00189E20.planar), &vertical, projection);
    }
    D_00189E20.distance = func_00282DF0((&D_00189E20.actual));
    D_00189E20.planarDistance = func_L00_002D3A58((char *)(&D_00189E20.actual));
    *(VectorBits *)&horizontal = *(VectorBits *)(&D_00189E20.actual);
    D_00189E20.forwardDistance = func_L00_002B5590(&horizontal);
    D_00189E20.height = func_L00_002D3B00((char *)(&D_00189E20.actual));
    if (D_00189E20.forwardDistance < zero) D_00189E20.forwardDistance = zero;
    *(VectorBits *)&horizontal = *(VectorBits *)(&D_00189E20.position);
    if (0.0001f < func_00282DF0((&D_00189E20.additional))) {
        float saved;
        func_00282CC0((&D_00189E20.position), (&D_00189E20.position), (&D_00189E20.additional));
        saved = D_00189E20.additional.w;
        func_00282C88((VectorBits *)(&D_00189E20.additional));
        D_00189E20.additional.w = saved;
        func_L00_002B5A88();
        func_L01_002B5218();
        func_00282CF0(&D_00189E20.displacement, (&D_00189E20.position), &start);
        func_L00_002B5250();
    }
    func_00282CF0(&D_00189E20.additionalDisplacement, (&D_00189E20.position), &horizontal);
    D_00189E20.additionalDistance = func_00282DF0(&D_00189E20.additionalDisplacement);
    D_00189E20.additionalDisplacement.w = D_00189E20.additional.w;
    D_00189E20.additional.w = zero;
    func_00282CF0(&D_00189E20.displacement, (&D_00189E20.position), &start);
    D_00189E20.slope = zero;
    if (0.004f < D_00189E20.planarDistance) {
        D_00189E20.slope = D_00189E20.displacement.z / D_00189E20.planarDistance;
        if (0.5f < D_00189E20.slope) D_00189E20.slope = 0.5f;
        else if (D_00189E20.slope < -0.5f) D_00189E20.slope = -0.5f;
    }
    if (0.86666673f < D_00189E20.distance) {
        func_00282D30(&D_00189E20.displacement, &D_00189E20.displacement, 0.86666673f / D_00189E20.distance);
        D_00189E20.distance = 0.86666673f;
    }
}
