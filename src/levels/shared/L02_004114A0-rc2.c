
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
extern void *D_L02_002A5DF0[];

extern void ref_L02_004114A0_00(s32, s32, s32);

void func_L02_004114A0(void *arg0) {
    s8 *p;
    s32 v;
    s32 a1;

    p = (*(s8 **)((char *)(arg0) + (0x68)));
    v = (*(s32 *)((char *)(p) + (0x10)));
    {
    static void *volatile rc2_labels[] = {&&rc2_case_0, &&rc2_case_1, &&rc2_case_2, &&rc2_case_3, &&rc2_case_4, &&rc2_case_5, &&rc2_case_6, &&rc2_case_7, &&rc2_case_8, &&rc2_case_9};
    u32 rc2_selector = (u32)(v);
    if (rc2_selector > 9U) goto rc2_default;
goto *D_L02_002A5DF0[rc2_selector];

    
    rc2_case_1:
        a1 = 0x27B9;
        goto rc2_switch_end;
    
    rc2_case_3:
        a1 = 0x27E9;
        goto rc2_switch_end;
    rc2_case_4:
        a1 = 0x27F6;
        goto rc2_switch_end;
    rc2_case_5:
        a1 = 0x27EB;
        goto rc2_switch_end;
    rc2_case_6:
        a1 = 0x27F2;
        goto rc2_switch_end;
    rc2_case_7:
        a1 = 0x27F3;
        goto rc2_switch_end;
    rc2_case_8:
        a1 = 0x27F4;
        goto rc2_switch_end;
    rc2_case_9:
        a1 = 0x27F5;
        goto rc2_switch_end;
    rc2_case_0:
    rc2_case_2:
    rc2_default:
        a1 = 0x2793;
        goto rc2_switch_end;
    
rc2_switch_end: ;
}
    ref_L02_004114A0_00(0xB, a1, 1);
}
