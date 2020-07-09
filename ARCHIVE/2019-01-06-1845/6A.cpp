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

int a[5];
bool segment;

void verif (int a, int b, int c) {
	if (a < 0 or b < 0 or c < 0) return;
	if (a+b > c and a+c > b and b+c > a) {
		printf ("TRIANGLE\n");
		exit (0);
	}
	if (a+b >= c and a+c >= b and b+c >= a)
		segment = true;
}

int main () {
	for (int i = 0; i < 4; i++)
		scanf ("%d", &a[i]);
	
	verif (a[0], a[1], a[2]);
	verif (a[0], a[1], a[3]);
	verif (a[0], a[2], a[3]);
	verif (a[1], a[2], a[3]);

	printf ("%s\n", segment ? "SEGMENT" : "IMPOSSIBLE");
	
	return 0;
}
