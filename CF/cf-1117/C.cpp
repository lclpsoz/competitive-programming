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

using pll = pair<ll, ll>;

const int N = 1e5 + 10;

ll X1, Y1, X2, Y2;
pll all;
int n;
char mov[N];

pll conv (char c) {
	if (c == 'U')
		return {0, 1};
	if (c == 'D')
		return {0, -1};
	if (c == 'R')
		return {1, 0};
	if (c == 'L')
		return {-1, 0};
}

bool check (ll days) {
	ll oriDays = days;
	ll full = days/n;
	pll ax = {all.x*full, all.y*full};
	days -= full*n;
	for (int i = 0; i < days; i++) {
		pll now = conv (mov[i]);
		ax.x += now.x;
		ax.y += now.y;
	}
	ll X3 = X1 + ax.x, Y3 = Y1 + ax.y;
	return (abs (X3 - X2) + abs (Y3 - Y2)) <= oriDays;
}

int main () {
	scanf ("%lld %lld", &X1, &Y1);
	scanf ("%lld %lld", &X2, &Y2);
	scanf ("%d", &n);
	scanf (" %s", mov);

	all = {0, 0};
	for (int i = 0; i < n; i++) {
		pll now = conv (mov[i]);
		all.x += now.x;
		all.y += now.y;
	}
	ll l = 1, r = 1e15 + 100;
	while (l < r) {
		ll md = (l + r)/2;
		if (check (md))
			r = md;
		else 
			l = md + 1;
	}
	if (r > (ll) 1e15)
		printf ("-1\n");
	else
		printf ("%lld\n", l);

	return 0;
}
