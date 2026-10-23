/* Near miss from src/levels/shared/L06_0035EA68.c: 280 bytes, expected 288; 0 of 2 places.
   Kept as a starting point; not linked, not counted.

   The body, the level's list walk and the append are right. What still differs against
   retail (level 06 at 0x0039A2F0):
   - retail keeps the walk's pointer in $a0, the score in $v1 and copies the count into
     $a1 and $a3 before the walk; here the score takes $a0, the pointer $s0 (a saved
     register) and the count stays in $v1, so this body is two instructions short (the
     save and the restore of $s0);
   - retail's first test is a branch likely (bnel), so the increment of the score in its
     delay slot only happens when the field matched; here the compiler emits a plain
     branch and the score's increment lands in the delay slot of the next test, with the
     loop's condition computed twice;
   - retail loads the field at 0xB2 before the field at 0xAA, which the order of the two
     declarations reproduces.

   The level's shot table is a list of 16-byte entries with the count in front of them;
   the call to func_00282AB0 (a different address in every level) is a ref here, and the
   list itself is the function's fifth argument, in $t0. */

typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef int s32;

extern void ref_L06_0039A2F0_00(s32 *, s32, s32);

void func_L06_0039A2F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 *list)
{
    char *shot;
    s32 count;
    s32 limit;
    s32 score;
    s32 tag = a3;
    s16 d;
    s16 fc = *(s16 *)(a2 + 0xB2);
    s16 fa = *(s16 *)(a2 + 0xAA);

    if (a3 == 1)
        d = (s16)(a0 - a2);
    else
        d = (s16)(a0 - *(u16 *)(a2 + 0x68));

    count = list[0];
    score = 0;
    if (count > 0) {
        limit = count;
        shot = (char *)list + 4;
        do {
            if (*(s32 *)shot == d) {
                score++;
                if (*(u16 *)(shot + 8) == a1) {
                    score++;
                    if (*(s16 *)(shot + 0xC) == fc) {
                        score++;
                        if (*(s16 *)(shot + 0xE) == fa) {
                            tag = *(s16 *)(shot + 0xA);
                            if (tag != 0) {
                                ref_L06_0039A2F0_00(shot + 4, a0, a1);
                                return;
                            }
                        }
                    }
                }
            }
            shot += 16;
        } while (score < limit);
    }
    shot = (char *)list + 4 + count * 16;
    list[0] = count + 1;
    *(s32 *)shot = d;
    ref_L06_0039A2F0_00(shot + 4, a0, a1);
    *(s16 *)(shot + 0xE) = fa;
    *(u16 *)(shot + 8) = a1;
    *(s16 *)(shot + 0xA) = tag;
    *(s16 *)(shot + 0xC) = fc;
}
