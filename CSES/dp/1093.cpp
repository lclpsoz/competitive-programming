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
const int MOD = 1e9 + 7;

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

const int ZERO = (501*500)/2 + 1;
const int MAXN = 2*ZERO;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vector<vi> dp(2, vi(MAXN));
	dp[0][ZERO] = 1;
	int acu = 0;
	for (int v = 1; v <= n; v++) {
		int p = v&1;
		for (int i = -acu; i <= acu; i++)
			dp[p][ZERO+i] = 0;
		for (int i = -acu; i <= acu; i++) {
			dp[p][ZERO+i-v] = (dp[p][ZERO+i-v]+dp[!p][ZERO+i])%MOD;
			dp[p][ZERO+i+v] = (dp[p][ZERO+i+v]+dp[!p][ZERO+i])%MOD;
		}
		// for (int i = -5; i <= 5; i++)
		// 	cout << dp[p][ZERO+i] << " \n"[i==5];
		acu += v;
	}

	cout << (dp[n&1][ZERO]*1ll*500000004)%MOD << '\n';

	return 0;
}
