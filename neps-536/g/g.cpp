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

inline int fcmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

void brute () {
	bitset<100> a, b;
	a[0] = 1;
	for (int i = 1; i < 64; i++) {
		cerr << i << ' ' << bitset<8>(i) << ":\t";
		for (int j = 0; j < i; j++)
			cerr << a[j];
		cerr << ' ';
		a = a^(a<<1);

		int ax = i-1;
		vi now;
		for (int j = 0; (1LL<<j) <= ax; j++)
			if (!(ax&(1<<j)))
				now.push_back(j);
		for (int j = 0; j <= ax; j++) {
			bool bit = 1;
			for (int p : now)
				if ((1<<p)&j) {
					bit = 0;
					break;
				}
			cerr << bit;
		}
		cerr << '\n';
			
	}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	// brute();

	int n;
	cin >> n;
	vector<ll> vec(n);
	for (ll &v : vec) cin >> v;
	ll ans = 0;
	int ax = n-1;
	vi now;
	for (int j = 0; (1LL<<j) <= ax; j++)
		if (!(ax&(1LL<<j)))
			now.push_back(j);
	for (int j = 0; j <= ax; j++) {
		bool bit = 1;
		for (int p : now)
			if ((1LL<<p)&j) {
				bit = 0;
				break;
			}
		if (bit) {
			if (vec[j] == -1) {
				cout << -1 << '\n';
				exit(0);
			}
			ans ^= vec[j];
		}
	}
	cout << ans << '\n';

	return 0;
}
