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

vector<int> vec;

int main () {
	int n;
	scanf ("%d", &n);
	while (n--) {
		char opt[1010];
		scanf ("%s", opt);
		if (opt[0] == 'a')
			vec.push_back (-1);
		else if (opt[0] == 'f') {
			int x;
			scanf ("%d", &x);
			vec.push_back (x);
		} else {
			if (vec.back () != -1 and vec.back() != 0)
				vec.pop_back ();
			else
				vec.push_back (0);
		}
	}

	llu mx = (1LL<<32) - 1;
	llu val = 0;
	llu qnt = 1;
	vector<int> ax;
	for (int x : vec) {
		if (x == -1)
			val += qnt;
		else if (x == 0) {
			qnt /= ax.back();
			ax.pop_back ();
		} else {
			qnt *= x;
			ax.push_back (x);
		}
		// printf ("x = %d, val = %lld\n", x, val);
		if (val > mx or qnt > mx) {
			printf ("OVERFLOW!!!\n");
			exit (0);
		}
	}
	printf ("%llu\n", val);

	return 0;
}
