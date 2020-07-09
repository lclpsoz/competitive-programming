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

int n;
int a[5050], delta[5];

int main () {
	scanf ("%d", &n);
	printf ("? 1 2\n");
	fflush (stdout);
	scanf ("%d", &delta[1]);
	
	printf ("? 2 3\n");
	fflush (stdout);
	scanf ("%d", &delta[2]);
	
	printf ("? 1 3\n");
	fflush (stdout);
	int aux;
	scanf ("%d", &aux);
	a[2] = (delta[1] + delta[2] - aux)/2;
	a[1] = delta[1] - a[2];
	a[3] = delta[2] - a[2];
	for (int i = 3; i < n; i++) {
		printf ("? %d %d\n", i, i+1);
		fflush (stdout);
		scanf ("%d", &aux);
		a[i+1] = aux-a[i];
	}
	printf ("!");
	for (int i = 1; i <= n; i++)
		printf (" %d", a[i]);
	putchar ('\n');
	fflush (stdout);

	return 0;
}
