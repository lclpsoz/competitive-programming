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

ll cross(pii a, pii b) {
	return a.x*1LL*b.y-a.y*1LL*b.x;
}

int quarter(pii a) {
	if(a.x >= 0 and a.y >= 0)
	    return 1;
	else if(a.x < 0 and a.y >= 0)
	    return 2;
	else if(a.x < 0 and a.y < 0)
	    return 3;
	return 4;
}
bool cmp_radial(const pii &lhs, const pii &rhs) {
	if(quarter(lhs) == quarter(rhs))
	    return cross(lhs, rhs) > 0;
	return quarter(lhs) < quarter(rhs);
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vector<pair<pii, int>> vec;
	ll total = 0;
	for(int i = 0; i < n; i++) {
		int x, y, g;
		cin >> x >> y >> g;
		total += g;
		vec.push_back({{x, y}, g});
	}
	// pii holder = {2000000001, 2000000001};
	ll ans = 2e18;
	for(int i = 0; i < n; i++) {
		// cout << "i = " << i << ", ans = " << ans << '\n';
		// cout.flush();
		// cout << center.x << '\n';
		int d_x = vec[i].x.x;
		int d_y = vec[i].x.y;
		vector<pair<pii, int>> points;
		for(int j = 0; j < n; j++)
			if(i!=j)
				points.push_back({{vec[j].x.x-d_x, vec[j].x.y-d_y}, vec[j].y});
		sort(ALL(points), [&](auto _lhs, auto _rhs) {
			return cmp_radial(_lhs.x, _rhs.x);
		});
		// for(auto pp : points)
		// 	cout << '(' << pp.x.x << ',' << pp.x.y << ") " << pp.y << "\n";
		int l = 0, r = 0;
		ll val_now = 0;
		int m = n-1;
		while(l < 2*m and r < 2*m) {
			pii vec_line = {points[l%m].x.x, points[l%m].x.y};
			r = max(l, r);
			while(cross(vec_line, points[(r+1)%m].x) > 0) {
				val_now += points[(r+1)%m].y;
				++r;
			}
			ll total_now = total - vec[i].y - points[l%m].y;
			// cout << "  l = " << l << ", r = " << r << ", val = " << val_now << ", now = " << abs(total_now-2*val_now) << '\n';
			// cout.flush();
			ans = min(ans, abs(total_now-2*val_now));
			++l;
			if(l <= r)
				val_now -= points[l%m].y;
		}
		
	}
	cout << ans << '\n';

	return 0;
}
