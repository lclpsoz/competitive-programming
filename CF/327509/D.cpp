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

template<typename T>
const T INF = (is_same<T, int>::value ? 1e9 : 1e18);
const ld EPS = 1e-9;
const int MOD = 1;

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

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
	if (fcmp (d) == 0) return false;
	out = (l2.v*l1.c - l1.v*l2.c) / d; // Require ld

	return true;
}

////////////////////////// End of GEOMETRY. //////////////////////////////

const int MAXV = 1e6;

const int DBG = 0;
set<pii> dbg_ans;
int n;

template <typename T> int sgn(T x) {
	return (T(0) < x) - (x < T(0));
}

int circleCircle(pt o1, double r1, pt o2, double r2, pair<pt,pt> &out) {
	pt d=o2-o1; double d2=sq(d);
	if (d2 == 0) {assert(r1 != r2); return 0;} // concentric circles
	double pd = (d2 + r1*r1 - r2*r2)/2; // = |O_1P| * d
	double h2 = r1*r1 - pd*pd/d2; // = hˆ2
	if (h2 >= 0) {
	pt p = o1 + d*pd/d2, h = perp(d)*sqrt(h2/d2);
	out = {p-h, p+h};
	}
	return 1 + sgn(h2);
}

ll qry (int x, int y) {
	ll d;
	cout << "" << x << ' ' << y << endl;
	assert(x >= 0 and x <= MAXV);
	assert(y >= 0 and y <= MAXV);
	if (DBG) {
		d = INF<ll>;
		for (auto [a, b] : dbg_ans) {
			ll dx = a-x;
			ll dy = b-y;
			d = min(d, dx*dx + dy*dy);
			if (a == x and b == y) {
				dbg_ans.erase({a, b});
				break;
			}
		}
		cerr << "      d = " << d << '\n';
	}
	else
		cin >> d;
	return d;
}

void neighbours (int x, int y) {
	// cerr << "    nei: " << x << ' ' << y << '\n';
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) {
			int a = x-i, b = y-j;
			if (a >= 0 and a <= MAXV and b >= 0 and b <= MAXV and
				qry(a, b) == 0)
				return;
		}
	assert(false);
}

pii base = {MAXV/2, MAXV/2};
ll base_d;
bool solve (ld x, ld y) {
	// cerr << "  solve(" << (ll)(round(x)+EPS) << ", " << (ll)(round(y)+EPS) << ")\n";
	ll d = qry((ll)(round(x)+EPS), (ll)(round(y)+EPS));
	if (d == 0)
		return true;
	if (d <= 2) {
		neighbours(x, y);
		return true;
	}
	pair<pt, pt> inter;
	circleCircle({(ld)base.x, (ld)base.y}, sqrt(base_d),
					{x, y}, sqrt(d), inter);
	inter.x.x = max((ld)0, min((ld)MAXV, inter.x.x));
	inter.y.x = max((ld)0, min((ld)MAXV, inter.y.x));
	inter.x.y = max((ld)0, min((ld)MAXV, inter.x.y));
	inter.y.y = max((ld)0, min((ld)MAXV, inter.y.y));
	if (solve(inter.x.x, inter.x.y))
		return true;
	if (solve(inter.y.x, inter.y.y))
		return true;
	return false;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n;
	if (DBG) {
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			dbg_ans.insert({x, y});
		}
		n = LEN(dbg_ans);
	}

	for (int i = 0; i < n; i++) {
		base_d = qry(base.x, base.y);
		if (base_d == 0)
			continue;
		else if (base_d <= 2)
			neighbours(base.x, base.y);
		else
			solve(base.x, min((double)MAXV, base.y+sqrt(base_d)));
	}



	return 0;
}
