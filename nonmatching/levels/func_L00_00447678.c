/* func_L00_00447678, 48 bytes, 27 placements.  ABANDON - instruction-scheduling wall.
   A one-line thunk: it loads the resident pointer word at 0x1B272C, adds 0xD9090, and calls
   func_446708 with it
   The function returns the constant 1 after the call..
   Candidate is the same size (48 bytes) and three words differ: the four instructions of
   arithmetic are exact, including the `lui 0xD; ori 0x9090` form of the constant, but retail
   fuses the load into the high address register at +0x4 (`lui $v0,%hi` then `lw $v0,%lo($v0)`)
   while this cc1 schedules the `lui` of the constant between them and loads into $v1
   (`lw $v1,%lo($v0)`), so +0x4 and +0x8 are swapped and the `addu` differs at +0x1c. Six
   spellings were measured on the func_L00_004450E8 shape and all six give the same three words:
   the scalar symbol with a signed constant, the same with `u`, the dereferenced `*(int *)&sym`,
   a local pointer, the constant first, and a named local for the load.
   Unblocking: a spelling that makes cc1 fuse the load into the address register. */

#include "include_asm.h"

extern int D_L00_001B272C;
extern void func_446708(int a0);

int func_L00_00447678(void)
{
    func_446708(D_L00_001B272C + 0xD9090)
    return 1;
}
