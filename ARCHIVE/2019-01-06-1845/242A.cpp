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

int x, y, a, b;
vector<pii> ans;

int main () {
	scanf ("%d %d %d %d", &x, &y, &a, &b);
	int base = b;
	while (a <= x) {
		while (a > b) {
			ans.push_back ({a, b});
			if (a > b+1 and y >= b+1)
				++b;
			else
				break;
		}
		if (x == a)
			break;
		++a;
		b = base;
	}
	
	printf ("%d\n", len (ans));
	for (pii p : ans)
		printf ("%d %d\n", p.x, p.y);

	return 0;
}