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
const int MOD = 1e9 + 7;

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;

int fat[N];
int pre_inv[N];

int pow_mod (int v, int p) {
	int ret = 1;
	while (p) {
		if (p&1) 
			ret = (ret * 1LL * v) % MOD;
		p >>= 1;
		v = (v * 1LL * v)%MOD;
	}
	return ret;
}

int inv_mod (int v) {
	return pow_mod(v, MOD-2);
}

int bin (int n, int k) {
	return (((fat[n] * 1LL * pre_inv[k])%MOD) * 1LL * pre_inv[n-k])%MOD;
	// if (k == n or k == 0) return 1;
	// return bin(n-1, k-1) + bin(n, k-1);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	fat[0] = fat[1] = 1;
	pre_inv[0] = pre_inv[1] = inv_mod(1);
	for (int i = 2; i < N; i++) {
		fat[i] = (fat[i-1] * 1LL * i)%MOD;
		pre_inv[i] = inv_mod(fat[i]);
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		vi vec(n);
		for (int &v : vec)
			cin >> v;
		if (m == 1)
			cout << n << '\n';
		else {
			sort(ALL(vec));

			ll ans = 0;
			int l = 0, r = 0;
			// cerr << "\nt = " << t << '\n'; 
			while (l < n) {
				while (r < n and vec[r]-vec[l] <= k)
					++r;
				// cerr << "  l = " << l << ", r = " << r << '\n';
				if (r-l >= m) {
					// cerr << "    sz ok!\n";
					ans = (ans + bin(r-l-1, m-1))%MOD;
				}
				++l;
			}	
			cout << ans << '\n';
		}
	}

	return 0;
}
