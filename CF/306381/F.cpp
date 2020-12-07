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
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

ll brute_ans (ll s1, ll s2, ll xl, ll xr) {
	ll ans = 0;
	for (ll x = xl; x <= xr; x++) {
		ll val = ((s1 * 1ll * x) ^ (s2 * 1ll * x));
		ll sum = val % MOD;
		ans = (ans + sum) % MOD;
	}
	return ans;
}

int target[100];

ll solve (int pos, bool smaller, string &number) {
	if (pos == -1)
		return 1LL;

	ll ret;
	if (target[pos] == -1) {
		if (smaller)
			ret = 2*solve (pos-1, smaller, number);
		else if (number[pos] == '1') {
			ret = solve (pos-1, true, number) + 
					solve (pos-1, false, number);
		}
		else {
			ret = solve (pos-1, false, number);
		}
	}
	else {
		if (smaller)
			ret = solve (pos-1, smaller, number);
		else if (target[pos] == 1) {
			if (number[pos] == '0')
				ret = 0LL;
			else
				ret = solve (pos-1, smaller, number);
		}
		else {
			if (number[pos] == '1')
				ret = solve (pos-1, true, number);
			else
				ret = solve (pos-1, smaller, number);
		}
	}

	return ret;
}

ll solve (string &number, int p1, int c1, int p2 = -1, int c2 = -1) {
	target[p1] = c1;
	if (p2 != -1)
		target[p2] = c2;
	ll ret = solve (LEN(number)-1, 0, number);
	target[p1] = -1;
	target[p2] = -1;
	return ret;
}

string bin_string (ll val) {
	if (val == 0) return "0";
	memset(target, -1, sizeof target);
	string number = bitset<70>(val).to_string();
	reverse(ALL(number));
	while (number.back() == '0') number.pop_back();
	reverse(ALL(number));
	return number;
}

int main () {
	freopen("geometry.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	memset(target, -1, sizeof target);
	int t;
	cin >> t;
	map<ll, int> mp;
	while (t--) {
		ll s1, s2, xl, xr;
		cin >> s1 >> s2 >> xl >> xr;
		ll ans = 0;
		if (s1 > s2) swap(s1, s2);
		if (s1 < s2) {
			int k1 = __builtin_ctzll(s1);
			int k2 = __builtin_ctzll(s2);
			int SHIFT = k2-k1;
			s1 = s1%MOD;
			s2 = s2%MOD;
			string number_xr = bin_string(xr);
			string number_xl = bin_string(xl-1);
			reverse(ALL(number_xl));
			reverse(ALL(number_xr));
			for (int i = 0; i < min(LEN(number_xr), SHIFT); i++) {
				ll val_r = solve(number_xr, i, 1);
				ll val_l = 0;
				if (xl > 1 and i < LEN(number_xl))
					val_l = solve(number_xl, i, 1);
				ll v1 = (val_r-val_l)%MOD;
				ll v2 = (1LL<<i)%MOD;
				ll mlt = (v1*v2)%MOD;
				ans = (ans+(s1*mlt)%MOD)%MOD;
			}

			for (int i = 0; i < LEN(number_xr); i++) {
				ll val_r = solve(number_xr, i, 1, i+SHIFT, 0);
				
				ll val_l = 0;
				if (xl > 1 and i < LEN(number_xl))
					val_l = solve(number_xl, i, 1, i+SHIFT, 0);
				ll pw = (1LL<<i)%MOD;

				ll v1 = (val_r-val_l)%MOD;
				ans = (ans + (s2*((v1*pw)%MOD))%MOD)%MOD;

				if (i >= SHIFT) {		
					val_r = solve(number_xr, i, 1, i-SHIFT, 0);
					if (xl > 1 and i < LEN(number_xl))
						val_l = solve(number_xl, i, 1, i-SHIFT, 0);
					// cout << "  val_r = " << val_r << '\n';
					v1 = (val_r-val_l)%MOD;
					ans = (ans + (s1*((v1*pw)%MOD)))%MOD;
				};
			}
		}
		cout << ans << endl;
	}

	return 0;
}
