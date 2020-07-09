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

const int MOD = 998244353;
inline int mod (ll x, int m = MOD) {
	return (int)(x%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 2e5 + 10;
const int P = 1e6 + 1000;


int n;
ll a[N], b[N], ax[N];
bool not_prime[P];
vector<int> primes;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &a[i]);
	for (int i = 0; i < n; i++)
		scanf ("%lld", &b[i]);

	// for (int k = 0; k < 20; k++) {
	// 	printf ("k = %d\n", k);
	// 	memset (ax, 0, sizeof ax);
	// 	for (int i = 0; i < k; i++)
	// 		for (int j = 0; j < k-i; j++)
	// 			for (int l = j; l < j+i+1; l++)
	// 				ax[l]++;
	// 	for (int i = 0; i < k; i++)
	// 		printf ("%d%c", ax[i], " \n"[i==k-1]);
	// 	for (int i = 0; i < k; i++)
	// 		printf ("%d%c", ax[i]-ax[i+1], " \n"[i==k-1]);
	// }
	for (ll dd = n-2, d = n, i = 0; i <= (n-1)/2; i++, d+=dd, dd-=2) {
		// printf ("dd = %lld, d = %lld, i = %lld\n", dd, d, i);
		a[i] *= d;
		if (i != n-i-1)
			a[n-i-1] *= d;
	}
	sort (b, b+n, greater<int>());
	sort (a, a+n);
	// for (int i = 0; i < n; i++)
		// printf ("%d%c", a[i], " \n"[i==n-1]);
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = (ans + ((a[i])%MOD * b[i]))%MOD;
		// printf ("%lld %lld %lld\n", *st.begin(), b[i], ans);
	}
	printf ("%lld\n", ans);


	return 0;
}
