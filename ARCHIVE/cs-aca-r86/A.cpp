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

int n, p , t;


int main () {
	cin >> n >> p >> t;
	int st = 1;
	for (int i = 0; i < t; i++)
		if (i%9 == 4 or i%9 > 5)
			++st;
		else if (i%9 == 5)
			--st;
	// printf ("%d\n", st);
	if (p <= st+n-1 and p >= st)
		printf ("%d\n", p - st + 1);
	else
		printf ("-1\n");

	return 0;
}
