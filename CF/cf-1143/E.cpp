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

const int N = 2e5 + 10;

int n, m, q;
set<pii> st;
int a[N], b[N], nxtP[N], nxt[N][20], lstOcu[N];
bool ok[N];
int lst[N], frstLst[N];

int main () {
	for (int i = 0; i < 18; i++)
		for (int j = 0; j < N; j++)
			nxt[j][i] = N-1;
	scanf ("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (i == n-1)
			nxtP[a[i]] = a[0];
		if (i)
			nxtP[a[i-1]] = a[i];
	}
	for (int i = 0; i < m; i++)
		scanf ("%d", &b[i]);
	for (int i = 0; i < N; i++) lstOcu[i] = N-1;
	for (int i = m-1; i >= 0; i--) {
		nxt[i][0] = lstOcu[nxtP[b[i]]];
		lstOcu[b[i]] = i;
	}

	for (int i = 1; i < 18; i++) {
		for (int j = 0; j < m; j++)
			nxt[j][i] = nxt[nxt[j][i-1]][i-1];
	}
	// for (int j = 0; j < m; j++)
	// 	for (int i = 0; i < 5; i++)
	// 		printf ("%2d%c", nxt[j][i], "\t\n"[i==4]);

	for (int i = 0; i < m; i++) {
		int ax = n-1;
		int pos = i;
		int now = 0;
		while (ax) {
			if (ax&1)
				pos = nxt[pos][now];
			ax >>=1;
			now++;
		}
		// printf ("%d: %d\n", i, pos);
		lst[i] = N-1;
		if (pos < m)
			lst[i] = pos;
	}
	frstLst[m] = N-1;
	for (int i = m-1; i >= 0; i--) {
		frstLst[i] = min (frstLst[i+1], lst[i]);
		// printf ("%d: %d\n", i, frstLst[i]);
	}

	while (q--) {
		int x, y;
		scanf ("%d %d", &x, &y);
		--x, --y;
		printf ("%d", frstLst[x] <= y ? 1 : 0);
	}
	putchar ('\n');

	return 0;
}
