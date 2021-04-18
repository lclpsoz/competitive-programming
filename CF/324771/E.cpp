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
const T INF = (is_same<T, int>::value ? 1e9 : 9e18);
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

using u128 = __uint128_t;
const u128 INF_128 = (u128)INF<ll>*sqrt(INF<ll>);

const int N = 1e5 + 10;

int n, m;
int t[N];

u128 gcd_u128 (u128 x, u128 y) {
	if (y == 0) return x;
	return gcd_u128(y, x%y);
}

void impossible () {
	for (int i = 1; i <= n; i++)
		cout << "Never\n";
	exit(0);
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// vi vec;
	// for (int i = 1e9-3000; i <= INF<int>; i++) {
	// 	bool is_prime = true;
	// 	for (int j = 2; is_prime and j*j <= i; j++)
	// 		if (i%j == 0) is_prime = false;
	// 	if (is_prime)
	// 		vec.push_back(i);
	// }
	// reverse(ALL(vec));
	// for (int i = 0; i < 100; i++)
	// 	cerr << vec[i] << '\n';
	// for (int i = INF<int>; i >= INF<int>-10; i--)
	// 	cerr << i << '\n';

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> t[i];

	vector<u128> pref_lcm(n+1);
	pref_lcm[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (pref_lcm[i-1] > INF_128/t[i])
			impossible();
		pref_lcm[i] = (pref_lcm[i-1] * t[i])/gcd_u128(pref_lcm[i-1], t[i]);
	}
	vector<u128> suf_lcm(n+2);
	suf_lcm[n+1] = 1;
	for (int i = n; i >= 1; i--) {
		if (suf_lcm[i+1] > INF_128/t[i])
			impossible();
		suf_lcm[i] = (suf_lcm[i+1] * t[i])/gcd_u128(suf_lcm[i+1], t[i]);
	}

	for (int i = 1; i <= n; i++) {
		u128 lhs = pref_lcm[i-1];
		u128 rhs = suf_lcm[i+1];
		u128 g = gcd_u128(lhs, rhs);
		if (lhs > rhs) lhs /= g;
		else rhs /= g;
		if ((ld)lhs > (ld)INF<ll>/rhs and (ld)rhs > (ld)INF<ll>/lhs)
			cout << "Never\n";
		else {
			u128 now = lhs * rhs;
			if (now%t[i] == 0 or now > INF<int>+m)
				cout << "Never\n";
			else {
				assert(now < INF<ll>);
				u128 ax = now;
				now = (m/now)*now;
				while (now < m or (now <= INF<int>+m and now%t[i] == 0))
					now += ax;
				assert(now < INF<ll> and now >= m);
				ll ans = now-m;
				if (ans > INF<int>)
					cout << "Never\n";
				else
					cout << ans << '\n';
			}
		}
	}

	return 0;
}
