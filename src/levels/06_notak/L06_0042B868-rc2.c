
/* SPDX-License-Identifier: MIT
 * MIT License
 * 
 * Copyright (c) 2026 Forja contributors
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

/* The resident table already holds the retail label addresses. The unused
 * label list keeps each C branch available; it is not read by the program. */
extern void *D_L06_002E1F00[];

extern void ref_L06_0042B868_00(void *, s32, s32, s32);
extern s32 ref_L06_0042B868_01(void *);
extern void ref_L06_0042B868_02(u8, s32);

void func_L06_0042B868(void *arg0) {
    u8 mode = *(u8 *)((u8 *)arg0 + 0x20);
    s32 *timer = *(s32 **)((u8 *)arg0 + 0x68);

    {
    static void *volatile rc2_labels[] = {&&rc2_case_0, &&rc2_case_1, &&rc2_case_2, &&rc2_case_3, &&rc2_case_4};
    u32 rc2_selector = (u32)(mode);
    if (rc2_selector > 4U) goto rc2_default;
goto *D_L06_002E1F00[rc2_selector];

    rc2_case_0:
        *(u8 *)((u8 *)arg0 + 0x20) = 1;
        *timer = 0x5DC;
        return;
    rc2_case_1:
        if (*(u8 *)((u8 *)arg0 + 0xBC) != 0) {
            *(u8 *)((u8 *)arg0 + 0x20) = 2;
            if (*(u8 *)((u8 *)arg0 + 0x43) != 1) {
                ref_L06_0042B868_00(arg0, 1, 0, 0);
            }
            *(s32 *)((u8 *)arg0 + 0x98) = 0;
        }
        return;
    rc2_case_2:
        if ((*(u8 *)((u8 *)arg0 + 0x60) & 2) != 0) {
            *(u8 *)((u8 *)arg0 + 0x20) = 3;
            if (*(u8 *)((u8 *)arg0 + 0x43) != 2) {
                ref_L06_0042B868_00(arg0, 2, 0, 0);
            }
        }
        return;
    rc2_case_3:
        if (ref_L06_0042B868_01(timer) != 0) {
            *(u8 *)((u8 *)arg0 + 0x20) = 4;
            if (*(u8 *)((u8 *)arg0 + 0x43) != 3) {
                ref_L06_0042B868_00(arg0, 3, 0, 0);
            }
        }
        return;
    rc2_case_4:
        if ((*(u8 *)((u8 *)arg0 + 0x60) & 2) != 0) {
            *(u8 *)((u8 *)arg0 + 0x20) = 1;
            if (*(u8 *)((u8 *)arg0 + 0x43) != 0) {
                ref_L06_0042B868_00(arg0, 0, 0, 0);
            }
            *(s32 *)((u8 *)arg0 + 0x98) =
                *(s32 *)((u8 *)*(void **)((u8 *)arg0 + 0x24) + 0x10);
            *timer = 0x5DC;
            ref_L06_0042B868_02(*(u8 *)((u8 *)arg0 + 0x21), 0);
        }
        return;
    rc2_default:
        return;
    
rc2_switch_end: ;
}
}
