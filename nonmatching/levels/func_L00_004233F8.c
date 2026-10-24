/* Retained manual reconstruction, 2026-10-24.
 * Profile: -O2 -G8 -ffunction-sections.
 * Final measurements: us: 0/27 placements, exit1, 992 compiled bytes; us2:
 * 0/27 placements, exit1, 992 compiled bytes; pal: catalogue absent
 * (exit1).
 * Remaining: All camera, movement, orientation, plane/tracker
 * initialization, four genuine 16-byte copies and final projection/distance
 * tests are retained. The large global parent remains an incomplete byte
 * array, not an undersized SDA alias. Final -G8 code is 992/972 bytes with
 * a 0x60 rather than 0x70 frame and different allocation/storage
 * addressing. PAL catalogue absence is not a successful check.
 * Reopen with: Independent full-state field/storage declarations and local
 * lifetime evidence that reproduces the retail saved-register set and mixed
 * absolute/GP accesses.
 * No byte-match or linked-build credit is claimed.
 */
/* Initialize the owner's camera and movement state. Offsets below describe
 * individual subobjects; no complete owner or private-state size is assumed. */
typedef unsigned int CameraQuad __attribute__((mode(TI)));
extern CameraQuad D_L00_00189EA0;
extern CameraQuad D_L00_0018A0E0;
extern int D_L00_001B1580, D_L00_001B1584;
extern unsigned char D_L00_00189E20[];
extern unsigned short D_L00_001B1514, D_L00_001B1518;
extern float D_L00_001B14A0, D_L00_001B14A4;
extern float D_L00_001B1510, D_L00_001B14D4, D_L00_001B14D8, D_L00_001B14DC;
extern float D_L00_001A8900, D_L00_001A8904;
extern int D_L00_001B1854;
extern unsigned char *D_L00_001B8E14;

extern void func_00282C88(void *);
extern void func_L00_00423290(unsigned char *);
extern float func_00283CE0(int);
extern void func_L00_00420638(char *);
extern void func_L00_00423038(int);
extern void func_00282CF0(void *, void *, void *);
extern float func_00282DB0(void *, void *);
extern void func_00282D30(void *, void *, float);
extern float func_00282DF0(void *);
#define CF(p, o) (*(float *)((p) + (o)))
#define CI(p, o) (*(int *)((p) + (o)))
#define CS(p, o) (*(short *)((p) + (o)))

void func_L00_004233F8(unsigned char *owner)
{
    CameraQuad projected, difference;
    unsigned char *base = *(unsigned char **)(owner + 0x70);
    unsigned char *camera = base + 0x60;
    unsigned char *movement, *root, *orientation, *rotation, *plane, *tracker;
    float distance;
    D_L00_001B1580 = 0;
    D_L00_001B1584 = 0;
    *(CameraQuad *)camera = D_L00_00189EA0;
    CF(camera, 0xB0) = 1.5f;
    camera[0xC4] = 0;
    camera[0xD6] = 0;
    CI(camera, 0xC0) = CI(D_L00_00189E20, 0x2290);
    CS(camera, 0xEC) = D_L00_001B1514;
    CF(camera, 0xDC) = D_L00_001B14A0;
    CF(camera, 0xE4) = D_L00_001B14A4;
    CF(camera, 0xE0) = 0.2f;
    CF(camera, 0xE8) = 0.2f;
    CF(camera, 0xB8) = 0.005f;
    CS(camera, 0xC6) = 0;
    CS(camera, 0xD8) = 0;
    CS(camera, 0xEE) = 0;
    CI(camera, 0xB4) = 0;
    CS(camera, 0xDA) = 0;
    CI(camera, 0xBC) = 0;
    CI(camera, 0xF0) = 0;
    CI(camera, 0xF4) = 0;
    CI(camera, 0xF8) = 0;
    CI(camera, 0xFC) = 0;
    movement = *(unsigned char **)(owner + 0x70) + 0x160;
    CF(movement, 0x30) = 2.0f;
    CF(movement, 0x2C) = 4.64f;
    CI(movement, 0x34) = 0;
    CI(movement, 0x38) = 0;
    CI(movement, 0x28) = 0;
    CI(movement, 0x20) = 0;
    CI(movement, 0x24) = 0;
    CS(movement, 0x3C) = 0;
    CS(movement, 0x3E) = 0;
    CF(movement, 0x54) = 0.003f;
    CF(movement, 0x58) = 4.64f;
    CF(movement, 0x48) = 0.003f;
    CI(movement, 0x44) = 0;
    CI(movement, 0x50) = 0;
    root = *(unsigned char **)(owner + 0x70);
    CS(root, 0x10) = 1;
    CS(root, 0x12) = 0;
    CS(root, 0x14) = 0;
    CS(root, 0x16) = 0;
    D_L00_001A8900 = 0.85f;
    orientation = *(unsigned char **)(owner + 0x70) + 0x20;
    CS(orientation, 0) = 0;
    CF(orientation, 0x20) = 0.2f;
    CF(orientation, 0x38) = 0.0002908882452175021f;
    CF(orientation, 0x34) = 0.0002908882452175021f;
    CF(orientation, 0x1C) = 0.005f;
    CI(orientation, 0x10) = 0;
    CI(orientation, 0xC) = 0;
    CS(orientation, 2) = 0;
    CI(orientation, 0x14) = 0;
    CI(orientation, 0x18) = 0;
    CI(orientation, 0x28) = 0;
    CI(orientation, 0x2C) = 0;
    CI(orientation, 0x30) = 0;
    rotation = *(unsigned char **)(owner + 0x70) + 0x1C0;
    CI(rotation, 0) = 0;
    CF(rotation, 0x14) = D_L00_001A8904;
    CI(rotation, 8) = 0;
    CI(rotation, 4) = 0;
    CI(rotation, 0xC) = 0;
    CI(rotation, 0x10) = 0;
    CF(rotation, 0x18) = 0.523598849773407f;
    CI(rotation, 0x24) = 0;
    CI(rotation, 0x1C) = 0;
    CI(rotation, 0x20) = 0;
    plane = *(unsigned char **)(owner + 0x70) + 0x240;
    CI(plane, 0) = 0;
    CI(plane, 0x10) = 0;
    CS(plane, 4) = 0;
    CS(plane, 6) = 0;
    CF(plane, 0xC) = D_L00_001B1510;
    CF(plane, 8) = CF(movement, 0x2C);
    tracker = *(unsigned char **)(owner + 0x70) + 0x1F0;
    CI(tracker, 0x30) = 0;
    CS(tracker, 0x3A) = 0;
    CS(tracker, 0x36) = 0;
    CS(tracker, 0x38) = 0;
    CS(tracker, 0x4C) = 0;
    CS(tracker, 0x4E) = 0;
    CI(tracker, 0x48) = D_L00_001B1854;
    CS(tracker, 0x34) = 2000;
    CF(tracker, 0x44) = D_L00_001B14D4;
    CF(tracker, 0x3C) = D_L00_001B14DC;
    CF(tracker, 0x40) = D_L00_001B14D8;
    func_00282C88(tracker + 0x10);
    if (owner[0x7D] == 2) {
        func_L00_00423290(owner);
        *(CameraQuad *)(owner + 0x40) = *(CameraQuad *)owner;
        if (CS(D_L00_001B8E14, 0x86) == 7 && CS(D_L00_00189E20, 0x34C) == 0)
            CS(orientation, 0) = 0;
        else {
            CS(orientation, 0) = D_L00_001B1518;
            CF(orientation, 0x24) = 1.0f / func_00283CE0((short)D_L00_001B1518);
        }
    } else {
        func_L00_00420638((char *)owner);
    }
    func_L00_00423038(1);
    func_00282CF0(movement, owner + 0x30, camera + 0x50);
    *(CameraQuad *)(movement + 0x10) = *(CameraQuad *)movement;
    *(CameraQuad *)root = *(CameraQuad *)(owner + 0x30);
    *(CameraQuad *)(tracker + 0x20) = *(CameraQuad *)(owner + 0x30);
    distance = func_00282DB0(movement, &D_L00_0018A0E0);
    func_00282D30(&projected, &D_L00_0018A0E0, distance);
    func_00282CF0(&difference, movement, &projected);
    distance = CF(movement, 0x2C) - func_00282DF0(&difference);
    CF(tracker, 0x30) = distance;
    if (distance < -0.1f) CS(tracker, 0x3A) = 1;
    CF(orientation, 8) = CF(movement, 0x30);
    CF(orientation, 4) = CF(camera, 0xB0);
    CS(owner, 0x7E) = 0;
}
#undef CF
#undef CI
#undef CS
