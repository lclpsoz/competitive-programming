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
		int n, k;
		cin >> n >> k;
		vi h(n);
		for (int &v : h)
			cin >> v;
		int l = h[0];
		int r = l;
		bool ans = true;
		for (int i = 1; ans and i < n-1; i++) {
			l = max(l-(k-1), h[i]);
			r = min(r+k-1, h[i]+k-1);
			if (h[i] > r or r < l) {
				ans = false;
			}
			// cerr << "i = " << i << ", l = " << l << ", r = " << r << '\n';
		}
		l -= k-1;
		r += k-1;
		// cerr << "i = " << n-1 << ", l = " << l << ", r = " << r << '\n';
		if (!ans or (h.back() > r or h.back() < l))
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}
