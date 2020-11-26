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

////////////////////////// Solution starts below. //////////////////////////////

bool cmp (pt a, pt b) {
	return !(cmp (a.x, b.x) == 0 and cmp (a.y, b.y) == 0);
}

struct seg {
	pt a, b;
	line l = {a, b};
};

int mdc (int a, int b) {
	if (b == 0) return a;
	return mdc (b, a%b);
}

bool inSeg (pair<ll, ll> p, seg s) {
	int mnX, mnY, mxX, mxY;
	mnX = min (s.a.x, s.b.x);
	mxX = max (s.a.x, s.b.x);
	mnY = min (s.a.y, s.b.y);
	mxY = max (s.a.y, s.b.y);
	if (p.x < mnX or p.x > mxX
		or p.y < mnY or p.y > mxY)
		return false;
	return true;
}

int common (seg s1, seg s2, pt &out) {
	if (!inter (s1.l, s2.l, out))
		return 0;
	ll x = round (out.x);
	ll y = round (out.y);
	if (cmp (x, out.x) == 0 and cmp (y, out.y) == 0 and inSeg ({x, y}, s1) and inSeg ({x, y}, s2))
		return 1;
	return 0;
}

using pll = pair<ll, ll>;

int n;
int ans;
vector<seg> vec;
set<pll> points;

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y, a, b;
		scanf ("%d %d %d %d", &x, &y, &a, &b);
		vec.push_back ({{x, y}, {a, b}});
	}
	
	for (int i = 0; i < len (vec); i++) {
		map<pll, int> mp;
		seg s = vec[i];
		int x = abs (s.a.x-s.b.x);
		int y = abs (s.a.y-s.b.y);
		int md = mdc (x, y);
		ans += 2 + md - 1;
		pt out;
		for (int j = i+1; j < len (vec); j++)
			if (common (s, vec[j], out)) {
				pll p = {(ll)out.x, (ll)out.y};
				if (points.count (p) == 0) mp[p]++;
			}
		
		for (auto p : mp) {
			points.insert (p.x);
			ans -= p.y;
		}
	}
	
	printf ("%d\n", ans);
	
	return 0;
}