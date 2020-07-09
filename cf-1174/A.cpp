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

int a[101010];

int main () {
	int n;
	scanf ("%d", &n);
	set<int> st;
	for (int i = 0; i < 2*n; i++) {
		scanf ("%d", &a[i]);
		st.insert (a[i]);
	}
	if (len (st) == 1) {
		printf ("-1\n");
		exit (0);
	}
	sort (a, a+2*n);
	for (int i = 0; i < 2*n; i++)
		printf ("%d ", a[i]);
	putchar ('\n');

	return 0;
}
