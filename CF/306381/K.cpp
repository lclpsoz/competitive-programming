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

ll bin_search (ll bef_val, ll bef_delta, ll now_val, ll now_delta) {
	ll l = 0, r = 2*INF<int>;
	while (l < r) {
		ll md = (l+r)/2;
		if (bef_val + bef_delta*md >= now_val + now_delta*md)
			r = md;
		else
			l = md+1;
	}
	return l;
}

void no () {
	cout << "-1\n";
	exit(0);
}

int main () {
	freopen("plants.in", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n;
	cin >> n;
	vector<ll> h(n), g(n);

	for (ll &v : h)
		cin >> v;
	for (ll &v : g)
		cin >> v;

	ll l = 0, r = 2*INF<int>;
	for (int i = 1; i < n; i++) {
		if (g[i-1] > g[i])
			r = min(r, bin_search(h[i-1], g[i-1], h[i], g[i]));
		else if (g[i-1] < g[i])
			l = max(l, bin_search(h[i], g[i], h[i-1], g[i-1]));
		else if (h[i-1] > h[i])
			no();
		// cerr << i << ": " << l << ", " << r << '\n';
	}
	if (l <= r)
		cout << l << '\n';
	else
		no();

	return 0;
}
