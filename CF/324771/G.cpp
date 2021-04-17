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
const ld EPS = 1e-3;
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

template <typename _T> int sgn(_T x) {
	return (_T(0) < x) - (x < _T(0));
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


////////////////////////// End of GEOMETRY. //////////////////////////////

void test(pt p1, pt p2, pt p3, T r)
{
	pair<pt, pt> out;
	int q = circleCircle(p1, r, p2, r, out);
	r += EPS;
	if(q)
	{
		if(sq(out.first - p3) <= r * r)
		{
			cout << "YES" << endl;
			cout << fixed << out.first.x << " " << out.first.y << endl;
			exit(0);
		}
		if(sq(out.second - p3) <= r * r)
		{
			cout << "YES" << endl;
			cout << fixed << out.second.x << " " << out.second.y << endl;
			exit(0);
		}
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int r; cin >> r;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cin >> x3 >> y3;

	test({x1, y1}, {x2, y2}, {x3, y3}, r);
	test({x2, y2}, {x3, y3}, {x1, y1}, r);
	test({x3, y3}, {x1, y1}, {x2, y2}, r);

	cout << "NO" << endl;

	return 0;
}
