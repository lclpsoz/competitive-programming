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

int t, n;
int dp[405][205];
int a[205];

int solve(int tm, int p) {
	if(p == n) return 0;
	if(tm > 2*n+1) return 1e9;
	int &ret = dp[tm][p];
	if(ret != -1) return ret;
	return ret = min(solve(tm+1, p), solve(tm+1, p+1) + abs(tm-a[p]));
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	cin >> t;
	while(t--) {
		cin >> n;
		memset(dp, -1, sizeof dp);
		for(int i = 0; i < n; i++)
			cin >> a[i];
		sort(a, a+n);
		cout << solve(1, 0) << '\n';
	}

	return 0;
}
