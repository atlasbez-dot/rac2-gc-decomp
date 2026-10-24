/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 516 / 524 bytes; size equality is not a match.
 * us: 0/27 placements; 516/524 bytes.
 * us2: 0/27 placements; 516/524 bytes.
 * pal: 0/27 placements; 516/524 bytes.
 * Residual: Resident-base allocation and loop address formation differ; both matrix temporaries are measured three-row, 48-byte objects.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: 0 of 27 places match; exit 1.
 * Resident-base allocation and loop address formation differ; both matrix temporaries are measured three-row, 48-byte objects.
 * 3 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef int Quadword __attribute__((mode(TI)));
typedef union { Quadword q; float f[4]; } Vector;
typedef struct { Vector row[3]; } Matrix3;
extern unsigned char D_00189E20[];
extern void func_00283360(Matrix3 *);
extern void func_00282F20(Vector *, Vector *, float);
extern void func_00283738(Matrix3 *, Matrix3 *, Matrix3 *);
extern void func_00282CF0(Vector *, Vector *, Vector *);
extern void func_00283098(Vector *, Vector *, Matrix3 *);
extern void func_00282CC0(Vector *, Vector *, Vector *);

/* Apply the pending axis scales to the player and its attached objects. */
void func_L00_002A7748(void) {
    Matrix3 scale;
    Matrix3 transformed;
    Vector delta;
    unsigned char *player = D_00189E20;
    unsigned char *object;
    int row, column;
    if (*(short *)(player + 0x2500) == 0) return;
    func_00283360(&scale);
    func_00282F20(&scale.row[0], &scale.row[0], *(float *)(player + 0x2020));
    func_00282F20(&scale.row[1], &scale.row[1], *(float *)(player + 0x2024));
    func_00282F20(&scale.row[2], &scale.row[2], *(float *)(player + 0x2028));
    func_00283738(&transformed, &scale, (Matrix3 *)(player + 0x40));
    func_00283738(&transformed, (Matrix3 *)player, &transformed);
    object = *(unsigned char **)(player + 0x2290);
    func_00283738((Matrix3 *)(object + 0xC0), (Matrix3 *)(object + 0xC0), &scale);
    if (player[0x22B4] == 0) {
        unsigned char *player = D_00189E20;
        for (row = 0; row < 7; ++row) {
            for (column = 0; column < 3; ++column) {
                object = *(unsigned char **)(player + row * 0x50 + 0x1220);
                if (column == 1) object = *(unsigned char **)(player + row * 0x50 + 0x1224);
                else if (column == 2) object = *(unsigned char **)(player + row * 0x50 + 0x1228);
                if (object) {
                    func_00283738((Matrix3 *)(object + 0xC0), &transformed, (Matrix3 *)(object + 0xC0));
                    func_00282CF0(&delta, (Vector *)(object + 0x10), (Vector *)(player + 0x80));
                    func_00283098(&delta, &delta, &transformed);
                    func_00282CC0((Vector *)(object + 0x10), &delta, (Vector *)(player + 0x80));
                }
            }
        }
    }
    {
        unsigned char *tail = D_00189E20;
    if (*(float *)(tail + 0x2020) == 1.0f && *(float *)(tail + 0x2024) == 1.0f && *(float *)(tail + 0x2028) == 1.0f)
        *(short *)(tail + 0x2500) = 0;
    *(float *)(tail + 0x2028) = 1.0f;
    *(float *)(tail + 0x2020) = 1.0f;
    *(float *)(tail + 0x2024) = 1.0f;
}
}
