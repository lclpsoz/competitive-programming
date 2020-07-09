#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size()) // Be careful with spaces!!!
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

//////////////////////// GEOMETRY ////////////////////////

using T = ld;

struct pt {
	T x, y;

	pt operator+ (pt p) {return {x+p.x, y+p.y};}
	pt operator- (pt p) {return {x-p.x, y-p.y};}
	pt operator* (T v) {return {x*v, y*v};}
	pt operator/ (T v) {return {x/v, y/v};}

	bool operator== (pt p) {return make_pair (x, y) == make_pair (p.x, p.y);}
	bool operator!= (pt p) {return !(operator==(p));}

};

T sq (pt p) {return p.x*p.x + p.y*p.y;}
ld abs (pt p) {return sqrt ((ld)sq (p));}

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << ", " << p.y << ")";
}


T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }


struct line {
	pt v; T c;

	line (T a, T b, T _c) : v({b, -a}), c(_c) {}
	line (pt p, pt q) : v(q-p), c(cross (v, p)) {}

};

bool inter (line l1, line l2, pt &out) {
	T d = cross (l1.v, l2.v);
	if (cmp (d) == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // Require ld

	return true;
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
pt st, en;

int main ()
{
    int n;
    scanf ("%Lf %Lf", &st.x, &st.y);
    scanf ("%Lf %Lf", &en.x, &en.y);
    scanf ("%d", &n);
    int ans = 0;
    ld minX, maxX, minY, maxY;
    minX = min (st.x, en.x);
    maxX = max (st.x, en.x);
    minY = min (st.y, en.y);
    maxY = max (st.y, en.y);
    
    line base = {en, st};
    
    for (int i = 1; i <= n; i++) {
        ld a, b, c;
        scanf ("%Lf %Lf %Lf", &a, &b, &c);
        line l = {a, b, -c};
        pt out;
        inter (base, l, out);
        if (cmp (out.x, minX) >= 0 and cmp (out.x, maxX) <= 0 and
            cmp (out.y, minY) >= 0 and cmp (out.y, maxY) <= 0)
            ++ans;
    }
    
    printf ("%d\n", ans);

	return 0;
}
