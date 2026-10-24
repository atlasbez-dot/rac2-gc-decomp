/* Current nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 10_hrugis_cloud: 872 bytes, expected 868; func_L10_00418D88: 0 of 2 places match (src/levels/shared/L10_00418D88-g8.c).
   us2: 10_hrugis_cloud: 872 bytes, expected 868; func_L10_00418D88: 0 of 2 places match (src/levels/shared/L10_00418D88-g8.c).
   pal: func_L10_00418D88 is in neither catalogue of pal; func_L10_00418D88 is in neither catalogue of pal.
   872 against 868 bytes. Both attack modes and sound-handle maintenance are reconstructed. The raw callback operand precedes the named handler by eight bytes in the primary placement; it remains a scoped ref with secondary identity unqualified. Reopen after qualifying that binding and the remaining state-machine register/control flow.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_00418D88 - 868 bytes, 2 place(s), level 10_hrugis_cloud, retail
   at 0x00418d88. Screened with tools/w10_screen.py: 26 call(s)
   [func_002ED688@00418DB4, func_L00_00367720@00418DFC,
   func_L10_004190F0@00418E0C, func_L05_00379E60@00418E2C,
   func_L05_0037C160@00418E50, func_L05_0037B538@00418E64,
   func_002E59F8@00418EA4, func_002E5CF8@00418EBC,
   func_L05_0037B948@00418ED8, func_L10_004191E8@00418F20,
   func_L05_0037B888@00418F28, func_L05_0037B6D0@00418F38,
   func_00282948@00418F40, func_L10_00419348@00418F48,
   func_L05_0037C160@00418F68, func_L05_0037B538@00418F7C,
   func_L05_0037B948@00418F98, func_002ED688@00418FAC,
   func_00277F48@00418FE4, func_002ED688@00419024,
   func_L10_004191E8@0041904C, func_L05_0037B888@00419054,
   func_L05_0037B6D0@00419064, func_00282948@0041906C,
   func_L10_00419348@00419074, func_002E5DA0@004190B4]; data addresses
   materialised [0x190000, 0x190000, 0x190000, 0x420000, 0x3ca30000,
   0x190000, 0x3da30000, 0x190000, 0x1c0000]; float constants [0x43300000,
   0x43300000, 0x42a00000]; $gp-relative small data: no   saves: -; callee-
   saved registers saved [-]; words plain C cannot emit [-]. Head: addiu
   $sp, $sp, -0x50 ; sd $s2, 0x10($sp) ; sd $s3, 0x18($sp) ; daddu $s2, $a0,
   $zero ; sd $s0, 0x0($sp) ; sd $s1, 0x8($sp). Not matched in this wave:
   the body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

typedef unsigned char u8;
typedef short s16;
typedef int s32;
extern char D_00188660[];
extern u8 *D_L10_001B251C __attribute__((sda));
extern u8 *D_L10_001C3B40[];
/* The registered entry precedes the named handler in the primary placement;
   retain the raw primary callback operand without inventing a function.
   Its secondary-placement identity is not yet qualified. */
extern char ref_L10_00418D88_00[];
extern s32 func_002ED688(u8 *);
extern int func_L00_00367720(void);
extern void func_L10_004190F0(u8 *);
extern void func_L05_00379E60(int, int, int, int);
extern void func_L05_0037C160(u8 *);
extern int func_L05_0037B538(u8 *, int, int, int);
extern void func_002E59F8(s32);
extern int func_002E5CF8(int, int, char *);
extern void func_L05_0037B948(u8 *, int, float);
extern void func_L10_004191E8(void *);
extern int func_L05_0037B888(char *);
extern void func_L05_0037B6D0(char *);
extern int func_00282948(void *);
extern void func_L10_00419348(u8 *);
extern int func_00277F48(void *, int, void *, int, float);
extern int func_002E5DA0(int, int, char *, int);

/* Updates the two attack modes, chooses a live target and maintains its sound. */
void func_L10_00418D88(u8 *self) {
    char *state = *(char **)(self + 0x68);
    char *motion = (char *)func_002ED688(self);
    char *otherMotion;
    u8 *target;
    int handle, i, count;
    switch (self[0x20]) {
    case 0:
        self[0x30] = 255;
        if (!func_L00_00367720()) return;
        func_L10_004190F0(self);
        if (*(int *)(state + 0x264))
            func_L05_00379E60((int)self, (int)ref_L10_00418D88_00, 0, 0);
        break;
    case 1:
        *(float *)(self + 0x2C) = 0.019999999552965164f;
        func_L05_0037C160(self);
        if (func_L05_0037B538(self, 0, 0, 0)) {
            handle = *(int *)(state + 0x26C);
            if (handle != -1 && *(u8 **)(D_00188660 + handle * 0x70 + 0x88) == self &&
                *(u8 *)(D_00188660 + handle * 0x70 + 0x74)) func_002E59F8(handle);
            *(int *)(state + 0x26C) = -1;
            func_002E5CF8(1, 0, (char *)self);
        }
        if (*(int *)(motion + 0x110)) {
            func_L05_0037B948(self, 0, 176.0f);
            if (*(int *)(state + 0x260) != -1) {
                *(int *)(motion + 0x11C) = 1;
                *(u8 **)(motion + 0x120) = D_L10_001B251C + (*(int *)(state + 0x260) << 8);
            }
            if (*(int *)(motion + 0x108) && *(int *)(motion + 0x104)) func_L10_004191E8(self);
            if (func_L05_0037B888((char *)self)) func_L05_0037B6D0((char *)self);
            func_00282948(state + 0x268);
            func_L10_00419348(self);
        }
        break;
    case 2:
        *(float *)(self + 0x2C) = 0.07999999821186066f;
        func_L05_0037C160(self);
        func_L05_0037B538(self, 0, 0, 0);
        if (!*(int *)(motion + 0x110)) break;
        func_L05_0037B948(self, 0, 176.0f);
        target = *(u8 **)(motion + 0x120);
        if (target) {
            otherMotion = (char *)func_002ED688(target);
            if (!*(int *)(otherMotion + 0x110)) *(int *)(motion + 0x120) = 0;
        }
        if (!*(int *)(motion + 0x120)) {
            count = func_00277F48(self + 0x10, 0, self, 0, 80.0f);
            for (i = 0; i < count; i++) {
                target = D_L10_001C3B40[i];
                if (*(s16 *)(target + 0xAA) == 0xCBE) {
                    otherMotion = (char *)func_002ED688(target);
                    if (*(int *)(otherMotion + 0x110)) {
                        *(u8 **)(motion + 0x120) = target;
                        *(int *)(motion + 0x11C) = 0;
                        break;
                    }
                }
            }
        }
        if (*(int *)(motion + 0x104)) func_L10_004191E8(self);
        if (func_L05_0037B888((char *)self)) func_L05_0037B6D0((char *)self);
        func_00282948(state + 0x268);
        func_L10_00419348(self);
        break;
    }
    handle = *(int *)(state + 0x26C);
    if (*(u8 **)(D_00188660 + handle * 0x70 + 0x88) != self ||
        !*(u8 *)(D_00188660 + handle * 0x70 + 0x74))
        *(int *)(state + 0x26C) = func_002E5DA0(3, 6, (char *)self, 0xF93);
}
