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

extern s8 *ref_L20_00444138_00;
extern u32 ref_L20_00444138_01;
extern u32 g_001B2FA0 __attribute__((sda));

void func_L20_00444138(void) {
    s8 *a0;
    u16 v1;
    u32 v0;

    a0 = ref_L20_00444138_00;
    v0 = ref_L20_00444138_01;
    if (v0 < (u32) a0) {
        return;
    }
    if ((*(u8 *)((s8 *)(a0) + (0x20))) == 0xFF) {
        return;
    }
    do {
        v1 = (*(u16 *)((s8 *)(a0) + (0xAA)));
        if (!((u32) (v1 - 0x1233) < 2U || (s16) v1 == 0x1231 || (s16) v1 == 0x1232)) {
            v0 = g_001B2FA0;
        } else {
            (*(s8 *)((s8 *)(a0) + (0x31))) = 0;
            (*(u16 *)((s8 *)(a0) + (0x34))) = (u16) ((*(u16 *)((s8 *)(a0) + (0x34))) | 1);
            v0 = ref_L20_00444138_01;
        }
        a0 += 0x100;
        if (v0 < (u32) a0) {
            break;
        }
        if ((*(u8 *)((s8 *)(a0) + (0x20))) == 0xFF) {
            break;
        }
    } while (1);
}
