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

const int N = 2e5+10;

int n;
int a[N];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		a[n+i] = a[i];
	}
	
	int lst = 0;
	int ans = 0;
	int acu = 0;
	for (int i = 0; i < 2*n; i++) {
		if (a[i] >= acu+a[i]) {
			lst = i;
			acu = a[i];
		} else
			acu += a[i];
		if (i-lst+1 > n) {
			acu -= a[lst];
			++lst;
			while (a[lst] < 0
		}
// 		printf ("%d %d, %d\n", i, acu, lst);
		ans = max (ans, acu);
	}
	acu = max (0, acu);
	printf ("%d\n", ans);

	return 0;
}
