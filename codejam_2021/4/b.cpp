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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = (int)x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e3 + 100;

int dp[N];
// set<pii> st;

// void brute (int x, int sum, int prof) {
// 	// cerr << x << ' ' << sum << ' ' << prof << '\n';
// 	if (st.count({x, sum}) == 0) {
// 		st.insert({x, sum});
// 		dp[sum] = max(dp[sum], prof);
// 		for (int i = 2*x; sum+i < N; i+=x)
// 			brute(i, sum + i, prof+1);
// 	}
// }

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// for (int i = 3; i < N; i++)
	// 	brute(i, i, 1);


	vector<pair<pii, int>> cases[N];
	for (int i = 3; i < N; i++) {
		dp[i] = 1;
		cases[i].push_back({{i, i}, 1});
	}

	for (int i = 3; i < N; i++) {
		for (auto [sum_v, q] : cases[i]) {
			auto [sum, v] = sum_v;
			for (int j = 2*v; sum+j < N; j += v) {
				cases[j].push_back({{sum+j, j}, q+1});
				dp[sum+j] = max(dp[sum+j], q+1);
			}
		}
	}

	// for (int i = 3; i < N; i++) {
	// 	for (int j = (N/i-2)*i; j > i; j-=i)
	// 		dp[j+i] = max(dp[j+i], dp[i]+dp[j]);
	// }

	// for (int i = 3; i < 50; i++)
	// 	cerr << i << ": " << dp[i] << '\n';

	int t;
	cin >> t;
	for (int t_now = 1; t_now <= t; t_now++) {
		int x;
		cin >> x;
		// int ans = 1;
		// for (int i = 3; i < x; i++) {
		// 	if (x%i == 0) {

		// 		while (((ans+1LL)*(ans+2))/2 <= x/i)
		// 			++ans;
		// 		break;
		// 	}	
		// }
		cout << "Case #" << t_now << ": " << dp[x] << '\n';
	}

	return 0;
}
