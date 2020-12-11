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

const ld EPS = 1e-11;
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

vpii points[4];
set<pair<pii, int>> st_pts;

int conv(char c) {
	if(c == 'R')
		return 0;
	else if(c == 'L')
		return 1;
	else if(c == 'U')
		return 2;
	return 3;
}

ld eval(ld now) {
	ld x_max = -1e18;
	ld x_min = 1e18;
	ld y_max = -1e18;
	ld y_min = 1e18;
	for(auto [pt, tt] : st_pts) {
		ld x = pt.x;
		ld y = pt.y;
		if(tt == 0)
			x += now;
		else if(tt == 1)
			x -= now;
		else if(tt == 2)
			y += now;
		else
			y -= now;
		// cout << x << ' ' << y << '\n';
		x_max = max(x_max, x);
		x_min = min(x_min, x);
		y_max = max(y_max, y);
		y_min = min(y_min, y);
	}
	return (x_max-x_min)*(y_max-y_min);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(20);

	int n;
	cin >> n;
	while(n--) {
		int x, y;
		char c;
		cin >> x >> y >> c;
		// int id = ;
		st_pts.insert({{x, y}, conv(c)});
	}

// ld ans = 1e16;
// for(int i = 1; i < LEN(times); i++) {
// 	ld l = times[i-1], r = times[i];
// 	assert(l >= 0);
// 	// cout << l << ' ' << r << '\n';
// 	// cout << "eval(l) = " << eval(r) << '\n';
	ld l = 0, r = 2e9;
	int iter = 1000;
	while(iter--) {
		ld tl = (2*l+r)/3;
		ld tr = (l+2*r)/3;
		ld etl = eval(tl);
		ld etr = eval(tr);
		// cout << tl << ' ' << tr << '\n';
		// cout << etl << ' ' << etr << '\n';
		if(etl > etr)
			l = tl;
		else
			r = tr;
	}
	// cout << eval(1) << '\n';
	// cout << eval(2) << '\n';
	// cout << eval(3) << '\n';
	// ans = min(ans, eval(l));
	// }
	cout << eval(l) << '\n';


	return 0;
}
