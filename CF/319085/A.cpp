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
const ld PI = acosl(-1);

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

ld area_saved (ll r, ld theta) {
	ld area_c = r*r*PI;
	ld sub_area = ((PI - theta)/(2*PI))*area_c;
	ld cat_adj = r/tanl(theta/2);
	ld area_triangles = (cat_adj*r);
	return area_triangles - sub_area;
}

ld area_tr (ld a, ld b, ld c) {
	ld s = (a+b+c)/2;
	return sqrtl(s*(s-a)*(s-b)*(s-c));
}

ld get_r_circ(ld ab, ld bc, ld ca) {
	ld p = ab+bc+ca;
	return area_tr(ab, bc, ca) / (0.5 * p);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);

	ld a, b, c, r;
	cin >> a >> b >> c >> r;
	ld area_intact = 0;
	// cerr << "r_circ = " << get_r_circ(a, b, c) << '\n';
	ld r_circ = get_r_circ(a, b, c);
	// cerr << "area_circ = " << PI*r_circ*r_circ << '\n';
	// cerr << "area_tr = " << area_tr(a, b, c) << '\n';

	ld prop = r*r/(r_circ*r_circ);
	// cerr << "prop = " << prop << '\n';
	// cerr << "area_smaller = " << (prop*area_tr(a, b, c)) << '\n';
	area_intact += (prop)*area_tr(a, b, c) - (PI*r*r);
	cout << 1-(area_intact/area_tr(a, b, c)) << '\n';


	return 0;
}
