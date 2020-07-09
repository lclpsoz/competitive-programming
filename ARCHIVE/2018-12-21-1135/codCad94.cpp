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

const int K = 45;

int ans;
int n, k;
int a[K];

void solve (int p, int qnt, ll acu) {
	acu *= a[p];
	ans += (n/acu) * (qnt&1 ? 1 : -1);
// 	printf ("p = %d,  qnt = %d, acu = %lld, ans = %d\n", p, qnt, acu, ans);
	for (int i = p+1; i < k; i++) {
		if (a[i]*acu > n)
			return;
		solve (i, qnt+1, acu);
	}
}

int main () {
	scanf ("%d %d", &n, &k);
	for (int i = 0; i < k; i++)
		scanf ("%d", &a[i]);
	sort (a, a+k);

	for (int i = 0; i < k; i++)
		solve (i, 1, 1LL);

	printf ("%d\n", n-ans);
	
	return 0;
}
