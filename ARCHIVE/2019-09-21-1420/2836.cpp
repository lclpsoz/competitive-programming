#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int T = 8 * (1e5 + 1), N = 2e5 + 10;

int n;
vector<int> seg[T];
vector<int> mp[N];
vector<pair<pii, pii>> rects;
vector<int> compX, compY;

bool check (vector<int> &vec, int y1, int y2) {
    return (upper_bound (vec.begin(), vec.end(), y2) - lower_bound (vec.begin(), vec.end(), y1)) != 0;
}

void build (int t, int tl, int tr) {
//     printf ("t = %d, tl = %d, tr = %d\n", t, tl, tr);
    if (tl == tr) {
        for (int v : mp[tl])
            seg[t].push_back (v);
        sort (seg[t].begin(), seg[t].end());
    } else {
        int md = (tl+tr)/2;
        build (2*t, tl, md);
        build (2*t + 1, md+1, tr);
        int p1 = 0, p2 = 0;
        vector<int> &v = seg[t];
        vector<int> &v1 = seg[2*t];
        vector<int> &v2 = seg[2*t + 1];
        while (p1 < len (v1) and p2 < len (v2)) {
            if (v1[p1] < v2[p2])
                v.push_back (v1[p1++]);
            else
                v.push_back (v2[p2++]);
        }
        while (p1 < len (v1)) v.push_back (v1[p1++]);
        while (p2 < len (v2)) v.push_back (v2[p2++]);
//         sort (seg[t].begin(), seg[t].end());
    }
}

bool qry (int t, int tl, int tr, int x1, int y1, int x2, int y2) {
//     printf ("x1 = %d, x2 = %d\n", x1, x2);
    if (x1 <= tl and tr <= x2)
        return check (seg[t], y1, y2);
    else {
        int md = (tl + tr) / 2;
        if (x1 <= md and x2 >= tl and qry (2*t, tl, md, x1, y1, x2, y2)) return true;
        if (x1 <= tr and x2 >= md+1 and qry (2*t + 1, md + 1, tr, x1, y1, x2, y2)) return true;
    }
    
    return false;
}

int main () {
    scanf ("%d", &n);
    while (n--) {
        int x1, y1, x2, y2;
        scanf ("%d %d %d %d", &x1, &y1, &x2, &y2);
        rects.push_back ({{x1, y1}, {x2, y2}});
        compX.push_back (x1);
        compX.push_back (x2);
        compY.push_back (y1);
        compY.push_back (y2);
    }
    sort (compX.begin(), compX.end());
    compX.resize (unique (compX.begin(), compX.end()) - compX.begin());
    int xMax = -1;
    for (auto &p : rects) {
        p.x.x = lower_bound (compX.begin(), compX.end(), p.x.x) - compX.begin();
        p.y.x = lower_bound (compX.begin(), compX.end(), p.y.x) - compX.begin();
        mp[p.x.x].push_back (p.x.y);
        xMax = max (max (p.x.x, p.y.x), xMax);
    }
    
    build (1, 1, xMax);
    
    int ans = 0;
    for (auto p : rects)
        ans += !qry (1, 1, xMax, p.x.x, p.x.y, p.y.x, p.y.y);
    printf ("%d\n", ans);

	return 0;
}
