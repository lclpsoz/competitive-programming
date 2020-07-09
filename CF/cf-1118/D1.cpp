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

const int N = 2e5+10;

int n, m;
int a[N];

ll eval (int days) {
	ll ret = 0;
	for (int i = 0; i < n; i++)
		ret += max (0, a[i] - i/days);
	
// 	printf ("%d: %d\n", days, ret);
	return ret;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf ("%d", &a[i]);
	sort (a, a+n, greater<int>());
	
	int l = 1, r = n+1;
	while (l < r) {
		int md = (l+r)/2;
		if (eval (md) >= m)
			r = md;
		else
			l = md+1;
	}
	
	if (l == n+1)
		printf ("-1\n");
	else
		printf ("%d\n", l);

	return 0;
}
