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
string s, t;
int dp[201][201][201];

int solve(int p, int lft, int k) {
	if(p == n) return 0;
	int &ret = dp[p][lft][k];
	if(ret != -1) return ret;
		ret = solve(p+1, lft, k);
	if(t[0] == t[1]) {
		if(s[p] == t[0])
			ret = max(ret, solve(p+1, lft+1, k)+lft);
		else if(k)
			ret = max(ret, solve(p+1, lft+1, k-1)+lft);
	} else {
		if(s[p] == t[0])
			ret = max(ret, solve(p+1, lft+1, k));
		else if(k)
			ret = max(ret, solve(p+1, lft+1, k-1));
		if(s[p] == t[1]) {
			ret = max(ret, solve(p+1, lft, k)+lft);
		} else if(k)
			ret = max(ret, solve(p+1, lft, k-1) + lft);
	}
	// cout << p << ' ' << lft << ' ' << k << ' ' << ret << '\n';
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	memset(dp, -1, sizeof dp);

	int k;
	cin >> n >> k;

	cin >> s >> t;
	cout << solve(0, 0, k) << '\n';

	return 0;
}
