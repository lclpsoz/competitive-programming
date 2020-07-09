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

const int MOD = 360;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int n;
int a[1000];

void solve (int p, int sum) {
// 	printf ("%d %d\n", p, sum);
	if (p == n) {
		if (sum == 0) {
			printf ("YES\n");
			exit (0);
		} else
			return;
	}
	solve (p+1, mod (sum+a[p]));
	solve (p+1, mod (sum-a[p]));
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	
	solve (0, 0);
	printf ("NO\n");

	return 0;
}
