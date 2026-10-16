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

extern s32 ref_L03_003C4BD8_00(void *);
extern s32 ref_L03_003C4BD8_01(s32);
extern s32 ref_L03_003C4BD8_02(s32, s32);
extern f32 ref_L03_003C4BD8_03(f32, f32);
extern f32 ref_L03_003C4BD8_04(f32, f32);
extern void ref_L03_003C4BD8_05(void *, s8 *);
extern s8 D_00189F00[];

void func_L03_003C4BD8(void *arg0) {
    s32 temp_v0;
    f32 temp_f0;
    f32 temp_f1;
    void *temp_s0;

    temp_s0 = (*(void **)((s8 *)(arg0) + (0x68)));
    if (ref_L03_003C4BD8_00((s8 *)temp_s0 + 0x384) != 0) {
        if ((*(u8 *)((s8 *)(arg0) + (0x95))) == 2) {
            (*(f32 *)((s8 *)(temp_s0) + (0x388))) = ref_L03_003C4BD8_04(5.0f, 60.0f) * 0.017453294f;
            (*(f32 *)((s8 *)(temp_s0) + (0x38C))) = ref_L03_003C4BD8_03(-20.0f, 0.0f) * 0.017453294f;
            (*(s32 *)((s8 *)(temp_s0) + (0x384))) = ref_L03_003C4BD8_02(30, 45);
            (*(s32 *)((s8 *)(temp_s0) + (0x390))) = 0;
        } else {
            (*(f32 *)((s8 *)(temp_s0) + (0x388))) = ref_L03_003C4BD8_04(5.0f, 20.0f) * 0.017453294f;
            (*(f32 *)((s8 *)(temp_s0) + (0x38C))) = ref_L03_003C4BD8_03(-15.0f, 5.0f) * 0.017453294f;
            temp_v0 = ref_L03_003C4BD8_01(4) == 0;
            (*(s32 *)((s8 *)(temp_s0) + (0x390))) = temp_v0;
            if (temp_v0 != 0) {
                (*(s32 *)((s8 *)(temp_s0) + (0x384))) = ref_L03_003C4BD8_02(180, 300);
            } else {
                (*(s32 *)((s8 *)(temp_s0) + (0x384))) = ref_L03_003C4BD8_02(60, 120);
            }
        }
    }
    if ((*(s32 *)((s8 *)(temp_s0) + (0x390))) != 0) {
        ref_L03_003C4BD8_05(arg0, D_00189F00);
        return;
    }
    temp_f0 = (*(f32 *)((s8 *)(temp_s0) + (0x38C)));
    temp_f1 = (*(f32 *)((s8 *)(temp_s0) + (0x388)));
    (*(f32 *)((s8 *)(temp_s0) + (0x324))) = temp_f0;
    (*(f32 *)((s8 *)(temp_s0) + (0x328))) = temp_f1;
    (*(f32 *)((s8 *)(temp_s0) + (0x2A4))) = temp_f0;
    (*(f32 *)((s8 *)(temp_s0) + (0x2A8))) = temp_f1;
}
