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

	int n, q;
	cin >> n >> q;
	vi vec(n+1, 1);
	map<int, int> mp;
	mp[1] = n;
	while (q--) {
		int opt;
		cin >> opt;
		if (opt == 1) {
			int l, r, x;
			cin >> l >> r >> x;
			assert(x <= 1000);
			for (int i = l; i <= r; i++) {
				mp[vec[i]]--;
				vec[i] = x;
				mp[vec[i]]++;
			}
		}
		else if (opt == 2) {
			int x;
			cin >> x;
			int ans = 0;
			for (int i = 1; i <= n; i++) ans += vec[i] == x;
			cout << ans << '\n';
		}
		else {
			int cur_mx = 0;
			for (int i = 1; i <= 1000; i++)
				cur_mx = max(cur_mx, mp[i]);
			cout << cur_mx << '\n';
		}
	}

	return 0;
}
