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
		vpii ans;
		set<int> st;
		int val = n;
		while (val > 2) {
			st.insert(val);
			int ax = sqrt(val);
			if (ax*ax < val)
				++ax;
			val = ax;
		}
		for (int i = 3; i <= n; i++)
			if (!st.count(i))
				ans.push_back({i, n});
		vi vec;
		for (int v : st)
			vec.push_back(v);
		reverse(ALL(vec));
		vec.push_back(2);
		for (int i = 0; i < LEN(vec)-1; i++) {
			ans.push_back({vec[i], vec[i+1]});
			ans.push_back({vec[i], vec[i+1]});
		}
		assert(LEN(ans) <= n+5);
		cout << LEN(ans) << '\n';
		for (auto &[x, y] : ans)
			cout << x << ' ' << y << '\n';
	}

	return 0;
}
