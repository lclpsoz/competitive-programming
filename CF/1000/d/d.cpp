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
const int MOD = 998244353;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int n;
int dp[1010];
int val[1010];
int bin_v[1010][1010];

int bin(int a, int b) {
	if(a == b or b == 0) return 1;
	int &ret = bin_v[a][b];
	if(ret != -1)
		return ret;
	return ret = (bin(a-1, b-1) + bin(a-1, b))%MOD;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(bin_v, -1, sizeof bin_v);

	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> val[n-i];
	for(int p = 1; p <= n; p++) {
		dp[p] = dp[p-1];
		if(val[p] > 0)
			for(int i = 0; i < p-val[p]; i++) {
				int amount = 1;
				if(val[p] > 1) {
					int q = p-i-2;
					amount = bin(q, val[p]-1);
					// cerr << ' ' << q << val[p]-1 << " -> " << amount << '\n';
				}
				dp[p] = (dp[p] + (ll)amount + (dp[i]*1LL*amount)%MOD)%MOD;
			}
	}
	cout << dp[n] << '\n';

	return 0;
}
