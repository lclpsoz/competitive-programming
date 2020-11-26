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

int n, m;
ll x[N], chg[N], one[N];

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf ("%lld", &x[i]);
	ll base = 0;
	for (int i = 1; i < m; i+=2) {
		base += abs (x[i]-x[i-1]);
		if (i < m-1)
			base += abs (x[i] - x[i+1]);
	}

	for (int i = 0; i < m; i++) {
		if (i < m-1) {
			if (x[i+1] > x[i]) {
				chg[x[i]]--;
				one[x[i]] += x[i]-1;
			}
			if (x[i+1] == x[i]-1)
				chg[x[i]]++;
			if (x[i+1] < x[i]) {
				chg[x[i]]++;
				ll dBef = abs (x[i] - (x[i+1] + 1));
				ll dNow = abs (1 - (x[i+1] + 1));
				one[x[i]] += (dNow - dBef);
			}
		}
		if (i) {
			if (x[i-1] > x[i]) {
				chg[x[i]]--;
				one[x[i]] += x[i]-1;
			}
			if (x[i-1] < x[i]) {
				chg[x[i]]++;
				ll dBef = abs (x[i] - (x[i-1] + 1));
				ll dNow = abs (1 - (x[i-1] + 1));
				one[x[i]] += (dNow - dBef);
			}
		}
	}
	// for (int i = 1; i <= n; i++)
	// 	printf ("%d: %d %d\n", i, chg[i], one[i]);

	for (int i = 1; i <= n; i++) {
		printf ("%lld ", base);
		base -= one[i];
		base += chg[i] + one[i+1];
	}
	putchar ('\n');

	return 0;
}
