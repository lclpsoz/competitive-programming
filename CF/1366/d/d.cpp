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

const int N = 1e7 + 5;

int small_p[N];

pii solve (int x) {
	// cerr << "i = " << i << ", x = " << x << '\n';
	if (small_p[x] == 0) return {-1, -1};
	int ax = small_p[x];
	while (x%(ax*1LL*small_p[x]) == 0)
		ax *= small_p[x];
	if (ax == x or x/ax == ax or gcd(x/ax, ax) != 1) {
		return {-1, -1};
	}
	else
		return {ax, x/ax};
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	for (int i = 2; i*i < N; i++)
		for (int j = i; j < N; j+=i)
			if (!small_p[j])
				small_p[j] = i;

	int n;
	cin >> n;
	vi l(n), r(n);
	for (int i = 0; i < n; i++) {

		int x;
		cin >> x;
	// for (int x = 2; x <= 1e7; x++) {
		// cerr << "x = " << x << '\n';
		auto [a, b] = solve(x);
		l[i] = a, r[i] = b;
		// if (a != -1) {
		// 	if (gcd(a+b, x) != 1) {
		// 		cerr << "wrong " << x << " -> " << a << ", " << b << '\n';
		// 		cerr << gcd(a+b, x) << '\n';
		// 		exit(0);
		// 	}
		// }
		// else {
		// 	for (int j = 2; j*j <= x; j++)
		// 		for (int k = 2; k*k <= x; k++)
		// 			if (x%j == 0 and x%k == 0 and gcd(j + k, x) == 1)  {
		// 				cerr << "fail " << x << '\n';
		// 				exit(0);
		// 			}
		// }
	}
	for (int i = 0; i < n; i++)
		cout << l[i] << " \n"[i==n-1];
	for (int i = 0; i < n; i++)
		cout << r[i] << " \n"[i==n-1];

	return 0;
}
