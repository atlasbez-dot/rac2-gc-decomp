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

extern s32 func_002E59F8();
extern s32 func_002E5CF8();
extern s32 D_00188660[];

void func_0029F450(void *arg0) {
    s32 var_v0;
    void *temp_a0;

    if ((*(u8 *)((s8 *)(arg0) + (0x6D))) != 0xFF) {
        temp_a0 = (s32) ((s8 *) (((*(u8 *)((s8 *)(arg0) + (0x6D))) * 0x70)) + (s32) (&D_00188660[0]));
        if ((*(s32 *)((s8 *)(temp_a0) + (0x88))) != arg0) {
            (*(u8 *)((s8 *)(arg0) + (0x6D))) = 0xFFU;
        } else {
            if (((*(s16 *)((s8 *)(temp_a0) + (0x7E))) != (*(u8 *)((s8 *)(arg0) + (0x6C)))) || ((*(u16 *)((s8 *)(arg0) + (0x34))) & 0x40) || ((*(u16 *)((s8 *)(arg0) + (0x7C))) & 0x8000)) {
                func_002E59F8((*(u8 *)((s8 *)(arg0) + (0x6D))));
                var_v0 = 0xFF;
                goto block_13;
            }
        }
    } else if (((*(u8 *)((s8 *)(arg0) + (0x6C))) != (*(u8 *)((s8 *)(arg0) + (0x6D)))) && !((*(u16 *)((s8 *)(arg0) + (0x34))) & 0x40) && !((*(u16 *)((s8 *)(arg0) + (0x7C))) & 0x8000)) {
        var_v0 = func_002E5CF8((*(u8 *)((s8 *)(arg0) + (0x6C))), 4, arg0);
block_13:
        (*(u8 *)((s8 *)(arg0) + (0x6D))) = var_v0;
    }
}
