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

	ll lazy = 0, val = 0;
	ll l_up, r_up, sz;
	ll s_up;
	// neutral values

	node(){}

	template<class base_t>
	node(const base_t& x, int _sz)
	{
		val = 0;
		sz = _sz;
	}

	node(const node& l, const node& r)
	{
		val = l.val + r.val;
	}

	node& operator += (const node& p)
	{
		lazy += (sz * (p.l_up + p.r_up) / 2) * p.s_up;
		dirty = true;
		return *this;
	}

	void apply()
	{
		val += lazy;
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
			t[root] = node_t(0, r - l + 1);
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
				node aux = t[root];
				
				if(t[root].l_up != t[root].r_up)
					aux.r_up = t[root].l_up + t[left(root)].sz - 1;
				t[left(root)] += aux;
				
				if(t[root].l_up != t[root].r_up)
				{
					aux.l_up = aux.r_up + 1;
					aux.r_up = t[root].r_up;
				}
				t[right(root)] += aux;
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

	int n; cin >> n;
	int P2 = 6283158;
	segtree<node> seg(P2);
	ll ans = 0;
	node up;

	while(n--)
	{
		string inp[3];
		cin >> inp[0] >> inp[1] >> inp[2];

		ll now[3] = {0, 0, 0};
		for(int k = 0; k < 3; k++)
		{
			int z = 6;
			string aux;
			for(int i = 0; i < LEN(inp[k]); i++)
			{
				if(inp[k][i] == '.') z--;
				else aux.push_back(inp[k][i]);
			}
			while(z--) aux.push_back('0');
			ll p = 1;
			while(!empty(aux))
				now[k] += p * int(aux.back() - '0'), aux.pop_back(), p *= 10;
			
		}

		ans += now[0];
		// cout << now[0] << " " << now[1] << " " << now[2] << endl;

		ll sz = min(now[0] / now[2], P2 - now[3] - 1);
		up.s_up = now[1];
		up.l_up = 0;
		up.r_up = sz;
		seg.update(now[3], now[3] + sz, up);
		
		if(now[3] + sz + 1 < P2)
		{
			up.s_up = now[0];
			up.l_up = 1;
			up.r_up = 1;
			seg.update(now[3] + sz + 1, P2, up);
		}

		sz = min(now[0] / now[2], now[3]);
		up.s_up = now[1];
		up.l_up = sz;
		up.r_up = 0;
		seg.update(now[3] - sz, now[3], up);
		if(now[3] - sz - 1 >= 0)
		{
			up.s_up = now[0];
			up.l_up = 1;
			up.r_up = 1;
			seg.update(0, now[3] - sz - 1, up);
		}
	}

	ll mn = (ll)1e18;
	for(int i = 0; i < P2; i++)
		mn = min(mn, seg.query(i).val);

	cout << (ans - mn) / (1e6) << endl;

	return 0;
}
