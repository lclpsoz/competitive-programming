#include "bits/stdc++.h"
using namespace std;

////////////// Prewritten code follows. Look down for solution. ////////////////
#define x first
#define y second
#define len(x) ((int)(x).size())
using pii = pair<int, int>;
using ll = long long;
using llu = long long unsigned;
using ld = long double;

const ld EPS = 1e-9;
inline int cmp(ld x, ld y = 0, ld tol = EPS) {
	return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

const int MOD = 1;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e5 + 10;

ll tree[4*N], lazy[4*N];

void prop (int p, int q) {
// 	printf ("prop: %d\n", p);
	if (q > 1) {
		lazy[2*p] += lazy[p];
		lazy[2*p + 1] += lazy[p];
	}
	tree[p] += lazy[p]*q;
	lazy[p] = 0;
}

void upd (int p, int l, int r, int tl, int tr, int v) {
// 	printf ("p = %d, l = %d, r = %d, tl = %d, tr = %d\n", p, l, r, tl, tr);
	prop (p, tr-tl+1);
	
	if (l <= tl and tr <= r) {
		lazy[p] += v;
		prop (p, tr-tl+1);
// 		printf ("ADDED!!!\n");
		return;
	} else if (tr < l or r < tl)
		return;
		
	int md = (tl+tr)/2;
	upd (2*p, l, r, tl, md, v);
	upd (2*p + 1, l, r, md + 1, tr, v);
	tree[p] = tree[2*p] + tree[2*p+1];
}

ll qry (int p, int l, int r, int tl, int tr) {
	prop (p, tr-tl+1);
// 	printf ("p = %d -> %lld, l = %d, r = %d, tl = %d, tr = %d\n", p, tree[p], l, r, tl, tr);
	
	if (l <= tl and tr <= r)
		return tree[p];
	else if (tr < l or r < tl)
		return 0;
	
	int md = (tl+tr)/2;
	return 	qry (2*p, 	l, r, tl, md) +
			qry (2*p+1, l, r, md + 1, tr);
}

int main () {
	int t, n, c;
	scanf ("%d", &t);
	while (t--) {
		memset (tree, 0, sizeof tree);
		memset (lazy, 0, sizeof lazy);
		scanf ("%d %d", &n, &c);
		while (c--) {
			int opt, p, q, v;
			scanf ("%d %d %d", &opt, &p, &q);
// 			printf ("qry: %d %d %d\n", opt, p, q);
			if (p > q) swap (p, q);
			if (opt == 0) {
				scanf ("%d", &v);
				upd (1, p, q, 1, n, v);
			} else
				printf ("%lld\n", qry (1, p, q, 1, n));
		}
	}

	return 0;
}
