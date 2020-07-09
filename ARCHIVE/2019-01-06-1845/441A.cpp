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

int n, v;
int ans;
vector<int> vec;

int main () {
	scanf ("%d %d", &n, &v);
	for (int i = 1; i <= n; i++) {
		int k;
		scanf ("%d", &k);
		int mn = 1e9;
		while (k--) {
			int x;
			scanf ("%d", &x);
			mn = min (mn, x);
		}
		if (mn < v)
			vec.push_back (i);
	}
	printf ("%d\n", len (vec));
	for (int i = 0; i < len(vec); ++i) {
		if (i) putchar (' ');
		printf ("%d", vec[i]);
	}
	putchar ('\n');

	return 0;
}
