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

const int N = 21, MAXMSK = 1<<21;

int n, x;
int dp[MAXMSK];
int w[N];
ll sum[MAXMSK];

int solve (int msk) {
	if (msk == 0) return 0;
	// cerr << "msk = " << bitset<5>(msk) << '\n';
	int &ret = dp[msk];
	if (ret != -1) return ret;
	ret = 21;
	for (int sub = msk; sub; sub = (sub-1)&msk) {
		// cerr << "sub = " << bitset<21>(sub) << '\n';
		if (sum[sub] <= x)
			ret = min(ret, solve(msk^sub)+1);
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	memset(dp, -1, sizeof dp);


	cin >> n >> x;
	for (int i = 0; i < n; i++) cin >> w[i];
	for (int i = 0; i < (1<<n); i++)
		for (int j = 0; j < n; j++)
			if ((1<<j)&i)
				sum[i] += w[j];
	int ans = 21;
	for (int i = 1; i < (1<<n); i++)
		if (sum[i] <= x)
			ans = min(ans, solve(((1<<n)-1)^i) + 1);
	cout << ans << '\n';

	return 0;
}
