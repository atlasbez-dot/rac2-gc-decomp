/*
 * Retained handwritten near miss; historical evidence only.
 * No linked-image equality or complete retail semantics is established.
 * Compiler: game EE-GCC 2.9-ee-991111b (project profile).
 * Profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * Reported final C / retail: 5696 / 5868 bytes; size equality is not a match.
 * us: 0/1 placements; 5696/5868 bytes.
 * us2: 0/1 placements; 5696/5868 bytes.
 * pal: absent from catalogue (not a match).
 * Residual: Final5696/5868bytes,frame0x460vs0x440,firstmismatch+0;scheduling/register/source-shape differences.
 * Reopening condition: Demonstrated frame/register-allocation or original temporary-lifetime source shape remedy; noISAorcatalogueblockerclaimed.
 * Where listed, tools/check.py measurements predate retention; no compilation was rerun for this copy.
 */

/* Unmatched complete manual reconstruction of the two-target arc and four trails.
 * Retained profile: -O2 -G8 -ffunction-sections -frac2-qcopy.
 * Final US and US2: 5696 bytes versus 5868, 0/1 placements, exit 1.
 * PAL has no entry for this canonical function. First mismatch is +0;
 * frame 0x460 versus retail 0x440, with scheduling/allocation differences.
 * Seven bounded trials covered normal G8 (5392), qcopy (5560), qcopy-barrier
 * (5552), explicit target-damage blocks (5672), live configuration reloads
 * (5736), reused dead target temporaries (5696), and nested packet scopes (5704).
 * The retained form keeps ordered floating comparisons, fresh configuration
 * reads after helper calls, and the full measured contact/vector/trail extents.
 * R5900 mult/madd results are ordinary array index/address arithmetic; no stale
 * HI input, manufactured aliases, assembly, output patches, or register pins.
 * AB1F0's canonical signed 32-bit word is explicitly interpreted as a nullable
 * data pointer where retail dereferences it. 77F48 returns a 32-bit count;
 * C2210 returns an object pointer and consumes three FP plus seven GPR inputs.
 * Packet records are partial measured layouts, not claims of original names.
 * The remaining obstacle is source shape and temporary lifetime. Reopen with a
 * demonstrated frame/register-allocation remedy. Behavior and linked-image
 * equality remain unverified; no exact-C credit is claimed.
 */
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int TI128 __attribute__((mode(TI)));
typedef struct { int a,b,c,d; } __attribute__((aligned(16))) Quad16;
typedef union { TI128 q; float v[4]; } Vector;
typedef struct {
    Vector normal;
    int owner, mask;
    unsigned char kind, subtype;
    unsigned short class_id;
    float amount;
    int enabled;
} ContactPacket;
extern unsigned char D_0013957A;
extern char D_00189E20[];
extern char *D_0018C0B0;
extern char *D_L01_001FB3E0[];
extern unsigned char D_L01_002637A0[][0xE0];
extern int D_L01_001A9030[];
extern Vector D_L01_001B94C0;
extern float D_L01_001B94D8[];
extern short D_L01_001B2E00[];
extern short D_L01_001B2E08[4], D_L01_001B2E10[4], D_L01_001B2E18[4], D_L01_001B2E20[4];
extern char *D_L01_001BF918;
extern Vector D_L01_001BF920;
extern Vector D_L01_0023A050[20], D_L01_0023A190[20];
extern float D_L01_0023A2D0[20], D_L01_0023A460[20];
extern Vector D_L01_0023A320[20], D_L01_0023A4B0[4][5];
extern Vector D_L01_001A8F60;
extern float D_L01_001AF094 __attribute__((sda));
extern float D_L01_001AF098 __attribute__((sda));
extern float D_L01_001AF09C __attribute__((sda));
extern float D_L01_001AF0A0 __attribute__((sda));
extern float D_L01_001AF0A4 __attribute__((sda));
extern float D_L01_001AF0A8 __attribute__((sda));
extern float D_L01_001AF0AC __attribute__((sda));
extern float D_L01_001AF0B0 __attribute__((sda));
extern float D_L01_001AF0B4 __attribute__((sda));
extern float D_L01_001AF0B8 __attribute__((sda));
extern float D_L01_001AF0BC __attribute__((sda));
extern float D_L01_001AF0C0 __attribute__((sda));
extern float D_L01_001AF0C4 __attribute__((sda));
extern float D_L01_001AF0C8 __attribute__((sda));
extern float D_L01_001AF0CC __attribute__((sda));
extern float D_L01_001AF0D0 __attribute__((sda));
extern float D_L01_001AF0E4 __attribute__((sda));
extern float D_L01_001AF0E8 __attribute__((sda));
extern u32 D_L01_001AF0F8 __attribute__((sda));
extern float D_L01_001AF128 __attribute__((sda));
extern float D_L01_001AF12C __attribute__((sda));
extern int func_002AB1F0(unsigned char *);
extern void func_00282C88(TI128 *);
extern void func_00282CC0(void *,void *,void *),func_00282CF0(void *,void *,void *);
extern void func_00282D08(void *,void *,void *,float),func_00282D30(void *,void *,float);
extern float func_00282DB0(void *,void *),func_00282DF0(void *),func_00282E20(void *),func_00282E48(void *,void *);
extern void func_00282DD8(void *,void *,void *),func_00282F20(void *,void *,float);
extern float func_00283180(float),func_00283198(float),func_002831B0(float),func_00283248(float,float);
extern float func_00283B98(float,float),func_00283BE0(float,float),func_00283C80(float,float),func_00283CE0(int);
extern int func_00283CF0(float),func_00282948(void *),func_00282978(void *);
extern int func_002A77E0(int),func_002A7820(int,int);
extern float func_002A7878(float,float),func_002A78D8(float,float),func_002ABB18(float);
extern void func_002A8C00(char *,int,int,float,Quad16 *);
extern void func_002A8E20(void *,void *);
extern void func_002ACEC0(void *,void *,void *,float);
extern void func_00300190(void *,void *);
extern int func_002761F8(void *,void *,int,void *,int);
extern int func_00277F48(void *,int,void *,void *,float);
extern void *func_002C2210(void *,int,u32,int,int,void *,int,float,float,float);
#define I(p,o) (*(int *)((char *)(p)+(o)))
#define F(p,o) (*(float *)((char *)(p)+(o)))
#define H(p,o) (*(short *)((char *)(p)+(o)))
#define U(p,o) (*(unsigned short *)((char *)(p)+(o)))
#define P(p,o) (*(char **)((char *)(p)+(o)))

void func_L01_00388FD0(unsigned char *object)
{
    Vector first_target, second_target, direction, cross;
    Vector blended, tangent, target_delta, temporary, offset, previous_offsets[4];
    ContactPacket packet, first_packet, second_packet;
    char *ignored[128];
    char *context = P(object,0x68), *candidate, *best = 0, *runner_up = 0, *data, *hit;
    char **scan;
    Vector *point, *branch;
    float best_score = 0.0f, second_score = 0.0f;
    float segment_length = D_L01_001AF094, first_distance = 0.0f;
    float distance, camera_angle, player_angle, score, a, b, c, amplitude, jitter, amount, blend, sign;
    int enabled, i, j, k, hit_segment = 0, ignored_count = 0, segments, index, life;
    enabled = D_L01_002637A0[D_0013957A][4] != 0;
    D_L01_001AF0AC = func_00283B98(D_L01_001AF0AC,D_L01_001AF0B0);
    D_L01_001AF0B4 = func_00283BE0(D_L01_001AF0B4,D_L01_001AF0B8);
    D_L01_001AF0C8 = func_00283B98(D_L01_001AF0C8,D_L01_001AF0CC);
    if (!P(context,0x20) || (enabled && !P(context,0x38))) {
        if (P(context,0x38)) {
            P(context,0x20) = P(context,0x38);
            H(context,0x40) = H(context,0x42);
            P(context,0x38) = 0;
            H(context,0x42) = 0;
        } else {
            for (scan = D_L01_001FB3E0; *scan; ++scan) {
                candidate = *scan;
                if (candidate == P(context,0x20) || candidate == P(context,0x38) ||
                    !P(candidate,0x24) || H(P(candidate,0x24),0x46) != 5 ||
                    (unsigned char)candidate[0x20] == 0xFE || (unsigned char)candidate[0x20] == 0xFD ||
                    !func_002AB1F0((unsigned char *)candidate)) continue;
                func_00282CF0(&first_target,candidate+0x10,context);
                if (!D_L01_001A9030[0]) distance = func_00282E20(&first_target);
                else {
                    amount = func_00282DB0(&first_target,D_0018C0B0+0xE0);
                    func_00282D30(&second_target,D_0018C0B0+0xE0,amount);
                    func_00282CF0(&temporary,&first_target,&second_target);
                    distance = func_00282DF0(&temporary);
                }
                if (!(distance <= D_L01_001AF094)) continue;
                a = func_00283248(F(candidate,0x10)-D_L01_001B94C0.v[0],F(candidate,0x14)-D_L01_001B94C0.v[1]);
                camera_angle = func_00283C80(D_L01_001B94D8[0],a);
                if (!(camera_angle <= D_L01_001AF09C)) continue;
                player_angle = 0.0f;
                if (!D_L01_001A9030[0]) {
                    a = func_00283248(F(candidate,0x10)-F(D_00189E20,0x80),F(candidate,0x14)-F(D_00189E20,0x84));
                    player_angle = func_00283C80(a,F(D_00189E20,0x98));
                } else {
                    func_00282CF0(&second_target,candidate+0x10,D_00189E20+0x80);
                    a = func_00282DB0(&second_target,D_0018C0B0+0xE0);
                    func_00282D30(&temporary,D_0018C0B0+0xE0,a);
                    func_00282CF0(&second_target,&second_target,&temporary);
                    a = func_00282DB0(&second_target,D_0018C0B0+0xC0);
                    b = func_00282DF0(&second_target);
                    if (b == 0.0f) continue;
                    player_angle = 1.5707964f-func_002831B0(a/b);
                }
                if (!(player_angle <= D_L01_001AF098)) continue;
                score = ((D_L01_001AF09C-camera_angle)/D_L01_001AF09C)*D_L01_001AF12C +
                    (D_L01_001AF094-distance)/D_L01_001AF094;
                if (score > best_score) {
                    runner_up = best; second_score = best_score;
                    best = candidate; best_score = score;
                } else if (!(score <= second_score)) { runner_up = candidate; second_score = score; }
            }
        }
    }
    if (best) {
        if (!P(context,0x20)) {
            H(context,0x40) = 0; P(context,0x20) = best;
            if (func_00282948(D_L01_001B2E00)) D_L01_001B2E00[0] = 10;
        } else runner_up = best;
    }
    if (runner_up && enabled) {
        distance = func_00282E48(context,best+0x10);
        if (distance < D_L01_001AF094 && distance+func_00282E48(best+0x10,runner_up+0x10) < D_L01_001AF094) {
            H(context,0x42) = 0; P(context,0x38) = runner_up;
        }
    }
    if (P(context,0x20)) {
        hit = P(context,0x20);
        data = (char *)func_002AB1F0((unsigned char *)hit);
        first_target.q = *(TI128 *)(hit+0x10);
        func_00282D30(&second_target,hit+0xE0,F(data,0x10));
        func_00282CC0(&first_target,&first_target,&second_target);
        first_distance = func_00282E48(context,&first_target);
        segment_length = first_distance;
    }
    if (P(context,0x38)) {
        hit = P(context,0x38);
        data = (char *)func_002AB1F0((unsigned char *)hit);
        second_target.q = *(TI128 *)(hit+0x10);
        func_00282D30(&temporary,hit+0xE0,F(data,0x10));
        func_00282CC0(&second_target,&second_target,&temporary);
        segment_length = first_distance+func_00282E48(&first_target,&second_target);
    }
    segment_length *= 0.05f;
    D_L01_001AF0F8 = enabled ? 0x207F20 : 0x7F2020;
    func_00282C88(&temporary.q);
    func_002A8C00((char *)&packet,(int)object,0x210000,F(D_L01_002637A0[D_0013957A],0x70),(Quad16 *)&temporary);
    packet.class_id = U(object,0xAA); packet.subtype = 1; packet.kind = 5;
    H(context,0x3E) = 20;
    func_00277F48(context,0x10,D_0018C0B0,&packet,0.3f);
    func_00282CF0(&direction,context+0x10,context);
    func_00282F20(&direction,&direction,1.0f);
    if (P(context,0x20) || P(context,0x38)) {
        func_00282DD8(&cross,&direction,D_00189E20+0x2C0);
        func_002ACEC0(&direction,&direction,&cross,0.17453295f);
    }
    func_00282D30(&tangent,&direction,segment_length);
    D_L01_0023A050[0].q = *(TI128 *)context;
    D_L01_0023A190[0].q = *(TI128 *)context;
    for (i=1; i<20; ++i) {
        point = &D_L01_0023A050[i]; branch = &D_L01_0023A190[i];
        a = func_00283CE0(i);
        amplitude = D_L01_001AF0A4+(D_L01_001AF0A8-D_L01_001AF0A4)*a*0.05f;
        a = func_002ABB18(D_L01_001AF0AC+(float)i*D_L01_001AF0A0);
        b = func_00283198(a);
        jitter = amplitude*b+func_002A78D8(D_L01_001AF0E4,D_L01_001AF0E8);
        a = D_L01_0023A2D0[i]; D_L01_0023A2D0[i] = jitter; point->v[2] -= a;
        func_00300190(point,point);
        func_00282CF0(&cross,point,&D_L01_0023A050[i-1]);
        func_00282D08(&blended,&cross,&tangent,0.85f);
        distance = func_00282DF0(&blended);
        if (distance == 0.0f) point->q = D_L01_0023A050[i-1].q;
        else {
            func_00282D30(&blended,&blended,segment_length/distance);
            func_00282CC0(point,&D_L01_0023A050[i-1],&blended);
            tangent.q = blended.q;
        }
        point->v[2] += jitter;
        func_00282CF0(&cross,point,&D_L01_0023A050[i-1]);
        if (P(context,0x20)) {
            if (!enabled || !P(context,0x38)) {
                func_00282CF0(&target_delta,&first_target,point);
                distance = func_00282DF0(&target_delta);
                if (distance != 0.0f) {
                    if (i==19) { blend=0.5f; segment_length=distance; }
                    else if (i<16) blend=0.10000001f;
                    else { blend=0.5f; segment_length=distance/func_00283CE0(19-i); }
                    func_00282D30(&target_delta,&target_delta,segment_length/distance);
                    func_00282D08(&tangent,&tangent,&target_delta,blend);
                }
            } else {
                func_00282CF0(&target_delta,i<10 ? &first_target : &second_target,point);
                distance=func_00282DF0(&target_delta);
                if (distance != 0.0f) {
                    if (i==9 || i==19) { blend=0.7f; segment_length=distance; }
                    else if ((unsigned)(i-5)<5 || i>14) {
                        blend=0.7f; segment_length=distance/func_00283CE0(i<10 ? 9-i : 19-i);
                    } else blend=0.2f;
                    func_00282D30(&target_delta,&target_delta,segment_length/distance);
                    func_00282D08(&tangent,&tangent,&target_delta,blend);
                }
            }
        }
        branch->q = point->q;
        if (i<10) {
            a=func_002ABB18(D_L01_001AF0B4+(float)i*D_L01_001AF0BC);
            b=func_002ABB18(D_L01_001AF0C8+(float)i*D_L01_001AF0D0);
            b=func_00283198(b)*D_L01_001AF0C0;
            c=func_00283198(a);
            jitter=b*c+func_002A78D8(0.0f,0.1f);
            D_L01_0023A460[i]=jitter; branch->v[2]+=jitter;
            b=func_00283B98(func_00283248(cross.v[0],cross.v[1]),1.5707965f);
            c=func_00283180(a)*D_L01_001AF0C4;
            offset.v[0]=func_00283180(b)*c; offset.v[1]=func_00283198(b)*c; offset.v[2]=0.0f;
            D_L01_0023A320[i].q=offset.q;
            func_00282CC0(branch,branch,&offset);
        } else {
            branch->v[2]+=D_L01_0023A460[21-i];
            func_00282CC0(branch,branch,&D_L01_0023A320[21-i]);
            offset.q=D_L01_0023A320[i].q;
        }
        if (i>1 && (i==19 || !(i&1))) {
            func_00282CF0(&temporary,point,&D_L01_001B94C0);
            if (!D_L01_001A9030[0]) temporary.v[2]=0.0f;
            else {
                a=func_00282DB0(&temporary,D_0018C0B0+0xE0);
                func_00282D30(&target_delta,D_0018C0B0+0xE0,a);
                func_00282CF0(&temporary,&temporary,&target_delta);
            }
            distance=func_00282DF0(&temporary);
            if (distance==0.0f) temporary.v[2]=1.0f;
            else func_00282D30(&temporary,&temporary,1.0f/distance);
            temporary.v[3]=5627.9248046875f;
            packet.normal=temporary;
            hit_segment=func_002761F8(&D_L01_0023A050[i-2],point,0x10,object,0);
            if (hit_segment) {
                hit=D_L01_001BF918;
                if (hit) {
                    if (!func_002AB1F0((unsigned char *)hit) || !P(hit,0x24) || H(P(hit,0x24),0x46)!=5)
                        func_002A8E20(hit,&packet);
                    else { hit_segment=0; ignored[ignored_count++]=hit; I(hit,0x98)=0; }
                }
                if (hit_segment) {
                    point->q=D_L01_001BF920.q;
                    H(context,0x3E)=i;
                    *(TI128 *)(context+0x10)=D_L01_001BF920.q;
                    if (!D_L01_001BF918) { P(context,0x20)=0; H(context,0x40)=0; }
                    break;
                }
            }
        }
    }
    for (j=0;j<ignored_count;++j) I(ignored[j],0x98)=I(P(ignored[j],0x24),0x10);
    if (!hit_segment) *(TI128 *)(context+0x10)=D_L01_0023A050[19].q;
    hit=P(context,0x20);
    if (hit && !U(context,0x40) && !U(context,0x44)) {
        func_00282CF0(&target_delta,hit+0x10,&D_L01_001B94C0);
        if (!D_L01_001A9030[0]) target_delta.v[2]=0.0f;
        else {
            a=func_00282DB0(&target_delta,D_0018C0B0+0xE0);
            func_00282D30(&second_packet.normal,D_0018C0B0+0xE0,a);
            func_00282CF0(&target_delta,&target_delta,&second_packet.normal);
        }
        func_00282F20(&target_delta,&target_delta,1.0f);
        target_delta.v[3]=5627.9248046875f;
        func_002A8C00((char *)&first_packet,(int)object,0x210000,F(D_L01_002637A0[D_0013957A],0x70),(Quad16 *)&target_delta);
        first_packet.class_id=U(object,0xAA); first_packet.subtype=3; first_packet.kind=5;
        func_002A8E20(hit,&first_packet);
        data=(char *)func_002AB1F0((unsigned char *)hit);
        H(context,0x44)=data && H(data,4)==1 ? 1 : 5;
    }
    hit=P(context,0x38);
    if (hit && !U(context,0x42) && !U(context,0x46)) {
        func_00282CF0(&target_delta,hit+0x10,&D_L01_001B94C0);
        if (!D_L01_001A9030[0]) target_delta.v[2]=0.0f;
        else {
            a=func_00282DB0(&target_delta,D_0018C0B0+0xE0);
            func_00282D30(&second_packet.normal,D_0018C0B0+0xE0,a);
            func_00282CF0(&target_delta,&target_delta,&second_packet.normal);
        }
        func_00282F20(&target_delta,&target_delta,1.0f);
        target_delta.v[3]=5627.9248046875f;
        func_002A8C00((char *)&second_packet,(int)object,0x210000,F(D_L01_002637A0[D_0013957A],0x70),(Quad16 *)&target_delta);
        second_packet.class_id=U(object,0xAA); second_packet.subtype=3; second_packet.kind=5;
        func_002A8E20(hit,&second_packet);
        data=(char *)func_002AB1F0((unsigned char *)hit);
        H(context,0x46)=data && H(data,4)==1 ? 1 : 5;
    }
    for (i=0;i<4;++i) {
        if (i<2) { second_packet.normal.q=*(TI128 *)context; amount=0.4f; }
        else { second_packet.normal.q=*(TI128 *)(context+0x10); amount=0.5f; }
        if (!func_00282978(&D_L01_001B2E08[i])) {
            for (j=0;j<4;++j) {
                func_00282CF0(&previous_offsets[j],&D_L01_0023A4B0[i][j+1],&D_L01_0023A4B0[i][j]);
                previous_offsets[j].v[0]+=func_002A78D8(0.0f,0.1f);
                previous_offsets[j].v[1]+=func_002A78D8(0.0f,0.1f);
                previous_offsets[j].v[2]+=func_002A78D8(0.0f,0.1f);
            }
            D_L01_0023A4B0[i][0].q=second_packet.normal.q;
            for (j=0;j<4;++j) func_00282CC0(&D_L01_0023A4B0[i][j+1],&D_L01_0023A4B0[i][j],&previous_offsets[j]);
            index=D_L01_001B2E08[i]-D_L01_001B2E20[i]; if (index<0) index=-index;
            a=func_00283CE0(index); b=func_00283CE0(15);
            D_L01_001B2E10[i]=func_00283CF0((1.0f-a/b)*32.0f);
        } else {
            D_L01_001B2E08[i]=D_L01_001B2E18[i]; D_L01_001B2E10[i]=0;
            a=func_002A78D8(0.52359885f,1.0471977f);
            b=func_002A7878(-1.0471977f,0.17453295f);
            func_00282D30(&target_delta,&direction,amount);
            func_002ACEC0(&target_delta,&target_delta,D_00189E20+0x740,b);
            func_002ACEC0(&target_delta,&target_delta,D_00189E20+0x750,a);
            D_L01_0023A4B0[i][0].q=second_packet.normal.q;
            func_00282CC0(&D_L01_0023A4B0[i][1],&second_packet.normal,&target_delta);
            sign=1.0f;
            for (j=0;j<3;++j) {
                func_00282CF0(&first_packet,&D_L01_0023A4B0[i][j+1],&D_L01_001B94C0);
                a=func_002A7878(0.17453295f,0.9599312f)*sign; sign=-sign;
                func_002ACEC0(&target_delta,&target_delta,&first_packet,a);
                func_00282CC0(&D_L01_0023A4B0[i][j+2],&D_L01_0023A4B0[i][j+1],&target_delta);
            }
        }
    }
    a=func_002A78D8(0.52359885f,1.0471977f);
    b=func_002A7878(-0.52359885f,1.0471977f);
    func_00282D30(&target_delta,&direction,D_L01_001AF128);
    func_002ACEC0(&target_delta,&target_delta,D_00189E20+0x740,b);
    func_002ACEC0(&target_delta,&target_delta,D_00189E20+0x750,a);
    life=func_002A7820(1,8); if (func_002A77E0(2)) life=-life;
    a=func_002A7878(0.2f,0.6f);
    func_002C2210(context,15,D_L01_001AF0F8|0x7F000000,0,life,&target_delta,1,a*0.3f,a,0.0f);
    func_002C2210(context,15,0x307F7F7F,0,-life,&target_delta,1,a*0.15f,a*0.5f,0.0f);
    life=func_002A7820(1,8); if (func_002A77E0(2)) life=-life;
    a=func_002A7878(0.15f,3.0f);
    func_002C2210(context+0x10,12,D_L01_001AF0F8|0x7F000000,0,life,&D_L01_001A8F60,1,a*0.1f,a,0.0f);
}
