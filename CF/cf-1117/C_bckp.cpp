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

int X1, Y1, X2, Y2;
int n;
char mov[N];

pii conv (char c) {
	if (c == 'U')
		return {0, 1};
	if (c == 'D')
		return {0, -1};
	if (c == 'R')
		return {0, 1};
	if (c == 'L')
		return {0, -1};
}

int main () {
	scanf ("%d %d", &X1, &Y1);
	scanf ("%d %d", &X2, &Y2);
	scanf ("%d", &n);
	scanf (" %s", mov);

	pii obj = {X2 - X1, Y2 - Y1};
	pii all = {0, 0};
	for (int i = 0; i < n; i++) {
		pii now = conv (mov[i]);
		all.x += now.x;
		all.y += now.y;
	}
	ll ans = 0;

	// First cancel movement against correct direction
	int available = n;
	pii adpt = all;
	if (all.x * 1LL * obj.x <= 0) {
		available -= abs (all.x);
		adpt.x = 0;
	}
	if (all.y * 1LL * obj.y <= 0) {
		available -= abs (all.y);	
		adapt.y = 0;
	}
	// Can't move towards dest!!!
	if (available == 0) {
		printf ("-1\n");
		exit (0);
	}

	

	int adptX = adpt.x;
	if (obj.x < 0)
		adptX -= n;
	else
		adptX += n;

	int adptY = adpt.y;
	if (obj.y < 0)
		adptY -= n;
	else
		adptY += n;

	ans += n * (abs (obj.x)/abs (adptX.x));
	obj.x %= abs (adptX.x);
	ans += n * (abs (obj.y)/abs (adptY.y));
	obj.y %= abs (adptY.y);

	for (int i = 1; i <= n; i++) {

	}

	return 0;
}
