/* 25 October 2026 approved-helper experiment; original C below is preserved.
 * Trial profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier
 * Trial checks: us: 0/28; us2: 0/28; pal: 0/28.
 * 668/688 bytes, frame 0xA0. The real snapshot qcopy is retained, but loop address/induction and contact/damage setup allocation differ. A typed local table base tied; mno-split-addresses regressed to 664 bytes and was reverted.
 * Reopen: New table-base/contact-field or induction evidence. The old reconstruction explicitly lacked a complete semantic qualification; do not infer native behavior from size or helper use.
 * No exact, linked or native-runtime credit is claimed.
 */

/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 664 / 688 bytes; size equality is not a match.
 * us: 0/28 placements; 664/688 bytes.
 * us2: 0/28 placements; 664/688 bytes.
 * pal: 0/28 placements; 664/688 bytes.
 * Residual: Loop/copy allocation; true contact prefix through +0x24 rounds to 48 aligned bytes.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 003054E8: 664 bytes versus retail 688; frame 0xA0.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * Contact layout includes the secondary damage word at +0x24; allocation and loop/copy scheduling remain different.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
extern void func_00282CF0(void *, void *, void *);
extern void func_00282CC0(void *, void *, void *);
extern int func_00277258(void *, int, void *, float);
extern char ref_00305798_00[];

typedef struct {
    ParticleVector position, velocity;
    float timer;
    char *owner;
    u8 reserved28[8];
} ParticleTrail;
typedef struct {
    Quad16 normal;
    int owner, flags;
    u8 kind, source;
    unsigned short objectClass;
    float damage;
    int mode;
    float secondaryDamage;
} HitContactView;
typedef struct { u8 prefix[0x70]; float damage; u8 remainder[0xe0 - 0x74]; } ParticleDamageDescriptor;
extern char *ref_003054E8_00;
extern ParticleVector ref_003054E8_01;
extern ParticleDamageDescriptor ref_003054E8_02[];
extern u8 D_00139588[];
extern char *D_0018C0B0 __attribute__((sda));
extern int func_002829D8(float *);
extern int func_002761F8(void *, void *, int, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002A8C00(char *, int, int, float, Quad16 *);
extern void func_002A8E20(char *, void *);
extern void func_00334160(char *, int, int);
extern void func_00306680(void *, int);

/* Advance owned particle trails and turn a collision into a contact and impact. */
void func_003054E8(char *object)
{
    char *state = *(char **)(object+0x68);
    ParticleVector previous, normal;
    HitContactView contact;
    ParticleTrail *trail;
    char *hit;
    int index, effect;
    for (index=0; index<100; ++index) {
        trail=(ParticleTrail *)(ref_00305798_00+index*0x30);
        if (trail->owner != object) continue;
        if (func_002829D8(&trail->timer) || trail->position.f[0]<2.0f || trail->position.f[0]>1021.0f ||
            trail->position.f[1]<2.0f || trail->position.f[1]>1021.0f ||
            trail->position.f[2]<2.0f || trail->position.f[2]>1021.0f) {
            trail->owner=0;
            --*(int *)(state+0x64);
            continue;
        }
        previous.word=trail->position.word;
        func_00282CC0(&trail->position,&trail->position,&trail->velocity);
        if (!func_002761F8(&previous,&trail->position,0,object,0)) continue;
        hit=ref_003054E8_00;
        if (!hit) {
            trail->owner=0;
            --*(int *)(state+0x64);
            func_00306680(&ref_003054E8_01,3);
        } else {
            if ((!( *(unsigned short *)(hit+0x34)&0x1000) && *(short *)(*(char **)(hit+0x24)+0x46)!=5) ||
                hit==D_0018C0B0 || *(short *)(hit+0xaa)==0x1366) {
                trail->owner=0;
                effect=3;
            } else {
                func_00282F20(&normal,&trail->velocity,1.0f);
                func_002A8C00((char *)&contact,(int)object,0x210000,
                    ref_003054E8_02[D_00139588[9]].damage,(Quad16 *)&normal);
                contact.objectClass=*(unsigned short *)(object+0xaa);
                contact.source=3; contact.kind=5;
                func_002A8E20(hit,&contact);
                func_00334160(hit,0x29,*(int *)(object+0xb8));
                trail->owner=0; effect=6;
            }
            --*(int *)(state+0x64);
            func_00306680(&ref_003054E8_01,effect);
        }
    }
}
