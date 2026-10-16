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

s32 func_L02_003FC0D0(void *arg0, s32 arg1) {
    s32 temp_v1;
    void *temp_a0;

    temp_a0 = *(void **)((u8 *)arg0 + 0x68);
    if (arg1 == 0xA44) {
        goto return_special;
    }
    if (arg1 < 0xA45) {
        if (arg1 == 0x9CA) {
            goto decrement_50;
        }
        if (arg1 == 0x9F8) {
            goto return_special;
        }
        goto return_general;
    }
    if (arg1 == 0xC3B) {
        goto decrement_58;
    }
    if (arg1 < 0xC3C) {
        if (arg1 == 0xB22) {
            goto decrement_54;
        }
        goto return_general;
    }
    if (arg1 == 0xC3E) {
        goto decrement_5C;
    }
    goto return_general;

decrement_50:
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 0x50);
    if (temp_v1 <= 0) {
        goto return_general;
    }
    *(s32 *)((u8 *)temp_a0 + 0x50) = temp_v1 - 1;
    return 1;

decrement_54:
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 0x54);
    if (temp_v1 <= 0) {
        goto return_general;
    }
    *(s32 *)((u8 *)temp_a0 + 0x54) = temp_v1 - 1;
    return 1;

decrement_58:
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 0x58);
    if (temp_v1 <= 0) {
        goto return_general;
    }
    *(s32 *)((u8 *)temp_a0 + 0x58) = temp_v1 - 1;
    return 1;

decrement_5C:
    temp_v1 = *(s32 *)((u8 *)temp_a0 + 0x5C);
    if (temp_v1 <= 0) {
        goto return_general;
    }
    *(s32 *)((u8 *)temp_a0 + 0x5C) = temp_v1 - 1;
    return 1;

return_special:
    return 0;
return_general:
    return 0;
}
