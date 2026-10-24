/* Retained manual C reconstruction; not linked and not matching.
 * Profile: -O2 -G0 -ffunction-sections
 * Local tools/check.py measurements: us: 976 compiled bytes, 0/1 placements, exit 1; us2: 976 compiled bytes, 0/1 placements, exit 1; pal: catalogue absent (exit 1).
 * Retail extent: 1068 bytes. No exact-C credit and no full build performed.
 * Residual: 976 versus 1068 bytes (-92), frame 0x40 versus 0x50. Complete member class scan and four-slot weighted history retained; class 0xD4A is counted unconditionally, unlike 0xD4B. Class-branch sharing, base allocation and history scheduling differ.
 * Reopen: Reopen with measured class-chain block ordering and history-base lifetime evidence. No assembly classification follows from the allocation mismatch.
 * Arrays with unknown total extent remain incomplete. Pointer-offset views do
 * not establish the full sizes or ownership of game records.
 */
/* Counts active members and updates the four-slot weighted activity history. */
typedef unsigned char u8;
#define S16(p,o) (*(short *)((p)+(o)))
#define U16(p,o) (*(unsigned short *)((p)+(o)))
#define I32(p,o) (*(int *)((p)+(o)))
#define F32(p,o) (*(float *)((p)+(o)))
extern short *D_L11_001FC420[];
extern u8 *D_L11_001B359C;
extern u8 D_00189E20[];
extern void func_L11_00445DF8(u8 *, int, float, float);
extern int func_L00_0035F5A0(int, int, int);
extern int func_00282978(short *);
void func_L11_00440360(u8 *object)
{
    u8 *state = *(u8 **)(object + 0x68);
    short *list;
    int active, i, slot, kind;
    float total, weights, energy, motion;
    u8 *member, *detail, *members;
    if (I32(state,0xc0) == 255) return;
    list = D_L11_001FC420[I32(state,0xc0)];
    if (list == 0) return;
    if (object[0x20] == 9 && object[0xbc] == 0) return;
    total=0.0f; active=0;
    members=D_L11_001B359C;
    U16(state,0x200) = 0;
    do {
        member = members + ((*list & 0x7fff) << 8);
        if (member != 0 && member[0x20] != 254 && member[0x20] != 253 && member[0x20] != 1) {
            kind = S16(member,0xaa);
            detail = *(u8 **)(member+0x68);
            if (kind == 0xd98 || kind == 0xdcf || kind == 0xdf4 || kind == 0xdf7 || kind == 0xdf9 || kind == 0xd4b) {
                total += F32(detail,0x20);
                if (F32(detail,0x20) > 0.0f) active++;
            } else if (kind == 0xd37) {
                U16(state,0x200)++;
                total += F32(detail,0x20);
                if (F32(detail,0x20) > 0.0f) active++;
            } else if (kind == 0xd4a || kind == 0xb3a) {
                active++;
                total += F32(detail,0x20);
            }
        }
    } while (*list++ >= 0);
    func_L11_00445DF8(object, I32(state,0x140)-active, F32(state,0x144)-total,
        F32(state,0x148)-(float)I32(D_00189E20,0x24cc));
    if (F32(state,0x148)-(float)I32(D_00189E20,0x24cc) > 0.0f)
        func_L00_0035F5A0(0x17,0,0);
    if (active < I32(state,0x140))
        I32(state,0x50 + S16(state,0x1ec)*16) += I32(state,0x140)-active;
    if (total < F32(state,0x144))
        F32(state,0x54 + S16(state,0x1ec)*16) += F32(state,0x144)-total;
    if ((float)I32(D_00189E20,0x24cc) < F32(state,0x148))
        F32(state,0x58 + S16(state,0x1ec)*16) += F32(state,0x148)-(float)I32(D_00189E20,0x24cc);
    F32(state,0x144) = total;
    I32(state,0x140) = active;
    F32(state,0x148) = (float)I32(D_00189E20,0x24cc);
    weights=0.0f; energy=0.0f; motion=0.0f;
    for (i=4;i>0;i--) {
        float weight = 1.0f / (5.0f-(float)i);
        slot = (S16(state,0x1ec)+i)%4;
        energy += weight*F32(state,0x54+slot*16);
        motion += weight*F32(state,0x58+slot*16);
        weights += weight*(float)I32(state,0x50+slot*16);
    }
    F32(state,0x14c) = energy*0.2f + weights + motion * -2.0f;
    if (func_00282978((short *)(state+0x1ee))) {
        S16(state,0x1ec) = (short)(U16(state,0x1ec)+1)%4;
        I32(state,0x50+S16(state,0x1ec)*16)=0;
        I32(state,0x54+S16(state,0x1ec)*16)=0;
        I32(state,0x58+S16(state,0x1ec)*16)=0;
        S16(state,0x1ee)=600;
    }
}
