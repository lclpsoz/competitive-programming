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

set<int> st;

int main () {
	st.insert (0);
	int x = 2;
	while (x <= 1000000000) {
		// printf ("%d\n", x);
		st.insert (x);
		x = 2*x + 2;
	}

	int n;
	scanf ("%d", &n);
	if (st.count (n))
		printf ("Second player wins\n");
	else
		printf ("First player wins\n");

	return 0;
}
