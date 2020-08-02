#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

int n, k;
int dp[2010][2010];

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	// memset(dp, -1, sizeof dp);
	scanf("%d %d", &n, &k);
	int ans = 0;
	for(int i = 1; i <= n; i++) dp[k][i] = 1;
	for(int p = k-1; p >= 1; p--)
		for(int v = 1; v <= n; v++)
			for(int vv = v; vv <= n; vv += v)
				dp[p][v] = (dp[p][v]+dp[p+1][vv])%MOD;
	for(int i = 1; i <= n; i++)
		ans = (ans+dp[1][i])%MOD;
	printf("%d\n", ans);


	return 0;
}
