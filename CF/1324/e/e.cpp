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

const int N = 2e3 + 10;

int n, h, l, r;
int dp[N][N];
int shift[N];

int solve (int pos, int tm) {
	if (pos == n)
		return 0;
	int &ret = dp[pos][tm];
	if (ret != -1) return ret;
	int nxt = (tm+shift[pos])%h;
	ret = solve(pos+1, nxt) + (l <= nxt and nxt <= r);

	nxt = (tm+shift[pos]-1)%h;
	ret = max(ret, solve(pos+1, nxt) + (l <= nxt and nxt <= r));
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	memset(dp, -1, sizeof dp);

	cin >> n >> h >> l >> r;
	for (int i = 0; i < n; i++)
		cin >> shift[i];
	cout << solve(0, 0) << '\n';
	return 0;
}
