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

ld area (ld a, ld b, ld c) {
	if (fcmp(a, b+c) >= 0 or fcmp(b, a+c) >= 0 or fcmp(c, a+b) >= 0)
		return 0;
	ld s = (a+b+c)/2;
	return sqrt(s*(s-a)*(s-b)*(s-c));
}

int main () {
	freopen("sticks.in", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(20);

	int t; cin >> t;
	while(t--)
	{
		vi x(3);
		int k;
		for (int &v : x) cin >> v;
		cin >> k;
		sort(ALL(x));
		k = min(k, x[1]+x[2]-x[0]);
		ld l, r;
		l = 0, r = k;
		for (int i = 0; i < 300; i++) {
			ld lmd = (2*l + r)/3;
			ld rmd = (l + 2*r)/3;
			if (area(x[0]+lmd, x[1], x[2]) > area(x[0]+rmd, x[1], x[2]))
				r = rmd;
			else
				l = lmd;
			// cerr << l << ' ' << r << '\n';
		}
		// for (int base = 1; (1+base*0.01)*x[0] <= k; base++) {
		// 	ld now = (1+base*0.01)*x[0];
		// 	cout << now << ": " << area(now, x[1], x[2]) << '\n';
		// }
		cout << fixed << area (x[0]+l, x[1], x[2]) << '\n';
	}

	return 0;
}
