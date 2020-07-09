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

const int MOD = 1e9 + 7;
inline int mod (ll x, int m = MOD) {
	return (int)(((x%m) + m)%m);
}

////////////////////////// Solution starts below. //////////////////////////////

const int N = 1e7 + 100;

int n, m;
bitset<N> not_prime;

int powMod (int b, int p) {
	int ret = 1;
	while (p) {
		if (p&1)
			ret = (ret * 1LL * b)%MOD;
		b = (b * 1LL * b) % MOD;
		p >>= 1;
	}

	return ret;
}

int invMod (int x) {
	return powMod (x, MOD-2);
}

void primes () {
	// scanf ("%d %d", &n, &m);
	n = N - 1; m = n;
	for (int i = 2; i*i < n; i++)
		if (!not_prime[i])
			for (int j = i*i; j < n; j += i)
				not_prime[j] = 1;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (!not_prime[i] == 0) {
			printf ("%7d\t", i);
			++cnt;
			if (cnt%20 == 0)
				putchar ('\n');
		}
	}
}

int main () {
	mt19937_64 rng((llu)chrono::steady_clock::now().time_since_epoch().count());
	for (int i = 2; i <= 10; i++) {
		for (int j = 1; j <= 15; j++)
			printf ("%10d ", powMod (i, j));
		putchar ('\n');
	}

	for (int i = 0; i < 170; i++) putchar ('_');
	putchar ('\n');

	vector<int> vec;
	int n = 5e4;
	for (int i = 0; i < n; i++) {
		vec.push_back (rng()%MOD);
		if (i%100000 == 0)
			printf ("%llu, ", rng());
	}
	putchar ('\n');

	sort (vec.begin(), vec.end());
	vector<pii> pairs;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vec[i]%vec[j] == 0) {
				pairs.push_back ({vec[i], vec[j]});
				// printf ("%10d / %10d -> %d %d\n", vec[i], vec[j], vec[i]/vec[j], (vec[i]*1LL*invMod(vec[j]))%MOD);
			}
		}

	}
		



	return 0;
}
