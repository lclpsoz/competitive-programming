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

const int N = 1e5+100;

int n;
int a[N], sum;


int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	if (sum&1) {
		printf ("0\n");
		exit (0);
	}
	
	int ans = 0;
	int acu = 0;
	sum /= 2;
	for (int i = 0; i < n-1; i++) {
		acu += a[i];
		if (acu == sum)
			++ans;
	}
	printf ("%d\n", ans);

	return 0;
}
