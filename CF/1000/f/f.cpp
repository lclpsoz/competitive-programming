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

const int MAXV = 5e5+10;

struct seg_tree {
	int n;
	vpii seg;
	const pii P_INF = {INF<int>, INF<int>};

	seg_tree(int _n) : n(_n) {
		seg = vpii(4*n);
		build(1, 1, n);
	}

	void build(int v, int tl, int tr) {
		if(tl == tr)
			seg[v] = P_INF;
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

	void upd(int v, int tl, int tr, int pos, pii val) {
		if(tl == tr and tl == pos)
			seg[v] = val;
		else if(tl <= pos and pos <= tr){
			int tm = (tl+tr)/2;
			upd(2*v, tl, tm, pos, val);
			upd(2*v+1, tm+1, tr, pos, val);
			if(seg[2*v].x < seg[2*v+1].x)
				seg[v] = seg[2*v];
			else
				seg[v] = seg[2*v+1];
		}
	}

	void upd(int pos, pii val) {
		upd(1, 1, n, pos, val);
	}

	void upd_clear(int pos) {
		upd(1, 1, n, pos, P_INF);
	}
	
	pii qry(int v, int tl, int tr, int l, int r) {
		if(l <= tl and tr <= r)
			return seg[v];
		else if(l <= tr and tl <= r) {
			int tm = (tl+tr)/2;
			pii ret = qry(2*v, tl, tm, l, r);
			pii now = qry(2*v+1, tm+1, tr, l, r);
			// cerr << "|| l = " << l << ", " << r << " : " << ret.x << ' ' << ret.y << ' ' << now.x << ' ' << now.y << '\n';
			if(now.x < ret.x)
				ret = now;
			return ret;
		}
		return P_INF;
	}

	pii qry(int l, int r) {
		return qry(1, 1, n, l, r);
	}
};

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n;
	cin >> n;
	vi vec(n);
	for(int &v : vec)
		cin >> v;
	
	vi idx(MAXV), lft(n);
	for(int i = 0; i < n; i++) {
		lft[i] = idx[vec[i]];
		idx[vec[i]] = i+1;
	}

	int m;
	cin >> m;
	vector<pair<pii, int>> queries;
	for(int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		queries.push_back({{r, l}, i});
	}
	sort(ALL(queries));

	vi ans(m);
	int pos_q = 0;
	seg_tree seg(n);
	for(int r_cur = 1; r_cur <= n and pos_q < LEN(queries); r_cur++) {
		int pos_bef = lft[r_cur-1];
		if(pos_bef)
			seg.upd_clear(pos_bef);
		seg.upd(r_cur, {pos_bef, vec[r_cur-1]});
		while(pos_q < LEN(queries) and queries[pos_q].x.x == r_cur) {
			auto &[coord, pos_ans] = queries[pos_q];
			swap(coord.x, coord.y);
			pii now = seg.qry(coord.x, r_cur);
			if(now.x < coord.x)
				ans[pos_ans] = now.y;
			++pos_q;
		}
	}

	for(int &v : ans)
		cout << v << '\n';

	return 0;
}
