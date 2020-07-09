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

int k, n;
int a[110];
bool marked[110];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);

	int ans = 0;
	for (int b = 1; b <= n; b++) {
		memset (marked, 0, sizeof marked);
		int acu = 0;
		for (int i = -10000; i < 10000; i++)
			if (b + i*k >= 1 and b + i*k <= n)
				marked[b + i*k] = true;
		for (int i = 1; i <= n; i++)
			if (!marked[i])
				acu += a[i];
		ans = max (abs (acu), ans);
	}
	printf ("%d\n", ans);
	
	return 0;
}
