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

int n, m, k;

int p[110], s[110];
set<int, greater<int>> st[110];

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &p[i]);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf ("%d", &x);
		st[x].insert (p[i]);
		s[i] = x;
	}
	int ans = 0;
	for (int i = 1; i <= k; i++) {
		int x;
		scanf ("%d", &x);
		if (*st[s[x]].begin() != p[x]) ++ans;
	}
	printf ("%d\n", ans);

	return 0;
}
