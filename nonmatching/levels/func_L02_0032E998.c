/* 768/764, all three releases 0/9.
 * Profile: default -O2 -G0 -ffunction-sections.
 * Breadth-first routing through 32-byte nodes with the measured 256-byte visited array. Extra saved state and loop-lifetime allocation remain; helper call banks and both float inputs retained. Reopen with source loop-lifetime evidence.
 */
typedef unsigned char u8;
typedef unsigned short u16;
struct RouteNode {
    int path;
    u8 neighbors[4];
    u8 portals[4];
    u16 flags;
    u8 unused[18];
};
extern char *D_L02_001FF1C0[];
extern float func_00283248(float, float);
extern float func_00283B98(float, float);
extern int func_L02_0032EDD8(void *, struct RouteNode *, int, int *);
extern float func_L02_0032EC98(void *, void *, void *, float, float);

int func_L02_0032E998(float *position, float *target, float *heading, struct RouteNode *nodes, int count, int *sourceNode, int *targetNode, float override, float margin) {
    u8 visited[256];
    int i, j, found = -1, portal = -1, step;
    unsigned int layer;
    char *path;
    float angle;
    *heading = func_00283248(target[0] - position[0], target[1] - position[1]);
    if (override != 0.0f)
        *heading = func_00283B98(override, *heading);
    if (!func_L02_0032EDD8(position, nodes, count, sourceNode))
        return 0;
    if (!func_L02_0032EDD8(target, nodes, count, targetNode))
        return 0;
    if (nodes[*targetNode].flags & 1)
        return 0;
    if (*sourceNode == *targetNode)
        return 1;
    for (i = 0; i < count; i++)
        visited[i] = 0;
    visited[*targetNode] = 1;
    for (layer = 1; layer < 50; layer++) {
        for (i = 0; i < count; i++) {
            if (visited[i] == layer) {
                for (j = 0; j < 4; j++) {
                    unsigned int neighbor = nodes[i].neighbors[j];
                    if (!(neighbor & 0x80) && !visited[neighbor] && !(nodes[neighbor].flags & 1)) {
                        visited[neighbor] = layer + 1;
                        if (neighbor == *sourceNode) {
                            portal = nodes[i].portals[j];
                            found = i;
                        }
                    }
                }
            }
            if (found != -1)
                break;
        }
        if (found != -1)
            break;
    }
    if (found == -1)
        return 0;
    path = D_L02_001FF1C0[nodes[found].path];
    angle = *heading;
    if (visited[found] >= 3) {
        step = visited[found] - 1;
        for (j = 0; j < 4; j++) {
            if (visited[nodes[found].neighbors[j]] == step) {
                i = nodes[found].portals[j] * 16;
                angle = func_L02_0032EC98(path + i + 0x10, path + i + 0x20, position, angle, margin);
                break;
            }
        }
    }
    *heading = func_L02_0032EC98(path + portal * 16 + 0x10, path + portal * 16 + 0x20, position, angle, margin);
    return 1;
}
