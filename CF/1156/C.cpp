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
int a[N];

int main () {
	int n, z;
	scanf ("%d %d", &n, &z);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a+n);
	int l = 0, r = n/2;
	int ans = 0;
	while (l < n) {
		while (r < n and a[r] < a[l]+z) ++r;
		if (r == n) break;
		a[r] = -1;
		++ans;
		++l;
		while (l < n and a[l] == -1) ++l;
	}
	printf ("%d\n", ans);
	return 0;
}
