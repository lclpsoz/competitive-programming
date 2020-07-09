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

const ll FLAG = (ll)1e19 + 10;
const int N = 1e5 + 10;

struct node {
	ll v, lazy;
	int lazyP;
} tree[4*N];

int n;
int a[N], k[N];
ll pref[N], pPref[N];

inline ll read(){
	ll x=0,f=1; char ch=getchar();
	while(ch>'9'||ch<'0') {if(ch=='-') f=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}

ll buildTree (int seg, int l, int r) {
	tree[seg] = {0, FLAG, 0};
	if (l == r)
		return tree[seg].v = a[l];
	else {
		int md = (l+r)/2;
		return tree[seg].v = buildTree (2*seg, l, md) + 
						buildTree (2*seg+1, md+1, r);		
	}
}

void upd (int seg, int l, int r) {
	if (tree[seg].lazy != FLAG) {
		int q = r - l + 1;
		int p = tree[seg].lazyP;
		ll &v = tree[seg].lazy;
		// printf (" upd: seg = %d, %d %d, v = %d, p = %d\n", seg, l, r, v, p);
		tree[seg].v = pPref[r-1] - pPref[l-2] - q*pref[p-1] + q*v;
		if (l < r) {
			tree[2*seg].lazy = v;
			tree[2*seg + 1].lazy = v;
			tree[2*seg].lazyP = p;
			tree[2*seg + 1].lazyP = p;
		}
		v = FLAG;
	}
}

ll chg (int seg, int l, int r, int x, int y, ll v, int p) {
	upd (seg, l, r);
	if (r < x or y < l) return tree[seg].v;
	if (x <= l and r <= y) {
		tree[seg].lazy = v;
		tree[seg].lazyP = p;
		upd (seg, l, r);
		return tree[seg].v;
	}
	int md = (l+r)/2;
	return tree[seg].v = chg (2*seg, l, md, x, y, v, p) + 
							chg (2*seg + 1, md+1, r, x, y, v, p);
}

ll chg1 (int seg, int l, int r, int p, ll v) {
	upd (seg, l, r);
	if (r < p or p < l) return tree[seg].v;
	if (l == r and p == l)
		return tree[seg].v = v;
	int md = (l+r)/2;
	return tree[seg].v = chg1 (2*seg, l, md, p, v) + 
							chg1 (2*seg + 1, md+1, r, p, v);
}

ll qry (int seg, int l, int r, int x, int y) {
	// printf ("  qry: %d, %d, %d, %d, %d\n", seg, l, r, x, y);
	upd (seg, l, r);
	if (r < x or y < l)
		return 0;
	if (x <= l and r <= y)
		return tree[seg].v;
	int md = (l+r)/2;
	return qry (2*seg, l, md, x, y) +
			qry (2*seg + 1, md+1, r, x, y);
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++)
		a[i] = read();

	for (int i = 1; i < n; i++) {
		k[i] = read();
		pref[i] = pref[i-1] + k[i];
		pPref[i] = pPref[i-1] + pref[i];
	}

	buildTree (1, 1, n);

	int q;
	scanf ("%d", &q);
	while (q--) {
		// for (int i = 1; i <= n; i++)
		// 	printf ("a[%d] = %lld\n", i, qry(1, 1, n, i, i));
		char opt;
		scanf (" %c", &opt);
		if (opt == '+') {
			int p, v;
			scanf ("%d %d", &p, &v);
			ll aOld = qry (1, 1, n, p, p);
			chg1 (1, 1, n, p, aOld + v);
			ll aNow = qry (1, 1, n, p, p);
			assert (aOld + v == aNow);
			if (qry (1, 1, n, p+1, p+1) < aNow + k[p]) {
				int l = p+1, r = n;
				while (l < r) {
					int md = (l+r + 1)/2;
					if (qry (1, 1, n, md, md) < aNow + pref[md-1] - pref[p-1])
						l = md;
					else
						r = md-1;
				}
				chg (1, 1, n, p+1, l, aNow, p);
			}
		} else {
			int l, r;
			scanf ("%d %d", &l, &r);
			printf ("%lld\n", qry (1, 1, n, l, r));
		}
	}

	return 0;
}
