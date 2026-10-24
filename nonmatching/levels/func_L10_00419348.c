/* Current nonmatching reconstruction; game compiler, -O2 -G16 -Wa,-G16 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier -frac2-zero-ti-por.
   us: 10_hrugis_cloud: instruction at +0x10 differs; func_L10_00419348: 0 of 2 places match (src/levels/shared/L10_00419348-particles.c).
   us2: 10_hrugis_cloud: instruction at +0x10 differs; func_L10_00419348: 0 of 2 places match (src/levels/shared/L10_00419348-particles.c).
   pal: func_L10_00419348 is in neither catalogue of pal; func_L10_00419348 is in neither catalogue of pal.
   Same 560-byte extent; early zero-store and saved-FPU-register scheduling differs from +0x10. Uses truthful 16-byte style records with G16/WaG16 and the qualified zero-por/copy profiles. Reopen with a source expression tree for the two initial zero vectors and shared constants.
   Historical screening comments below predate this measured C reconstruction. */
/* MMI (SPECIAL2) instruction: no C spelling. 560 bytes, level
   10_hrugis_cloud. Retail at 0x00419348 carries the SPECIAL2 words
   0x700014A9, 0x700014A9 (+0x0004, +0x008C) - opcode 0x1C, which rabbitizer
   prints as `INVALID`; it is the MMI family (pcpyld and its relatives) the
   sixth wave recorded and that no C spelling reaches. This cc1 emits
   `lq`/`sq` for a `mode(TI)` local and `ldl`/`ldr`/`sdl`/`sdr` for a struct
   assignment, never the packed copy. ASM_FUNC candidate, as for the rest of
   the family. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef float f32;
typedef int Quad __attribute__((mode(TI)));
typedef struct ParticleStyle {
    u32 color;
    u8 parameters[8];
    u16 frameCount;
    u16 reserved;
} ParticleStyle;
extern ParticleStyle D_L10_001B0FB0 __attribute__((sda));
extern ParticleStyle D_L10_001B0FC0 __attribute__((sda));
extern ParticleStyle D_L10_001B0FD0 __attribute__((sda));
extern void func_00283098(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_002ACB48(float *, float);
extern float func_002A7878(float, float);
extern void *func_L00_0033C0D0(void *, void *, void *, void *, int);

/* Emits three fragments from the transformed exhaust point. */
void func_L10_00419348(u8 *self) {
    f32 offset[4];
    f32 velocity[4];
    f32 point[4];
    f32 first[4];
    f32 second[4];
    f32 third[4];
    f32 alternate[4];
    *(Quad *)offset = 0;
    *(Quad *)velocity = 0;
    offset[0] = -0.6000000238418579f;
    offset[2] = 0.25999999046325684f;
    offset[3] = 1.0f;
    if (self[0x20] == 1) {
        *(Quad *)alternate = 0;
        alternate[0] = -0.15000000596046448f;
        alternate[2] = 0.05999999865889549f;
        alternate[3] = 1.0f;
        *(Quad *)offset = *(Quad *)alternate;
    }
    func_00283098(point, offset, self + 0xC0);
    func_00282CC0(point, point, self + 0x10);
    point[3] = 0;
    *(Quad *)first = *(Quad *)point;
    *(Quad *)second = *(Quad *)point;
    *(Quad *)third = *(Quad *)point;
    func_002ACB48(point, 0.1f);
    func_002ACB48(first, 0.1f);
    func_002ACB48(second, 0.1f);
    func_002ACB48(third, 0.1f);
    velocity[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.5f;
    func_L00_0033C0D0(self, first, velocity, &D_L10_001B0FB0, 1);
    velocity[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.5f;
    func_L00_0033C0D0(self, second, velocity, &D_L10_001B0FC0, 1);
    velocity[0] = -(func_002A7878(30.0f, 40.0f) * 0.01666666753590107f) * 0.5f;
    func_L00_0033C0D0(self, third, velocity, &D_L10_001B0FD0, 1);
}
