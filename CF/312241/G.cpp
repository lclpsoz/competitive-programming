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

inline int fcmp (ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

inline int mod (ll x, int m = MOD) {
	int ret = x%m;
	if (ret < 0)
		ret += m;
	return ret;
}

template<typename T, typename M = __gnu_pbds::null_type>
using ordered_set = __gnu_pbds::tree<T, M, less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

////////////////////////// Solution starts below. //////////////////////////////

inline int left(int root){ return 2 * root;}
inline int right(int root){ return 2 * root + 1;}

struct node
{
	int val = 0;
	node(){}
    void apply(int l, int r)
    {}
};

const int N = 1e5 + 10;
node t[4 * N];

node merge(node& l, node& r)
{
    node p;
    p.val = max(l.val, r.val);
    return p;
}

node query(int root, int l, int r, int ql, int qr)
{
    if(l > qr || r < ql)
        return node();

    if(l >= ql && r <= qr)
        return t[root];
    
    int mid = (l + r) / 2;
    node a = query(left(root), l, mid, ql, qr);
    node b = query(right(root), mid + 1, r, ql, qr);
    return merge(a, b);
}
	
void update(int root, int l, int r, int p, int val)
{
	if(l > p || r < p) return;

    if(l == p && r == p)
    {
        t[root].val = val;
        return;
    }
    
    int mid = (l + r) / 2;
    update(left(root), l, mid, p, val);
    update(right(root), mid + 1, r, p, val);
    t[root] = merge(t[left(root)], t[right(root)]);
}

int main () {
	// freopen("FILE_NAME_INPUT.EXTENSION", "r", stdin);
	// freopen("FILE_NAME_OUTPUT.EXTENSION", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.precision(10);

	int n; cin >> n;
	vi g(n), a(n), b(n);
	
	for(int i = 0; i < n; i++)
		cin >> g[i] >> a[i] >> b[i];
	
	for(int i = n - 1; i >= 0; i--)
	{
		int l = min(n, i + a[i]);
		int r = min(n, i + b[i]);
		int q = query(1, 0, n, l, r).val;
		update(1, 0, n, i, g[i] + q);
	}

	cout << t[1].val << endl;

	return 0;
}
