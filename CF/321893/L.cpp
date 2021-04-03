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

const int MAXN = 1e7 + 10;

bitset<MAXN> not_prime;

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (int i = 2; i*i < MAXN; i++)
		for (int j = i*i; j < MAXN; j+=i)
			not_prime[j] = 1;
	
	vi primes;
	for (int i = 2; i*i < MAXN; i++)
		if (!not_prime[i])
			primes.push_back(i);
	
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int ans = 0;
		for (int p : primes) {
			// cerr << "p = " << p << ", a = " << a << ", b = " << b << '\n';
			if (a == 1 and b == 1) break;
			if (a%p == 0 or b%p == 0) ++ans;
			while (a%p == 0) a/=p;
			while (b%p == 0) b/=p;
		}
		// cerr << a << ' ' << b << '\n';
		if ((a != 1 and b == 1) or (a == 1 and b != 1))
			++ans;
		else if (a > 1 and b > 1)
			ans += 1 + (a != b);
		cout << ans << '\n';
	}


	return 0;
}
