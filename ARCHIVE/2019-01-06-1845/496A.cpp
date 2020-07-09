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
int a[110];

int main () {
	scanf ("%d", &n);
	int mx = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		if (i)
			mx = max (mx, a[i]-a[i-1]);
	}
	int mnPos = max (mx, a[2]-a[0]);
	for (int i = 2; i < n-1; i++)
		if (max (mx, a[i+1]-a[i-1]) < mnPos)
			mnPos = max (mx, a[i+1]-a[i-1]);
	printf ("%d\n", mnPos);
	
	return 0;
}
