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

const int N = 1e5 + 10;

ll n, k;
ll sum[N], a[N];

void solve (int p) {
	sum[p] = sum[p-1] + a[p];
// 	printf ("%d %lld\n", p, sum[p]);
	if (sum [k] == n) return;
	if (p == k) {
		if (sum[p-1] + a[p-1]*2 < n) {
			a[p] = a[p-1]*2;
			sum[p] = sum[p-1] + a[p];
			solve (p-1);
		}
		else {
			a[p] = n-sum[p-1];
			sum[p] = sum[p-1] + a[p];
			return;
		}
	}
	else if (a[p]+1 <= a[p-1]*2) {
		a[p]++;
		sum[p] = sum[p-1] + a[p];
		solve (min ((int)k, p+1));
	}
	else
		solve (p-1);
}

int main () {
	scanf ("%lld %lld", &n, &k);
	if (k == 1)
		printf ("YES\n%lld\n", n);
	else if (	(n < ((k*(k+1))/2)) or
				(k == 2 and n == 4) or
				(k == 3 and n == 8)		)
		printf ("NO\n");
	else {
		ll dif = n - ((k*(k+1))/2);
		ll st = dif / k + 1;
		printf ("YES\n");
		if (dif%k == 0) {
			for (int i = 0; i < k; i++)
				printf ("%lld ", st++);
			putchar ('\n');
		} else {
			for (int i = 1; i <= k; i++) {
				a[i] = st++;
				sum[i] = sum[i-1] + a[i];
			}
			solve (k);
			for (int i = 1; i <= k; i++)
				printf ("%lld ", a[i]);
			putchar ('\n');
		}
	}

	return 0;
}
