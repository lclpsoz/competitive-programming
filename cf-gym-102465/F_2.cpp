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

ll cross(const pii &lhs, const pii &rhs) {
	return lhs.x*1LL*rhs.y - lhs.y*1LL*rhs.x;
}

int quarter(const pii &pt) {
	if(pt.x >= 0 and pt.y >= 0)
		return 0;
	else if(pt.x <= 0 and pt.y >= 0)
		return 1;
	else if(pt.x < 0 and pt.y < 0)
		return 2;
	return 3;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vector<pair<pii, int>> all_points;
	ll total = 0;
	for(int i = 0; i < n; i++) {
		int x, y, g;
		cin >> x >> y >> g;
		all_points.push_back({{x, y}, g});
		total += g;
	}

	ll ans = 1e19;
	for(auto &[center, center_g] : all_points) {
		vector<pair<pii, int>> points;
		for(auto &point : all_points)
			if(point.x != center)
				points.push_back({{point.x.x-center.x, point.x.y-center.y}, point.y});
		
		sort(ALL(points), [&](const pair<pii, int> &lhs, const pair<pii, int> &rhs) {
			if(quarter(lhs.x) == quarter(rhs.x)) return cross(lhs.x, rhs.x) > 0;
			return quarter(lhs.x) < quarter(rhs.x);
		});

		int m = n-1;
		int l = 0, r = 0;
		ll sum_now = 0;
		while(l < 2*m and r < 2*m) {
			pii line_vec = points[l%m].x;
			r = max(l, r);
			// cout << "here!\n";
			// cout.flush();
			while(cross(line_vec, points[(r+1)%m].x) > 0) {
				++r;
				sum_now += points[r%m].y;
				// cout << "  r = " << r << '\n';
				// cout.flush();
			}
			ll total_now = total - points[l%m].y - center_g;
			// cout << "l = " << l  << ", r = " << r << ", sum_now = " << sum_now << '\n';
			// cout.flush();
			ans = min(ans, abs(total_now - 2*sum_now));
			++l;
			if(l <= r)
				sum_now -= points[l%m].y;
		}
		// cout << "  ans = " << ans << "\n\n";
	}
	cout << ans << '\n';

	return 0;
}
