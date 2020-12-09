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

bitset<52> vis;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vi vec(n);
		for (int &v : vec)
			cin >> v;
		set<int> st;
		for (int i = 0; i < n; i++)
			for (int j = i+1; j < n; j++)
				st.insert(vec[i]+vec[j]);
		int ans = 0;
		for (int sum : st) {
			int now = 0;
			vis.reset();
			for (int i = 0; i < n; i++)
				for (int j = i+1; j < n; j++)
					if (!vis[i] and !vis[j] and vec[i]+vec[j] == sum) {
						++now;
						vis[i] = vis[j] = 1;
						break;
					}
			ans = max(ans, now);
		}
		cout << ans << '\n';
	}

	return 0;
}
