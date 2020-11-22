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



int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vi vec(n);
		for(int &v : vec)
			cin >> v;
		vi sorted = vec;
		sort(ALL(sorted));
		sorted.resize(unique(ALL(sorted)) - sorted.begin());
		for(int i = 0; i < n; i++)
			vec[i] = lower_bound(ALL(sorted), vec[i])-sorted.begin();
		
		vector<vi> dp(n+5, vi(5));
		vi mid_ok(n);
		vector<bool> mid_started(n);
		for(int i = 0; i < n; i++)
			mid_ok[vec[i]]++;
		for(int i = 0; i < n; i++) {
			// Start
			dp[vec[i]][0]++;

			// Extend to mid
			if(vec[i] and !mid_started[vec[i]]) {
				mid_started[vec[i]] = 1;
				mid_ok[vec[i]]--;
				dp[vec[i]][1] = dp[vec[i]-1][0]+1;
				if(mid_ok[vec[i]-1] == 0)
					dp[vec[i]][1] = max(dp[vec[i]][1], dp[vec[i]-1][1]+1);
			}
			else {
				mid_ok[vec[i]]--;
				dp[vec[i]][1]++;
			}

			// End
			dp[vec[i]][2]++;
			if(vec[i]) {
				dp[vec[i]][2] = max(dp[vec[i]][2], dp[vec[i]-1][0]+1);
				if(mid_ok[vec[i]-1] == 0)
					dp[vec[i]][2] = max(dp[vec[i]][2], dp[vec[i]-1][1]+1);
			}
			// cout << "i = " << i << ", vec[i] = " << vec[i] << ",\tdp = " << dp[vec[i]][0] << ' ' << dp[vec[i]][1] << ' ' << dp[vec[i]][2] << '\n';
		}

		int ans = 0;
		for(int i = 0; i <= n; i++)
			for(int j = 0; j < 3; j++)
				ans = max(ans, dp[i][j]);
		cout << n-ans << '\n';
	}

	return 0;
}
