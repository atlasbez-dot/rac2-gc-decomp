/* 0 of 4 places match - last line: 05_feltzin_system: instruction at +0x0 differs
   One compile. The body is a call, a null guard and five stores; this cc1 turns the
   guard into `beql $s0,$zero` with `ld $s0,0x0($sp)` (the frame restore!) in the
   annulled delay slot, where retail branches plainly and restores in the shared
   epilogue. Same annulled-slot wall as func_L12_00427C58, so no more shapes. */

extern void func_379CA0();
extern void func_3065F8(int);

void func_L05_0037BB28(int a0) {
    int p = func_379CA0();

    if (p == 0)
        return;
    func_3065F8(p);
    *(int *)(p + 0x10) = 0;
    *(int *)(p + 0x18) = -1;
    *(int *)(p + 0x20) = -1;
    *(int *)(p + 0x1C) = -1;
    *(int *)(p + 0x14) = 0;
}
