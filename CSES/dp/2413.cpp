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

const int N = 1e6 + 10;

int n;
int dp[N][2];

int solve (int p, int bef) {
	// cerr << "p = " << p << ", n = " << n << '\n';
	if (p == 0) return 1;
	int &ret = dp[p][bef];
	if (ret != -1) return ret;
	ret = 0;
	--p;
	if (bef == 0)
		ret = (4LL*solve(p, 0) + solve(p, 1))%MOD;
	else
		ret = (solve(p, 0) + 2LL*solve(p, 1))%MOD;
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	memset(dp, -1, sizeof dp);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << (solve(n-1, 0) + solve(n-1, 1))%MOD << '\n';
	}

	return 0;
}
