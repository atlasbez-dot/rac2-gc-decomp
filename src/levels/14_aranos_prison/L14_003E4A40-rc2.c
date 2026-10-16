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

extern f32 ref_L14_003E4A40_00(f32, f32);
extern void ref_L14_003E4A40_01(void *, s32, s32);
extern s32 ref_L14_003E4A40_02(void *);
extern void ref_L14_003E4A40_03(s32, s32);
extern s32 ref_L14_003E4A40_04(s32, s32, void *);
extern u8 D_00188660[];

void func_L14_003E4A40(void *arg0) {
    s32 *temp_s1;
    s32 temp_a1;
    u8 temp_v1;
    void *temp_a0;
    void *temp_v1_2;

    temp_v1 = *(u8 *)((u8 *)arg0 + 0x20);
    temp_s1 = *(s32 **)((u8 *)arg0 + 0x68);
    switch (temp_v1) {
    case 0:
        ref_L14_003E4A40_01(arg0, 1, -1);
        *temp_s1 = -1;
        return;
    case 1:
        if (ref_L14_003E4A40_02(arg0) != 0) {
            ref_L14_003E4A40_01(arg0, 2, -1);
        }
        return;
    case 2:
        if (*(f32 *)((u8 *)arg0 + 0xF0) > -1.5707964f) {
            temp_a0 = (void *)(D_00188660 + (*temp_s1 * 0x70));
            if ((*(void **)((u8 *)temp_a0 + 0x88) != arg0) ||
                (*(u8 *)((u8 *)temp_a0 + 0x74) == 0)) {
                *temp_s1 = ref_L14_003E4A40_04(0, 4, arg0);
            }
            *(f32 *)((u8 *)arg0 + 0xF0) =
                ref_L14_003E4A40_00(*(f32 *)((u8 *)arg0 + 0xF0), 0.00872664712369442f);
        }
        temp_a1 = *temp_s1;
        if (temp_a1 != -1) {
            temp_v1_2 = (void *)(D_00188660 + (temp_a1 * 0x70));
            if ((*(void **)((u8 *)temp_v1_2 + 0x88) == arg0) &&
                (*(u8 *)((u8 *)temp_v1_2 + 0x74) != 0)) {
                ref_L14_003E4A40_03(temp_a1, temp_a1);
            }
        }
        *temp_s1 = -1;
        return;
    default:
        return;
    }
}
