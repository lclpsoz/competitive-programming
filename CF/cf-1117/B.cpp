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

const int N = 2e5 + 10;

int n, m, k;
int a[N];

int main () {
	scanf ("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a+n);
	int mx1 = a[n-1];
	int mx2 = a[n-2];
	int axM = (m/(k+1));
	//printf ("%d\n", axM);
	printf ("%lld\n", axM*1LL*(k*1LL*mx1 + mx2) + (m - axM*(k+1))*1LL*mx1);

	return 0;
}
