/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G32 -ffunction-sections -Wa,-G32 -frac2-qcopy -frac2-qcopy-barrier.
 * Reported final C / retail: 992 / 984 bytes; size equality is not a match.
 * us: 0/28 placements; 992/984 bytes.
 * us2: 0/28 placements; 992/984 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Switch/address/allocation; truthful 28-byte palette, full signed64 input and full-word kind narrowed at actual store.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Nonmatching manual reconstruction, 2026-10-23.
 * 00302470: 992 bytes versus retail 984; frame 0xA0.
 * Profile: -O2 -G32 -ffunction-sections -Wa,-G32 -frac2-qcopy -frac2-qcopy-barrier.
 * All carrying US/US2/PAL checks returned zero matches and exit 1;
 * catalogue absence is recorded separately and never counted as success.
 * The seven-float palette is 28 bytes. The signed64-bit denomination, full-word kind input and pointer result are preserved. Switch layout, addressing and allocation still differ.
 * Reopen only with new measured source/type/scheduling evidence. No artificial
 * barriers, register pins, generated decompiler C or omitted behavior were used.
 */

typedef unsigned char u8;
typedef unsigned int u32;
typedef int ParticleWord __attribute__((mode(TI)));
typedef union { ParticleWord word; float f[4]; } ParticleVector;
extern float ref_00302470_00[7] __attribute__((sda));
extern int ref_00302470_01 __attribute__((sda));
extern ParticleVector ref_00302470_02 __attribute__((nosda));
extern int D_001A7A14 __attribute__((nosda));
extern char *D_0018C0B0 __attribute__((nosda));
extern float func_00282E48(void *, void *);
extern char *func_0029EFD0(int);
extern void func_002833F0(void *, void *);
extern void func_002AEC18(void *, int);
extern void func_002A04B8(void *, u32 *, u32 *, u32 *);
extern void func_002A0468(unsigned long long *, unsigned long long,
    unsigned long long, unsigned long long, unsigned long long);
extern void func_002A0488(void *, u32, u32, u32);
extern int func_002A77E0(int);
extern float func_002A7940(void);
extern float func_002A7878(float, float);
extern void func_00282CF0(void *, void *, void *);
extern void func_00282DD8(void *, void *, void *);
extern void func_00282F20(void *, void *, float);
extern void func_002AB668(void *, int, float);
extern int func_003022A0(char *, char *, float, float);
extern void func_002A0F48(void *);

/* Allocate the denomination near the camera and initialize its pickup motion. */
char *func_00302470(char *source, void *position, void *velocity, u32 flags, long value, int kind)
{
    char *object, *state, *parent, *sourcePosition;
    ParticleVector difference, crossed;
    u32 red, green, blue;
    float scale, angle;
    if (func_00282E48(position,&ref_00302470_02)>=64.0f) {
        D_001A7A14=(u32)D_001A7A14+(unsigned long)value;
        return 0;
    }
    switch (value) {
    case 5: object=func_0029EFD0(14); scale=ref_00302470_00[1]; break;
    case 20: object=func_0029EFD0(15); scale=ref_00302470_00[2]; break;
    case 50: object=func_0029EFD0(16); scale=ref_00302470_00[3]; break;
    case 100: object=func_0029EFD0(17); scale=ref_00302470_00[4]; break;
    case 500: object=func_0029EFD0(18); scale=ref_00302470_00[5]; break;
    case 1000: object=func_0029EFD0(19); scale=ref_00302470_00[6]; break;
    default: object=func_0029EFD0(13); scale=ref_00302470_00[0]; break;
    }
    sourcePosition=(char *)((u32)source+0x10);
    if (!object) return 0;
    state=*(char **)(object+0x68);
    state[0x40]=(u8)kind;
    parent=source;
    if (parent) while (*(char **)(parent+0xb8)) parent=*(char **)(parent+0xb8);
    *(unsigned short *)(object+0x34)|=0x100;
    object[0x63]=0x14; object[0x20]=1; object[0x31]=1;
    object[0x30]=0x40; *(short *)(object+0x32)=0x40;
    *(char **)(object+0xb8)=parent;
    *(float *)(object+0x2c)=*(float *)(*(char **)(object+0x24)+0x24)*scale;
    func_002833F0(object+0xc0,object+0xf0);
    func_002AEC18(object,ref_00302470_01);
    func_002A04B8(object,&red,&green,&blue);
    func_002A0468((unsigned long long *)object,0,13,0,0);
    func_002A0488(object,red,green,blue);
    *(ParticleWord *)(object+0x10)=*(ParticleWord *)position;
    *(ParticleWord *)(state+0x20)=*(ParticleWord *)velocity;
    if (func_002A77E0(2)) state[0x55]|=1;
    *(float *)(state+0x50)=func_002A7940();
    *(float *)(state+0x58)=func_002A7940();
    *(float *)(state+0x68)=*(float *)(object+0x18);
    angle=func_002A7878(0.0f,720.0f);
    func_00282CF0(&difference,sourcePosition,object+0x10);
    func_00282DD8(&crossed,state+0x20,&difference);
    func_00282F20(state+0x30,&crossed,1.0f);
    func_002AB668(state+0x30,(int)(state+0x30),angle*0.00029088825f);
    if (flags&2) {
        angle=0.0f;
        if (flags&0x10) angle=func_002A7878(-30.0f,30.0f)*0.017453294f;
        func_003022A0(object,D_0018C0B0,angle,0.0f);
    }
    func_002A0F48(object);
    return object;
}
