#include<bits/stdc++.h>
using namespace std;

// ----------------
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

// ----------------

using T = ld;

struct pt {
	T x, y;
	
	pt operator* (T v) { return {x*v, y*v}; }
	pt operator/ (T v) { return {x/v, y/v}; }
}

struct line {
	pt v, T c;
	line (pt a, pt q) : v (q-p), c(cross (v, p)) {}
};

T orient (pt a, pt b, pt c) { return a.x*b.y - a.y*b.x; }

T cross (pt a, pt b) { return a.x*b.x

bool properInter (pt a, pt b, pt c, pt d, pt &out) {
	T oa = orient (c, d, a),
	ob = orient (c, d, b),
	oc = orient (a, b, c),
	od = orient (a, b, d);
	
	if (oa*ob < 0 and oc*od < 0) {
		out = (a*ob - b*oa) / (ob-oa);
		return true;
	}
	return false;
}

set<pt> inters (pt a, pt b, pt c, pt d) {
	pt out;
	if (properInter (a, b, c, d, out)) return {out};
	set<pt> s;
	if (onSegment (c, d, a)) s.insert (a);
	if (onSegment (c, d, b)) s.insert (b);
	if (onSegment (a, b, c)) s.insert (c);
	if (onSegment (a, b, d)) s.insert (d);

	return s;
}

bool inDisk (pt a, pt b, pt p) {
	return dot (a-p, b-p) <= 0;
}

bool onSegment (pt a, pt b, pt p) {
	return orient (a, b, p) == 0 and inDisk (a, b, p);
}

bool inter (line l1, line l2, pt &out) {
	T d = cross (l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d;
	
	return true;
}


int main () {
	int n;
	scanf ("%d", &n);
	vector<pt> vec;
	while (n--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
	}
	
	
	
	return 0;
}
