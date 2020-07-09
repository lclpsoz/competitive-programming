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

const int N = 2e5 + 100;
const int MINV = 0, MAXV = N-1;

int t;
int n, q;
int mini, maxi;
ll lf[N], rg[N], qn[N];
ll lfTotal;
multiset<int> mset;

void upd (ll *bit, int p, ll v) {
	for (int i = p; i < N; i+=i&-i)
		bit[i] += v;
}

ll qry (ll *bit, int p) {
	ll ret = 0;
	for (int i = p; i >= 1; i-=i&-i)
		ret += bit[i];
	return ret;
}

int main () {
	int v[N];
	scanf ("%d", &t);
	while (t--) {
		memset (lf, 0, sizeof lf);
		memset (rg, 0, sizeof rg);
		memset (qn, 0, sizeof qn);
		scanf ("%d %d", &n, &q);
		mset.clear();
		lfTotal = 0;
		for (int i = 1; i <= n; i++) {
			mset.insert (i);
			v[i] = i;
			upd (qn, i, 1);
			upd (lf, i, i);
			lfTotal += i;
			upd (rg, i, MAXV - i);
		}
		mini = 1, maxi = n;
		while (q--) {
			int op;
			scanf ("%d", &op);
			if (op == 1) {
				int p, k;
				scanf ("%d %d", &p, &k);
				upd (qn, v[p], -1);
				upd (qn, k, 1);
				upd (lf, v[p], -v[p]);
				upd (lf, k, k);
				lfTotal += k - v[p];
				upd (rg, v[p], -(MAXV - v[p]));
				upd (rg, k, (MAXV - k));
				mset.erase (mset.find (v[p]));
				mset.insert (k);
				v[p] = k;
				mini = *mset.begin();
				maxi = *mset.rbegin();
			} else {
				// printf ("mini = %d, maxi = %d\n", mini, maxi);
				int md = (mini+maxi)/2;
				int qRg = qry (qn, md);
				ll esq = (lfTotal - qry (lf, md)) - (mini*1LL*(n-qRg));
				ll dir = qry (rg, md) - ((MAXV - maxi)*1LL*qRg);
				// assert (esq >= 0 and dir >= 0);
				// printf ("esq = %lld, dir = %lld\n", esq, dir);
				printf ("%lld\n", esq + dir - (maxi - mini));
			}
		}
	}

	return 0;
}
