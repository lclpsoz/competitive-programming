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

int n, k;
pii jmp[N];
int ans[N];
int vals[N];
set<pii> st;

int main () {
	scanf ("%d %d", &n, &k);
	if (n == 1) {
		printf ("1\n");
		exit (0);
	}
	jmp[1] = {-1, 2}, jmp[n] = {n-1, -1};
	for (int i = 2; i < n; i++) {
		jmp[i] = {i-1, i+1};
	}

	for (int i = 1; i <= n; i++) {
		scanf ("%d", &vals[i]);
		st.insert ({-vals[i], i});
	}

	bool tim = 0;
	while (!st.empty()) {
		int p = st.begin()->y;
		// printf ("p: %d\n", p);
		int q = k+1;
		int nxt = p;
		while (q-- and nxt != -1) {
			// printf ("%d\n", nxt);
			ans[nxt] = tim;
			st.erase ({-vals[nxt], nxt});
			nxt = jmp[nxt].x;
		}
		int lft = nxt;

		q = k + 1;
		nxt = p;
		while (q-- and nxt != -1) {
			ans[nxt] = tim;
			st.erase ({-vals[nxt], nxt});
			nxt = jmp[nxt].y;
		}
		if (lft != -1)
			jmp[lft].y = nxt;
		if (nxt != -1)
			jmp[nxt].x = lft;

		tim = !tim;
	}
	for (int i = 1; i <= n; i++)
		printf ("%d", ans[i]+1);
	putchar ('\n');

	return 0;
}
