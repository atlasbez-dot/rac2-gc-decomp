/* Bounded manual reconstruction; not linked.
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * 1004/1004 bytes; us: 0/27 places; us2: 0/27 places; pal: absent from catalogue.
 * Collision query and vector copies reproduce size and frame. The absolute scalar access
 * at001B0808 stays nosda. First difference+0x7c is pointer scheduling; later register lifetimes
 * differ. Query members not initialized in retail remain uninitialized. Reopen with a matching
 * collision-query lifetime witness.
 */
typedef int BounceWord128 __attribute__((mode(TI)));
typedef union { BounceWord128 word; float f[4]; } BounceVector;
typedef struct {
    BounceVector previous, position, velocity;
    unsigned char *hit;
    int *excluded;
    int mode;
    float radius, response, friction;
    int flags0, flags1, enabled, surface, active;
    float tolerance;
} BounceQuery;
extern void func_002AFFD8(char *, char *, int);
extern void func_00282CC0(void *, void *, void *);
extern void func_00300190(void *, void *);
extern void func_00300248(int, int);
extern void func_002FEE70(int, void *, int);
extern void func_002FE880(void *, float *, float);
extern int func_002FE9D0(BounceQuery *);
extern int func_002AB1F0(unsigned char *);
extern void func_002FE8D8(void *, float *);
extern void func_00282D30(void *, void *, float);
extern void func_00282F20(void *, void *, float);
extern int func_002761F8(void *, void *, int, void *, void *);
extern int func_002E5CF8(int, int, char *);
extern char *func_L00_003EF3E0(BounceWord128 *, BounceWord128 *);
extern void func_002FEE50(int);
extern void func_0029F338(void *);
extern float func_00283B98(float, float);
extern void func_002A9288(void *, float);
extern float D_L00_001B0808 __attribute__((nosda));
extern float D_L00_001B0828 __attribute__((sda));
extern float D_L00_001B082C __attribute__((sda));
extern BounceVector D_L00_001BF220 __attribute__((nosda));
extern BounceVector D_L00_001BF240 __attribute__((nosda));
#define BW(p,o) (*(BounceWord128 *)((p)+(o)))
#define BF(p,o) (*(float *)((p)+(o)))
#define BI(p,o) (*(int *)((p)+(o)))

void func_L00_003EE920(unsigned char *object) {
    char *state = *(char **)(object + 0x68);
    BounceVector previous, aim, point, normal, offset;
    BounceQuery query;
    int excluded[2], collision;
    char *info, *spawn;
    short category;
    switch (object[0x20]) {
    case 0:
        object[0x20] = 1;
    case 1:
        previous.word = BW(object, 0x10);
        func_002AFFD8((char *)&previous, (char *)&aim, 1);
        func_00282CC0(object + 0x10, object + 0x10, state);
        func_00300190(object + 0x10, object + 0x10);
        func_00300248((int)state, (int)state);
        func_002FEE70(BI(state, 0x34), state, 0);
        func_002FE880(object + 0x10, (float *)state, D_L00_001B0808 * 0.00027777778f);
        excluded[0] = 0;
        excluded[1] = 0xCE3;
        query.previous.word = previous.word;
        query.position.word = BW(object, 0x10);
        query.velocity.word = BW(state, 0);
        query.hit = object;
        query.excluded = excluded;
        query.mode = 2;
        query.radius = 0.25f;
        query.response = D_L00_001B0828;
        query.friction = D_L00_001B082C;
        query.flags0 = 0;
        query.flags1 = 0;
        query.active = 0;
        collision = func_002FE9D0(&query);
        BW(object, 0x10) = query.position.word;
        BW(state, 0) = query.velocity.word;
        BW(state, 0x20) = query.previous.word;
        if (collision == 2)
            object[0x20] = 2;
        if (query.hit) {
            category = *(short *)(*(char **)(query.hit + 0x24) + 0x46);
            if (category == 5 || category == 9 || (*(unsigned short *)(query.hit + 0x34) & 0x4000)) {
                info = (char *)func_002AB1F0(query.hit);
                func_002FE8D8(query.hit + 0x10, normal.f);
                point.word = BW(object, 0x10);
                if (info) {
                    func_00282D30(&offset, &normal, BF(info, 0x10));
                    func_00282CC0(&point, &point, &offset);
                }
                func_00282D30(&normal, &normal, -3.0f);
                func_00282CC0(&normal, &normal, &point);
                object[0x20] = 2;
                BW(object, 0x10) = D_L00_001BF220.word;
                BW(state, 0x20) = D_L00_001BF240.word;
                func_00282F20(state + 0x20, state + 0x20, 1.0f);
                if (func_002761F8(&point, &normal, 6, query.hit, 0)) {
                    BW(object, 0x10) = D_L00_001BF220.word;
                    BW(state, 0x20) = D_L00_001BF240.word;
                    func_00282F20(state + 0x20, state + 0x20, 1.0f);
                }
            }
        }
        break;
    case 2:
        func_002E5CF8(0, 0, (char *)object);
        spawn = func_L00_003EF3E0((BounceWord128 *)(object + 0x10), (BounceWord128 *)(state + 0x20));
        BI(spawn, 0xB8) = BI(state, 0x30);
        func_002FEE50(BI(state, 0x34));
        func_0029F338(object);
        return;
    }
    BF(object, 0xF0) = func_00283B98(BF(object, 0xF0), BF(state, 0x10));
    BF(object, 0xF4) = func_00283B98(BF(object, 0xF4), BF(state, 0x14));
    func_002A9288(object, 0.2f);
    if (BF(object, 0x10) < 2.0f || BF(object, 0x10) > 1021.0f ||
        BF(object, 0x14) < 2.0f || BF(object, 0x14) > 1021.0f ||
        BF(object, 0x18) < 2.0f || BF(object, 0x18) > 1021.0f) {
        func_002FEE50(BI(state, 0x34));
        func_0029F338(object);
    }
}
