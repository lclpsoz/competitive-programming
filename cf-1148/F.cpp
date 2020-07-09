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
 
const int N = 3e5 + 10;
 
int n;
pair<ll, ll> a[N];
 
int main () {
	scanf ("%d", &n);
	ll total = 0;
	for (int i = 0; i < n; i++) {
		scanf ("%lld %lld", &a[i].y, &a[i].x);
		total += a[i].y;
	}
	if (total < 0)
		for (int i = 0; i < n; i++) a[i].y *= -1;
	sort (a, a+n);
	ll now = 1<<1;
	total = 0;
	ll s = 0;
	int p = 0;
	for (int i = 0; i < n; i++) {
		// cout << bitset<8>(a[i].x) << '\n';
		while (a[i].x >= now) {
			// printf (" p = %d, total = %lld\n", p, total);
			if (total > 0) {
				s |= (1LL<<p);
				for (int j = 0; j < n; j++)
					if ((1LL<<p) & a[j].x)
						a[j].y *= -1;
			}
			total = 0;
			now <<= 1;
			++p;
		}
		total += a[i].y;
	}
	if (total > 0) {
		s |= 1LL<<p;
	}
	printf ("%lld\n", s);
 
	return 0;
}