/* Best attempt, session of 23 October 2026 (small tier, 27 places). Last check.py line:
   func_L00_003EB7C0: 0 of 27 places match (src/levels/shared/L00_003EA0E0.c)
   retail 292 bytes, best produced 268-280. Same family wall as the recorded
   straight-line L00 near misses: the prologue's callee-saved set and store order
   (retail saves $s0-$s2 then $ra at 0x28; the closest attempt saved two s-registers
   and $ra at 0x20), the late materialisation of the table base (retail lui $s1,0x19
   after the second func_2EF240 call; the attempt hoists it to function entry), the
   per-block `lw 0x2290($s1)` loads and the atan call's scheduling. Base-as-local with
   shared `lw 0x2290` and `addiu 0x80`, per-block pointer locals and inline derefs at
   the call arguments were all measured; none reproduced the retail order.
   Body semantics: f20 = func_2EF240(*(int*)(object+0x38)) * PI / func_2EF240(3);
   three euler angles from f20 via func_2EE6E0/func_2EE6F8 (1.2x, 1.2x + 6.15, 2x),
   func_2EE3D0 each against the pointer at *(D_00189E20_6 + 0x2290) + 0xD0/0xE0/0xC0,
   then three func_2EE108 composes into the object. */

extern float func_2EE6E0(float);
extern float func_2EE6F8(float);
extern float func_2EF240(int);
extern void func_2EE3D0(void *, void *, float);
extern void func_2EE108(void *out, void *in, char *angles);
extern char D_00189E20_6[];

void func_L00_003EB7C0(char *a0, char *object)
{
    char buf[16];
    char *base = D_00189E20_6;
    char *head;
    float scaled = 1.2f;
    float angle;
    float f;

    f = func_2EF240(*(int *)(object + 0x38));
    angle = f * (3.1415927f / func_2EF240(3));
    f = func_2EE6E0(angle);
    head = *(char **)(base + 0x2290);
    func_2EE3D0(buf, head + 0xD0, f * scaled);
    func_2EE108(object, buf, base + 0x80);
    f = func_2EE6F8(angle);
    head = *(char **)(base + 0x2290);
    func_2EE3D0(buf, head + 0xE0, f * scaled + 6.15f);
    func_2EE108(object, object, buf);
    f = func_2EE6F8(angle);
    head = *(char **)(base + 0x2290);
    func_2EE3D0(buf, head + 0xC0, f + f);
    func_2EE108(object, object, buf);
}
