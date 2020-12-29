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

// map<vi, int> dp;

// int sum (vi vec) {
// 	int ret = 0;
// 	for (int v : vec)
// 		ret += v;
// 	return ret;
// }

// int grundy (vi now) {
// 	if (sum (now) == 0)
// 		return 0;
// 	if (dp.count(now))
// 		return dp[now];
// 	vi nxt;
// 	if (now[0]) {
// 		vi ax = now;
// 		ax[0]--;
// 		nxt.push_back(grundy(ax));
// 	}
// 	for (int i = 1; i < LEN(now); i++)
// 		if (now[i] > now[i-1]) {
// 			vi ax = now;
// 			ax[i]--;
// 			nxt.push_back(grundy(ax));
// 		}
// 	sort(ALL(nxt));
// 	nxt.resize(unique(ALL(nxt)) - nxt.begin());
// 	int mex = 0;
// 	for (int v : nxt) {
// 		if (v != mex)
// 			break;
// 		++mex;
// 	}
// 	return dp[now] = mex;
// }

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, k;
	cin >> n >> k;
	if (n == 1) {
		int val;
		cin >> val;
		cout << (val%(k+1) ? "Dali" : "Dila") << '\n';
		// vi win(val+1);
		// win[0] = 0;
		// int cnt = 1;
		// for (int i = 1; i <= val; i++) {
		// 	cerr << i << " " << cnt << '\n';
		// 	win[i] = cnt;
		// 	cnt += win[i] == 0;
		// 	if (i-k >= 0)
		// 		cnt -= win[i-k] == 0;
		// }
		// cout << (win[n] ? "Dali" : "Dila") << '\n';
	}
	else {
		vi vec(n);
		ll sum = 0;
		for (int &v : vec) {
			cin >> v;
			sum += v;
		}
		cout << (sum%2 ? "Dali" : "Dila") << '\n';
	}
	
	// cout << grundy(vec) << '\n';
	// for (auto [vec, grundy] : dp) {
	// 	for (int v : vec)
	// 		cout << v << ' ';
	// 	cout << ": " << grundy << '\n';
	// 	assert(grundy == sum(vec)%2);
	// }


	return 0;
}
