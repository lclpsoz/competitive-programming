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

const int N = 5e5 + 10;

struct seg_tree {
	int n;
	vpii seg;

	seg_tree(int _n) : n(_n) {
		seg = vpii(4*n);
		build(1, 1, n);
	}

	void build(int v, int tl, int tr) {
		if(tl == tr)
			seg[v] = {n, INF<int>};
		else {
			int tm = (tl+tr)/2;
			build(2*v, tl, tm);
			build(2*v+1, tm+1, tr);
			if(seg[2*v].x < seg[2*v+1].x)
				seg[v] = seg[2*v];
			else
				seg[v] = seg[2*v+1];
		}
	}

	void upd(int pos, pii pp, int v, int tl, int tr) {
		if(tl == tr and tl == pos)
			seg[v] = pp;
		else if(tl <= pos and pos <= tr) {
			int tm = (tl+tr)/2;
			upd(pos, pp, 2*v, tl, tm);
			upd(pos, pp, 2*v+1, tm+1, tr);

			if(seg[2*v].x < seg[2*v+1].x)
				seg[v] = seg[2*v];
			else
				seg[v] = seg[2*v+1];
		}
	}

	void upd(int pos, pii pp) {
		// cerr << "upd: " << pos << ", pp = " << pp.x << ' ' << pp.y << '\n';
		upd(pos, pp, 1, 1, n);
	}

	pii qry(int v, int tl, int tr, int l, int r) {
		// cerr << "    qrt(" << l << ") = " << "t = " << tl << ' ' << tr << ", SEG[V] = " << seg[v].x << ' ' << seg[v].y << '\n';
		if(l <= tl and tr <= r)
			return seg[v];
		else {
			int tm = (tl+tr)/2;

			pii ret = {INF<int>, INF<int>};
			if(tl <= r and l <= tm) {
				pii now = qry(2*v, tl, tm, l, r);
				// cerr << "      FRT qrt(" << l << ") = " << "t = " << tl << ' ' << tr << "now = " << now.x << ' ' << now.y << '\n';
				if(now.x < ret.x)
					ret = now;
			}
			if(tm+1 <= r and l <= tr) {
				pii now = qry(2*v+1, tm+1, tr, l, r);
				// cerr << "      SEC qrt(" << l << ") = " << "t = " << tl << ' ' << tr << "now = " << now.x << ' ' << now.y << '\n';
				if(now.x < ret.x)
					ret = now;
			}
			
			return ret;
		}
	}

	pii qry(int l) {

		pii pp = qry(1, 1, n, l, n);
		// cerr << "qry(" << l << "): " << pp.x << ' ' << pp.y << '\n';
		return pp;
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n), lft(n);
	for(int &v : vec)
		cin >> v;
	vi idx(N, -1);
	for(int i = 0; i < LEN(vec); i++) {
		lft[i] = idx[vec[i]]+1;
		idx[vec[i]] = i;
	}
	int m;
	cin >> m;
	vector<pair<pii, int>> queries;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({{r, l}, i});
	}

	seg_tree seg(n);
	sort(ALL(queries));
	int pos = 0;
	vi ans(m);
	for(int r = 1; r <= n and pos < LEN(queries); r++) {
		// cerr << "r = " << r << '\n';
		if(lft[r-1] > 0)
			seg.upd(lft[r-1], {INF<int>, INF<int>});
		seg.upd(r, {lft[r-1], vec[r-1]});
		while(pos < LEN(queries) and queries[pos].x.x == r) {
			auto &[coord, pos_ans] = queries[pos];
			swap(coord.x, coord.y);
			pii pp = seg.qry(coord.x);
			if(pp.x < coord.x)
				ans[pos_ans] = pp.y;
			pos++;
		}
	}

	for(int v : ans)
		cout << v << '\n';

	return 0;
}
