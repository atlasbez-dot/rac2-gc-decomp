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

extern s32 ref_L03_003F62C8_00 __attribute__((sda));
extern s32 ref_L03_003F62C8_01 __attribute__((sda));
extern s32 ref_L03_003F62C8_02(s32);
extern void ref_L03_003F62C8_03(void *, s32, s32);

void func_L03_003F62C8(void *arg0) {
    void *self  = arg0;
    u8 *obj  = *(u8 **)((u8 *)self + 0x68);
    s32 global_mode  = ref_L03_003F62C8_00;
    s32 mode ;
    u8 counter;

    if (global_mode < 0) {
        counter = *(u8 *)(obj + 0x30A);
        if (counter != 0) {
            mode = 1;
            *(u8 *)(obj + 0x30A) = (u8)(counter - 1);
            goto dispatch;
        }
        counter = *(u8 *)(obj + 0x309);
        if (counter != 0) {
            mode = 0;
            *(u8 *)(obj + 0x309) = (u8)(counter - 1);
            goto dispatch;
        }
        counter = *(u8 *)(obj + 0x30B);
        if (counter != 0) {
            mode = 2;
            *(u8 *)(obj + 0x30B) = (u8)(counter - 1);
            goto dispatch;
        }
        mode = ref_L03_003F62C8_02((s32)*(u8 *)(obj + 0x308) + 1);
    } else {
        mode = global_mode;
    }

dispatch:
    switch (mode) {
    case 0:
        ref_L03_003F62C8_03(self, 7, 3);
        if (*(u8 *)(obj + 0x308) >= 2) {
            *(f32 *)(obj + 0x2F8) = 0.6981318f;
            *(f32 *)(obj + 0x2FC) = -0.6981318f;
        } else if (ref_L03_003F62C8_02(2) != 0) {
            *(f32 *)(obj + 0x2F8) = 0.6981318f;
        } else {
            *(f32 *)(obj + 0x2FC) = -0.6981318f;
        }
        *(u8 *)(obj + 0x30B) = 1;
        return;
    case 1:
        *(s32 *)(obj + 0x2E4) = 0x12C;
        ref_L03_003F62C8_03(self, 9, 4);
        *(u8 *)(obj + 0x309) = (u8)(ref_L03_003F62C8_02(2) + 1);
        return;
    case 2:
        *(s32 *)(obj + 0x2E4) = ref_L03_003F62C8_01;
        ref_L03_003F62C8_03(self, 0xC, 5);
        *(u8 *)(obj + 0x309) = 1;
        return;
    default:
        return;
    }
}
