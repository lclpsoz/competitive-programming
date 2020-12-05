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
	out.x = (l2.v.x*l1.c - l1.v.x*l2.c) / d;
	out.y = (l2.v.y*l1.c - l1.v.y*l2.c) / d;

	return true;
}

////////////////////////// Solution starts below. //////////////////////////////

const int DBG = 0;

bool read_ans () {
	string s;
	cin >> s;
	return s[0] == 'Y';
}

bool qry (pt x) {
	if (!DBG)
		cout << "? 1 " << x.x << ' ' << x.y << endl;
	else {
		exit(0);
	}
	return read_ans();
}

bool qry (pt a, pt b, pt c) {
	if (!DBG)
		cout << "? 3 " 	<< a.x << ' ' << a.y << ' '
						<< b.x << ' ' << b.y << ' '
						<< c.x << ' ' << c.y << endl;
	else {
		exit(0);
	}
	return read_ans();
}

void prt_ans (pt a) {
	cout << "! " << a.x << ' ' << a.y << endl;
	exit(0);
}

pii bin_search_diag (pt base_st, int l, int r) {
	cerr << "bin_diag\n";
	while (l+1 < r) {
		int md = (l+r+1)/2;
		if (qry (base_st, {l, l}, {md, md}))
			r = md;
		else
			l = md+1;
	}

	return {l, r};
}

pii bin_search_side (pt base_st, int n, bool is_floor) {
	cerr << "bin_side\n";
	int l = 1, r = n;
	while (l+1 < r) {
		int md = (l+r+1)/2;
		pt l_pt = {l, l};
		pt md_pt = {md, md};
		if (is_floor)
			l_pt.x = n, md_pt.x = n;
		else
			l_pt.y = n, md_pt.y = n;
		if (qry (base_st, l_pt, md_pt))
			r = md;
		else
			l = md+1;
	}

	return {l, r};
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

bool between_lines (pair<line, line> diag, pt a) {
	return ((diag.x.side(a) == 0 and diag.y.side(a) == 0) or
							(diag.x.side(a) != diag.y.side(a)));
}

void solve (pair<line, line> diag, pair<line, line> side) {
	ll x_mn = INF<ll>, x_mx = -INF<ll>;
	ll y_mn = INF<ll>, y_mx = -INF<ll>;
	for (pair<ld, ld> a : get_inters(diag, side)) {
		x_mn = min(x_mn, (ll)(floor(a.x)+EPS));
		x_mx = max(x_mx, (ll)(ceil(a.x)+EPS));
		y_mn = min(y_mn, (ll)(floor(a.y)+EPS));
		y_mx = max(y_mx, (ll)(ceil(a.y)+EPS));
	}
	vector<pt> pt_check;
	for (int i = x_mn; i <= x_mx; i++)
		for (int j = y_mn; j <= y_mx; j++) {
			pt a = {i, j};
			if (between_lines(diag, a) and between_lines(side, a)) {
				cerr << "a = " << a.x << ' ' << a.y << '\n';
				pt_check.push_back(a);
			}
		}
	assert(LEN(pt_check) <= 6);
	for (pt a : pt_check)
		if (qry(a))
			prt_ans(a);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);
	
	int n;
	cin >> n;
	
	if (n <= 3) {
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (qry({i, i}))
					prt_ans({i, i});
	}
	// Ceil
	else if (qry({1, 1}, {1, n}, {n, n})) {
		pt base_st = {1, n};
		pt base_st_side = {2, 1};
		auto [l_diag, r_diag] = bin_search_diag(base_st, 1, n);
		auto [l, r] = bin_search_side(base_st_side, n, 0);
		line diag_l1 = line(base_st, {l_diag, l_diag});
		line diag_l2 = line(base_st, {r_diag, r_diag});
		line side_l1 = line(base_st_side, {1, l});
		line side_l2 = line(base_st_side, {1, r});
		solve({diag_l1, diag_l2}, {side_l1, side_l2});
	}
	// Floor
	else {
		pt base_st = {n, 1};
		pt base_st_side = {1, 2};
		auto [l_diag, r_diag] = bin_search_diag(base_st, 1, n);
		auto [l, r] = bin_search_side(base_st_side, n, 1);
		exit(0);
	}

	return 0;
}
