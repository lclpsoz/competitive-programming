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

const int N = 2e5 + 10;

char s[N];
int n;
int q;
int bef[N];
int ans[N];

int main () {
	scanf ("%d %s", &n, s);
	for (int i = 0; i < n; i++) {
		if (s[i] == '(') {
			printf ("%d", q&1);
			q++;
		} else {
			q--;
			printf ("%d", q&1);
		}
	}
	putchar ('\n');

	return 0;
}
