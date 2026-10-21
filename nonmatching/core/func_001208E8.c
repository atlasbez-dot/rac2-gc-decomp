/* Near miss for func_001208E8 (324 bytes, boot 0x001208E8).
   tools/check.py: "boot: 316 bytes, expected 324" - the prologue and the
   code up to 0x00120964 are byte-identical to retail; four instructions
   are missing and two differ (see below).

   The function is libgcc's exception handler search (gcc/libgcc2.c of the
   public gnu-ee-binutils-gcc-1.1 archive the qualified compiler is built
   from). The table is a two-word header followed by 16-byte entries of
   {start, end, handler, flags}; an entry whose start is -1 ends the list.
   The search walks the entries whose [start, end) range holds the key and
   calls the callback of the entries that have one; the callback is
   reached through the first word of the third argument.

   The ABI here is the SDK's: five argument registers, $a0-$a3 and $t0
   (the SDK's EE-GCC passes the fifth argument in $t0, not on the stack).

   What still differs from retail:
     - the entry pointer is computed into $v1 and copied to $s0, retail
       computes it into $a1 (and loads through it) before the copy;
     - retail has a nop at 0x00120994 that this C does not produce;
     - retail's loop back edge fills the delay slot of the branch with the
       `sltu` of the next iteration, this C copies the loaded word there
       instead (one extra `daddu $v1, $v0, $zero`);
     - retail's callback path jumps to the shared tail (`b 0x001209E8`
       with the store to *arg4 in its delay slot) and so assigns the
       handler twice; this C falls through and assigns it once, which is
       two instructions short.

   What would unblock it: the source's shape for the two assignments
   (the retail's duplicated one) and for the entry pointer (a temporary
   that the loop variable is copied from). */

#include "common.h"
#include "structs.h"

typedef struct {
    unsigned int start;
    unsigned int end;
    void *handler;
    unsigned int flags;
} eh_search_entry;

typedef struct {
    unsigned int header[2];
    eh_search_entry entries[1];
} eh_search_table;

typedef struct {
    void *(*fn)(void *, unsigned int, void *);
} eh_search_callback;

void *func_001208E8(void *arg0, void *arg1, void *arg2, int arg3, int *arg4) {
    eh_search_table *table = (eh_search_table *)arg1;
    eh_search_callback *cb = (eh_search_callback *)arg2;
    eh_search_entry *e;
    void *result = 0;
    unsigned int key = (unsigned int)arg0;
    int index;

    *arg4 = 1;
    if (table != 0) {
        eh_search_entry *base;
        eh_search_entry *first;
        index = 0;
        base = table->entries;
        if (arg3) {
            index = (int)((char *)arg0 - (char *)base) >> 4;
            key = ((eh_search_entry *)arg0)->end - 1;
            if (base[index].start != 0xFFFFFFFF) {
                index++;
            }
        } else {
            key = key - 1;
        }
        first = base + index;
        if (base[index].start != 0xFFFFFFFF) {
            for (e = first; e->start != 0xFFFFFFFF; e++) {
                if (key < e->start) {
                    continue;
                }
                if (key >= e->end) {
                    continue;
                }
                if (e->flags != 0) {
                    if (cb->fn == 0) {
                        continue;
                    }
                    if (cb->fn(cb, e->flags, table) == 0) {
                        continue;
                    }
                    if (result == 0) {
                        result = e->handler;
                    }
                    *arg4 = 0;
                }
                if (result == 0) {
                    result = e->handler;
                }
            }
        }
    }
    return result;
}
