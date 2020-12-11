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

const int MOD = 1;
inline int mod(ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

using pll = pair<ll, ll>;

ll cross(pll a, pll b) {
	return a.x*b.y - a.y*b.x;
}

int quarter(pll a) {
	if(a.x >= 0 and a.y >= 0) return 1;
	else if(a.x < 0 and a.y >= 0) return 2;
	else if(a.x < 0 and a.y < 0) return 3;
	else return 4;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(30);

	int n;
	cin >> n;
	vector<pll> vec;
	for(int i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		if(x or y)
			vec.push_back({x, y});
	}
	n = LEN(vec);
	sort(ALL(vec), [&](const pll &lhs, const pll &rhs) {
		if(quarter(lhs) == quarter(rhs)) return cross(lhs, rhs) > 0;
		else return quarter(lhs) < quarter(rhs);
	});

	ll ans = 0;
	for(int i = 0; i < n; i++) {
		pll now = {0, 0};
		for(int j = i, q = 0; j < 2*n and q < n; j++, q++) {
			int p = j%n;
			now.x += vec[p].x, now.y += vec[p].y;
			ans = max(ans, now.x*now.x + now.y*now.y);
		}
	}
	cout << sqrt((ld)ans) << '\n';


	return 0;
}
