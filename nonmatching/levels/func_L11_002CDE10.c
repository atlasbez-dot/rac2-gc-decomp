/* 1372/1372; us/us2 0/2 each; PAL absent.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -g.
 * Resident movement projection preserves three independent 16-byte scratch vectors and full helper inputs, including the live clamp magnitudes omitted by the reference decompiler. Frame/register allocation and resident-base lifetimes differ. No padding added. Reopen with original aggregate/lifetime evidence.
 */
typedef unsigned char u8;
typedef unsigned int u32;
typedef int TI128 __attribute__((mode(TI)));
extern u8 D_00189E20[];
extern void func_L00_002D4140(u32, void *, void *);
extern float func_L00_002D3A58(char *);
extern void func_L00_002D3BD8(char *, int, float);
extern float func_L00_002D3B00(char *);
extern void func_L00_002D3B58(TI128 *, TI128 *, float);
extern float func_00282DF0(void *);
extern void func_00282F20(void *, void *, float);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282C88(TI128 *);
extern void func_L00_002B5A88(void);
extern void func_L09_002B7238(void);
extern void func_00282CF0(void *, void *, void *);
extern void func_L00_002B5250(void);
extern float func_00282DB0(void *, void *);
extern void func_L00_002D3960(char *, char *);
extern float func_L00_002B5590(void *);
extern void func_00282D30(void *, void *, float);

void func_L11_002CDE10(void) {
    TI128 initial, planar, vertical;
    u8 *hero = D_00189E20;
    char *position = (char *)hero + 0x80;
    char *velocity = (char *)hero + 0xF0;
    char *impulse = (char *)hero + 0x100;
    char *displacement = (char *)hero + 0x110;
    char *projected = (char *)hero + 0x120;
    char *up = (char *)hero + 0x130;
    char *flat = (char *)hero + 0x140;
    char *impulseMove = (char *)hero + 0x150;
    float limit, magnitude, component, savedW;
    int state = *(int *)(hero + 0x2294);
    initial = *(TI128 *)position;
    func_L00_002D4140(*(u32 *)(hero + 0x588), impulse, hero + 0x90);
    state = *(int *)(hero + 0x2294);
    if (state == 0x14 || state == 0x5B || state == 0x58 || state == 0x81) {
        if (*(short *)(hero + 0x1F0) == 0) {
            magnitude = func_L00_002D3A58(velocity);
            limit = *(float *)(hero + 0x264) - 0.02f;
            if (limit < magnitude)
                func_L00_002D3BD8(velocity, (int)velocity, limit);
        }
        component = func_L00_002D3B00(velocity);
        if (component < -*(float *)(hero + 0x31C)) {
            limit = -*(float *)(hero + 0x31C) - 0.02f;
            if (limit > 0.0f)
                limit = 0.0f;
            func_L00_002D3B58((TI128 *)velocity, (TI128 *)velocity, limit);
        }
    } else if (*(int *)(hero + 0x229C) != 13 && *(int *)(hero + 0x229C) != 14 && state != 0x44 && *(short *)(hero + 0x1F0) == 0) {
        magnitude = func_00282DF0(velocity);
        limit = *(float *)(hero + 0x264) - 0.02f;
        if (limit < magnitude)
            func_00282F20(velocity, velocity, limit);
    }
    func_00282CC0(position, position, velocity);
    func_00282CC0(position, position, hero + 0xA60);
    func_00282C88((TI128 *)(hero + 0xA60));
    *(u32 *)(hero + 0x26C) = 0;
    hero[0x287] = 0;
    if (func_00282DF0(impulse) <= 0.00009999999747378752f) {
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(displacement, position, &initial);
        func_L00_002B5250();
    } else {
        func_L09_002B7238();
    }
    func_00282CF0(projected, position, &initial);
    *(TI128 *)flat = *(TI128 *)projected;
    *(TI128 *)up = *(TI128 *)projected;
    func_00282F20(projected, projected, 1.0f);
    magnitude = func_00282DB0(projected, velocity);
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(projected, velocity, magnitude);
    planar = *(TI128 *)velocity;
    func_L00_002D3960((char *)&planar, (char *)&planar);
    func_L00_002D3960(flat, flat);
    func_00282F20(flat, flat, 1.0f);
    magnitude = func_00282DB0(flat, &planar);
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(flat, &planar, magnitude);
    vertical = *(TI128 *)velocity;
    func_L00_002D3BD8((char *)&vertical, (int)&vertical, 0.0f);
    func_L00_002D3BD8(up, (int)up, 0.0f);
    func_00282F20(up, up, 1.0f);
    magnitude = func_00282DB0(up, &vertical);
    if (magnitude < 0.0f)
        magnitude = 0.0f;
    func_00282F20(up, &vertical, magnitude);
    *(float *)(hero + 0x170) = func_00282DF0(projected);
    *(float *)(hero + 0x174) = func_L00_002D3A58(projected);
    planar = *(TI128 *)projected;
    *(float *)(hero + 0x178) = func_L00_002B5590(&planar);
    *(float *)(hero + 0x180) = func_L00_002D3B00(projected);
    if (*(float *)(hero + 0x178) < 0.0f)
        *(float *)(hero + 0x178) = 0.0f;
    planar = *(TI128 *)position;
    if (func_00282DF0(impulse) > 0.00009999999747378752f) {
        func_00282CC0(position, position, impulse);
        savedW = *(float *)(impulse + 0xC);
        func_00282C88((TI128 *)impulse);
        *(float *)(impulse + 0xC) = savedW;
        func_L00_002B5A88();
        func_L09_002B7238();
        func_00282CF0(displacement, position, &initial);
        func_L00_002B5250();
    }
    func_00282CF0(impulseMove, position, &planar);
    *(float *)(hero + 0x184) = func_00282DF0(impulseMove);
    *(float *)(impulseMove + 0xC) = *(float *)(impulse + 0xC);
    *(float *)(impulse + 0xC) = 0.0f;
    func_00282CF0(displacement, position, &initial);
    *(float *)(hero + 0x17C) = 0.0f;
    if (*(float *)(hero + 0x174) > 0.004000000189989805f) {
        component = *(float *)(displacement + 8) / *(float *)(hero + 0x174);
        if (component > 0.5f)
            component = 0.5f;
        else if (component < -0.5f)
            component = -0.5f;
        *(float *)(hero + 0x17C) = component;
    }
    if (*(float *)(hero + 0x170) > 0.8666667342185974f) {
        func_00282D30(displacement, displacement, 0.8666667342185974f / *(float *)(hero + 0x170));
        *(float *)(hero + 0x170) = 0.8666667342185974f;
    }
}
