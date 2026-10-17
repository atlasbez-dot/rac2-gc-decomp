
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

struct Q4 { s8 b[4]; };
extern struct Q4 D_001AE860;
extern void func_00351848(void *, s32 *, s32 *, s32 *, s32 *);
extern s32 func_00350460(s32, s32, s32, s32, struct Q4 *, s32, s32, s32);
extern void func_00351868(s32, s32);
extern void func_003512B8(void *);

s32 func_00351960(void *arg0) {
    struct Q4 tmp;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 v0;

    tmp = D_001AE860;
    func_00351848(arg0, &sp10, &sp14, &sp18, &sp1C);
    if ((sp14 + sp1C) < 4) {
        return 0;
    }
    v0 = func_00350460((sp10 & 0x0FFFFFFF) | 0x20000000, sp14, (sp18 & 0x0FFFFFFF) | 0x20000000, sp1C, &tmp, 4, 0, 0);
    func_00351868(*(s32 *)0x1B23CC + 0xD9048, v0);
    func_003512B8((s8 *)arg0 + 0x48);
    if (*(s32 *)((s8 *)arg0 + 0xA8) == 0) {
        *(s32 *)((s8 *)arg0 + 0xA8) = 2;
    }
    return 1;
}
