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

const int N = 3e5 + 10;

int n, m;
int a[N], now[N];

bool check (int x) {

	for (int i = 1; i <= n; i++) {
		a[i] = now[i];
		int st = a[i], en = (a[i]+x)%m;
		if (en < st) {
			if (a[i-1] > en) a[i] = max (a[i-1], st);
			else a[i] = a[i-1];
		}
		else if (st <= en) {
			if (a[i-1] > en) return false;
			a[i] = max (st, a[i-1]);
		}
	}


	return true;
}

int main () {
	scanf ("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf ("%d", &now[i]);

	int l = 0, r = m-1;
	while (l < r) {
		int md = (l+r)/2;
		if (check (md))
			r = md;
		else
			l = md+1;
	}
	printf ("%d\n", l);

	return 0;
}
