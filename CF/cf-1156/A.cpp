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

const int N = 115;

int a[N];

void inf () {
	printf ("Infinite\n");
	exit (0);
}

int main () {
	int n;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int bef = a[i-1];
		int now = a[i];
		if (bef == now)
			inf ();
		
		if (bef == 1) {
			if (now == 2)
				ans += 3;
			else if (now == 3)
				ans += 4;
		} else if (bef == 2) {
			if (now == 1)
				ans += 3;
			else
				inf ();
		} else { // 3
			if (now == 1)
				ans += 4;
			else if (now == 2)
				inf ();
		}
	}
	for (int i = 0; i < n; i++)
		if (a[i] == 3 and a[i+1] == 1 and a[i+2] == 2)
			--ans;
	printf ("Finite\n%d\n", ans);

	return 0;
}
