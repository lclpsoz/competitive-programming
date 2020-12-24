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

ld dp[105][105][105];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int a, b, c;
	cin >> a >> b >> c;

	vector<vi> now, nxt;
	now.push_back({a, b, c});
	dp[a][b][c] = 1;
	ld ans = 0;
	while (LEN(now)) {
		for (auto &vv : now) {
			int i = vv[0];
			int j = vv[1];
			int k = vv[2];
			// cerr << i << ' ' << j << ' ' << k << '\n';
			if (i == 100 or j == 100 or k == 100) {
				int d = i-a + j-b + k-c;
				// cerr << "d = " << d << '\n';
				ans += d*dp[i][j][k];
			}
			else {
				ld prob = dp[i][j][k];
				int sum = 0;
				for (int i = 0; i < 3; i++)
					sum += vv[i];
				for (int i = 0; i < 3; i++) {
					vv[i]++;
					dp[vv[0]][vv[1]][vv[2]] += prob*(ld)(vv[i]-1)/(ld)sum;
					nxt.push_back(vv);
					vv[i]--;
				}
			}
		}
		sort(ALL(nxt));
		nxt.resize(unique(ALL(nxt)) - nxt.begin());

		now.swap(nxt);
		nxt.clear();
	}
	cout << fixed << ans << '\n';

	return 0;
}
