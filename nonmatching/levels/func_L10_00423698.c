/* Current nonmatching reconstruction; game compiler, -O2 -G8 -ffunction-sections.
   us: 10_hrugis_cloud: instruction at +0x28 differs; func_L10_00423698: 0 of 2 places match (src/levels/shared/L10_00423698-g8.c).
   us2: func_L10_00423698 is in neither catalogue of us2; func_L10_00423698 is in neither catalogue of us2.
   pal: func_L10_00423698 is in neither catalogue of pal; func_L10_00423698 is in neither catalogue of pal.
   Same 228-byte extent; constant/store scheduling differs from +0x28. Moving base construction after the calls fixed the initial address lifetime, but swapping initialization stores tied. Disabling scheduling did not recover the sequence. Reopen with a verified reset-state layout/order.
   Historical screening comments below predate this measured C reconstruction. */
/* func_L10_00423698 - 228 bytes, 2 place(s), level 10_hrugis_cloud, retail
   at 0x00423698. Screened with tools/w10_screen.py: 9 call(s)
   [func_L05_0037B210@004236A4, func_L05_00379F18@004236AC,
   func_002ED8A0@004236E4, func_L05_00379F28@0042371C,
   func_L05_0037D6E8@00423724, func_L05_00379F68@0042372C,
   func_L05_00445A98@00423734, func_0029F338@00423748,
   func_0029F338@00423760]; data addresses materialised [0x220000,
   0x2a0000]; float constants [0x41000000]; $gp-relative small data: yes
   saves: -; callee-saved registers saved [-]; words plain C cannot emit
   [-]. Head: addiu $sp, $sp, -0x10 ; sd $s0, 0x0($sp) ; sd $ra, 0x8($sp) ;
   jal func_37CFD8 ; lui $s0, 0x22 ; jal func_37BD00. Not matched in this
   wave: the body is straight-line code whose register allocation and the
   materialisation of its constant addresses have to be reproduced word for
   word. What would unblock it: the exact source expression tree, so this
   cc1 picks the same registers in the same order. */

typedef unsigned char u8;
typedef struct GornConfig { int words[10]; } GornConfig;
extern char D_L10_00221CD0[];
extern GornConfig D_L10_002A3C70[];
extern int D_L10_001B13A0 __attribute__((sda));
extern int D_L10_001B13A4 __attribute__((sda));
extern char *D_L10_001B13F0 __attribute__((sda));
extern void *D_L10_001B1400 __attribute__((sda));
extern void *D_L10_001B1404 __attribute__((sda));
extern int D_L10_001B1438 __attribute__((sda));
extern int D_L10_001B1440 __attribute__((sda));
extern void func_L05_0037B210(void);
extern void func_L05_00379F18(int);
extern int func_002ED8A0(int);
extern void func_L05_00379F28(int);
extern int func_L05_00442860(void);
extern void func_L05_0037D6E8(void);
extern void func_L05_00379F68(void);
extern void func_L05_00445A98(void);
extern void func_0029F338(void *);

/* Starts the next mission phase with the same shared object cleanup. */
void func_L10_00423698(void) {
    char *state;
    int i;
    func_L05_0037B210();
    func_L05_00379F18(1);
    state = D_L10_00221CD0;
    D_L10_001B13A0 = -2;
    *(int *)(state + 0x28) = 100;
    *(int *)(state + 0x2C) = 1;
    *(int *)(state + 0x10) = 0;
    *(int *)(state + 0xC) = 0;
    D_L10_001B1438 = 1;
    D_L10_001B13A4 = 0;
    *(int *)(state + 0x14) = 0;
    i = func_002ED8A0(6);
    D_L10_001B1440 = 0;
    *(float *)(state + 0x30) = 8.0f;
    D_L10_002A3C70[i].words[5] = D_L10_002A3C70[i].words[4];
    func_L05_00379F28(0);
    func_L05_0037D6E8();
    func_L05_00379F68();
    func_L05_00445A98();
    if (D_L10_001B1400) { func_0029F338(D_L10_001B1400); D_L10_001B1400 = 0; }
    if (D_L10_001B1404) { func_0029F338(D_L10_001B1404); D_L10_001B1404 = 0; }
}
