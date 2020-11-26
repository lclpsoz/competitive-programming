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

const int N = 5005;

int n, k;
set<int> st[N];
int ans[N];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		int stP = i%k;
		int p = stP;
		if (st[p].count (x) == 1) p = (p+1)%k;
		while (st[p].count (x) == 1 and p != stP) p = (p+1)%k;
		if (st[p].count (x)) {
			printf ("NO\n");
			exit (0);
		}
		ans[i] = p;
		st[p].insert (x);
	}
	
	printf ("YES\n");
	for (int i = 0; i < n; i++)
		printf ("%d%c", ans[i]+1, " \n"[i==n-1]);

	return 0;
}
