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

ll bin[55][55];
ll vals[55];

ll f_bin(int x, int y) {
	if(x==y or y == 0) return 1;
	if(bin[x][y] != 0) return bin[x][y];
	return bin[x][y] = f_bin(x-1, y-1) + f_bin(x-1, y);
}

ll solve(int p, int k, ll maxi) {
	if(k == 0) return 1;
	if(p < k-1) return 0;
	if(p == 0)
		return vals[p] <= maxi;
	ll ret = 0;
	if(p >= k and vals[p] <= maxi)
		ret = f_bin(p, k);
	else if(vals[p] > maxi)
		ret = solve(p-1, k, maxi);
	if(vals[p] <= maxi)
		ret += solve(p-1, k-1, maxi-vals[p]);
	// cout << "p = " << p << ", k = " << k << ", maxi = " << maxi << " => " << ret << '\n';
	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, k;
	ll a, b;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> vals[i];
	sort(vals, vals + n);
	cin >> a >> b;
	cout << solve(n-1, k, b)-solve(n-1, k, a-1) << '\n';
	

	return 0;
}
