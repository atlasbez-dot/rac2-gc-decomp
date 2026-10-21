/* func_L00_002D4C28 (364 bytes, 27 places) - best attempt, NOT MATCHED.
 *
 * tools/check.py func_L00_002D4C28 --diff:
 *   "00_aranos_tutorial: 368 bytes, expected 364" and the same for the other 26 places.
 *
 * The prologue (the mode test, the two branches and the frame) and the whole tail (the
 * six flag-bit clears and the epilogue) are byte-identical to retail, and so is the loop
 * body.  Two measured differences remain, both about the address of the record at
 * D_L00_001BCAC0:
 *   (a) retail materialises that address once (`lui $v1,0x1C ; addiu $v1,$v1,-0x3540`),
 *       keeps it in $v1 and puts the list pointer in $a2 (`addiu $a2,$v1,0x18C`); this cc1
 *       copies the address into $t0 for the loop and then reuses $v1 for the list pointer
 *       (`addiu $v1,$v1,0x18C`), so the loop's count reload reads $t0 instead of $v1;
 *   (b) the two constants of the loop body land in $a3/$a2 here and in $t0/$a3 in retail,
 *       a consequence of (a) (the extra live value).
 *
 * What was measured to get here (each step is a compile):
 *   - the base must be reached through a struct member (`Base_2A`), not through
 *     `char *base = D_00189E20_2A`: only the struct form gives retail's
 *     `lui`+`addiu`+`lw <member offset>` shape; the plain array form puts the %lo
 *     relocation on the load, which tools/check.py cannot match against retail's
 *     %hi/%lo pair on the lui/addiu;
 *   - the mode word D_L00_001A8F00 is read once and keeps retail's coalesced
 *     `lui $v1,%hi ; lw $v1,%lo($v1)` form; putting it in a variable splits the two
 *     registers and the body no longer matches;
 *   - the count is read from the record on every iteration (the loop body can alias it),
 *     which is what makes retail reload it with `lh $v0,0x44($v1)`;
 *   - `if (mode != 2 && mode != 6) return;` gives retail's `beq`/`bnel` pair.
 *
 * To retake: a source whose list pointer is a separate value from the record address, so
 * that the record address stays in $v1 for the whole loop.
 */

extern char D_00189E20_2A[];

extern char D_L00_001BCAC0[];

extern void func_L00_002AFBF0(void);

extern void func_L00_002AA178(char *);

extern void func_L00_002B0968(char *);

extern void func_L00_002D4A38(void);

#ifndef RAC2_T_BASE_2A
#define RAC2_T_BASE_2A
typedef struct {
    unsigned char pad0[0x1270];
    void *f1270;
    void *f1274;
    unsigned char pad1[0x12C0 - 0x1278];
    void *f12C0;
    unsigned char pad2[0x1360 - 0x12C4];
    void *f1360;
    void *f1364;
    void *f1368;
} Base_2A;
#endif

#ifndef RAC2_T_REC_1BCAC0
#define RAC2_T_REC_1BCAC0
typedef struct {
    unsigned char pad0[0x44];
    short count;
    unsigned char pad1[0x18C - 0x46];
    void *list[1];
} Rec_1BCAC0;
#endif

/* Clears the flag bit of every node of the record's list whose kind is 0x50A, then
   runs the three level entry points and clears the flag bit of the six level
   objects. */
void func_L00_002D4C28(char *arg0)
{
    int mode = D_L00_001A8F00;
    int i;
    void **p;
    void *node;
    unsigned short v;

    if (mode != 2 && mode != 6)
        return;

    if (((Base_2A *)D_00189E20_2A)->f12C0 == 0)
        func_L00_002AFBF0();

    i = 0;
    if (((Rec_1BCAC0 *)D_L00_001BCAC0)->count > 0) {
        p = &((Rec_1BCAC0 *)D_L00_001BCAC0)->list[0];
        do {
            node = *p;
            if (node != 0) {
                if (*(short *)((char *)node + 0xAA) == 0x50A) {
                    v = *(unsigned short *)((char *)node + 0x34);
                    if (v != 0xD54) {
                        v |= 0x800;
                        *(unsigned short *)((char *)node + 0x34) = v;
                    }
                }
            }
            i++;
            p++;
        } while (i < ((Rec_1BCAC0 *)D_L00_001BCAC0)->count);
    }

    func_L00_002AA178(arg0);
    func_L00_002B0968(arg0);
    func_L00_002D4A38();

    node = ((Base_2A *)D_00189E20_2A)->f12C0;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
    node = ((Base_2A *)D_00189E20_2A)->f1270;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
    node = ((Base_2A *)D_00189E20_2A)->f1274;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
    node = ((Base_2A *)D_00189E20_2A)->f1360;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
    node = ((Base_2A *)D_00189E20_2A)->f1364;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
    node = ((Base_2A *)D_00189E20_2A)->f1368;
    if (node != 0) {
        v = *(unsigned short *)((char *)node + 0x34);
        *(unsigned short *)((char *)node + 0x34) = v & 0xFFFE;
    }
}
