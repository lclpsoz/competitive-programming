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
struct node
{
	bool dirty = false;
	int sz = 0;
	ll lazy = 0;
	ll val = 0;
	// neutral values

	node(){}

	template<class base_t>
	node(const base_t& _lazy)
	{
		lazy = _lazy;
	}

	template<class base_t>
	node(const base_t& x, int _sz)
	{
		val = x;
		sz = _sz;
	}

	template<class base_t>
	node(const base_t& x, const ll _lazy, int _sz)
	{
		val = x;
		lazy = _lazy;
		sz = _sz;
	}

	node(const node& l, const node& r)
	{
		val = l.val + r.val + l.lazy*l.sz + r.lazy*r.sz;
		sz = l.sz + r.sz;
	}

	node& operator += (const node& p)
	{
		//get lazy|update
		dirty = true;
		lazy += p.lazy;
		return *this;
	}

	void apply()
	{
		//apply lazy on this node
		//reset lazy after
		val += lazy*sz;
		lazy = 0;
		dirty = false;
	}
};

template<class node_t>
class segtree
{
private:
	inline int left(int root){ return 2 * root;}
	inline int right(int root){ return 2 * root + 1;}

	vector<node_t> t;
	int n;

	template<class base_t>
	void build(int root, int l, int r, const vector<base_t>& v)
	{
		if(l == r)
		{
			t[root] = node_t(v[l], 1);
			return;
		}

		int mid = (l + r) / 2;
		build(left(root), l, mid, v);
		build(right(root), mid + 1, r, v);
		t[root] = node_t(t[left(root)], t[right(root)]);
	}

	void build(int root, int l, int r)
	{
		if(l == r)
		{
			t[root] = node_t(0, 1);
			return;
		}

		int mid = (l + r) / 2;
		build(left(root), l, mid);
		build(right(root), mid + 1, r);
		t[root] = node_t(t[left(root)], t[right(root)]);
	}
		
	node_t query(int root, int l, int r, int ql, int qr)
	{
		if(l > qr || r < ql)
			return node_t();
	
		push(root, l, r);

		if(l >= ql && r <= qr)
			return t[root];
		
		int mid = (l + r) / 2;
		node_t a = query(left(root), l, mid, ql, qr);
		node_t b = query(right(root), mid + 1, r, ql, qr);
		return node_t(a, b);
	}
	
	void update(int root, int l, int r, int ql, int qr, const node_t& v)
	{
		push(root, l, r);

		if(l > qr || r < ql) return;

		if(l >= ql && r <= qr)
		{
			t[root] += v;
			push(root, l, r);
			return;
		}
		
		int mid = (l + r) / 2;
		update(left(root), l, mid, ql, qr, v);
		update(right(root), mid + 1, r, ql, qr, v);
		t[root] = node_t(t[left(root)], t[right(root)]);
	}

	inline void push(int root, int l, int r)
	{
		if(t[root].dirty)
		{
			if(l != r)
			{
				t[left(root)] += t[root];
				t[right(root)] += t[root];
			}
			t[root].apply();
		}
	}

public:
	segtree(int _n = 1) : n(_n)
	{
		t.resize(4 * n);
		build(1, 0, n - 1);
	}

	template<class base_t>
	segtree(const vector<base_t>& v) : n(LEN(v))
	{
		t.resize(4 * n);
		build(1, 0, n - 1, v);
	}

	void update(int l, int r, const node_t& v)
	{
		update(1, 0, n - 1, l, r, v);
	}

	void update(int p, const node_t& v)
	{
		update(1, 0, n - 1, p, p, v);
	}

	node_t query(int l, int r)
	{
		return query(1, 0, n - 1, l, r);
	}
	
	node_t query(int p)
	{
		return query(1, 0, n - 1, p, p);
	}
};


int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n, q;
	cin >> n >> q;
	vi vec(n);
	for (int &v : vec)
		cin >> v;

	segtree<node> seg(vec);


	while (q--) {
		int opt;
		cin >> opt;
		int a, b;
		int x;
		if (opt == 1) {
			cin >> a >> b;
			cin >> x;
			seg.update(a-1, b-1, node(x));
		}
		else if (opt == 2) {
			cin >> x;
			cout << seg.query(x-1).val << '\n';
		}
	}

	return 0;
}
