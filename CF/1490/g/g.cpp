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



int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vi vec(n);
		for (int &x : vec)
			cin >> x;
		vector<ll> vals;
		vi pos;
		ll acu = 0;
		for (int i = 0; i < n; i++) {
			acu += vec[i];
			if (acu > 0 and (LEN(vals) == 0 or vals.back() < acu)) {
				vals.push_back(acu);
				pos.push_back(i);
			}
		}
		while (m--) {
			ll x;
			cin >> x;
			if (LEN(vals) == 0 or (acu <= 0 and x > vals.back()))
				cout << "-1 ";
			else {
				auto last_cycle = [&](ll val) {
					auto it = lower_bound(ALL(vals), val);
					if (it == vals.end()) return -1;
					else
						return pos[it-vals.begin()];
					
				};

				// cerr << "x = " << x << '\n';
				ll ans = 0;
				if (x > vals.back()) {
					ll dif = x-vals.back();
					ll q = dif/acu + (dif%acu > 0);
					// cerr << "  q = " << q << ", acu = " << acu << ", n = " << n << '\n';
					x -= q*acu;
					ans += q*n;
				}
				// cerr << "ans = " << ans << '\n';
				if (x > 0)
					ans += last_cycle(x);
				cout << ans << ' ';
			}
		}
		cout << '\n';
	}

	return 0;
}
