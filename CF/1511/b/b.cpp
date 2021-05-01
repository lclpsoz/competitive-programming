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


vi primes[11];

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (ll base = 1, dg = 1; base < 1e9; base*=10, dg++) {
		ll nxt = base*10;
		for (int i = 0; i < 100 and i < nxt; i++) {
			int now = base+i;
			if (now == 1 or now == 2) continue;
			bool is_prime = true;
			for (int j = 2; is_prime and j*j <= i; j++)
				if (now%j == 0) is_prime = false;
			if (is_prime)
				primes[dg].push_back(now);
		}
	}


	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == b and b == c)
			cout << primes[a][0] << ' ' << primes[a][0] << '\n';
		else {
			ll x, y;
			x = y = primes[c][0];
			// cerr << "|" << x << '\n';
			while (a > c) {
				x *= 10;
				a--;
			}
			while (b > c) {
				y *= 11;
				b--;
			}
			cout << x << ' ' << y << '\n';
		}		
	}

	return 0;
}
