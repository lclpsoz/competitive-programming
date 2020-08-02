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

const int N = 1e5 + 10, B = 400;
int n, m, a[N], b[N], ax[N];
int t[4*N], marked[4*N];

void push(int v) {
    if (marked[v]) {
        t[v*2] = t[v*2+1] = t[v];
        marked[v*2] = marked[v*2+1] = true;
        marked[v] = false;
    }
}

void update(int v, int tl, int tr, int l, int r, int new_val) {
    if (l > r) 
        return;
    if (l == tl && tr == r) {
        t[v] = new_val;
        marked[v] = true;
    } else {
        push(v);
        int tm = (tl + tr) / 2;
        update(v*2, tl, tm, l, min(r, tm), new_val);
        update(v*2+1, tm+1, tr, max(l, tm+1), r, new_val);
    }
}

int get(int v, int tl, int tr, int pos) {
    if (tl == tr) {
        return t[v];
    }
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm) 
        return get(v*2, tl, tm, pos);
    else
        return get(v*2+1, tm+1, tr, pos);
}

int main () {
	// ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.precision(10);

	cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	vector<pair<int, pii>> vec;
	vec.push_back({-1, {-1, -1}});
	while(m--) {
		int opt;
		int x, y, k;
		scanf("%d", &opt);
		// printf("opt = %d\n", opt);
		// printf("----- DEBUG ------\n");
		// for(int i = 1; i <= n; i++)
		// 	printf("%d%c", get(1, 1, n, i), " \n"[i==n]);
		// printf("------------------\n");
		if(opt == 2) {
			scanf("%d", &k);
			int idx = get(1, 1, n, k);
			if(idx == 0)
				printf("%d\n", b[k-1]);
			else {
				auto now = vec[idx];
				k -= now.x;
				// printf("pos = %d\n", now.y.x+k);
				printf("%d\n", a[now.y.x+k-1]);
			}
		} else {
			scanf("%d %d %d", &x, &y, &k);
			update(1, 1, n, y, y+k-1, LEN(vec));
			vec.push_back({y, {x, x+k-1}});
		}
	}

	return 0;
}
