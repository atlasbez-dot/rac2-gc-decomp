/* GNU game -O2 -G0, 1264/1200 bytes, us/us2/pal each 0/2 places.
 * Readable region flood fill, adjacency and bounding-sphere reconstruction.
 * One trial: extra loop/index code and a 0x1e0 frame instead of 0x1d0.
 * Reopen with typed region structures and the nested-loop allocation understood.
 */
typedef struct { float x, y, z, w; } RegionPoint;
typedef struct { int id; signed char links[4]; unsigned char edges[4]; int reserved; RegionPoint sphere; } RegionRecord;
typedef struct { int count; int reserved[3]; RegionPoint points[1]; } RegionGeometry;
extern RegionGeometry *D_L03_001FE700[];
extern void func_00282C88(void *);
extern void func_00282CC0(void *, void *, void *);
extern void func_00282A88(void *, int);
extern int func_L02_00349BD8(int, int, int *, int *);
extern void func_00282D30(void *, void *, float);
extern float func_00282E80(void *, void *);

int func_L03_00329EF0(void *unused, int *ids, RegionRecord *records, int capacity) {
    unsigned char depth[256];
    RegionPoint center;
    int pass = 1;
    int count = 0;
    int changed, i, j, edgeA, edgeB, k;
    int sourceEdge, targetEdge;
    RegionGeometry *geometry;
    RegionPoint *point;
    float distance;
    func_00282A88(depth, 0x100);
    depth[0] = pass;
    do {
        changed = 0;
        for (i = 0; i < capacity && count < capacity && ids[i] != -1; i++) {
            if (depth[i] == pass) {
                records[count++].id = ids[i];
                for (j = 0; j < capacity && ids[j] != -1; j++) {
                    if (j == i || depth[j])
                        continue;
                    if (func_L02_00349BD8(ids[i], ids[j], &sourceEdge, &targetEdge)) {
                        changed = 1;
                        depth[j] = pass + 1;
                    }
                }
            }
        }
        pass++;
    } while (changed && pass < 0x20);
    for (i = 0; i < count; i++)
        for (j = 3; j >= 0; j--)
            records[i].links[j] = -1;
    for (i = 0; i < count; i++) {
        for (j = i + 1; j < count; j++) {
            if (func_L02_00349BD8(records[i].id, records[j].id, &edgeA, &edgeB)) {
                D_L03_001FE700[records[i].id]->points[edgeA].w = 0;
                D_L03_001FE700[records[j].id]->points[edgeB].w = 0;
                for (k = 0; k < 4; k++) {
                    if (records[i].links[k] == -1) {
                        records[i].links[k] = j;
                        records[i].edges[k] = edgeA;
                        break;
                    }
                }
                for (k = 0; k < 4; k++) {
                    if (records[j].links[k] == -1) {
                        records[j].links[k] = i;
                        records[j].edges[k] = edgeB;
                        break;
                    }
                }
            }
        }
    }
    for (i = 0; i < count; i++) {
        geometry = D_L03_001FE700[records[i].id];
        func_00282C88(&center);
        point = geometry->points;
        for (j = 0; j < geometry->count; j++, point++)
            func_00282CC0(&center, &center, point);
        func_00282D30(&center, &center, 1.0f / (float)geometry->count);
        center.w = 0;
        point = geometry->points;
        for (j = 0; j < geometry->count; j++, point++) {
            distance = func_00282E80(&center, point);
            if (distance > center.w)
                center.w = distance;
        }
        records[i].sphere = center;
    }
    return count;
}
