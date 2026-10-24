/* 2026-10-23 bounded reconstruction, not linked.
 * Profile: -O2 -G0 -ffunction-sections -frac2-qcopy -frac2-qcopy-barrier.
 * us: 0 of 27 places match (src/levels/shared/L00_003F5238-qcopy.c); us2: 0 of 27 places match (src/levels/shared/L00_003F5238-qcopy.c); pal: func_L00_003F5238 is in neither catalogue of pal.
 * 308/340 bytes; conditional local copies fold offsets and the global result block uses different addressing. Tried explicit request layout and typed tuning fields. Reopen with independently measured local-copy lowering and global structure layout.
 * Historical note below is retained; its no-C-attempt statement predates this draft.
 */
/* from src/levels/shared/L00_003EE100.c: not written this wave. Retail 340 bytes, 27 place(s), first word at L00:003f5238.
 * Rule: MMI/LQ/SQ (op 0x1e).
 * No C attempt was made (wave-5 tour-2 discard rule).
 * Retail opens with:
 *   0x003f5238  lui         $v0, 0x14
 *   0x003f523c  addiu       $sp, $sp, -0x70
 *   0x003f5240  lbu         $v1, -0x6A81($v0)
 *   0x003f5244  addiu       $a3, $zero, 0xE0
 *   0x003f5248  sd          $s0, 0x40($sp)
 *   0x003f524c  lui         $a2, 0x26
 * Kept as data for the maintainers. */

#include "common.h"
typedef int TI128 __attribute__((mode(TI)));
typedef struct {
    TI128 direction;
    char *owner;
    int flags;
    unsigned char enabled,kind;
    unsigned short id;
    float scale;
    int active;
    char pad[12];
} CollisionRequest5238;
extern unsigned char D_0013957F;
typedef struct { char prefix[0x50]; float speed; char gap[0x1c]; float distance; char rest[0x6c]; } Tuning;
extern Tuning D_L00_00262570[];
extern char *D_0018C0B0;
extern char D_L00_001BF200[];
extern void func_00282F20(void *,void *,float);
extern int func_002761F8(char *,void *,int,char *,void *);
extern void func_L00_003F5390(char *,char *);
extern int func_L00_0031BE88(char *);
extern void func_00334160(char *,int,int);
int func_L00_003F5238(char *object,char *source)
{
    CollisionRequest5238 request;
    TI128 position;
    char *state = *(char **)(object + 0x68);
    request.flags = 0x10000;
    request.owner = object;
    request.active = 1;
    request.scale = D_L00_00262570[D_0013957F].distance;
    request.direction = *(TI128 *)state;
    func_00282F20(&request.direction,&request.direction,1.0f);
    request.id = *(unsigned short *)(object + 0xaa);
    *(float *)((char *)&request.direction + 12) = 5627.9248f;
    request.enabled = 1;
    request.kind = 1;
    if (*(int *)(state + 0x28) == 1) position = *(TI128 *)(state + 0x40);
    else position = *(TI128 *)(object + 0x10);
    if (func_002761F8(source,&position,0,D_0018C0B0,&request) != 0) {
        func_L00_003F5390(object,D_L00_001BF200 + 0x20);
        if (*(char **)(D_L00_001BF200 + 0x18) == 0) return 1;
        if (func_L00_0031BE88(*(char **)(D_L00_001BF200 + 0x18)) != 0) return 1;
        if (*(char **)(D_L00_001BF200 + 0x18) != 0)
            func_00334160(*(char **)(D_L00_001BF200 + 0x18),0x42,*(int *)(object + 0xb8));
    }
    return 0;
}
