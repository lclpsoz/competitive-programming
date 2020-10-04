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

vector<int> t, lazy;

void push(int v) {
    t[v * 2] = max(0, t[v * 2] - lazy[v]);
    lazy[v * 2] = lazy[v * 2] + lazy[v];
    t[v * 2 + 1] = max(0, t[v * 2 + 1] - lazy[v]);
    lazy[v * 2 + 1] = lazy[v * 2 + 1] + lazy[v];
    lazy[v] = 0;
}

void build(const vector<int> &a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
        return;
    }
    int tm = (tl + tr) / 2;
    build(a, v * 2, tl, tm);
    build(a, v * 2 + 1, tm + 1, tr);
    t[v] = t[v * 2] + t[v * 2 + 1];
}

void update(int v, int tl, int tr, int l, int r, int add) {
	if (l > r)
		return;
    if (l == tl && r == tr) {
    	t[v] = max(0, t[v] - add);
    	lazy[v] = max(0, lazy[v] + add);
    }
    else {
    	push(v);
        int tm = (tl + tr) / 2;
        update(v * 2, tl, tm, l, min(r, tm), add);
        update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}

long long query(int v, int tl, int tr, int l, int r) {
	if (l > r)
		return 0;
	if (l <= tl && tr <= r)
		return t[v];
	push(v);
	int tm = (tl + tr) / 2;
	return query(v * 2, tl, tm, l, min(r, tm)) + query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
}

int main () {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);

    int n, q;
    cin >> n >> q;
    vector<int> h(n);
    t = lazy = vector<int>(4 * n + 1, 0);

    for (int i = 0; i < n; i++)
    	cin >> h[i];
    build(h, 1, 0, n - 1);

    for (int i = 0; i < q; i++) {
    	int type;
    	cin >> type;
    	if (type == 1) {
    		int a, b;
    		cin >> a >> b;
    		cout << query(1, 0, n - 1, a - 1, b - 1) << endl;
    	} else {
    		int a, b, s;
    		cin >> a >> b >> s;
    		update(1, 0, n - 1, a - 1, b - 1, s);
    		cout << "update " << t[1] << " " << t[2] << " " << t[3] << endl;
    	}
    }

	return 0;
}
