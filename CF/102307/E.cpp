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

const int DBG = false;
const int N = 1e5 + 10;

int read_float() {
	string _str;
	cin >> _str;
	int it = _str.find('.');
	if(it == LEN(_str))
		return stoi(_str)*100;
	else
		return stoi(_str.substr(0, it))*100 + 
				stoi(_str.substr(it+1, LEN(_str)-it-1));
}

struct segTree {
	int n;
	vector<int> tree, lazy;
	segTree(int _n) {
		n = _n;
		tree = vector<int>(4*n);
		lazy = vector<int>(4*n);
	}

	void push(int idx, int tl, int tr) {
		if(tl < tr and lazy[idx]) {
			tree[2*idx] += lazy[idx];
			tree[2*idx+1] += lazy[idx];
			lazy[2*idx] += lazy[idx];
			lazy[2*idx+1] += lazy[idx];
			lazy[idx] = 0;
		}
	}

	void add_one(int l, int r) {
		l = max(1, l);
		r = min(r, n);
		if(DBG)
			cout << "||add_one: " << l << ' ' << r << '\n';
		add(1, l, r, 1, n, 1);
	}

	void rem_one(int l, int r) {
		l = max(1, l);
		r = min(r, n);
		add(1, l, r, 1, n, -1);
	}

	void add(int idx, int l, int r, int tl, int tr, int val) {
		// cout << "||add: idx = "<<idx<<"| {l, r} = "<<l <<", " << r << '\n';
		if(l <= tl and tr <= r) {
			tree[idx] += val;
			lazy[idx] += val;
			// cout << "||lazy[" << idx << "] = "<< lazy[idx] << '\n';
		} else if(tl <= r and l <= tr) {
			push(idx, tl, tr);
			int tm = (tl+tr)/2;
			add(2*idx, l, r, tl, tm, val);
			add(2*idx+1, l, r, tm+1, tr, val);
			tree[idx] = max(tree[2*idx], tree[2*idx+1]);
			// cout << "||tree[" << idx << "] = " << tree[idx] << '\n';
		}
	}

	int get_max(int l, int r) {
		l = max(1, l);
		r = min(r, n);
		return qry(1, l, r, 1, n);
	}

	int qry(int idx, int l, int r, int tl, int tr) {
		// cout << "||idx = " << idx << '\n';
		if(l <= tl and tr <= r) {
			return tree[idx];
		} else if(tl <= r and l <= tr) {
			push(idx, tl, tr);
			int tm = (tl+tr)/2;
			return tree[idx] = max(	qry(2*idx, l, r, tl, tm),
									qry(2*idx+1, l, r, tm+1, tr));
		}
	}
};


int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);


	int n, d, alfa;
	set<pii> st;
	vector<int> dist(N);
	// int r[N], w[N];
	vector<pii> pts;

	cin >> n >> d;
	alfa = read_float();
	for(int i = 1; i <= n; i++) {
		int w;
		cin >> dist[i];
		w = read_float();
		pts.push_back({w, i});
	}
	sort(ALL(pts));
	int l, r;
	l = r = 0;
	segTree seg(N);

	// for(int i = 0; i < LEN(pts); i++)
	// 	cout << "|-| " << i << ": " << pts[i].x << ' ' << dist[pts[i].y] << '\n';

	int ans = 0;
	while(l < n) {
		while((pts[r].x-pts[l].x+36000)%36000 <= alfa and st.count(pts[r]) == 0) {
			st.insert(pts[r]);
			int p = pts[r].y;
			seg.add_one(dist[p]-d, dist[p]);
			r = (r+1)%n;
		}

		if(DBG) {
			cout << "  l, r = " << l << ", " << r << '\n';
			cout << "    max = " << seg.get_max(1, N) << '\n';
		}
		ans = max(ans, seg.get_max(1, N));
		int p = pts[l].y;
		seg.rem_one(dist[p]-d, dist[p]);
		if(LEN(st) == n) break;
		st.erase(pts[l++]);
	}

	cout << ans << '\n';


	return 0;
}
