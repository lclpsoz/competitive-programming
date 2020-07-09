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
pii a[1010];

int main () {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &a[i].x);
		a[i].y = i+1;
	}
	sort(a, a+n, greater<pii>());
	int ans = 0;
	for(int i = 0; i < n; i++)
		ans += a[i].x*i + 1;
	printf("%d\n", ans);
	for(int i = 0; i < n; i++)
		printf("%d%c", a[i].y, " \n"[i==n-1]);

	return 0;
}
