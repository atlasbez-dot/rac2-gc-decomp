/* func_0034E070 - 420 bytes, 28 places (the boot and every level).

   Near miss (428 of 420 bytes): the body is right - the two global parameter
   reads, the loop over the 0x48-byte records of the object with its eight
   calls, the two colour writes and the two trailing calls - but the register
   allocation differs:

   * the retail keeps the object in $s1, the second argument in $s2, the loop
     limit (object + 0x750) in $s3, the first argument in $s4 and the %hi of
     D_001AE710 in $s5; this C keeps the object in $s2 and the loop limit in a
     temporary, so it needs an extra `daddu` copy and one more saved register;
   * the retail loads D_001A8CFC with `lui $v0,0x1B; lw $v0,-0x7304($v0)` twice
     (the high half is not kept in a register), this C keeps the high half in
     a saved register across the calls.

   Declaring D_001A8CFC with __attribute__((sda)) gives the retail's
   `lui`/`lw` pair for the first load but does not change the allocation and
   makes the body longer (436 bytes).

   What would unblock it: the source shape that keeps the loop limit in a
   callee-saved register and reloads the address of D_001A8CFC at each use.
*/

extern int D_001A8CFC;
extern void *D_001AE710;
extern void *D_001AE720;

extern int func_00336D50(int, int);
extern void func_00336408(void *, int, int, void *, void *);
extern void func_00336CC8(void *, int);
extern void func_00336B90(void *, int);
extern void func_00336B98(void *, int);
extern void func_00336498(void *, int, int);
extern void func_003364B0(void *, int, int);
extern void func_00336CE0(void *, int);
extern void func_00336CC0(void *, int);
extern void func_0034B2C8(void *, int, int);
extern void func_00336710(void *, void *, void *);
extern int *func_00335E20(void *);
extern void *func_003367B8(void *);
extern void func_00337C10(void *, void *);

void func_0034E070(void *object, int a1, int a2)
{
    char *base = (char *)object;
    char *record = base;
    void *colour;

    *(int *)(base + 0x220C) = func_00336D50(D_001A8CFC + 0x8710, 0x57);
    *(int *)(base + 0x2210) = func_00336D50(D_001A8CFC + 0x8710, 0x58);
    for (; record < base + 0x750; record += 0x48) {
        func_00336408(record, 0x20, 1, D_001AE710, (void *)a2);
        func_00336CC8(record, 5);
        func_00336B90(record, 0x64);
        func_00336B98(record, 0);
        func_00336498(record, 0x8049C1FF, 0x80001EFF);
        func_003364B0(record, 0x50F0C070, 0x50F0C070);
        func_00336CE0(record, 0x8000);
        func_00336CC0(record, 1);
    }
    func_0034B2C8(base + 0x7A0, a1, a2);
    func_00336710(base + 0x1D30, D_001AE720, (void *)a2);
    func_00335E20(base + 0x1D30);
    colour = func_003367B8(base + 0x1D30);
    *(float *)colour = 2155905152.0f;
    colour = func_003367B8(base + 0x1D30);
    *(float *)colour = 60020.0f;
    *(int *)((char *)colour + 4) = 0;
    *(int *)(base + 0x798) = a2;
    func_00337C10(base + 0x1D6C, (void *)a2);
    func_00337C10(base + 0x1FBC, (void *)a2);
}
