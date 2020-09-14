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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9 + 7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll dp[25];

ll fact(int x) {
	ll ret = 1;
	for(int i = 1; i <= x; i++)
		ret = i*ret;
	return ret;
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int n;
	cin >> n;
	dp[1] = 0, dp[2] = 1;
	for(int i = 3; i <= n; i++) {
		dp[i] = fact(i)-1;
		for(int q = 1; q < i; q++) {
			ll ax = (fact(i)/fact(i-q));
			ax /= fact(q);
			// cout << "ax = " << ax << '\n';
			// cout << dp[i] << '\n';
			dp[i] -= ax*dp[i-q];
		}
	}
	cout << dp[n]%MOD << '\n';

	return 0;
}
