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

const int P = 1000;
using u128 = __uint128_t;

// bitset<P> not_prime;
vector<ll> primes, amount;
ll sum;
ll ans = 0;
int num_calls = 0;

void dfs (int pos, u128 prod) {
	// cerr << "pos = " << pos << '\n';
	++num_calls;
	if (pos == LEN(primes))
		return;
	int val = primes[pos];
	int uses = 0;
	while (prod < sum and uses <= amount[pos]) {
		// cerr << "  sum = " << sum << ", prod = " << (ll)prod << '\n';
		dfs (pos+1, prod);
		// if (val == 2)
		// 	cerr << "oi!\n";
		sum -= val;
		uses++;
		prod *= val;
		if (uses > amount[pos]) break;
		if (prod == sum)
			ans = max(ans, sum);
	}
	sum += uses * val;
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// for (int i = 2; i*i < P; i++)
	// 	if (!not_prime[i])
	// 		for (int j = i*i; j < P; j+=i)
	// 			not_prime[j] = 1;

	// for (int i = 2; i < P; i++)
	// 	if (!not_prime[i])
	// 		primes.push_back(i);
	
	// for (int p : primes)
	// 	cout << p << ' ' << 10000000000000 << '\n';

	int n_tests;
	cin >> n_tests;
	for (int t = 1; t <= n_tests; t++) {
		// cerr << "t = " << t << '\n';
		int n;
		cin >> n;
		sum = ans = 0;
		num_calls = 0;
		for (int i = 0; i < n; i++) {
			ll x, y;
			cin >> x >> y;
			primes.push_back(x);
			amount.push_back(y);
			sum += x*y;
		}
		// cerr << "sum = " << sum << '\n';
		dfs(0, 1);
		// cerr << "num_calls = " << num_calls << '\n';
		cout << "Case #" << t << ": " << ans << '\n';
		primes.clear();
		amount.clear();
	}

	return 0;
}
