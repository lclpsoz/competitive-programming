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

const ll INF = 1e18;
const int N = 1e5 + 10;

int n;
int w[N];
string strs[N][2];
ll dp[N][2];

ll solve(int p, int rev) {
	if(p == n)
		return 0;
	ll &ret = dp[p][rev];
	if (ret != -1) return ret;
	ret = INF;

	if(strs[p+1][0] >= strs[p][rev])
		ret = solve(p+1, 0);
	if(strs[p+1][1] >= strs[p][rev])
		ret = min(ret, solve(p+1, 1) + w[p+1]);
	// printf("p = %d, rev = %d, ret = %lld\n", p, rev, ret);
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);
	cin >> n;
	for(int i = 1; i <= n; i++)
		cin >> w[i];

	for(int i = 1; i <= n; i++) {
		cin >> strs[i][0];
		strs[i][1] = strs[i][0];
		reverse(ALL(strs[i][1]));
	}

	ll ans = min(solve(1, 0), solve(1, 1) + w[1]);
	printf("%lld\n", ans == INF ? -1LL : ans);

	return 0;
}
