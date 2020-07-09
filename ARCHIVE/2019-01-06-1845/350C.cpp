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

using pp = pair<pii, char>;

int n;
vector<pp> act;
vector<pii> bombs;

void mv (int x, int y) {
	if (x > 0)
		act.emplace_back (make_pair (1, x), 'R');
	else if (x < 0)
		act.emplace_back (make_pair (1, -x), 'L');
	if (y > 0)
		act.emplace_back (make_pair (1, y), 'U');
	else if (y < 0)
		act.emplace_back (make_pair (1, -y), 'D');
}

void defuse (int x, int y) {
	mv (x, y);
 	act.emplace_back (make_pair (2, 0), '-');
	mv (-x, -y);
	act.emplace_back (make_pair (3, 0), '-');
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		bombs.emplace_back (x, y);
	}
	sort (bombs.begin(), bombs.end(), [] (auto p1, auto  p2) {
		p1 = {abs (p1.x), abs (p1.y)};
		p2 = {abs (p2.x), abs (p2.y)};
		return p1 < p2;
	});
	for (auto p : bombs)
		defuse (p.x, p.y);
	
	printf ("%d\n", len (act));
	for (auto p : act)
		if (p.x.x == 1)
			printf("%d %d %c\n", p.x.x, p.x.y, p.y);
		else
			printf("%d\n", p.x.x);

	return 0;
}
