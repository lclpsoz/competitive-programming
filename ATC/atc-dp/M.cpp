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

const int MOD = 1e9+7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 110, K = 1e5+10;

int n, k;
int a[N];
int pd[N][K];

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &a[i]);
	
	for (int j = 0; j <= a[1]; j++)
		pd[1][j] = 1;
	for (int i = 2; i <= n; i++) {
		int acu = 0;
		for (int j = 0; j <= k; j++) {
			acu = mod (acu + pd[i-1][j]);
			if ((j-a[i]-1) >= 0) acu = mod (acu - pd[i-1][j-a[i]-1]);
			pd[i][j] = acu;
		}
	}
// 	for (int i = 1; i <= n; i++) {
// 		for (int j = 0; j <= k; j++)
// 			printf ("%d ", pd[i][j]);
// 		putchar ('\n');
// 	}
	
	printf ("%d\n", pd[n][k]);

	return 0;
}
