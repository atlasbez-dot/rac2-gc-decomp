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

void ref_L01_003B49D8_00(void *, void **, s32 *);
void ref_L01_003B49D8_01(void *, s32, void *);
void ref_L01_003B49D8_02(void *);
void ref_L01_003B49D8_03(void **, s32 *);

typedef struct {
    void *items[16];
    s32 count;
} temp_buffer;

void func_L01_003B49D8(void *arg0, s32 arg1) {
    temp_buffer buffer;
    s8 *state;
    f32 saved_130;
    f32 saved_138;
    f32 limit ;
    f32 current ;
    f32 reduced ;

    buffer.count = 0;
    state = (s8 *)(*(void **)((s8 *)(arg0) + (0x68)));
    if ((*(u8 *)((s8 *)(state) + (0x35D))) != 0) {
        ref_L01_003B49D8_00(arg0, buffer.items, &buffer.count);
    }
    saved_130 = (*(f32 *)((s8 *)(state) + (0x130)));
    saved_138 = (*(f32 *)((s8 *)(state) + (0x138)));
    if (buffer.count > 0) {
        (*(f32 *)((s8 *)(state) + (0x138))) = 2.0f * saved_138;
        (*(f32 *)((s8 *)(state) + (0x130))) = 2.0f * saved_130;
    }
    ref_L01_003B49D8_01(arg0, arg1, state + 0x110);
    ref_L01_003B49D8_02(arg0);
    current = (*(f32 *)((s8 *)(state) + (0x1B8)));
    limit = 0.083333336f;
    if (current > limit) {
        reduced = 0.9f;
        reduced = current * reduced;
        reduced = (reduced > limit) ? limit : reduced;
        (*(f32 *)((s8 *)(state) + (0x1B8))) = reduced;
    }
    (*(f32 *)((s8 *)(state) + (0x130))) = saved_130;
    (*(f32 *)((s8 *)(state) + (0x138))) = saved_138;
    if ((*(u8 *)((s8 *)(state) + (0x35D))) != 0) {
        ref_L01_003B49D8_03(buffer.items, &buffer.count);
    }
}
