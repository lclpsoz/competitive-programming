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

const ll INF = 1e18;
const int N = 1e5+100;

int n;
ll pd[N][6];
char str[N];
char hard[] = "hard";
int a[N];

ll solve (int p, int q) {
	if (q == 4)
		return INF;
	if (p == n)
		return 0;
	
	ll &r = pd[p][q];
	if (r != -1)
		return r;
	if (str[p] != hard[q])
		r = solve (p+1, q);
	else
		r = min (solve (p+1, q+1), solve (p+1, q) + a[p]);
	
	return r;
}

int main () {
	memset (pd, -1, sizeof pd);
	scanf ("%d %s", &n, str);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	
	printf ("%lld\n", solve (0, 0));

	return 0;
}
