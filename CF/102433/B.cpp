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

struct node
{
	bool dirty = false;

	ll mx = -1e9, lazy = 0;
	int val = 1e9;

	node(){}

	template<class base_t>
	node(const base_t& x)
	{
		val = x;
		mx = 0;
	}

	node(const node& l, const node& r)
	{
		if(l.mx == r.mx)
			val = min(l.val, r.val), mx = l.mx;
		else if(l.mx > r.mx)
			val = l.val, mx = l.mx;
		else
			val = r.val, mx = r.mx;
	}

	node& operator += (const node& p)
	{
		lazy += p.lazy;
		dirty = true;
		return *this;
	}

	void apply()
	{
		mx += lazy;
		dirty = false;
		lazy = 0;
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
			t[root] = node_t(v[l]);
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
			t[root] = node_t(/*leaf value*/);
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
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int n, k;
	cin >> n >> k;

	vi a(n), ans;
	vector<vi> p(k);

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		p[--a[i]].emplace_back(i);
	}

	segtree<node> seg(a);
	node up;

	set<int> st;
	for(int i = n - 1; i >= 0; i--)
	{
		st.insert(a[i]);
		up.lazy = LEN(st);
		seg.update(i, up);
	}

	vector<bool> used(n, 0);
	int l = 0;
	while(LEN(ans) < k)
	{
		auto now = seg.query(l, n - 1);
		int v = now.val;

		ans.emplace_back(v + 1);
		used[v] = 1;

		up.lazy = -1e9;
		for(int pos : p[v]) seg.update(pos, up);
		up.lazy = -1;
		seg.update(l, p[v].back(), up);
		l = *upper_bound(ALL(p[v]), l);
	}

	for(int i = 0; i < k; i++)
		cout << ans[i] << " \n"[i == k - 1];

	return 0;
}
