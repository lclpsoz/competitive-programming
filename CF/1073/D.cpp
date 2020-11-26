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

const int N = 2e5+100;

int n;
ll t, sum;
int a[N];

int main () {
	scanf ("%d %lld", &n, &t);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &a[i]);
		sum += a[i];
	}
	
	ll ans = n * 1LL * (t/sum);
	t %= sum; // All full rounds he can do
	
	int qnt = 1;
	while (qnt) {
		sum = qnt = 0;
		for (int i = 0; i < n; i++)
			if (t >= a[i]) {
				t -= a[i];
				++qnt; sum += a[i];
			}
		if (qnt) {
			ans += qnt;
			ans += qnt * (t/sum);
			t %= sum;
		}
	}
	
	printf ("%lld\n", ans);
	

	return 0;
}
