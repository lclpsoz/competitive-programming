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

ll mdc(ll a, ll b) {
	if(a == 0) return a;
	return mdc(b%a, a);
}

int inv_mod(int b, int p, int m) {
	int ret = 1;
	while(p) {
		if(p&1) ret = (ret * 1LL * b)%m;
		b = (b * 1LL * b)%m;
		p >>= 1;
	}
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int a, b, p;
	ll x;
	cin >> a >> b >> p >> x;

	bi pw_a(p+10);
	map<int, int> used;
	ll ans = 0;
	int cycle_start = -1;
	int cycle_len = -1;
	int base = 1;
	for(int i = 1; i <= p; i++) {
		base = (base * 1LL * a)%p;
		pw_a[i] = base;
		if(used.count(base)) {
			cycle_start = used[base];
			cycle_len = i-cycle_start;
			break;
		}
		used[base] = i;
	}
	base = 1;
	for(int i = 1; i < cycle_start; i++) {
		ans += (i*1LL*pw_a[i])%p == b;
	}
	
	for(int i = cycle_start; i < cycle_start+cycle_len; i++) {
		int need = (inv_mod(pw_a[i], p-2, p) * 1LL * b)%p;
		for(int j = i; j <= x; j += cycle_len)
			if(j%p == need) {
				
				break;
			}
	}

	return 0;
}
