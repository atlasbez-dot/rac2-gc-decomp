/*
 * Retail is an 8-byte direct tail wrapper: j func_002B9038; addi $a1, $zero, 0.
 * The ordinary build emits a 28-byte frame/call/return sequence. A dedicated
 * -mastra-sibcall trial also emitted 28 bytes (0/28 placements). The combined
 * -foptimize-sibling-calls/-mastra-sibcall option is rejected by this compiler.
 */
extern void *func_002B9038(int size, int mode);

void *func_002B9030(int size) {
    return func_002B9038(size, 0);
}
