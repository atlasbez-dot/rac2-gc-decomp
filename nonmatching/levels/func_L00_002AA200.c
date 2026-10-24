/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G0 -ffunction-sections.
 * Reported final C / retail: 648 / 632 bytes; size equality is not a match.
 * us: 0/27 placements; 648/632 bytes.
 * us2: 0/27 placements; 648/632 bytes.
 * pal: 0/27 placements; 648/632 bytes.
 * Residual: Packed-value/header counter allocation and the 0x80 frame versus retail 0x70 differ. The typed variable packet header ties the byte-view form.
 * Reopening condition: Reopen only after independent source, data-layout, ABI or compiler evidence specifically explains the residual above; then test that single hypothesis. Do not repeat tied source forms or flag sweeps.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Readable manual reconstruction, measured 2026-10-23.
 * Retained profile: -O2 -G0 -ffunction-sections.
 * us: 0 of 27 places match; exit 1.
 * us2: 0 of 27 places match; exit 1.
 * pal: 0 of 27 places match; exit 1.
 * Packed-value/header counter allocation and the 0x80 frame versus retail 0x70 differ. The typed variable packet header ties the byte-view form.
 * 3 bounded source/profile trials; no exact-C credit is claimed.
 * Live helper inputs and consumed return banks were checked against retail and
 * current definitions. Original scalar-return intent remains unqualified for
 * procedural ASM callees whose results this body does not consume.
 * Reopen with independent layout/lifetime, table-extent or scheduling evidence;
 * no source barriers, register pins, invented aliases or padding were used.
 */

typedef unsigned long PackedVector;
typedef struct {
    unsigned short reserved0, reserved2, reserved4, qwc;
    unsigned short baseBytes, scaleCount, scaleBytes, positionCount;
    PackedVector initial;
    PackedVector entries[0];
} PackedTransformPacket;
extern unsigned char *D_0018C0B0;
extern void func_L00_00316F60(unsigned char *);
extern PackedVector func_L00_002EE660(const void *, float);

/* Pack selected scratchpad transforms, retaining only changed scale/position rows. */
void func_L00_002AA200(int *indices, PackedTransformPacket *out, unsigned char *baseline,
                       int padding, unsigned char *object) {
    PackedVector *entry = out->entries;
    PackedVector value, old;
    int *index;
    int count = 1;
    int scales = 0;
    int positions = 0;
    int ordinal;
    int firstBytes, secondCount;
    const PackedVector absent = 0x7FFF000000000000UL;
    const PackedVector mask = 0x0000FFFFFFFFFFFFUL;
    /* The 0x70000000 region is the EE scratchpad, not a level data address. */
    unsigned char *scratch = (unsigned char *)0x70000000;
    if (!object) object = D_0018C0B0;
    func_L00_00316F60(object);
    out->initial = absent;
    index = indices + 1;
    while (*index >= 0) {
        *entry++ = func_L00_002EE660(scratch + (*index << 6), 32768.0f);
        ++index;
        ++count;
    }
    while (padding > 0) {
        *entry++ = absent;
        --padding;
        ++count;
    }
    firstBytes = count * 8;
    index = indices + 1;
    ordinal = 1;
    while (*index >= 0) {
        value = func_L00_002EE660(scratch + (*index << 6) + 0x10, 4096.0f) & mask;
        if (value != 0x0000100010001000UL) {
            *entry = value;
            ++scales;
            ((unsigned short *)entry)[3] = ordinal | 0x8000;
            ++entry;
        }
        ++index;
        ++ordinal;
    }
    secondCount = count + scales;
    index = indices + 1;
    ordinal = 1;
    while (*index >= 0) {
        value = func_L00_002EE660(scratch + (*index << 6) + 0x20, 1.0f) & mask;
        old = func_L00_002EE660(*(unsigned char **)(baseline + 0x18) + ordinal * 16, 1.0f) & mask;
        if (value != old) {
            *entry = value;
            ++positions;
            ((unsigned short *)entry)[3] = ordinal;
            ++entry;
        }
        ++index;
        ++ordinal;
    }
    if ((unsigned int)entry & 15) *entry++ = 0;
    out->positionCount = positions;
    out->scaleCount = scales;
    out->baseBytes = firstBytes;
    out->qwc = (((unsigned char *)entry - 16 - (unsigned char *)out) >> 4);
    out->scaleBytes = secondCount * 8;
    out->reserved0 = 0;
    out->reserved2 = 0;
    out->reserved4 = 0;
}
