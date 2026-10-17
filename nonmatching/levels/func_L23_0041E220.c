/* func_L23_0041E220 (64 bytes, 1 place) -- measured 0 of 1, best candidate 60 bytes.
   (Measurement from wave 9 worker 16, kept here; not re-measured in wave 6.)

   Retail is the decision tree of a `switch` whose two labels do NOT share a block
   (each case gets its own lw/jr/lwc1) plus a default:

     lh   $v1,0xAA($a0)
     addiu $v0,$zero,0xE3B
     beq  $v1,$v0,.case44          ; root test on the HIGHER case
     slti $v0,$v1,0xE3C            ; <= the root value -> left subtree
     beqz $v0,.default             ; (this slti is the tree's range check)
     addiu $v0,$zero,0xE3A
     bne  $v1,$v0,.shared_tail     ; single-node left subtree
     ...
   .case2C: lw $v0,0x68($a0); jr $ra; lwc1 $f0,0x2C($v0)
   .case44: lw $v0,0x68($a0); jr $ra; lwc1 $f0,0x44($v0)
   .default: lw $v0,0x68($a0); .shared_tail: jr $ra; lwc1 $f0,0x44($v0)

   Writing it as `switch (k) { case 0xE3A: ...; case 0xE3B: ...; }` makes cc1 merge the
   two labels into ONE range node (44 bytes) -- the root must stay on 0xE3B, which is
   what a three-node list (0xE3A, 0xE3B, default) gives. As an if chain the structure
   comes out right but cc1's cross-jumping then folds the two identical 0x44 blocks
   into one backward `beql` (60 bytes).

   Both spellings below are kept: the if chain is the 60-byte one, the switch without
   default is the 44-byte one. What is still missing is a source that keeps three
   separate blocks AND the 0xE3B root.
*/

typedef short s16;

/* 60 bytes: right blocks, no 0xE3B root (cross-jumping merged the two 0x44 blocks). */
float func_L23_0041E220(char *arg0) {
    s16 kind = *(s16 *)(arg0 + 0xAA);

    if (kind == 0xE3B)
        return *(float *)(*(char **)(arg0 + 0x68) + 0x44);
    if (kind < 0xE3C) {
        if (kind == 0xE3A)
            return *(float *)(*(char **)(arg0 + 0x68) + 0x2C);
    }
    return *(float *)(*(char **)(arg0 + 0x68) + 0x44);
}

#if 0
/* 44 bytes: cc1 merges the 0xE3A/0xE3B labels into a range node. */
float func_L23_0041E220(char *arg0) {
    switch (*(s16 *)(arg0 + 0xAA)) {
    case 0xE3A:
        return *(float *)(*(char **)(arg0 + 0x68) + 0x2C);
    case 0xE3B:
        return *(float *)(*(char **)(arg0 + 0x68) + 0x44);
    }
    return *(float *)(*(char **)(arg0 + 0x68) + 0x44);
}
#endif
