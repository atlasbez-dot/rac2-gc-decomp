
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 RC2 decomp contributions
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */
#include "common.h"

extern s32 ref_L04_004027B0_00(void **a0, s32 a1, s32 a2, s32 a3);
extern s32 ref_L04_004027B0_01(void **a0, void *a1, s32 a2, s32 a3);
extern void ref_L04_004027B0_02(void *a0);
extern f32 ref_L04_004027B0_03(f32 a0);
extern void ref_L04_004027B0_04(void *a0, void *a1, void *a2);
extern f32 ref_L04_004027B0_05(void *a0, void *a1);
extern void ref_L04_004027B0_06(void *a0, void *a1, void *a2);
extern void ref_L04_004027B0_07(void *a0);
extern void ref_L04_004027B0_08(void *a0, void *a1);
extern void ref_L04_004027B0_09(s32 a0, s32 a1, void *a2);
extern void ref_L04_004027B0_10(void *a0, f32 a1, f32 a2);

struct Fr {
    f32 v[4];
    s8 m[0x40];
    void *sp50;
};

void func_L04_004027B0(s8 *arg0, s8 *arg1) {
    struct Fr fr;
    s8 *s3;
    u16 *s0;

    if (*(s32 *)(arg1 + 0x80) != -1) {
        ref_L04_004027B0_00(&fr.sp50, *(s32 *)(arg1 + 0x80), 0, 0);
        s3 = arg1 + 0x13C;
        if (fr.sp50 != 0) {
            do {
                if (*(s16 *)((s8 *)fr.sp50 + 0xAA) == 0x474 || *(s16 *)((s8 *)fr.sp50 + 0xAA) == 0xCEF) {
                    ref_L04_004027B0_04(fr.v, (s8 *)fr.sp50 + 0x10, arg0 + 0x10);
                    if (!(ref_L04_004027B0_05(fr.v, fr.v) > 20.0f)) {
                        ref_L04_004027B0_07(fr.m);
                        ref_L04_004027B0_08(fr.m, (s8 *)fr.sp50 + 0xC0);
                        ref_L04_004027B0_06(fr.v, fr.v, fr.m);
                        if (ref_L04_004027B0_03(fr.v[0]) < 2.8f && ref_L04_004027B0_03(fr.v[1]) < 1.25f) {
                            if (ref_L04_004027B0_03(fr.v[2]) < 1.5f) {
                                s0 = *(u16 **)((s8 *)fr.sp50 + 0x68);
                                if (*(s16 *)(arg1 + 0x140) == 0 && ((u8 *)(*(s8 **)(arg1 + 0x164)))[0x20] != 3) {
                                    ref_L04_004027B0_09(0, 0, fr.sp50);
                                }
                                *(s16 *)(arg1 + 0x140) = *s0;
                            }
                        }
                    }
                }
                ref_L04_004027B0_01(&fr.sp50, fr.sp50, 0, 0);
            } while (fr.sp50 != 0);
        }
        if (*(s16 *)(arg1 + 0x140) != 0) {
            *(s16 *)(arg1 + 0x142) = 1;
            ref_L04_004027B0_10(s3, 0.10000000894069671630859375f, 0.00555555569f);
            if (*(s16 *)(arg1 + 0x140) != 0) {
                ref_L04_004027B0_02(arg1 + 0x140);
            }
        } else {
            *(s16 *)(arg1 + 0x142) = 0;
            ref_L04_004027B0_10(s3, 0.0f, 0.002777777845f);
        }
    }
}
