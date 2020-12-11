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

    int val = 0;
    // neutral values

    node(){}

    template<class base_t>
    node(const base_t& x)
    {
        val = x;
    }

    node(const node& l, const node& r)
    {
        val = max(l.val, r.val);
    }

    node& operator += (const node& p)
    {
        val = p.val;
        return *this;
    }

    void apply()
    {
        //apply lazy on this node
        //reset lazy after
        //dirty = false;
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

    int n;
    cin >> n;

    if(n == 1)
    {
        int a; cin >> a;
        int q; cin >> q;
        while(q--)
        {
            int t, x, y;
            cin >> t >> x >> y;
            if(t == 2) cout << 1 << endl;
        }
        return 0;
    }

    vector<int> a(n), d(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
        d[i - 1] = abs(a[i] - a[i - 1]);

    segtree<node> seg(d);
    node up;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        --x;
        if (t == 1) {
            a[x] = y;
            if(x)
            {
                up.val = abs(a[x] - a[x - 1]);
                seg.update(x - 1, up);
            }
            if(x + 1 < n)
            {
                up.val = abs(a[x + 1] - a[x]);
                seg.update(x, up);
            }
        } else {
            int l = x, r = n - 1, ans = x;
            while(l <= r)
            {
                int mid = (l + r) / 2;
                if(seg.query(x, mid - 1).val <= y) ans = mid, l = mid + 1;
                else r = mid - 1;
            }

            cout << ans + 1 << '\n';
        }
    }

	return 0;
}
