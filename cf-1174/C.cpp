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

int n;
int a[N];

int main () {
	scanf ("%d", &n);
	int val = 1;
	for (int i = 2; i <= n; i++)
		if (a[i] == 0) {
			for (int j = i; j <= n; j+=i)
				if (a[j] == 0) a[j] = val;
			++val;
		}
	for (int i = 2; i <= n; i++) printf ("%d ", a[i]);
	putchar ('\n');

	return 0;
}
