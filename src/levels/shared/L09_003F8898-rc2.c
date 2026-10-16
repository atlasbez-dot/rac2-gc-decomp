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

extern s32 ref_L09_003F8898_00(s8 *);
extern s16 ref_L09_003F8898_01(s32, s32);
extern void ref_L09_003F8898_02(s32, s8 *, s32, s32, f32);
extern u16 ref_L09_003F8898_03 __attribute__((sda));
extern s32 ref_L09_003F8898_04 __attribute__((sda));
extern s32 ref_L09_003F8898_05 __attribute__((sda));
extern s32 ref_L09_003F8898_06 __attribute__((sda));

void func_L09_003F8898(s8 *arg0) {
    s8 *s0;
    u16 v1;

    s0 = (*(s8 **)((s8 *)(arg0) + (0x68)));
    if ((*(u8 *)((s8 *)(s0) + (0x2EA))) != 0) {
        (*(u8 *)((s8 *)(s0) + (0x2EA))) = 0;
        if ((*(s16 *)((s8 *)(s0) + (0x2E0))) < ref_L09_003F8898_04) {
            (*(s16 *)((s8 *)(s0) + (0x2E0))) = ref_L09_003F8898_01(ref_L09_003F8898_05, ref_L09_003F8898_06);
        }
    }
    if (ref_L09_003F8898_00(s0 + 0x2E0) == 0) {
        (*(u16 *)((s8 *)(s0) + (0x2E8))) = ref_L09_003F8898_03;
    }
    ref_L09_003F8898_00(s0 + 0x2E2);
    ref_L09_003F8898_00(s0 + 0x2E6);
    ref_L09_003F8898_00(s0 + 0x2E8);
    v1 = (*(u16 *)((s8 *)(arg0) + (0x96)));
    if (v1 <= 0xFFFE) {
        (*(u16 *)((s8 *)(arg0) + (0x96))) = (u16)(v1 + 1);
    }
    ref_L09_003F8898_02((*(s32 *)((s8 *)(s0) + (0x2F8))), s0 + 0x430, 4, 1, 1.89999997615814208984375f);
}
