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

const int N = 7000;

int not_prime[N];

int mdc (int a, int b) {
	if (a == 0) return b;
	return mdc (b%a, a);
}

pii brute (int a) {
	int mx = -1;
	int b;
	for (int i = 1; i < a; i++) {
		if (mdc (i&a, i^a) > mx) {
			mx = mdc (i&a, i^a);
			b = i;
		}
	}
	return {mx, b};
}

int main () {
	for (int i = 2; i*i < N; i++)
		if(!not_prime[i])
			for (int j = i*i; j < N; j+=i)
				not_prime[j] = true;
	
// 	for (int i = 4;; i*= 2) {
// 		int a = i-1;
// 		pii p = brute (a);
// // 		printf ("%s\n", a%3 == 0 ? "DIVISIBLE" : "NO");
// 		int sm = a;
// 		for (int j = 2; j*j < a; j++)
// 			if (!not_prime[j] and a%j == 0) {
// 				sm = j; break;
// 			}
// 		printf ("a = %d\n", a);
// 		if (p.x != a/sm)
// 			printf ("FAIL\n");
// //  		printf ("%d: %d %d %d\n", a, p.x, p.y, a/sm);
// 	}
	
	int q, a;
	scanf ("%d", &q);
	while (q--) {
		scanf ("%d", &a);
		if (__builtin_popcount (a+1) == 1) {
			int sm = a;
			for (int j = 2; j*j < a; j++)
				if (!not_prime[j] and a%j == 0) {
					sm = j; break;
				}
			printf ("%d\n", a/sm);
		} else {
			int x = 1;
			while (x <= a) x <<= 1;
			x -= 1;
			printf ("%d\n", x);
		}
	}

	return 0;
}
