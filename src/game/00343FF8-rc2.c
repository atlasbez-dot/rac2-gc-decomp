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

extern s32 func_002E5E58();
extern s16 D_0025E328[][5];

void func_00343FF8(s32 arg0, s32 arg1) {
    s32 temp_v1;
    s32 temp_v0;

    if (arg1 & 0x1000) {
        func_002E5E58(3, 0, 0);
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x440))) - 1;
        (*(s32 *)((s8 *)(arg0) + (0x440))) = temp_v1;
        if (temp_v1 < 0) {
            temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x43C)));
            if (temp_v0 < 2) {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
                (*(s32 *)((s8 *)(arg0) + (0x448))) = 0;
            } else if (temp_v0 == 2) {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 1;
            } else {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
                (*(s32 *)((s8 *)(arg0) + (0x448))) = 1;
                (*(s32 *)((s8 *)(arg0) + (0x43C))) = 0;
            }
        }
    } else if (arg1 & 0x4000) {
        func_002E5E58(3, 0, 0);
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x440))) + 1;
        (*(s32 *)((s8 *)(arg0) + (0x440))) = temp_v1;
        if (temp_v1 >= 2) {
            temp_v0 = (*(s32 *)((s8 *)(arg0) + (0x43C)));
            if (temp_v0 < 2) {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
                (*(s32 *)((s8 *)(arg0) + (0x448))) = 0;
            } else if (temp_v0 == 2) {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
            } else {
                (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
                (*(s32 *)((s8 *)(arg0) + (0x448))) = 3;
                (*(s32 *)((s8 *)(arg0) + (0x43C))) = 0;
            }
        }
    } else if (arg1 & 0x8000) {
        func_002E5E58(3, 0, 0);
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x43C))) - 1;
        (*(s32 *)((s8 *)(arg0) + (0x43C))) = temp_v1;
        if (temp_v1 < 0) {
            (*(s32 *)((s8 *)(arg0) + (0x43C))) = 3;
        }
    } else if (arg1 & 0x2000) {
        func_002E5E58(3, 0, 0);
        temp_v1 = (*(s32 *)((s8 *)(arg0) + (0x43C))) + 1;
        (*(s32 *)((s8 *)(arg0) + (0x43C))) = temp_v1;
        if (temp_v1 >= 4) {
            (*(s32 *)((s8 *)(arg0) + (0x43C))) = 0;
            (*(s32 *)((s8 *)(arg0) + (0x448))) = 3;
            (*(s32 *)((s8 *)(arg0) + (0x440))) = 0;
        }
    }
    (*(s32 *)((s8 *)(arg0) + (0x444))) = D_0025E328[(*(s32 *)((s8 *)(arg0) + (0x43C))) + (*(s32 *)((s8 *)(arg0) + (0x440))) * 4][3];
}
