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

using T = ll;

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

bool operator== (line &a, line &b) {
	return (a.c == b.c and a.v == b.v);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1010;

int n;
vector<pt> vec;
deque<line> lines;
int link[N], sz[N];

int find (int x) {
	if (link[x] == x) return x;
	return link[x] = find (link[x]);
}

int main ()
{
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) link[i] = i, sz[i] = 1;
	while (n--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		vec.push_back ({x, y});
	}

	ll ans = 0;
	for (int i = 0; i < len (vec); i++) {
		vector<line> linesNow;
		for (int j = i+1; j < len (vec); j++) {
			line l = line({vec[i], vec[j]});
			bool ok = true;
			for (line l2 : linesNow)
				if (l2.side(vec[i]) == 0 and l2.side(vec[j]) == 0) {
					ok = false;
					break;
				}
			for (int k = 0; ok and k < i; k++)
				if (l.side(vec[k]) == 0)
					ok = false;
			if (ok)
				linesNow.push_back (l);
		}
		for (auto l2 : linesNow) lines.push_back (l2);
	}

	line base({0, 0}, {0, 1});
	sort (lines.begin(), lines.end(), [&] (line &l1, line &l2) {
		ld coef1 = l1.v.x == 0 ? 1e18 : l1.v.y/(ld)l1.v.x;
		ld coef2 = l2.v.x == 0 ? 1e18 : l2.v.y/(ld)l2.v.x;
		return cmp (coef1, coef2) == -1;
		//return cross (l1.v, l2.v) < 0;
	});
	vector<int> ax;
	// int bi = 1000000000;
	// for (int i = 0; i < len (lines); i++) {
	// 	if (lines[i].c == bi and lines[i].v.x == bi and lines[i].v.y == bi) continue;
	// 	ax.push_back (1);
	// 	for (int j = i+1; j < len (lines); j++)
	// 		if (cross (lines[i].v, lines[j].v) == 0) {
	// 			++ax.back();
	// 			lines[j].v = {bi, bi};
	// 			lines[j].c = bi;
	// 		}
	// }

	int q = len (lines)+1;
	while (q-- and cross(lines.front().v, lines.back().v) == 0) {
		lines.push_back (lines.front());
		lines.pop_front();
	}

	for (int i = 0; i < len (lines); i++) {
		// printf ("(%d, %d) c = %d\n", lines[i].v.x, lines[i].v.y, lines[i].c);
		if (len (ax) == 0)
			ax.push_back (1);
		else {
			if (cross (lines[i].v, lines[i-1].v) == 0)
				ax.back()++;
			else
				ax.push_back (1);
		}
	}

	// for (int i = 0; i < len (lines); i++)
	// 	for (int j = i+1; j < len (lines); j++) {
	// 		pt o;
	// 		ans += inter (lines[i], lines[j], o);
	// 	}

	int total = len(lines);
	for (int v : ax) {
		// printf ("v = %d\n", v);
		ans += v*1LL*(total-v);
		total -= v;
	}
	printf ("%lld\n", ans);
	return 0;
}
