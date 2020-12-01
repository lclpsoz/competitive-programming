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


ll calc_dist(vpii &pts, vpii &sq) {
	vector<pair<ll, ll>> dists;
	vi cnt(4);
	vector<ll> mini(4, INF<ll>);
	vector<vector<ll>> vals(4);
	ll ret = 0;
	for(int i = 0; i < 4; i++) {
		dists.push_back({sq[i].x-pts[i].x, sq[i].y-pts[i].y});
		ret += abs(dists.back().x) + abs(dists.back().y);
		if(dists.back().x > 0) {
			cnt[0]++;
			vals[0].push_back(abs(dists.back().x));
		}
		if(dists.back().x < 0)
			cnt[1]++, vals[1].push_back(abs(dists.back().x));
		if(dists.back().y > 0)
			cnt[2]++, vals[2].push_back(abs(dists.back().y));
		if(dists.back().y < 0)
			cnt[3]++, vals[3].push_back(abs(dists.back().y));
	}
	for(int i = 0; i < 4; i++)
		if(cnt[i] > 2) {
			sort(ALL(vals[i]));
			ret -= (cnt[i] == 3 ? 2 : 4)*vals[i][0];
			if(cnt[i] == 4) {
				ret -= 2*(vals[i][1]-vals[i][0]);
			}

		}

	return ret;
}

ll eval(ll sz, vpii vec) {
	ll ret = 1e18;
	vpii sq = {	{0, 0},
				{sz, 0},
				{sz, sz},
				{0, sz}};
	do {
		ret = min(ret, calc_dist(vec, sq));
	} while(next_permutation(ALL(vec)));

	return ret;
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int t;
	cin >> t;
	while(t--) {
		vpii pts;
		int mx = -1;
		for(int i = 0; i < 4; i++) {
			int x, y;
			cin >> x >> y;
			pts.push_back({x, y});
			mx = max(mx, y);
			mx = max(mx, x);
		}
		ll l = 0, r = mx+1;
		sort(ALL(pts));
		int mx_op = 1e3;
		while(l < r-2 and mx_op--) {
			ll tl = (2*l + r)/3;
			ll tr = (l + 2*r)/3;
			// cerr << l << ' ' << r << '\n';
			// cerr << eval(l, pts) << ' ' << eval(r, pts) << '\n';
			if(eval(tl, pts) > eval(tr, pts))
				l = tl;
			else
				r = tr;
		}
		ll ans = INF<ll>;
		for(int i = max(0LL, l-2); i < r+2; i++)
			ans = min(ans, eval(i, pts));
		// for(int i = 0; i < 8; i++)
		// 	cerr << "eval(" << i << ") = " << eval(i, pts) << '\n';
		cout << ans << '\n';
	}

	return 0;
}
