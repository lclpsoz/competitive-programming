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

ll sq (pt p) {return p.x*p.x + p.y*p.y;}
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


const int N = 1e3 + 10;

int n;
int sz[N], link[N];
vector<pt> vec;
vector<pair<ll, pii>> edge;
vector<pii> edgesUsed;

int find (int a) {
	if (link[a] == a) return a;
	return link[a] = find (link[a]);
}

bool same (int a,  int b) { return find (a) == find (b); }

void unite (int a, int b) {
	a = find (a), b = find (b);
	if (sz[a] > sz[b]) swap (a, b);
	sz[b] += sz[a];
	link[a] = b;
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
	double oa = orient(c,d,a),
	ob = orient(c,d,b),
	oc = orient(a,b,c),
	od = orient(a,b,d);
	// Proper intersection exists iff opposite signs
	if (oa*ob < 0 && oc*od < 0) {
	out = (a*ob - b*oa) / (ob-oa);
	return true;
	}
	return false;
}

bool check (int u, int v){
	pt o;
	for (auto pp : edgesUsed)
		if (properInter (vec[u], vec[v], vec[pp.x], vec[pp.y], o))
			return false;
	return true;
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) link[i] = i, sz[i] = 1;
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			edge.push_back ({sq ({vec[i].x-vec[j].x, vec[i].y-vec[j].y}), {i, j}});
	sort (edge.begin(), edge.end(), greater<pair<ll, pii>>());
	ld ans = 0;
	while (!edge.empty()) {
		int u, v;
		ll d;
		u = edge.back().y.x, v = edge.back().y.y, d = edge.back().x;
		edge.pop_back ();
		if (!same (u, v) and check (u, v)) {
			// printf ("%d %d %lld\n", u, v, d);
			unite (u, v);
			edgesUsed.push_back ({u, v});
			ans += sqrt (d);
		}
	}
	printf ("%0.6Lf\n", ans);
	
	return 0;
}