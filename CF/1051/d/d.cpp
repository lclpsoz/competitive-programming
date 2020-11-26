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
int dp[1010][2010][4];

int solve(int p, int k, int bef) {
	if(k < 0)
		return 0;
	if(!p)
		return k == 0;
	int &ret = dp[p][k][bef];
	if(ret != -1) return ret;
	ret = 0;
	if(p == n) {
		for(int i = 0; i < 4; i++) {
			int ax = k;
			if(i == 0 or i == 3) ax--;
			else ax-=2;
			ret = (ret + solve(p-1, ax, i))%MOD;
		}
	}
	else {
		for(int i = 0; i < 4; i++) {
			int ax = k;
			if(bef == 0) ax -= i!=0;
			if(bef == 3) ax -= i!=3;
			if(bef == 1 and i == 2) ax-=2;
			if(bef == 2 and i == 1) ax-=2;
			ret = (ret + solve(p-1, ax, i))%MOD;
			// cout << "||p = " << p << ", a = " << a << ", b = " << b << ", r = " << ret << '\n';
		}
	}
	// cout << "p = " << p << ", k = " << k << ", bef = " << bef << ", ret = " << ret << '\n';
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);
	int k;
	cin >> n >> k;
	cout << solve(n, k, 0) << '\n';

	return 0;
}
