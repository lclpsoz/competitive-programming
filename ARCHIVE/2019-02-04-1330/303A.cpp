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

const int N = 1e5+10;

int n;
int a[N], b[N];

int main () {
	scanf ("%d", &n);
	if (n%2 == 0) {
		printf ("-1\n");
		return 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = i;
		b[i] = (i + n/2) % n;
	}
	for (int i = 0; i < n; i++)
		printf ("%d%c", a[i], " \n"[i==n-1]);
	for (int i = 0; i < n; i++)
		printf ("%d%c", b[i], " \n"[i==n-1]);
	for (int i = 0; i < n; i++)
		printf ("%d%c", (a[i]+b[i])%n, " \n"[i==n-1]);

	return 0;
}
