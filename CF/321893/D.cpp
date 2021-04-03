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

const int MAXP = 1e6 + 10, MAXN = 1e6 + 5;

bitset<MAXP> not_prime;
vi ans[MAXN];

int fast_exp (int b, int p, int md) {
	int ret = 1;
	ll base = b;
	while (p) {
		if (p&1) ret = (ret*1LL*base)%md;
		// cerr << "ret = " << ret << '\n';
		p>>=1;
		base=(base*1LL*base)%md;
	}
	return ret;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (int i = 2; i*i < MAXP; i++)
		for (int j = i*i; j < MAXP; j+=i)
			not_prime[j] = 1;

	// cerr << fast_exp(2, 5, 115) << '\n';
	// exit(0);
	for (int i = 3; i < MAXP; i++) {
		if (!not_prime[i]) {
			int k = (i-fast_exp(2, i, i)+i)%i;
			// cerr << i << ", k = " << k << '\n';
			int ax = k;
			while (ax < MAXN) {
				ans[ax].push_back(i);
				ax += i;
			}
		}
	}

	// for (int i = 2; i <= 100000; i++) {
	// 	cerr << "k = " << i << ": ";
	// 	for (int v : ans[i])
	// 		cerr << " " << v;
	// 	cerr << '\n';
	// }

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		if (LEN(ans[k]) == 0)
			cout << "-1\n";
		else 
			for (int i = 0; i < LEN(ans[k]); i++)
				cout << ans[k][i] << " \n"[i==LEN(ans[k])-1];
	}

	return 0;
}
