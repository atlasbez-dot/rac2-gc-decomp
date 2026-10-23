/* func_L00_00410508, 392 bytes, 27 placements.  ABANDON - not attempted past the reading.
 *
 * The record is a long state machine: the frame is 0x50 with $s0-$s2 saved, the object
 * pointer is kept in $s2 and its node in $s1 (`lw $s1,0x68($s2)`).  It calls
 * func_002D4040 first and gives up when the call returns zero (`bnel $v0,$zero`), then
 * stamps the node's +0x28 word with the count and calls the level's func_L00_00410508's
 * helper chain: func_002EE5B0 and func_002EE108 build a 16-byte vector, func_0031A768 and
 * the eight-argument func_L00_003AB9C0 follow, and the tail is the float comparison
 * `c.olt.s` chain that flips the node's +0x20 word.
 *
 * What would unblock it: the prototypes of func_002D4040, func_002EE5B0, func_002EE108,
 * func_002EAC30 and func_L00_003AB9C0, and the source order of the two branches.
 */
#include "include_asm.h"

extern int func_002D4040(char *);

extern void func_002EE5B0(void *, void *, char *);

extern void func_002EE108(void *, void *, void *);

extern char *func_L00_003AB9C0(char *, char *, int, int, float, float, float, float);

extern int func_002D3F30(int, int);

extern void func_00280B90(void *, void *, int);

/* The record stamps the node's words and ends with a float comparison that flips the
   node's +0x20 word; the whole body is one long state machine over the node at +0x68. */
void func_L00_00410508(char *a0, char *a1)
{
    char *node;

    node = *(char **)(a0 + 0x68);
    if (func_002D4040(a0) != 0) {
        func_002EE5B0(0, 0, a0 + 0xC0);
        func_002EE108(0, 0, 0);
        func_L00_003AB9C0(a0, a1, *(int *)node, 0x001B8F20, *(float *)(node + 8),
                          2.0f, 5.0f, 0.6f);
    }
}

INCLUDE_ASM("asm/levels", func_L00_00410508);
