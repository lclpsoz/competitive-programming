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

const int N = 1e6+10;

int n;
int dp[N];

int main () {
	scanf("%d", &n);
	ll odd, even;
	odd = even = 0;
	dp[0] = 0;
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		if(i%2) {
			dp[i] = (dp[i]+even+1)%MOD;
			odd = (odd+dp[i])%MOD;
		}
		else {
			dp[i] = (dp[i]+odd+1)%MOD;
			even = (even+dp[i])%MOD;
		}
		ans = (ans+dp[i])%MOD;
	}
	printf("%lld\n", ans);

	return 0;
}
