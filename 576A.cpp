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

set<int> ans;
bool not_prime[N];


int main () {
	int n;
	scanf ("%d", &n);
	not_prime[0] = not_prime[1] = true;
	for (int i = 2; i*i < N; i++)
		for (int j = i*i; j < N; j+=i)
			not_prime[j] = true;

	for (int i = 2; i <= n; i++) {
		int now = i;
		for (int j = 2; j <= i; j++)
			if(!not_prime[j]) {
				int ax = 1;
				while (now%j == 0) {
					ax *= j;
					now /= j;
				}
				if (ax > 1)
					ans.insert (ax);
			}
	}

	printf ("%d\n", len (ans));
	for (int v : ans)
		printf ("%d ", v);
	putchar ('\n');

	return 0;
}
