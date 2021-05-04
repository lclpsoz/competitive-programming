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

using pt = pair<ld, ld>;

pt rotate (pt p, ld a) {
	return {p.x*cos(a) - p.y*sin(a), p.x*sin(a) + p.y*cos(a)};
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);

	int n;
	cin >> n;
	ld x0, y0, xmd, ymd;
	cin >> x0 >> y0 >> xmd >> ymd;
	pair<ld, ld> md = {(x0+xmd)/2, (y0+ymd)/2};
	ld pi = acos(-1);
	x0 -= md.x;
	y0 -= md.y;
	ld ang = 180.0/(n/2);
	pt ans = rotate ({x0, y0}, pi*ang/180.0);
	cout << ans.x+md.x << ' ' << ans.y+md.y << '\n';

	return 0;
}
