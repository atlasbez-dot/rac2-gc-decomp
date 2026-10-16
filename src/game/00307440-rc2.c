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

extern void func_00282CC0(void *a0, void *a1, void *a2);
extern void func_00282CF0(void *a0, void *a1, void *a2);

struct V4 {
    f32 x;
    f32 y;
    f32 z;
    s32 w;
};

void func_00307440(s8 *arg0) {
    struct V4 v;
    struct V4 r;
    s8 *t;
    s8 *m;

    v.w = 0;
    t = (*(s8 **)((s8 *)(arg0) + (0x68)));
    v.x = (*(f32 *)((s8 *)(t) + (0x74)));
    v.y = (*(f32 *)((s8 *)(t) + (0x78)));
    v.z = (*(f32 *)((s8 *)(t) + (0x7C)));
    func_00282CF0(&r, (*(s8 **)((s8 *)(t) + (0x70))) + 0x10, &v);
    func_00282CC0(arg0 + 0x10, &r, arg0 + 0x10);
    m = (*(s8 **)((s8 *)(t) + (0x70)));
    (*(f32 *)((s8 *)(t) + (0x74))) = (*(f32 *)((s8 *)(m) + (0x10)));
    (*(f32 *)((s8 *)(t) + (0x78))) = (*(f32 *)((s8 *)(m) + (0x14)));
    (*(f32 *)((s8 *)(t) + (0x7C))) = (*(f32 *)((s8 *)(m) + (0x18)));
    if ((*(s16 *)((s8 *)((*(s8 **)((s8 *)(m) + (0x24)))) + (0x46))) == 0x12) {
        if ((*(u8 *)((s8 *)((*(s8 **)((s8 *)(m) + (0x68)))) + (0x14))) == 0) {
            (*(s8 *)((s8 *)(arg0) + (0x20))) = 7;
        }
    }
}
