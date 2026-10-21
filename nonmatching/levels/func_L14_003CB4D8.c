/* func_L14_003CB4D8 (224 bytes, 1 place: 14_aranos_prison) -- NEAR MISS, not integrated.
   state: 224 bytes, the frame is the retail one and the instruction count is the
   retail one; what differs is the register allocation and where the pointers
   come from.
   check.py (14_aranos_prison), with the source below:
     003CB4DC  sd $s0,0x40($sp)     | sd $s1,0x48($sp)
     003CB4E4  daddu $s0,$a0,$zero  | daddu $s1,$a0,$zero
     003CB530  addiu $s1,$sp,0x20   | addiu $s0,$sp,0x20
   Retail keeps the object pointer in $s1 and the vector buffer's address in $s0,
   this cc1 keeps them the other way round; the derived pointers (arg0 + 0xC0,
   *(arg0 + 0x68), arg0 + 0xF0) are the retail ones.
   What is measured and right:
   - the file has to be a -g8 one: the level's own float at 0x001AFF0C is read
     through $gp (`lwc1 $f0,0xF1C($gp)`), which only the small-data profile
     emits (the matched src/levels/shared/L00_003A8E28-g8.c is the witness);
   - the zero quadword is materialised in $v0 and stored (`por`+`sq`), which
     needs a second 16-byte object in the frame: the vector at +0x30 is zeroed and
     then copied to the one at +0x20, and the copy keeps the register alive;
   - the four 16-byte locals are the rotation vector (copied from arg0 + 0xF0 and
     passed to func_002AD6F0, the level's 0x328DA8), the buffer, and the two
     vectors the engine builds from the level's float;
   - the calls are func_002833F0 (0x2F6498), func_00283098 (0x2F60F8),
     func_00282CC0 (0x2F5C38) twice, func_00282CF0 (0x2F5C68) and func_002AD6F0.
   Tried and not enough: the object pointer as a parameter that is modified in
     place, as a separate variable that is incremented, and as a copy of the
     parameter; the derived pointers taken from the parameter and from the copy;
     the buffer's address as a variable and as the array itself.
   Next idea: a source that keeps the object's pointer in $s1 and the buffer's
   address in $s0; the allocator hands out the callee-saved registers in the
   order the locals are created, and the parameter's copy is created first. */

extern float D_L14_001AFF0C __attribute__((sda));

extern void func_2F6498(void *dst, void *src);

extern void func_2F60F8(void *dst, void *src, void *mtx);

extern void func_2F5C38(void *dst, void *src, void *src2);

extern void func_2F5C68(void *dst, void *src, void *src2);

extern void func_328DA8(void *a, void *b, void *c, void *d);

/* A 16-byte vector: the compiler reaches lq/sq only through TImode. */
typedef int TI128 __attribute__((mode(TI)));

void func_L14_003CB4D8(char *arg0) {
    float v0[4];
    float v1[4];
    float v2[4];
    float v3[4];
    TI128 zero = 0;
    char *s2;
    char *s3;
    char *s4;

    s2 = arg0 + 0xC0;
    s3 = *(char **)(arg0 + 0x68);
    s4 = arg0 + 0xF0;
    *(TI128 *)v0 = *(TI128 *)s4;
    *(float *)(arg0 + 0xF4) = *(float *)(s3 + 0x80);
    func_2F6498(s2, s4);
    arg0 = arg0 + 0x10;
    *(TI128 *)v3 = zero;
    v3[2] = D_L14_001AFF0C;
    *(TI128 *)v2 = *(TI128 *)v3;
    func_2F60F8(v2, v2, s2);
    func_2F5C38(v2, v2, arg0);
    func_2F5C68(v1, s3 + 0x70, v2);
    func_2F5C38(arg0, arg0, v1);
    func_328DA8(s3 + 0x20, v1, v0, s4);
}
