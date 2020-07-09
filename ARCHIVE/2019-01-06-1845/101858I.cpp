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

T dot (pt a, pt b) { return a.x*b.x + a.y*b.y; }

ld angle (pt a, pt b) {
	ld cosTheta = dot (a, b)/(abs (a)*abs(b));
	return acos (max ((ld)-1.0, min ((ld)1.0, cosTheta)));
}

T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

// (+, 0, -) -> (left turn, collinear, right turn)
T orient (pt a, pt b, pt c) { return cross (b-a, c-a); }

pt perp (pt a) { return {-a.y, a.x}; }

struct line {
	pt v; T c;

	line (pt _v, T _c) : v(_v), c(_c) {}
	// From a*x + b*y = c
	line (T a, T b, T _c) : v({b, -a}), c(_c) {}
	// Line from point p to q ("line orientation")
	line (pt p, pt q) : v(q-p), c(cross (v, p)) {}

	// T as ll
	T side (pt p) { return cross (v, p) - c; }
	ld dist (pt p) { return abs (side (p)) / abs (v); }
	ld sqDist (pt p) {return (side (p)*side(p)) / (ld)sq(v);}
	line perpThrough (pt p) { return {p, p + perp (v)}; }
	// Compare points by projection on the line:
	bool cmpProj (pt p, pt q) { return dot (v, p) < dot (v, q); }
	line translate (pt t) { return {v, c+cross(v, t)};}
	// T as ld
	line shiftLeft (ld dist) { return {v, c+dist*abs(v)}; }
	pt proj (pt p) { return p - ((perp (v)*side (v))/sq (v)); }
	pt refl (pt p) { return p - ((perp (v)*2*side (v))/sq (v)); }
};

bool inter (line l1, line l2, pt &out) {
	T d = cross (l1.v, l2.v);
	if (cmp (d) == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // Require ld

	return true;
}

bool interSeg (pt a, pt b, line l1, line l2, pt &out) {
	if (!inter (l1, l2, out) or
		out == a or out == b)
		return false;
	pt x = {min (a.x, b.x), max (a.x, b.x)};
	pt y = {min (a.y, b.y), max (a.y, b.y)};
	if (out.x < x.x or out.x > x.y or
		out.y < y.x or out.y > y.y)
		return false;
	return true;
}

////////////////////////// Solution starts below. //////////////////////////////

int m[3];
int n;
vector<pt> pol[3];

vector<pt> readPol (int q) {
	vector<pt> vec;
	for (int i = 0; i < q; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
	}
	
	vec.push_back (vec[0]);
	
	return vec;
}

bool inside (vector<pt> vec, pt p) {
	line horiz = {(pt){p.x, p.y - 1}, p};
	
	vector<ld> vals;
	for (int i = 1; i < len(vec); i++) {
		pt out = {-1, -1};
		if (interSeg (vec[i-1], vec[i], {vec[i-1], vec[i]}, horiz, out)) {
			int vCmp = cmp (out.x, p.x);
			if (vCmp == 0)
				return true;
			else if (vCmp == -1)
				vals.push_back (out.x);
		}
	}
	
	sort (vals.begin(), vals.end());
	int q = 0;
	ld bef = -(1e18);
	for (int i = 0; i < len (vals); i++)
		if (cmp (bef, vals[i]) != 0) {
			++q;
			bef = vals[i];
		}
	
	return q&1;
}

int main ()
{
	for (int i = 0; i < 3; i++)
		scanf ("%d", &m[i]);

	for (int i = 0; i < 3; i++)
		pol[i] = readPol (m[i]);

	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		
		if (inside (pol[0], {x, y}))
			printf ("Sheena\n");
		else if (inside (pol[1], {x, y}))
			printf ("Rose\n");
		else if (inside (pol[2], {x, y}))
			printf ("Maria\n");
		else
			printf ("Outside\n");
	}

	return 0;
}
