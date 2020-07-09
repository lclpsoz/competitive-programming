#include<bits/stdc++.h>
using namespace std;

// -----------
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp (ld x, ld y = 0, ld tol = EPS) {
    return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
    return (int)(((x%m) + m)%m);
}
// -----------

using T = ll;

struct pt {
    T x, y;
    
    pt operator+ (pt p) {return {x+p.x, y+p.y};}
    pt operator- (pt p) {return {x-p.x, y-p.y};}
};

ostream& operator<< (ostream& os, pt p) {
    return os << "(" << p.x << ", " << p.y << ")";
}

using segment = pair<pt, pt>;

int s, k, w;
vector<pt> kids;
vector<segment> walls;
int ans[15];

T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

T orient (pt a, pt b, pt c) { return cross (b-a, c-a); }

bool properInter (pt a, pt b, pt c, pt d) {
    T oa = orient (c, d, a);
    T ob = orient (c, d, b);
    T oc = orient (a, b, c);
    T od = orient (a, b, d);
//     cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
//     cout << "GER: " << oa << ' ' << ob << ' ' << oc << ' ' << od << '\n';
    if (oa < 0)
        oa = -1;
    else if (oa > 0)
        oa = 1;
    if (oc < 0)
        oc = -1;
    else if (oc > 0)
        oc = 1;
    if (oa*ob < 0 and oc*od < 0)
        return true;
    return false;
}

bool check (pt a, pt b) {
    segment look = {a, b};
    for (segment seg : walls)
        if (properInter (look.x, look.y, seg.x, seg.y)) {
//             printf ("%d %d %d %d\n", look.x.x, look.x.y, look.y.x, look.y.y);
//             printf ("seg: %d %d %d %d\n", seg.x.x, seg.x.y, seg.y.x, seg.y.y);
            return false;
        }
    return true;
}

int main () {
//     printf ("TEST: %d\n", properInter ({0, 0}, {1, 0}, {49, 49}, {50, 50}));
    while (scanf ("%d %d %d", &s, &k, &w) != EOF) {
        kids.clear();
        walls.clear();
        for (int i = 0; i < k; i++) {
            ll x, y;
            scanf ("%lld %lld", &x, &y);
            kids.push_back ({x, y});
        }
        
        while (w--) {
            ll x1, y1, x2, y2;
            scanf ("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);
            walls.push_back ({{x1, y1}, {x2, y2}});
        }
        
        for (int i = 0; i < s; i++) {
            int qnt = 0;
            for (int j = 0; j < k; j++)
                if (i != j)
                    qnt += check (kids[i], kids[j]);
            printf ("%d\n", qnt);
        }
    }
    
    return 0;
}
