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

extern s32 func_00282978(void *);
extern f32 func_00283CE0(s16);
extern s32 func_00283CF0(f32);
extern void func_002A0488(s32, s32, s32, s32);

struct Anim {
    s16 f0;
    s16 f2;
    u8 f4;
    u8 f5;
    u8 f6;
    u8 f7;
    u8 f8;
    u8 f9;
    s16 fA;
    s16 fC;
    u16 fE;
};

void func_002AB8C0(s32 arg0, struct Anim *p) {
    f32 R;
    f32 f20;
    s32 s2;
    s32 s1;
    s32 a3;

    if (p->f0 == 0) {
        return;
    }
    if (func_00282978(p) != 0) {
        if (p->f2 != 0) {
            func_002A0488(arg0, p->f4, p->f5, p->f6);
            return;
        }
        p->f2 = 1;
        p->f0 = p->fE;
    }
    if (p->f2 == 0) {
        R = func_00283CE0(p->fC);
        f20 = (R - (f32)p->f0) / R;
        if (p->f7 != 0) {
            s2 = func_00283CF0((f32)p->f4 + (f32)(p->f7 - p->f4) * f20);
        } else {
            s2 = p->f4;
        }
        if (p->f8 != 0) {
            s1 = func_00283CF0((f32)p->f5 + (f32)(p->f8 - p->f5) * f20);
        } else {
            s1 = p->f5;
        }
        if (p->f9 != 0) {
            a3 = func_00283CF0((f32)p->f6 + (f32)(p->f9 - p->f6) * f20);
        } else {
            a3 = p->f6;
        }
    } else {
        R = func_00283CE0((s16)p->fE);
        f20 = (R - (f32)p->f0) / R;
        if (p->f7 != 0) {
            s2 = func_00283CF0((f32)p->f7 + (f32)(p->f4 - p->f7) * f20);
        } else {
            s2 = p->f4;
        }
        if (p->f8 != 0) {
            s1 = func_00283CF0((f32)p->f8 + (f32)(p->f5 - p->f8) * f20);
        } else {
            s1 = p->f5;
        }
        a3 = (p->f9 != 0) ? func_00283CF0((f32)p->f9 + (f32)(p->f6 - p->f9) * f20) : p->f6;
    }
    func_002A0488(arg0, s2, s1, a3);
}
