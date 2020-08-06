#include "bits/stdc++.h"
using namespace std;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

const int N = 1e5 + 10;

int t, n, k, z;
int a[N];
int dp[7][N];

int solve(int lf, int p) {
	// printf("  |lf = %d, p = %d\n", lf, p);
	if(lf > z or 2*lf+p > k or p < 0) return 0;
	// printf("  lf = %d, p = %d\n", lf, p);
	int &ret = dp[lf][p];
	if(ret != -1) return ret;
	return ret = a[p] + max(solve(lf + 1, p-1), solve(lf, p+1));
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &n, &k, &z);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for(int i = 0; i < n; i++)
			for(int j = 0; j <= z; j++)
				dp[j][i] = -1;
		printf("%d\n", solve(0, 0));
	}

	return 0;
}
