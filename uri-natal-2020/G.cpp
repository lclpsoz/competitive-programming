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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll dp[55][55];

ll bin(int n, int k) {
	if (k == 0 or k == n) return 1;
	ll &ret = dp[n][k];
	if (ret != -1) return ret;
	return ret = bin(n-1, k-1)+bin(n-1, k);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(2);

	memset(dp, -1, sizeof dp);

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		ld ans = 0;
		int n, k, x;
		cin >> n >> k >> x;
		ld broken = x/(ld)100;
		ld ok = 1-broken;

		ld p = 1;
		for (int j = 0; j < n; j++) {
			if (j < k)
				p *= broken;
			else
				p *= ok;
		}
		// cout << bin(50, 23) << '\n';
		// cout << bin(6, 3) << '\n';
		p *= bin(n, k);
		cout << fixed << "A chance de Basy acertar o numero no dia " << i << " eh " << p*100 << "%\n";
	}

	return 0;
}
