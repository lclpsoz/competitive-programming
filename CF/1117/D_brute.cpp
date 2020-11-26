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

const int N = 1e5 + 10;

int fat[N], invFat[N];

int invMod (int v) {
	int ret = 1;
	int p = MOD - 2;
	int b = v;
	while (p) {
		if (p&1)
			ret = mod (ret * 1LL * b);
		b = mod (b * 1LL * b);
		p >>= 1;
	}

	return ret;
}

int bin (int a, int b) {
	int ret = mod (mod (fat[a] * 1LL * invFat[b])*1LL*invFat[a-b]);
	// printf ("a = %d, b = %d\t| %d * %d * %d = %d\n", a, b, fat[a], invFat[b], invFat[a-b], ret);
	return ret;
}

int solve (int x, int m) {
	int ret = 0;
	for (int i = x; i >= 0; i-=m) {
		ret = mod (ret + bin (x, i));
		x -= m-1;
	}

	return ret;
}

int main () {
	fat[0] = fat[1] = invFat[0] = invFat[1] = 1;
	for (int i = 2; i < N; i++) {
		fat[i] = mod (fat[i-1] * 1LL * i);
		invFat[i] = invMod (fat[i]);
	}
	printf ("%d\n", bin (8, 2));
	int m;
	scanf ("%d", &m);
	printf ("m = %d\n", m);
	for (int i = 1; i <= 100; i++) {
		printf ("%4d|", i);
		printf (" %d\n", solve (i, m));
	}

	return 0;
}
