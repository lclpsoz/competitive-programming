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
vector<int> vec;

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		vec.push_back (x);
	}
	if (n == 1)
		printf ("1\n"), exit (0);
	int ans = 2;
	int acu = 2;
	for (int l = 0; l+2 < n; l++) {
		if (vec[l+2] == vec[l] + vec[l+1])
			++acu;
		else
			acu = 2;
		ans = max (ans, acu);
	}
	printf ("%d\n", ans);
	

	return 0;
}
