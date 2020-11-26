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
set<int> st;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		st.insert (x);
	}
	if (len (st) == 1)
		printf ("0\n");
	else if (len (st) == 2) {
		int v1 = *st.begin(); st.erase (st.begin());
		int v2 = *st.begin();
		if ((v2 - v1)%2 == 0)
			printf ("%d\n", (v2 - v1)/2);
		else
			printf ("%d\n", (v2 - v1));
	}
	else if (len (st) > 3)
		printf ("-1\n");
	else {
		int v1 = *st.begin(); st.erase (st.begin());
		int v2 = *st.begin(); st.erase (st.begin());
		int v3 = *st.begin();
		if ((v3 - v2) == (v2 - v1))
			printf ("%d\n", v3 - v2);
		else
			printf ("-1\n");
	}

	return 0;
}
