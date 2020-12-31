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
	return x%m;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

inline int mult (ll a, ll b) {
	return mod(mod(a)*1LL*mod(b));
}

int solve (vector<ll> &vec) {
	int n = LEN(vec);
	ll ret = 0;
	vi cnt(61);
	vpii cnt2(61);
	for (ll v : vec)
		for (int j = 0; j <= 60; j++)
			cnt[j] += (v&(1LL<<j))>0;

	vi active(62);
	for (ll v : vec) {
		int amount = __builtin_popcountll(v);
		for (int i = 0; i <= 60; i++)
			if (v&(1LL<<i))
				active[i] += amount;
	}
	// vi temp(62);
	for (int bit = 0; bit <= 60; bit++) {
		int qnt = cnt[bit];
		ll shift = 1LL<<bit;
		ll ax = 0;
		cnt2.assign(LEN(cnt2), {0, 0});
		vector<ll> mov(30);
		for (ll v : vec) {
			if (v&shift) {
				int p = 0;
				ll msk = 0;
				do {
					msk = mov[p] & v;
					mov[p] ^= v;
					v = msk;
					++p;
				} while(v);
			}
		}
		for (int i = 0; i < LEN(mov); i++)
			if (mov[i]) {
				int val = 1<<i;
				for (int j = 0; j <= 60; j++)
					if (mov[i]&(1LL<<j))
						cnt2[j].x+=val;
			}
		for (int j = 0; j <= 60; j++) {
			// ax = mod(ax + mult(1LL<<j, mult(n, cnt2[j].x)+mult(cnt[j], qnt-cnt2[j].x)));
			ll j_const = mult(1LL<<j, n-cnt[j]);
			ax = mod(ax + mult(cnt2[j].x, j_const));
			// temp[j] += cnt2[j].x;
		}

		for (int j = 0; j <= 60; j++)
			ax = mod(ax + mult(1LL<<j, mult(cnt[j], cnt[bit])));
		ret = mod(ret + mult(ax, mult(qnt, shift)));
	}
	// for (int i = 0; i <= 60; i++)
	// 	cerr << i << ": " << temp[i] << ", calc[" << i << "] = " << calc[i] << '\n';

	return ret;
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
		cout << solve(vec) << '\n';
	}

	return 0;
}
