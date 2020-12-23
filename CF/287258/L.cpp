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

const int P = 80;

bitset<P> is_prime;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (int i = 2; i <= 30; i++) {
		bool prime = true;
		for (int j = 2; j*j <= i; j++)
			if (i%j == 0)
				prime = false;
		if (prime) {
			is_prime[i] = 1;
		}
	}

	const int MAXN = 1e5 + 10;
	vi dp(MAXN);
	for (int i = 1; i < LEN(dp); i++) {
		dp[i] = dp[i-1];
		if (is_prime[__builtin_popcount(i)])
			dp[i]++;
	}
	// cout << LEN(dp) << endl;
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		if (l == 0) ++l;
		cout << dp[r] - dp[l-1] << '\n';
	}

	return 0;
}
