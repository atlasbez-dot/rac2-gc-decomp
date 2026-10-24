/*
 * Manual reconstruction retained as a near miss; no linked-build or runtime credit.
 * Prior worker profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Prior worker coverage: US 0/1; US2 0/1; PAL 0/1.
 * These are the recorded worker checks; no fresh compilation was run for retention.
 */

/*
 * Manual C reconstruction retained after bounded retail comparison.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Measured text: 1732 bytes; retail: 1804 bytes. Stack frame 0x320; retail 0x320.
 * Final coverage: US 0/1, US2 0/1, PAL 0/1. Absences are not matches.
 * 2 measured source/profile forms. Target scan, angle/lifetime allocation and branch
 * scheduling differ. The 128-entry disabled-object array, restoration loop, early return and
 * floating comparison polarity are preserved. Reopen on scan/collision source lifetimes and
 * branch shape.
 * All carrying checks are nonmatches (exit 1); no linked-build credit.
 */

typedef int Quad __attribute__((mode(TI)));
typedef union { Quad q; float f[4]; } Vector;
extern float D_L26_001AFDB4 __attribute__((sda));
extern float D_L26_001AFDB0 __attribute__((sda));
extern int D_L26_001A8FF0;
extern int D_L26_001A8FF4 __attribute__((sda));
extern char *D_0018C0B0;
extern short D_0018A168;
extern float D_00189EA0[4];
extern float D_0018A144;
extern char *D_L26_001FAAA0[];
extern char *D_L26_001BEFD8;
extern Vector D_L26_001BEFE0;
extern void func_00282D30(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern char *func_002AB1F0(void *);
extern float func_00283248(float, float);
extern float func_00282E80(void *, void *);
extern float func_00283C80(float, float);
extern float func_00282E48(void *, void *);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern float func_00282C48(float);
extern float func_00282DF0(void *);
extern float func_002831B0(float);
extern void func_002AF000(float *, float, float, float);
extern float func_00283CE0(int);

char *func_L26_003BFF58(char *object, Vector *origin, float *heading, float *pitch) {
    Vector start;
    Vector eye_offset;
    Vector player_eye;
    char *disabled[128];
    Vector target_point;
    Vector offset;
    Vector delta;
    Vector projected;
    char *private = *(char **)(object + 0x68);
    char *target;
    char *descriptor;
    char *result = 0;
    char *hit;
    float best = D_L26_001AFDB4;
    float yaw;
    float elevation;
    float difference;
    float distance;
    float projection;
    float length;
    float cone;
    float radius;
    float margin;
    int close;
    int allowed;
    int index;
    int disabled_count = 0;
    int retries;
    int i;
    start.q = origin->q;
    func_00282D30(&eye_offset, D_0018C0B0 + 0xE0, 0.5f);
    func_00282CC0(&player_eye, D_0018C0B0 + 0x10, &eye_offset);
    if (func_002761F8(&player_eye, &start, 6, D_0018C0B0, 0)) return 0;
    for (index = 0; (target = D_L26_001FAAA0[index]) != 0; index++) {
        if ((signed char)target[0x20] == -2 || (signed char)target[0x20] == -3 ||
            *(short *)(target + 0xAA) == 0xE7D || *(short *)(target + 0xAA) == 0xEB0)
            continue;
        target_point.q = *(Quad *)(target + 0x10);
        descriptor = func_002AB1F0(target);
        if (!descriptor || descriptor[0xE] == 3) continue;
        func_00282D30(&offset, target + 0xE0, *(float *)(descriptor + 0x10));
        func_00282CC0(&target_point, &target_point, &offset);
        if (!*(char **)(target + 0x24) || *(short *)(*(char **)(target + 0x24) + 0x46) != 5)
            continue;
        close = 0;
        yaw = func_00283248(target_point.f[0] - start.f[0], target_point.f[1] - start.f[1]);
        elevation = func_00283248(func_00282E80(&start, &target_point), target_point.f[2] - start.f[2]);
        difference = func_00283C80(*heading, yaw);
        distance = func_00282E48(&start, &target_point);
        if (!D_L26_001A8FF0 && D_0018A168 == 0 && !D_L26_001A8FF4) {
            if (distance < 2.5f &&
                func_00283C80(*(float *)(D_0018C0B0 + 0xF8),
                    func_00283248(*(float *)(target + 0x10) - D_00189EA0[0],
                                   *(float *)(target + 0x14) - D_00189EA0[1])) < 1.0471977f &&
                func_00282C48(start.f[2] - target_point.f[2]) < 2.0f)
                close = 1;
        } else if (distance < 2.5f) {
            func_00282CF0(&delta, target + 0x10, D_0018C0B0 + 0x10);
            projection = func_00282DB0(&delta, D_0018C0B0 + 0xE0);
            if (func_00282C48(projection) < 2.0f) {
                func_00282D30(&projected, D_0018C0B0 + 0xE0, projection);
                func_00282CF0(&delta, &delta, &projected);
                projection = func_00282DB0(&delta, D_0018C0B0 + 0xC0);
                length = func_00282DF0(&delta);
                if (length != 0.0f && 1.5707964f - func_002831B0(projection / length) < 1.0471977f)
                    close = 1;
            }
        }
        if (close && !func_002761F8(&start, &target_point, 6, D_0018C0B0, 0)) {
            result = target;
            *pitch = -elevation;
            *heading = yaw;
            break;
        }
        if (!((distance <= best || target == *(char **)(private + 0x10)) && distance <= D_L26_001AFDB4))
            continue;
        func_002AF000(offset.f, distance, *heading, *pitch + D_0018A144 * 0.5f);
        func_00282CC0(&offset, &offset, &start);
        cone = func_002831B0(func_00282E48(&offset, &target_point) / (distance + distance));
        cone += cone;
        if (cone > D_L26_001AFDB0 * 0.017453294f) {
            descriptor = func_002AB1F0(target);
            if (descriptor) {
                radius = func_00283CE0((unsigned char)descriptor[0xA]) * 0.125f;
                margin = func_002831B0(radius / distance);
                if (radius < distance) {
                    cone -= margin;
                    if (cone < 0.0f) cone = 0.0f;
                }
            }
        }
        allowed = 1;
        if (cone < D_L26_001AFDB0 * 0.017453294f) {
            delta.q = start.q;
            retries = 0;
            while (func_002761F8(&delta, &target_point, 6, object, 0)) {
                if (++retries > 6) break;
                hit = D_L26_001BEFD8;
                if (!hit) { allowed = 0; break; }
                if (*(short *)(hit + 0xAA) != 0xE7D && *(short *)(hit + 0xAA) != 0xEB0) {
                    if (hit != target) allowed = 0;
                    break;
                }
                disabled[disabled_count++] = hit;
                *(int *)(hit + 0x98) = 0;
                if (disabled_count >= 128) break;
                delta.q = D_L26_001BEFE0.q;
            }
            if (allowed) {
                *pitch = -elevation;
                if (difference < 0.17453295f) *heading = yaw;
                result = target;
                best = distance;
                if (target == *(char **)(private + 0x10)) return target;
            }
        }
    }
    for (i = 0; i < disabled_count; i++)
        *(int *)(disabled[i] + 0x98) = *(int *)(*(char **)(disabled[i] + 0x24) + 0x10);
    return result;
}
