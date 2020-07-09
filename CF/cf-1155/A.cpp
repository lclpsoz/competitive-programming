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

int main () {
	int n;
	string s;
	cin >> n >> s;
	bool ok = false;
	int l, r;
	for (int i = 0; i < n-1; i++)
		if (s[i] > s[i+1]) {
			printf ("YES\n");
			printf ("%d %d\n", i+1, i+2);
			return 0;
		}
		
	printf ("NO\n");

	return 0;
}
