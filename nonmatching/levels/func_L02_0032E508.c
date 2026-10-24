/* 2026-10-23 bounded readable-C attempt.
 * Profile: -O2 -G0 -ffunction-sections.
 * US: 1208 versus 1164; graph traversal stack/register allocation, mixed global access and vector construction differ.
 * All carrying placements checked in us, us2 and pal; no candidate.
 * Tried scalar/TI versus union vectors, pointer grouping, expression/control flow
 * spelling, and applicable qualified copy profiles. Reopen with a demonstrated
 * scheduling or symbol declaration remedy; do not infer handwritten assembly.
 */

typedef int TI128 __attribute__((mode(TI)));
extern void func_00282A88(void *, int);
extern int D_L02_001B36A4;
extern char *D_L02_001FF1C0[];
extern float func_00282E48(void *, void *);
extern float func_00282E80(const void *, const void *);
extern int func_L02_00349BD8(int, int, int *, int *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282D30(void *, void *, float);

typedef struct L02RegionLink {
    int index;
    unsigned char neighbors[4];
    unsigned char edges[4];
    int unused;
    TI128 center;
} L02RegionLink;

extern void func_00282C88(void *);

int func_L02_0032E508(void *unused, int start, L02RegionLink *regions, int capacity) {
    unsigned char visited[256];
    TI128 center;
    int edgeA, edgeB, connectionA, connectionB;
    int count = 0, depth = 1, changed, i, j, k;
    char *polygon;
    float distance;
    func_00282A88(visited, 256);
    visited[start] = depth;
    do {
        changed = 0;
        for (i = 0; i < D_L02_001B36A4; ++i) {
            if (visited[i] == depth && count < capacity) {
                regions[count++].index = i;
                for (j = 0; j < D_L02_001B36A4; ++j) {
                    if (i != j && visited[j] == 0) {
                        polygon = D_L02_001FF1C0[j];
                        if (*(int *)polygon <= 64 && func_00282E48(polygon + 0x10, polygon + (*(int *)polygon << 4)) <= 0.2f) {
                            if (func_L02_00349BD8(i, j, &edgeA, &edgeB)) {
                                visited[j] = depth + 1;
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
        ++depth;
    } while (changed && depth < 32);
    for (i = 0; i < count; ++i)
        for (j = 3; j >= 0; --j) regions[i].neighbors[j] = 0xFF;
    for (i = 0; i < count; ++i) {
        for (j = i + 1; j < count; ++j) {
            if (func_L02_00349BD8(regions[i].index, regions[j].index, &connectionA, &connectionB)) {
                *(int *)(D_L02_001FF1C0[regions[i].index] + (connectionA << 4) + 0x1C) = 0;
                *(int *)(D_L02_001FF1C0[regions[j].index] + (connectionB << 4) + 0x1C) = 0;
                for (k = 0; k < 4; ++k) {
                    if (regions[i].neighbors[k] == 0xFF) {
                        regions[i].neighbors[k] = j;
                        regions[i].edges[k] = connectionA;
                        break;
                    }
                }
                for (k = 0; k < 4; ++k) {
                    if (regions[j].neighbors[k] == 0xFF) {
                        regions[j].neighbors[k] = i;
                        regions[j].edges[k] = connectionB;
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; ++i) {
        polygon = D_L02_001FF1C0[regions[i].index];
        func_00282C88(&center);
        for (j = 0; j < *(int *)polygon; ++j)
            func_00282CC0(&center, &center, polygon + (j << 4) + 0x10);
        func_00282D30(&center, &center, 1.0f / (float)*(int *)polygon);
        ((float *)&center)[3] = 0.0f;
        for (j = 0; j < *(int *)polygon; ++j) {
            distance = func_00282E80(&center, polygon + (j << 4) + 0x10);
            if (((float *)&center)[3] < distance) ((float *)&center)[3] = distance;
        }
        regions[i].center = center;
    }
    return count;
}
