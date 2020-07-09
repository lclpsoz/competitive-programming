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

const int MOD = 6;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

int ar[10];

int main () {
	for (int i = 0; i < 6; i++)
		scanf ("%d", &ar[i]);

	int mx = 0;
	int base;
	int cut[5];
	for (int i = 0; i < 6; i++)
		if (ar[i] > mx) {
			mx = ar[i];
			base = mx + ar[mod (i-1)] + ar[mod (i+1)];
			cut[0] = ar[mod (i+1)];
			cut[1] = ar[mod (i-1)];
			cut[2] = ar[mod (i+3)];
		}
		
	printf ("%d\n", (base * base) - cut[0]*cut[0] - cut[1]*cut[1] - cut[2]*cut[2]);
		
		
	return 0;
}
