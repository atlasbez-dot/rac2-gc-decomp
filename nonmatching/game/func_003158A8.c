/* func_003158A8 (292 bytes, 28 places; unit src/game/0030F7B0-qcopy.c).
   26 October 2026 (M32): 292/292, 7 lines off: the four float zeros are one chained
   assignment (retail stores them from one FPR), the constants are 0x3C8EFA37/0x3D567752.
   Left: the D_001B1688 read (retail lui/lw tied in  before the -1; a sda [] form
   ties it but the scheduler then sinks it) and the 0x5C/0x6C store order. Permuter. */
typedef int TI128 __attribute__((mode(TI)));

/* func_003158A8: spawns effect object 0x81F at the given position for the owner,
   half its default scale, and seeds its spin rates (1 to 3 degrees). */
typedef struct {
    char pad00[0x30];
    int owner;
    char pad34[2];
    short timer;
    float spinX;
    float spinY;
    char pad40[0x1C];
    int start;
    float unk60;
    float unk64;
    int state;
    float unk6C;
    float unk70;
    int unk74;
    int unk78;
} EffectVars_003158A8;

typedef struct {
    char pad00[0x10];
    TI128 position;
    unsigned char active;
    char pad21[0xB];
    float scale;
    unsigned char alpha;
    unsigned char flag31;
    short half32;
    char pad34[0x34];
    EffectVars_003158A8 *vars;
    char pad6C[0x2C];
    int unk98;
} Effect_003158A8;

extern void *func_0029EFD0(int);
extern void func_00282C88(void *);
extern float func_002A7878(float, float);
extern void func_002A0F48(void *);
extern int D_001B1688;

Effect_003158A8 *func_003158A8(int owner, TI128 *position)
{
    Effect_003158A8 *object = (Effect_003158A8 *)func_0029EFD0(0x81F);

    if (object != 0) {
        EffectVars_003158A8 *vars = object->vars;

        object->alpha = 0xFF;
        object->half32 = 0x7F;
        object->flag31 = 1;
        object->scale = object->scale * 0.5f;
        object->active = 1;
        vars->owner = owner;
        vars->timer = 0;
        vars->unk78 = 0;
        object->position = *position;
        func_00282C88(vars);
        vars->spinX = func_002A7878(0.017453296f, 0.052359886f);
        vars->spinY = func_002A7878(0.017453296f, 0.052359886f);
        vars->start = D_001B1688;
        vars->unk6C = vars->unk70 = vars->unk60 = vars->unk64 = 0.0f;
        vars->unk74 = 0;
        vars->state = -1;
        object->unk98 = 0;
        func_002A0F48(object);
    }
    return object;
}
