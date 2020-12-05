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

ll solve (int a, int b) {
	for (int x = 1; x < a and x < b; x++)
		if (b%x == 0) {
			ll val = 1;
			for (int i = 0; val <= a and i < b/x; i++)
				val *= x;
			// cout << "x = " << x << ", val = " << val << '\n';
			if (val == a)
				return x;
		}
	
	ll val = 1;
	for (int c = 1; val < INF<ll> and b*1LL*c <= INF<ll>; c++) {
		val *= a;
		if (val == b*1LL*c)
			return val;
	}

	return 0;
}

bool check (ll a, int b, ll x) {
	ll val_a = 1;
	for(int i = 0; i < x; i++)
		val_a = (a*1LL*val_a)%MOD;

	ll val_b = 1;
	for(int i = 0; i < b; i++)
		val_b = (x*1LL*val_b)%MOD;
	
	return val_a == val_b;
}

void brute () {
	for(int a = 2; a <= 50; a++)
		for(int b = 2; b <= 50; b++) {
			int now = 0;
			for (int x = 2; x < 50; x++)
				if (check(a, b, x)) {
					now = x;
					break;
				}
			if (solve (a, b) < 50 and now != solve (a, b)) {
				cout << "a = " << a << ", b = " << b << ", now = " << now << ", solve = " << solve(a, b) << '\n';
				exit(0);
			}
		}
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	brute();

	int a, b;
	cin >> a >> b;
	cout << solve(a, b) << '\n';

	return 0;
}
