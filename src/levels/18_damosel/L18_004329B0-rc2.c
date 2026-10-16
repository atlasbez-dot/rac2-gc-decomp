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
#ifndef NULL
#define NULL 0
#endif

extern void ref_L18_004329B0_00(s32, s32);
extern void ref_L18_004329B0_01(s32, s32, void *);
extern void ref_L18_004329B0_02(void *, s32, s32, s32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32);
extern void ref_L18_004329B0_03(void *);
extern u8 D_00188660[];

void func_L18_004329B0(void *arg0) {
    void *temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    s32 temp_a1 = *(s32 *)((u8 *)temp_s0 + 0x7F0);

    if (temp_a1 != -1) {
        u8 *temp_v1 = D_00188660 + temp_a1 * 0x70;
        if (*(void **)(temp_v1 + 0x88) == arg0 && *(u8 *)(temp_v1 + 0x74) != 0) {
            ref_L18_004329B0_00(temp_a1, temp_a1);
        }
    }

    *(s32 *)((u8 *)temp_s0 + 0x7F0) = -1;
    ref_L18_004329B0_02((u8 *)arg0 + 0x10, 1, 0x19, 0x14, 1.0f, 20.0f, 0x14, 0x14, 0x2D, 1, 1, 1, 0, 0);
    ref_L18_004329B0_01(6, 0, arg0);

    if (*(void **)((u8 *)temp_s0 + 0x7C0) != NULL) {
        ref_L18_004329B0_03(*(void **)((u8 *)temp_s0 + 0x7C0));
        *(void **)((u8 *)temp_s0 + 0x7C0) = NULL;
    }
    if (*(void **)((u8 *)temp_s0 + 0x7C4) != NULL) {
        ref_L18_004329B0_03(*(void **)((u8 *)temp_s0 + 0x7C4));
        *(void **)((u8 *)temp_s0 + 0x7C4) = NULL;
    }
    if (*(void **)((u8 *)temp_s0 + 0x7C8) != NULL) {
        ref_L18_004329B0_03(*(void **)((u8 *)temp_s0 + 0x7C8));
        *(void **)((u8 *)temp_s0 + 0x7C8) = NULL;
    }
    ref_L18_004329B0_03(arg0);
}
