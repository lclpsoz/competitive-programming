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

const int MSK = (1<<16) + 10;

int n, m;
ll dp[MSK][130][17];

ll solve (int msk, int qnt, int row) {
	if (row > n) return ((qnt == 0 and msk == 0) ? 0 : -INF<ll>);
	ll &ret = dp[msk][qnt][row];
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	cin >> n >> m;
	int a, b;
	cin >> a >> b;

	// 0 is a vertical title
	ll ans = 0;
	for (int msk = 0; msk < 1<<m; msk++) {
		int cnt_a = 0;
		for (int i = 0; i < m-1; i++) {
			if (msk&(1<<i) and msk&(1<<(i+1))) {
				cnt_a++;
				++i;
			}
			else if (!(msk&(1<<i)))
				cnt_a++;
		}
		ans += solve(msk, a-cnt_a, 2);
	}
	cout << ans << '\n';

	return 0;
}
