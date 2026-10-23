/* Retained C, not matched.
   Profile: -O2 -G8 -ffunction-sections -frac2-keep-block-order -fno-schedule-insns.
   288/288 bytes; 0/27 on USA/PAL/US2, first mismatch +0x88. Zero-mode-first layout and exact rounded constants recovered; constant allocation and zero-arm store scheduling differ. Five bounded trials including both CFG switches and scheduler variants. */

extern float D_001A790C;
extern float D_001A7910;
extern float D_001A7914;
extern float D_001A7918;
extern float D_001A791C;
extern float D_001A7920;
extern int D_001A7924;
extern float D_001A7928;
extern int D_001A7B90;
extern float D_L00_001A7918 __attribute__((sda));
extern float D_L00_001A7928 __attribute__((sda));

void func_L00_00322428(int mode) {
 if(mode==0) {
  float one = 1.0f;
  float frame = 1.0f/60.0f;
  float square = 1.0f/3600.0f;
  float cube = 1.0f/216000.0f;
  D_001A7914=one;
  D_001A791C=square;
  D_001A7920=cube;
  D_001A7924=5;
  D_001A7928=frame;
  D_001A7B90=0;
  D_001A790C=one;
  D_001A7910=one;
  D_L00_001A7918=frame;
 } else {
  D_001A7B90=1;
  D_001A790C=1.2f;
  D_001A7910=1.44f;
  D_001A7914=0.83333337306976318359375f;
  D_001A7918=0.02000000141561031341552734375f;
  D_001A791C=0.00040000001899898052215576171875f;
  D_001A7920=0.000008f;
  D_001A7924=6;
  D_L00_001A7928=0.02f;
 }
}
