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
		// cerr << "n = " << n << '\n';
		vi a(n), b(n);
		for (int &x : a)
			cin >> x;
		for (int &x : b)
			cin >> x;
		vector<ll> ones, twos;
		for (int i = 0; i < n; i++)
			if (b[i] == 1)
				ones.push_back(a[i]);
			else
				twos.push_back(a[i]);
		// cerr << "HERE!\n";
		sort(ALL(ones), greater<int>());
		sort(ALL(twos), greater<int>());
		for (int i = 1; i < LEN(twos); i++)
			twos[i] += twos[i-1];
		ll acu = 0;
		ll ans = INF<ll>;
		for (int i = 0; i <= LEN(ones); i++) {
			if (i)
				acu += ones[i-1];
			// cerr << "  i = " << i << ", acu = " << acu << '\n';
			auto it = lower_bound(ALL(twos), m-acu);
			
			ll now = acu;
			int q_2 = 0;
			if (acu < m and LEN(twos) and it != twos.end()) {
				q_2 += (it-twos.begin())+1;
				now += *it;
			}
			if (now >= m)
				ans = min(ans, 2LL*q_2 + i);
		}
		if (ans == INF<ll>)
			cout << -1 << '\n';
		else
			cout << ans << '\n';
	}

	return 0;
}
