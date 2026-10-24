/* Current nonmatching reconstruction; game compiler, -O2 -G0 -ffunction-sections.
   us: 10_hrugis_cloud: 144 bytes, expected 148; func_L10_0037D200: 0 of 2 places match (src/levels/shared/L10_0037D200.c).
   us2: 10_hrugis_cloud: 144 bytes, expected 148; func_L10_0037D200: 0 of 2 places match (src/levels/shared/L10_0037D200.c).
   pal: 10_hrugis_cloud: 144 bytes, expected 148; func_L10_0037D200: 0 of 2 places match (src/levels/shared/L10_0037D200.c).
   144 against 148 bytes. This reconstruction corrects the historical draft: the float pointer is the first field of the data block at +0x68, requiring two pointer loads before the float. A promoted halfword and reversed pointer addition did not recover the retail register pair and branch schedule. Reopen with a natural list-iterator layout.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_0037D200, 148 bytes, 2 places.  ABANDON - the loop test idiom.
   Read in full and the logic is measured: `p = D_001FB1E0[a0[0x21]]`, then a walk over the
   halfword list it points at, counting the entries whose record at
   `D_001B251C + ((h & 0x7FFF) << 8)` has bit 0x20 in its +0x34 halfword and a positive
   float at `*(float **)(record + 0x68)`; the list ends at the first halfword with bit 15
   set, and the count is the answer.
   The candidate is 140 bytes against 148: retail keeps the loaded halfword in a SECOND
   register ($a1 = the entry, $v1 = the index value) and tests it with `sll $v0,$a1,16;
   bgez`, re-materialising that shift in the annulled slot of the inner beql; this cc1
   instead reloads the halfword (`lh`) for the test and emits `bgezl` with the load in the
   slot, two words shorter. A named halfword variable tested as `(short)h >= 0` changed
   nothing (both spellings measured, 140 each).
   What would unblock it: the register pair / branch-likely form for the terminator test. */

#include "include_asm.h"

typedef unsigned char u8;
extern unsigned short *D_L10_001FB1E0[];
extern char *D_L10_001B251C;

/* Counts active members of the object's group whose health pointer is positive. */
int func_L10_0037D200(u8 *self) {
    unsigned short *ids = D_L10_001FB1E0[self[0x21]];
    unsigned int entry;
    char *object;
    float *health;
    int count = 0;
    if (!ids) return 0;
    do {
        entry = *ids;
        object = ((entry & 0x7FFF) << 8) + D_L10_001B251C;
        if (*(unsigned short *)(object + 0x34) & 0x20) {
            health = **(float ***)(object + 0x68);
            if (health && *health > 0.0f) count++;
        }
        ids++;
    } while ((short)entry >= 0);
    return count;
}
