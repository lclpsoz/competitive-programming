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

char str[5];

int main () {
	int l = 1, r = 1'000'000;
	while (l < r) {
		int md = (l+r+1)/2;
		printf ("%d\n", md);
		fflush (stdout);
		scanf ("%s", str);
		if (str[0] == '>')
			l = md;
		else
			r = md-1;
	}
	
	printf ("! %d\n", l);

	return 0;
}
