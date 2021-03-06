#include "bits/stdc++.h"
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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
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
	T side (pt p) { return ((cross (v, p) - c) > 0) ? 1 : ((cross (v, p) - c) < 0 ? -1 : 0); }
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

bool inter (line l1, line l2, pair<ld, ld> &out) {
	T d = cross (l1.v, l2.v);
	if (cmp (d) == 0) return false;
	// out = (l2.v*l1.c - l1.v*l2.c) / d; // Require ld
	// cerr << "    l1 -> " << l1.v.x << ' ' << l1.v.y << ", c = " << l1.c << '\n';
	// cerr << "    l2 -> " << l2.v.x << ' ' << l2.v.y << ", c = " << l2.c << '\n';
	out.x = (ld)(l2.v.x*(ld)l1.c - l1.v.x*(ld)l2.c) / d;
	out.y = (ld)(l2.v.y*(ld)l1.c - l1.v.y*(ld)l2.c) / d;

	return true;
}

////////////////////////// Solution starts below. //////////////////////////////

const int DBG = 0;

const int MAXV = 2.2e8;
pt _ans;
int n;
int DBG_total = 0;

bool between_lines (pair<line, line> lin, pt a) {
	return (lin.x.side(a) == 0 or lin.y.side(a) == 0 or
				(lin.x.side(a) != lin.y.side(a)));
}

bool read_ans () {
	string s;
	cin >> s;
	return s[0] == 'Y';
}

bool qry (pt x) {
	++DBG_total;
	if (DBG < 2)
		cout << "? 1 " << x.x << ' ' << x.y << endl;
	if (DBG) {
		bool ret = (x.x == _ans.x and x.y == _ans.y);
		if (DBG > 2)
			cerr << "ret = " << ret << '\n';
		return ret;
	}
	return read_ans();
}

bool qry (pt a, pt b, pt c) {
	++DBG_total;
	if (DBG < 2)
		cout << "? 3 " 	<< a.x << ' ' << a.y << ' '
						<< b.x << ' ' << b.y << ' '
						<< c.x << ' ' << c.y << endl;
	if (DBG) {
		line l3 = {b, c};
		bool ret = between_lines({{a, b}, {a, c}}, _ans) and
			(l3.side(_ans) == 0 or l3.side(_ans) == l3.side(a));

		if (DBG > 2)
			cerr << "ret = " << ret << '\n';
		return ret;
	}
	return read_ans();
}

void prt_ans (pt a) {
	cout << "! " << a.x << ' ' << a.y << endl;
	exit(0);
}

vector<pair<ld, ld>> get_inters (pair<line, line> diag, pair<line, line> side) {
	pair<ld, ld> pt_inter;
	vector<pair<ld, ld>> pts_inters;
	inter(diag.x, side.x, pt_inter);
	pts_inters.push_back(pt_inter);

	inter(diag.x, side.y, pt_inter);
	pts_inters.push_back(pt_inter);

	inter(diag.y, side.x, pt_inter);
	pts_inters.push_back(pt_inter);

	inter(diag.y, side.y, pt_inter);
	pts_inters.push_back(pt_inter);

	return pts_inters;
}

void solve (pair<line, line> diag, pair<line, line> side) {
	ll x_mn = INF<ll>, x_mx = -INF<ll>;
	ll y_mn = INF<ll>, y_mx = -INF<ll>;
	for (pair<ld, ld> a : get_inters(diag, side)) {
		x_mn = min(x_mn, (ll)(floor(a.x)-EPS));
		x_mx = max(x_mx, (ll)(ceil(a.x)+EPS));
		y_mn = min(y_mn, (ll)(floor(a.y)-EPS));
		y_mx = max(y_mx, (ll)(ceil(a.y)+EPS));
	}
	vector<pt> pt_check;
	for (int i = x_mn; i <= x_mx; i++)
		for (int j = y_mn; j <= y_mx; j++) {
			pt a = {i, j};
				// cerr << "a = " << a.x << ' ' << a.y << '\n';
			if (a.x and a.y and a.x <= n and a.y <= n and between_lines(diag, a) and between_lines(side, a))
				pt_check.push_back(a);
		}

	assert(DBG_total+LEN(pt_check) <= 60);
	for (pt a : pt_check)
		if (qry(a))
			prt_ans(a);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	cin >> n;
	if (DBG)
		cin >> _ans.x >> _ans.y;

	pt fixed_left = {1, MAXV};
	int l = 0, r = MAXV;
	auto apply_left = [=] (int v) {
		pt p = {1, 1};
		p.x = min(p.x+v, (ll)MAXV);
		v -= p.x-1;
		p.y += v;
		return p;
	};
	while (l < r-1)  {
		int md = (l+r+1)/2;
		if (qry(fixed_left, apply_left(l), apply_left(md)))
			r = md;
		else
			l = md;
	}
	if (DBG > 2) {
		cerr << "left_l -> (" << apply_left(l).x << ", " << apply_left(l).y << ")\n";
		cerr << "left_r -> (" << apply_left(r).x << ", " << apply_left(r).y << ")\n";
	}
	line left_l1 = line({1, MAXV}, apply_left(l));
	line left_l2 = line({1, MAXV}, apply_left(r));

	pt fixed_right = {MAXV, MAXV};
	auto apply_right = [=] (int v) {
		pt p = {1, MAXV};
		p.y = max(p.y-v, 1LL);
		v -= MAXV-p.y;
		p.x += v;
		return p;
	};
	l = 0, r = 2*MAXV - 2;
	while (l < r-1)  {
		int md = (l+r+1)/2;
		if (qry(fixed_right, apply_right(l), apply_right(md)))
			r = md;
		else
			l = md;
	}
	if (DBG > 2) {
		cerr << "right_l -> (" << apply_right(l).x << ", " << apply_right(l).y << ")\n";
		cerr << "right_r -> (" << apply_right(r).x << ", " << apply_right(r).y << ")\n";
	}
	line right_l1 = line(fixed_right, apply_right(l));
	line right_l2 = line(fixed_right, apply_right(r));

	solve({left_l1, left_l2}, {right_l1, right_l2});


	return 0;
}
