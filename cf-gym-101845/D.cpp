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

using T = ll;

struct pt {
	T x, y;

	pt(T a, T b) : x(a), y(b) {}
	pt operator+ (pt p) {return {x+p.x, y+p.y};}
	pt operator- (pt p) {return {x-p.x, y-p.y};}
	pt operator* (T v) {return {x*v, y*v};}
	pt operator/ (T v) {return {x/v, y/v};}

	bool operator== (pt p) {return make_pair (x, y) == make_pair (p.x, p.y);}
	bool operator!= (pt p) {return !(operator==(p));}
	bool operator< (const pt& p) const {return pair<T, T>(x, y) < pair<T, T>(p.x, p.y);}
};

T sq (pt p) {return p.x*p.x + p.y*p.y;}
ld abs (pt p) {return sqrt ((ld)sq (p));}

ostream& operator<< (ostream& os, pt p) {
	return os << "(" << p.x << ", " << p.y << ")";
}

T dot (pt a, pt b) { return a.x*b.x + a.y*b.y; }

T cross (pt a, pt b) { return a.x*b.y - a.y*b.x; }

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, m;
	cin >> n >> m;

	vector<pair<pt, int>> p, upper, lower;

	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;	
		p.emplace_back(pt(x, y), i);
	}

	sort(ALL(p));

	vector<pt> pts;
	vi pos(n);
	vector<ll> pre(n + 2, 0);
	ll total = 0;

	{
		pt a = p[0].first, b = p.back().first;
		upper.emplace_back(p[0]);
		lower.emplace_back(p[0]);
		for(int i = 1; i < n - 1; i++)
		{
			if(cross(p[i].first - a, b - a) < 0) upper.emplace_back(p[i]);
			else lower.emplace_back(p[i]);
		}
		upper.emplace_back(p.back());
		lower.emplace_back(p.back());
	
		for(int i = 0; i < LEN(upper) - 1; i++)
		{
			pos[upper[i].second] = LEN(pts);
			pts.emplace_back(upper[i].first);
		}
		for(int i = LEN(lower) - 1; i > 0; i--)
		{
			pos[lower[i].second] = LEN(pts);
			pts.emplace_back(lower[i].first);
		}

		pts.emplace_back(p[0].first);

		for(int i = 0; i < n; i++)
			pre[i + 1] = pre[i] + cross(pts[i], pts[i + 1]);

		total = pre[n];
		// for(int i = 0; i < n + 1; i++)
		// 	cout << pts[i] << " \n"[i == n];
	}

	if(total < 0) total = -total;
	// cout << fixed << total * 0.5 << endl;

	ll ans = 0;

	while(m--)
	{
		int a, b;
		cin >> a >> b;
		--a, --b;
		a = pos[a], b = pos[b];

		if(a > b) swap(a, b);

		ll now = pre[b] - pre[a] + cross(pts[b], pts[a]);
		if(now < 0) now = -now;
		// cout << pts[a] << " " << pts[b] << ": " << now * 0.5 << endl;
		ans = max(ans, min(now, total - now));
	}

	cout << fixed << ans * 0.5 << endl;

	return 0;
}
