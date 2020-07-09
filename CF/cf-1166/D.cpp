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

const int N = 55;

int t;
ll r[N];

int main () {
	scanf ("%d", &t);
	while (t--) {
		ll a, b, m;
		scanf ("%lld %lld %lld", &a, &b, &m);
		if (a == b) {
			printf ("1 %lld\n", a);
		} else if (a >= b-m) {
			printf ("2 %lld %lld\n", a, b);
		} else {
			int k = 3;
			// printf ("  [%lld, %lld]\n", ((1LL<<(k-2))*(a+1)), ((1LL<<(k-2))*(a+m)));
			while (((1LL<<(k-2))*(a+1)) < b and ((1LL<<(k-2))*(a+m)) < b) ++k;
			if (((1LL<<(k-2))*(a+1)) > b) {
				printf ("-1\n");
			} else {
				for (int i = 1; i <= k-1; i++)
					r[i] = 1;
				b -= ((1LL<<(k-2))*(a+1));
				for (int i = 1; i <= k; i++) {
					ll now = 1;
					if (k-i > 1)
						now = 1LL<<(k-i-2);
					ll q = min (m-1, b/now);
					b -= q*now;
					r[i] += q;
				}
				printf ("%d %lld ", k, a);
				for (int i = 1; i < k; i++) {
					ll now = 0;
					for (int j = 1; j <= i; j++) {
						ll mult = 1;
						if (i-j > 1)
							mult = (1LL<<(i-j-1));
						now += mult*r[j];
					}
					printf ("%lld ", ((1LL<<(i-1))*a + now));
				}
				putchar ('\n');
			}
		}
	}

	return 0;
}
