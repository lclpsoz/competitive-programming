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

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll a[401];
ll dp[401][401];

ll solve(int l, int r) {
	if(l == r) return 0;
	ll &ret = dp[l][r];
	if(ret != -1) return ret;
	ret = 1e18;
	for(int i = l; i < r; i++)
		ret = min(ret, solve(l, i)+solve(i+1, r));
	return ret += a[r]-a[l-1];
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] += a[i-1];
	}
	cout << solve(1, n) << '\n';

	return 0;
}
