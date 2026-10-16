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

f32 ref_L04_0044D6A0_00(f32, f32);
f32 ref_L04_0044D6A0_01(f32, f32);
f32 ref_L04_0044D6A0_02(f32, f32);
void ref_L04_0044D6A0_03(void *, void *);
void ref_L04_0044D6A0_04(void *);
void ref_L04_0044D6A0_05(void *);
void ref_L04_0044D6A0_06(void *, void *, s32, s32, f32);

void func_L04_0044D6A0(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 var_f0;
    f32 deltaX;
    f32 deltaY;
    u16 temp_v1;
    void *temp_s1;
    void *temp_v0;
    f32 bound ;
    f32 lower ;

    temp_s1 = (*(void **)((s8 *)(arg0) + (0x68)));
    ref_L04_0044D6A0_03(arg0, (u8 *)temp_s1 + 0x50);
    ref_L04_0044D6A0_04((u8 *)temp_s1 + 0x2FC);
    ref_L04_0044D6A0_05((u8 *)temp_s1 + 0x302);
    temp_v1 = (*(u16 *)((s8 *)(arg0) + (0x96)));
    if (temp_v1 <= 0xFFFEU) {
        (*(u16 *)((s8 *)(arg0) + (0x96))) = (u16)(temp_v1 + 1);
    }
    if ((*(u8 *)((s8 *)(arg0) + (0x95))) == 2) {
        temp_v0 = (*(void **)((s8 *)(temp_s1) + (0x250)));
        deltaX = (*(f32 *)((s8 *)(temp_v0) + (0x10))) - (*(f32 *)((s8 *)(arg0) + (0x10)));
        deltaY = (*(f32 *)((s8 *)(temp_v0) + (0x14))) - (*(f32 *)((s8 *)(arg0) + (0x14)));
        bound = 1.04719769954681396484375f;
        var_f0 = ref_L04_0044D6A0_02(ref_L04_0044D6A0_00(deltaX, deltaY), (*(f32 *)((s8 *)(arg0) + (0xF8))));
        if (var_f0 > bound) {
            var_f0 = bound;
        } else {
            lower = -bound;
            if (var_f0 < lower) {
                var_f0 = lower;
            }
        }
        if ((*(u16 *)((s8 *)(arg0) + (0x34))) & 0x8000) {
            var_f0 = -var_f0;
        }
        temp_f0 = ref_L04_0044D6A0_01(var_f0, (*(f32 *)((s8 *)(temp_s1) + (0x2C8))));
        (*(f32 *)((s8 *)(temp_s1) + (0x2C8))) = temp_f0;
        if (!(temp_f0 > bound)) {
            goto second_low;
        }
        (*(f32 *)((s8 *)(temp_s1) + (0x2C8))) = bound;
        goto second_done;
        second_low:
        lower = -bound;
        if (temp_f0 < lower) {
            (*(f32 *)((s8 *)(temp_s1) + (0x2C8))) = lower;
        }
        second_done:
        ;
    }
    ref_L04_0044D6A0_06(arg0, (u8 *)temp_s1 + 0x260, 1, 1, 2.5f);
}
