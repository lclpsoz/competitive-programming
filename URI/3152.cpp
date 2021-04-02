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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	vpii v1(4);
	pii pt_x = {INF<int>+10, -INF<int>-10}, pt_y = {INF<int>+10, -INF<int>-10};
	ll area1 = 0;
	for (auto &[x, y] : v1) {
		cin >> x >> y;
		pt_x.x = min(x, pt_x.x);
		pt_x.y = max(x, pt_x.y);
		pt_y.x = min(y, pt_y.x);
		pt_y.y = max(y, pt_y.y);
	}
	area1 = (pt_x.y-pt_x.x)*1LL*(pt_y.y-pt_y.x);
	area1 *= 2;
	for (int i = 0; i < 3; i++)	 {
		int dx = v1[i].x-v1[i+1].x;
		int dy = v1[i].y-v1[i+1].y;
		area1 -= abs(dx*1LL*dy);
	}
	
	vpii v2(4);
	ll area2 = 0;
	pt_x = {INF<int>+10, -INF<int>-10}, pt_y = {INF<int>+10, -INF<int>-10};
	for (auto &[x, y] : v2) {
		cin >> x >> y;
		pt_x.x = min(x, pt_x.x);
		pt_x.y = max(x, pt_x.y);
		pt_y.x = min(y, pt_y.x);
		pt_y.y = max(y, pt_y.y);
	}
	area2 = (pt_x.y-pt_x.x)*1LL*(pt_y.y-pt_y.x);
	area2 *= 2;
	for (int i = 0; i < 3; i++)	 {
		int dx = v2[i].x-v2[i+1].x;
		int dy = v2[i].y-v2[i+1].y;
		area2 -= abs(dx*1LL*dy);
	}
	// cerr << "area1 = " << area1 << '\n';
	// cerr << "area2 = " << area2 << '\n';
	cout << "terreno " << (area1 > area2 ? 'A' : 'B') << '\n';

	return 0;
}
