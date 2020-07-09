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

int n;
vector<pair<pii, int>> v1, v2;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x, y;
		scanf ("%d %d", &x, &y);
		if (x > y)
			v1.push_back ({{y, x}, i+1});
		else
			v2.push_back ({{y, x}, i+1});
	}
	sort (v1.begin(), v1.end());
	sort (v2.begin(), v2.end(), greater<pair<pii, int>>());
	if (len (v1) > len (v2)) {
		printf ("%d\n", len (v1));
		for (auto p : v1)
			printf ("%d ", p.y);
		putchar ('\n');
	} else {
		printf ("%d\n", len (v2));
		for (auto p : v2)
			printf ("%d ", p.y);
		putchar ('\n');

	}


	return 0;
}
