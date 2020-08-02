#include "bits/stdc++.h"
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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
	ll val, lazy;

	node(bool neutral = true)
	{
		if(neutral)
		{
			lazy = 0, val = 1e18;
		}
		else
		{
			lazy = 0, val = 0;
		}
	}

	node(const node& l, const node& r)
	{
		val = min(l.val, r.val);
	}

	node& operator += (const node& p)
	{
		lazy += p.lazy;
		return *this;
	}

	void apply()
	{
		val += lazy;
		lazy = 0;
	}
};

template<class node_t>
class segtree
{
private:
	vector<node_t> t;
	int n;

	void build(int root, int l, int r)
	{
		if(l == r)
		{
			t[root] = node_t(false);
			return;
		}

		int mid = (l + r) / 2;
		build(2 * root, l, mid);
		build(2 * root + 1, mid + 1, r);
		t[root] = node_t(t[2 * root], t[2 * root + 1]);
	}
		
	node_t query(int root, int l, int r, int ql, int qr)
	{
		if(l > qr || r < ql)
			return node_t(true);
	
		push(root, l, r);

		if(l >= ql && r <= qr)
			return t[root];
		
		int mid = (l + r) / 2;
		node_t a = query(2 * root, l, mid, ql, qr);
		node_t b = query(2 * root + 1, mid + 1, r, ql, qr);
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
		update(2 * root, l, mid, ql, qr, v);
		update(2 * root + 1, mid + 1, r, ql, qr, v);
		t[root] = node_t(t[2 * root], t[2 * root + 1]);
	}

	inline void push(int root, int l, int r)
	{
		if(l != r)
		{
			t[2 * root] += t[root];
			t[2 * root + 1] += t[root];
		}
		t[root].apply();
	}

public:
	segtree(int _n = 1) : n(_n)
	{
		t.resize(4 * n);
		build(1, 0, n - 1);
	}

	void update(int l, int r, const node_t& v)
	{
		if(l > r) return;
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

const int N = 5e5 + 10, K = 20;
int n, sz[N], tin[N], timer;
vpii adj[N];
segtree<node> seg;
node up;
vector<tuple<int, int, int>> que[N];
ll d1[N];

void dfs(int v, int p)
{
	sort(ALL(adj[v]));

	sz[v] = 1;
	tin[v] = ++timer;

	for(auto [u, c] : adj[v])
	{
		if(u == p) continue;
		d1[u] = d1[v] + c;
		dfs(u, v);
		sz[v] += sz[u];
	}
}

ll ans[N];
void dfs(int v, int p, int l, int r)
{
	int lft = 1;
	for(auto [a, b, id] : que[v])
		ans[id] = seg.query(a - 1, b - 1).val;
	
	for(auto [u, c] : adj[v])
	{
		if(u == p) continue;
		up.lazy = c;
		seg.update(0, l + lft - 2, up);
		seg.update(l + lft + sz[u] - 1, n - 1, up);
		up.lazy = -c;
		seg.update(l + lft - 1, l + lft + sz[u] - 2, up);
		
		dfs(u, v, l + lft, l + lft + sz[u] - 1);
		
		up.lazy = -c;
		seg.update(0, l + lft - 2, up);
		seg.update(l + lft + sz[u] - 1, n - 1, up);
		up.lazy = c;
		seg.update(l + lft - 1, l + lft + sz[u] - 2, up);
		
		lft += sz[u];
	}
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

	int q;
	cin >> n >> q;

	for(int i = 2; i <= n; i++)
	{
		int p, w;
		cin >> p >> w;

		adj[p].emplace_back(i, w);
		adj[i].emplace_back(p, w);
	}

	for(int i = 0; i < q; i++)
	{
		int v, l, r;
		cin >> v >> l >> r;
		que[v].emplace_back(l, r, i);
	}

	dfs(1, 0);

	seg = segtree<node>(n);

	for(int i = 0; i < n; i++)
	{
		up.lazy = (LEN(adj[i + 1]) == 1 ? d1[i + 1] : (ll)1e16);
		seg.update(i, up);
	}

	dfs(1, 0, 1, n);

	for(int i = 0; i < q; i++)
		cout << ans[i] << endl;

	return 0;
}
