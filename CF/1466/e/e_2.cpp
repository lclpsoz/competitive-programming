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
const int MOD = 1e9+7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

inline int mult (int a, int b) {
	return mod(a*1LL*b);
}

inline int mult (ll a, int b) {
	return mod(mod(a)*1LL*b);
}

inline int mult (int a, ll b) {
	return mod(a*1LL*mod(b));
}

inline int mult (ll a, ll b) {
	return mod(mod(a)*1LL*mod(b));
}

int solve (vector<ll> &vec) {
	int n = LEN(vec);
	ll ret = 0;
	vi cnt(61);
	for (ll v : vec)
		for (int j = 0; j <= 60; j++)
			cnt[j] += (v&(1LL<<j))>0;

	vi mult_cnt(61);
	for (int i = 0; i <= 60; i++)
		mult_cnt[i] = mult(cnt[i], (1LL<<i));

	for (ll v : vec) {
		ll shift = 0;
		for (int i = 0; i <= 60; i++)
			if ((1LL<<i)&v)
				shift += mult_cnt[i];
		ll ax = 0;
		for (int i = 0; i <= 60; i++)
			if ((1LL<<i)&v)
				ax += mult(1LL<<i, n);
			else
				ax += mult(1LL<<i, cnt[i]);
		// cerr << "v = " << v << ", shift = " << shift << ", ret = " << ret << '\n';		
		ret += mult(ax, shift);
	}
	// for (int i = 0; i <= 60; i++)
	// 	cerr << i << ": " << temp[i] << ", calc[" << i << "] = " << calc[i] << '\n';

	return mod(ret);
}

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
		vector<ll> vec;
		for (int i = 0; i < n; i++) {
			ll v;
			cin >> v;
			vec.push_back(v);
		}
		// cerr << "BRUTE:\n";
		// brute(vec);
		// cerr << "-- END BRUTE\n";
		cout << solve(vec) << '\n';
	}

	return 0;
}
