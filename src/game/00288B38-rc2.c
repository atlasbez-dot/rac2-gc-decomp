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

typedef struct {
    s8 pad0[8];
    struct {
        u32 key;
        u32 extra;
    } arr[5];
    s32 f30;
    s32 f34;
} R3;

extern u32 D_00139768[];

void func_00288B38(R3 *arg0) {
    u32 key;
    s32 var_a1;
    s32 temp_v0;

    var_a1 = arg0->f34;
    while (var_a1 != arg0->f30) {
        key = arg0->arr[var_a1].key;
        if (key < 0xB1) {
            D_00139768[key >> 2] |= 1 << (key & 31);
        }
        temp_v0 = var_a1 + 1;
        var_a1 = (temp_v0 != 5) ? temp_v0 : 0;
    }
}
