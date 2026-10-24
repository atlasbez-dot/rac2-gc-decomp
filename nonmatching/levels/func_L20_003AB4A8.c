/* Readable C reconstruction, measured2026-10-23.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0/1, us2: 0/1, pal: not carried.
 * 788 versus776 bytes; collision branches, scalar/vector scheduling and register allocation differ.
 * Tried: Measured collision-query fields, vector copies and exact retail float constants.
 * Reopen: A demonstrated collision-query/control-flow source shape.
 * Historical notes below are preserved; their copy-wall claims are superseded
 * by the current qualified copy profiles. No handwritten-assembly inference.
 */

/* Not matched (worker 06, level-20 wave of 2026-10-20): the 128-bit
   copies are the wall.  The retail mixes the two forms inside this
   one body: the stores to the stack keep their offset (`sq $v0,0x10($sp)`
   - the offset is in the instruction) while the copies whose base is a
   computed pointer go through a register (`lq $v0,0x0($s3)` with `addiu
   $s3,...`, `sq $v0,0x0($s5)`, `lq $v0,0x0($s2)`, `sq $v0,0x0($s0)`,
   `lq $v0,0x0($a0)`, `sq $v0,0x0($v1)`).

   This compiler folds the offset of every 128-bit access into the
   instruction, so the copies whose base is `reg + const` do not match.
   The mechanism is measured in the note of func_L20_0039C448: the CSE
   substitutes the pointer's value into the address of the `lq`/`sq` and
   the reload pass keeps the offset in the instruction; only a pointer
   that is a parameter or a value loaded from memory keeps the register
   form.

   This body belongs in the `-G8` unit?  No: it reaches no global
   through `$gp`. */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct {
    Vector direction;
    void *owner;
    unsigned int mask;
    unsigned char mode, flags;
    short kind;
    int code, enabled;
} CollisionQuery;
typedef struct { int code; unsigned char unknown[0xDC]; } CollisionSettings;
extern unsigned char D_00139574;
extern CollisionSettings D_L20_0026D9E0[];
extern unsigned char *D_0018C0B0;
extern unsigned char *D_L20_001C0418;
extern int D_L20_001C041C;
extern Vector D_L20_001C0420, D_L20_001C0440;
extern void *D_L20_001AC810;
extern void func_00282CC0(void *, const void *, const void *);
extern void func_002AFFD8(char *, char *, int);
extern void func_00282D30(void *, const void *, float);
extern void func_L00_0038F3D8(char *);
extern void func_00282F70(void *, const void *, float);
extern int func_002761F8(void *, void *, int, void *, CollisionQuery *);
extern void func_00283028(void *, const void *, const void *);
extern void func_00282F20(void *, const void *, float);
extern int func_00282948(int *);
extern void func_002FEE50(int);
extern void func_L00_0038DE70(void *, void *, void *);
extern void func_L00_0038E880(void *, void *, void *);

void func_L20_003AB4A8(unsigned char *object) {
    Vector response, normal, oldPosition, direction;
    CollisionQuery query;
    unsigned char *state = *(unsigned char **)(object + 0x68);
    Vector *position = (Vector *)(object + 0x10);
    unsigned char *hit;
    int collision;
    response.q = 0;
    normal.q = 0;
    response.f[2] = 0.033333335f;
    normal.f[2] = 1.0f;
    oldPosition.q = position->q;
    func_00282CC0(position, position, state);
    func_002AFFD8((char *)position, (char *)&direction, 0);
    func_00282D30(&direction, &direction, 0.000305555586004f);
    func_L00_0038F3D8((char *)object);
    query.mask = 0x830000;
    if (*(int *)(state + 0x18) < 290) query.mask = 0x830001;
    query.enabled = 1;
    query.code = D_L20_0026D9E0[D_00139574].code;
    query.direction.q = *(Quadword *)state;
    query.owner = object;
    func_00282F70(&query.direction, &query.direction, 1.0f);
    query.kind = *(short *)(object + 0xAA);
    query.mode = 2;
    query.flags = 1;
    query.direction.f[3] = 5627.9248046875f;
    query.direction.f[2] = 1.0f;
    ++*(int *)(state + 0x14);
    collision = func_002761F8(&oldPosition, position, 16, object, &query);
    if (!collision) {
        if (func_00282948((int *)(state + 0x18))) {
            object[0xBC] = 1;
            func_00282CC0(&response, &response, state);
        }
    } else {
        hit = D_L20_001C0418;
        if (hit) {
            if (!((hit == D_0018C0B0 || *(short *)(hit + 0xAA) == 0xC0) && *(int *)(state + 0x18) > 289) &&
                !(*(void **)(hit + 0x64) == D_L20_001AC810 && *(short *)(hit + 0xAA) != 0x336)) {
                object[0xBC] = 1;
                position->q = D_L20_001C0420.q;
                func_00283028(&response, state, &D_L20_001C0440);
                func_00282F20(&response, &response, 0.033333335f);
                func_00282F20(&normal, &D_L20_001C0440, 1.0f);
            }
        } else if (D_L20_001C041C > 0) {
            object[0xBC] = 1;
            position->q = D_L20_001C0420.q;
            func_00283028(&response, state, &D_L20_001C0440);
            func_00282F20(&response, &response, 0.033333335f);
            func_00282F20(&normal, &D_L20_001C0440, 1.0f);
        }
    }
    if (object[0xBC]) {
        func_002FEE50(*(int *)(state + 0x1C));
        if (*(int *)(state + 0x14) < 20) func_L00_0038DE70(object, &response, &normal);
        else func_L00_0038E880(object, &response, &normal);
    }
}
