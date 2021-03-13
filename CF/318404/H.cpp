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

const int P = 7e4;
bitset<P> top, mid, bottom;

void prt (bitset<P> &bt, int l, int r) {
	for (int i = l; i <= r; i++)
		cerr << bt[l] << " \n"[i==r];
}

void inp (bitset<P> &bt, int mid_p) {
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		x += mid_p;
		bt[x] = 1;
	}
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int mid_p = P/2;
	inp(top, mid_p);
	inp(mid, mid_p);
	inp(bottom, mid_p);

	// Cycle positions
	for (int i = 0; i < mid_p-1; i++) {
		int ax = top[mid_p-i];
		top[mid_p-i] = top[mid_p+i];
		top[mid_p+i] = ax;
	}

	ll ans = 0;
	// Sum count if mid_p is set
	if (mid[mid_p])
		ans += (top&bottom).count();


	// Save original top
	bitset<P> original_top = top;
	// Going forward
	for (int i = mid_p+1; i < P; i++) {
		// Shift 2, to compensate shift 1 in mid
		top <<= 2;
		if (mid[i])
			ans += (top&bottom).count();
	}
	// Going backwards
	top = original_top;
	for (int i = mid_p-1; i; i--) {
		// Shift 2, to compensate shift 1 in mid
		top >>= 2;
		if (mid[i])
			ans += (top&bottom).count();
	}

	cout << ans << '\n';

	return 0;
}
