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

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1e9+7;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

int fat[2020], inv[2020];

int inv_mod(int x) {
	int ret = 1;
	int p = MOD-2;
	while(p) {
		if(p&1) ret = (ret*1LL*x)%MOD;
		x = (x*1LL*x)%MOD;
		p /= 2;
	}
	return ret;
}

int bin(int n, int k) {
	return ((fat[n]*1LL*inv[n-k])%MOD*1LL*inv[k])%MOD;
}


int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);
	int n;
	cin >> n;
	fat[0] = fat[1] = 1;
	inv[0] = inv[1] = 1;
	for(int i = 2; i < 2020; i++) {
		fat[i] = (fat[i-1]*1LL*i)%MOD;
		inv[i] = inv_mod(fat[i]);
		// cout << i << ' ' << fat[i] << ' ' << inv[i] << '\n';
	}
	int ans = 0;
	for(int i = 1; 3*i <= n; i++) {
		int balls = n - 3*i;
		int boxes = i;
		ans = (ans + bin(balls+boxes-1, balls))%MOD;
	}
	cout << ans << '\n';

	return 0;
}
