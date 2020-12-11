#include "bits/stdc++.h"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/pb_ds/assoc_container.hpp"
using namespace std;
////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define LEN(x) ((int)(x).size())
#define ALL(x) x.begin(), x.end()
using ll = long long;
using llu = long long unsigned;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using vpii = vector<pii>;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////


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

pt a, b, c, d;
ld d1, d2;

ld dist(ld t) {
	ld x1, y1, x2, y2;
	if(cmp(t, d1) >= 0)
		x1 = b.x, y1 = b.y;
	else if(cmp(t, 0) == 0)
		x1 = a.x, y1 = a.y;
	else {
		ld prop = t/d1;
		x1 = a.x-(a.x-b.x)*prop;
		y1 = a.y-(a.y-b.y)*prop;
	}

	if(cmp(t, d2) >= 0)
		x2 = d.x, y2 = d.y;
	else if(cmp(t, 0) == 0)
		x2 = c.x, y2 = c.y;
	else {
		ld prop = t/d2;
		x2 = c.x-(c.x-d.x)*prop;
		y2 = c.y-(c.y-d.y)*prop;
	}

	// cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
	x1 -= x2;
	y1 -= y2;
	return 	sqrt(x1*x1 + y1*y1);
}

ld ternary(ld l, ld r) {
	int qnt = 1e5;
	while(qnt--) {
		ld tl = (2*l + r)/3;
		ld tr = (l + 2*r)/3;
		ld vl = dist(tl);
		ld vr = dist(tr);
		// cout << "vl = " << vl << ", vr = " << vr << '\n';
		// cout << "l = " << l << ", r = " << r << '\n';
		if(vl < vr)
			r = tr;
		else
			l = tl;
	}
	return dist(l);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    cout.precision(15);
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> d.x >> d.y;
	ld x = a.x-b.x;
	ld y = a.y-b.y;
	d1 = sqrt(x*x + y*y);
	x = c.x-d.x;
	y = c.y-d.y;
	d2 = sqrt(x*x + y*y);
	// cout << d1 << ' ' << d2 << '\n';
	// for(ld i = 0; i <= max(8, 8); i+=0.1)
	// 	cout << i << '\t' << dist(i) << '\n';

	ld ans = ternary(0, max(d1, d2));
	ans = min(ans, ternary(0, min(d1, d2)));
	if(cmp(d1, d2))
		ans = min(ans, ternary(min(d1, d2), max(d1, d2)));

	line l1(a, b);
	line l2(c, d);
	
	pt ir;
	if(inter(l1, l2, ir)) {
		x = ir.x-a.x;
		y = ir.y-a.y;
		ld md1 = sqrt(x*x + y*y);
		x = ir.x-c.x;
		y = ir.y-c.y;
		ld md2 = sqrt(x*x + y*y);
		vector<ld> vec = {0, d1, d2, md1, md2};
		sort(ALL(vec));
		for(int i = 0; i < LEN(vec)-1; i++)
			ans = min(ans, ternary(vec[i], vec[i+1]));
	}

	cout << ans << '\n';




	return 0;
}
