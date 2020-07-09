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

const int P = 1e6 + 1000;

int t;
int n;
set<int> inD;
bool not_prime[P];
vector<int> primes;

ll mdc (ll x, ll y) {
	if (x == 0) return y;
	return mdc (y%x, x);
}

ll mmc (ll x, ll y) {
	return (x*y)/mdc (x, y);
}

bool checkDiv (ll mc) {
	ll mcOri = mc;
	vector<int> pNow;
	vector<int> qNow;
	int pos = 0;
	while (mc > 1 and primes[pos] <= mc) {
		if (mc%primes[pos] == 0) {
			pNow.push_back (primes[pos]);
			qNow.push_back (1);
			mc/=primes[pos];
			while (mc%primes[pos] == 0) {
				qNow.back()++;
				mc/=primes[pos];
			}
		}
		++pos;
	}

	vector<int> ax;
	for (int i = 0; i < len (qNow); i++) ax.push_back (0);
	ax.push_back (0);
	while (ax[len(qNow)] == 0) {
		ll num = 1;
		for (int i = 0; i < len (qNow); i++) {
			for (int j = 0; j < ax[i]; j++)
				num *= pNow[i];
		}
		// printf ("%lld\n", num);
		if (num != 1 and num != mcOri and inD.count (num) == 0) return false;
		ax[0]++;
		for (int i = 0; i < len(qNow); i++)
			if (ax[i] > qNow[i]) {
				ax[i] = 0;
				ax[i+1]++;
			}
		// for (int i = 0; i < len (ax); i++)
		// 	printf ("%d: %d\n", i, ax[i]);
	}

	return true;
}

int main () {
	for (int i = 2; i*i < P; i++)
		if (!not_prime[i])
			for (int j = i*i; j < P; j+=i)
				not_prime[j] = true;
	for (int i = 2; i < P; i++)
		if (!not_prime[i])
			primes.push_back (i);

	// for (int i = len(primes)-1; primes[i] > 1e6 - 200; i--)
	// 	if (primes[i] < 1000000)
	// 		printf ("%d\n", primes[i]);

	// for (int i = 0; i < 10 ; i++)
	// 	printf ("%d ", primes[i]);
	// putchar ('\n');

	scanf ("%d", &t);
	ll maxi = 999983 * 1LL * 999979;
	while (t--) {
		inD.clear();
		scanf ("%d", &n);
		ll mc = 1;
		bool ans = true;
		for (int i = 0; i < n; i++) {
			int x;
			scanf ("%d", &x);
			inD.insert (x);
			if (ans) 
				mc = mmc (mc, x);

			if (mc > maxi)
				ans = false;
		}
		// printf ("%lld\n", mc);
		if (!ans) {
			printf ("-1\n");
			continue;
		}
		if (inD.count (mc) == 1) // Only 1 prime
			mc *= *inD.begin();
		if (checkDiv (mc))
			printf ("%lld\n", mc);
		else
			printf ("-1\n");
	}

	return 0;
}
